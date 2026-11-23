// Library code (Final Mix). One function at a time: replace an INCLUDE_ASM line with matching C.
// Data this file owns is still in the data segments: declare it extern here, do not define it.
#include "common.h"

INCLUDE_ASM("asm/nonmatchings/lib/libkernl/intr", QueryIntrContext);

INCLUDE_ASM("asm/nonmatchings/lib/libkernl/intr", DisableIntc);

INCLUDE_ASM("asm/nonmatchings/lib/libkernl/intr", EnableIntc);

INCLUDE_ASM("asm/nonmatchings/lib/libkernl/intr", DisableDmac);

INCLUDE_ASM("asm/nonmatchings/lib/libkernl/intr", EnableDmac);

INCLUDE_ASM("asm/nonmatchings/lib/libkernl/intr", iEnableIntc);

INCLUDE_ASM("asm/nonmatchings/lib/libkernl/intr", iDisableIntc);

INCLUDE_ASM("asm/nonmatchings/lib/libkernl/intr", iEnableDmac);

INCLUDE_ASM("asm/nonmatchings/lib/libkernl/intr", iDisableDmac);
