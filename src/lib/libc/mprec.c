// Library code (Final Mix). One function at a time: replace an INCLUDE_ASM line with matching C.
// Data this file owns is still in the data segments: declare it extern here, do not define it.
#include "../../../include/include_asm.h"

INCLUDE_ASM("asm/nonmatchings/lib/libc/mprec", _Balloc);

INCLUDE_ASM("asm/nonmatchings/lib/libc/mprec", _Bfree);

INCLUDE_ASM("asm/nonmatchings/lib/libc/mprec", _multadd);

INCLUDE_ASM("asm/nonmatchings/lib/libc/mprec", _s2b);

INCLUDE_ASM("asm/nonmatchings/lib/libc/mprec", _hi0bits);

INCLUDE_ASM("asm/nonmatchings/lib/libc/mprec", _lo0bits);

INCLUDE_ASM("asm/nonmatchings/lib/libc/mprec", _i2b);

INCLUDE_ASM("asm/nonmatchings/lib/libc/mprec", _multiply);

INCLUDE_ASM("asm/nonmatchings/lib/libc/mprec", _pow5mult);

INCLUDE_ASM("asm/nonmatchings/lib/libc/mprec", _lshift);

INCLUDE_ASM("asm/nonmatchings/lib/libc/mprec", __mcmp);

INCLUDE_ASM("asm/nonmatchings/lib/libc/mprec", __mdiff);

INCLUDE_ASM("asm/nonmatchings/lib/libc/mprec", _ulp);

INCLUDE_ASM("asm/nonmatchings/lib/libc/mprec", _b2d);

INCLUDE_ASM("asm/nonmatchings/lib/libc/mprec", _d2b);

INCLUDE_ASM("asm/nonmatchings/lib/libc/mprec", _ratio);

INCLUDE_ASM("asm/nonmatchings/lib/libc/mprec", _mprec_log10);
