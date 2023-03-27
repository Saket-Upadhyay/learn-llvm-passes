//
// Created by Saket Upadhyay on 3/27/23.
//

#include "MBAAdd.h"

#include "llvm/ADT/Statistic.h"
#include "llvm/IR/IRBuilder.h"
#include "llvm/Passes/PassBuilder.h"
#include "llvm/Passes/PassPlugin.h"
#include "llvm/Transforms/Utils/BasicBlockUtils.h"

#include "Ratio.h"

#include <random>

using namespace llvm;
#define DEBUG_TYPE "mba-add"
STATISTIC(SubstCount, "The # of substituted Instructions");

static cl::opt<Ratio, false, llvm::cl::parser<Ratio>> MBARatio{
        "mba-ratio",
        cl::desc("Only apply the mba pass on <ratio> of the candidates"),
        cl::value_desc("ratio"), cl::init(1.), cl::Optional};

bool MBAAdd::runOnBasicBlock(BasicBlock &basicBlock) {
    bool Changed = false;
    std::mt19937_64 RNG;
    RNG.seed(1234);
    std::uniform_int_distribution<double> Dist(0., 1.);


    for (auto instruction = basicBlock.begin(), IE = basicBlock.end(); instruction != IE; ++instruction) {
        auto *BinOp = dyn_cast<BinaryOperator>(instruction);
        if (!BinOp)
            continue;

        // Skip instructions other than add
        if (BinOp->getOpcode() != Instruction::Add)
            continue;

        // Skip if the result is not 8-bit wide (this implies that the operands are
        // also 8-bit wide)
        if (!BinOp->getType()->isIntegerTy() ||
            BinOp->getType()->getIntegerBitWidth() != 8)
            continue;

        // Use Ratio and RNG to decide whether to substitute this particular 'add'
        if (Dist(RNG) > MBARatio.getRatio())
            continue;

        //BuildIR

        IRBuilder<> Builder(BinOp);

        auto Val39 = ConstantInt::get(BinOp->getType(), 39);
        auto Val151 = ConstantInt::get(BinOp->getType(), 151);
        auto Val23 = ConstantInt::get(BinOp->getType(), 23);
        auto Val2 = ConstantInt::get(BinOp->getType(), 2);
        auto Val111 = ConstantInt::get(BinOp->getType(), 111);
        // Build an instruction representing `(((a ^ b) + 2 * (a & b)) * 39 + 23) * 151 + 111`

        Instruction * newInstruction =
                BinaryOperator::CreateAdd(
                        Val111,
                        // e5 = e4 * 151
                        Builder.CreateMul(
                                Val151,
                                // e4 = e2 + 23
                                Builder.CreateAdd(
                                        Val23,
                                        // e3 = e2 * 39
                                        Builder.CreateMul(
                                                Val39,
                                                // e2 = e0 + e1
                                                Builder.CreateAdd(
                                                        // e0 = a ^ b
                                                        Builder.CreateXor(BinOp->getOperand(0),
                                                                          BinOp->getOperand(1)),
                                                        // e1 = 2 * (a & b)
                                                        Builder.CreateMul(
                                                                Val2, Builder.CreateAnd(BinOp->getOperand(0),
                                                                                        BinOp->getOperand(1))))
                                        ) // e3 = e2 * 39
                                ) // e4 = e2 + 23
                        ) // e5 = e4 * 151
                ); // E = e5 + 111

        LLVM_DEBUG(dbgs() << *BinOp << " -> " << *newInstruction << "\n");

        //Replace Inst.
        ReplaceInstWithInst(basicBlock.getInstList(),instruction,newInstruction);
        Changed= true;
        ++SubstCount;

    }

    return Changed;

}

PreservedAnalyses MBAAdd::run(Function &function, FunctionAnalysisManager &functionAnalysisManager) {
    bool isChanged = false;

    for (auto &basicBlock: function) {
    isChanged |= MBAAdd::runOnBasicBlock(basicBlock);
    }

    return (isChanged ? PreservedAnalyses::none() : PreservedAnalyses::all());
}

//PassRegistration

llvm::PassPluginLibraryInfo getMBAAddPluginInfo() {
    return {LLVM_PLUGIN_API_VERSION, "mba-add", LLVM_VERSION_STRING,
            [](PassBuilder &PB) {
                PB.registerPipelineParsingCallback(
                        [](StringRef Name, FunctionPassManager &FPM,
                           ArrayRef<PassBuilder::PipelineElement>) {
                            if (Name == "mba-add") {
                                FPM.addPass(MBAAdd());
                                return true;
                            }
                            return false;
                        });
            }};
}

extern "C" LLVM_ATTRIBUTE_WEAK ::llvm::PassPluginLibraryInfo
llvmGetPassPluginInfo() {
    return getMBAAddPluginInfo();
}