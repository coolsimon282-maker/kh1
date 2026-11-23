// Library code (Final Mix). One function at a time: replace an INCLUDE_ASM line with matching C.
// Data this file owns is still in the data segments: declare it extern here, do not define it.
#include "../../../include/include_asm.h"

INCLUDE_ASM("asm/nonmatchings/lib/libm/e_rem_pio2", __ieee754_rem_pio2);
