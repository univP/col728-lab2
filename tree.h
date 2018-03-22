#ifndef TREE_H
#define TREE_H

#include "symtab.h"

// Forward declarations
class ast_struct;
class ast_program;

class ast_expression;                   // Subclasses of ast_expression below
class ast_identifier_expression;  
class ast_i_constant;
class ast_f_constant;
class ast_unary_expression;
class ast_mul_expression;
class ast_div_expression;
class ast_mod_expression;
class ast_add_expression;
class ast_sub_expression;
class ast_less_expression;
class ast_leq_expression;
class ast_assign_expression;
class ast_postfix_expression;
typedef std::list<ast_expression*> ast_argument_list;
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
typedef std::list<ast_external_declaration*> ast_external_declaration_list;
class ast_function_definition;          // subclass of ast_external_declaration
class ast_parameter_type_list;

std::ostream& pad(int d, std::ostream& s);

// Class definitions

class ast_struct {

};

class ast_program : public ast_struct {
    typedef ast_external_declaration_list::iterator ListI;
private:
    ast_external_declaration_list* external_declarations;
public:
    ast_program(ast_external_declaration_list* external_declarations);
    std::ostream& print_struct(int d, std::ostream& s);
    void CodeGen();
};

class ast_expression : public ast_struct {
private:
    Symbol type;
public:
    Symbol get_type();
    void set_type(Symbol type);
    virtual llvm::Value* CodeGen() = 0;
    virtual std::ostream& print_struct(int d, std::ostream& s) = 0;
};

class ast_identifier_expression : public ast_expression {
private:
    Symbol identifier;
public:
    ast_identifier_expression(Symbol identifier);
    std::ostream& print_struct(int d, std::ostream& s);
    llvm::Value* CodeGen();
};

class ast_i_constant : public ast_expression {
private:
    Symbol i_constant;
public:
    ast_i_constant(Symbol i_constant);
    std::ostream& print_struct(int d, std::ostream& s);
    llvm::Value* CodeGen();
};

class ast_f_constant : public ast_expression {
private:
    Symbol f_constant;
public:
    ast_f_constant(Symbol f_constant);
    std::ostream& print_struct(int d, std::ostream& s);
    llvm::Value* CodeGen();
};

class ast_string_expression : public ast_expression {
private:
    Symbol string_literal;
public:
    ast_string_expression(Symbol string_literal)
        : string_literal(string_literal) {}
    std::ostream& print_struct(int d, std::ostream& s);
    llvm::Value* CodeGen();
};

class ast_postfix_expression : public ast_expression {
    typedef ast_argument_list::iterator argI;
private:
    Symbol function_name;
    ast_argument_list* arguments;
public:
    ast_postfix_expression(Symbol function_name, ast_argument_list* arguments):
        function_name(function_name), arguments(arguments) {}
    std::ostream& print_struct(int d, std::ostream& s);
    llvm::Value* CodeGen();
};

class ast_unary_expression : public ast_expression {
private:
    char unary;
    ast_expression* expression;
public:
    ast_unary_expression(char unary, 
        ast_expression* expression): unary(unary), expression(expression) {}
    std::ostream& print_struct(int d, std::ostream& s);
    llvm::Value* CodeGen();
};

class ast_mul_expression : public ast_expression {
private:
    ast_expression *e1, *e2;
public:
    ast_mul_expression(ast_expression* e1, ast_expression* e2)
        : e1(e1), e2(e2) {}
    std::ostream& print_struct(int d, std::ostream& s);
    llvm::Value* CodeGen();
};

class ast_div_expression : public ast_expression {
private:
    ast_expression *e1, *e2;
public:
    ast_div_expression(ast_expression* e1, ast_expression* e2)
        : e1(e1), e2(e2) {}
    std::ostream& print_struct(int d, std::ostream& s);
    llvm::Value* CodeGen();
};

class ast_mod_expression : public ast_expression {
private:
    ast_expression *e1, *e2;
public:
    ast_mod_expression(ast_expression* e1, ast_expression* e2)
        : e1(e1), e2(e2) {}
    std::ostream& print_struct(int d, std::ostream& s);
    llvm::Value* CodeGen();
};

class ast_add_expression : public ast_expression {
private:
    ast_expression *e1, *e2;
public:
    ast_add_expression(ast_expression* e1, ast_expression* e2)
        : e1(e1), e2(e2) {}
    std::ostream& print_struct(int d, std::ostream& s);
    llvm::Value* CodeGen();
};

class ast_sub_expression : public ast_expression {
private:
    ast_expression *e1, *e2;

public:
    ast_sub_expression(ast_expression* e1, ast_expression* e2)
        : e1(e1), e2(e2) {}
    std::ostream& print_struct(int d, std::ostream& s);
    llvm::Value* CodeGen();
};

