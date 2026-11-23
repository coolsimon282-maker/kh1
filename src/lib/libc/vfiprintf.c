// Library code (Final Mix). One function at a time: replace an INCLUDE_ASM line with matching C.
// Data this file owns is still in the data segments: declare it extern here, do not define it.
#include "../../../include/include_asm.h"

INCLUDE_ASM("asm/nonmatchings/lib/libc/vfiprintf", __sprint);

INCLUDE_ASM("asm/nonmatchings/lib/libc/vfiprintf", __sbprintf);

INCLUDE_ASM("asm/nonmatchings/lib/libc/vfiprintf", vfiprintf);

INCLUDE_ASM("asm/nonmatchings/lib/libc/vfiprintf", _vfiprintf_r);
