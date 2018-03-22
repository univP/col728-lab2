#include <stdio.h>
#include <stdlib.h>
#include "c.tab.hpp"

extern "C" int yylex();
int yyparse();
extern "C" FILE *yyin;

static void usage()
{
    printf("Usage: cc <prog.c>\n");
}

/*--------------------------------------------------.
|   Section 1: Main control flow of the program.    |
`--------------------------------------------------*/

#include "parser.h"
extern "C" ast_program* program;

StrTable id_table;      // Contains identifiers
StrTable str_table;     // Contains string literals
StrTable int_table;     // Contains integer constants
StrTable float_table;   //  Contains floating point literals

Symbol
    Void = id_table.add_string("void"),
    Int = id_table.add_string("int"),
    Float = id_table.add_string("float"),
    Char = id_table.add_string("char"),
    Str = id_table.add_string("string"),
    Undefined = id_table.add_string(".undefined"),  // Type uninitialized
    No_type = id_table.add_string(".no_type");      // No expression type

// Used for type checking
struct MethodType {
    Symbol return_type;
    std::vector<Symbol> param_types;
    bool variadic;
};

llvm::LLVMContext llvm_context;
llvm::IRBuilder<> builder(llvm_context);
std::unique_ptr<llvm::Module> module;
SymTable<Symbol, llvm::Value> named_values;
SymTable<Symbol, std::string> named_types;
std::map<Symbol, ast_function_declarator*> fun_decls;
SymTable<Symbol, std::string> variable_table;
SymTable<Symbol, MethodType> method_table;
std::vector<std::string> errors;

// Majorly implements the last two phases namely
//  semantic analysis and code generation.
// Prints the abstract syntax tree along with types to semant.tree file.
// Outputs human readable llvm code to terminal.
// Outputs object file in output.o
// Link using clang output.o and execute ./a.out to run the program.
// Supported grammar can be seen in c.y file.

int
main(int argc, char **argv)
{
    if (argc != 2) {
        usage();
        exit(1);
    }

    char const *filename = argv[1];
    yyin = fopen(filename, "r");
    assert(yyin != NULL);

    // Parsing phase.
    int retv = yyparse();
    // printf("retv = %d\n", ret);

    // Catches syntax errors.
    if (retv) {
        std::cerr << "Compilation halted due to lexer/parser errors." 
            << std::endl;
        exit(0);
    }
    
    // Semantic analysis phase.
    std::ofstream semant_stream;
    std::string file("semant.tree");
    semant_stream.open(file);
    program->print_struct(0, semant_stream);
    semant_stream.close();

    if (errors.size() != 0) {
        // Print all the errors and halt.
        for (std::string error : errors) {
            std::cerr << error << std::endl;
        }

        std::cerr << "Compilation halted due to semantic errors." 
            << std::endl;
        exit(0);
    }

    //  Code Generation phase.
    program->CodeGen();
    
    llvm::InitializeAllTargetInfos();
    llvm::InitializeAllTargets();
    llvm::InitializeAllTargetMCs();
    llvm::InitializeAllAsmParsers();
    llvm::InitializeAllAsmPrinters();

    auto TargetTriple = llvm::sys::getDefaultTargetTriple();
    module->setTargetTriple(TargetTriple);

    std::string Error;
    auto Target = llvm::TargetRegistry::lookupTarget(TargetTriple, Error);

    // Print an error and exit if we couldn't find the requested target.
    // This generally occurs if we've forgotten to initialise the
    // TargetRegistry or we have a bogus target triple.
    if (!Target) {
        llvm::errs() << Error;
        return 1;
    }

    auto CPU = "generic";
    auto Features = "";

    llvm::TargetOptions opt;
    auto RM = llvm::Optional<llvm::Reloc::Model>();
    auto TheTargetMachine =
        Target->createTargetMachine(TargetTriple, CPU, Features, opt, RM);

    module->setDataLayout(TheTargetMachine->createDataLayout());

    std::string Filename("output.o");
    std::error_code EC;
    llvm::raw_fd_ostream dest(Filename, EC, llvm::sys::fs::F_None);

    if (EC) {
        llvm::errs() << "Could not open file: " << EC.message();
        return 1;
    }

    llvm::legacy::PassManager pass;
    auto FileType = llvm::TargetMachine::CGFT_ObjectFile;

    if (TheTargetMachine->addPassesToEmitFile(pass, dest, FileType)) {
        llvm::errs() << "TheTargetMachine can't emit a file of this type";
        return 1;
    }

    pass.run(*module);
    dest.flush();

    llvm::outs() << "Wrote " << Filename << "\n";

    exit(0);
}

/*------------------------------.
|   Section 2 : Code generation |
`------------------------------*/
// We align all the variables before storing them.
// This is a helper method to retrieve alignment boundary given type.
unsigned int get_alignment(llvm::Type* type) {
    if (type->isIntegerTy(32)) {
        return 4;
    } else if (type->isDoubleTy()) {
        return 8;
    } else if (type->isPointerTy() && (
        type->getPointerElementType())->isIntegerTy(8)) {
            return 8;
    }

    type->dump();
    my_assert(0, __LINE__, __FILE__);
    return 0;
}

// Helper method to retrieve llvm type from type inferred by AST.
llvm::Type* get_llvm_type(Symbol type_specifier, bool pointer) {
    if (pointer) {
        if (type_specifier == Int) {
            return llvm::Type::getInt32PtrTy(llvm_context);
        } else if (type_specifier == Float) {
            return llvm::Type::getDoublePtrTy(llvm_context);
        } else if (type_specifier == Void) {
            return llvm::Type::getInt8PtrTy(llvm_context);
        } else if (type_specifier == Char) {
            return llvm::Type::getInt8PtrTy(llvm_context);
        }
    } else {
        if (type_specifier == Int) {
            return llvm::Type::getInt32Ty(llvm_context);
        } else if (type_specifier == Float) {
            return llvm::Type::getDoubleTy(llvm_context);
        } else if (type_specifier == Void) {
            return llvm::Type::getVoidTy(llvm_context);
        } else if (type_specifier == Str) {
            return llvm::Type::getInt8PtrTy(llvm_context);
        } else if (type_specifier == Char) {
            return llvm::Type::getInt32Ty(llvm_context);
        }
    }

    my_assert(0, __LINE__, __FILE__);
    return NULL;
}

