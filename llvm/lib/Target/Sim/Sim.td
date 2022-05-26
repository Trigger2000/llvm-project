include "llvm/Target/Target.td"

//===----------------------------------------------------------------------===//
// Sim Subtarget features
//===----------------------------------------------------------------------===//

// def FeatureDummy
//    : SubtargetFeature<"dummy", "Dummy", "true",
//                       "Dummy feature">;

include "SimRegisterInfo.td"
include "SimCallingConv.td"

include "SimInstrInfo.td"
def SimInstrInfo : InstrInfo;

// include "SimSchedule.td" - it's not necessary
// include "SimInstrFormats.td" - included in SimInstrInfo.td

//===----------------------------------------------------------------------===//
// Sim processors supported.
//===----------------------------------------------------------------------===//

// skipped
// def : ProcessorModel<"mc88110", M88kSchedModel, []>;

class Proc<string Name, list<SubtargetFeature> Features>
 : Processor<Name, NoItineraries, Features>;

def : Proc<"generic", []>;
//def : Proc<"dummy-st", []>;

// skipped:
// def SimAsmParser : AsmParser;
// def SimAsmParserVariant : AsmParserVariant {
//  let RegisterPrefix = "%";
// }
// def SimAsmWriter : AsmWriter;

// denis' version
// def SimAsmWriter : AsmWriter {
//   string AsmWriterClassName  = "InstPrinter";
//   int PassSubtarget = 1;
//   int Variant = 0;
// }
// def SimAsmParser : AsmParser {
//   bit ShouldEmitMatchRegisterName = 0;
// }

// Will generate SimGenAsmWrite.inc included by SimInstPrinter.cpp, contents
//  as follows,
// void SimInstPrinter::printInstruction(const MCInst *MI, raw_ostream &O) {...}
// const char *SimInstPrinter::getRegisterName(unsigned RegNo) {...}

def Sim : Target {
  let InstructionSet = SimInstrInfo;

  // let AssemblyParsers  = [SimAsmParser];
  // let AssemblyParserVariants  = [SimAsmParserVariant];
  // let AssemblyWriters = [SimAsmWriter];
  // let AllowRegisterRenaming = 1;
}