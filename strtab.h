#ifndef STRTAB_H
#define STRTAB_H

#include <string>
#include <list>
#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <cstdlib>
#include <sstream>
#include <fstream>
#include <algorithm>
#include <utility>
#include <memory>
#include "llvm/ADT/APFloat.h"
#include "llvm/ADT/Optional.h"
#include "llvm/ADT/STLExtras.h"
#include "llvm/IR/BasicBlock.h"
#include "llvm/IR/Constants.h"
#include "llvm/IR/DerivedTypes.h"
#include "llvm/IR/Function.h"
#include "llvm/IR/Instructions.h"
#include "llvm/IR/IRBuilder.h"
#include "llvm/IR/LLVMContext.h"
#include "llvm/IR/LegacyPassManager.h"
#include "llvm/IR/Module.h"
#include "llvm/IR/Type.h"
#include "llvm/IR/Verifier.h"
#include "llvm/Support/FileSystem.h"
#include "llvm/Support/Host.h"
#include "llvm/Support/raw_ostream.h"
#include "llvm/Support/TargetRegistry.h"
#include "llvm/Support/TargetSelect.h"
#include "llvm/Target/TargetMachine.h"
#include "llvm/Target/TargetOptions.h"
#include "llvm/Transforms/Scalar.h"
#include "llvm/Transforms/Scalar/GVN.h"

#define my_assert(e,l,f) if (!(e)) { std::cerr << "Line: "<< l << ", File: " << f << std::endl; exit(1); }

// Contains all the basic header files necessary for 
//  Code Generation.
// Also contains string table storing all Symbols.

typedef std::string* Symbol;

class StrTable : public std::map<std::string, Symbol> {
    typedef iterator MapI;
public:
    Symbol add_string(std::string str) {
        MapI it = find(str);

        if (it != end()) {
            return it->second;
        }

        Symbol symbol = new std::string(str);
        insert(std::make_pair(str, symbol));
        return symbol;
    }
};

extern StrTable id_table;
extern StrTable str_table;
extern StrTable int_table;
extern StrTable float_table;

#endif