// We initialize all the variables with a default value depending on the type.
llvm::Constant* get_default_value(llvm::Type* type) {
    if (type->isIntegerTy(32)) {
        return llvm::ConstantInt::get(llvm_context, 
            llvm::APInt(32, 0, true));
    } else if (type->isDoubleTy()) {
        return llvm::ConstantFP::get(llvm_context, 
            llvm::APFloat(0.0));
    } else if (type->isPointerTy() && (
        type->getPointerElementType())->isIntegerTy(8)) {
            llvm::StringRef string_ref("");
            return llvm::ConstantDataArray::getString(llvm_context,
                string_ref);
    }

    my_assert(0, __LINE__, __FILE__);
    return NULL;
}

// Retrieve back AST type from llvm type.
Symbol get_symbol_type(llvm::Type* type) {
    if (type->isIntegerTy(32)) {
        return Int;
    } else if (type->isDoubleTy()) {
        return Float;
    } else if (type->isVoidTy()) {
        return Void;
    } else if (type->isPointerTy() && (
        type->getPointerElementType())->isIntegerTy(8)) {
            return Str;
    }

    my_assert(0, __LINE__, __FILE__);
    return NULL;
}

bool is_same_type(Symbol s1, Symbol s2) {
    if (s1 == Char) {
        s1 = Int;
    }

    if (s2 == Char) {
        s2 = Int;
    }

    return s1 == s2;
}

// Function may either be declared already or inserted into the map
//  before calling this function. This checks at both places and returns
//  the function template.
llvm::Function* get_function(llvm::Type* type, Symbol function_name) {
    llvm::Function* function = module->getFunction(*function_name);

    if (function) {
        return function;
    }

    std::map<Symbol, ast_function_declarator*>::iterator
        mit = fun_decls.find(function_name);
    
    if (mit != fun_decls.end()) {
        return mit->second->CodeGenGlobal(type);
    }

    return NULL;
}

// We add the local variables to the top of the function block.
llvm::AllocaInst* CreateEntryBlockAlloca(llvm::Type* type, 
        llvm::Function* function, Symbol local_var) {
    llvm::IRBuilder<> local_builder(&function->getEntryBlock(), 
        function->getEntryBlock().begin());
    return local_builder.CreateAlloca(type, nullptr, *local_var);
}

// Code generation function defined in appropriate AST nodes.
// Named values contain the location of the the variable allocated
//  and Named types contains the type of the variable.
void ast_program::CodeGen() {
    named_values.enter_scope();
    named_types.enter_scope();
    module = llvm::make_unique<llvm::Module>("col728 lab2",
        llvm_context);

    for (ListI lit = external_declarations->begin(); 
            lit != external_declarations->end(); lit++) {
        (*lit)->CodeGen();
    }
    
    module->print(llvm::errs(), nullptr);
    named_types.exit_scope();
    named_values.exit_scope();
}

// Since an external declaration can be either a declaration/function_definition
//  the index determines the value in the union.
void ast_external_declaration::CodeGen() {
    if (index == 0) {
        data.declaration->CodeGenGlobal();
    } else if (index == 1) {
        data.function_definition->CodeGen();
    } else {
        my_assert(0, __LINE__, __FILE__);
    }
}

// We load at an aligned address since we align all the symbols.
llvm::Value* ast_identifier_expression::CodeGen() {
    llvm::Value* value = named_values.lookup(identifier);

    if (value == NULL) {
        return nullptr;
    } else {
        set_type(named_types.lookup(identifier));
    }
    
    return builder.CreateAlignedLoad(value, ::get_alignment(::get_llvm_type(
        get_type(), false)), identifier->c_str());
}

// i_constant may either be a character or any of the formats provided in the 
//  lexer. We need to appropriately convert them to an integer.
llvm::Value* ast_i_constant::CodeGen() {
    int val;
    
    if ((*i_constant)[0] == '\'') {
        if ((*i_constant)[1] == '\\') {
            switch((*i_constant)[2]) {
                case 'a':
                    val = '\a';
                    break;
                case 'b':
                    val = '\b';
                    break;
                case 'f':
                    val = '\f';
                    break;
                case 'n':
                    val = '\n';
                    break;
                case 'r':
                    val = '\r';
                    break;
                case 't':
                    val = '\t';
                    break;
                case 'v':
                    val = '\v';
                    break;
                default:
                    val = (*i_constant)[2];
            }
        } else {
            val = (*i_constant)[1];
        }
    } else {
        val = atoi(i_constant->c_str());
    }

    set_type(Int);
    return llvm::ConstantInt::get(llvm_context, 
        llvm::APInt(32, val, true));
}

// Printf accepts a double type.
llvm::Value* ast_f_constant::CodeGen() {
    double val = atof(f_constant->c_str());
    set_type(Float);
    return llvm::ConstantFP::get(llvm_context, llvm::APFloat(val));
}

