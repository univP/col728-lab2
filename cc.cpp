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
extern "C" ast_program* root;

int
main(int argc, char **argv)
{
    if (argc != 2) {
        usage();
        exit(1);
    }
    char const *filename = argv[1];
    yyin = fopen(filename, "r");
    assert(yyin);
    int ret = yyparse();
    printf("retv = %d\n", ret);
    exit(0);
}

/*----------------------------------------------.
|   Section 2 : Symbol definitions of tree.h    |
`----------------------------------------------*/

ast_program::ast_program(ast_external_declaration* external_declaration)
    : external_declaration(external_declaration) {}

ast_identifier_expression::ast_identifier_expression(Symbol identifier)
    : identifier(identifier) {}

ast_i_constant::ast_i_constant(Symbol i_constant)
    : i_constant(i_constant) {}

ast_f_constant::ast_f_constant(Symbol f_constant)
    : f_constant(f_constant) {}

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