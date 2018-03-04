%{
#include <cstdio>
#include <iostream>
using namespace std;

// stuff from flex that bison needs to know about:
extern "C" int yylex();
int yyparse();
extern "C" FILE *yyin;
 
void yyerror(const char *s);

// Declare the constructed AST root.
#include "parser.h"
ast_program* program;
%}

%define api.value.type {union YYSTYPE}

%type <expression> primary_expression
%type <expression> constant
%type <expression> expression
%type <declaration> declaration
%type <type_specifier>	declaration_specifiers
%type <init_declarators> init_declarator_list
%type <init_declarator> init_declarator
%type <declarator> declarator
%type <declarator> direct_declarator
%type <parameter_declarations> parameter_type_list
%type <parameter_declarations> parameter_list
%type <parameter_declaration> parameter_declaration
%type <statement> statement
%type <expression_statement> expression_statement
%type <compound_statement> compound_statement
%type <block_items> block_item_list
%type <block_item> block_item
%type <external_declarations> translation_unit
%type <external_declaration> external_declaration
%type <function_definition> function_definition  

%token	IDENTIFIER I_CONSTANT F_CONSTANT STRING_LITERAL FUNC_NAME SIZEOF
%token	PTR_OP INC_OP DEC_OP LEFT_OP RIGHT_OP LE_OP GE_OP EQ_OP NE_OP
%token	AND_OP OR_OP MUL_ASSIGN DIV_ASSIGN MOD_ASSIGN ADD_ASSIGN
%token	SUB_ASSIGN LEFT_ASSIGN RIGHT_ASSIGN AND_ASSIGN
%token	XOR_ASSIGN OR_ASSIGN
%token	TYPEDEF_NAME ENUMERATION_CONSTANT

%token	TYPEDEF EXTERN STATIC AUTO REGISTER INLINE
%token	CONST RESTRICT VOLATILE
%token	BOOL CHAR SHORT INT LONG SIGNED UNSIGNED FLOAT DOUBLE VOID
%token	COMPLEX IMAGINARY 
%token	STRUCT UNION ENUM ELLIPSIS

%token	CASE DEFAULT IF ELSE SWITCH WHILE DO FOR GOTO CONTINUE BREAK RETURN

%token	ALIGNAS ALIGNOF ATOMIC GENERIC NORETURN STATIC_ASSERT THREAD_LOCAL

%start program
%%

program
	: translation_unit
	;

primary_expression
	: IDENTIFIER
	| constant
	| '(' expression ')'
	;

constant
	: I_CONSTANT		/* includes character_constant */
	| F_CONSTANT
	;

expression
	: primary_expression
	;

declaration
	: declaration_specifiers init_declarator_list ';'
	;

declaration_specifiers
	: type_specifier
	;

init_declarator_list
	: init_declarator
	| init_declarator_list ',' init_declarator
	;

init_declarator
	: declarator
	;

type_specifier
	: VOID
	| CHAR
	| INT
	| FLOAT
	;

declarator
	: direct_declarator
	;

direct_declarator
	: IDENTIFIER
	| direct_declarator '(' parameter_type_list ')'
	| direct_declarator '(' ')'
	;

parameter_type_list
	: parameter_list
	;

parameter_list
	: parameter_declaration
	| parameter_list ',' parameter_declaration
	;

parameter_declaration
	: declaration_specifiers declarator
	;

statement
	: compound_statement
	| expression_statement
	;

compound_statement
	: '{' '}'
	| '{'  block_item_list '}'
	;

block_item_list
	: block_item
	| block_item_list block_item
	;

block_item
	: declaration
	| statement
	;

expression_statement
	: ';'
	| expression ';'
	;

translation_unit
	: external_declaration
	;

external_declaration
	: function_definition
	;

function_definition
	: declaration_specifiers declarator compound_statement
	;

%%
#include <stdio.h>

void yyerror(const char *s)
{
	fflush(stdout);
	fprintf(stderr, "*** %s\n", s);
}
