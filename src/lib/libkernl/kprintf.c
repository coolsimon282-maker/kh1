// Library code (Final Mix). One function at a time: replace an INCLUDE_ASM line with matching C.
// Data this file owns is still in the data segments: declare it extern here, do not define it.
#include "common.h"

INCLUDE_ASM("asm/nonmatchings/lib/libkernl/kprintf", kputchar);

INCLUDE_ASM("asm/nonmatchings/lib/libkernl/kprintf", deci2Putchar);

INCLUDE_ASM("asm/nonmatchings/lib/libkernl/kprintf", serialPutchar);

INCLUDE_ASM("asm/nonmatchings/lib/libkernl/kprintf", ftoi);

INCLUDE_ASM("asm/nonmatchings/lib/libkernl/kprintf", printfloat);

INCLUDE_ASM("asm/nonmatchings/lib/libkernl/kprintf", _printf);

INCLUDE_ASM("asm/nonmatchings/lib/libkernl/kprintf", kprintf);

INCLUDE_ASM("asm/nonmatchings/lib/libkernl/kprintf", scePrintf);
