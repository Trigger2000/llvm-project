#ifndef LLVM_LIB_TARGET_SIM_SIMTARGETMACHINE_H
#define LLVM_LIB_TARGET_SIM_SIMTARGETMACHINE_H

#include "SimInstrInfo.h"
#include "SimSubtarget.h"
#include "llvm/Target/TargetMachine.h"

namespace llvm {

class SimTargetMachine : public LLVMTargetMachine {
public:
  SimTargetMachine(const Target &T, const Triple &TT, StringRef CPU,
                   StringRef FS, const TargetOptions &Options,
                   Optional<Reloc::Model> RM, Optional<CodeModel::Model> CM,
                   CodeGenOpt::Level OL, bool JIT);
  ~SimTargetMachine() override = default;

    // SimSubtarget holds configuration for the code generation, such as which features are enabled.
  const SimSubtarget *getSubtargetImpl() const {
    return &Subtarget;
  }
  const SimSubtarget *getSubtargetImpl(const Function &) const override {
    return &Subtarget; 
  }

  // Pass Pipeline Configuration
  TargetPassConfig *createPassConfig(PassManagerBase &PM) override;
  TargetLoweringObjectFile *getObjFileLowering() const override {
    return TLOF.get();
  }
private:
  std::unique_ptr<TargetLoweringObjectFile> TLOF;
  SimSubtarget Subtarget;
};
}   // llvm

#endif  // LLVM_LIB_TARGET_SIM_SIMTARGETMACHINE_H