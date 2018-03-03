#ifndef TREE_H
#define TREE_H

#include "list.h"

class ast_struct;
class ast_program;
class ast_external_declaration;
class ast_function_definition;
class ast_type_specifier;

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

};

#endif