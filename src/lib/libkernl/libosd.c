// Library code (Final Mix). One function at a time: replace an INCLUDE_ASM line with matching C.
// Data this file owns is still in the data segments: declare it extern here, do not define it.
#include "common.h"

#define SYSCALL(id) __asm__ volatile("li $3,"#id"\n syscall")

typedef struct {
    int num;
    void* func;
} OsdSysEntry;

typedef struct {
    u32 spdifMode : 1;
    u32 screenType : 2;
    u32 videoOutput : 1;
    u32 japLanguage : 1;
    u32 ps1drvConfig : 8;
    u32 version : 3;
    u32 language : 5;
    u32 timezoneOffset : 11;
} OsdConfigParam;

/* libosd.o's data (still in the data segments) */
extern OsdSysEntry D_0046B6C0[3]; /* InitExecPS2's syscall entries */
extern char D_0046AF18[];         /* the kernel patch InitExecPS2 copies to 0x80074000 (0x7A8 bytes) */
extern OsdSysEntry D_0046B6D8;    /* the byte-copy helper for syscall 0x5A */
extern char** D_0046C208;         /* the kernel's argument area */
extern char D_00492380[];         /* the program name passed with the arguments */

void GetOsdConfigParam(OsdConfigParam* p);
void SetOsdConfigParam(OsdConfigParam* p);
void FlushCache(int op);
int strlen(const char* s);
void func_00260AC0(void);
int ExecPS2(void* entry, void* gp, int argc, char** argv);
void LoadExecPS2(const char* name, int argc, char** argv);
void ExecOSD(int argc, char** argv);
void Exit(int n);
char* func_0025F7D0(const char* name, int argc, char** argv);

void func_0025F600(int n, void* f) {
    SYSCALL(0x74);
}

void func_0025F610(void* dst, void* src, int size) {
    SYSCALL(0x5A);
}

int func_0025F620(u32* dst, u32* src, u32 size) {
    u32 i;

    size >>= 2;
    for (i = 0; i < size; i++) {
        *dst++ = *src++;
    }
    return 0;
}

void* func_0025F658(int n) {
    SYSCALL(0x5B);
}

int PatchIsNeeded(void) {
    OsdConfigParam old;
    OsdConfigParam p;

    GetOsdConfigParam(&old);
    p = old;
    p.version = 1;
    SetOsdConfigParam(&p);
    GetOsdConfigParam(&p);
    SetOsdConfigParam(&old);
    return p.version == 0;
}

void InitExecPS2(void) {
    u32 i;

    if (PatchIsNeeded()) {
        func_0025F600(D_0046B6C0[0].num, D_0046B6C0[0].func);
        func_0025F610((void*)0x80074000, D_0046AF18, 0x7A8);
        FlushCache(0);
        FlushCache(2);
        func_0025F600(D_0046B6C0[1].num, D_0046B6C0[1].func);
        for (i = 2; i < 3; i++) {
            func_0025F600(D_0046B6C0[i].num, func_0025F658(D_0046B6C0[i].num));
        }
    }
}

void func_0025F780(void* dst, void* src, int size) {
    SYSCALL(0x5A);
}

int func_0025F790(u8* dst, u8* src, u32 size) {
    u32 i;

    for (i = 0; i < size; i++) {
        *dst++ = *src++;
    }
    return 0;
}

void func_0025F7C0(int n, void* f) {
    SYSCALL(0x74);
}

INCLUDE_ASM("asm/nonmatchings/lib/libkernl/libosd", func_0025F7D0);

void TerminateLibrary(void) {
    func_00260AC0();
}

/* returns a wider type than ExecPS2's int: that is what keeps the call a jal, not a tail jump */
long func_0025F8F0(void* entry, void* gp, int argc, char** argv) {
    func_0025F7D0(D_00492380, argc, argv);
    TerminateLibrary();
    return ExecPS2(entry, gp, argc, D_0046C208 + 1);
}

void func_0025F960(const char* name, int argc, char** argv) {
    char* r = func_0025F7D0(name, argc, argv);
    TerminateLibrary();
    LoadExecPS2(r, argc, D_0046C208 + 1);
}

void func_0025F9A8(int n) {
    TerminateLibrary();
    Exit(n);
}

void func_0025F9D0(int argc, char** argv) {
    func_0025F7D0(D_00492380, argc, argv);
    TerminateLibrary();
    ExecOSD(argc, D_0046C208 + 1);
}
