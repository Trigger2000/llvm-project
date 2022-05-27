#ifndef LLVM_LIB_TARGET_Sim_Sim_H
#define LLVM_LIB_TARGET_Sim_Sim_H

#include "MCTargetDesc/SimMCTargetDesc.h"
#include "llvm/Target/TargetMachine.h"

namespace llvm {
class SimTargetMachine;
class FunctionPass;
class SimSubtarget;
class AsmPrinter;
class InstructionSelector;
class MCInst;
class MCOperand;
class MachineInstr;
class MachineOperand;
class PassRegistry;

bool lowerSimMachineInstrToMCInst(const MachineInstr *MI, MCInst &OutMI,
                                    AsmPrinter &AP);
bool LowerSimMachineOperandToMCOperand(const MachineOperand &MO,
                                         MCOperand &MCOp, const AsmPrinter &AP);

FunctionPass *createSimISelDag(SimTargetMachine &TM,
                                CodeGenOpt::Level OptLevel);


namespace Sim {
enum {
  GP = Sim::R0,
  RA = Sim::R1,
  SP = Sim::R2,
  FP = Sim::R3,
  BP = Sim::R4,
};
} // namespace Sim

} // namespace llvm

#endif