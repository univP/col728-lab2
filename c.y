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

%type <program> program
%type <expression> primary_expression
%type <expression> constant
%type <expression> expression
%type <declaration> declaration
%type <type_specifier>	declaration_specifiers
%type <init_declarators> init_declarator_list
%type <init_declarator> init_declarator
%type <type_specifier> type_specifier
%type <declarator> declarator
%type <direct_declarator> direct_declarator
%type <parameter_declarations> parameter_type_list
%type <parameter_declarations> parameter_list
%type <parameter_declaration> parameter_declaration
%type <statement> statement
%type <compound_statement> compound_statement
%type <block_items> block_item_list
%type <block_item> block_item
%type <expression> expression_statement
%type <external_declarations> translation_unit
%type <external_declaration> external_declaration
%type <function_definition> function_definition
%type <expression> postfix_expression
%type <arguments> argument_expression_list
%type <expression> unary_expression
%type <unary> unary_operator
%type <expression> multiplicative_expression
%type <expression> additive_expression
%type <expression> relational_expression
%type <expression> equality_expression
%type <expression> assignment_expression

%token	<symbol> IDENTIFIER I_CONSTANT F_CONSTANT 
%token 	STRING_LITERAL FUNC_NAME SIZEOF
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
	{ program = new ast_program($1); }
	;

primary_expression
	: IDENTIFIER
	{ $$ = new ast_identifier_expression($1); }
	| constant
	{ $$ = $1; }
	| '(' expression ')'
	{ $$ = $2; }
	;

constant
	: I_CONSTANT		/* includes character_constant */
	{ $$ = new ast_i_constant($1); }
	| F_CONSTANT
	{ $$ = new ast_f_constant($1); }
	;

postfix_expression
	: primary_expression
	{ $$ = $1; }
	| IDENTIFIER '(' ')'
	{ $$ = new ast_postfix_expression($1,new ast_argument_list()); }
	| IDENTIFIER '(' argument_expression_list ')'
	{ $$ = new ast_postfix_expression($1, $3); }
	;

argument_expression_list
	: assignment_expression
	{ $$ = new ast_argument_list(); $$->push_back($1);  }
	| argument_expression_list ',' assignment_expression
	{ $$ = $1; $$->push_back($3); }
	;

unary_expression
	: postfix_expression
	{ $$ = $1; }
	| unary_operator primary_expression
	{ $$ = new ast_unary_expression($1, $2); }
	;

unary_operator
	: '~'
	{ $$ = '~'; }
	| '-'
	{ $$ = '-'; }
	| '!'
	{ $$ = '!'; }
	;

multiplicative_expression
	: unary_expression
	{ $$ = $1; }
	| multiplicative_expression '*' unary_expression
	{ $$ = new ast_mul_expression($1, $3); }
	;

additive_expression
	: multiplicative_expression
	{ $$ = $1; }
	| additive_expression '+' multiplicative_expression
	{ $$ = new ast_add_expression($1, $3); }
	| additive_expression '-' multiplicative_expression
	{ $$ = new ast_sub_expression($1, $3); }
	;

relational_expression
	: additive_expression
	{ $$ = $1; }
	| relational_expression '<' additive_expression
	{ $$ = new ast_less_expression($1, $3); }
	| relational_expression LE_OP additive_expression
	{ $$ = new ast_leq_expression($1, $3); }
	;

equality_expression
	: relational_expression
	{ $$ = $1; }
	| equality_expression EQ_OP relational_expression
	{ $$ = new ast_eq_expression($1, $3); }
	;

assignment_expression
	: equality_expression
	{ $$ = $1; }
	| IDENTIFIER '=' assignment_expression
	{ $$ = new ast_assign_expression($1, $3); }
	;

expression
	: assignment_expression
	{ $$ = $1; }
	;

declaration
	: declaration_specifiers init_declarator_list ';'
	{ $$ = new ast_declaration($1, $2); }
	;

declaration_specifiers
	: type_specifier
	{ $$ = $1; }
	;

init_declarator_list
	: init_declarator
	{ $$ = new ast_init_declarator_list();
		$$->push_back($1); }
	| init_declarator_list ',' init_declarator
	{ $1->push_back($3);
		$$ = $1; }
	;

init_declarator
	: declarator
	{ $$ = new ast_init_declarator($1); }
	;

type_specifier
	: VOID
	{ $$ = new ast_type_specifier(id_table.add_string("void")); }
	| CHAR
	{ $$ = new ast_type_specifier(id_table.add_string("char")); }
	| INT
	{ $$ = new ast_type_specifier(id_table.add_string("int")); }
	| FLOAT
	{ $$ = new ast_type_specifier(id_table.add_string("float")); }
	;

declarator
	: direct_declarator
	{ $$ = new ast_declarator($1); }
	;

direct_declarator
	: IDENTIFIER
	{ $$ = new ast_direct_declarator(new ast_identifier_declarator($1)); }
	| IDENTIFIER '(' parameter_type_list ')'
	{ $$ = new ast_direct_declarator(new ast_function_declarator($1, $3)); }
	| IDENTIFIER '(' ')'
	{ $$ = new ast_direct_declarator(new ast_function_declarator(
		$1, new ast_parameter_declaration_list())); }
	;

parameter_type_list
	: parameter_list
	{ $$ = $1; }
	;

parameter_list
	: parameter_declaration
	{ $$ = new ast_parameter_declaration_list(); 
		$$->push_back($1); }
	| parameter_list ',' parameter_declaration
	{ $1->push_back($3);
		$$ = $1; }
	;

parameter_declaration
	: declaration_specifiers declarator
	{ $$ = new ast_parameter_declaration($1, $2); }
	;

statement
	: compound_statement
	{ $$ = $1; }
	| expression_statement
	{ $$ = new ast_expression_statement($1); }
	| selection_statement
	{ $$ = NULL; }
	;

compound_statement
	: '{' '}'
	{ $$ = new ast_compound_statement(new ast_block_item_list()); }
	| '{'  block_item_list '}'
	{ $$ = new ast_compound_statement($2); }
	;

block_item_list
	: block_item
	{ $$ = new ast_block_item_list();
		$$->push_back($1); }
	| block_item_list block_item
	{ $1->push_back($2);
		$$ = $1; }
	;

block_item
	: declaration
	{ $$ = new ast_block_item($1); }
	| statement
	{ $$ = new ast_block_item($1); }
	;

expression_statement
	: ';'
	{ $$ = new ast_no_expression(); }
	| expression ';'
	{ $$ = $1; }
	;

selection_statement
	: IF '(' expression ')' statement ELSE statement
	| IF '(' expression ')' statement
	;

translation_unit
	: external_declaration
	{ $$ = new ast_external_declaration_list();
		$$->push_back($1); }
	| translation_unit external_declaration
	{ $1->push_back($2);
		$$ = $1; }
	;

external_declaration
	: function_definition
	{ $$ = new ast_external_declaration($1); }
	| declaration
	{ $$ = new ast_external_declaration($1); }
	;

function_definition
	: declaration_specifiers declarator compound_statement
	{ $$ = new ast_function_definition($1, $2, $3); }
	;

%%
#include <stdio.h>

void yyerror(const char *s)
{
	fflush(stdout);
	fprintf(stderr, "*** %s\n", s);
}