// All string consstants are stored as global variables.
llvm::Value* ast_string_expression::CodeGen() {
    set_type(Str);
    llvm::Constant* strConstant = llvm::ConstantDataArray::getString(
        llvm_context, *string_literal);
    llvm::GlobalVariable* GVStr =
        new llvm::GlobalVariable(*module, strConstant->getType(), true,
            llvm::GlobalValue::PrivateLinkage, strConstant);
    GVStr->setAlignment(1);
    llvm::Constant* zero = llvm::Constant::getNullValue(
        llvm::IntegerType::getInt32Ty(llvm_context));
    llvm::Constant* indices[] = {zero, zero};
    llvm::Type* str_type = llvm::ArrayType::get(llvm::Type::getInt8Ty(
        llvm_context), string_literal->size()+1);
    llvm::Constant* strVal = llvm::ConstantExpr::getGetElementPtr(
        str_type, GVStr, indices, true);
    return strVal;
}

llvm::Value* ast_no_expression::CodeGen() {
    set_type(No_type);
    return NULL;
}

Symbol ast_type_specifier::get_type_specifier() {
    return type_specifier;
}

// While CodeGen is the function that generates code, sometimes we require 
//  to generate code differently in local and global contexts (Like defining a
//  global variable vs local variable). In which case the function name is 
//  suffixed by the context.
void ast_declaration::CodeGenGlobal() {
    llvm::Type* type = ::get_llvm_type(type_specifier->get_type_specifier(), 
        false);

    for (ListI lit = init_declarators->begin(); 
            lit != init_declarators->end(); lit++) {
        (*lit)->CodeGenGlobal(type);
    }
}

void ast_init_declarator::CodeGenGlobal(llvm::Type* type) {
    declarator->CodeGenGlobal(type);
}

void ast_declarator::CodeGenGlobal(llvm::Type* type) {
    direct_declarator->CodeGenGlobal(type);
}

void ast_direct_declarator::CodeGenGlobal(llvm::Type* type) {
    if (index == 0) {
        data.identifier_declarator->CodeGenGlobal(type);
    } else if (index == 1) {
        data.function_declarator->CodeGenGlobal(type);
    } else {
        my_assert(0, __LINE__, __FILE__);
    }
}

// See CodeGen of external declaration.
void ast_identifier_declarator::CodeGenGlobal(llvm::Type* type) {
    llvm::GlobalVariable* var = new llvm::GlobalVariable(/*Module=*/*module, 
        /*Type=*/type,
        /*isConstant=*/false,
        /*Linkage=*/llvm::GlobalValue::CommonLinkage,
        /*Initializer=*/::get_default_value(type),
        /*Name=*/identifier->c_str());
    var->setAlignment(4);
    named_values.insert(identifier, var);
    named_types.insert(identifier, ::get_symbol_type(type));
}

// Local functions start here.
void ast_declaration::CodeGenLocal() {
    llvm::Type* type = ::get_llvm_type(type_specifier->get_type_specifier(),
        false);

    for (ListI lit = init_declarators->begin();
        lit != init_declarators->end(); lit++) {
            (*lit)->CodeGenLocal(type);
    }
}

void ast_init_declarator::CodeGenLocal(llvm::Type* type) {
    declarator->CodeGenLocal(type);
}

void ast_declarator::CodeGenLocal(llvm::Type* type) {
    direct_declarator->CodeGenLocal(type);
}

void ast_direct_declarator::CodeGenLocal(llvm::Type* type) {
    if (index == 0) {
        data.identifier_declarator->CodeGenLocal(type);
    } else {
        my_assert(0, __LINE__, __FILE__);
    }
}

// An aligned store of the default value is done.
void ast_identifier_declarator::CodeGenLocal(llvm::Type* type) {
    llvm::Function* function = builder.GetInsertBlock()->getParent();
    llvm::AllocaInst* alloca = ::CreateEntryBlockAlloca(type, function, 
        identifier);
    alloca->setAlignment(::get_alignment(type));
    named_values.insert(identifier,alloca);
    named_types.insert(identifier, ::get_symbol_type(type));
    builder.CreateAlignedStore(::get_default_value(type), alloca,
        ::get_alignment(type));
}

void ast_compound_statement::CodeGen() {
    for (ListI lit = block_items->begin(); lit != block_items->end();
            lit++) {
        (*lit)->CodeGen();
    }
}

void ast_expression_statement::CodeGen() {
    expression->CodeGen();
}

llvm::Function* ast_function_declarator::CodeGenGlobal(llvm::Type* type){
    std::vector<llvm::Type*> arg_types;
    ast_parameter_declaration_list* parameter_declarations =
        parameter_types->get_parameter_declarations();

    for(ListI lit = parameter_declarations->begin(); 
        lit!= parameter_declarations->end(); lit++){
            Symbol type = (*lit)->get_type();
            bool pointer = (*lit)->is_pointer();
            arg_types.push_back(::get_llvm_type(type, pointer));
    }

    llvm::FunctionType* function_type = llvm::FunctionType::get(type, 
        arg_types, parameter_types->is_variadic());

    llvm::Function* function = llvm::Function::Create(function_type,
        llvm::Function::ExternalLinkage, *identifier, module.get());

    ListI lit = parameter_declarations->begin();

    for (auto& Arg : function->args()) {
        Arg.setName(*(*lit)->get_identifier());
        lit++;
    }

    my_assert(function != NULL, __LINE__, __FILE__);
    return function;
}

