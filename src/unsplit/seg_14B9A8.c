// Placeholder for code that hasn't been assigned to a source file yet (Final Mix offset 0x14B9A8).
// Functions can be matched here like in any other file; the file may be split later.
#include "common.h"

extern s32 D_0046A058[];
extern u8 D_004919B0[];
extern u8 D_004919E8[];
extern s32 D_0066AA84;
extern s32 _impure_ptr;
void abort(void);
void fiprintf(s32, u8 *, s32, s32, s32);
void func_00149E38(s32, u8 *);
void func_0024F008();
s32 sceCdGetError(void);
void sceDevctl(u8 *, s32, s32, s32, s32, s32);

s32 func_0024B9A8(s32 i) {
    return D_0046A058[i];
}

extern s32 D_00669A38;

s32 func_0024B9C0(void) {
    return D_00669A38;
}

extern s32 D_00669A3C;

s32 func_0024B9D0(void) {
    return D_00669A3C;
}

void func_0024B9E0(s32 x) {
    D_00669A38 = x;
}

void func_0024B9F0(s32 x) {
    D_00669A3C = x;
}

void func_0024BA00(s32 a0) {
    s32 t0;
    D_00669A38 = a0;
    t0 = sceCdGetError();
    D_00669A3C = t0;
}

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_14B9A8", func_0024BA28);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_14B9A8", func_0024BB88);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_14B9A8", func_0024BBC8);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_14B9A8", func_0024BC08);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_14B9A8", func_0024BC68);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_14B9A8", func_0024BCE8);

extern u32 D_002C5AD8;

u32 func_0024BE58(void) {
    u32 x = D_002C5AD8;
    return x | ((x >> 24) & 0xF0);
}

extern u32 D_002C5AE0;

u32 func_0024BE70(void) {
    u32 x = D_002C5AE0;
    return x | ((x >> 24) & 0xF0);
}

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_14B9A8", func_0024BE88);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_14B9A8", func_0024C460);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_14B9A8", func_0024C8B8);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_14B9A8", func_0024C950);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_14B9A8", func_0024CDE8);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_14B9A8", func_0024CE80);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_14B9A8", func_0024CF00);

extern s32 D_0046A5D8;

s32 func_0024CF80(void) {
    return D_0046A5D8;
}

extern s32 D_00669A7C;

s32 func_0024CF90(void) {
    return D_00669A7C;
}

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_14B9A8", func_0024CFA0);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_14B9A8", func_0024D138);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_14B9A8", func_0024D1C8);

extern s32 D_0046A55C;

s32 func_0024D408(void) {
    return D_0046A55C;
}

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_14B9A8", func_0024D418);

extern s32 D_0046A53C;

s32 func_0024A000(void) {
    return D_0046A53C;
}

extern s32 D_0046A60C;

s32 func_0024D4A0(void) {
    return D_0046A60C;
}

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_14B9A8", func_0024D4B0);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_14B9A8", func_0024D5D0);

extern s32 D_0046A618;

s32 func_0024D608(void) {
    return D_0046A618;
}

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_14B9A8", func_0024D618);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_14B9A8", func_0024D808);

extern u8 D_0046A620[];

void *func_0024D8A0(void) {
    return D_0046A620;
}

extern u8 D_0046A628[];

void *func_0024D8B0(void) {
    return D_0046A628;
}

extern u8 D_0046A640[];

void *func_0024D8C0(void) {
    return D_0046A640;
}

extern u8 D_0046A650[];

void *func_0024D8D0(void) {
    return D_0046A650;
}

extern u8 D_0046A660[];

void *func_0024D8E0(void) {
    return D_0046A660;
}

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_14B9A8", func_0024D8F0);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_14B9A8", func_0024D9A0);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_14B9A8", func_0024D9F0);

void func_0024DAA0(void) {
    sceDevctl(D_004919B0, 0x4807, 0, 0, 0, 0);
}

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_14B9A8", func_0024DAD0);

extern s32 D_0046A674;

s32 func_0024DB68(void) {
    return D_0046A674;
}

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_14B9A8", func_0024DB78);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_14B9A8", func_0024DCC8);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_14B9A8", func_0024DD98);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_14B9A8", func_0024DDF8);

extern s32 D_0046A67C;

s32 func_0024E078(void) {
    return D_0046A67C;
}

void func_0024E088(s32 x) {
    D_0046A67C = x;
}

extern s32 D_0046A680;

s32 func_0024E098(void) {
    return D_0046A680;
}

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_14B9A8", func_0024E0A4);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_14B9A8", func_0024E0E4);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_14B9A8", func_0024AB00);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_14B9A8", func_0024E18C);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_14B9A8", func_0024E1D0);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_14B9A8", func_0024E640);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_14B9A8", func_0024E678);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_14B9A8", func_0024E6E0);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_14B9A8", func_0024E6E8);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_14B9A8", func_0024E75C);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_14B9A8", func_0024E8D4);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_14B9A8", func_0024EA4C);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_14B9A8", func_0024EBF8);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_14B9A8", func_0024EC1C);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_14B9A8", func_0024EDC8);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_14B9A8", func_0024EDF0);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_14B9A8", func_0024EF88);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_14B9A8", func_0024F008);

void func_0024F070(void) {
    func_00149E38(*(u16 *)(*(u8 **)&D_0066AA84 + 0x4C), func_0024F008);
}

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_14B9A8", func_0024F098);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_14B9A8", func_0024F1D0);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_14B9A8", func_0024F210);

void __assert(s32 a0, s32 a1, s32 a2) {
    fiprintf(*(s32 *)(*(u8 **)&_impure_ptr + 0xC), D_004919E8, a2, a0, a1);
    abort();
}
