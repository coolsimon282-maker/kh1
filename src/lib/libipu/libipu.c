// Library code (Final Mix). One function at a time: replace an INCLUDE_ASM line with matching C.
// Data this file owns is still in the data segments: declare it extern here, do not define it.
#include "common.h"

INCLUDE_ASM("asm/nonmatchings/lib/libipu/libipu", setD3_CHCR);

INCLUDE_ASM("asm/nonmatchings/lib/libipu/libipu", setD4_CHCR);

INCLUDE_ASM("asm/nonmatchings/lib/libipu/libipu", sceIpuStopDMA);

INCLUDE_ASM("asm/nonmatchings/lib/libipu/libipu", sceIpuRestartDMA);

INCLUDE_ASM("asm/nonmatchings/lib/libipu/libipu", sceIpuSync);
