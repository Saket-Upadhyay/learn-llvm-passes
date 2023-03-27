//
// Created by Saket Upadhyay on 2/20/23.
//

#ifndef LEARN_LLVM_PASSES_COUNTINSTRUCTIONS_H
#define LEARN_LLVM_PASSES_COUNTINSTRUCTIONS_H

#include <llvm/IR/PassManager.h>
#include <llvm/Passes/PassPlugin.h>
#include <llvm/Passes/PassBuilder.h>
#include <llvm/IR/Instructions.h>
#include <llvm/IR/InstrTypes.h>

namespace llvm{
    class CountInstr : public PassInfoMixin<CountInstr>
    {
    public:
        PreservedAnalyses run(Function &function, FunctionAnalysisManager &functionAnalysisManager);
    }; //namespace llvm
}
#endif //LEARN_LLVM_PASSES_COUNTINSTRUCTIONS_H
