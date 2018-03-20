#ifndef PARSE_H
#define PARSE_H

#include "context.h"

union YYSTYPE {
	ast_program* program;
	ast_expression* expression;
	ast_block_item* block_item;
	ast_declaration* declaration;
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
	ast_external_declaration_list* external_declarations;
	ast_function_definition* function_definition;
	ast_statement* statement;
    Symbol symbol;
	ast_argument_list* arguments;
	ast_expression_statement* expression_statement;
	char unary;
};

extern YYSTYPE yylval;

#endif