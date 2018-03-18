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
int semant_debug = 1;
int cgen_debug = 0;

StrTable id_table;
StrTable str_table;
StrTable int_table;
StrTable float_table;

Symbol
    Void = id_table.add_string("void"),
    Char = id_table.add_string("char"),
    Int = id_table.add_string("int"),
    Float = id_table.add_string("float"),
    Undefined = id_table.add_string(".undefined"),
    No_type = id_table.add_string(".no_type");

llvm::LLVMContext llvm_context;
llvm::IRBuilder<> builder(llvm_context);
std::unique_ptr<llvm::Module> module;
SymTable<Symbol, llvm::AllocaInst> named_values;
SymTable<Symbol, std::string> named_types;
std::map<Symbol, ast_function_declarator*> fun_decls;

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
    int ret = yyparse();
    printf("retv = %d\n", ret);
    
    if (semant_debug) {
        program->print_struct(0, std::cerr);
    }

    program->CodeGen();

    exit(0);
}

/*------------------------------.
|   Section 2 : Code generation |
`------------------------------*/

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

llvm::AllocaInst* CreateEntryBlockAlloca(llvm::Type* type, 
        llvm::Function* function, Symbol local_var) {
    llvm::IRBuilder<> local_builder(&function->getEntryBlock(), 
        function->getEntryBlock().begin());
    return local_builder.CreateAlloca(type, nullptr, *local_var);
}

void ast_program::CodeGen() {
    named_values.enter_scope();
    module = llvm::make_unique<llvm::Module>("my cool jit",
        llvm_context);

    for (ListI lit = external_declarations->begin(); 
            lit != external_declarations->end(); lit++) {
        (*lit)->CodeGen();
    }
    
    module->print(llvm::errs(), nullptr);
    named_values.exit_scope();
}

void ast_external_declaration::CodeGen() {
    if (index == 0) {
        data.declaration->CodeGenGlobal();
    } else if (index == 1) {
        data.function_definition->CodeGen();
    } else {
        my_assert(0, __LINE__, __FILE__);
    }
}

llvm::Value* ast_identifier_expression::CodeGen() {
    llvm::Value* value = named_values.lookup(identifier);
    set_type(named_types.lookup(identifier));
    return builder.CreateLoad(value, identifier->c_str());
}

llvm::Value* ast_i_constant::CodeGen() {
    int val = atoi(i_constant->c_str());
    set_type(Int);
    return llvm::ConstantInt::get(llvm_context, 
        llvm::APInt(32, val, true));
}

llvm::Value* ast_f_constant::CodeGen() {
    double val = atof(f_constant->c_str());
    set_type(Float);
    return llvm::ConstantFP::get(llvm_context, llvm::APFloat(val));
}

llvm::Value* ast_no_expression::CodeGen() {
    set_type(Undefined);
    return NULL;
}

Symbol ast_type_specifier::get_type_specifier() {
    return type_specifier;
}

llvm::Type* get_llvm_type(Symbol type_specifier) {
    if (type_specifier == Int) {
        return llvm::Type::getInt32Ty(llvm_context);
    } else if (type_specifier == Float) {
        return llvm::Type::getFloatTy(llvm_context);
    } else if (type_specifier == Void) {
        return NULL;
    }

    my_assert(0, __LINE__, __FILE__);
    return NULL;
}

llvm::Value* get_default_value(llvm::Type* type) {
    if (type->isIntegerTy()) {
        return llvm::ConstantInt::get(llvm_context, 
            llvm::APInt(32, 0, true));
    } else if (type->isFloatTy()) {
        return llvm::ConstantFP::get(llvm_context, 
            llvm::APFloat(0.));
    }

    my_assert(0, __LINE__, __FILE__);
    return NULL;
}

Symbol get_symbol_type(llvm::Type* type) {
    if (type->isIntegerTy()) {
        return Int;
    } else if (type->isFloatTy()) {
        return Float;
    }

    my_assert(0, __LINE__, __FILE__);
    return NULL;
}

