#ifndef PARSE_H
#define PARSE_H

#include "tree.h"

union YYSTYPE {
	ast_program* program;
	ast_expression* expression;
	ast_block_item* block_item;
	ast_type_specifier* type_specifier;
	ast_init_declarator_list* init_declarators;
	ast_init_declarator* init_declarator;
	ast_declarator* declarator;
	ast_direct_declarator* direct_declarator;
	ast_parameter_declaration_list* parameter_declarations;
	ast_parameter_declaration* parameter_declaration;
	ast_compound_statement* compound_statement;
	ast_block_item_list* block_items;
	ast_external_declaration* external_declaration;
    Symbol symbol;
};

extern YYSTYPE yylval;

#endif