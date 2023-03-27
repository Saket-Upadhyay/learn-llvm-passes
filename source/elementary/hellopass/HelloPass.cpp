//
// Created by Saket Upadhyay on 2/15/23.
//
#include "HelloPass.h"



using namespace llvm;

void functionVisitor(Function &Function)
{
    errs() << Function.getName() <<"\n";
}

PreservedAnalyses HelloPass::run(Function &F, FunctionAnalysisManager &AM) {
    functionVisitor(F);
    return PreservedAnalyses::all();
}



//Registering the Pass
PassPluginLibraryInfo getHelloPassPluginInfo()
{
    return {LLVM_PLUGIN_API_VERSION, "HelloPass", LLVM_VERSION_STRING, [](PassBuilder &PB){
        PB.registerPipelineParsingCallback(
                [](StringRef Name, FunctionPassManager &FPM,
                        ArrayRef<PassBuilder::PipelineElement>){
                    if (Name == "hello-pass")
                    {
                        FPM.addPass(HelloPass());
                        return true;
                    }
                    return false;
                });
    }};
    //end return
}

extern "C" LLVM_ATTRIBUTE_WEAK llvm::PassPluginLibraryInfo llvmGetPassPluginInfo(){
    return getHelloPassPluginInfo();
}