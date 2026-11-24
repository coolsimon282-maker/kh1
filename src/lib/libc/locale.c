// Library code (Final Mix). One function at a time: replace an INCLUDE_ASM line with matching C.
// Data this file owns is still in the data segments: declare it extern here, do not define it.
#include "../../../include/include_asm.h"
#include <string.h>
#include <locale.h>
#include <reent.h>

extern struct lconv D_00491F88; /* lconv */
extern char D_00491FC8[];       /* "C" */
extern char D_00491FB8[];       /* "" */

char *_setlocale_r(struct _reent *p, int category, const char *locale)
{
    if (locale) {
        if (strcmp(locale, D_00491FC8) && strcmp(locale, D_00491FB8))
            return 0;
        p->_current_category = category;
        p->_current_locale = locale;
    }
    return D_00491FC8;
}

struct lconv *_localeconv_r(struct _reent *data)
{
    return (struct lconv *)&D_00491F88;
}

char *setlocale(int category, const char *locale)
{
    return _setlocale_r(_impure_ptr, category, locale);
}

struct lconv *localeconv(void)
{
    return _localeconv_r(_impure_ptr);
}
