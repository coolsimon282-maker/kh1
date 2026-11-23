// Library code (Final Mix). One function at a time: replace an INCLUDE_ASM line with matching C.
// Data this file owns is still in the data segments: declare it extern here, do not define it.
#include "common.h"

INCLUDE_ASM("asm/nonmatchings/lib/libgraph", sceGsResetGraph);

INCLUDE_ASM("asm/nonmatchings/lib/libgraph", sceGsGetGParam);

INCLUDE_ASM("asm/nonmatchings/lib/libgraph", sceGsResetPath);

INCLUDE_ASM("asm/nonmatchings/lib/libgraph", func_00265558);

INCLUDE_ASM("asm/nonmatchings/lib/libgraph", GetGsDxDyOffset);

INCLUDE_ASM("asm/nonmatchings/lib/libgraph", sceGsSetDefDispEnv);

INCLUDE_ASM("asm/nonmatchings/lib/libgraph", sceGsPutDispEnv);

INCLUDE_ASM("asm/nonmatchings/lib/libgraph", sceGsPutDrawEnv);

INCLUDE_ASM("asm/nonmatchings/lib/libgraph", sceGsSyncV);

INCLUDE_ASM("asm/nonmatchings/lib/libgraph", sceGsSyncPath);

INCLUDE_ASM("asm/nonmatchings/lib/libgraph", sceGsSetDefLoadImage);

INCLUDE_ASM("asm/nonmatchings/lib/libgraph", sceGsSetDefStoreImage);

INCLUDE_ASM("asm/nonmatchings/lib/libgraph", sceGsExecLoadImage);

INCLUDE_ASM("asm/nonmatchings/lib/libgraph", sceGsExecStoreImage);

INCLUDE_ASM("asm/nonmatchings/lib/libgraph", sceGsSyncVCallback);
