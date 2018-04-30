#include "llvm/Pass.h"
#include "llvm/IR/BasicBlock.h"
#include "llvm/Support/raw_ostream.h"
#include "llvm/IR/Instruction.h"
#include "llvm/IR/Instructions.h"
#include "llvm/IR/Constants.h"
#include "llvm/Transforms/Utils/BasicBlockUtils.h"
#include "llvm/Analysis/CFG.h"
#include "llvm/IR/InstrTypes.h"

#include <map>
#include <set>
#include <list>
#include <algorithm>
#include <vector>

using namespace llvm;

// TODO:
// 1. implement the dataflow analysis algorithm
//  a. data: set of exprs
//  b. direction: forward
//  c. meet: intersection
//  d. transfer: add expr to set
//  e. boundary: out[entry] = {}
//  f. internal: all expressions

namespace {

    class CsePass : public FunctionPass {
    
    public:
        static char ID;

        // Input and Output of each basic block mapped to a set of instructions 
        // only binary operators are considered
        typedef std::set<Instruction*> InstSet;
        typedef std::map<BasicBlock*, InstSet*> InstSetMap;
        InstSetMap inSetMap, outSetMap;
        std::list<BasicBlock*> workQueue;

        CsePass() : FunctionPass(ID) {}

        bool isValid(Instruction* inst) {
            unsigned opcode = inst->getOpcode();
            return opcode == Instruction::Add || opcode == Instruction::Sub
                || opcode == Instruction::Mul || opcode == Instruction::SDiv
                || opcode == Instruction::SRem || opcode == Instruction::Xor
                || opcode == Instruction::ICmp;
        }

        // Step1: Compute the available instructions at each basic block
        void availInstSet(Function& func) {
            // Initialize the data structures
            inSetMap.clear();
            outSetMap.clear();
            workQueue.clear();

            InstSet allInst;

            for (Function::iterator fb = func.begin(), fe = func.end(); fb != fe; fb++) {
                BasicBlock& basicBlock = *fb;

                for (BasicBlock::iterator ib = basicBlock.begin(), ie = basicBlock.end(); ib != ie; ib++) {
                    Instruction* inst = &*ib;

                    if (isValid(inst)) {
                        allInst.insert(inst);
                    }
                }
            }

            for (Function::iterator fb = func.begin(), fe = func.end(); fb != fe; fb++) {
                // Initialize with all instructions
                inSetMap[&*fb] = new InstSet(allInst);
                outSetMap[&*fb] = new InstSet(allInst);

                // Add all basic blocks to work queue
                workQueue.push_back(&*fb);
            }

            // No instruction on entry
            inSetMap[&func.getEntryBlock()]->clear();

            // Breadth first traversal
            while (!workQueue.empty()) {
                BasicBlock* frontBlock = workQueue.front();
                workQueue.pop_front();

                // compute input from predecessors
                for (pred_iterator pb = pred_begin(frontBlock), pe = pred_end(frontBlock); pb != pe; pb++) {
                    if (pb == pred_begin(frontBlock)) {
                        inSetMap[frontBlock] = new InstSet(*outSetMap[*pb]);
                    } else {
                        // Intersection of sets
                        InstSet intersect;
                        set_intersection(inSetMap[frontBlock]->begin(), inSetMap[frontBlock]->end(), 
                            outSetMap[*pb]->begin(), outSetMap[*pb]->end(), std::inserter(intersect, intersect.begin()));
                        inSetMap[frontBlock] = new InstSet(intersect);
                    }
                }

                // Compute output from input through a series of transfer functions
                InstSet newSet(*inSetMap[frontBlock]);

                for (BasicBlock::iterator ib = frontBlock->begin(), ie = frontBlock->end(); ib != ie; ib++) {
                    // Only add binary operators
                    Instruction* inst = &*ib;
                    
                    if (isValid(inst)) {
                        newSet.insert(inst);
                    }
                }

                // Add all the successors to list if output set changed
                if (newSet != *outSetMap[frontBlock]) {
                    for (succ_iterator sb = succ_begin(frontBlock), se = succ_end(frontBlock); sb != se; sb++) {
                        workQueue.push_back(*sb);
                    }

                    outSetMap[frontBlock] = new InstSet(newSet);
                }
            }
        }

        // Replace current instruction if it matches already available instruction
        bool findReplace(Function& func) {
            bool changed = false;

            // To compute available expressions, first extract in set of each basic block
            for (Function::iterator fb = func.begin(), fe = func.end(); fb != fe; fb++) {
                InstSet newSet(*inSetMap[&*fb]);

                // Store iterator and value in a vector and replace them later
                // Cannot modify while iterating the loop
                std::vector<BasicBlock::iterator> iterList;
                std::vector<Value*> valueList;

                // newSet represents the input set at program point
                for (BasicBlock::iterator ib = (*fb).begin(), ie = (*fb).end(); ib != ie; ib++) {
                    // Only process binary operators
                    Instruction* inst = &*ib;
                    
                    if (isValid(inst)) {
                        // Look up current expression
                        for (Instruction* bop : newSet) {
                            if (inst->getOpcode() == bop->getOpcode() 
                                && inst->getOperand(0) == bop->getOperand(0) 
                                && inst->getOperand(1) == bop->getOperand(1)) {
                                    // Add required info to vectors
                                    iterList.push_back(ib);
                                    valueList.push_back(bop);
                                    changed = true;
                                    break;
                            }
                        }

                        // Add current instruction to available expressions
                        newSet.insert(inst);
                    }
                }

                // Replace instructions
                for (unsigned index = 0; index < iterList.size(); index++) {
                    BasicBlock::iterator ib = iterList[index];
                    Instruction* inst = &*ib;
                    Value* bop = valueList[index];
                    ReplaceInstWithValue(inst->getParent()->getInstList(), ib, bop);
                }
            }

            return changed;
        }

        bool runOnFunction(Function &function) override {
            availInstSet(function);
            return findReplace(function);
        }
    };
}

char CsePass::ID = 0;
static RegisterPass<CsePass> X("cse", "Common Subexpression Elimination Pass");