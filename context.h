#ifndef CONTEXT_H
#define CONTEXT_H

#include "tree.h"

extern llvm::LLVMContext llvm_context;
extern llvm::IRBuilder<> builder;
extern std::unique_ptr<llvm::Module> module;
extern SymTable<Symbol, llvm::Value> named_values;
extern std::map<Symbol, ast_function_declarator*> fun_decls;
extern SymTable<Symbol, std::string> named_types;

#endif