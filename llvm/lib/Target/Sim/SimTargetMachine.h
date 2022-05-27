#ifndef LLVM_LIB_TARGET_Sim_SimTARGETMACHINE_H
#define LLVM_LIB_TARGET_Sim_SimTARGETMACHINE_H

#include "SimInstrInfo.h"
#include "SimSubtarget.h"
#include "llvm/Target/TargetMachine.h"

namespace llvm {

class SimTargetMachine : public LLVMTargetMachine {
  std::unique_ptr<TargetLoweringObjectFile> TLOF;
  SimSubtarget Subtarget;
  // mutable StringMap<std::unique_ptr<SimSubtarget>> SubtargetMap;

public:
  SimTargetMachine(const Target &T, const Triple &TT, StringRef CPU,
                    StringRef FS, const TargetOptions &Options,
                    Optional<Reloc::Model> RM, Optional<CodeModel::Model> CM,
                    CodeGenOpt::Level OL, bool JIT);
  ~SimTargetMachine() override;

  const SimSubtarget *getSubtargetImpl() const { return &Subtarget; }
  const SimSubtarget *getSubtargetImpl(const Function &) const override {
    return &Subtarget;
  }

  // Pass Pipeline Configuration
  TargetPassConfig *createPassConfig(PassManagerBase &PM) override;
  TargetLoweringObjectFile *getObjFileLowering() const override {
    return TLOF.get();
  }

#if 0
  bool
  addPassesToEmitFile(PassManagerBase &, raw_pwrite_stream &,
                      raw_pwrite_stream *, CodeGenFileType,
                      bool /*DisableVerify*/ = true,
                      MachineModuleInfoWrapperPass *MMIWP = nullptr) override {
    return false;
  }
#endif
  // TargetTransformInfo getTargetTransformInfo(const Function &F) override;
};
} // end namespace llvm

#endif