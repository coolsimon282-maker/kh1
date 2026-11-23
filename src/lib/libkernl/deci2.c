// Library code (Final Mix). One function at a time: replace an INCLUDE_ASM line with matching C.
// Data this file owns is still in the data segments: declare it extern here, do not define it.
#include "common.h"

INCLUDE_ASM("asm/nonmatchings/lib/libkernl/deci2", sceDeci2Open);

INCLUDE_ASM("asm/nonmatchings/lib/libkernl/deci2", sceDeci2Close);

INCLUDE_ASM("asm/nonmatchings/lib/libkernl/deci2", sceDeci2ReqSend);

INCLUDE_ASM("asm/nonmatchings/lib/libkernl/deci2", sceDeci2Poll);

INCLUDE_ASM("asm/nonmatchings/lib/libkernl/deci2", sceDeci2ExRecv);

INCLUDE_ASM("asm/nonmatchings/lib/libkernl/deci2", sceDeci2ExSend);

INCLUDE_ASM("asm/nonmatchings/lib/libkernl/deci2", sceDeci2ExReqSend);

INCLUDE_ASM("asm/nonmatchings/lib/libkernl/deci2", sceDeci2ExLock);

INCLUDE_ASM("asm/nonmatchings/lib/libkernl/deci2", sceDeci2ExUnLock);

INCLUDE_ASM("asm/nonmatchings/lib/libkernl/deci2", kputs);
