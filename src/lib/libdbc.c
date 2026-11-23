// Library code (Final Mix). One function at a time: replace an INCLUDE_ASM line with matching C.
// Data this file owns is still in the data segments: declare it extern here, do not define it.
#include "common.h"

INCLUDE_ASM("asm/nonmatchings/lib/libdbc", sceDbcGetModVersion);

INCLUDE_ASM("asm/nonmatchings/lib/libdbc", sceDbcInit);

INCLUDE_ASM("asm/nonmatchings/lib/libdbc", sceDbcEnd);

INCLUDE_ASM("asm/nonmatchings/lib/libdbc", sceDbcSetWorkAddr);

INCLUDE_ASM("asm/nonmatchings/lib/libdbc", sceDbcCreateSocket);

INCLUDE_ASM("asm/nonmatchings/lib/libdbc", sceDbcDeleteSocket);

INCLUDE_ASM("asm/nonmatchings/lib/libdbc", sceDbcGetDepNumber);

INCLUDE_ASM("asm/nonmatchings/lib/libdbc", sceDbcInitSocket);

INCLUDE_ASM("asm/nonmatchings/lib/libdbc", sceDbcResetSocket);

INCLUDE_ASM("asm/nonmatchings/lib/libdbc", sceDbcGetDeviceStatus);

INCLUDE_ASM("asm/nonmatchings/lib/libdbc", sceDbcSRData);

INCLUDE_ASM("asm/nonmatchings/lib/libdbc", sceDbcSendData);

INCLUDE_ASM("asm/nonmatchings/lib/libdbc", sceDbcSendData2);

INCLUDE_ASM("asm/nonmatchings/lib/libdbc", sceDbcReceiveData);

INCLUDE_ASM("asm/nonmatchings/lib/libdbc", DPRINT);
