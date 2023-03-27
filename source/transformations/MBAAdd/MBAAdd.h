//
// Created by Saket Upadhyay on 3/27/23.
//

#ifndef LEARN_LLVM_PASSES_MBAADD_H
#define LEARN_LLVM_PASSES_MBAADD_H

#include "llvm/IR/PassManager.h"
#include "llvm/Pass.h"

namespace llvm{
struct MBAAdd : public PassInfoMixin<MBAAdd> {
public:
    PreservedAnalyses run(Function &F, FunctionAnalysisManager &AM);
    bool runOnBasicBlock(BasicBlock &BB);
    };
}



#endif //LEARN_LLVM_PASSES_MBAADD_H
