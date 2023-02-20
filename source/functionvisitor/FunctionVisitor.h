//
// Created by drdope on 2/19/23.
//

#ifndef LEARN_LLVM_PASSES_FUNCTIONVISITOR_H
#define LEARN_LLVM_PASSES_FUNCTIONVISITOR_H

#include <llvm/IR/PassManager.h>
#include <llvm/Passes/PassPlugin.h>
#include <llvm/Passes/PassBuilder.h>


namespace llvm {

    class FunctionVisitor : public PassInfoMixin<FunctionVisitor> {
    public:
        PreservedAnalyses run(Function &F, FunctionAnalysisManager &AM);
    };
} //namespace llvm

#endif //LEARN_LLVM_PASSES_FUNCTIONVISITOR_H
