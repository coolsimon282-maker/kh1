// Library code (Final Mix). One function at a time: replace an INCLUDE_ASM line with matching C.
#include "common.h"

int DIntr(void);
int EIntr(void);

#define D_ENABLER ((volatile unsigned int *)0x1000F520)
#define D_ENABLEW ((volatile unsigned int *)0x1000F590)
#define D4_CHCR ((volatile unsigned int *)0x1000B400)
#define IPU_CMD ((volatile unsigned int *)0x10002000)
#define IPU_CTRL ((volatile int *)0x10002010)
#define IPU_in_FIFO 0x10007010

/* ipuinit.o's file-static setD4_CHCR */
void func_00272738(int chcr)
{
    DIntr();
    *D_ENABLEW = *D_ENABLER | 0x10000;
    *D4_CHCR = chcr;
    *D_ENABLEW = *D_ENABLER & 0xFFFEFFFF;
    EIntr();
}

typedef unsigned int u128_ipu __attribute__((mode(TI)));

#ifdef VERSION_FM
/* .data (0x0046E0B0-0x0046E120): the quantiser matrices (ipuQuantMatrix: the intra matrix, then one row of the
   non-intra matrix, sent four times) and the colour table (ipuColorTable) sceIpuInit loads */
union {
    unsigned char b[80];
    volatile u128_ipu q[5];
} D_0046E0B0 = {{
    8, 16, 16, 19, 16, 19, 22, 22, 22, 22, 22, 22, 26, 24, 26, 27,
    27, 27, 26, 26, 26, 26, 27, 27, 27, 29, 29, 29, 34, 34, 34, 29,
    29, 29, 27, 27, 29, 29, 32, 32, 34, 34, 37, 38, 37, 35, 35, 34,
    35, 38, 38, 40, 40, 40, 48, 48, 46, 46, 56, 56, 58, 69, 69, 83,
    16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16,
}};
union {
    unsigned short c[16];
    u128_ipu q[2];
} D_0046E100 = {{
    0x0000, 0x0421, 0x0842, 0x03E0, 0x1084, 0x14A5, 0x18C6, 0x1CE7,
    0x001F, 0x2529, 0x294A, 0x7C00, 0x318C, 0x35AD, 0x7FFF, 0x39CE,
}};
#else
/* the quantiser matrices (ipuQuantMatrix) and the colour table (ipuColorTable), still in .data */
extern union {
    unsigned char b[80];
    volatile u128_ipu q[5];
} D_0046E0B0;
extern union {
    unsigned short c[16];
    u128_ipu q[2];
} D_0046E100;
#endif

void sceIpuInit(void)
{
    func_00272738(1);
    *IPU_CTRL = 0x40000000;
    while (*IPU_CTRL < 0) {}
    *IPU_CMD = 0;
    while (*IPU_CTRL < 0) {}
    *(volatile u128_ipu *)IPU_in_FIFO = D_0046E0B0.q[0];
    *(volatile u128_ipu *)IPU_in_FIFO = D_0046E0B0.q[1];
    *(volatile u128_ipu *)IPU_in_FIFO = D_0046E0B0.q[2];
    *(volatile u128_ipu *)IPU_in_FIFO = D_0046E0B0.q[3];
    *(volatile u128_ipu *)IPU_in_FIFO = D_0046E0B0.q[4];
    *(volatile u128_ipu *)IPU_in_FIFO = D_0046E0B0.q[4];
    *(volatile u128_ipu *)IPU_in_FIFO = D_0046E0B0.q[4];
    *(volatile u128_ipu *)IPU_in_FIFO = D_0046E0B0.q[4];
    *IPU_CMD = 0x50000000;
    while (*IPU_CTRL < 0) {}
    *IPU_CMD = 0x58000000;
    while (*IPU_CTRL < 0) {}
    *(volatile u128_ipu *)IPU_in_FIFO = D_0046E100.q[0];
    *(volatile u128_ipu *)IPU_in_FIFO = D_0046E100.q[1];
    *IPU_CMD = 0x60000000;
    while (*IPU_CTRL < 0) {}
    *IPU_CMD = 0x90000000;
    while (*IPU_CTRL < 0) {}
    *IPU_CTRL = 0x40000000;
    while (*IPU_CTRL < 0) {}
    *IPU_CMD = 0;
    while (*IPU_CTRL < 0) {}
}

long func_00272C38(const char *s, char **end, int base);

/* newlib atoi */
int func_002729D8(const char *s)
{
    return (int)func_00272C38(s, 0, 10);
}

INCLUDE_ASM("asm/nonmatchings/lib/libipu/ipuinit", func_00272A00);

INCLUDE_ASM("asm/nonmatchings/lib/libipu/ipuinit", func_00272C38);