// Retrieves arguments and stores them on stack.
// This makes meeting SSA requirement of LLVM becomes simpler, since
//  no such restrictions are laid out for data in memory.
// A new scope is entered inside a function definition over the global scope.
llvm::Function* ast_function_definition::CodeGen() {
    named_values.enter_scope();
    named_types.enter_scope();

    ast_function_declarator* fun_decl = declarator->get_fun_decl();
    fun_decls.insert(make_pair(fun_decl->get_identifier(), fun_decl));
    Symbol return_type = type_specifier->get_type_specifier();
    llvm::Function* function = ::get_function(::get_llvm_type(return_type,
        false), fun_decl->get_identifier());
    llvm::FunctionType* function_type = function->getFunctionType();
    llvm::BasicBlock* basic_block = llvm::BasicBlock::Create(
        llvm_context, "entry", function);
    builder.SetInsertPoint(basic_block);

    unsigned int index = 0;

    for (auto& farg : function->args()) {
        llvm::Type* type = function_type->getParamType(index++);
        llvm::AllocaInst* alloca = ::CreateEntryBlockAlloca(type, function, 
            id_table.add_string(farg.getName()));
        alloca->setAlignment(::get_alignment(type));
        builder.CreateAlignedStore(&farg, alloca, ::get_alignment(type));
        named_values.insert(id_table.add_string(farg.getName()),
            alloca);
        named_types.insert(id_table.add_string(farg.getName()),
            ::get_symbol_type(type));
    }

    compound_statement->CodeGen();

    if (return_type == Void) {
        builder.CreateRetVoid();
    }

    llvm::verifyFunction(*function);

    named_values.exit_scope();
    named_types.exit_scope();
    
    return function;
}

// See CodeGen of external declaration.
void ast_block_item::CodeGen() {
    if (index == 0) {
        data.declaration->CodeGenLocal();
    } else if (index == 1) {
        data.statement->CodeGen();
    } else {
        my_assert(0, __LINE__, __FILE__);
    }
}

// Handles the function dispatch.
// Expressions (actual arguments) are evaluated in left-right order.
llvm::Value* ast_postfix_expression::CodeGen(){
    llvm::Function* function = module->getFunction(*function_name);

    if (!function) {
        return nullptr;
    }

    if(!(function->isVarArg()) && 
        function->arg_size() != arguments->size()) {
        return nullptr;
    }

    std::vector<llvm::Value*> ArgsV;
    for(argI ait = arguments->begin(); ait!= arguments->end(); ait++){
        ArgsV.push_back((*ait)->CodeGen());
    }
    
    return builder.CreateCall(function, ArgsV, "calltmp");
}

llvm::Value* ast_unary_expression::CodeGen(){
    llvm::Value* value = expression->CodeGen();
    set_type(Int);
    if(!value)
        return NULL;
   
    if(unary=='-')
        return builder.CreateNeg(value);
    else if(unary=='~')
        return builder.CreateNot(value);
    else if(unary=='!')
        return builder.CreateICmpEQ(value, llvm::ConstantInt::get(llvm_context, 
            llvm::APInt(32, 0, true)));
    else
        return NULL;
}

// Binary operators come in 3 flavors
//  1. arithmetic, 2. comparison, 3. boolean
// Arithmetic operators, we handle all of +, -, *, /, %
//  however we operate only between two ints or two floats
//  which is sufficient enough.
llvm::Value* ast_mul_expression::CodeGen(){
    llvm::Value* e1_eval = e1->CodeGen();
    llvm::Value* e2_eval = e2->CodeGen();

    if (is_same_type(e1->get_type(), Int) && 
            is_same_type(e2->get_type(), Int)){
        set_type(Int);
        return builder.CreateMul(e1_eval, e2_eval, "multmp");
    } else if (e1->get_type() == Float && e2->get_type() == Float) {
        set_type(Float);
        return builder.CreateFMul(e1_eval, e2_eval, "multmp");
    }

    return nullptr;
}

llvm::Value* ast_div_expression::CodeGen(){
    llvm::Value* e1_eval = e1->CodeGen();
    llvm::Value* e2_eval = e2->CodeGen();

    if (is_same_type(e1->get_type(), Int) && 
            is_same_type(e2->get_type(), Int)){
        set_type(Int);
        return builder.CreateSDiv(e1_eval, e2_eval, "divtmp");
    } else if (e1->get_type() == Float && e2->get_type() == Float) {
        set_type(Float);
        return builder.CreateFDiv(e1_eval, e2_eval, "divtmp");
    }

    return nullptr;
}

llvm::Value* ast_mod_expression::CodeGen(){
    llvm::Value* e1_eval = e1->CodeGen();
    llvm::Value* e2_eval = e2->CodeGen();

    if (is_same_type(e1->get_type(), Int) && 
            is_same_type(e2->get_type(), Int)){
        set_type(Int);
        return builder.CreateSRem(e1_eval, e2_eval, "modtmp");
    } else if (e1->get_type() == Float && e2->get_type() == Float) {
        set_type(Float);
        return builder.CreateFRem(e1_eval, e2_eval, "modtmp");
    }

    return nullptr;
}

llvm::Value* ast_add_expression::CodeGen(){
    llvm::Value* e1_eval = e1->CodeGen();
    llvm::Value* e2_eval = e2->CodeGen();

    if (is_same_type(e1->get_type(), Int) && 
            is_same_type(e2->get_type(), Int)){
        set_type(Int);
        return builder.CreateAdd(e1_eval, e2_eval, "addtmp");
    }else if (e1->get_type() == Float && e2->get_type() == Float) {
        set_type(Float);
        return builder.CreateFAdd(e1_eval, e2_eval, "addtmp");
    }

    return nullptr;
}


llvm::Value* ast_sub_expression::CodeGen(){
    llvm::Value* e1_eval = e1->CodeGen();
    llvm::Value* e2_eval = e2->CodeGen();

    if (is_same_type(e1->get_type(), Int) && 
            is_same_type(e2->get_type(), Int)){
        set_type(Int);
        return builder.CreateSub(e1_eval, e2_eval, "subtmp");
    }else if (e1->get_type() == Float && e2->get_type() == Float) {
        set_type(Float);
        return builder.CreateFSub(e1_eval, e2_eval, "subtmp");
    }

    return nullptr;
}

