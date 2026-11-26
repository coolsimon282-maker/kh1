/**
 * System font text, probably: loads menu/sysfont.bin into GS memory (glyphs and CLUT), keeps the current text
 * position / colour / size state, and wraps the string measuring and drawing routines with the two font sizes 14 and
 * 18. The draw functions return the width drawn (D_00639A8C). JP/EU: 0x1F0C30-0x1F3990.
 * Final Mix (#ifdef VERSION_FM): 0x1EF950-0x1F3110, up to xmeowp as in JP; functions paired with JP's by address
 * order and size where they correspond.
 */
#include "common.h"

#ifdef VERSION_FM
void func_00211698(void);
extern u8 D_003F3D80[];
extern s32 D_00641BA4;
extern s32 D_00641BA0;
void func_00121EB0(s32);
void func_00162110(s32, u8 *);
s32 func_001F9438_s(void *, s32, s32, s32, s32, s32, s32) __asm__("func_001F9438");
s32 func_001EF960(s32);
u8 *func_001F1868_x(u8 *, s32, s32, s32, s32, s32, s32) __asm__("func_001F1868");
u8 *func_001F15F0_x(u8 *, s32, s32, s32, s32, s32, s32) __asm__("func_001F15F0");
void func_001FB248(s32, s32, s32, s32, s32, s32);
void func_001FA8B0(s32, s32, s32, s32, s32, s32);
extern u8 D_003F2270[];
extern s32 D_0063F74C;
u8 *func_001F12C0(u8 *, s32, s32, s32, s32, s32, s32);
void func_001220B8(u8 *);
u8 *func_00122048(s32, s32);
s32 sceGsSyncPath(s32, u16);
void func_002083A8(s32, s32, s32, s32, s32, s32);
s32 func_001EF9E0(s32);
void func_00201C60(s32, s32, s32, s32);
void func_00201988(s32, s32, s32, s32);
void func_002016B0(s32, s32, s32, s32);
void func_0020BD18(s32, s32);
/* func_001F3708 as a definition in this file changes the callers' branch-likely choice: call it via an alias */
s32 func_001F3708_x(s32, s32) __asm__("func_001F3708");
void func_0020AB88(s32);
void func_0020A9B0(s32);
void func_0020B120(s32, s32, s32, s32, s32, s32);
extern u8 *D_00425BC8;
extern u8 D_003F33A8[];
void func_0020CCB0(s32);
void func_00205E30(s32, u8 *);
u8 *func_001F0BD8(s32);
extern s32 D_003F3E18[];
void func_0020FBE0(void);
void func_0020F3C8(void);
void func_0020EB98(void);
extern s32 D_00641224;
extern s32 D_00641220;
extern u8 D_003F3AB0[];
extern s32 D_003F3258[];
extern s32 D_00640E00[];
extern s32 D_00640E20;
void func_00142000(void);
void func_0020A1D8(void);
extern s32 D_002BC140;
extern s32 D_002BC144;
extern s32 D_00640E30;
extern s32 D_00640E2C;
extern s32 D_003F34A4;
extern s32 D_003F6E30;
extern s32 D_00641274;
extern s32 D_00641270;
extern s32 D_0064126C;
extern s32 D_00641268;
extern s32 D_00641264;
extern s32 D_00641260;
extern s32 D_0064125C;
extern s32 D_00641258;
extern s32 D_003E8E08;
void func_00214B20(u8 *);
void func_00214FC8(u8 *);
extern s32 D_003F34C0;
extern u8 D_003F3B40[];
void func_0020FC58(u8 *);
void func_0020F530(u8 *);
void func_0020EC50(u8 *);
s32 func_001FD538(u8 *a0);
void func_001FD5E0(u8 *, s32);
void func_001FD660(u8 *a0, s32 a1);
void func_001FD610(u8 *a0, s32 a1);
void func_001F86E0(void *, s32, s32, s32, s32);
void func_001EFAF0(void);
void func_001EFB98(s32);
void func_001EFB78(s32);
void func_001EFB58(s32);
extern s32 D_003E8E2C;
extern u8 D_003E4658[];
extern s32 D_0064120C;
extern s32 D_00641208;
extern s32 D_00641204;
extern s32 D_00641200;
void func_00207980(s32, s32, s32, s32, s32, s32, s32, s32, s32);
void func_00207938(s32, s32, s32, s32, s32, s32, s32, s32, s32);
void func_002078F0(s32, s32, s32, s32, s32, s32, s32, s32, s32);

typedef struct {
    u8 pad[0xB8];
    s16 b8lo : 5;
    s16 b8 : 11;
    u8 pad2[4];
    s16 belo : 4;
    s16 be : 12;
    s16 c0lo : 4;
    s16 c0 : 12;
    u8 pad3[2];
    s16 c4lo : 4;
    s16 c4 : 12;
    u8 pad4[0xA];
    u16 d0lo : 4;
} SObj;

