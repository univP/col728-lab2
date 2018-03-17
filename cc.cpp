#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
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

    exit(0);
}

llvm::Value* ast_identifier_expression::CodeGen(CodeGenContext* context) {
    llvm::Value* value = context->named_values.lookup(identifier);
    return value;
}

llvm::Value* ast_i_constant::CodeGen(CodeGenContext* context) {
    int val = atoi(i_constant->c_str());
    return llvm::ConstantInt::get(context->llvm_context, 
        llvm::APInt(32, val, true));
}

llvm::Value* ast_f_constant::CodeGen(CodeGenContext* context) {
    double val = atof(f_constant->c_str());
    return llvm::ConstantFP::get(context->llvm_context, llvm::APFloat(val));
}

llvm::Value* ast_no_expression::CodeGen(CodeGenContext* context) {
    return NULL;
}

Arg::Arg(Symbol type_specifier, Symbol arg_name): 
    type_specifier(type_specifier), arg_name(arg_name) {}

Symbol Arg::get_type_specifier() {
    return type_specifier;
}

Symbol Arg::get_arg_name() {
    return arg_name;
}

Symbol ast_type_specifier::get_type_specifier() {
    return type_specifier;
}

Arg* ast_parameter_declaration::get_arg() {
    assert(declarator->get_identifier() != NULL);
    return new Arg(type_specifier->get_type_specifier(), 
        declarator->get_identifier());
}

Symbol ast_identifier_declarator::get_identifier() {
    return identifier;
}

Symbol ast_function_declarator::get_identifier() {
    return NULL;
}

llvm::Function* ast_identifier_declarator::get_function(llvm::Type* return_type,
        CodeGenContext* context) {
    return NULL;
}

llvm::Type* get_llvm_type(Symbol type_specifier, CodeGenContext* context) {
    if (type_specifier == Int) {
        return llvm::Type::getInt32Ty(context->llvm_context);
    } else if (type_specifier == Float) {
        return llvm::Type::getFloatTy(context->llvm_context);
    }

    return NULL;
}

llvm::Function* ast_function_declarator::get_function(llvm::Type* return_type,
        CodeGenContext* context) {
    Symbol function_name = direct_declarator->get_identifier();
    assert(function_name != NULL);
    std::vector<llvm::Type*> param_types;

    for (ListI lit = parameter_declarations->begin(); 
            lit != parameter_declarations->end(); lit++) {
        Arg* arg = (*lit)->get_arg();
        param_types.push_back(get_llvm_type(arg->get_type_specifier(),
            context));
    }

    llvm::FunctionType* function_type = llvm::FunctionType::get(return_type,
        param_types, false);

    llvm::Function* function = llvm::Function::Create(function_type,
        llvm::Function::ExternalLinkage, *function_name, context->module.get());

    return function;
}

/*------------------------------------------------------.
|   Section 2 : Print AST nodes along with their types. |
`------------------------------------------------------*/

std::ostream& ast_program::print_struct(int d, std::ostream& s) {
    pad(d, s) << ".program" << std::endl;
    external_declaration->print_struct(d+1, s) << std::endl;
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
    direct_declarator->print_struct(d+1, s);

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

/*---------------------------------------------------.
|   Section 2 : Contructors of tree nodes in AST.    |
`---------------------------------------------------*/

ast_program::ast_program(ast_external_declaration* external_declaration)
    : external_declaration(external_declaration) {}

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

ast_function_declarator::ast_function_declarator(
        ast_direct_declarator* direct_declarator,
        ast_parameter_declaration_list* parameter_declarations)
    : direct_declarator(direct_declarator),
        parameter_declarations(parameter_declarations) {}

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

std::ostream& pad(int d, std::ostream& s) {
    assert(d >= 0);

    for (int i = 0; i < d; i++) {
        s << '\t';
    }

    return s;
}