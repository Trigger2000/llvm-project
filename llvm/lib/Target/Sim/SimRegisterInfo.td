// For tablegen(... -gen-emitter)  in CMakeLists.txt
class SimReg<bits<16> Enc, string n> : Register<n> {
  let HWEncoding = Enc;
  // let Namespace = "Sim"; - skipped
}

// skipped
// class SimGPRReg<bits<16> Enc, string n> : SimReg<Enc, n> {
//   let Namespace = "Sim";
// }

//===----------------------------------------------------------------------===//
//@Registers
//===----------------------------------------------------------------------===//
//@ All registers definition
let Namespace = "Sim" in {
  //@ General Purpose Registers
  def R0    : SimReg<0,  "r0">,    DwarfRegNum<[0]>;  // gp?
  def R1    : SimReg<1,  "r1">,    DwarfRegNum<[1]>;  // ra
  def R2    : SimReg<2,  "r2">,    DwarfRegNum<[2]>;  // sp
  def R3    : SimReg<3,  "r3">,    DwarfRegNum<[3]>;  // fp
  def R4    : SimReg<4,  "r4">,    DwarfRegNum<[4]>;  // bp
  def R5    : SimReg<5,  "r5">,    DwarfRegNum<[5]>;  // s0
  def R6    : SimReg<6,  "r6">,    DwarfRegNum<[6]>;  // s1
  def R7    : SimReg<7,  "r7">,    DwarfRegNum<[7]>;  // s2
  def R8    : SimReg<8,  "r8">,    DwarfRegNum<[8]>;  // s3
  def R9    : SimReg<9,  "r9">,    DwarfRegNum<[9]>;  // a0
  def R10   : SimReg<10, "r10">,   DwarfRegNum<[10]>; // a1
  def R11   : SimReg<11, "r11">,   DwarfRegNum<[11]>; // a2
  def R12   : SimReg<12, "r12">,   DwarfRegNum<[12]>; // a3
  def R13   : SimReg<13, "r13">,   DwarfRegNum<[13]>; // t0
  def R14   : SimReg<14, "r14">,   DwarfRegNum<[14]>; // t1
  def R15   : SimReg<15, "r15">,   DwarfRegNum<[15]>; // t2

  // def F0    : SimReg<0,  "f0">,    DwarfRegNum<[16]>;
  // def F1    : SimReg<1,  "f1">,    DwarfRegNum<[17]>;
  // def F2    : SimReg<2,  "f2">,    DwarfRegNum<[18]>;
  // def F3    : SimReg<3,  "f3">,    DwarfRegNum<[19]>;
  // def F4    : SimReg<4,  "f4">,    DwarfRegNum<[20]>;
  // def F5    : SimReg<5,  "f5">,    DwarfRegNum<[21]>;
  // def F6    : SimReg<6,  "f6">,    DwarfRegNum<[22]>;
  // def F7    : SimReg<7,  "f7">,    DwarfRegNum<[23]>;
  // def F8    : SimReg<8,  "f8">,    DwarfRegNum<[24]>;
  // def F9    : SimReg<9,  "f9">,    DwarfRegNum<[25]>;
  // def F10   : SimReg<10, "f10">,   DwarfRegNum<[26]>;
  // def F11   : SimReg<11, "f11">,   DwarfRegNum<[27]>;
  // def F12   : SimReg<12, "f12">,   DwarfRegNum<[28]>;
  // def F13   : SimReg<13, "f13">,   DwarfRegNum<[29]>;
  // def F14   : SimReg<14, "f14">,   DwarfRegNum<[30]>;
  // def F15   : SimReg<15, "f15">,   DwarfRegNum<[31]>;
}

//===----------------------------------------------------------------------===//
//@Register Classes
//===----------------------------------------------------------------------===//

def GPR : RegisterClass<"Sim", [i32], 32, (sequence "R%u", 0, 15)>;

// def FPR : RegisterClass<"Sim", [f32], 32, (sequence "F%u", 0, 15)>;

// skipped
// def GPROpnd : RegisterOperand<GPR>;