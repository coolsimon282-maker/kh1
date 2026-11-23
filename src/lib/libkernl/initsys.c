#ifdef VERSION_FM
// Final Mix links a newer build of this library file: its functions are matched one by one below.
#include "common.h"

#include "eekernel.h"

#define SYSCALL(id) __asm__ volatile("li $3,"#id"\n syscall")

typedef struct {
    s32 num;
    void* func;
} _sysEntry;

/* initsys.o's data (still in the data segments) */
extern _sysEntry D_0046AF00[2]; /* SysEntry: {0x5A, func_0025F3F0}, {0x83, func_0025F428} */
extern s32* D_0046AEF8;         /* _SyscallEntry */
extern s32 __sce_sema_id;
extern s32 __sce_eh_sema_id;

void InitAlarm(void);
void InitExecPS2(void);
u32* func_0025F428(u32* addr, u32* end, u32 value);
s32 func_0025F3F0(u32* dst, u32* src, u32 size);
u32 FindAddress(void* start, void* end, void* value);
void func_0025F5B0(s32 n, void* f);

void supplement_crt0(void) {
    struct SemaParam libc_sema;
    struct SemaParam eh_sema;

    libc_sema.maxCount = 0x1;
    libc_sema.initCount = 0x1;
    eh_sema.maxCount = 0x1;
    eh_sema.initCount = 0x1;
    __sce_sema_id = CreateSema(&libc_sema);
    __sce_eh_sema_id = CreateSema(&eh_sema);
    return;
}

void func_0025F3E0(void* dst, void* src, s32 size) {
    SYSCALL(0x5A);
}

s32 func_0025F3F0(u32* dst, u32* src, u32 size) {
    u32 i;

    size >>= 2;
    for (i = 0; i < size; i++) {
        *dst++ = *src++;
    }
    return 0;
}

u32* func_0025F428(u32* addr, u32* end, u32 value) {
    while (*addr != value && addr < end) {
        addr++;
    }
    if (addr >= end) {
        addr = 0;
    }
    return addr;
}

u32 FindAddress(void* start, void* end, void* value) {
    SYSCALL(0x83);
}

s32 func_0025F478(s32 n) {
    s32 v;

    func_0025F3E0(&v, D_0046AEF8 + n, 4);
    return v;
}

void func_0025F4B0(void) {
    u32 a;
    u32 b;
    u32 ta;
    u32 tb;

    func_0025F5B0(D_0046AF00[0].num, D_0046AF00[0].func);
    func_0025F5B0(D_0046AF00[1].num, D_0046AF00[1].func);
    a = FindAddress((void*)0x80000000, (void*)0x80080000, func_0025F428);
    b = FindAddress((void*)0x80000000, (void*)0x80080000, func_0025F3F0);
    ta = a - 0x20C;
    tb = b - 0x168;
    while (ta != tb) {
        if (ta < tb) {
            a = FindAddress((void*)(a + 4), (void*)0x80080000, func_0025F428);
            ta = a - 0x20C;
        } else {
            b = FindAddress((void*)(b + 4), (void*)0x80080000, func_0025F3F0);
            tb = b - 0x168;
        }
    }
    D_0046AEF8 = (s32*)ta;
}

void func_0025F5B0(s32 n, void* f) {
    SYSCALL(0x74);
}

void _InitSys(void) {
    supplement_crt0();
    func_0025F4B0();
    InitAlarm();
    InitThread();
    InitExecPS2();
    InitTLBFunctions();
}

#else
#include "common.h"
#include "eekernel.h"

#define KSEG0 0x80000000
#define SYSCALL(id) __asm__ volatile("li $3,"#id"\n syscall")

typedef struct {
    s32 num;
    void* func;
} _sysEntry;
static s32* kFindAddress(s32 value);
static void setup(s32 n, void (*f)());

_sysEntry SysEntry = {.num = 0x83, .func = &kFindAddress};
s32 _pad = 0;
s32 __sce_sema_id = 0;
s32 __sce_eh_sema_id = 0;
s32* _SyscallEntry = 0;

static void supplement_crt0(void) {
    struct SemaParam libc_sema;
    struct SemaParam eh_sema;
    
    libc_sema.maxCount = 0x1;
    libc_sema.initCount = 0x1;
    eh_sema.maxCount = 0x1;
    eh_sema.initCount = 0x1;
    __sce_sema_id = CreateSema(&libc_sema);
    __sce_eh_sema_id = CreateSema(&eh_sema);
    return;
}

static s32* kFindAddress(s32 value) {
    s32* addr;
    
    addr = (s32*)KSEG0;
    while (*addr != value) {
        addr++;
    }
    return addr;
}

static u32 FindAddress(void* value) {
    SYSCALL(0x83);
}

static s32 GetSystemCallTableEntry(void) {
    u32 addr;
    
    setup(SysEntry.num, SysEntry.func);
    addr = FindAddress(&kFindAddress);
    return addr - 0x20C;
}

static void setup(s32 n, void (*f)()) {
    SYSCALL(0x74);
}

static s32* _setup(s32 n) {
    SYSCALL(0x74);
    return _SyscallEntry + n;
}

void _InitSys(void) {
    supplement_crt0();
    GetSystemCallTableEntry();
    InitAlarm();
    InitThread();
    InitExecPS2();
    InitTLBFunctions();
}
#endif
