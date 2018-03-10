#ifndef PARSE_H
#define PARSE_H

#include "tree.h"

union YYSTYPE {
	ast_program* program;
	ast_expression* expression;
	ast_block_item* block_item;
	ast_type_specifier* type_specifier;
	List<ast_init_declarator>* init_declarators;
	ast_init_declarator* init_declarator;
	ast_declarator* declarator;
	ast_direct_declarator* direct_declarator;
	List<ast_parameter_declaration>* parameter_declarations;
	ast_parameter_declaration* parameter_declaration;
	ast_compound_statement* compound_statement;
	List<ast_block_item>* block_items;
	ast_external_declaration* external_declaration;
    Symbol symbol;
};

extern YYSTYPE yylval;

#endif