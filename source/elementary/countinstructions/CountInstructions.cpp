//
// Created by Saket Upadhyay on 2/20/23.
//

#include "CountInstructions.h"

using namespace llvm;

void functionVisitor(Function &function)
{
    errs() << "Function "<< function.getName() <<" contains - ";
    int instcount = 0;
    for (auto& bb : function) {
        for (auto& i : bb) {
            instcount++;
        }
    }
    errs() << instcount << " LLVM instructions.\n";

}


PreservedAnalyses CountInstr::run(Function &function, FunctionAnalysisManager &functionAnalysisManager) {

    functionVisitor(function);

    return PreservedAnalyses::all();

}


//Registering the pass
PassPluginLibraryInfo getCountInstrPluginInfo()
{
    return {
        LLVM_PLUGIN_API_VERSION,
        "CountInstrPass",
        LLVM_VERSION_STRING,
        [](PassBuilder &PB)
        {
            PB.registerPipelineParsingCallback(
                    [](StringRef Name, FunctionPassManager &FPM, ArrayRef<PassBuilder::PipelineElement>)
                    {
                        if (Name == "count-intr")
                        {
                            FPM.addPass(CountInstr());
                            return true;
                        }
                        return false;
                    }
                    );
        }
    };
}

extern "C" LLVM_ATTRIBUTE_WEAK llvm::PassPluginLibraryInfo llvmGetPassPluginInfo()
{
    return getCountInstrPluginInfo();
}