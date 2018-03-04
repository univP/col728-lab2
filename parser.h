#ifndef PARSE_H
#define PARSE_H

#include "tree.h"

union YYSTYPE {
	ast_program* program;
	List<ast_external_declaration>* external_declarations;
	ast_external_declaration* external_declaration;
	ast_declaration* declaration;
	ast_type_specifier* type_specifier;
	List<ast_init_declarator>* init_declarators;
	ast_init_declarator* init_declarator;
	ast_declarator* declarator;
	List<ast_parameter_declaration>* parameter_declarations;
	ast_parameter_declaration* parameter_declaration;
	ast_statement* statement;
	List<ast_block_item>* block_items;
	ast_block_item* block_item;
	ast_expression* expression;
	ast_expression_statement* expression_statement;
	ast_compound_statement* compound_statement;
	ast_function_definition* function_definition;
    Symbol symbol;
};

extern YYSTYPE yylval;

#endif