// Only comparison operators used are <, <= and ==
//  inclusion of >, >= is unnecessary
llvm::Value* ast_less_expression::CodeGen(){
    llvm::Value* e1_eval = e1->CodeGen();
    llvm::Value* e2_eval = e2->CodeGen();

    if (is_same_type(e1->get_type(), Int) && 
            is_same_type(e2->get_type(), Int)){
        set_type(Int);
        return builder.CreateICmpSLT(e1_eval, e2_eval, "lesstmp");
    } else if (e1->get_type() == Float && e2->get_type() == Float) {
        set_type(Float);
        return builder.CreateFCmpOLT(e1_eval, e2_eval, "lesstmp");
    }

    return nullptr;
}

llvm::Value* ast_leq_expression::CodeGen(){
    llvm::Value* e1_eval = e1->CodeGen();
    llvm::Value* e2_eval = e2->CodeGen();

    if (is_same_type(e1->get_type(), Int) && 
            is_same_type(e2->get_type(), Int)){
        set_type(Int);
        return builder.CreateICmpSLE(e1_eval, e2_eval, "leqtmp");
    }else if (e1->get_type() == Float && e2->get_type() == Float) {
        set_type(Float);
        return builder.CreateFCmpOLE(e1_eval, e2_eval, "leqtmp");
    }

    return nullptr;
}


llvm::Value* ast_eq_expression::CodeGen(){
    llvm::Value* e1_eval = e1->CodeGen();
    llvm::Value* e2_eval = e2->CodeGen();

    if (is_same_type(e1->get_type(), Int) && 
            is_same_type(e2->get_type(), Int)) {
        set_type(Int);
        return builder.CreateICmpEQ(e1_eval, e2_eval, "eqtmp");
    } else if (e1->get_type() == Float && e2->get_type() == Float) {
        set_type(Float);
        return builder.CreateFCmpOEQ(e1_eval, e2_eval, "eqtmp");
    }

    return nullptr;
}

// Assignment expressions are of type id = expression
llvm::Value* ast_assign_expression::CodeGen(){
    
    llvm::Value* e_val = expression->CodeGen();
    if(!e_val)
        return nullptr;
    
    llvm::Value* v_address = named_values.lookup(identifier);
    if(!v_address) {
        return nullptr;
    } else {
        set_type(named_types.lookup(identifier));
        builder.CreateAlignedStore(e_val, v_address, 
            ::get_alignment(::get_llvm_type(get_type(), false)));
    }

    return e_val;  
}

// We support both unmatched and matched if then else.
void ast_mif_statement::CodeGen(){
    llvm::Value* cond_val = condition->CodeGen();
    if(!cond_val)
        my_assert(0, __LINE__, __FILE__);
    
    cond_val = builder.CreateICmpNE(cond_val, llvm::ConstantInt::get(llvm_context, 
        llvm::APInt(32, 0, true)), "mifcond");
    
    llvm::Function* function = builder.GetInsertBlock()->getParent();
    llvm::BasicBlock* then_block = llvm::BasicBlock::Create(llvm_context,
         "then", function);
    llvm::BasicBlock* else_block = llvm::BasicBlock::Create(llvm_context, "else");
    llvm::BasicBlock* merge_block = llvm::BasicBlock::Create(llvm_context, "ifcont");

    builder.CreateCondBr(cond_val, then_block, else_block);
    builder.SetInsertPoint(then_block);
    then_statement->CodeGen();
    
    builder.CreateBr(merge_block);
    function->getBasicBlockList().push_back(else_block);
    builder.SetInsertPoint(else_block);
    else_statement->CodeGen();
    builder.CreateBr(merge_block);
    function->getBasicBlockList().push_back(merge_block);
    builder.SetInsertPoint(merge_block);
}

void ast_uif_statement::CodeGen(){

    llvm::Value* cond_val = condition->CodeGen();
    if(!cond_val)
        my_assert(0, __LINE__, __FILE__);
    
    cond_val = builder.CreateICmpNE(cond_val, llvm::ConstantInt::get(llvm_context, 
        llvm::APInt(32, 0, true)), "uifcond");
    
    llvm::Function* function = builder.GetInsertBlock()->getParent();
    llvm::BasicBlock* then_block = llvm::BasicBlock::Create(llvm_context,
         "then", function);
    llvm::BasicBlock* merge_block = llvm::BasicBlock::Create(llvm_context, "ifcont");

    builder.CreateCondBr(cond_val, then_block, merge_block);
    builder.SetInsertPoint(then_block);
    then_statement->CodeGen();
    
    builder.CreateBr(merge_block);
    function->getBasicBlockList().push_back(merge_block);
    builder.SetInsertPoint(merge_block);    
}

// Only jump statement used is return statement.
void ast_jump_statement::CodeGen() {
    llvm::Value* value = expression->CodeGen();
    builder.CreateRet(value);
}

// All four variants of for loop are supported.
void ast_for_statement::CodeGen() {
    llvm::Function* function = builder.GetInsertBlock()->getParent();

    if (index == 0) {
        data.expression_statement->CodeGen();
    } else if (index == 1) {
        data.declaration->CodeGenLocal();
    }

    llvm::BasicBlock* loop_block = llvm::BasicBlock::Create(llvm_context,
        "loop", function);
    llvm::BasicBlock* after_block = llvm::BasicBlock::Create(llvm_context,
        "after_loop");

    llvm::Value* cond_val = condition->get_expression()->CodeGen();
    builder.CreateCondBr(cond_val, loop_block, after_block);
    builder.SetInsertPoint(loop_block);
    
    body->CodeGen();
    update->CodeGen();
    cond_val = condition->get_expression()->CodeGen();
    builder.CreateCondBr(cond_val, loop_block, after_block);

    function->getBasicBlockList().push_back(after_block);
    builder.SetInsertPoint(after_block);
}

