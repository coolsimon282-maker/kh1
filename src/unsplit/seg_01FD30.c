// Placeholder for code that hasn't been assigned to a source file yet (Final Mix offset 0x01FD30).
// Functions can be matched here like in any other file; the file may be split later.
#include "common.h"

extern s32 D_004F2A00[];
void _sceSifLoadStartModule(s32, s32, s32, s32);
s32 func_00120930(void);

s32* func_0011FD30(void) {
    return D_004F2A00;
}

void func_001220D0(void);

void func_0011FD40(void) {
    func_001220D0();
    func_001102C0();
}

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_01FD30", func_0011FD60);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_01FD30", func_0011FE20);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_01FD30", func_0011FEC0);

typedef struct {
    u32 flags;
    u8 pad[0x2C];
    s32 unk_30;
    s32 unk_34;
} A2Slot;
extern A2Slot D_004F3230[];
extern s32 D_002C5C44;

A2Slot* func_0011FFD0(void) {
    A2Slot* p = D_004F3230;
    s32 i;

    for (i = 0; i < 16; i++, p++) {
        if (!(p->flags & 1)) {
            p->flags |= 1;
            p->unk_34 = D_002C5C44++;
            p->unk_30 = -1;
            return p;
        }
    }
    return NULL;
}

void func_00120038(s32* arg0) {
    *arg0 = 0;
}

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_01FD30", func_00120040);

u32 strlen(const char*);

s32 func_001200F8(s32 arg) {
    char* s = (char*)arg;
    s32 len = strlen(s);
    s32 i;
    s32 h = 0;

    for (i = 0; i < len; i++) {
        h = (h << 1) ^ ((s[i] << 16) % 0x11021);
    }
    return h;
}

s32 func_00120170(u32 arg0, u32* arg1) {
    u32 b = *arg1;

    if (arg0 < b) {
        return -1;
    }
    return arg0 > b;
}

extern s32 D_002C5C30;
extern u8 D_004E4A00[];
s32 func_001200F8(s32);
void* bsearch(const void*, const void*, u32, u32, s32 (*)(const void*, const void*));

void* func_00120190(s32 a0) {
    return bsearch((void*)func_001200F8(a0), D_004E4A00, D_002C5C30, 0x10, (void*)func_00120170);
}

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_01FD30", func_001201D0);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_01FD30", func_001202C0);

s32 sceCdDiskReady(s32);
s32 func_00269DA8(void*, void*);

void fm_func_00120438(void* a, void* b) {
    while (sceCdDiskReady(1) != 2 || func_00269DA8(a, b) == 0) {
        func_0011FD40();
    }
}

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_01FD30", func_001204A0);

extern s32 D_002C5C48;
void func_0011FD60(s32, s32, void*);
void FlushCache(int);

s32 func_00120580(void* name, void* dst) {
    u32 info[12];

    fm_func_00120438(info, name);
    func_0011FD60(info[0], (info[1] + 0x7FF) >> 11, dst);
    D_002C5C48 = info[1];
    FlushCache(0);
    FlushCache(2);
    return D_002C5C48;
}

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_01FD30", func_00120438);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_01FD30", func_00120678);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_01FD30", func_00120590);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_01FD30", func_001207F8);

s32 sceCdDiskReady(s32);
s32 sceCdSeek(u32);

void func_00120888(s32 a0) {
    u8* p;

    if (sceCdDiskReady(1) == 2) {
        p = func_00120190(a0);
        if (p != NULL) {
            sceCdSeek(*(u32*)(p + 8));
        }
    }
}

void* func_0011EEB8(void*, s32, s32);
s32 func_0011EF58(s32*, s32);
extern s32 D_004E49E8;

void* func_001208E0(s32 arg0) {
    return func_0011EEB8(&D_004E49E8, 0, arg0);
}

s32 func_00120908(void) {
    func_0011EF58(&D_004E49E8, 0);
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_01FD30", func_00120930);

s32 sceSifLoadModule(const char*, s32, const char*);

void func_001209D8(void) {
    s32 m = func_00120930();

    while (sceSifLoadModule((const char*)m, 0, 0) < 0) {
    }
}

void func_00120A20(s32 a0, s32 a1, s32 a2, s32 a3) {
    s32 t0 = func_00120930();
    _sceSifLoadStartModule(t0, a1, a2, a3);
}

void func_001208B8(void) {
    ((s16*)func_0011ED30(0x2D2A8, func_00120908))[1] = -1;
}

extern u8 D_004E4528[];
extern s32 D_004E4520;

void func_00120AA0(void) {
    s32 i;

    func_0011EDD0(&D_004E49E8, D_004E4528, 0x4C, 0x10);
    D_004E4520 = 0;
    for (i = 0; i < 16; i++) {
        func_00120038((s32*)&D_004F3230[i]);
    }
}

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_01FD30", func_00120B10);

extern s32 D_004F3208;
extern u8 D_0048D2A0[];
s32 sceCdSync(s32);
void fm_func_00120438(void*, void*);
void func_0011FD60(s32, s32, void*);
void func_0011FE20(void);

void func_00120BA0(void) {
    sceCdDiskReady(0);
    fm_func_00120438(&D_004F3208, D_0048D2A0);
    func_0011FD60(D_004F3208, 1, D_004F2A00);
    sceCdSync(0);
    func_0011FE20();
}
