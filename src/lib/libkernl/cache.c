// Library code (Final Mix). One function at a time: replace an INCLUDE_ASM line with matching C.
// Data this file owns is still in the data segments: declare it extern here, do not define it.
#include "common.h"

INCLUDE_ASM("asm/nonmatchings/lib/libkernl/cache", _sceSDC);

INCLUDE_ASM("asm/nonmatchings/lib/libkernl/cache", SyncDCache);

INCLUDE_ASM("asm/nonmatchings/lib/libkernl/cache", iSyncDCache);

INCLUDE_ASM("asm/nonmatchings/lib/libkernl/cache", _sceIDC);

INCLUDE_ASM("asm/nonmatchings/lib/libkernl/cache", InvalidDCache);

INCLUDE_ASM("asm/nonmatchings/lib/libkernl/cache", iInvalidDCache);
