#ifndef TREE_H
#define TREE_H

#include "list.h"
#include "table.h"

class ast_struct;
class ast_program;
class ast_external_declaration;
class ast_function_definition;
class ast_type_specifier;
class ast_identifier;
class ast_jump_statement;
class ast_i_constant;

class ast_struct {

};

class ast_program : public ast_struct {
private:
    List<ast_external_declaration>* external_declarations;
public:
    ast_program(List<ast_external_declaration>* external_declarations);
};

class ast_external_declaration : public ast_struct {

};

class ast_function_definition : public ast_external_declaration {
    
};

class ast_type_specifier {
private:
    Symbol type_specifier;
public:
    ast_type_specifier(Symbol type_specifier);
};

class ast_identifier : public ast_struct {
private:
    Symbol identifier;
public:
    ast_identifier(Symbol identifier);
};

class ast_jump_statement : public ast_struct {
private:
    ast_i_constant* i_constant;
public:
    ast_jump_statement(ast_i_constant* i_constant);
};

class ast_i_constant : public ast_struct {
private:
    Symbol i_constant;
public:
    ast_i_constant(Symbol i_constant);
};

#endif