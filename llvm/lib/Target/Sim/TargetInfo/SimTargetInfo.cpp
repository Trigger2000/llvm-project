#include "Sim.h"
#include "llvm/IR/Module.h"
#include "TargetInfo/SimTargetInfo.h"
#include "llvm/MC/TargetRegistry.h"

using namespace llvm;

Target &llvm::getTheSimTarget() {
  static Target TheSimTarget;
  return TheSimTarget;
}

extern "C" LLVM_EXTERNAL_VISIBILITY void LLVMInitializeSimTargetInfo() {
  RegisterTarget<Triple::sim, false> X(getTheSimTarget(), "Sim", "Sim (32-bit simulator arch)", "Sim");
}