//
// Created by Saket Upadhyay on 2/19/23.
//

#ifndef LEARN_LLVM_PASSES_HELLOPASS_H
#define LEARN_LLVM_PASSES_HELLOPASS_H

#include <llvm/IR/PassManager.h>
#include <llvm/Passes/PassPlugin.h>
#include <llvm/Passes/PassBuilder.h>


namespace llvm {

    class HelloPass : public PassInfoMixin<HelloPass> {
    public:
        PreservedAnalyses run(Function &F, FunctionAnalysisManager &AM);
    };
} //namespace llvm

#endif //LEARN_LLVM_PASSES_HELLOPASS_H
