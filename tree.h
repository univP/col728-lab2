#ifndef TREE_H
#define TREE_H

#include "context.h"

// Forward declarations
class ast_struct;
class ast_program;

class ast_expression;                   // Subclasses of ast_expression below
class ast_identifier_expression;  
class ast_i_constant;
class ast_f_constant;
class ast_no_expression;

class ast_block_item;
typedef std::list<ast_block_item*> ast_block_item_list;
class ast_declaration;                  // subclass of block_item
class ast_type_specifier;
class ast_init_declarator;
typedef std::list<ast_init_declarator*> ast_init_declarator_list;

class ast_declarator;
class ast_direct_declarator;            // subclass of ast_declarator
class ast_identifier_declarator;        // subclass of ast_direct_declarator
class ast_function_declarator;          // subclass of ast_direct_declarator
class ast_parameter_declaration;
typedef std::list<ast_parameter_declaration*> ast_parameter_declaration_list;

class ast_statement;                    // subclass of block_item
class ast_compound_statement;
class ast_expression_statement;

class ast_external_declaration;
class ast_function_definition;          // subclass of ast_external_declaration

std::ostream& pad(int d, std::ostream& s);

// Class definitions

class Arg {
private:
    Symbol type_specifier;
    Symbol arg_name;
public:
    Arg(Symbol type_specifier, Symbol arg_name);
    Symbol get_type_specifier();
    Symbol get_arg_name();
};

typedef std::list<Arg> Args;

class ast_struct {
public:
    virtual std::ostream& print_struct(int d, std::ostream& s) = 0;
};

class ast_program : public ast_struct {
private:
    ast_external_declaration* external_declaration;
public:
    ast_program(ast_external_declaration* external_declaration);
    std::ostream& print_struct(int d, std::ostream& s);
    void CodeGen();
};

class ast_expression : public ast_struct {
private:
    Symbol type;
public:
    Symbol get_type();
    void set_type(Symbol type);
    virtual llvm::Value* CodeGen(CodeGenContext* context) = 0;
};

class ast_identifier_expression : public ast_expression {
private:
    Symbol identifier;
public:
    ast_identifier_expression(Symbol identifier);
    std::ostream& print_struct(int d, std::ostream& s);
    llvm::Value* CodeGen(CodeGenContext* context);
};

class ast_i_constant : public ast_expression {
private:
    Symbol i_constant;
public:
    ast_i_constant(Symbol i_constant);
    std::ostream& print_struct(int d, std::ostream& s);
    llvm::Value* CodeGen(CodeGenContext* context);
};

class ast_f_constant : public ast_expression {
private:
    Symbol f_constant;
public:
    ast_f_constant(Symbol f_constant);
    std::ostream& print_struct(int d, std::ostream& s);
    llvm::Value* CodeGen(CodeGenContext* context);
};

class ast_block_item : public ast_struct {
public:
    virtual llvm::Value* CodeGen(CodeGenContext* context) = 0;
};

class ast_declaration : public ast_block_item {
    typedef ast_init_declarator_list::iterator ListI;
private:
    ast_type_specifier* type_specifier;
    ast_init_declarator_list* init_declarators;
public:
    ast_declaration(ast_type_specifier* type_specifier,
        ast_init_declarator_list* init_declarators);
    std::ostream& print_struct(int d, std::ostream& s);
    llvm::Value* CodeGen(CodeGenContext* context);
};

class ast_type_specifier : public ast_struct {
private:
    Symbol type_specifier;
public:
    ast_type_specifier(Symbol type_specifier);
    std::ostream& print_struct(int d, std::ostream& s);
    Symbol get_type_specifier();
};

class ast_init_declarator : public ast_struct {
private:
    ast_declarator* declarator;
public:
    ast_init_declarator(ast_declarator* declarator);
    std::ostream& print_struct(int d, std::ostream& s);
};

class ast_declarator : public ast_struct {
public:
    virtual Symbol get_identifier() = 0;
    virtual llvm::Function* get_function(llvm::Type* return_type, 
        CodeGenContext* context) = 0;
};

class ast_direct_declarator : public ast_declarator {

};

class ast_identifier_declarator : public ast_direct_declarator {
private:
    Symbol identifier;
public:
    ast_identifier_declarator(Symbol identifier);
    std::ostream& print_struct(int d, std::ostream& s);
    Symbol get_identifier();
    llvm::Function* get_function(llvm::Type* return_type, 
        CodeGenContext* context);
};

class ast_function_declarator : public ast_direct_declarator {
    typedef ast_parameter_declaration_list::iterator ListI;
private:
    ast_direct_declarator* direct_declarator;
    ast_parameter_declaration_list* parameter_declarations;
public:
    ast_function_declarator(ast_direct_declarator* direct_declarator,
        ast_parameter_declaration_list* parameter_declarations);
    std::ostream& print_struct(int d, std::ostream& s);
    Symbol get_identifier();
    llvm::Function* get_function(llvm::Type* return_type, 
        CodeGenContext* context);
};

class ast_parameter_declaration : public ast_struct {
private:
    ast_type_specifier* type_specifier;
    ast_declarator* declarator;
public:
    ast_parameter_declaration(ast_type_specifier* type_specifier,
        ast_declarator* declarator);
    std::ostream& print_struct(int d, std::ostream& s);
    Arg* get_arg();
};

class ast_statement : public ast_block_item {

};

class ast_compound_statement : public ast_statement {
    typedef ast_block_item_list::iterator ListI;
private:
    ast_block_item_list* block_items;
public:
    ast_compound_statement(ast_block_item_list* block_items);
    std::ostream& print_struct(int d, std::ostream& s);
    llvm::Value* CodeGen(CodeGenContext* context);
};

class ast_expression_statement : public ast_statement {
private:
    ast_expression* expression;
public:
    ast_expression_statement(ast_expression* expression);
    std::ostream& print_struct(int d, std::ostream& s);
    llvm::Value* CodeGen(CodeGenContext* context);
};

class ast_no_expression : public ast_expression {
public:
    ast_no_expression();
    std::ostream& print_struct(int d, std::ostream& s);
    llvm::Value* CodeGen(CodeGenContext* context);
};

class ast_external_declaration : public ast_struct {
public:
    virtual llvm::Function* CodeGen(CodeGenContext* context) = 0; 
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
    std::ostream& print_struct(int d, std::ostream& s);
    llvm::Function* CodeGen(CodeGenContext* context);
};



#endif