void ast_declaration::CodeGenGlobal() {
    llvm::Type* type = get_llvm_type(type_specifier->get_type_specifier());

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

void ast_identifier_declarator::CodeGenGlobal(llvm::Type* type) {
    llvm::GlobalVariable* var = new llvm::GlobalVariable(/*Module=*/*module, 
        /*Type=*/type,
        /*isConstant=*/false,
        /*Linkage=*/llvm::GlobalValue::CommonLinkage,
        /*Initializer=*/0, // has initializer, specified below
        /*Name=*/identifier->c_str());
    var->setAlignment(4);
}

void ast_declaration::CodeGenLocal() {
    llvm::Type* type = ::get_llvm_type(type_specifier->get_type_specifier());

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

void ast_identifier_declarator::CodeGenLocal(llvm::Type* type) {
    llvm::Function* function = builder.GetInsertBlock()->getParent();
    llvm::AllocaInst* alloca = ::CreateEntryBlockAlloca(type, function, identifier);
    named_values.insert(identifier,alloca);
    named_types.insert(identifier, ::get_symbol_type(type));
    builder.CreateStore(get_default_value(type), alloca);    
}

llvm::Value* ast_compound_statement::CodeGen() {
    named_values.enter_scope();
    named_types.enter_scope();

    llvm::Value* last_value = NULL;    
    for (ListI lit = block_items->begin(); lit != block_items->end();
            lit++) {
        last_value = (*lit)->CodeGen();
    }

    named_values.exit_scope();
    named_types.exit_scope();
    return last_value;
}

llvm::Value* ast_expression_statement::CodeGen() {
    return expression->CodeGen();
}

llvm::Function* ast_function_declarator::CodeGenGlobal(llvm::Type* type){
    std::vector<llvm::Type*> arg_types;
    for(ListI lit = parameter_declarations->begin(); 
        lit!= parameter_declarations->end(); lit++){
            Symbol type = (*lit)->get_type();
            arg_types.push_back(::get_llvm_type(type));
    }

    llvm::FunctionType* function_type = llvm::FunctionType::get(type, 
        arg_types, false);

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

llvm::Function* ast_function_definition::CodeGen() {
    named_values.enter_scope();
    named_types.enter_scope();

    ast_function_declarator* fun_decl = declarator->get_fun_decl();
    fun_decls.insert(make_pair(fun_decl->get_identifier(), fun_decl));
    Symbol return_type = type_specifier->get_type_specifier();
    llvm::Function* function = ::get_function(::get_llvm_type(return_type), fun_decl->get_identifier());
    llvm::FunctionType* function_type = function->getFunctionType();
    llvm::BasicBlock* basic_block = llvm::BasicBlock::Create(
        llvm_context, "entry", function);
    builder.SetInsertPoint(basic_block);

    unsigned int index = 0;

    for (auto& farg : function->args()) {
        llvm::Type* type = function_type->getParamType(index++);
        llvm::AllocaInst* alloca = ::CreateEntryBlockAlloca(type, function, 
            id_table.add_string(farg.getName()));
        builder.CreateStore(&farg, alloca);
        named_values.insert(id_table.add_string(farg.getName()),
            alloca);
        named_types.insert(id_table.add_string(farg.getName()),
            ::get_symbol_type(type));
    }

    llvm::Value* ret_val = compound_statement->CodeGen();
    builder.CreateRet(ret_val);
    llvm::verifyFunction(*function);

    named_values.exit_scope();
    named_types.exit_scope();
    
    return function;
}

llvm::Value* ast_block_item::CodeGen() {
    if (index == 0) {
        data.declaration->CodeGenLocal();
        return NULL;
    } else if (index == 1) {
        return data.statement->CodeGen();
    }

    my_assert(0, __LINE__, __FILE__);
    return NULL;
}

llvm::Value* ast_postfix_expression::CodeGen(){

    llvm::Function* function = module->getFunction(*function_name);
    if(function->arg_size() != arguments->size())
        my_assert(0, __LINE__, __FILE__);

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

llvm::Value* ast_mul_expression::CodeGen(){
    llvm::Value* e1_eval = e1->CodeGen();
    llvm::Value* e2_eval = e2->CodeGen();

    if (e1->get_type() == Int && e2->get_type() == Int){
        set_type(Int);
        return builder.CreateMul(e1_eval, e2_eval, "multmp");
    }else {
        set_type(Float);
        return builder.CreateFMul(e1_eval, e2_eval, "multmp");
    }
}

llvm::Value* ast_add_expression::CodeGen(){
    llvm::Value* e1_eval = e1->CodeGen();
    llvm::Value* e2_eval = e2->CodeGen();

    if (e1->get_type() == Int && e2->get_type() == Int){
        set_type(Int);
        return builder.CreateAdd(e1_eval, e2_eval, "addtmp");
    }else {
        set_type(Float);
        return builder.CreateFAdd(e1_eval, e2_eval, "addtmp");
    }
}


llvm::Value* ast_sub_expression::CodeGen(){
    llvm::Value* e1_eval = e1->CodeGen();
    llvm::Value* e2_eval = e2->CodeGen();

    if (e1->get_type() == Int && e2->get_type() == Int){
        set_type(Int);
        return builder.CreateSub(e1_eval, e2_eval, "subtmp");
    }else {
        set_type(Float);
        return builder.CreateFSub(e1_eval, e2_eval, "subtmp");
    }
}


llvm::Value* ast_less_expression::CodeGen(){
    llvm::Value* e1_eval = e1->CodeGen();
    llvm::Value* e2_eval = e2->CodeGen();

    if (e1->get_type() == Int && e2->get_type() == Int){
        set_type(Int);
        return builder.CreateICmpSLT(e1_eval, e2_eval, "lesstmp");
    }else {
        set_type(Float);
        return builder.CreateFCmpOLT(e1_eval, e2_eval, "lesstmp");
    }
}

llvm::Value* ast_leq_expression::CodeGen(){
    llvm::Value* e1_eval = e1->CodeGen();
    llvm::Value* e2_eval = e2->CodeGen();

    if (e1->get_type() == Int && e2->get_type() == Int){
        set_type(Int);
        return builder.CreateICmpSLE(e1_eval, e2_eval, "leqtmp");
    }else {
        set_type(Float);
        return builder.CreateFCmpOLE(e1_eval, e2_eval, "leqtmp");
    }
}


llvm::Value* ast_eq_expression::CodeGen(){
    llvm::Value* e1_eval = e1->CodeGen();
    llvm::Value* e2_eval = e2->CodeGen();

    if (e1->get_type() == Int && e2->get_type() == Int){
        set_type(Int);
        return builder.CreateICmpEQ(e1_eval, e2_eval, "eqtmp");
    }else {
        set_type(Float);
        return builder.CreateFCmpOEQ(e1_eval, e2_eval, "eqtmp");
    }
}


llvm::Value* ast_assign_expression::CodeGen(){
    
    llvm::Value* e_val = expression->CodeGen();
    if(!e_val)
        return nullptr;
    
    llvm::Value* v_address = named_values.lookup(identifier);
    if(!v_address)
        return nullptr;

    builder.CreateStore(e_val, v_address); 
    set_type(named_types.lookup(identifier));
    return e_val;  
}




/*------------------------------------------------------.
|   Section 2 : Print AST nodes along with their types. |
`------------------------------------------------------*/

std::ostream& ast_program::print_struct(int d, std::ostream& s) {
    pad(d, s) << ".program" << std::endl;
    
    for (ListI lit = external_declarations->begin();
            lit != external_declarations->end(); lit++) {
        (*lit)->print_struct(d+1, s) << std::endl;
    }

    return s;
}

Symbol ast_expression::get_type() {
    return type;
}

void ast_expression::set_type(Symbol type) {
    this->type = type;
} 

std::ostream& ast_identifier_expression::print_struct(int d, std::ostream& s) {
    pad(d, s) << *identifier << ": " << *get_type() << std::endl;
    return s;
}

std::ostream& ast_i_constant::print_struct(int d, std::ostream& s) {
    pad(d, s) << *i_constant << ": " << *get_type() << std::endl;
    return s;
}

std::ostream& ast_f_constant::print_struct(int d, std::ostream& s) {
    pad(d, s) << *f_constant << ": " << *get_type() << std::endl;
    return s;
}

std::ostream& ast_declaration::print_struct(int d, std::ostream& s) {
    pad(d, s) << ".declaration" << std::endl;
    type_specifier->print_struct(d+1, s);

    for (ListI lit = init_declarators->begin(); lit != init_declarators->end(); lit++) {
        ast_init_declarator* init_declarator = *lit;
        init_declarator->print_struct(d+1, s);
    }

    return s;
}

std::ostream& ast_type_specifier::print_struct(int d, std::ostream& s) {
    pad(d, s) << *type_specifier << std::endl;
    return s;
}

std::ostream& ast_init_declarator::print_struct(int d, std::ostream& s) {
    pad(d, s) << ".init_declarator" << std::endl;
    declarator->print_struct(d+1, s);
    return s;
}

std::ostream& ast_identifier_declarator::print_struct(int d, std::ostream& s) {
    pad(d, s) << *identifier << std::endl;
    return s;
}

std::ostream& ast_function_declarator::print_struct(int d, std::ostream& s) {
    pad(d, s) << ".function_declarator" << std::endl;
    pad(d+1,s) << *identifier << std::endl;

    for (ListI lit = parameter_declarations->begin(); 
            lit != parameter_declarations->end(); lit++) {
        ast_parameter_declaration* parameter_declaration = *lit;
        parameter_declaration->print_struct(d+1, s);
    }

    return s;
}

std::ostream& ast_parameter_declaration::print_struct(int d, std::ostream& s) {
    pad(d, s) << ".parameter_declaration" << std::endl;
    type_specifier->print_struct(d+1, s);
    declarator->print_struct(d+1, s);
    return s;
}

std::ostream& ast_compound_statement::print_struct(int d, std::ostream& s) {
    pad(d, s) << ".compound_statement" << std::endl;

    for (ListI lit = block_items->begin(); lit != block_items->end(); lit++) {
        ast_block_item* block_item = *lit;
        block_item->print_struct(d+1, s);
    }

    return s;
}

std::ostream& ast_expression_statement::print_struct(int d, std::ostream& s) {
    pad(d, s) << ".expression_statement" << std::endl;
    expression->print_struct(d+1, s);
    return s;
}

std::ostream& ast_no_expression::print_struct(int d, std::ostream& s) {
    pad(d, s) << *get_type() << std::endl;
    return s;
}

std::ostream& ast_function_definition::print_struct(int d, std::ostream& s) {
    pad(d, s) << ".function_definition" << std::endl;
    type_specifier->print_struct(d+1, s);
    declarator->print_struct(d+1, s);
    compound_statement->print_struct(d+1, s);
    return s;
}

std::ostream& ast_block_item::print_struct(int d, std::ostream& s) {
    pad(d, s) << ".block_item" << std::endl;

    if (index == 0) {
        data.declaration->print_struct(d+1, s);
    } else if (index == 1) {
        data.statement->print_struct(d+1, s);
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
    for(argI ait = arguments->begin(); ait!= arguments->end(); ait++){
        (*ait)->print_struct(d+1, s);
    }     
    return s;
}

std::ostream& ast_unary_expression::print_struct(int d, std::ostream& s) {
    pad(d, s) << ".unary_expression" << std::endl;
    pad(d+1, s)<<unary <<std::endl;
    expression->print_struct(d+1, s); 
    return s;
}

std::ostream& ast_add_expression::print_struct(int d, std::ostream& s) {
    pad(d, s) << ".add_expression" << std::endl;
    e1->print_struct(d+1, s);  
    e2->print_struct(d+1, s); 

    return s;
}

std::ostream& ast_sub_expression::print_struct(int d, std::ostream& s) {
    pad(d, s) << ".sub_expression" << std::endl;
    e1->print_struct(d+1, s);  
    e2->print_struct(d+1, s); 

    return s;
}

std::ostream& ast_mul_expression::print_struct(int d, std::ostream& s) {
    pad(d, s) << ".multiply_expression" << std::endl;
    e1->print_struct(d+1, s);  
    e2->print_struct(d+1, s); 
    return s;
}

std::ostream& ast_less_expression::print_struct(int d, std::ostream& s) {
    pad(d, s) << ".less_expression" << std::endl;
    e1->print_struct(d+1, s);  
    e2->print_struct(d+1, s); 

    return s;
}

std::ostream& ast_leq_expression::print_struct(int d, std::ostream& s) {
    pad(d, s) << ".leq_expression" << std::endl;
    e1->print_struct(d+1, s);  
    e2->print_struct(d+1, s); 

    return s;
}

std::ostream& ast_eq_expression::print_struct(int d, std::ostream& s) {

    pad(d, s) << ".equality_expression" << std::endl;
    e1->print_struct(d+1, s);  
    e2->print_struct(d+1, s);  
  
    return s;
}

std::ostream& ast_assign_expression::print_struct(int d, std::ostream& s) {
    pad(d, s) << ".assign_expression" << std::endl;
    pad(d+1, s)<< *identifier <<std::endl;
    expression->print_struct(d+1, s);   
    return s;
}

std::ostream& ast_direct_declarator::print_struct(int d, std::ostream& s) {
    pad(d, s) << ".direct_declarator" << std::endl;

    if (index == 0) {
        data.identifier_declarator->print_struct(d+1, s);
    } else if (index == 1) {
        data.function_declarator->print_struct(d+1, s);
    }

    return s;
}

std::ostream& ast_declarator::print_struct(int d, std::ostream& s) {
    pad(d, s) << ".declarator" << std::endl;
    direct_declarator->print_struct(d+1, s);
    return s;
}


/*---------------------------------------------------.
|   Section 2 : Contructors of tree nodes in AST.    |
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

ast_parameter_declaration::ast_parameter_declaration(
        ast_type_specifier* type_specifier,
        ast_declarator* declarator)
    : type_specifier(type_specifier),
        declarator(declarator) {}

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

ast_function_declarator::ast_function_declarator(Symbol identifier,
        ast_parameter_declaration_list* parameter_declarations)
        : identifier(identifier), 
        parameter_declarations(parameter_declarations) {}

std::ostream& pad(int d, std::ostream& s) {
    my_assert(d >= 0, __LINE__, __FILE__);

    for (int i = 0; i < d; i++) {
        s << '\t';
    }

    return s;
}