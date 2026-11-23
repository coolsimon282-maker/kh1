// Library code (Final Mix). One function at a time: replace an INCLUDE_ASM line with matching C.
// Data this file owns is still in the data segments: declare it extern here, do not define it.
#include "common.h"

INCLUDE_ASM("asm/nonmatchings/lib/libkernl/cache", _sceSDC);

INCLUDE_ASM("asm/nonmatchings/lib/libkernl/cache", SyncDCache);

void _sceSDC(int start, int end);

void iSyncDCache(int start, int end) {
    _sceSDC(start & 0xFFFFFFC0, end & 0xFFFFFFC0);
}

INCLUDE_ASM("asm/nonmatchings/lib/libkernl/cache", _sceIDC);

INCLUDE_ASM("asm/nonmatchings/lib/libkernl/cache", InvalidDCache);

void _sceIDC(int start, int end);

void iInvalidDCache(int start, int end) {
    _sceIDC(start & 0xFFFFFFC0, end & 0xFFFFFFC0);
}
