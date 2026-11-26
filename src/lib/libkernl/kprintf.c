// Library code (Final Mix). One function at a time: replace an INCLUDE_ASM line with matching C.
// Data this file owns is still in the data segments: declare it extern here, do not define it.
#include "common.h"

int kputchar(int c)
{
    unsigned int base;

    do {
        base = 0x10000000;
    } while (*(volatile unsigned int *)(base | 0xF130) & 0x8000);

    *(unsigned char *)(base | 0xF180) = c;
    return c;
}

extern int D_004652D0;     /* deci2_count (0x0046AE4C) */
extern char D_00664E80[];  /* deci2_line[128] (0x0066AE80) */
int kputs(char *s);

void deci2Putchar(int c)
{
    int n;

    if (D_004652D0 >= 0x7E) {
        D_004652D0 = 0;
        D_00664E80[0x7F] = 0;
        kputs(D_00664E80);
    }
    n = D_004652D0;
    if (c == 0xA) {
        D_004652D0 = 0;
        D_00664E80[n] = c;
        D_00664E80[n + 1] = 0;
        kputs(D_00664E80);
    } else {
        D_004652D0 = n + 1;
        D_00664E80[n] = c;
    }
}

void serialPutchar(int c)
{
    if (c == 0xA) {
        kputchar(0xD);
        kputchar(0xA);
    } else {
        kputchar(c);
    }
}

/* gas 2.10 (configure.py LIB_GAS210_FILES): it fills the delay slots the original has filled. */
int ftoi(unsigned long long a)
{
    unsigned long long m = a;
    long long e;

    e = (long long)((m << 1) >> 53);
    e -= 1075;
    if (e < -53) {
        return 0;
    }
    if (e >= 13) {
        return 9999;
    }
    m = (m << 12) >> 12;
    m |= (unsigned long long)1 << 52;
    if (e < 0) {
        int s;

        e = -e;
        s = e - 2;
        m >>= s;
        if ((m & 3) == 3) {
            m = (m >> 2) + 1;
        } else {
            m >>= 2;
        }
    } else {
        m <<= e;
    }
    return (int)m;
}

INCLUDE_ASM("asm/nonmatchings/lib/libkernl/kprintf", printfloat);

INCLUDE_ASM("asm/nonmatchings/lib/libkernl/kprintf", _printf);

void _printf(char *fmt, char *ap);

void kprintf(char *fmt, ...)
{
    void *va = (char *)__builtin_next_arg(fmt) - 0x38;
    _printf(fmt, va);
}

typedef void (*PutcharFn)(int c);
extern PutcharFn D_0046AE50; /* putchar_fn */

void scePrintf(char *fmt, ...)
{
    void *va = (char *)__builtin_next_arg(fmt) - 0x38;
    PutcharFn save = D_0046AE50;

    D_0046AE50 = (PutcharFn)deci2Putchar;
    _printf(fmt, va);
    D_0046AE50 = save;
}