class ast_less_expression : public ast_expression {
private:
    ast_expression *e1, *e2;
public:
    ast_less_expression(ast_expression* e1, ast_expression* e2)
        : e1(e1), e2(e2) {}
    std::ostream& print_struct(int d, std::ostream& s);
    llvm::Value* CodeGen();
};

class ast_leq_expression : public ast_expression {
private:
    ast_expression *e1, *e2;
public:
    ast_leq_expression(ast_expression* e1, ast_expression* e2)
        : e1(e1), e2(e2) {}
    std::ostream& print_struct(int d, std::ostream& s);
    llvm::Value* CodeGen();
};

class ast_eq_expression : public ast_expression {
private:
    ast_expression *e1, *e2;
public:
    ast_eq_expression(ast_expression* e1, ast_expression* e2)
        : e1(e1), e2(e2) {}
    std::ostream& print_struct(int d, std::ostream& s);
    llvm::Value* CodeGen();
};

class ast_assign_expression : public ast_expression {
private:
    Symbol identifier;
    ast_expression* expression;
    
public:
    ast_assign_expression(Symbol identifier, ast_expression* expression)
        : identifier(identifier), expression(expression) {}
    std::ostream& print_struct(int d, std::ostream& s);
    llvm::Value* CodeGen();
};

class ast_block_item : public ast_struct {
private:
    int index;
    union {
        ast_declaration* declaration;
        ast_statement* statement;
    } data;
public:
    ast_block_item(ast_declaration* declaration);
    ast_block_item(ast_statement* statement);
    int get_index();
    std::ostream& print_struct(int d, std::ostream& s, Symbol type);
    void CodeGen();
};

class ast_declaration : public ast_struct {
    typedef ast_init_declarator_list::iterator ListI;
private:
    ast_type_specifier* type_specifier;
    ast_init_declarator_list* init_declarators;
public:
    ast_declaration(ast_type_specifier* type_specifier,
        ast_init_declarator_list* init_declarators);
    std::ostream& print_struct(int d, std::ostream& s);
    void CodeGenGlobal();
    void CodeGenLocal();
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
    std::ostream& print_struct(int d, std::ostream& s, Symbol type);
    void CodeGenGlobal(llvm::Type* type);
    void CodeGenLocal(llvm::Type* type);
};

class ast_identifier_declarator : public ast_struct {
private:
    Symbol identifier;
public:
    ast_identifier_declarator(Symbol identifier);
    std::ostream& print_struct(int d, std::ostream& s, Symbol type);
    void CodeGenGlobal(llvm::Type* type);
    void CodeGenLocal(llvm::Type* type);
    Symbol get_identifier() { return identifier; }
};

class ast_function_declarator : public ast_struct {
    typedef ast_parameter_declaration_list::iterator ListI;
private:
    Symbol identifier;
    ast_parameter_type_list* parameter_types;
public:
    ast_function_declarator(Symbol identifier,
        ast_parameter_type_list* parameter_types):
        identifier(identifier), parameter_types(parameter_types) {}
    std::ostream& print_struct(int d, std::ostream& s, Symbol type);
    llvm::Function* CodeGenGlobal(llvm::Type* type);
    Symbol get_identifier() { return identifier; }
};

class ast_direct_declarator : public ast_struct {
private:
    int index;
    union {
        ast_identifier_declarator* identifier_declarator;
        ast_function_declarator* function_declarator;
    } data;
public:
    ast_direct_declarator(ast_identifier_declarator* identifier_declarator) {
        data.identifier_declarator = identifier_declarator;
        index = 0;
    }
    
    ast_direct_declarator(ast_function_declarator* function_declarator) {
        data.function_declarator = function_declarator;
        index = 1;
    }
    
    void CodeGenGlobal(llvm::Type* type);
    void CodeGenLocal(llvm::Type* type);
    
    ast_function_declarator* get_fun_decl() {
        my_assert(index == 1, __LINE__, __FILE__);
        return data.function_declarator;
    }

    std::ostream& print_struct(int d, std::ostream& s, Symbol type);
};

class ast_declarator : public ast_struct {
private:
    ast_direct_declarator* direct_declarator;
public:
    ast_declarator(ast_direct_declarator* direct_declarator)
        : direct_declarator(direct_declarator) {}
    void CodeGenGlobal(llvm::Type* type);
    void CodeGenLocal(llvm::Type* type);

    ast_function_declarator* get_fun_decl() {
        return direct_declarator->get_fun_decl();
    }
    
    std::ostream& print_struct(int d, std::ostream& s, Symbol type);
};

class ast_parameter_declaration : public ast_struct {
private:
    ast_type_specifier* type_specifier;
    Symbol identifier;
    bool pointer;
public:
    ast_parameter_declaration(ast_type_specifier* type_specifier,
        Symbol identifier, bool pointer): type_specifier(type_specifier), 
        identifier(identifier), pointer(pointer) {}
    std::ostream& print_struct(int d, std::ostream& s);
    
    Symbol get_type(){
        return type_specifier->get_type_specifier();
    }
    
    Symbol get_identifier(){
        return identifier;
    }

