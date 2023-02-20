//
// Created by drdope on 2/19/23.
//
#include "FunctionVisitor.h"

using namespace llvm;

void functionVisitor(Function &Function)
{
    errs() << "Visiting Function: " << Function.getName() << " (Takes "<<Function.arg_size()<<" arguments)"<<"\n";
}

PreservedAnalyses FunctionVisitor::run(Function &F, FunctionAnalysisManager &AM) {
    functionVisitor(F);
    return PreservedAnalyses::all();
}



//Registering the Pass
PassPluginLibraryInfo getFunctionVisitorPluginInfo()
{
    return {LLVM_PLUGIN_API_VERSION, "HelloPass", LLVM_VERSION_STRING, [](PassBuilder &PB){
        PB.registerPipelineParsingCallback(
                [](StringRef Name, FunctionPassManager &FPM,
                   ArrayRef<PassBuilder::PipelineElement>){
                    if (Name == "func-visit")
                    {
                        FPM.addPass(FunctionVisitor());
                        return true;
                    }
                    return false;
                });
    }};
    //end return
}

extern "C" LLVM_ATTRIBUTE_WEAK llvm::PassPluginLibraryInfo llvmGetPassPluginInfo(){
    return getFunctionVisitorPluginInfo();
}
