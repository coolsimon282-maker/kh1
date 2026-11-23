// Library code (Final Mix). One function at a time: replace an INCLUDE_ASM line with matching C.
// Data this file owns is still in the data segments: declare it extern here, do not define it.
#include "common.h"

INCLUDE_ASM("asm/nonmatchings/lib/libkernl/eeloadfile", _lf_bind);

INCLUDE_ASM("asm/nonmatchings/lib/libkernl/eeloadfile", _lf_version);

INCLUDE_ASM("asm/nonmatchings/lib/libkernl/eeloadfile", sceSifLoadFileReset);

INCLUDE_ASM("asm/nonmatchings/lib/libkernl/eeloadfile", _sceSifLoadModuleBuffer);

INCLUDE_ASM("asm/nonmatchings/lib/libkernl/eeloadfile", sceSifStopModule);

INCLUDE_ASM("asm/nonmatchings/lib/libkernl/eeloadfile", sceSifUnloadModule);

INCLUDE_ASM("asm/nonmatchings/lib/libkernl/eeloadfile", sceSifSearchModuleByName);

INCLUDE_ASM("asm/nonmatchings/lib/libkernl/eeloadfile", sceSifSearchModuleByAddress);

INCLUDE_ASM("asm/nonmatchings/lib/libkernl/eeloadfile", sceSifLoadModuleBuffer);

INCLUDE_ASM("asm/nonmatchings/lib/libkernl/eeloadfile", sceSifLoadStartModuleBuffer);

INCLUDE_ASM("asm/nonmatchings/lib/libkernl/eeloadfile", _sceSifLoadModule);

INCLUDE_ASM("asm/nonmatchings/lib/libkernl/eeloadfile", sceSifLoadModule);

INCLUDE_ASM("asm/nonmatchings/lib/libkernl/eeloadfile", _sceSifLoadStartModule);

INCLUDE_ASM("asm/nonmatchings/lib/libkernl/eeloadfile", _sceSifLoadElfPart);

INCLUDE_ASM("asm/nonmatchings/lib/libkernl/eeloadfile", sceSifLoadElfPart);

INCLUDE_ASM("asm/nonmatchings/lib/libkernl/eeloadfile", sceSifLoadElf);

INCLUDE_ASM("asm/nonmatchings/lib/libkernl/eeloadfile", sceSifGetIopAddr);

INCLUDE_ASM("asm/nonmatchings/lib/libkernl/eeloadfile", sceSifSetIopAddr);
