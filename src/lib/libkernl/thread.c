// Library code (Final Mix). One function at a time: replace an INCLUDE_ASM line with matching C.
// Data this file owns is still in the data segments: declare it extern here, do not define it.
#include "common.h"

INCLUDE_ASM("asm/nonmatchings/lib/libkernl/thread", topThread);

INCLUDE_ASM("asm/nonmatchings/lib/libkernl/thread", InitThread);

INCLUDE_ASM("asm/nonmatchings/lib/libkernl/thread", iWakeupThread);

INCLUDE_ASM("asm/nonmatchings/lib/libkernl/thread", iRotateThreadReadyQueue);

INCLUDE_ASM("asm/nonmatchings/lib/libkernl/thread", iSuspendThread);
