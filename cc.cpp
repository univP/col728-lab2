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

Symbol
    Void = id_table.add_string("int"),
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
    pad(d, s) << identifier->get_str() << ": " << get_type()->get_str() << std::endl;
    return s;
}

std::ostream& ast_i_constant::print_struct(int d, std::ostream& s) {
    pad(d, s) << i_constant->get_str() << ": " << get_type()->get_str() << std::endl;
    return s;
}

std::ostream& ast_f_constant::print_struct(int d, std::ostream& s) {
    pad(d, s) << f_constant->get_str() << ": " << get_type()->get_str() << std::endl;
    return s;
}

std::ostream& ast_declaration::print_struct(int d, std::ostream& s) {
    pad(d, s) << ".declaration" << std::endl;
    type_specifier->print_struct(d+1, s);

    for (List<ast_init_declarator>* l = init_declarators; l; l = l->get_tail()) {
        l->get_head()->print_struct(d+1, s);
    }

    return s;
}

std::ostream& ast_type_specifier::print_struct(int d, std::ostream& s) {
    pad(d, s) << type_specifier->get_str() << std::endl;
    return s;
}

std::ostream& ast_init_declarator::print_struct(int d, std::ostream& s) {
    pad(d, s) << ".init_declarator" << std::endl;
    declarator->print_struct(d+1, s);
}

std::ostream& ast_identifier_declarator::print_struct(int d, std::ostream& s) {
    pad(d, s) << identifier->get_str() << std::endl;
    return s;
}

std::ostream& ast_function_declarator::print_struct(int d, std::ostream& s) {
    pad(d, s) << ".function_declarator" << std::endl;
    direct_declarator->print_struct(d+1, s);

    for (List<ast_parameter_declaration>* l = parameter_declarations; l; l = l->get_tail()) {
        l->get_head()->print_struct(d+1, s);
    }

    return s;
}

std::ostream& ast_parameter_declaration::print_struct(int d, std::ostream& s) {
    pad(d, s) << ".parameter_declaration" << std::endl;
    type_specifier->print_struct(d+1, s);
    declarator->print_struct(d+1, s);
}

std::ostream& ast_compound_statement::print_struct(int d, std::ostream& s) {
    pad(d, s) << ".compound_statement" << std::endl;

    for (List<ast_block_item>* l = block_items; l; l = l->get_tail()) {
        l->get_head()->print_struct(d+1, s);
    }

    return s;
}

std::ostream& ast_expression_statement::print_struct(int d, std::ostream& s) {
    pad(d, s) << ".expression_statement" << std::endl;
    expression->print_struct(d+1, s);
    return s;
}

std::ostream& ast_no_expression::print_struct(int d, std::ostream& s) {
    pad(d, s) << get_type()->get_str() << std::endl;
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
        List<ast_init_declarator>* init_declarators)
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
        List<ast_parameter_declaration>* parameter_declarations)
    : direct_declarator(direct_declarator),
        parameter_declarations(parameter_declarations) {}

ast_parameter_declaration::ast_parameter_declaration(
        ast_type_specifier* type_specifier,
        ast_declarator* declarator)
    : type_specifier(type_specifier),
        declarator(declarator) {}

ast_compound_statement::ast_compound_statement(List<ast_block_item>* block_items)
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

/*--------------------------------------------------.
|   Section 3 : Symbol definitions for stringtab.h  |
`--------------------------------------------------*/

Entry::Entry(int index, std::string str): index(index), str(str) {}

int Entry::get_index() { return index; }

std::string Entry::get_str() { return str; }

Table::Table(): table(NULL), len(0) {}

Symbol Table::add_string(std::string str) {
    for (List<Entry>* l = table; l; l = l->get_tail()) {
        if (l->get_head()->get_str() == str) {
            return l->get_head();
        }
    }

    Symbol symbol = new Entry(len++, str);
    table = new List<Entry>(symbol, table);
    return symbol;
}

List<Entry>* Table::get_table() {
    return table;
}

int Table::get_len() {
    return len;
}