// Library code (Final Mix). One function at a time: replace an INCLUDE_ASM line with matching C.
// Data this file owns is still in the data segments: declare it extern here, do not define it.
#include "../../../include/include_asm.h"
#include <stdlib.h>
#include <string.h>
#include <reent.h>

extern void *_calloc_r(struct _reent *, size_t, size_t);

struct _Bigint *_Balloc(struct _reent *ptr, int k)
{
    int x;
    struct _Bigint *rv;

    if (ptr->_freelist == NULL) {
        ptr->_freelist = (struct _Bigint **)_calloc_r(ptr, sizeof(struct _Bigint *), 16);
        if (ptr->_freelist == NULL) {
            return NULL;
        }
    }

    if ((rv = ptr->_freelist[k]) != 0) {
        ptr->_freelist[k] = rv->_next;
    } else {
        x = 1 << k;
        rv = (struct _Bigint *)_calloc_r(ptr, 1, sizeof(struct _Bigint) + (x - 1) * sizeof(rv->_x));
        if (rv == NULL)
            return NULL;
        rv->_k = k;
        rv->_maxwds = x;
    }
    rv->_sign = rv->_wds = 0;
    return rv;
}

#include <reent.h>

void _Bfree(struct _reent *ptr, struct _Bigint *v)
{
    if (v) {
        v->_next = ptr->_freelist[v->_k];
        ptr->_freelist[v->_k] = v;
    }
}

struct _Bigint *_Balloc(struct _reent *ptr, int k);
void _Bfree(struct _reent *ptr, struct _Bigint *v);

#define Bcopy(x, y) memcpy((char *)&x->_sign, (char *)&y->_sign, y->_wds * sizeof(__Long) + 2 * sizeof(int))

struct _Bigint *_multadd(struct _reent *ptr, struct _Bigint *b, int m, int a)
{
    int i, wds;
    __ULong *x, y;
    __ULong xi, z;
    struct _Bigint *b1;

    wds = b->_wds;
    x = b->_x;
    i = 0;
    do {
        xi = *x;
        y = (xi & 0xffff) * m + a;
        z = (xi >> 16) * m + (y >> 16);
        a = (int)(z >> 16);
        *x++ = (z << 16) + (y & 0xffff);
    } while (++i < wds);
    if (a) {
        if (wds >= b->_maxwds) {
            b1 = _Balloc(ptr, b->_k + 1);
            Bcopy(b1, b);
            _Bfree(ptr, b);
            b = b1;
        }
        b->_x[wds++] = a;
        b->_wds = wds;
    }
    return b;
}

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

int _hi0bits(register __ULong x)
{
    register int k = 0;

    if (!(x & 0xffff0000)) {
        k = 16;
        x <<= 16;
    }
    if (!(x & 0xff000000)) {
        k += 8;
        x <<= 8;
    }
    if (!(x & 0xf0000000)) {
        k += 4;
        x <<= 4;
    }
    if (!(x & 0xc0000000)) {
        k += 2;
        x <<= 2;
    }
    if (!(x & 0x80000000)) {
        k++;
        if (!(x & 0x40000000))
            return 32;
    }
    return k;
}

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

extern const int D_00491FD0[3]; /* p05: 5, 25, 125 */

struct _Bigint *_pow5mult(struct _reent *ptr, struct _Bigint *b, int k)
{
    struct _Bigint *b1, *p5, *p51;
    int i;

    if ((i = k & 3) != 0)
        b = _multadd(ptr, b, D_00491FD0[i - 1], 0);

    if (!(k >>= 2))
        return b;
    if (!(p5 = ptr->_p5s)) {
        p5 = ptr->_p5s = _i2b(ptr, 625);
        p5->_next = 0;
    }
    for (;;) {
        if (k & 1) {
            b1 = _multiply(ptr, b, p5);
            _Bfree(ptr, b);
            b = b1;
        }
        if (!(k >>= 1))
            break;
        if (!(p51 = p5->_next)) {
            p51 = p5->_next = _multiply(ptr, p5, p5);
            p51->_next = 0;
        }
        p5 = p51;
    }
    return b;
}

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

int __mcmp(struct _Bigint *a, struct _Bigint *b)
{
    __ULong *xa, *xa0, *xb, *xb0;
    int i, j;

    i = a->_wds;
    j = b->_wds;
    if (i -= j)
        return i;
    xa0 = a->_x;
    xa = xa0 + j;
    xb0 = b->_x;
    xb = xb0 + j;
    for (;;) {
        if (*--xa != *--xb)
            return *xa < *xb ? -1 : 1;
        if (xa <= xa0)
            break;
    }
    return 0;
}

#define Storeinc(a, b, c) (((unsigned short *)a)[1] = (unsigned short)b, ((unsigned short *)a)[0] = (unsigned short)c, a++)

struct _Bigint *__mdiff(struct _reent *ptr, struct _Bigint *a, struct _Bigint *b)
{
    struct _Bigint *c;
    int i, wa, wb;
    __Long borrow, y;
    __ULong *xa, *xae, *xb, *xbe, *xc;
    __Long z;

    i = __mcmp(a, b);
    if (!i) {
        c = _Balloc(ptr, 0);
        c->_wds = 1;
        c->_x[0] = 0;
        return c;
    }
    if (i < 0) {
        c = a;
        a = b;
        b = c;
        i = 1;
    } else
        i = 0;
    c = _Balloc(ptr, a->_k);
    c->_sign = i;
    wa = a->_wds;
    xa = a->_x;
    xae = xa + wa;
    wb = b->_wds;
    xb = b->_x;
    xbe = xb + wb;
    xc = c->_x;
    borrow = 0;
    do {
        y = (*xa & 0xffff) - (*xb & 0xffff) + borrow;
        borrow = y >> 16;
        z = (*xa++ >> 16) - (*xb++ >> 16) + borrow;
        borrow = z >> 16;
        Storeinc(xc, z, y);
    } while (xb < xbe);
    while (xa < xae) {
        y = (*xa & 0xffff) + borrow;
        borrow = y >> 16;
        z = (*xa++ >> 16) + borrow;
        borrow = z >> 16;
        Storeinc(xc, z, y);
    }
    while (!*--xc)
        wa--;
    c->_wds = wa;
    return c;
}

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

extern int _lo0bits(unsigned int *y);

struct _Bigint *_d2b(struct _reent *ptr, double dd, int *e, int *bits)
{
    struct _Bigint *b;
    int de, i, k;
    unsigned int *x, y, z;
    MpDouble d;

    d.d = dd;
    b = _Balloc(ptr, 1);
    x = b->_x;
    z = word0(d) & 0xFFFFF;
    word0(d) &= 0x7FFFFFFF;
    if ((de = (int)(word0(d) >> 20)) != 0)
        z |= 0x100000;
    if (word1(d)) {
        y = word1(d);
        if ((k = _lo0bits(&y)) != 0) {
            x[0] = y | z << (32 - k);
            z >>= k;
        } else
            x[0] = y;
        i = b->_wds = (x[1] = z) ? 2 : 1;
    } else {
        k = _lo0bits(&z);
        x[0] = z;
        i = b->_wds = 1;
        k += 32;
    }
    if (de) {
        *e = de - 1023 - (53 - 1) + k;
        *bits = 53 - k;
    } else {
        *e = de - 1023 - (53 - 1) + 1 + k;
        *bits = 32 * i - _hi0bits(x[i - 1]);
    }
    return b;
}

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
