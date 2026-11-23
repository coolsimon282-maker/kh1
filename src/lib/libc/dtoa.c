// Library code (Final Mix). One function at a time: replace an INCLUDE_ASM line with matching C.
// Data this file owns is still in the data segments: declare it extern here, do not define it.
#include "../../../include/include_asm.h"

INCLUDE_ASM("asm/nonmatchings/lib/libc/dtoa", quorem);

INCLUDE_ASM("asm/nonmatchings/lib/libc/dtoa", _dtoa_r);
