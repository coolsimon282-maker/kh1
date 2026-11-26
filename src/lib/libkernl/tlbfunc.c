// Library code (Final Mix). One function at a time: replace an INCLUDE_ASM line with matching C.
// Its .data is defined after the TlbSyscallEntry type below.
#include "common.h"

/* the kernel syscall stubs: `addiu $3,$0,NUM; syscall 0; jr $31; nop` */
#define SYSCALL_STUB(T, name, num)                                                                  \
    T name()                                                                                       \
    {                                                                                              \
        __asm__ __volatile__("addiu $3, $0, " #num "\n\tsyscall 0");                               \
    }

#ifndef VERSION_FM
extern void *D_0046C1C0;      /* the TLB handler SetTLBHandler installs */
extern void *D_0046C1C8[];    /* the debug handler table, by cause */
#else
extern void* D_0046C1C0;
extern void* D_0046C1C8[];
#endif
void func_00260D00(void);
void _kDebugException(void);
int SetVTLBRefillHandler(int cause, void *fn);
int SetVCommonHandler(int cause, void *fn);

void *SetTLBHandler(void *fn)
{
    D_0046C1C0 = fn;
    SetVTLBRefillHandler(1, func_00260D00);
    SetVTLBRefillHandler(2, func_00260D00);
    SetVTLBRefillHandler(3, func_00260D00);
    return fn;
}

void *SetDebugHandler(int cause, void *fn)
{
    void *old;

    if ((unsigned int)(cause - 1) >= 13) {
        return (void *)0xFFFFFFFF;
    }
    old = D_0046C1C8[cause];
    D_0046C1C8[cause] = fn;
    if ((unsigned int)(cause - 1) < 3) {
        SetVTLBRefillHandler(cause, _kDebugException);
    } else {
        SetVCommonHandler(cause, _kDebugException);
    }
    return old;
}

SYSCALL_STUB(void, func_002608D0, 0x5A)

int func_002608E0(unsigned int *dst, unsigned int *src, unsigned int size)
{
    unsigned int i;

    size >>= 2;
    for (i = 0; i < size; i++) {
        *dst++ = *src++;
    }
    return 0;
}

SYSCALL_STUB(int, func_00260918, 0x5B)

SYSCALL_STUB(void, func_00260928, 0x74)

typedef struct {
    int no;
    void *fn;
} TlbSyscallEntry;

#ifdef VERSION_FM
void _kExitTLBHandler(void);
extern char D_00494038[];

// .data (0x0046BE90-0x0046C4F0)
unsigned int fm_D_0046BE90[204] = { /* code copied to 0x80075000 */
    0x3C028007, 0x0000282D, 0x24435300, 0x00000000, 0x8C620000, 0x14820003, 0x24A50001, 0x03E00008,
    0x8C620004, 0x2CA20006, 0x1440FFF9, 0x24630008, 0x03E00008, 0x0000102D, 0x00051602, 0x304300F0,
    0x24020030, 0x10620014, 0x2C620031, 0x10400009, 0x24020010, 0x1062000E, 0x2C620011, 0x1040000A,
    0x24020020, 0x1060000C, 0x2402FFFF, 0x10000014, 0x00000000, 0x24020050, 0x10620005, 0x2C620051,
    0x10400003, 0x24020040, 0x10620003, 0x00000000, 0x03E00008, 0x2402FFFF, 0x40842800, 0x40855000,
    0x40861000, 0x40871800, 0x0000040F, 0x42000006, 0x0000040F, 0x42000008, 0x0000040F, 0x40020000,
    0x03E00008, 0x00000000, 0x2C820030, 0x1040000B, 0x2402FFFF, 0x40840000, 0x40852800, 0x40865000,
    0x40871000, 0x40881800, 0x0000040F, 0x42000002, 0x0000040F, 0x03E00008, 0x0080102D, 0x03E00008,
    0x00000000, 0x00000000, 0x2C820030, 0x14400003, 0x00000000, 0x03E00008, 0x2402FFFF, 0x40840000,
    0x0000040F, 0x42000001, 0x0000040F, 0x40022800, 0xACA20000, 0x40035000, 0xACC30000, 0x40021000,
    0xACE20000, 0x40031800, 0xAD030000, 0x03E00008, 0x0080102D, 0x00000000, 0x40845000, 0x0000040F,
    0x42000008, 0x0000040F, 0x40040000, 0x04810003, 0x00000000, 0x10000009, 0x2404FFFF, 0x42000001,
    0x0000040F, 0x40022800, 0xACA20000, 0x40031000, 0xACC30000, 0x40021800, 0xACE20000, 0x03E00008,
    0x0080102D, 0x00000000, 0x27BDFFD0, 0xFFB00010, 0x0080802D, 0x32020FFF, 0x14400007, 0xFFBF0020,
    0x3C02000F, 0x2603FFFF, 0x3442FFFE, 0x0043102B, 0x14400003, 0x3C047000, 0x1000003B, 0x2402FFFF,
    0x03A0282D, 0x34844000, 0x37A60004, 0x0C01D456, 0x37A70008, 0x0040282D, 0x04A10009, 0x00000000,
    0x12000031, 0x0000102D, 0x40053000, 0x24A20001, 0x40823000, 0x0000040F, 0x10000013, 0x00000000,
    0x16000011, 0x24A2FFFF, 0x3C03E001, 0x00021340, 0x00433021, 0x40023000, 0x2442FFFF, 0x40823000,
    0x40850000, 0x40802800, 0x40865000, 0x40801000, 0x40801800, 0x0000040F, 0x42000002, 0x0000040F,
    0x10000019, 0x0000102D, 0x3C02FFFF, 0x26041000, 0x3442F000, 0x3C067000, 0x00822024, 0xAFA00000,
    0x02021024, 0x00042182, 0x00021182, 0x3484001F, 0x3442001F, 0x34C64000, 0xAFA20004, 0xAFA40008,
    0x40850000, 0x0000182D, 0x40832800, 0x40865000, 0x40821000, 0x40841800, 0x0000040F, 0x42000002,
    0x0000040F, 0x00A0102D, 0xDFBF0020, 0xDFB00010, 0x03E00008, 0x27BD0030, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000055, 0x80075038, 0x00000056, 0x800750C8, 0x00000057, 0x80075108, 0x00000058, 0x80075158,
    0x00000059, 0x800751A8, 0x00000003, 0x80075330,
};
void* D_0046C1C0 = NULL;      /* the TLB handler SetTLBHandler installs */
void* D_0046C1C8[16] = {NULL}; /* the debug handler table, by cause */
int D_0046C208 = 0;
TlbSyscallEntry D_0046C210[8] = {
    {0x5A, func_002608E0},
    {0x5B, (void*)0x80075000},
    {0x54, _kExitTLBHandler},
    {0x55, NULL},
    {0x56, NULL},
    {0x57, NULL},
    {0x58, NULL},
    {0x59, NULL}
};
// TLB entries {PageMask, EntryHi, EntryLo0, EntryLo1}: 13 + 18 + 8, and the table that counts them
unsigned int D_0046C250[13][4] = {
    {0x00000000, 0x70000000, 0x80000007, 0x00000007},
    {0x00006000, 0xFFFF8000, 0x00001E1F, 0x00001F1F},
    {0x00000000, 0x10000000, 0x00400017, 0x00400053},
    {0x00000000, 0x10002000, 0x00400097, 0x004000D7},
    {0x00000000, 0x10004000, 0x00400117, 0x00400157},
    {0x00000000, 0x10006000, 0x00400197, 0x004001D7},
    {0x00000000, 0x10008000, 0x00400217, 0x00400257},
    {0x00000000, 0x1000A000, 0x00400297, 0x004002D7},
    {0x00000000, 0x1000C000, 0x00400313, 0x00400357},
    {0x00000000, 0x1000E000, 0x00400397, 0x004003D7},
    {0x0001E000, 0x11000000, 0x00440017, 0x00440415},
    {0x0001E000, 0x12000000, 0x00480017, 0x00480415},
    {0x01FFE000, 0x1E000000, 0x00780017, 0x007C0017},
};
unsigned int D_0046C320[18][4] = {
    {0x0007E000, 0x00080000, 0x0000201F, 0x0000301F},
    {0x0007E000, 0x00100000, 0x0000401F, 0x0000501F},
    {0x0007E000, 0x00180000, 0x0000601F, 0x0000701F},
    {0x001FE000, 0x00200000, 0x0000801F, 0x0000C01F},
    {0x001FE000, 0x00400000, 0x0001001F, 0x0001401F},
    {0x001FE000, 0x00600000, 0x0001801F, 0x0001C01F},
    {0x007FE000, 0x00800000, 0x0002001F, 0x0003001F},
    {0x007FE000, 0x01000000, 0x0004001F, 0x0005001F},
    {0x007FE000, 0x01800000, 0x0006001F, 0x0007001F},
    {0x0007E000, 0x20080000, 0x00002017, 0x00003017},
    {0x0007E000, 0x20100000, 0x00004017, 0x00005017},
    {0x0007E000, 0x20180000, 0x00006017, 0x00007017},
    {0x001FE000, 0x20200000, 0x00008017, 0x0000C017},
    {0x001FE000, 0x20400000, 0x00010017, 0x00014017},
    {0x001FE000, 0x20600000, 0x00018017, 0x0001C017},
    {0x007FE000, 0x20800000, 0x00020017, 0x00030017},
    {0x007FE000, 0x21000000, 0x00040017, 0x00050017},
    {0x007FE000, 0x21800000, 0x00060017, 0x00070017},
};
unsigned int D_0046C440[8][4] = {
    {0x0007E000, 0x30100000, 0x0000403F, 0x0000503F},
    {0x0007E000, 0x30180000, 0x0000603F, 0x0000703F},
    {0x001FE000, 0x30200000, 0x0000803F, 0x0000C03F},
    {0x001FE000, 0x30400000, 0x0001003F, 0x0001403F},
    {0x001FE000, 0x30600000, 0x0001803F, 0x0001C03F},
    {0x007FE000, 0x30800000, 0x0002003F, 0x0003003F},
    {0x007FE000, 0x31000000, 0x0004003F, 0x0005003F},
    {0x007FE000, 0x31800000, 0x0006003F, 0x0007003F},
};
void* D_0046C4C0[7] = {(void*)0xD, (void*)0x12, (void*)0x8, NULL, D_0046C250, D_0046C320, D_0046C440};
void* D_0046C4DC = D_00494038;
int D_0046C4E0[4] = {0};
#else
extern TlbSyscallEntry D_0046C210[8];
extern int D_0046C208;
extern char fm_D_0046BE90[];
#endif
int func_00260918();
void func_00260928();
void func_002608D0();
void FlushCache(int);

void InitTLBFunctions(void)
{
    unsigned int i;

    func_00260928(D_0046C210[0].no, D_0046C210[0].fn);
    func_002608D0((void *)0x80075000, fm_D_0046BE90, 0x330);
    FlushCache(0);
    FlushCache(2);
    func_00260928(D_0046C210[1].no, D_0046C210[1].fn);
    func_00260928(D_0046C210[2].no, D_0046C210[2].fn);
    for (i = 3; i < 8; i++) {
        func_00260928(D_0046C210[i].no, (void *)func_00260918(D_0046C210[i].no));
    }
    D_0046C208 = func_00260918(3);
}

SYSCALL_STUB(int, PutTLBEntry, 0x55)

SYSCALL_STUB(int, func_00260A10, -0x55)

SYSCALL_STUB(int, func_00260A20, 0x56)

int func_00260A20();

int _SetTLBEntry(int idx)
{
    if ((unsigned int)(idx - 13) >= 35) {
        return -1;
    }
    return func_00260A20(idx);
}

SYSCALL_STUB(int, iSetTLBEntry, -0x56)

SYSCALL_STUB(int, func_00260A70, 0x57)

SYSCALL_STUB(int, iGetTLBEntry, -0x57)

SYSCALL_STUB(int, ProbeTLBEntry, 0x58)

SYSCALL_STUB(int, func_00260AA0, -0x58)

SYSCALL_STUB(int, func_00260AB0, 0x59)

int GetMemorySize(void);
int InitTLB32MB(void);
int InitTLB(void);

int func_00260AC0(void)
{
    if (GetMemorySize() == 0x2000000) {
        return InitTLB32MB();
    }
    return InitTLB();
}

INCLUDE_ASM("asm/nonmatchings/lib/libkernl/tlbfunc", InitTLB32MB);

INCLUDE_ASM("asm/nonmatchings/lib/libkernl/tlbfunc", _kTLBException);
