#ifndef TREE_H
#define TREE_H

#include "list.h"
#include "table.h"

// Forward declarations
class ast_struct;
class ast_program;
class ast_external_declaration;
class ast_function_definition;

class ast_declaration; // subtype of block_item

class ast_type_specifier;

class ast_init_declarator;
class ast_declarator;
class ast_direct_declarator; // subclass of ast_declarator
class ast_identifier; // subclass of ast_declarator
class ast_parameter_declaration;

class ast_statement; // subtype of block_item

class ast_compound_statement;
class ast_block_item;

class ast_expression_statement;
class ast_expression;
class ast_primary_expression;
class ast_constant;
class ast_i_constant;
class ast_f_constant;


#endif