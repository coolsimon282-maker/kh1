// Library code (Final Mix). One function at a time: replace an INCLUDE_ASM line with matching C.
// Data this file owns is still in the data segments: declare it extern here, do not define it.
#include "../../../include/include_asm.h"

INCLUDE_ASM("asm/nonmatchings/lib/libc/mprec", _Balloc);

#include <reent.h>

void _Bfree(struct _reent *ptr, struct _Bigint *v)
{
    if (v) {
        v->_next = ptr->_freelist[v->_k];
        ptr->_freelist[v->_k] = v;
    }
}

INCLUDE_ASM("asm/nonmatchings/lib/libc/mprec", _multadd);

INCLUDE_ASM("asm/nonmatchings/lib/libc/mprec", _s2b);

INCLUDE_ASM("asm/nonmatchings/lib/libc/mprec", _hi0bits);

#include <reent.h>

int _lo0bits(unsigned int *y)
{
    unsigned int v = *y;
    int n;
    if (v & 7) {
        if (v & 1) {
            return 0;
        }
        if (v & 2) {
            *y = v >> 1;
            return 1;
        }
        *y = v >> 2;
        return 2;
    }
    n = 0;
    if ((v & 0xFFFF) == 0) {
        n = 0x10;
        v >>= 16;
    }
    if ((v & 0xFF) == 0) {
        n += 8;
        v >>= 8;
    }
    if ((v & 0xF) == 0) {
        n += 4;
        v >>= 4;
    }
    if ((v & 3) == 0) {
        n += 2;
        v >>= 2;
    }
    if (v & 1) {
        *y = v;
    } else {
        v >>= 1;
        n += 1;
        if (v == 0) {
            return 0x20;
        }
        *y = v;
    }
    return n;
}

extern struct _Bigint *_Balloc(struct _reent *ptr, int i);

struct _Bigint *_i2b(struct _reent *ptr, int i)
{
    struct _Bigint *b;

    b = _Balloc(ptr, 1);
    b->_x[0] = i;
    b->_wds = 1;
    return b;
}

INCLUDE_ASM("asm/nonmatchings/lib/libc/mprec", _multiply);

INCLUDE_ASM("asm/nonmatchings/lib/libc/mprec", _pow5mult);

INCLUDE_ASM("asm/nonmatchings/lib/libc/mprec", _lshift);

INCLUDE_ASM("asm/nonmatchings/lib/libc/mprec", __mcmp);

INCLUDE_ASM("asm/nonmatchings/lib/libc/mprec", __mdiff);

INCLUDE_ASM("asm/nonmatchings/lib/libc/mprec", _ulp);

INCLUDE_ASM("asm/nonmatchings/lib/libc/mprec", _b2d);

INCLUDE_ASM("asm/nonmatchings/lib/libc/mprec", _d2b);

INCLUDE_ASM("asm/nonmatchings/lib/libc/mprec", _ratio);

extern double D_00491FE0[];

static double dpmul(double a, double b);

double _mprec_log10(int dig)
{
    double v = 1.0;

    if (dig < 24) {
        return D_00491FE0[dig];
    }
    while (dig > 0) {
        v = dpmul(v, 10.0);
        dig--;
    }
    return v;
}
