// Library code (Final Mix). One function at a time: replace an INCLUDE_ASM line with matching C.
// Data this file owns is still in the data segments: declare it extern here, do not define it.
#include "common.h"

INCLUDE_ASM("asm/nonmatchings/lib/libkernl/tlbfunc", SetTLBHandler);

INCLUDE_ASM("asm/nonmatchings/lib/libkernl/tlbfunc", SetDebugHandler);

INCLUDE_ASM("asm/nonmatchings/lib/libkernl/tlbfunc", func_002608D0);

INCLUDE_ASM("asm/nonmatchings/lib/libkernl/tlbfunc", func_002608E0);

INCLUDE_ASM("asm/nonmatchings/lib/libkernl/tlbfunc", func_00260918);

INCLUDE_ASM("asm/nonmatchings/lib/libkernl/tlbfunc", func_00260928);

INCLUDE_ASM("asm/nonmatchings/lib/libkernl/tlbfunc", InitTLBFunctions);

INCLUDE_ASM("asm/nonmatchings/lib/libkernl/tlbfunc", PutTLBEntry);

INCLUDE_ASM("asm/nonmatchings/lib/libkernl/tlbfunc", func_00260A10);

INCLUDE_ASM("asm/nonmatchings/lib/libkernl/tlbfunc", func_00260A20);

INCLUDE_ASM("asm/nonmatchings/lib/libkernl/tlbfunc", _SetTLBEntry);

INCLUDE_ASM("asm/nonmatchings/lib/libkernl/tlbfunc", iSetTLBEntry);

INCLUDE_ASM("asm/nonmatchings/lib/libkernl/tlbfunc", func_00260A70);

INCLUDE_ASM("asm/nonmatchings/lib/libkernl/tlbfunc", iGetTLBEntry);

INCLUDE_ASM("asm/nonmatchings/lib/libkernl/tlbfunc", ProbeTLBEntry);

INCLUDE_ASM("asm/nonmatchings/lib/libkernl/tlbfunc", func_00260AA0);

INCLUDE_ASM("asm/nonmatchings/lib/libkernl/tlbfunc", func_00260AB0);

INCLUDE_ASM("asm/nonmatchings/lib/libkernl/tlbfunc", func_00260AC0);

INCLUDE_ASM("asm/nonmatchings/lib/libkernl/tlbfunc", InitTLB32MB);

INCLUDE_ASM("asm/nonmatchings/lib/libkernl/tlbfunc", _kTLBException);
