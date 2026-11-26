// Placeholder for code that hasn't been assigned to a source file yet (Final Mix offset 0x132D60).
// Functions can be matched here like in any other file; the file may be split later.
#include "common.h"

#include "sdk/ee/eetypes.h"

extern u_long128 D_003F2080;
extern u_long128 D_0040EF80;

void func_0022F808(void) {
    u_long128 *src = &D_003F2080;
    u_long128 *dst = &D_0040EF80;
    s32 count = 0x16C0;
    do {
        *dst = *src;
        src++;
        dst++;
        count--;
    } while (count > 0);
}

#include "sdk/ee/eetypes.h"

extern u_long128 D_0040EF80;
extern u_long128 D_003F2080;

void func_00232DA0(void) {
    u_long128 *src = &D_0040EF80;
    u_long128 *dst = &D_003F2080;
    s32 count = 0x16C0;
    do {
        *dst = *src;
        src++;
        dst++;
        count--;
    } while (count > 0);
}

extern struct {
    s32 unk0;
    s32 unk4;
} D_00425B80;

void func_0022F888(void) {
    D_00425B80.unk0 = 0x5153484B;
    D_00425B80.unk4 = 0x01317F14;
}

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_00232E08);

extern u8 D_003F8298[];
u8* func_00232F88(u32 a0) {
    D_003F8298[0xD] = a0 / 10 + '0';
    D_003F8298[0xE] = a0 % 10 + '0';
    return D_003F8298;
}

extern u8 D_003F82A8[];

u8 *func_00232FC8(u32 arg0) {
    D_003F82A8[0xE] = (arg0 / 10) + 0x30;
    D_003F82A8[0xF] = (arg0 % 10) + 0x30;
    D_003F82A8[0x1E] = (arg0 / 10) + 0x30;
    D_003F82A8[0x1F] = (arg0 % 10) + 0x30;
    return &D_003F82A8;
}

extern u8 D_003F82D0[];

u8 *func_00233018(u32 arg0) {
    D_003F82D0[0xE] = (arg0 / 10) + 0x30;
    D_003F82D0[0xF] = (arg0 % 10) + 0x30;
    return &D_003F82D0;
}

extern u8 D_003F82F0[];

u8 *func_00233058(u32 arg0) {
    D_003F82F0[0xE] = (arg0 / 10) + 0x30;
    D_003F82F0[0xF] = (arg0 % 10) + 0x30;
    return &D_003F82F0;
}

extern u8 D_003F8310[];

u8 *func_00233098(u32 arg0) {
    D_003F8310[0xE] = (arg0 / 10) + 0x30;
    D_003F8310[0xF] = (arg0 % 10) + 0x30;
    return &D_003F8310;
}

extern u8 D_003F8330[];

u8 *func_002330D8(u32 arg0) {
    D_003F8330[0xE] = (arg0 / 10) + 0x30;
    D_003F8330[0xF] = (arg0 % 10) + 0x30;
    return &D_003F8330;
}

extern u8 D_003F8350[];

u8 *func_00233118(u32 arg0) {
    D_003F8350[0xE] = (arg0 / 10) + 0x30;
    D_003F8350[0xF] = (arg0 % 10) + 0x30;
    return &D_003F8350;
}

extern s32 D_00351E10;

void func_00233158(void) {
    D_00351E10 = 0;
}

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_00233168);

extern s32 D_00425BC0[];
extern void func_F20000(s32, s32);

void func_002335D8(s32 arg0) {
    func_00120438((const char *)D_00425BC0[arg0], (void *)func_F20000);
    func_F20000(0, 0);
}

extern u8 D_002C5AD0[];
extern s32 D_00425BC8;
extern s32 D_00647780;
extern s32 D_0064778C;
extern s32 D_00647798;
extern void func_002336D8(void);

void func_00233610(void) {
    D_00425BC8 = (s32)&D_002C5AD0;
    D_00647780 = 0;
    D_0064778C = 0;
    D_00647798 = 0;
    func_002336D8();
}

extern s32 D_00647780;
extern s32 D_00647784;
extern s32 D_00647788;
void func_00233650(s32 arg0, s32 arg1) {
    D_00647780 = 1;
    D_00647784 = arg0;
    D_00647788 = arg1;
}

extern s32 D_00647780;

void func_00233670(void) {
    D_00647780 = 0;
}

extern s32 D_0064778C;
extern s32 D_00647790;
extern s32 D_00647794;
void func_00233680(s32 arg0, s32 arg1) {
    D_0064778C = 1;
    D_00647790 = arg0;
    D_00647794 = arg1;
}

extern s32 D_0064778C;

void func_002336A0(void) {
    D_0064778C = 0;
}

extern s32 D_00647798;
extern s32 D_0064779C;

void func_002336B0(s32 arg0) {
    D_00647798 = 1;
    D_0064779C = arg0;
}

extern s32 D_00647798;

void func_002336C8(void) {
    D_00647798 = 0;
}

extern f32 D_006477A4;

void func_002336D8(void) {
    D_006477A4 = 0;
}

f32 func_002336E8(void) {
    return D_006477A4;
}

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_002336F8);