/*------------------------------------------------------.
|   Section 3 : Print AST nodes along with their types. |
`------------------------------------------------------*/

// Does basic semantic analysis and prints AST nodes in tree format.
std::ostream& ast_program::print_struct(int d, std::ostream& s) {
    variable_table.enter_scope();
    method_table.enter_scope();
    pad(d, s) << ".program" << std::endl;
    
    for (ListI lit = external_declarations->begin();
            lit != external_declarations->end(); lit++) {
        (*lit)->print_struct(d+1, s) << std::endl;
    }

    variable_table.exit_scope();
    method_table.exit_scope();
    return s;
}

Symbol ast_expression::get_type() {
    return type;
}

void ast_expression::set_type(Symbol type) {
    this->type = type;
} 

std::ostream& ast_identifier_expression::print_struct(int d, std::ostream& s) {
    Symbol type = variable_table.lookup(identifier);

    if (type == NULL) {
        errors.push_back(*identifier + " used in expression and undeclared.");
    } else {
        set_type(type);
    }

    pad(d, s) << *identifier << ": " << *get_type() << std::endl;
    return s;
}

std::ostream& ast_i_constant::print_struct(int d, std::ostream& s) {
    set_type(Int);
    pad(d, s) << *i_constant << ": " << *get_type() << std::endl;
    return s;
}

std::ostream& ast_f_constant::print_struct(int d, std::ostream& s) {
    set_type(Float);
    pad(d, s) << *f_constant << ": " << *get_type() << std::endl;
    return s;
}

std::ostream& ast_string_expression::print_struct(int d, std::ostream& s) {
    set_type(Str);
    pad(d, s) << *string_literal << ": " << *get_type() << std::endl;
    return s;
}

std::ostream& ast_declaration::print_struct(int d, std::ostream& s) {
    pad(d, s) << ".declaration" << std::endl;
    type_specifier->print_struct(d+1, s);

    for (ListI lit = init_declarators->begin(); lit != init_declarators->end(); lit++) {
        ast_init_declarator* init_declarator = *lit;
        init_declarator->print_struct(d+1, s, 
            type_specifier->get_type_specifier());
    }

    return s;
}

std::ostream& ast_type_specifier::print_struct(int d, std::ostream& s) {
    pad(d, s) << *type_specifier << std::endl;
    return s;
}

std::ostream& ast_init_declarator::print_struct(int d, std::ostream& s, 
        Symbol type) {
    pad(d, s) << ".init_declarator" << std::endl;
    declarator->print_struct(d+1, s, type);
    return s;
}

std::ostream& ast_identifier_declarator::print_struct(int d, std::ostream& s,
        Symbol type) {
    pad(d, s) << *identifier << std::endl;

    if (variable_table.probe(identifier)) {
        errors.push_back("Redeclaration of variable " + *identifier);
    } else {
        variable_table.insert(identifier, type);
    }

    return s;
}

std::ostream& ast_function_declarator::print_struct(int d, std::ostream& s,
        Symbol type) {
    pad(d, s) << ".function_declarator" << std::endl;
    pad(d+1,s) << *identifier << std::endl;
    parameter_types->print_struct(d+1, s);
    std::vector<Symbol> param_types;

    for (ListI lit = parameter_types->get_parameter_declarations()->begin();
            lit != parameter_types->get_parameter_declarations()->end(); lit++) {
                param_types.push_back((*lit)->get_type());
    }

    MethodType* method_type = new MethodType;
    method_type->return_type = type;
    method_type->param_types = param_types;
    method_type->variadic = parameter_types->is_variadic();
    
    if (method_table.probe(identifier)) {
        errors.push_back("Redeclaration of method " + *identifier);
    } else {
        method_table.insert(identifier, method_type);
    }

    return s;
}

std::ostream& ast_parameter_declaration::print_struct(int d, std::ostream& s) {
    pad(d, s) << ".parameter_declaration" << std::endl;
    type_specifier->print_struct(d+1, s);
    pad(d+1,s) << *identifier << std::endl;
    
    if (variable_table.probe(identifier)) {
        errors.push_back("Redeclaration of formal argument " + *identifier);
    } else {
        variable_table.insert(identifier,
            type_specifier->get_type_specifier());
    }

    return s;
}

std::ostream& ast_compound_statement::print_struct(int d, std::ostream& s,
        Symbol type) {
    pad(d, s) << ".compound_statement" << std::endl;

    for (ListI lit = block_items->begin(); lit != block_items->end(); lit++) {
        ast_block_item* block_item = *lit;
        block_item->print_struct(d+1, s, type);
    }

    return s;
}

std::ostream& ast_expression_statement::print_struct(int d, std::ostream& s,
        Symbol type) {
    pad(d, s) << ".expression_statement" << std::endl;
    expression->print_struct(d+1, s);
    return s;
}

std::ostream& ast_no_expression::print_struct(int d, std::ostream& s) {
    pad(d, s) << ".no_expression" << std::endl;
    set_type(No_type);
    return s;
}

std::ostream& ast_function_definition::print_struct(int d, std::ostream& s) {
    variable_table.enter_scope();
    pad(d, s) << ".function_definition" << std::endl;
    type_specifier->print_struct(d+1, s);
    declarator->print_struct(d+1, s, type_specifier->get_type_specifier());
    compound_statement->print_struct(d+1, s, 
        type_specifier->get_type_specifier());
    variable_table.exit_scope();
    return s;
}

std::ostream& ast_block_item::print_struct(int d, std::ostream& s,
        Symbol type) {
    pad(d, s) << ".block_item" << std::endl;

    if (index == 0) {
        data.declaration->print_struct(d+1, s);
    } else if (index == 1) {
        data.statement->print_struct(d+1, s, type);
    }

    return s;
}

