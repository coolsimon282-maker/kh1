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

#include <reent.h>

extern struct _Bigint *_multadd(struct _reent *ptr, struct _Bigint *b, int x, int d);

struct _Bigint *_s2b(struct _reent *ptr, const char *s, int nd0, int nd, unsigned int y9)
{
    struct _Bigint *b;
    int i, k;
    int x, y;

    x = (nd + 8) / 9;
    for (k = 0, y = 1; x > y; y <<= 1, k++)
        ;
    b = _Balloc(ptr, k);
    b->_x[0] = y9;
    b->_wds = 1;
    i = 9;
    if (9 < nd0) {
        s += 9;
        do
            b = _multadd(ptr, b, 10, *s++ - '0');
        while (++i < nd0);
        s++;
    } else
        s += 10;
    for (; i < nd; i++)
        b = _multadd(ptr, b, 10, *s++ - '0');
    return b;
}

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

#include <reent.h>

extern struct _Bigint *_Balloc(struct _reent *ptr, int i);

#define Storeinc(p, hi, lo) \
    (*(unsigned short *)(p) = (unsigned short)(lo), \
     *(((unsigned short *)(p)) + 1) = (unsigned short)(hi), \
     (p) = (unsigned int *)((unsigned char *)(p) + 4))

struct _Bigint *_multiply(struct _reent *ptr, struct _Bigint *a, struct _Bigint *b)
{
    struct _Bigint *c;
    int k, wa, wb, wc;
    unsigned int carry, *x, *xa, *xae, *xb, *xbe, *xc, *xc0, y, z;
    unsigned int z2;

    if (a->_wds < b->_wds) {
        c = a;
        a = b;
        b = c;
    }
    k = a->_k;
    wa = a->_wds;
    wb = b->_wds;
    wc = wa + wb;
    if (wc > a->_maxwds) {
        k++;
    }
    c = _Balloc(ptr, k);
    for (x = c->_x, xa = x + wc; x < xa; x++) {
        *x = 0;
    }
    xa = a->_x;
    xae = xa + wa;
    xb = b->_x;
    xbe = xb + wb;
    xc0 = c->_x;
    for (; xb < xbe; xb++, xc0++) {
        if ((y = *xb & 0xFFFF) != 0) {
            x = xa;
            xc = xc0;
            carry = 0;
            do {
                z = (*x & 0xFFFF) * y + (*xc & 0xFFFF) + carry;
                carry = z >> 16;
                z2 = (*x++ >> 16) * y + (*xc >> 16) + carry;
                carry = z2 >> 16;
                Storeinc(xc, z2, z);
            } while (x < xae);
            *xc = carry;
        }
        if ((y = *xb >> 16) != 0) {
            x = xa;
            xc = xc0;
            carry = 0;
            z2 = *xc;
            do {
                z = (*x & 0xFFFF) * y + (*xc >> 16) + carry;
                carry = z >> 16;
                Storeinc(xc, z, z2);
                z2 = (*x++ >> 16) * y + (*xc & 0xFFFF) + carry;
                carry = z2 >> 16;
            } while (x < xae);
            *xc = z2;
        }
    }
    for (xc0 = c->_x, xc = xc0 + wc; wc > 0 && *--xc == 0; wc--) {
        ;
    }
    c->_wds = wc;
    return c;
}

INCLUDE_ASM("asm/nonmatchings/lib/libc/mprec", _pow5mult);

extern struct _Bigint *_Balloc(struct _reent *ptr, int i);
void _Bfree(struct _reent *ptr, struct _Bigint *v);

struct _Bigint *_lshift(struct _reent *ptr, struct _Bigint *b, int k)
{
    int i, k1, n, n1;
    struct _Bigint *b1;
    unsigned int *x, *x1, *xe, z;

    n = k >> 5;
    k1 = b->_k;
    n1 = n + b->_wds + 1;
    for (i = b->_maxwds; n1 > i; i <<= 1) {
        k1++;
    }
    b1 = _Balloc(ptr, k1);
    x1 = b1->_x;
    for (i = 0; i < n; i++) {
        *x1++ = 0;
    }
    x = b->_x;
    xe = x + b->_wds;
    if (k &= 0x1F) {
        k1 = 32 - k;
        z = 0;
        do {
            *x1++ = *x << k | z;
            z = *x++ >> k1;
        } while (x < xe);
        if ((*x1 = z) != 0) {
            ++n1;
        }
    } else {
        do {
            *x1++ = *x++;
        } while (x < xe);
    }
    b1->_wds = n1 - 1;
    _Bfree(ptr, b);
    return b1;
}

INCLUDE_ASM("asm/nonmatchings/lib/libc/mprec", __mcmp);

INCLUDE_ASM("asm/nonmatchings/lib/libc/mprec", __mdiff);

INCLUDE_ASM("asm/nonmatchings/lib/libc/mprec", _ulp);

#include <reent.h>

typedef union {
    double d;
    struct {
        unsigned int lo;
        unsigned int hi;
    } words;
} MpDouble;

#define word0(d) (d).words.hi
#define word1(d) (d).words.lo

extern int _hi0bits(unsigned int);

double _b2d(struct _Bigint *a, int *e)
{
    unsigned int *xa, *xa0, w, y, z;
    int k;
    MpDouble d;

    xa0 = a->_x;
    xa = xa0 + a->_wds;
    y = *--xa;
    k = _hi0bits(y);
    *e = 32 - k;
    if (k < 11) {
        word0(d) = 0x3FF00000 | y >> (11 - k);
        w = xa > xa0 ? *--xa : 0;
        word1(d) = y << (21 + k) | w >> (11 - k);
    } else {
        z = xa > xa0 ? *--xa : 0;
        k -= 11;
        if (k != 0) {
            word0(d) = 0x3FF00000 | y << k | z >> (32 - k);
            y = xa > xa0 ? *--xa : 0;
            word1(d) = z << k | y >> (32 - k);
        } else {
            word0(d) = 0x3FF00000 | y;
            word1(d) = z;
        }
    }
    return d.d;
}

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
