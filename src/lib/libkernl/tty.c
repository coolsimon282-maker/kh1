// Library code (Final Mix). One function at a time: replace an INCLUDE_ASM line with matching C.
// Data this file owns is still in the data segments: declare it extern here, do not define it.
#include "common.h"

INCLUDE_ASM("asm/nonmatchings/lib/libkernl/tty", QueueInit);

INCLUDE_ASM("asm/nonmatchings/lib/libkernl/tty", QueuePeekWriteDone);

INCLUDE_ASM("asm/nonmatchings/lib/libkernl/tty", QueuePeekReadDone);

INCLUDE_ASM("asm/nonmatchings/lib/libkernl/tty", sceTtyHandler);

INCLUDE_ASM("asm/nonmatchings/lib/libkernl/tty", sceTtyWrite);

INCLUDE_ASM("asm/nonmatchings/lib/libkernl/tty", sceTtyRead);

INCLUDE_ASM("asm/nonmatchings/lib/libkernl/tty", sceTtyInit);