typedef struct {
    s16 lo : 4;
    s16 v : 12;
} SBf;
#define LN(p, o) (*(u8 **)((p) + (o)))
#define BF(p, o) (((SBf *)((u8 *)(p) + (o)))->v)

void func_00201600(s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
void func_00201550(s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
void func_002014A0(s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern u8 D_003F3530[];
s32 func_00206370(s32, s32, s32, s32, s32, s32, s32, s32, s32);
void func_00202678(void *, s32, s32);
void func_001F5FE0();
extern f32 D_002B8344;
extern s32 D_003F2F10[];
void func_00203028(u8 *, s32, s32, s32, s32);
extern s32 D_003E9630[];
s32 func_001FC330(s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
void func_00203A10(void *, s32);
s32 func_001FBCD8(s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern u16 D_003E890E[];
extern u8 D_003E8910[];
extern u8 D_003E5ED8[];
extern u8 D_003F3420[];
extern u8 D_003F2C50[];
s32 func_001FB428(s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern s32 D_003E8E28;

extern s32 D_003DE6A0;
extern s32 D_003E8E00;
extern s32 D_003E8E04;
extern u8 D_003E8E30[];
extern u8 D_003E9660[];
extern s32 D_003ED718;
extern u8 D_003ED728[];
extern u8 D_003F1660[];
extern s32 D_003F1A60;
extern s32 D_003F1A64;
extern s32 D_003F1A68;
extern u8 D_003F2670[];
extern u8 D_003F2720[];
extern u8 D_003F2C40[];
extern s32 D_0063F740;
extern s32 D_0063F744;
extern s32 D_0063F748;
extern u8 D_0063F758[];
extern s32 D_00640DD8;
extern s32 D_00640DDC;
extern s32 D_00640DE0;
extern s32 D_00640E24;
extern s32 D_00640E28;
extern s32 D_006411E0;
extern s32 D_006411FC;
extern s32 D_00641210;
extern s32 D_00641214;
extern s32 D_00641218;
extern s32 D_00641250;
extern s32 D_00641BC4;
extern s32 D_00641BC8;
extern s32 D_00641BCC;
extern s32 D_00641BD0;
extern s32 D_00641BD4;
extern s32 D_00641BD8;
extern s32 D_00641BDC;
extern s32 D_00641C04;
extern s32 D_00641C08;
extern s32 D_00642C58;
extern s32 D_00642C5C;
extern s32 D_00642C60;
extern s32 D_00642C64;
extern s32 D_00642C68;
extern s32 D_00642C6C;
extern s32 D_00642C70;
void func_0011D598(s32);
s32 func_001EBEA8(void);
s32 func_001EFAE8(void);
s32 func_001EFBB8();
s32 func_001EFC68();
void func_001EFD20(s32, s32);
s32 func_001EFD98();
s32 func_001EFDB8();
void func_001EFEE8(s32);
s32 func_001EFF50(s32);
void func_001EFFC0(s32);
void func_001F0118(s32, s32);
void func_001F0148(s32, s32);
void func_001F0340(s32, s32);
void func_001F07D8(s32, s32, s32, s32, s32, s32, s32, s32);
void func_001F0868(s32, s32, s32, s32, s32, s32, s32, s32);
s32 func_001F08A0(s32);
s32 func_001F08D8(s32);
void func_001F0EA8(s32, s32, s32, s32, s32, s32, s32, s32);
s32 func_001F0EF0();
void func_001F15F0(s32, s32, s32, s32, s32, s32, s32);
void func_001F1F58(s32, s32, s32, s32, s32, s32);
void func_001F1FC8(s32, s32, s32, s32, s32, s32);
void func_001F2630(s32, s32, s32, s32, s32, s32);
s32 func_001F3520(s32, s32);
s32 func_001F3A20(s32, s32);
s32 func_001F4378(s32);
s32 func_001F4390(s32);
s32 func_001F43C8(s32);
s32 func_001F4400(s32);
void func_001F5E10();
void func_001F9010(s32);
void func_001F9078(s32, s32, s32);
void func_001F9098(s32, s32, s32);
void func_001F90B8(s32, s32, s32);
void func_001F9138(s32, s32, s32, s32);
void func_001F9180(s32, s32, s32, s32);
void func_001F91C8(s32, s32, s32, s32);
void func_001F9270(s32, s32, s32, s32, s32, s32);
void func_001F92B0(s32, s32, s32, s32, s32, s32);
void func_001F92F0(s32, s32, s32, s32, s32, s32);
void func_001F9378(s32, s32, s32, s32, s32, s32);
void func_001F9398(s32, s32, s32, s32, s32, s32);
void func_001F93B8(s32, s32, s32, s32, s32, s32);
void func_001F9438(s32, s32, s32, s32, s32, s32, s32);
void func_001F94F0(s32, s32, s32, s32, s32, s32, s32);
void func_001F9E48(s32, s32, s32, s32, s32, s32, s32);
void func_001FA718(s32, s32, s32, s32);
void func_001FA748(s32, s32, s32, s32);
void func_001FA778(s32, s32, s32, s32);
void func_001FA808(s32, s32, s32, s32, s32);
void func_001FA840(s32, s32, s32, s32, s32);
void func_001FA878(s32, s32, s32, s32, s32);
void func_001FADE0(s32, s32, s32, s32, s32, s32);
void func_001FB408(s32, s32, s32, s32, s32, s32, s32, s32);
void func_001FCDC8(s32, s32, s32, s32, s32, s32, s32, s32);
void func_001FD720(s32);
void func_001FD858(void);
void func_001FDFD0(s32);
s32 func_001FE1B8(void);
s32 func_001FE5A0(void);
void func_001FEFF0(s32, s32, s32, s32, s32, s32, s32, s32);
void func_001FF488(u8 *, s32, s32, s32, s32, s32);
void func_00200648(s32, s32, s32, s32, s32, s32);
void func_00206130(s32, s32, s32, s32, s32, s32);
void func_00206E28(void);
void func_00206F20(void);
void func_00206FF0(void);
void func_002070C0(void);
void func_002071B8(void);
void func_00207288(void);
void func_00207358(void);
void func_002073B0(s32, u8 *);
void func_00207598(void);
void func_00207830(s32, s32, s32, s32, s32, s32, s32);
void func_002079C8(s32);
void func_00207A38(s32);
void func_00208458(s32, s32, s32, s32, s32);
void func_00209E18(void);
void func_0020BE10(s32);
void func_0020BE68(s32, s32, s32);
void func_00211398(void);
void func_00213D30(void);
void func_00216140(void);
void func_002178D0(void);
void func_00218A00(void);
void func_0021ADC8(void);
void func_0021DB30(void);
void func_00229850(void);
s32 func_002366D8(s32, s32);
s32 sceDmaGetChan(s32);
s32 sceDmaSend(s32, u8 *);

INCLUDE_ASM("asm/nonmatchings/xbiscuit", func_001EF950);
#else
#include "libdma.h"

extern s32 D_003DEF90;
extern s32 D_003E0810;
extern s32 D_003E2BE0;
extern s32 D_003E3080;
extern s32 D_003E3084;
extern s32* D_003E30A8;
extern s32 D_003E30AC;
extern s32 D_003E38C0;
extern s32 D_003EB8C0;

const char D_0048A590[32] = "menu/sysfont.bin";

extern s32 D_00639A80;
extern s32* D_00639A84;
extern s32* D_00639A88;
extern s32 D_00639A8C;
extern void* D_0063B050;

void func_001F0DF8(s32*, s32*);
void* func_001F1960(s32, s32, s32, s32, s32, s32, s32, s32);
void* func_001F19F0(s32, s32, s32, s32, s32, s32, s32, s32);
void* func_001F1FA8(s32, s32, s32, s32, s32, s32, s32, s32);

void func_001F0C30(void) {
    void* dst;
    u64 stack0[22];
    u64 stack1[22];

    dst = func_00155ED8(0x34, 12);

    func_00120438(D_0048A590, dst);

    GsPacket_LoadImage(0x3FFC, 1, 0, 0, 0, 0x10, 0x10, 0x40, dst + 0x10000, stack1);
    FlushCache(0);
    sceDmaSend(sceDmaGetChan(SCE_DMA_GIF), stack1);
    sceGsSyncPath(0, 0);

    GsPacket_LoadImage(0x1000, 4, 36, 0, 0, 0x100, 0x100, 0x800, dst, stack0);
    FlushCache(0);
    sceDmaSend(sceDmaGetChan(SCE_DMA_GIF), stack0);
    sceGsSyncPath(0, 0);

    GsPacket_LoadImage(0x1000, 4, 44, 0, 0, 0x100, 0x100, 0x800, dst + 0x8000, stack0);
    FlushCache(0);
    sceDmaSend(sceDmaGetChan(SCE_DMA_GIF), stack0);
    sceGsSyncPath(0, 0);
}
#endif

#ifdef VERSION_FM
void fm_func_001EFAA8(void) {
    D_003E8E28 = (s32)D_003E4658;
    D_003E8E2C = 0x310;
    func_001EFB58(0x14);
    func_001EFB78(0);
    func_001EFB98(0);
    func_001EFAF0();
}
#else
// Nonmatch: Assignment instructions out of order
INCLUDE_ASM("asm/nonmatchings/xbiscuit", func_001F0D88);
#endif

#ifdef VERSION_FM
void func_001EFAF0(void) {
    func_001EFB18((s32)D_003E5ED8, (s32)D_003E8910);
}
#else
// void func_001F0D88(void) {
//     D_003E30A8 = &D_003DEF90;
//     D_003E30AC = 0x310;
//     func_001F0E38(20);
//     func_001F0E58(8);
//     func_001F0E58(0);
//     func_001F0DD0();
// }

void func_001F0DD0(void) {
    func_001F0DF8(&D_003E0810, &D_003E2BE0);
}
#endif

#ifdef VERSION_FM
void func_001EFB18(s32 a0, s32 a1) {
    D_0063F744 = a0;
    D_0063F748 = a1;
}
#else
void func_001F0DF8(s32* arg0, s32* arg1) {
    D_00639A84 = arg0;
    D_00639A88 = arg1;
}
#endif

#ifdef VERSION_FM
void fm_func_001EFB30(u8 *a0) {
    D_0063F744 = (a0 + *(s32 *)(a0 + 0x14));
    D_0063F748 = (a0 + *(s32 *)(a0 + 0x10));
}
#else
INCLUDE_ASM("asm/nonmatchings/xbiscuit", func_001F0E10);
#endif

#ifdef VERSION_FM
void func_001EFB58(s32 a0) {
    D_0063F740 = (a0 << 4);
}
#else
void func_001F0E38(s32 arg0) {
    D_00639A80 = arg0 << 4;
}
#endif

#ifdef VERSION_FM
s32 func_001EFB68(void) {
    return D_0063F740 >> 4;
}
#else
s32 func_001F0E48(void) {
    return D_00639A80 >> 4;
}
#endif

#ifdef VERSION_FM
void func_001EFB78(s32 a0) {
    D_003E8E00 = a0;
}
#else
INCLUDE_ASM("asm/nonmatchings/xbiscuit", func_001F0E58);
#endif

#ifdef VERSION_FM
s32 func_001EFB88(void) {
    return D_003E8E00;
}
#else
s32 func_001F0E68(void) {
    return D_003E3080;
}
#endif

#ifdef VERSION_FM
void func_001EFB98(s32 a0) {
    D_003E8E04 = a0;
}
#else
void func_001F0E78(s32 arg0) {
    D_003E3084 = arg0;
}
#endif

#ifndef VERSION_FM
s32 func_001F0E88(void) {
    return D_003E3084;
}
#endif

#ifdef VERSION_FM
s32 func_001EFBA8(void) {
    return D_003E8E04;
}
#else
INCLUDE_ASM("asm/nonmatchings/xbiscuit", func_001F0E98);
#endif

#ifdef VERSION_FM
s32 func_001EFBB8(a0)
    s32 a0;
{
    return D_0063F744 + ((u16 *)D_0063F748)[a0 - 1];
}

void func_001EFBE0(s32 a0, s32 a1) {
    s32 t0 = func_001EFBB8();
    func_001EFD20(t0, a1);
}

s32 func_001F0EF0(a0)
    s32 a0;
{
    return (s32)(D_003E5ED8 + D_003E890E[a0]);
}

void func_001EFC38(s32 a0, s32 a1) {
    s32 t0 = func_001F0EF0();
    func_001EFD20(t0, a1);
}
#endif

#ifdef VERSION_FM
s32 func_001EFC68(a0, a1, a2)
    u16 *a0;
    s32 a1;
    s32 a2;
{
    return a1 + a0[a2 - 1];
}

void func_001EFC80(s32 a0, s32 a1, s32 a2, s32 a3) {
    s32 t0 = func_001EFC68();
    func_001EFD20(t0, a3);
}
#else
s32 func_001F0EC0(s32 arg0, s32 arg1) {
    s32 val = func_001F0E98(arg0);
    return func_001F0FF8(val, arg1);
}
#endif

#ifndef VERSION_FM
INCLUDE_ASM("asm/nonmatchings/xbiscuit", func_001F0EF0);

s32 func_001F0F10(s32 arg0, s32 arg1) {
    s32 val = func_001F0EF0(arg0);
    return func_001F0FF8(val, arg1);
}

INCLUDE_ASM("asm/nonmatchings/xbiscuit", func_001F0F40);

s32 func_001F0F58(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 val = func_001F0F40(arg0, arg1, arg2);
    return func_001F0FF8(val, arg3);
}
#endif

#ifdef VERSION_FM
s32 func_001EFCB0(u8 *a0, s32 a1) {
    return (s32)(a0 + *(s32 *)(a0 + 0x14)) + ((u16 *)(a0 + *(s32 *)(a0 + 0x10)))[a1 - 1];
}
#else
INCLUDE_ASM("asm/nonmatchings/xbiscuit", func_001F0F88);
#endif

#ifdef VERSION_FM
void func_001EFCD8(u8 *a0, s32 a1, s32 a2) {
    u8 *b = a0 + *(s32 *)(a0 + 0x14);
    u8 *a = a0 + *(s32 *)(a0 + 0x10);
    func_001EFD20(func_001EFC68(a, b, a1), a2);
}
#else
INCLUDE_ASM("asm/nonmatchings/xbiscuit", func_001F0FB0);
#endif

#ifdef VERSION_FM
INCLUDE_ASM("asm/nonmatchings/xbiscuit", func_001EFD20);
#endif

#ifndef VERSION_FM
INCLUDE_ASM("asm/nonmatchings/xbiscuit", func_001F0FF8);

s32 func_001F1070(s32 arg0) {
    s32 val = func_001F0E98(arg0);
    return func_001F1090(val);
}
#endif

#ifdef VERSION_FM
s32 func_001EFD98(a0)
    s32 a0;
{
    return func_001EFDB8(func_001EFBB8(a0));
}

INCLUDE_ASM("asm/nonmatchings/xbiscuit", func_001EFDB8);
#else
INCLUDE_ASM("asm/nonmatchings/xbiscuit", func_001F1090);
#endif

#ifdef VERSION_FM
s32 fm_func_001EFE68(void) {
    s32 t0 = func_001EFD98();
    return t0 + 1;
}
#else
s32 func_001F1140(s32 arg0) {
    return func_001F1070(arg0) + 1;
}
#endif

#ifdef VERSION_FM
s32 func_001EFE88(void) {
    s32 t0 = func_001EFDB8();
    return t0 + 1;
}
#else
s32 func_001F1160(s32 arg0) {
    return func_001F1090(arg0) + 1;
}
#endif

#ifdef VERSION_FM
void func_001EFEA8(void) {
    s32 t0 = func_001EFBB8();
    func_001EFEE8(t0);
}
#else
s32 func_001F1180(s32 arg0) {
    s32 val = func_001F0E98(arg0);
    return func_001F11C0(val);
}
#endif

#ifdef VERSION_FM
void func_001EFEC8(void) {
    s32 t0 = func_001EFC68();
    func_001EFEE8(t0);
}

extern u8 D_003E8D28[];

s32 func_001EFEE8_c(u8* p) __asm__("func_001EFEE8");
s32 func_001EFEE8_c(u8* p) {
    s32 n = 1;
    for (;;) {
        if (*p < 0x15) {
            switch (*p) {
            case 0:
                return n;
            case 0x10:
                p++;
                n++;
                break;
            default:
                p += D_003E8D28[*p];
                break;
            }
        } else if (*p < 0x20) {
            p += 2;
        } else {
            p++;
        }
    }
}

s32 func_001EFF50(s32 a0) {
    u8 *p = (u8 *)D_003E8E28;
    s32 i;

    for (i = 0; i < D_003E8E2C; i++, p += 8) {
        if (*(u16 *)p == a0) {
            return i;
        }
    }
    return 0;
}
#endif

#ifdef VERSION_FM
void func_001EFFA0(void) {
    s32 t0 = func_001EFBB8();
    func_001EFFC0(t0);
}
#else
s32 func_001F11A0(s32 arg0, s32 arg1, s32 arg2) {
    s32 val = func_001F0F40(arg0, arg1, arg2);
    return func_001F11C0(val);
}
#endif

#ifdef VERSION_FM
INCLUDE_ASM("asm/nonmatchings/xbiscuit", func_001EFFC0);
#endif

#ifndef VERSION_FM
INCLUDE_ASM("asm/nonmatchings/xbiscuit", func_001F11C0);

INCLUDE_ASM("asm/nonmatchings/xbiscuit", func_001F1228);
#endif

#ifdef VERSION_FM
void func_001F00D0(s32 a0) {
    func_001F0118(a0, 0x12);
}
#else
s32 func_001F1278(s32 arg0) {
    return func_001F12C0(arg0, 18);
}
#endif

#ifdef VERSION_FM
void func_001F00E8(s32 a0) {
    func_001F0148(a0, 0x12);
}
#else
s32 func_001F1290(s32 arg0) {
    return func_001F12F0(arg0, 18);
}
#endif

#ifdef VERSION_FM
void func_001F0100(s32 a0) {
    func_001F0340(a0, 0x12);
}
#else
s32 func_001F12A8(s32 arg0) {
    return func_001F14F0(arg0, 18);
}
#endif

#ifdef VERSION_FM
void func_001F0118(s32 a0, s32 a1) {
    s32 t0 = func_001EFBB8();
    func_001F0148(t0, a1);
}
#else
s32 func_001F12C0(s32 arg0, s32 arg1) {
    s32 val = func_001F0E98(arg0);
    return func_001F12F0(val, arg1);
}
#endif

#ifdef VERSION_FM
INCLUDE_ASM("asm/nonmatchings/xbiscuit", func_001F0148);
#else
INCLUDE_ASM("asm/nonmatchings/xbiscuit", func_001F12F0);
#endif

#ifdef VERSION_FM
INCLUDE_ASM("asm/nonmatchings/xbiscuit", func_001F0340);
#else
INCLUDE_ASM("asm/nonmatchings/xbiscuit", func_001F14F0);
#endif

#ifdef VERSION_FM
INCLUDE_ASM("asm/nonmatchings/xbiscuit", func_001F0448);
#else
INCLUDE_ASM("asm/nonmatchings/xbiscuit", func_001F15F0);
#endif

#ifdef VERSION_FM
s32 func_001F05E8(s32 a0) {
    return *(u8 *)(a0 * 8 + D_003E8E28 + 6);
}
#else
INCLUDE_ASM("asm/nonmatchings/xbiscuit", func_001F1770);
#endif

#ifdef VERSION_FM
s32 fm_func_001F0600(s32 a0, s32 a1) {
    return ((*(u8 *)(a0 * 8 + D_003E8E28 + 6) << 4) * a1 / 18) >> 4;
}
#else
INCLUDE_ASM("asm/nonmatchings/xbiscuit", func_001F1788);
#endif

#ifdef VERSION_FM
void func_001F0638(s32 a0, s32 a1, s32 a2, s32 a3, s32 a4, s32 a5) {
    func_001F0868(a0, a1, 0, a2, a3, a4, a5, 0xE);
}
#else
void* func_001F17C0(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5) {
    return func_001F19F0(arg0, arg1, 0, arg2, arg3, arg4, arg5, 14);
}
#endif

#ifdef VERSION_FM
void func_001F0670(s32 a0, s32 a1, s32 a2, s32 a3, s32 a4, s32 a5) {
    func_001F07D8(a0, a1, 0, a2, a3, a4, a5, 0x12);
}
#else
void* func_001F17F8(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5) {
    return func_001F1960(arg0, arg1, 0, arg2, arg3, arg4, arg5, 18);
}
#endif

#ifdef VERSION_FM
void func_001F06A8(s32 a0, s32 a1, s32 a2, s32 a3, s32 a4, s32 a5) {
    func_001F0868(a0, a1, 0, a2, a3, a4, a5, 0x12);
}
#else
void* func_001F1830(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5) {
    return func_001F19F0(arg0, arg1, 0, arg2, arg3, arg4, arg5, 18);
}
#endif

#ifdef VERSION_FM
void func_001F06E0(s32 a0, s32 a1, s32 a2, s32 a3, s32 a4, s32 a5) {
    func_001F0EA8(a0, a1, 0, a2, a3, a4, a5, 0x12);
}
#else
void* func_001F1868(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5) {
    return func_001F1FA8(arg0, arg1, 0, arg2, arg3, arg4, arg5, 18);
}
#endif

#ifdef VERSION_FM
void func_001F0718(s32 a0, s32 a1, s32 a2, s32 a3, s32 a4, s32 a5, s32 a6) {
    func_001F07D8(a0, a1, 0, a2, a3, a4, a5, a6);
}
#else
void* func_001F18A0(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6) {
    return func_001F1960(arg0, arg1, 0, arg2, arg3, arg4, arg5, arg6);
}
#endif

#ifdef VERSION_FM
void func_001F0758(s32 a0, s32 a1, s32 a2, s32 a3, s32 a4, s32 a5, s32 a6) {
    func_001F0868(a0, a1, 0, a2, a3, a4, a5, a6);
}
#else
void* func_001F18E0(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6) {
    return func_001F19F0(arg0, arg1, 0, arg2, arg3, arg4, arg5, arg6);
}
#endif

#ifdef VERSION_FM
void func_001F0798(s32 a0, s32 a1, s32 a2, s32 a3, s32 a4, s32 a5, s32 a6) {
    func_001F0EA8(a0, a1, 0, a2, a3, a4, a5, a6);
}
#else
void* func_001F1920(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6) {
    return func_001F1FA8(arg0, arg1, 0, arg2, arg3, arg4, arg5, arg6);
}
#endif

#ifdef VERSION_FM
extern s32 func_001EFBB8(s32);

void func_001F07D8(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7) {
    func_001F0868(arg0, arg1, arg2, arg3, arg4, arg5, func_001EFBB8(arg6), arg7);
}
#else
void* func_001F1960(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7) {
    s32 val = func_001F0E98(arg6);
    return func_001F19F0(arg0, arg1, arg2, arg3, arg4, arg5, val, arg7);
}
#endif

#ifdef VERSION_FM
INCLUDE_ASM("asm/nonmatchings/xbiscuit", func_001F0868);
#else
INCLUDE_ASM("asm/nonmatchings/xbiscuit", func_001F19F0);
#endif

#ifdef VERSION_FM
INCLUDE_ASM("asm/nonmatchings/xbiscuit", func_001F0EA8);
#else
INCLUDE_ASM("asm/nonmatchings/xbiscuit", func_001F1FA8);
#endif

#ifdef VERSION_FM
INCLUDE_ASM("asm/nonmatchings/xbiscuit", func_001F12C0);
#else
INCLUDE_ASM("asm/nonmatchings/xbiscuit", func_001F2378);
#endif

#ifdef VERSION_FM
INCLUDE_ASM("asm/nonmatchings/xbiscuit", func_001F15F0);
#else
void* func_001F2670(s32, s32, s32, s32, s32, s32, s32);
INCLUDE_ASM("asm/nonmatchings/xbiscuit", func_001F2670);
#endif

#ifdef VERSION_FM
void func_001F1868(s32 a0, s32 a1, s32 a2, s32 a3, s32 a4, s32 a5, s32 a6) {
    s32 t0 = func_001EFF50(a5);
    func_001F15F0(a0, a1, a2, a3, a4, t0, a6);
}
#else
void* func_001F2888(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6) {
    s32 val = func_001F1228(arg5);
    return func_001F2670(arg0, arg1, arg2, arg3, arg4, val, arg6);
}
#endif

#ifdef VERSION_FM
INCLUDE_ASM("asm/nonmatchings/xbiscuit", func_001F18E8);
#else
INCLUDE_ASM("asm/nonmatchings/xbiscuit", func_001F2908);
#endif

#ifdef VERSION_FM
void func_001F1DF0(s32 a0, s32 a1, s32 a2, s32 a3) {
    func_001F1F58(0, a0, a1, a2, a3, 0xE);
}
#else
s32 func_001F2DD8(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    func_001F2F88(0, arg0, arg1, arg2, arg3, 14);
    return D_00639A8C;
}
#endif

#ifdef VERSION_FM
void func_001F1E28(s32 a0, s32 a1, s32 a2, s32 a3) {
    func_001F1FC8(0, a0, a1, a2, a3, 0xE);
}
#else
s32 func_001F2E20(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    func_001F30A0(0, arg0, arg1, arg2, arg3, 14);
    return D_00639A8C;
}
#endif

#ifdef VERSION_FM
void func_001F1E60(s32 a0, s32 a1, s32 a2, s32 a3) {
    func_001F2630(0, a0, a1, a2, a3, 0xE);
}
#else
s32 func_001F2E68(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    func_001F31B8(0, arg0, arg1, arg2, arg3, 14);
    return D_00639A8C;
}
#endif

#ifdef VERSION_FM
void func_001F1E98(s32 a0, s32 a1, s32 a2, s32 a3, s32 a4) {
    func_001F1F58(0, a0, a1, a2, a3, a4);
}
#else
s32 func_001F2EB0(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    func_001F2F88(0, arg0, arg1, arg2, arg3, arg4);
    return D_00639A8C;
}
#endif

#ifdef VERSION_FM
void func_001F1ED8(s32 a0, s32 a1, s32 a2, s32 a3, s32 a4) {
    func_001F1FC8(0, a0, a1, a2, a3, a4);
}
#else
s32 func_001F2EF8(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    func_001F30A0(0, arg0, arg1, arg2, arg3, arg4);
    return D_00639A8C;
}
#endif

#ifdef VERSION_FM
void func_001F1F18(s32 a0, s32 a1, s32 a2, s32 a3, s32 a4) {
    func_001F2630(0, a0, a1, a2, a3, a4);
}
#else
s32 func_001F2F40(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    func_001F31B8(0, arg0, arg1, arg2, arg3, arg4);
    return D_00639A8C;
}
#endif

#ifdef VERSION_FM
s32 func_001EFBB8(s32);

void func_001F1F58(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5) {
    func_001F1FC8(arg0, arg1, arg2, arg3, func_001EFBB8(arg4), arg5);
}

INCLUDE_ASM("asm/nonmatchings/xbiscuit", func_001F1FC8);

INCLUDE_ASM("asm/nonmatchings/xbiscuit", func_001F2630);
#endif

#ifndef VERSION_FM
INCLUDE_ASM("asm/nonmatchings/xbiscuit", func_001F2F88);

INCLUDE_ASM("asm/nonmatchings/xbiscuit", func_001F30A0);

INCLUDE_ASM("asm/nonmatchings/xbiscuit", func_001F31B8);
#endif

#ifdef VERSION_FM
s32 func_001F2A50(s32 a0, s32 a1, s32 a2, s32 a3, s32 a4) {
    u8 *p;
    u8 *q;
    u8 *end;
    sceDmaSend(sceDmaGetChan(0x2), D_003F2270);
    p = func_00122048(0x1000, 0x80);
    q = (u8 *)(((u32)p & 0xFFFFFFF) | 0x80000000);
    end = func_001F12C0(p + 0x10, 0x1, a0, a1, a2, a3, a4);
    *(u64 *)p = (((end - p) >> 4) - 1) | 0x70000000;
    sceDmaSend(sceDmaGetChan(0x2), q);
    sceGsSyncPath(0, 0);
    func_001220B8(p);
    return D_0063F74C;
}
#else
INCLUDE_ASM("asm/nonmatchings/xbiscuit", func_001F32D0);
#endif

#ifdef VERSION_FM
s32 func_001F2B58(s32 a0, s32 a1, s32 a2, s32 a3, s32 a4) {
    u8 *p;
    u8 *q;
    u8 *end;
    sceDmaSend(sceDmaGetChan(0x2), D_003F2270);
    p = func_00122048(0x400, 0x80);
    q = (u8 *)(((u32)p & 0xFFFFFFF) | 0x80000000);
    end = func_001F15F0_x(p + 0x10, 0x1, a0, a1, a2, a3, a4);
    *(u64 *)p = (((end - p) >> 4) - 1) | 0x70000000;
    sceDmaSend(sceDmaGetChan(0x2), q);
    sceGsSyncPath(0, 0);
    func_001220B8(p);
    return D_0063F74C;
}
#else
INCLUDE_ASM("asm/nonmatchings/xbiscuit", func_001F33D8);
#endif

#ifdef VERSION_FM
s32 func_001F2C60(s32 a0, s32 a1, s32 a2, s32 a3, s32 a4) {
    u8 *p;
    u8 *q;
    u8 *end;
    sceDmaSend(sceDmaGetChan(0x2), D_003F2270);
    p = func_00122048(0x400, 0x80);
    q = (u8 *)(((u32)p & 0xFFFFFFF) | 0x80000000);
    end = func_001F1868_x(p + 0x10, 0x1, a0, a1, a2, a3, a4);
    *(u64 *)p = (((end - p) >> 4) - 1) | 0x70000000;
    sceDmaSend(sceDmaGetChan(0x2), q);
    sceGsSyncPath(0, 0);
    func_001220B8(p);
    return D_0063F74C;
}
#else
INCLUDE_ASM("asm/nonmatchings/xbiscuit", func_001F34E0);
#endif

#ifdef VERSION_FM
u8 *func_001F18E8_x(u8 *, s32, s32, s32, s32, s32, s32, s32, s32, s32) __asm__("func_001F18E8");

s32 func_001F2D68(s32 a0, s32 a1, s32 a2, s32 a3, s32 a4, s32 a5, s32 a6, s32 a7) {
    u8 *p;
    u8 *q;
    u8 *end;
    sceDmaSend(sceDmaGetChan(0x2), D_003F2270);
    p = end = func_00122048(0x400, 0x80);
    q = (u8 *)(((u32)p & 0xFFFFFFF) | 0x80000000);
    end = func_001F18E8_x(p + 0x10, 0x1, a0, a1, a2, a3, a4, a5, a6, a7);
    *(u64 *)p = (((end - p) >> 4) - 1) | 0x70000000;
    sceDmaSend(sceDmaGetChan(0x2), q);
    sceGsSyncPath(0, 0);
    func_001220B8(p);
    return D_0063F74C;
}
#else
INCLUDE_ASM("asm/nonmatchings/xbiscuit", func_001F35E8);
#endif

#ifdef VERSION_FM
void func_001F2E98(u8 *a0, u8 *a1) {
    *(s32 *)(a0 + 0x0) = (s32)D_003E9660;
    *(s32 *)(a1 + 0x0) = (s32)D_003F1660;
}
#else
void func_001F3718(s32** arg0, s32** arg1) {
    *arg0 = &D_003E38C0;
    *arg1 = &D_003EB8C0;
}
#endif

#ifdef VERSION_FM
INCLUDE_ASM("asm/nonmatchings/xbiscuit", func_001F2EB8);
#else
INCLUDE_ASM("asm/nonmatchings/xbiscuit", func_001F3738);
#endif