std::ostream& ast_external_declaration::print_struct(int d, std::ostream& s) {
    pad(d, s) << ".external_declaration" << std::endl;

    if (index == 0) {
        data.declaration->print_struct(d+1, s);
    } else if (index == 1) {
        data.function_definition->print_struct(d+1, s);
    }

    return s;
}

std::ostream& ast_postfix_expression::print_struct(int d, std::ostream& s) {
    pad(d, s) << ".post_expression" << std::endl;
    pad(d+1, s)<<*function_name <<std::endl;
    MethodType* method_type = method_table.lookup(function_name);
    
    if (!method_type) {
        errors.push_back("Undeclared method " + *function_name + " called.");
        return s;
    } else if (!method_type->variadic && 
        (method_type->param_types).size() != arguments->size()) {
            errors.push_back("Incorrect number of arguments passed.");
            return s;
    }

    int index = 0;
    
    for(argI ait = arguments->begin(); ait!= arguments->end(); ait++){
        (*ait)->print_struct(d+1, s);

        if (!method_type->variadic && !is_same_type(
                method_type->param_types[index], (*ait)->get_type())) {
            errors.push_back("Incorrect type of actual argument.");
            return s;
        }

        index++;
    }

    set_type(method_type->return_type);
    return s;
}

std::ostream& ast_unary_expression::print_struct(int d, std::ostream& s) {
    pad(d, s) << ".unary_expression" << std::endl;
    pad(d+1, s)<<unary <<std::endl;
    expression->print_struct(d+1, s);

    if (!is_same_type(expression->get_type(), Int)) {
        errors.push_back("Invalid type of argument.");
    } else {
        set_type(Int);
    }

    return s;
}

std::ostream& ast_add_expression::print_struct(int d, std::ostream& s) {
    pad(d, s) << ".add_expression" << std::endl;
    e1->print_struct(d+1, s);  
    e2->print_struct(d+1, s); 

    if (is_same_type(e1->get_type(), Int) && 
            is_same_type(e2->get_type(), Int)) {
        set_type(Int);
    } else if (e1->get_type() == Float && e2->get_type() == Float) {
        set_type(Float);
    } else {
        errors.push_back("Invalid type of arguments.");
    }

    return s;
}

std::ostream& ast_sub_expression::print_struct(int d, std::ostream& s) {
    pad(d, s) << ".sub_expression" << std::endl;
    e1->print_struct(d+1, s);  
    e2->print_struct(d+1, s); 

    if (is_same_type(e1->get_type(), Int) && 
            is_same_type(e2->get_type(), Int)) {
        set_type(Int);
    } else if (e1->get_type() == Float && e2->get_type() == Float) {
        set_type(Float);
    } else {
        errors.push_back("Invalid type of arguments.");
    }

    return s;
}

std::ostream& ast_mul_expression::print_struct(int d, std::ostream& s) {
    pad(d, s) << ".multiply_expression" << std::endl;
    e1->print_struct(d+1, s);  
    e2->print_struct(d+1, s); 

    if (is_same_type(e1->get_type(), Int) && 
            is_same_type(e2->get_type(), Int)) {
        set_type(Int);
    } else if (e1->get_type() == Float && e2->get_type() == Float) {
        set_type(Float);
    } else {
        errors.push_back("Invalid type of arguments.");
    }

    return s;
}

std::ostream& ast_div_expression::print_struct(int d, std::ostream& s) {
    pad(d, s) << ".div_expression" << std::endl;
    e1->print_struct(d+1, s);  
    e2->print_struct(d+1, s); 

    if (is_same_type(e1->get_type(), Int) && 
            is_same_type(e2->get_type(), Int)) {
        set_type(Int);
    } else if (e1->get_type() == Float && e2->get_type() == Float) {
        set_type(Float);
    } else {
        errors.push_back("Invalid type of arguments.");
    }

    return s;
}

std::ostream& ast_mod_expression::print_struct(int d, std::ostream& s) {
    pad(d, s) << ".mod_expression" << std::endl;
    e1->print_struct(d+1, s);  
    e2->print_struct(d+1, s); 

    if (is_same_type(e1->get_type(), Int) && 
            is_same_type(e2->get_type(), Int)) {
        set_type(Int);
    } else if (e1->get_type() == Float && e2->get_type() == Float) {
        set_type(Float);
    } else {
        errors.push_back("Invalid type of arguments.");
    }

    return s;
}

std::ostream& ast_less_expression::print_struct(int d, std::ostream& s) {
    pad(d, s) << ".less_expression" << std::endl;
    e1->print_struct(d+1, s);  
    e2->print_struct(d+1, s); 

    if (is_same_type(e1->get_type(), Int) && 
            is_same_type(e2->get_type(), Int)) {
        set_type(Int);
    } else if (e1->get_type() == Float && e2->get_type() == Float) {
        set_type(Float);
    } else {
        errors.push_back("Invalid type of arguments.");
    }

    return s;
}

std::ostream& ast_leq_expression::print_struct(int d, std::ostream& s) {
    pad(d, s) << ".leq_expression" << std::endl;
    e1->print_struct(d+1, s);  
    e2->print_struct(d+1, s); 

    if (is_same_type(e1->get_type(), Int) && 
            is_same_type(e2->get_type(), Int)) {
        set_type(Int);
    } else if (e1->get_type() == Float && e2->get_type() == Float) {
        set_type(Int);
    } else {
        errors.push_back("Invalid type of arguments.");
    }

    return s;
}

std::ostream& ast_eq_expression::print_struct(int d, std::ostream& s) {

    pad(d, s) << ".equality_expression" << std::endl;
    e1->print_struct(d+1, s);  
    e2->print_struct(d+1, s);  
  
    if (is_same_type(e1->get_type(), Int) && 
            is_same_type(e2->get_type(), Int)) {
        set_type(Int);
    } else if (e1->get_type() == Float && e2->get_type() == Float) {
        set_type(Float);
    } else {
        errors.push_back("Invalid type of arguments.");
    }

    return s;
}

