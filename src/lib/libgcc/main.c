// Library code (Final Mix). One function at a time: replace an INCLUDE_ASM line with matching C.
// Data this file owns is still in the data segments: declare it extern here, do not define it.
#include "common.h"

INCLUDE_ASM("asm/nonmatchings/lib/libgcc/main", __do_global_dtors);

INCLUDE_ASM("asm/nonmatchings/lib/libgcc/main", __do_global_ctors);

INCLUDE_ASM("asm/nonmatchings/lib/libgcc/main", __main);
