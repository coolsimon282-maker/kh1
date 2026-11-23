// Library code (Final Mix). One function at a time: replace an INCLUDE_ASM line with matching C.
// Data this file owns is still in the data segments: declare it extern here, do not define it.
#include "common.h"

INCLUDE_ASM("asm/nonmatchings/lib/libkernl/iopreset", sceSifResetIop);

INCLUDE_ASM("asm/nonmatchings/lib/libkernl/iopreset", sceSifIsAliveIop);

INCLUDE_ASM("asm/nonmatchings/lib/libkernl/iopreset", sceSifSyncIop);

INCLUDE_ASM("asm/nonmatchings/lib/libkernl/iopreset", sceSifRebootIop);