std::ostream& ast_assign_expression::print_struct(int d, std::ostream& s) {
    pad(d, s) << ".assign_expression" << std::endl;
    pad(d+1, s)<< *identifier <<std::endl;
    expression->print_struct(d+1, s);

    Symbol type = variable_table.lookup(identifier);

    if (!type) {
        errors.push_back("Assigned to undeclared variable " + *identifier);
    } else if (!is_same_type(expression->get_type(), type)) {
        errors.push_back("In assignment expected: " + *type + " ,got: " 
            + *expression->get_type());
    } else {
        set_type(type);
    }

    return s;
}

std::ostream& ast_direct_declarator::print_struct(int d, std::ostream& s,
        Symbol type) {
    pad(d, s) << ".direct_declarator" << std::endl;

    if (index == 0) {
        data.identifier_declarator->print_struct(d+1, s, type);
    } else if (index == 1) {
        data.function_declarator->print_struct(d+1, s, type);
    }

    return s;
}

std::ostream& ast_declarator::print_struct(int d, std::ostream& s, Symbol type) {
    pad(d, s) << ".declarator" << std::endl;
    direct_declarator->print_struct(d+1, s, type);
    return s;
}


std::ostream& ast_mif_statement::print_struct(int d, std::ostream& s,
        Symbol type) {
    pad(d, s) << ".mid_statement" << std::endl;
    condition->print_struct(d+1, s);
    then_statement->print_struct(d+1, s, type);
    else_statement->print_struct(d+1, s, type);
    return s;
}

std::ostream& ast_uif_statement::print_struct(int d, std::ostream& s,
        Symbol type) {
    pad(d, s) << ".uid_statement" << std::endl;
    condition->print_struct(d+1, s);
    then_statement->print_struct(d+1, s, type);
    return s;
}

std::ostream& ast_jump_statement::print_struct(int d, std::ostream& s,
        Symbol type) {
    pad(d, s) << ".jump_statement" << std::endl;
    expression->print_struct(d+1, s);

    if (expression->get_type() != type) {
        errors.push_back("Incorrect return type");
    }

    return s;
}

std::ostream& ast_for_statement::print_struct(int d, std::ostream& s,
        Symbol type) {
    pad(d,s) << ".for_statement" << std::endl;

    if (index == 0) {
        data.expression_statement->print_struct(d+1, s, type);
    } else if (index == 1) {
        data.declaration->print_struct(d+1, s);
    }

    condition->print_struct(d+1, s, type);
    update->print_struct(d+1, s);
    body->print_struct(d+1, s, type);
    return s;
}

std::ostream& ast_parameter_type_list::print_struct(int d, std::ostream& s) {
    pad(d,s) << ".parameter_type_list" << std::endl;

    for (ListI lit = parameter_declarations->begin(); 
            lit != parameter_declarations->end(); lit++) {
        ast_parameter_declaration* parameter_declaration = *lit;
        parameter_declaration->print_struct(d+1, s);
    }

    return s;
}

/*---------------------------------------------------.
|   Section 4 : Contructors of tree nodes in AST.    |
`---------------------------------------------------*/

ast_program::ast_program(ast_external_declaration_list* external_declarations)
    : external_declarations(external_declarations) {}

ast_identifier_expression::ast_identifier_expression(Symbol identifier)
    : identifier(identifier) {
        set_type(Undefined);
}

ast_i_constant::ast_i_constant(Symbol i_constant)
    : i_constant(i_constant) {
        set_type(Undefined);
}

ast_f_constant::ast_f_constant(Symbol f_constant)
    : f_constant(f_constant) {
        set_type(Undefined);
}

ast_declaration::ast_declaration(ast_type_specifier* type_specifier,
        ast_init_declarator_list* init_declarators)
    : type_specifier(type_specifier),
        init_declarators(init_declarators) {}

ast_type_specifier::ast_type_specifier(Symbol type_specifier)
    : type_specifier(type_specifier) {}

ast_init_declarator::ast_init_declarator(ast_declarator* declarator)
    : declarator(declarator)  {}

ast_identifier_declarator::ast_identifier_declarator(Symbol identifier)
    : identifier(identifier) {}

ast_compound_statement::ast_compound_statement(ast_block_item_list* block_items)
    : block_items(block_items) {}

ast_expression_statement::ast_expression_statement(ast_expression* expression)
    : expression(expression) {}

ast_function_definition::ast_function_definition(
        ast_type_specifier* type_specifier,
        ast_declarator* declarator,
        ast_compound_statement* compound_statement)
    : type_specifier(type_specifier),
        declarator(declarator),
        compound_statement(compound_statement) {}

ast_no_expression::ast_no_expression() {
    set_type(Undefined);
}

ast_block_item::ast_block_item(ast_declaration* declaration) {
    data.declaration = declaration;
    index = 0;
}

ast_block_item::ast_block_item(ast_statement* statement) {
    data.statement = statement;
    index = 1;
}

int ast_block_item::get_index() {
    return index;
}

ast_external_declaration::ast_external_declaration(
        ast_declaration* declaration) {
    data.declaration = declaration;
    index = 0;
}

ast_external_declaration::ast_external_declaration(ast_function_definition* 
        function_definition) {
    data.function_definition = function_definition;
    index = 1;
}

int ast_external_declaration::get_index() {
    return index;
}

std::ostream& pad(int d, std::ostream& s) {
    my_assert(d >= 0, __LINE__, __FILE__);

    for (int i = 0; i < d; i++) {
        s << '\t';
    }

    return s;
}