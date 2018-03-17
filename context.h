#ifndef CONTEXT_H
#define CONTEXT_H

#include "symtab.h"

class CodeGenContext {
public:
    llvm::LLVMContext llvm_context;
    // llvm::IRBuilder<> builder(llvm_context);
    std::unique_ptr<llvm::Module> module;
    SymTable<Symbol, llvm::Value> named_values;
};

#endif