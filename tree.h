#ifndef TREE_H
#define TREE_H

#include "table.h"

// Forward declarations
class ast_struct;
class ast_program;

class ast_expression;                   // Subclasses of ast_expression below
class ast_identifier_expression;  
class ast_i_constant;
class ast_f_constant;
class ast_no_expression;

class ast_block_item;
class ast_declaration;                  // subclass of block_item
class ast_type_specifier;
class ast_init_declarator;

class ast_declarator;
class ast_direct_declarator;            // subclass of ast_declarator
class ast_identifier_declarator;        // subclass of ast_direct_declarator
class ast_function_declarator;          // subclass of ast_direct_declarator
class ast_parameter_declaration;

class ast_statement;                    // subclass of block_item
class ast_compound_statement;
class ast_expression_statement;

class ast_external_declaration;
class ast_function_definition;          // subclass of ast_external_declaration


// Class definitions
class ast_struct {

};

class ast_program : public ast_struct {
private:
    ast_external_declaration* external_declaration;
public:
    ast_program(ast_external_declaration* external_declaration);
};

class ast_expression : public ast_struct {

};

class ast_identifier_expression : public ast_expression {
private:
    Symbol identifier;
public:
    ast_identifier_expression(Symbol identifier);
};

class ast_i_constant : public ast_expression {
private:
    Symbol i_constant;
public:
    ast_i_constant(Symbol i_constant);
};

class ast_f_constant : public ast_expression {
private:
    Symbol f_constant;
public:
    ast_f_constant(Symbol f_constant);
};

class ast_block_item : public ast_struct {

};

class ast_declaration : public ast_block_item {
private:
    ast_type_specifier* type_specifier;
    List<ast_init_declarator>* init_declarators;
public:
    ast_declaration(ast_type_specifier* type_specifier,
        List<ast_init_declarator>* init_declarators);
};

class ast_type_specifier : public ast_struct {
private:
    Symbol type_specifier;
public:
    ast_type_specifier(Symbol type_specifier);
};

class ast_init_declarator : public ast_struct {
private:
    ast_declarator* declarator;
public:
    ast_init_declarator(ast_declarator* declarator);
};

class ast_declarator : public ast_struct {

};

class ast_direct_declarator : public ast_declarator {

};

class ast_identifier_declarator : public ast_direct_declarator {
private:
    Symbol identifier;
public:
    ast_identifier_declarator(Symbol identifier);
};

class ast_function_declarator : public ast_direct_declarator {
private:
    ast_direct_declarator* direct_declarator;
    List<ast_parameter_declaration>* parameter_declarations;
public:
    ast_function_declarator(ast_direct_declarator* direct_declarator,
        List<ast_parameter_declaration>* parameter_declarations);
};

class ast_parameter_declaration : public ast_struct {
private:
    ast_type_specifier* type_specifier;
    ast_declarator* declarator;
public:
    ast_parameter_declaration(ast_type_specifier* type_specifier,
        ast_declarator* declarator);
};

class ast_statement : public ast_block_item {

};

class ast_compound_statement : public ast_statement {
private:
    List<ast_block_item>* block_items;
public:
    ast_compound_statement(List<ast_block_item>* block_items);
};

class ast_expression_statement : public ast_statement {
private:
    ast_expression* expression;
public:
    ast_expression_statement(ast_expression* expression);
};

class ast_no_expression : public ast_expression {

};

class ast_external_declaration : public ast_struct {

};

class ast_function_definition : public ast_external_declaration {
private:
    ast_type_specifier* type_specifier;
    ast_declarator* declarator;
    ast_compound_statement* compound_statement;
public:
    ast_function_definition(ast_type_specifier* type_specifier,
        ast_declarator* declarator,
        ast_compound_statement* compound_statement);
};



#endif