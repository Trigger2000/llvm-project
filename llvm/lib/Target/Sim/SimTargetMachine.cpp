//===----------------------------------------------------------------------===//
//
// Implements the info about Sim target spec.
//
//===----------------------------------------------------------------------===//

#include "SimTargetMachine.h"
#include "Sim.h"
//#include "SimTargetTransformInfo.h"
#include "TargetInfo/SimTargetInfo.h"
#include "llvm/CodeGen/Passes.h"
#include "llvm/CodeGen/TargetLoweringObjectFileImpl.h"
#include "llvm/CodeGen/TargetPassConfig.h"
#include "llvm/IR/Attributes.h"
#include "llvm/IR/Function.h"
#include "llvm/IR/LegacyPassManager.h"
#include "llvm/Support/TargetRegistry.h"
#include "llvm/Support/CodeGen.h"
#include "llvm/Support/ErrorHandling.h"
#include "llvm/Target/TargetOptions.h"

#define DEBUG_TYPE "Sim"

using namespace llvm;

static Reloc::Model getRelocModel(Optional<Reloc::Model> RM) {
  return RM.getValueOr(Reloc::Static);
}

/// SimTargetMachine ctor - Create an ILP32 Architecture model
SimTargetMachine::SimTargetMachine(const Target &T, const Triple &TT,
                                     StringRef CPU, StringRef FS,
                                     const TargetOptions &Options,
                                     Optional<Reloc::Model> RM,
                                     Optional<CodeModel::Model> CM,
                                     CodeGenOpt::Level OL, bool JIT)
    : LLVMTargetMachine(T,
                        "e-m:e-p:32:32-i1:8:32-i8:8:32-i16:16:32-i32:32:32-"
                        "f32:32:32-i64:32-f64:32-a:0:32-n32",
                        TT, CPU, FS, Options, getRelocModel(RM),
                        getEffectiveCodeModel(CM, CodeModel::Small), OL),
      TLOF(std::make_unique<TargetLoweringObjectFileELF>()),
      Subtarget(TT, std::string(CPU), std::string(FS), *this) {
  initAsmInfo();
}

SimTargetMachine::~SimTargetMachine() = default;

namespace {

/// Sim Code Generator Pass Configuration Options.
class SimPassConfig : public TargetPassConfig {
public:
  SimPassConfig(SimTargetMachine &TM, PassManagerBase &PM)
      : TargetPassConfig(TM, PM) {}

  SimTargetMachine &getSimTargetMachine() const {
    return getTM<SimTargetMachine>();
  }

  bool addInstSelector() override;
  // void addPreEmitPass() override;
  // void addPreRegAlloc() override;
};

} // end anonymous namespace

TargetPassConfig *SimTargetMachine::createPassConfig(PassManagerBase &PM) {
  return new SimPassConfig(*this, PM);
}

bool SimPassConfig::addInstSelector() {
  addPass(createSimISelDag(getSimTargetMachine(), getOptLevel()));
  return false;
}

// void SimPassConfig::addPreEmitPass() { llvm_unreachable(""); }

// void SimPassConfig::addPreRegAlloc() { llvm_unreachable(""); }

// Force static initialization.
extern "C" LLVM_EXTERNAL_VISIBILITY void LLVMInitializeSimTarget() {
  RegisterTargetMachine<SimTargetMachine> X(getTheSimTarget());
}

#if 0
TargetTransformInfo
SimTargetMachine::getTargetTransformInfo(const Function &F) {
  return TargetTransformInfo(SimTTIImpl(this, F));
}
#endif