    bool is_pointer() { return pointer; }
};

class ast_statement : public ast_struct {
public:
    virtual void CodeGen() = 0;
    virtual std::ostream& print_struct(int d, std::ostream& s, Symbol type) = 0;
};

class ast_mif_statement : public ast_statement{
private:
    ast_expression* condition;
    ast_statement* then_statement;
    ast_statement* else_statement;
public:
    ast_mif_statement(ast_expression* condition, ast_statement* then_statement,
        ast_statement* else_statement) : condition(condition), 
            then_statement(then_statement), else_statement(else_statement) {}
    void CodeGen();
    std::ostream& print_struct(int d, std::ostream& s, Symbol type);
};

class ast_uif_statement : public ast_statement{
private:
    ast_expression* condition;
    ast_statement* then_statement;
public:
    ast_uif_statement(ast_expression* condition, ast_statement* then_statement)
         : condition(condition), 
            then_statement(then_statement) {}
    void CodeGen();
    std::ostream& print_struct(int d, std::ostream& s, Symbol type);    
};

class ast_compound_statement : public ast_statement {
    typedef ast_block_item_list::iterator ListI;
private:
    ast_block_item_list* block_items;
public:
    ast_compound_statement(ast_block_item_list* block_items);
    std::ostream& print_struct(int d, std::ostream& s, Symbol type);
    void CodeGen();
};

class ast_expression_statement : public ast_statement {
private:
    ast_expression* expression;
public:
    ast_expression_statement(ast_expression* expression);
    std::ostream& print_struct(int d, std::ostream& s, Symbol type);
    void CodeGen();
    ast_expression* get_expression() { return expression; }
};

class ast_no_expression : public ast_expression {
public:
    ast_no_expression();
    std::ostream& print_struct(int d, std::ostream& s);
    llvm::Value* CodeGen();
};

class ast_external_declaration : public ast_struct {
private:
    int index;
    union {
        ast_declaration* declaration;
        ast_function_definition* function_definition;
    } data;
public:
    ast_external_declaration(ast_declaration* declaration);
    ast_external_declaration(ast_function_definition* function_definition);
    int get_index();
    void CodeGen();
    std::ostream& print_struct(int d, std::ostream& s);
};

class ast_function_definition : public ast_struct {
private:
    ast_type_specifier* type_specifier;
    ast_declarator* declarator;
    ast_compound_statement* compound_statement;
public:
    ast_function_definition(ast_type_specifier* type_specifier,
        ast_declarator* declarator,
        ast_compound_statement* compound_statement);
    std::ostream& print_struct(int d, std::ostream& s);
    llvm::Function* CodeGen();
};

class ast_jump_statement : public ast_statement {
private:
    ast_expression* expression;
public:
    ast_jump_statement(): expression(new ast_no_expression()) {}
    ast_jump_statement(ast_expression* expression): expression(expression) {}
    std::ostream& print_struct(int d, std::ostream& s, Symbol type);
    void CodeGen();
};

class ast_for_statement : public ast_statement {
private:
    int index;
    union {
        ast_expression_statement* expression_statement;
        ast_declaration* declaration;
    } data;
    ast_expression_statement* condition;
    ast_expression* update;
    ast_statement* body;
public:
    ast_for_statement(ast_expression_statement* expression_statement,
        ast_expression_statement* condition, ast_statement* body)
        : condition(condition), update(new ast_no_expression()),
            body(body) {
            index = 0;
            data.expression_statement = expression_statement;
    }

    ast_for_statement(ast_expression_statement* expression_statement,
        ast_expression_statement* condition, ast_expression* update,
            ast_statement* body)
        : condition(condition), update(update), body(body) {
            index = 0;
            data.expression_statement = expression_statement;
    }

    ast_for_statement(ast_declaration* declaration,
        ast_expression_statement* condition, ast_statement* body)
        : condition(condition), update(new ast_no_expression()),
            body(body) {
            index = 1;
            data.declaration = declaration;
    }

    ast_for_statement(ast_declaration* declaration,
        ast_expression_statement* condition, ast_expression* update,
            ast_statement* body)
        : condition(condition), update(update), body(body) {
            index = 1;
            data.declaration = declaration;
    }

    std::ostream& print_struct(int d, std::ostream& s, Symbol type);
    void CodeGen();
};

class ast_parameter_type_list: public ast_struct {
    typedef ast_parameter_declaration_list::iterator ListI;
private:
    ast_parameter_declaration_list* parameter_declarations;
    bool variadic;
public:
    ast_parameter_type_list(ast_parameter_declaration_list* 
        parameter_declarations, bool variadic)
        : parameter_declarations(parameter_declarations), variadic(variadic) {}
    
    ast_parameter_declaration_list* get_parameter_declarations() {
        return parameter_declarations;
    }

    bool is_variadic() {
        return variadic;
    }

    std::ostream& print_struct(int d, std::ostream& s);
};

#endif