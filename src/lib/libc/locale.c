// Library code (Final Mix). One function at a time: replace an INCLUDE_ASM line with matching C.
// Data this file owns is still in the data segments: declare it extern here, do not define it.
#include "../../../include/include_asm.h"

INCLUDE_ASM("asm/nonmatchings/lib/libc/locale", _setlocale_r);

extern struct lconv D_00491F88;

struct lconv *_localeconv_r(struct Reent *data)
{
    return (struct lconv *)&D_00491F88;
}

INCLUDE_ASM("asm/nonmatchings/lib/libc/locale", setlocale);

INCLUDE_ASM("asm/nonmatchings/lib/libc/locale", localeconv);
