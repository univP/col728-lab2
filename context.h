#ifndef CONTEXT_H
#define CONTEXT_H

#include "symtab.h"

extern llvm::LLVMContext llvm_context;
extern llvm::IRBuilder<> builder;
extern std::unique_ptr<llvm::Module> module;
extern SymTable<Symbol, llvm::Value> named_values;

#endif