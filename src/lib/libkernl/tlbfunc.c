// Library code (Final Mix). One function at a time: replace an INCLUDE_ASM line with matching C.
// Data this file owns is still in the data segments: declare it extern here, do not define it.
#include "common.h"

/* the kernel syscall stubs: `addiu $3,$0,NUM; syscall 0; jr $31; nop` */
#define SYSCALL_STUB(T, name, num)                                                                  \
    T name()                                                                                       \
    {                                                                                              \
        __asm__ __volatile__("addiu $3, $0, " #num "\n\tsyscall 0");                               \
    }

extern void *D_0046C1C0;      /* the TLB handler SetTLBHandler installs */
extern void *D_0046C1C8[];    /* the debug handler table, by cause */
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

extern TlbSyscallEntry D_0046C210[8];
extern int D_0046C208;
extern char fm_D_0046BE90[];
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
