#include "common.h"

extern s32 D_003E8E08[];
void func_0020BB90(s32, s32);
extern u8 D_003F7630[];
extern u8 D_003F7660[];
extern u8 D_003F7690[];
extern s32 D_003F76BC;
extern u8 D_003F75A0[];
extern u8 D_003F75D0[];
extern u8 D_003F7600[];
extern s32 D_003F76B8;
extern u8 D_003F7510[];
extern u8 D_003F7540[];
extern u8 D_003F7570[];
extern s32 D_003F76B4;
void func_0020BBC0(u8 *);
void func_001F3110(s32);
extern s32 D_003F6FF8[];
extern u8 D_003F6FD0[];
extern u8 D_003F6F00[];
extern u8 D_003F6ED0[];
extern u8 D_003F6EA0[];
extern s32 D_006469A4;
extern s32 D_006437E4;
extern s32 D_006437DC;
void func_0020BDA8(s32);
void func_001F3D58(u8 *, s32);
void func_001F4058(u8 *, s32);
void func_00233EF8(s32);
void func_00229A10(s32);
void func_00233FF8(s32, s32);
s32 func_00233F40(s32, s32);
extern s32 D_003F6FC8[];
extern s32 D_00646990;
void func_00207BB0(s32, s32);
s32 func_001FE570(s32);
void func_0020BD18(s32, s32);
s32 func_001FC308(s32, s32, s32, s32, s32, s32, s32, s32, s32);
void func_001F4690(u8 *, u8 *);
u8 *func_001F3A20(u8 *, s32);
void func_001F3758(s32);
extern f32 D_006469B8[];
extern f32 D_002B8344;
void func_001FADE0(s32, s32, s32, s32, s32, s32);
s32 func_001F36B8(s32);
s32 func_001F4400(s32);
s32 func_001EFD98(s32);
extern s32 D_00647630;
void func_002365E0(void);
void func_002336F8(void);
void func_0020B998(void);
extern s32 D_003F7774;
void func_00231A80(void);
u32 func_001F0A80(void);
s32 func_001EFA48(s32);
void *func_0011D598(s32);
extern u8 *D_00425BC8;
s32 func_001F4390(s32);
void func_0020AB88(s32);
extern s32 D_006437D8;
extern s32 D_006437C4;
extern s32 D_006437D0[2];
extern s32 D_006437C8[2];
extern s32 D_003F34A4;
extern u8 D_003F70E8[];
extern s32 D_003F720C;
extern s32 D_003F7A64;
extern s32 D_003F7E94;
extern s32 D_003F7EC4;
extern s32 D_00646A10;
extern s32 D_00646A20;
extern s32 D_00646A24;
extern s32 D_00646A28;
extern s32 D_00647644;
extern s32 D_00647650;
extern s32 D_00647654;
extern s32 D_00647658;
extern s32 D_0064770C;
void func_00109268(void);
s32 func_001EC360(void);
void func_001EFB78(s32);
s32 func_001F0EF0(s32);
void func_001F3840(s32);
s32 func_001F40C8(void);
s32 func_001F42B8(s32);
void func_001F82B0(void);
void func_001F9010(s32);
void func_001F9438(s32, s32, s32, s32, s32, s32, s32);
s32 func_001F94F0(s32, s32, s32, s32, s32, s32, s32);
void func_00205938(s32, s32);
void func_00205E30(s32, u8 *);
void func_00206130(s32, s32, s32, s32, s32, s32);
void func_00207830(s32, s32, s32, s32, s32, s32, s32);
void func_0020A8F0(void);
void func_0020B968(void);
void func_0020BE10(s32);
void func_0020CA30(s32, s32, s32, s32);
void func_0022F818(void);
void func_00231740(s32, s32, s32, s32);
void func_00231958(void);
void func_001F3E90(u8 *, u8 *);
void func_001F3DC0(u8 *);
void func_001F3E20(u8 *, u8 *);
/* unused: rule F1 (layout; went with the D_lay21AD08 pads, which were dropped on 26 Nov) */
void func_00205B30(u8 *, u8 *);
void func_001FD858(u8 *);
s32 func_001FD518(u8 *);
s32 func_001EF530(s32);
void func_0011D598_v(s32) __asm__("func_0011D598");
s32 func_001FD618(u8 *);
s32 func_001FD548(u8 *);
s32 func_001FE5A0();
void func_00233F18(void);
void func_00202FC0(u8 *);
s32 func_001FD590(u8 *);
void func_001F8BA8(u8 *);
void func_001F8F30(void);
void func_001FF488(u8 *, s32, s32, s32, s32, s32);
s32 fm_func_001EE428_r(s32) __asm__("fm_func_001EE428");
typedef struct {
    s32 unk0;
    s32 pad[3];
} A3Slot425C28;
extern A3Slot425C28 D_00425C28[];
/* unused: layout only (F1): without them func_00231CD0 and func_00231EA0 change; 2, 4-9 and 12-24 OK among
 * 0-24 (26 Nov, when the file was split off seg_11AC38), 7 used. */
extern s32 D_lay2298E0_1;
extern s32 D_lay2298E0_2;
extern s32 D_lay2298E0_3;
extern s32 D_lay2298E0_4;
extern s32 D_lay2298E0_5;
extern s32 D_lay2298E0_6;
extern s32 D_lay2298E0_7;

void func_002298E0(s32 a0) {
    func_001F9010(0x17);
    func_001F9438(a0, 0, 0xAE, 0xC, 0x1A6, 0x11, 0x80399BFF);
}

void func_00229928(s32 a0) {
    if (func_001F42B8(a0)) {
        if (*(s32 *)(D_00425BC8 + 0x8) & 0x4000) {
            func_001F3758(D_00646990);
            func_0011D598(0x3);
        } else {
            func_0020BD18(a0, 0x8);
            if (func_001FE570(a0)) {
                func_001F3758(D_00646990);
            }
        }
    }
    func_00207BB0(a0, 0x1A9);
}

void func_002299B0(u8 *a0) {
    s32 n = func_001EFD98(0x1A9) * 0x170;
    *(s32 *)(a0 + 0xB4) -= n;
    *(s16 *)(a0 + 0xBA) += n;
    *(s16 *)(a0 + 0xC0) += n;
}

extern s32 D_006437E0;
extern u8 D_003F6E70[];

void func_00229A10(s32 a0) {
    u8 *e;
    func_001F3758(*(s32 *)(D_00646990 + 0x10));
    func_0011D598(3);
    D_006437E4 = 0;
    D_006469A4 = 0;
    D_006437E0 = 0;
    func_00233EF8(0);
    e = func_001F3A20(D_003F6E70, 6);
    if (e != NULL) {
        func_001F4690(e, (u8 *)a0);
        func_001F4058(e, 2);
        func_001F3D58(e, 6);
        func_002299B0(e);
    }
}

INCLUDE_ASM("asm/nonmatchings/unsplit/file1298E0", func_00229AD0);

void func_00229BD8(u8 *a0) {
    s32 n = func_001EFD98(0x1A7) * 0x170;
    *(s32 *)(a0 + 0xB4) -= n;
    *(s16 *)(a0 + 0xBA) += n;
    *(s16 *)(a0 + 0xC0) += n;
}

void func_00229C38(s32 a0) {
    if (func_001F42B8(a0)) {
        if (func_00233F40(D_006437C4, 0)) {
            func_00233FF8(D_006437C4, 0);
            func_00229A10(a0);
        } else if (*(s32 *)(D_00425BC8 + 0x8) & 0x4000) {
            func_001F3758(D_00646990);
            func_0011D598(0x3);
        } else {
            func_0020BD18(a0, 0x8);
            if (func_001FE570(a0)) {
                func_001F3758(D_00646990);
            }
        }
    }
    func_00207BB0(a0, 0x19C);
}

void func_00229CF8(u8 *a0) {
    s32 n = func_001EFD98(0x19C) * 0x170;
    *(s32 *)(a0 + 0xB4) -= n;
    *(s16 *)(a0 + 0xBA) += n;
    *(s16 *)(a0 + 0xC0) += n;
}

void func_00229D58(s32 a0) {
    if (func_001F42B8(a0)) {
        if (func_00233F40(D_006437C4, 0)) {
            func_00233FF8(D_006437C4, 0);
            func_00229A10(a0);
        } else if (*(s32 *)(D_00425BC8 + 0x8) & 0x4000) {
            func_001F3758(D_00646990);
            func_0011D598(0x3);
        } else {
            func_0020BD18(a0, 0x8);
            if (func_001FE570(a0)) {
                func_001F3758(D_00646990);
            }
        }
    }
    func_00207BB0(a0, 0x1A8);
}

void func_00229E18(u8 *a0) {
    s32 n = func_001EFD98(0x1A8) * 0x170;
    *(s32 *)(a0 + 0xB4) -= n;
    *(s16 *)(a0 + 0xBA) += n;
    *(s16 *)(a0 + 0xC0) += n;
}

void func_00229E78(s32 a0) {
    func_001F9010(0x17);
    func_001F9438(a0, 0, 0xAE, 0xC, 0x1A5, 0x11, 0x80399BFF);
}

typedef struct {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
    s32 unk10;
    u8 unk14[0x24];
    s32 unk38;
} SaveSlot645250;
s32 func_001FD618(u8 *);
s32 func_001FD548(u8 *);
void func_00202FC0(u8 *);
s32 func_001FD590(u8 *);
void func_001F8BA8(u8 *);
void func_001F8F30(void);
void func_001FF488(u8 *, s32, s32, s32, s32, s32);
s32 fm_func_001EE428_r(s32) __asm__("fm_func_001EE428");
extern s32 D_006437C0;
extern s32 D_006450C0[];
extern SaveSlot645250 D_00645250[];
extern u8 D_003F6E40[];
extern s32 D_003F6F58[];

void func_00229EC0(u8 *a0) {
    u8 *e;
    SaveSlot645250 *sv;
    s32 n;
    s32 cur;
    s32 i;
    s32 y;

    if (func_001F42B8((s32)a0)) {
        if (func_00233F40(D_006437C4, 0)) {
            func_00233FF8(D_006437C4, 0);
            func_001F3D58(a0, 6);
            func_00229A10((s32)a0);
        } else if (*(s32 *)(D_00425BC8 + 8) & 0x4000) {
            func_001F3D58(a0, 6);
            func_001F3758(D_00646990);
            func_0011D598(3);
            D_006437E4 = 0;
        } else {
            func_001FD858(a0);
            func_0020BD18((s32)a0, 8);
            D_006437C8[D_006437C4] = func_001FD618(a0);
            D_006437D0[D_006437C4] = func_001FD518(a0);
            D_006437C0 = func_001FD548(a0);
            if (func_001FE5A0(a0)) {
                if (D_006450C0[D_006437C0] != 0) {
                    if (D_00645250[D_006437C0].unk0 != 0x5153484B || D_00645250[D_006437C0].unk4 != 0x1317F14) {
                        func_0011D598(4);
                    } else {
                        func_0011D598(2);
                        func_001F3758((s32)a0);
                        func_0020BE10(0x10);
                        D_006437DC = 0x14;
                        func_00233F18();
                        if ((e = func_001F3A20(D_003F6E40, 6)) != NULL) {
                            func_001F4690(e, a0);
                            func_001F3DC0((u8 *)D_00646990);
                        }
                    }
                } else {
                    func_0011D598(4);
                }
            }
        }
    }
    func_00202FC0(a0);
    n = 0;
    cur = func_001FD518(a0);
    i = func_001FD618(a0);
    y = func_001FD590(a0);
    func_001F8BA8(a0);
    for (; n < 5 && i < 0x63; n++, i++, y += 0x38) {
        func_001FF488(a0, 0, y, 0x14A, 0x32, (n == cur) ? 0x5A040422 : 0x5A000000);
        if (D_006437E4 != 0) {
            if (D_006450C0[i] != 0) {
                sv = &D_00645250[i];
                if (sv->unk0 == 0x5153484B && sv->unk4 == 0x1317F14) {
                    func_001FB428((s32)a0, 0, 2, 1, 0xA, y + 0x12, i + 1, 0xF, 0x80399BFF);
                    func_001F9E48((s32)a0, 0, 0x34, y + 5, (s32)sv->unk14, 0xF, 0x80399BFF);
                    func_001F9438((s32)a0, 0, 0x105, y + 5, D_003F6F58[sv->unk38], 0xF, 0x80399BFF);
                    D_003E8E08[0] = fm_func_001EE428_r(sv->unk10);
                    D_003E8E08[1] = func_001EF530(sv->unk10);
                    D_003E8E08[2] = sv->unkC;
                    D_003E8E08[3] = sv->unk8;
                    func_001F9438((s32)a0, 0, 0x34, y + 0x1E, 0x1A4, 0xF, 0x80399BFF);
                } else {
                    func_001FB428((s32)a0, 0, 2, 1, 0xA, y + 0x12, i + 1, 0xF, 0x804040C0);
                    func_001F9438((s32)a0, 0, 0x34, y + 0x12, 0x1A2, 0xF, 0x804040C0);
                }
            } else {
                func_001FB428((s32)a0, 0, 2, 1, 0xA, y + 0x12, i + 1, 0xF, 0x802B803F);
                func_001F9438((s32)a0, 0, 0x34, y + 0x12, 0x1A3, 0xF, 0x802B803F);
            }
        }
    }
    func_001F8F30();
}

extern u8 D_003F6E70[];

void func_0022A3A0(u8 *a0) {
    u8 *e;
    func_001F36B8(*(s32 *)(a0 + 0x10));
    func_0011D598(3);
    D_006437E4 = 0;
    D_006469A4 = 0;
    func_00233EF8(0);
    e = func_001F3A20(D_003F6E70, 6);
    if (e != NULL) {
        func_001F4690(e, a0);
        func_001F4058(e, 2);
        func_001F3D58(e, 6);
        func_002299B0(e);
        func_0020BDA8(0x10);
    }
}

void func_0022A458(u8 *a0) {
    u8 *e;
    func_001F36B8(*(s32 *)(a0 + 0x10));
    func_0011D598(0x4);
    D_006437DC = 0;
    D_006437E4 = 0;
    D_006469A4 = 0;
    func_00233EF8(0);
    e = func_001F3A20(D_003F6EA0, 0x6);
    if (e != NULL) {
        func_001F4690(e, a0);
        func_001F4058(e, 0x2);
        func_001F3D58(e, 0x6);
        func_00229BD8(e);
        func_0020BDA8(0x10);
    }
}

void func_0022A518(u8 *a0) {
    u8 *e;
    func_001F36B8(*(s32 *)(a0 + 0x10));
    func_0011D598(0x4);
    D_006437DC = 0;
    D_006437E4 = 0;
    D_006469A4 = 0;
    func_00233EF8(0);
    e = func_001F3A20(D_003F6ED0, 0x6);
    if (e != NULL) {
        func_001F4690(e, a0);
        func_001F4058(e, 0x2);
        func_001F3D58(e, 0x6);
        func_00229CF8(e);
        func_0020BDA8(0x10);
    }
}

void func_0022A5D8(u8 *a0) {
    u8 *e;
    func_001F36B8(*(s32 *)(a0 + 0x10));
    func_0011D598(0x4);
    D_006437DC = 0;
    D_006437E4 = 0;
    D_006469A4 = 0;
    func_00233EF8(0);
    e = func_001F3A20(D_003F6F00, 0x6);
    if (e != NULL) {
        func_001F4690(e, a0);
        func_001F4058(e, 0x2);
        func_001F3D58(e, 0x6);
        func_00229E18(e);
        func_0020BDA8(0x10);
    }
}

INCLUDE_ASM("asm/nonmatchings/unsplit/file1298E0", func_0022A698);

void func_0022B248(s32 a0) {
    if (func_001F42B8(a0)) {
        if (*(s32 *)(D_00425BC8 + 0x8) & 0x4000) {
            func_001F36B8(a0);
            func_0011D598(0x3);
        } else {
            func_0020BD18(a0, 0x8);
            if (func_001FE570(a0)) {
                func_001F36B8(a0);
            }
        }
    }
    func_00207BB0(a0, D_003F6FC8[D_006437C4]);
}

void func_0022B2E0(u8 *a0) {
    u8 *e;
    func_0011D598(0x4);
    e = func_001F3A20(D_003F6FD0, 0x6);
    if (e != NULL) {
        s32 n;
        func_001F4690(e, a0);
        func_001F4058(e, 0x2);
        func_001F3D58(e, 0x6);
        n = func_001EFD98(D_003F6FF8[D_006437C4]) * 0x170;
        *(s32 *)(e + 0xB4) -= n;
        *(s16 *)(e + 0xBA) += n;
        *(s16 *)(e + 0xC0) += n;
        func_0020BDA8(0x10);
    }
}

void func_0022B3C8(s32 a0) {
    func_001F9010(0x17);
    func_001F9438(a0, 0, 0xAE, 0xC, 0x199, 0x11, 0x80399BFF);
}

INCLUDE_ASM("asm/nonmatchings/unsplit/file1298E0", func_0022B410);

void func_0022B630(void) {
    func_00109268();
}

INCLUDE_ASM("asm/nonmatchings/unsplit/file1298E0", func_0022B648);

extern u8 D_003F7000[];
extern u8 D_003F7030[];
extern u8 D_003F7060[];
void func_00109278(void);
void func_001F4040(u8 *, s32);
void func_001F40A0(u8 *, s32);
void func_0022B8A0(s32 a0) {
    u8 *e[3];
    if (func_001F42B8(a0)) {
        func_00109278();
        func_00233EF8(0);
        D_006469A4 = 0;
        D_006437E4 = 0;
        D_00425C28[0].unk0 = 3;
        D_00425C28[1].unk0 = 3;
        if ((e[0] = func_001F3A20(D_003F7060, 6)) != NULL) {
            func_001F4690(e[0], (u8 *)a0);
            func_001F4040(e[0], 4);
            func_001F40A0(e[0], 0x5A000000);
            if ((e[1] = func_001F3A20(D_003F7030, 6)) != NULL) {
                func_001F4690(e[1], e[0]);
                *(s16 *)(e[1] + 0xD2) = *(u16 *)&D_006437C4 * 16;
                if ((e[2] = func_001F3A20(D_003F7000, 6)) != NULL) {
                    func_001F4690(e[2], e[1]);
                    func_001F3DC0(e[1]);
                }
            }
        }
    }
}

void func_0022B9A8(s32 a0) {
    func_00207830(a0, 4, 2, 0, 0, 0x7A, 0x192);
}

void func_0022B9D8(s32 a0) {
    func_00205E30(a0, D_003F70E8);
    func_00206130(a0, 0, 0x3E, 0x200, 2, 0x80399BFF);
    func_0020CA30(a0, 0, 0x80221F8F, 0x806360E1);
}

extern u8 D_003F7128;

void func_0022BA40(s32 arg0) {
    func_00205E30(arg0, &D_003F7128);
    func_00206130(arg0, 0, 0, 0x200, 2, 0x80399BFF);
    func_001FC308(arg0, 0xA0, 0xC, 0, 0x3F, 0x14, 0, 0x80399BFF, 0x80399BFF);
}

void func_0022BAC0(u8 *a0) {
    func_0020AB88(*(s32 *)(a0 + 0x90) / 2);
    func_00205938((s32)a0, 0x64000000);
}

void func_0022BB00(s32 a0) {
    if (func_001F4390(a0) && (*(s32 *)(D_00425BC8 + 8) & 8)) {
        func_0011D598(4);
    }
}

INCLUDE_ASM("asm/nonmatchings/unsplit/file1298E0", func_0022BB48);

s32 func_0022BC28(void) {
    if (func_001F40C8() != 0) {
        func_002336F8();
        func_002365E0();
        func_001F82B0();
        func_0020B998();
        return 0;
    }
    D_003F34A4 = 0;
    return 4;
}

void func_0022BC80(void) {
    D_003F34A4 = 1;
    func_0020A8F0();
    func_0020B968();
    D_003F720C = 0;
}

extern u8 D_003F71A0;
void func_0022BB48(void *);

void func_0022BCB8(s32 arg0) {
    void *temp_2;
    func_001F3110(arg0);
    func_0022BC80();
    temp_2 = func_001F3A20(&D_003F71A0, 0);
    if (temp_2 != NULL) {
        func_0022BB48(temp_2);
    }
    *(u16 *)(func_0011ED30(0x2BFE7, func_0022BC28) + 2) = (s16) arg0;
}

void func_0022BD20(void) {
    D_006437C4 = 0;
    D_006437D8 = 0;
    D_006437C8[0] = 0;
    D_006437C8[1] = 0;
    D_006437D0[0] = 0;
    D_006437D0[1] = 0;
}

s32 func_001F3708(s32, s32);
void func_001FDFD0(s32);
void func_0020BC48(s32, s32, s32);
void func_00201440(s32, s32, s32, s32, s32, s32, s32, u8*, s32);
void func_002066B0(s32, s32, s32, s32, s32, s32);
void func_002053E8(s32, s32, s32, s32, s32, s32);
s32 fm_func_002193F0(void);
s32 fm_func_00219458_r(s32) __asm__("fm_func_00219458");
s32 func_00218C78(void);
s32 func_00218BB8(void);
s32 func_00218C08(void);
s32 func_00218C40(void);
s32 func_001EFBB8(s32);
extern s32 D_006469B0;
extern s32 D_006469B4;
extern u8 D_003F7210[];
extern s32 D_003F7228[];
extern s32 D_003F7230[];
extern s32 D_003F7238[];
extern s32 D_003F7248[];

s32 func_001F9438_r(s32, s32, s32, s32, s32, s32, s32) __asm__("func_001F9438");

void func_0022BD58(s32 a0) {
    s32 t;
    s32 t3;
    s32 t6;
    s32 bx;

    if (func_001F42B8(a0)) {
        if (*(s32 *)(D_00425BC8 + 8) & 0x4000) {
            func_001F3708(a0, 0xC);
            func_0011D598(3);
            D_006469B4 = D_006469B0;
            D_006469B0--;
        } else {
            func_001FDFD0(a0);
            t3 = *(s16 *)(a0 + 0xDA) * 0x60;
            bx = *(s16 *)(a0 + 0xBE) - 0x7000;
            t6 = *(s16 *)(a0 + 0xC4) * *(s16 *)(a0 + 0xD2);
            func_0020BC48(8,
                (*(s32 *)(a0 + 0xB0) + t3 + bx + *(s16 *)(a0 + 0xC2) - *(s16 *)(a0 + 0xC6)) >> 4,
                (*(s32 *)(a0 + 0xB4) + t6 / 16 + *(s16 *)(a0 + 0xC0) - 0x7400) >> 4);
            if (func_001FE570(a0)) {
                if (func_001FD538((u8 *)a0) == 0) {
                    D_006469B4 = D_006469B0;
                    D_006469B0++;
                    func_001F3708(a0, 0xB);
                } else {
                    D_006469B4 = D_006469B0;
                    D_006469B0 = fm_func_00219428() ? 1 : 2;
                    func_001F3708(a0, 0xC);
                }
            }
        }
    }
    func_00201440(a0, 2, 2, 0xB, 0x51, 0x7A, 0x48, D_003F7210, 0x57);
    func_002066B0(a0, -0x40, 0x70, 0x280, 0x80C2726E, 0x80C2726E);
    func_002053E8(a0, -0x40, 0x72, 0x280, 0x9C, 0x40000000);
    func_002066B0(a0, -0x40, 0x10E, 0x280, 0x80C2726E, 0x80C2726E);
    if (fm_func_00219428()) {
        func_001F9438_r(a0, 0, 0x28, 0xE6, 0x5E, 0xF, 0x80E6E6E6);
        D_003E8E08[0] = func_001EFBB8(D_003F7230[func_00218C78()]);
        func_001F9438_r(a0, 0, 0x80, 0x7E, 0x1C2, 0xF, 0x66FFC8B4);
        D_003E8E08[0] = fm_func_00219458_r(fm_func_002193F0());
        func_001F9438_r(a0, 0, 0x80, 0x92, 0x5C, 0xF, 0x66FFC8B4);
        D_003E8E08[0] = func_001EFBB8(D_003F7238[func_00218BB8()]);
        func_001F9438_r(a0, 0, 0x80, 0xA6, 0x1D7, 0xF, 0x66FFC8B4);
        D_003E8E08[0] = func_001EFBB8(D_003F7228[func_00218C08()]);
        func_001F9438_r(a0, 0, 0x80, 0xBA, 0x5D, 0xF, 0x66FFC8B4);
        D_003E8E08[0] = func_001EFBB8(D_003F7248[func_00218C40()]);
        func_001F9438_r(a0, 0, 0x80, 0xCE, 0x1DC, 0xF, 0x66FFC8B4);
    } else {
        func_001F9438_r(a0, 0, 0x28, 0xE6, 0x5E, 0xF, 0x80E6E6E6);
        D_003E8E08[0] = fm_func_00219458_r(fm_func_002193F0());
        func_001F9438_r(a0, 0, 0x80, 0x82, 0x5C, 0xF, 0x66FFC8B4);
        D_003E8E08[0] = func_001EFBB8(D_003F7238[func_00218BB8()]);
        func_001F9438_r(a0, 0, 0x80, 0x96, 0x1D7, 0xF, 0x66FFC8B4);
        D_003E8E08[0] = func_001EFBB8(D_003F7228[func_00218C08()]);
        func_001F9438_r(a0, 0, 0x80, 0xAA, 0x5D, 0xF, 0x66FFC8B4);
        D_003E8E08[0] = func_001EFBB8(D_003F7248[func_00218C40()]);
        func_001F9438_r(a0, 0, 0x80, 0xBE, 0x1DC, 0xF, 0x66FFC8B4);
    }
    t = func_001FD538((u8 *)a0);
    func_002078F0(a0, t == 0, 2, 2, 0x100, (s16)*(u16 *)(a0 + 0xC0) >> 4, 0x5A, 0x12D, 0x2C);
    func_002078F0(a0, t == 1, 2, 2, 0x160, (s16)*(u16 *)(a0 + 0xC0) >> 4, 0x5A, 0x18D, 0x2D);
}

INCLUDE_ASM("asm/nonmatchings/unsplit/file1298E0", func_0022C2A0);

INCLUDE_ASM("asm/nonmatchings/unsplit/file1298E0", func_0022C4E8);

INCLUDE_ASM("asm/nonmatchings/unsplit/file1298E0", func_0022C730);

INCLUDE_ASM("asm/nonmatchings/unsplit/file1298E0", func_0022C960);

INCLUDE_ASM("asm/nonmatchings/unsplit/file1298E0", func_0022CBA8);

INCLUDE_ASM("asm/nonmatchings/unsplit/file1298E0", func_0022CDE8);

s32 func_0022D038(void) {
    if (func_001F40C8() != 0) {
        func_001F82B0();
        func_0020B998();
        return 0;
    }
    D_003F34A4 = 0;
    return 4;
}

s32 fm_func_00219428(void);
extern u8 D_003F7380[];
extern s32 D_003F73A4;
extern s32 D_006469B0;
extern s32 D_006469B4;
void func_0022D080(s32 a0) {
    s32* p = &D_006469B4;
    s32* q = &D_006469B0;
    u8* buf[4];
    s32 v;

    func_001F3110(a0);
    buf[0] = func_001F3A20(D_003F7380, 0xC);
    v = fm_func_00219428() ? 1 : 2;
    *q = v;
    *p = v;
    func_0020BB90(0, 0);
    func_0020BDA8(0x10);
    D_003F34A4 = 1;
    D_003F73A4 = 0;
    *(s16*)((u8*)func_0011ED30(0x2BFE7, func_0022D038) + 2) = a0;
}

void func_0022D138(void) {
}

void func_0022D140(s32 a0) {
    if (func_001F4400(a0)) {
        u8 *p = (u8 *)D_006469B8;
        if (*(f32 *)(p + 0x4) != 0.0f) {
            *(f32 *)(p + 0x4) -= D_002B8344;
            if (*(f32 *)(p + 0x4) <= 0.0f) {
                func_001F36B8(a0);
            }
        }
    }
    func_001FADE0(a0, 0, 0, 0x1D, 0x12, *(s32 *)(a0 + 0x24));
}

void func_0022D1B8(s32 a0) {
    if (func_001F4400(a0)) {
        u8 *p = (u8 *)D_006469B8;
        if (*(f32 *)(p + 0x8) != 0.0f) {
            *(f32 *)(p + 0x8) -= D_002B8344;
            if (*(f32 *)(p + 0x8) <= 0.0f) {
                func_001F36B8(a0);
            }
        }
    }
    func_001FADE0(a0, 0, 0, 0xE, 0x12, *(s32 *)(a0 + 0x24));
}

void func_0022D230(s32 a0) {
    if (func_001F4400(a0)) {
        u8 *p = (u8 *)D_006469B8;
        if (*(f32 *)(p + 0xC) != 0.0f) {
            *(f32 *)(p + 0xC) -= D_002B8344;
            if (*(f32 *)(p + 0xC) <= 0.0f) {
                func_001F36B8(a0);
            }
        }
    }
    func_001FADE0(a0, 0, 0, 0x22, 0x12, *(s32 *)(a0 + 0x24));
}

void func_0022D2A8(s32 a0) {
    if (func_001F4400(a0)) {
        u8 *p = (u8 *)D_006469B8;
        if (*(f32 *)(p + 0x10) != 0.0f) {
            *(f32 *)(p + 0x10) -= D_002B8344;
            if (*(f32 *)(p + 0x10) <= 0.0f) {
                func_001F36B8(a0);
            }
        }
    }
    func_001FADE0(a0, 0, 0, 0x20, 0x12, *(s32 *)(a0 + 0x24));
}

void func_0022D320(s32 a0) {
    if (func_001F4400(a0)) {
        u8 *p = (u8 *)D_006469B8;
        if (*(f32 *)(p + 0x14) != 0.0f) {
            *(f32 *)(p + 0x14) -= D_002B8344;
            if (*(f32 *)(p + 0x14) <= 0.0f) {
                func_001F36B8(a0);
            }
        }
    }
    func_001FADE0(a0, 0, 0, 0x12, 0x12, *(s32 *)(a0 + 0x24));
}

void func_0022D398(s32 arg0) {
    if (func_001F4400(arg0)) {
        if (D_006469B8[0] != 0.0f) {
            D_006469B8[0] -= D_002B8344;
            if (D_006469B8[0] <= 0.0f) {
                func_001F36B8(arg0);
            }
        }
    }
    func_00205938(arg0, 0x33000000);
}

s32 func_001F4338(s32);
void func_0011D598_v(s32) __asm__("func_0011D598");
void func_0022D400(s32 a0) {
    if (func_001F4338(a0) && (*(s32 *)(D_00425BC8 + 8) & 0x8)) {
        func_001F36B8(a0);
        func_0011D598_v(0x3);
        D_006469B8[0] = 1.0f;
        D_006469B8[1] = 1.0f;
        D_006469B8[2] = 3.0f;
        D_006469B8[3] = 5.0f;
        D_006469B8[4] = 7.0f;
        D_006469B8[5] = 9.0f;
    }
}

s32 func_0022D498(void) {
    if (func_001F40C8() != 0) {
        func_001F82B0();
        return 0;
    }
    D_003F34A4 = 0;
    return 4;
}

void func_001F3E90(u8 *, u8 *);
void func_001F3E20(u8 *, u8 *);
extern u8 D_003F74D0[];
extern u8 D_003F74A0[];
extern u8 D_003F73B0[];
extern u8 D_003F73E0[];
extern u8 D_003F7410[];
extern u8 D_003F7440[];
extern u8 D_003F7470[];

void func_0022D4D8(s32 a0) {
    u8 *e[7];
    s32 i;
    u8 *t;

    func_001F3110(a0);
    if ((e[0] = func_001F3A20(D_003F74D0, 0x30)) != NULL) {
        func_001F3D58(e[0], 0);
        if ((e[1] = func_001F3A20(D_003F74A0, 0x2E)) != NULL) {
            func_001F3E90(e[0], e[1]);
            func_001F3E20(e[1], e[0]);
            func_001F3D58(e[1], 0x2F);
            if ((e[2] = func_001F3A20(D_003F73B0, 0x30)) != NULL) {
                func_001F3E90(e[1], e[2]);
                func_001F3E20(e[2], e[1]);
                func_001F3D58(e[2], 0x31);
                if ((e[3] = func_001F3A20(D_003F73E0, 0x30)) != NULL) {
                    func_001F3E90(e[2], e[3]);
                    func_001F3E20(e[3], e[2]);
                    func_001F3D58(e[3], 0x31);
                    *(f32 *)(e[3] + 0xA0) = 1.0f;
                    if ((e[4] = func_001F3A20(D_003F7410, 0x30)) != NULL) {
                        func_001F3E90(e[3], e[4]);
                        func_001F3E20(e[4], e[3]);
                        func_001F3D58(e[4], 0x31);
                        *(f32 *)(e[4] + 0xA0) = 2.0f;
                        if ((e[5] = func_001F3A20(D_003F7440, 0x30)) != NULL) {
                            func_001F3E90(e[4], e[5]);
                            func_001F3E20(e[5], e[4]);
                            func_001F3D58(e[5], 0x31);
                            *(f32 *)(e[5] + 0xA0) = 3.0f;
                            if ((e[6] = func_001F3A20(D_003F7470, 0x30)) != NULL) {
                                func_001F3E90(e[5], e[6]);
                                func_001F3E20(e[6], e[5]);
                                func_001F3D58(e[6], 0x31);
                                t = e[0];
                                *(f32 *)(e[6] + 0xA0) = 4.0f;
                                func_001F3DC0(t);
                            }
                        }
                    }
                }
            }
        }
    }
    D_003F34A4 = 1;
    for (i = 5; i >= 0; i--) {
        D_006469B8[i] = 0;
    }
    *(s16 *)((u8 *)func_0011ED30(0x2BFE9, func_0022D498) + 2) = a0;
}

void func_0022D728(void) {
}

INCLUDE_ASM("asm/nonmatchings/unsplit/file1298E0", func_0022D730);

void func_0022DA10(s32 a0) {
    func_001F9438(a0, 2, 0x100, 0x90, 0x5F, 0x12, 0x801E4696);
}

void func_0022DA40(s32 a0) {
    func_00205938(a0, 0x56000000);
}

s32 func_0022DA58(void) {
    if (func_001F40C8() != 0) {
        func_001F82B0();
        func_0020B998();
        return 0;
    }
    D_003F34A4 = 0;
    return 4;
}

extern u8 D_003F7540[];
extern u8 D_003F7510[];
s32 func_0022DA58(void);
void func_0022DAA0(s32 a0) {
    u8 *e[3];
    u8 *r;

    func_001F3110(a0);
    D_003F76B4 = 0;
    if ((e[0] = func_001F3A20(D_003F7570, 1)) != NULL && (e[1] = func_001F3A20(D_003F7540, 1)) != NULL) {
        func_001F4690(e[1], e[0]);
        e[2] = r = func_001F3A20(D_003F7510, 1);
        if (r != NULL) {
            func_001F4690(e[2], e[1]);
            r = e[2];
            *(f32 *)(r + 0xA0) = 16.0f;
        }
    } else {
        r = e[2];
    }
    D_003F34A4 = 1;
    func_0020BBC0(r);
    func_0020BD18((s32)e[2], 8);
    func_0020BDA8(0x10);
    *(s16 *)((u8 *)func_0011ED30(0x2BFE9, func_0022DA58) + 2) = a0;
}

void func_0022DB90(void) {
}

INCLUDE_ASM("asm/nonmatchings/unsplit/file1298E0", func_0022DB98);

void func_0022DE50(s32 a0) {
    func_001F9438(a0, 2, 0x100, 0x90, 0x1CE, 0x12, 0x801E4696);
}

void func_0022DE80(s32 a0) {
    func_00205938(a0, 0x56000000);
}

s32 func_0022DE98(void) {
    if (func_001F40C8() != 0) {
        func_001F82B0();
        func_0020B998();
        return 0;
    }
    D_003F34A4 = 0;
    return 4;
}

void func_0022DEE0(s32 a0) {
    u8 *e[3];
    u8 *r;

    func_001F3110(a0);
    D_003F76B8 = 0;
    if ((e[0] = func_001F3A20(D_003F7600, 1)) != NULL && (e[1] = func_001F3A20(D_003F75D0, 1)) != NULL) {
        func_001F4690(e[1], e[0]);
        e[2] = r = func_001F3A20(D_003F75A0, 1);
        if (r != NULL) {
            func_001F4690(e[2], e[1]);
            r = e[2];
            *(f32 *)(r + 0xA0) = 16.0f;
        }
    } else {
        r = e[2];
    }
    D_003F34A4 = 1;
    func_0020BBC0(r);
    func_0020BD18((s32)e[2], 8);
    func_0020BDA8(0x10);
    *(s16 *)((u8 *)func_0011ED30(0x2BFE9, func_0022DE98) + 2) = a0;
}

void func_0022DFD0(void) {
}

INCLUDE_ASM("asm/nonmatchings/unsplit/file1298E0", func_0022DFD8);

void func_0022E2C0(s32 a0) {
    s32 t0 = func_001F0EF0(0x1D8);
    func_001F94F0(a0, 2, 0x100, 0x90, t0, 0x12, 0x801E4696);
}

void func_0022E308(s32 a0) {
    func_00205938(a0, 0x56000000);
}

s32 func_0022E320(void) {
    if (func_001F40C8() != 0) {
        func_001F82B0();
        func_0020B998();
        return 0;
    }
    D_003F34A4 = 0;
    return 4;
}

void func_0022E368(s32 a0) {
    u8 *e[3];
    u8 *r;

    func_001F3110(a0);
    D_003F76BC = 0;
    if ((e[0] = func_001F3A20(D_003F7690, 1)) != NULL && (e[1] = func_001F3A20(D_003F7660, 1)) != NULL) {
        func_001F4690(e[1], e[0]);
        e[2] = r = func_001F3A20(D_003F7630, 1);
        if (r != NULL) {
            func_001F4690(e[2], e[1]);
            r = e[2];
            *(f32 *)(r + 0xA0) = 16.0f;
        }
    } else {
        r = e[2];
    }
    D_003F34A4 = 1;
    func_0020BBC0(r);
    func_0020BD18((s32)e[2], 8);
    func_0020BDA8(0x10);
    *(s16 *)((u8 *)func_0011ED30(0x2BFE9, func_0022E320) + 2) = a0;
}

void func_0022E458(void) {
}

INCLUDE_ASM("asm/nonmatchings/unsplit/file1298E0", func_0022E460);

void func_0022EA88(s32 a0) {
    func_00205938(a0, 0x40000000);
}

void func_0022EAA0(void) {
    func_001EFB78(0);
}

s32 func_0022EAB8(void) {
    if (func_001F40C8() != 0) {
        func_001F82B0();
        func_0020B998();
        return 0;
    }
    D_003F7774 = 0;
    return 4;
}

extern u8 D_003F7720[];
extern u8 D_003F7750[];
extern s32 D_006469D0;
extern s32 D_006469D4;
extern s32 D_006469DC;
extern s32 D_006469E4;
extern s32 D_006469EC;
extern s32 D_006469F4;
s32 func_0022EAB8(void);
void func_0022BA18(s32 a0) {
    u8 *e[2];
    func_001F3110(a0);
    if ((e[0] = func_001F3A20(D_003F7750, 0x2C)) != NULL) {
        if ((e[1] = func_001F3A20(D_003F7720, 0x2D)) != NULL) {
            func_001F3E90(e[0], e[1]);
            func_001F3E20(e[1], e[0]);
            *(s32 *)(e[1] + 0xA0) = 0;
        }
    }
    D_006469DC = 0;
    D_006469E4 = 0;
    D_006469EC = 0;
    D_006469F4 = 0;
    D_003F7774 = 1;
    D_006469D0 = 0;
    D_006469D4 = 0;
    func_0020B968();
    func_0020BB90(0x153, 0xA4);
    func_0020BDA8(0x28);
    *(s16 *)((u8 *)func_0011ED30(0x2BFE9, func_0022EAB8) + 2) = a0;
}

void func_0022EBE8(void) {
}

void func_0022EBF0(void) {
}

INCLUDE_ASM("asm/nonmatchings/unsplit/file1298E0", func_0022EBF8);

s32 func_0022EDC0(s32 a0) {
    u32 r = func_001EFA48(a0);

    if (func_001F0A80() < r) {
        return -1;
    }
    return a0;
}

extern s32 D_00646A14;
extern s32 D_00646A18;
extern u32 D_003E3D6C;
extern s32 D_0064763C;
extern s32 D_00647634;
extern s32 D_00647638;
void func_0022EBF8(s32);
void func_001F0AD0(s32);
void D598_v(s32) __asm__("func_0011D598");

s32 func_0022EE08(void) {
    func_0022EBF8(D_00646A14);
    if (D_00646A18 > 0) {
        D598_v(8);
        func_001F0AD0(D_0064763C);
        if ((u32)D_00646A20 < D_003E3D6C) {
            { s32 i = D_00647634; *(u8 *)(D_00647638 + i + 0x22) = D_00646A18; }
        } else {
            u8 *p = (u8 *)(D_00646A18 + (s32)D_003010F8 + 0x499);
            *p += D_00646A28;
        }
    } else {
        D598_v(4);
    }
    D_00646A28 = 1;
    return D_00646A18;
}

void func_0022EEE0(s32 a0) {
    D_00646A20 = a0;
    D_00647644 = 0x1E;
}

extern u16 *D_00646A08;
extern s32 D_003F7A68;
extern s32 *D_00646A0C;
extern void (*D_00646A04)(s32);
extern void (*D_00646A00)(s32);
extern s32 D_00646A14;
extern u32 D_003E3D6C;
extern u8 D_003F77B0[];
extern s32 D_003F7780[];
extern s32 D_003F7790[];
extern s32 D_003F77A0[];
void func_0022EBF8(s32);
void func_00205B30(u8 *, u8 *);
void func_001FBCB0(u8 *, s32, s32, s32, s32, s32, s32, s32);
void func_001F8EE0(u8 *);
void func_0020DD38(u8 *, s32, s32, s32, s32, s32);
void func_00207E20(u8 *, s32, s32, s32, s32);
s32 func_001F0BD8(u32);
s32 func_001F0420(s32, s32);
s32 func_001F03A0(s32);
void func_00242EF8(s32, s32, s32, s32 *, s32 *);

void func_0022EEF8(u8 *a0) {
    s32 pos[2];
    s32 col[4];
    u32 mx;
    s32 id;
    s32 price;
    s32 n;
    s32 snd;
    s32 cur;
    s16 cnt;
    s32 y;
    s32 j;
    s32 c;
    s32 alpha;
    s32 e;
    s32 x;
    s32 sel;
    s32 old;
    s32 s20;
    s32 al;
    s32 c2;

    *(u16 *)(a0 + 0xCC) = *D_00646A08;
    if (func_001F42B8((s32)a0)) {
        if (D_003F7A68 != 0) {
            func_001FD858(a0);
            func_0020BD18((s32)a0, 8);
            sel = func_001FD548(a0);
            D_00646A14 = (old = *(s32 *)(a0 + 0x24), sel);
            if (sel != old) {
                D_00646A28 = 1;
            }
            id = D_00646A0C[D_00646A14];
            price = func_001EFA48(id);
            mx = 1;
            if (price != 0) {
                mx = func_001F0A80() / price;
                if (mx != 0) {
                    n = 0x63 - *(u8 *)(id + (s32)D_003010F8 + 0x499);
                    if (n < (s32)mx) {
                        mx = n;
                    }
                }
            }
            if (mx == 0) {
                mx = 1;
            }
            snd = 0;
            if ((*(s32 *)(D_00425BC8 + 0x10) & 0x80000080) && !(*(s32 *)(D_00425BC8 + 0x10) & 0x20000020)) {
                if (D_00646A28 >= 2) {
                    D_00646A28--;
                    snd = 1;
                    *(s32 *)(a0 + 0x24) = D_00646A14;
                } else if (*(s32 *)(D_00425BC8 + 8) & 0x80000080) {
                    if (mx != 1) {
                        D_00646A28 = mx;
                        snd = 1;
                    }
                    *(s32 *)(a0 + 0x24) = D_00646A14;
                }
            } else if ((*(s32 *)(D_00425BC8 + 0x10) & 0x20000020) && !(*(s32 *)(D_00425BC8 + 0x10) & 0x80000080)) {
                if (D_00646A28 < (s32)mx) {
                    D_00646A28++;
                    snd = 1;
                    *(s32 *)(a0 + 0x24) = D_00646A14;
                } else if (*(s32 *)(D_00425BC8 + 8) & 0x20000020) {
                    if (mx != 1) {
                        D_00646A28 = 1;
                        snd = 1;
                    }
                    *(s32 *)(a0 + 0x24) = D_00646A14;
                }
            }
            if (snd) {
                func_0011D598(1);
            }
            if (func_001FE5A0(a0)) {
                func_0022EBF8(D_00646A14);
                if (D_00646A04 != NULL) {
                    D_00646A04(D_00646A0C[D_00646A14]);
                }
            }
        } else {
            func_0020BC48(8, 0x220, -0x20);
        }
    }
    D_00646A14 = func_001FD548(a0);
    if (D_00646A00 != NULL) {
        D_00646A00(D_00646A0C[D_00646A14]);
    }
    for (j = 0; (u32)j < 8; j++) {
        func_00205B30(a0, D_003F77B0 + j * 0x20);
    }
    func_001FC308((s32)a0, 0x104, 0xB, 0, 0, 6, 0, 0x80007EFF, 0x8000EDFF);
    func_001FC308((s32)a0, 0x161, 0xB, 0, 0, 4, 0, 0x402760F5, 0x402760F5);
    func_001FBCB0(a0, 1, 5, 1, 0x1F3, 8, func_001F0A80(), 1);
    func_001F9438((s32)a0, 2, 0x165, 0x2A, 0x66, 0xF, 0x801EC8C8);
    func_001F9438((s32)a0, 2, 0x1D7, 0x2A, 0x67, 0xF, 0x801EC8C8);
    func_00202FC0(a0);
    j = 0;
    cur = func_001FD518(a0);
    id = func_001FD618(a0);
    y = func_001FD590(a0);
    cnt = *(s16 *)(a0 + 0xCC);
    func_001F8EE0(a0);
    for (; j < 9 && id < cnt; j++, y += 0x1C) {
        price = D_00646A0C[id];
        id++;
        if (func_0022EDC0(price) < 0) {
            c = (j == cur) ? 3 : 2;
        } else {
            c = j == cur;
        }
        func_0020DD38(a0, c, 0x114, y, 0xA4, price);
        func_00207E20(a0, c, 0x1BC, y, func_001EFA48(price));
    }
    func_001F8F30();
    func_00206130((s32)a0, 0x108, 0x162, 0x24, 2, 0x80808080);
    func_001F9438((s32)a0, 0, 0x108, 0x164, 0x55, 0xC, 0x80808080);
    func_001FB428((s32)a0, 1, 2, 0, 0x12C, 0x164, D_00646A28, 0xC, 0x80808080);
    func_00206130((s32)a0, 0x108, 0x172, 0x24, 2, 0x80808080);
    c2 = 0x60808080;
    func_001FC308((s32)a0, 0x108, 0x152, 0, 0, 0x11, 0, c2, c2);
    func_001FC308((s32)a0, 0x123, 0x152, 0, 0, 0x12, 0, c2, c2);
    pos[0] = *(s32 *)(a0 + 0xB0) + ((0x1D6 - D_003E3D6C * 0x30) << 4);
    x = 0x1C4 - D_003E3D6C * 0x30;
    pos[1] = *(s32 *)(a0 + 0xB4) + 0x13F0;
    col[0] = 0x80;
    col[1] = 0x80;
    col[2] = 0x80;
    al = *(s32 *)(a0 + 0x90);
    col[3] = al;
    s20 = D_00646A20;
    if (s20 != -1) {
        if (D_00647644 != 0) {
            D_00647644--;
            price = al;
            *(s32 *)(a0 + 0x90) = price * D_00647644 / 30;
            func_001FC308((s32)a0, x + s20 * 0x30 - 0xA, 0x128, 0, 0, 0x17, 0, 0x402395FF, 0x402395FF);
            *(s32 *)(a0 + 0x90) = price;
        }
    }
    for (j = 0; (u32)j < D_003E3D6C && (e = func_001F0BD8(j)) != 0; j++) {
        func_001FC308((s32)a0, x, 0x130, 0, 0, 0x15, 0, 0x26E6E6E6, 0x26E6E6E6);
        func_001FC308((s32)a0, x, 0x130, 0, 0, 0x16, 0, 0x4C000000, 0x4C000000);
        func_001FB428((s32)a0, 1, 0, 0, x + 0x21, 0x163, func_001F0420(*(u8 *)(j + (s32)D_003010F8 + 0x48E), D_00646A0C[D_00646A14]), 0xF, (j == D_00646A20) ? 0x80E6E6E6 : 0x80808080);
        pos[0] += D_003F7790[j];
        pos[1] += D_003F77A0[j];
        func_00242EF8(e, D_003F7780[j], D_003F7780[j], pos, col);
        pos[0] = pos[0] - D_003F7790[j] + 0x300;
        pos[1] -= D_003F77A0[j];
        x += 0x30;
    }
    func_001FC308((s32)a0, 0x1C4, 0x130, 0, 0, 0x15, 0, 0x26E6E6E6, 0x26E6E6E6);
    func_001FC308((s32)a0, 0x1C4, 0x130, 0, 0, 0x16, 0, 0x4C000000, 0x4C000000);
    c2 = 0x80808080;
    func_001FC308((s32)a0, 0x1BC, 0x13C, 0, 0, 7, 0, c2, c2);
    func_001FB428((s32)a0, 1, 0, 0, 0x1E5, 0x163, func_001F03A0(D_00646A0C[D_00646A14]), 0xF, (D_003E3D6C == D_00646A20) ? 0x80E6E6E6 : c2);
}

INCLUDE_ASM("asm/nonmatchings/unsplit/file1298E0", func_0022F818);

extern s32 D_00646A1C;
extern s32 D_00646A30[];
extern s32 D_00646E30[];
extern s32 D_00647230[];
void func_0022FA58(s32 a0) {
    s32 v;
    s32 x;
    s32 *p;
    if (D_00647630 != 0) {
        x = D_00646A28;
        p = &D_00646A1C;
        v = D_00646A30[a0];
        *p = v;
        if (x == 1) {
            if (v != 0) goto chk;
            goto end;
        }
        if ((u32)D_00646A24 < D_003E3D6C || D_00646E30[a0] < x) {
            *p = -3;
            goto end;
        }
chk:
        if (func_001F0A80() > 0x1869E) {
            *p = -1;
        }
    } else {
        D_00646A1C = -2;
    }
end:
    D_00647638 = D_00647230[a0];
}

s32 func_0022FB50(s32 a0) {
    if (D_00647630 == 0) return -2;
    if (a0 != 0) { if (func_001F0A80() > 99998) return -1; }
    return a0;
}

INCLUDE_ASM("asm/nonmatchings/unsplit/file1298E0", func_0022FBA8);

void func_0022FC88(s32 a0) {
    D_00646A24 = a0;
    func_0022F818();
    D_00646A28 = 1;
}

extern s32 D_00646A1C;
extern s32 D_00646A30[];
extern u8 D_003F78D8[];
void func_0022FA58(s32);
s32 func_001EFA68(s32);
void func_001FD5E0(u8 *, s32);
void func_001FD610(u8 *, s32);
void func_001FD688(u8 *);

void func_0022FCB8(u8 *a0) {
    s32 pos[2];
    s32 col[4];
    s32 sel;
    s32 mx;
    s32 snd;
    s32 v;
    s32 j;
    s32 cur;
    s16 cnt;
    s32 k;
    s32 y;
    s32 id;
    s32 c;
    s32 x;
    s32 e;
    s32 s24;
    s32 t4;

    func_001FD5E0(a0, D_00647630);
    func_001FD610(a0, 8);
    func_001FD688(a0);
    if (func_001F42B8((s32)a0)) {
        if (D_003F7A68 != 0) {
            if (D_00647630 != 0) {
                func_001FD858(a0);
                func_0020BD18((s32)a0, 8);
                sel = func_001FD548(a0);
                if (sel != *(s32 *)(a0 + 0x24)) {
                    D_00646A28 = 1;
                }
                mx = 1;
                if (D_003E3D6C <= (u32)D_00646A24) {
                    mx = func_001F03A0(D_00646A30[sel]);
                }
                snd = 0;
                if ((*(s32 *)(D_00425BC8 + 0x10) & 0x80000080) && !(*(s32 *)(D_00425BC8 + 0x10) & 0x20000020)) {
                    if (D_00646A28 >= 2) {
                        D_00646A28--;
                        snd = 1;
                        *(s32 *)(a0 + 0x24) = sel;
                    } else if (*(s32 *)(D_00425BC8 + 8) & 0x80000080) {
                        D_00646A28 = mx;
                        if (mx != 1) {
                            snd = 1;
                        }
                        *(s32 *)(a0 + 0x24) = sel;
                    }
                } else if ((*(s32 *)(D_00425BC8 + 0x10) & 0x20000020) && !(*(s32 *)(D_00425BC8 + 0x10) & 0x80000080)) {
                    if (D_00646A28 < mx) {
                        D_00646A28++;
                        snd = 1;
                        *(s32 *)(a0 + 0x24) = sel;
                    } else if (*(s32 *)(D_00425BC8 + 8) & 0x20000020) {
                        if (mx != 1) {
                            D_00646A28 = 1;
                            snd = 1;
                        }
                        *(s32 *)(a0 + 0x24) = sel;
                    }
                }
                if (snd) {
                    func_0011D598(1);
                }
            }
            if (D_00646A24 != -1 && func_001FE5A0(a0)) {
                func_0022FA58(func_001FD548(a0));
                if (D_00646A04 != NULL) {
                    D_00646A04(D_00646A1C);
                }
            }
        } else {
            func_0020BC48(8, 0x220, -0x20);
        }
    }
    if (D_00646A00 != NULL) {
        if (D_00647630 != 0) {
            v = D_00646A30[func_001FD548(a0)];
        } else {
            v = 0;
        }
        D_00646A00(v);
    }
    for (j = 0; (u32)j < 8; j++) {
        func_00205B30(a0, D_003F78D8 + j * 0x20);
    }
    func_001FC308((s32)a0, 0x104, 0xB, 0, 0, 6, 0, 0x80007EFF, 0x8000EDFF);
    func_001FC308((s32)a0, 0x161, 0xB, 0, 0, 4, 0, 0x402760F5, 0x402760F5);
    func_001FBCB0(a0, 1, 5, 1, 0x1F3, 8, func_001F0A80(), 1);
    func_001F9438((s32)a0, 2, 0x165, 0x2A, 0x66, 0xF, 0x801EC8C8);
    func_001F9438_r((s32)a0, 2, 0x1D7, 0x2A, 0x67, 0xF, 0x801EC8C8);
    if (D_00647630 != 0) {
        func_00202FC0(a0);
        j = 0;
        cur = func_001FD518(a0);
        k = func_001FD618(a0);
        y = func_001FD590(a0);
        cnt = *(s16 *)(a0 + 0xCC);
        func_001F8EE0(a0);
        for (; j < 9 && k < cnt; j++, k++, y += 0x1C) {
            id = D_00646A30[k];
            if (func_0022FB50(id) < 0) {
                c = (j == cur) ? 3 : 2;
            } else {
                c = j == cur;
            }
            func_0020DD38(a0, c, 0x114, y, 0xA4, id);
            func_00207E20(a0, c, 0x1BC, y, func_001EFA68(id));
        }
        func_001F8F30();
    }
    func_00206130((s32)a0, 0x108, 0x162, 0x24, 2, 0x80808080);
    func_001F9438((s32)a0, 0, 0x108, 0x164, 0x55, 0xC, 0x80808080);
    func_001FB428((s32)a0, 1, 2, 0, 0x12C, 0x164, D_00646A28, 0xC, 0x80808080);
    func_00206130((s32)a0, 0x108, 0x172, 0x24, 2, 0x80808080);
    c = 0x60808080;
    func_001FC308((s32)a0, 0x108, 0x152, 0, 0, 0x11, 0, c, c);
    func_001FC308((s32)a0, 0x123, 0x152, 0, 0, 0x12, 0, c, c);
    t4 = D_003E3D6C * 0x30;
    pos[0] = *(s32 *)(a0 + 0xB0) + ((0x1D6 - t4) << 4);
    x = 0x1C4 - t4;
    pos[1] = *(s32 *)(a0 + 0xB4) + 0x13F0;
    col[0] = 0x80;
    col[1] = 0x80;
    col[2] = 0x80;
    col[3] = *(s32 *)(a0 + 0x90);
    s24 = D_00646A24;
    if (s24 != -1) {
        func_001FC308((s32)a0, x + s24 * 0x30 - 0xA, 0x126, 0, 0, 0x17, 0, 0x40FF8528, 0x40FF8528);
    }
    for (j = 0; (u32)j < D_003E3D6C && (e = func_001F0BD8(j)) != 0; j++) {
        func_001FC308((s32)a0, x, 0x130, 0, 0, 0x15, 0, 0x26E6E6E6, 0x26E6E6E6);
        func_001FC308((s32)a0, x, 0x130, 0, 0, 0x16, 0, 0x4C000000, 0x4C000000);
        if (D_00647630 != 0) {
            func_001FB428((s32)a0, 1, 0, 0, x + 0x21, 0x163, func_001F0420(*(u8 *)(j + (s32)D_003010F8 + 0x48E), D_00646A30[func_001FD548(a0)]), 0xF, (j == D_00646A24) ? 0x80E6E6E6 : 0x80808080);
        }
        pos[0] += D_003F7790[j];
        pos[1] += D_003F77A0[j];
        func_00242EF8(e, D_003F7780[j], D_003F7780[j], pos, col);
        pos[0] = pos[0] - D_003F7790[j] + 0x300;
        pos[1] -= D_003F77A0[j];
        x += 0x30;
    }
    func_001FC308((s32)a0, 0x1C4, 0x130, 0, 0, 0x15, 0, 0x26E6E6E6, 0x26E6E6E6);
    func_001FC308((s32)a0, 0x1C4, 0x130, 0, 0, 0x16, 0, 0x4C000000, 0x4C000000);
    id = 0x80808080;
    func_001FC308((s32)a0, 0x1BC, 0x13A, 0, 0, 7, 0, id, id);
    if (D_00647630 != 0) {
        func_001FB428((s32)a0, 1, 0, 0, 0x1E5, 0x163, func_001F03A0(D_00646A30[func_001FD548(a0)]), 0xF, (D_003E3D6C == D_00646A24) ? 0x80E6E6E6 : id);
    }
}

u32 func_001EFDD0(s32);
s32 func_001BC590(s32);
s32 func_001BA458(s32);
void func_002305B0(s32 a0) {
    s32 t = D_00646A0C[a0];
    D_0064763C = func_001EFDD0(t) * D_00646A28;
    if (func_001F0A80() >= (u32)D_0064763C) {
        if (func_001BC590(t) == func_001BA458(t)) {
            D_00646A18 = -2;
        } else if (func_001BC590(t) + D_00646A28 > func_001BA458(t)) {
            D_00646A18 = -4;
        } else {
            D_00646A18 = t;
        }
    } else {
        D_00646A18 = -1;
    }
}

u32 func_001EFDD0(s32);
s32 func_001BC590(s32);
s32 func_001BA458(s32);

s32 func_00230698(s32 a0) {
    u32 r = func_001EFDD0(a0);
    if (func_001F0A80() < r) {
        return -1;
    }
    if (func_001BC590(a0) == func_001BA458(a0)) {
        return -2;
    }
    if (func_001BC590(a0) < func_001BA458(a0)) {
        return a0;
    }
    return -4;
}


extern s32 D_00646A18;
extern s32 D_0064763C;
extern s32 D_00647640;
void func_001F0AD0(s32);
void func_001BA358(s32, s32);
void func_00230728(void) {
    if (D_00646A18 >= 0) {
        func_0011D598_v(8);
        func_001F0AD0(D_0064763C);
        func_001BA358(D_00646A18, D_00646A28);
        D_00647640 += D_00646A28;
    } else {
        func_0011D598_v(4);
    }
    D_00646A28 = 1;
}

extern u16 *D_00646A08;
extern s32 D_003F7A68;
extern s32 *D_00646A0C;
extern void (*D_00646A04)(s32);
extern s32 D_00646A18;
extern void (*D_00646A00)(s32);
extern u8 D_003F77B0[];
extern s32 D_00647640;
void func_002305B0(s32);
void func_00205B30(u8 *, u8 *);
void func_001FBCB0(u8 *, s32, s32, s32, s32, s32, s32, s32);
void func_001F8EE0(u8 *);
void func_0020E1C0(u8 *, s32, s32, s32, s32, s32);
void func_00207E20(u8 *, s32, s32, s32, s32);

void func_002307C0(u8 *a0) {
    s32 sel;
    u32 mx;
    s32 id;
    u32 price;
    s32 n;
    s32 snd;
    s32 sel2;
    s32 cur;
    s16 cnt;
    s32 y;
    s32 j;

    *(u16 *)(a0 + 0xCC) = *D_00646A08;
    if (func_001F42B8((s32)a0)) {
        if (D_003F7A68 != 0) {
            func_001FD858(a0);
            func_0020BD18((s32)a0, 8);
            sel = func_001FD548(a0);
            if (sel != *(s32 *)(a0 + 0x24)) {
                D_00646A28 = 1;
            }
            mx = 1;
            id = D_00646A0C[sel];
            price = func_001EFDD0(id);
            if (price != 0) {
                mx = func_001F0A80() / price;
                if (mx != 0) {
                    n = func_001BA458(id) - func_001BC590(id);
                    if (n < (s32)mx) {
                        mx = n;
                    }
                }
            }
            if (mx == 0) {
                mx = 1;
            }
            snd = 0;
            if ((*(s32 *)(D_00425BC8 + 0x10) & 0x80000080) && !(*(s32 *)(D_00425BC8 + 0x10) & 0x20000020)) {
                if (D_00646A28 >= 2) {
                    D_00646A28--;
                    snd = 1;
                    *(s32 *)(a0 + 0x24) = sel;
                } else if (*(s32 *)(D_00425BC8 + 8) & 0x80000080) {
                    if (mx != 1) {
                        D_00646A28 = mx;
                        snd = 1;
                    }
                    *(s32 *)(a0 + 0x24) = sel;
                }
            } else if ((*(s32 *)(D_00425BC8 + 0x10) & 0x20000020) && !(*(s32 *)(D_00425BC8 + 0x10) & 0x80000080)) {
                if (D_00646A28 < (s32)mx) {
                    D_00646A28++;
                    snd = 1;
                    *(s32 *)(a0 + 0x24) = sel;
                } else if (*(s32 *)(D_00425BC8 + 8) & 0x20000020) {
                    if (mx != 1) {
                        D_00646A28 = 1;
                        snd = 1;
                    }
                    *(s32 *)(a0 + 0x24) = sel;
                }
            }
            if (snd) {
                func_0011D598(1);
            }
            if (func_001FE5A0(a0)) {
                func_002305B0(sel);
                if (D_00646A04 != NULL) {
                    D_00646A04(D_00646A18);
                }
            }
        } else {
            func_0020BC48(8, 0x220, -0x20);
        }
    }
    sel2 = func_001FD548(a0);
    if (D_00646A00 != NULL) {
        D_00646A00(D_00646A0C[sel2]);
    }
    for (j = 0; (u32)j < 8; j++) {
        func_00205B30(a0, D_003F77B0 + j * 0x20);
    }
    func_001FC308((s32)a0, 0x104, 0xB, 0, 0, 0x3B, 0, 0x80FF5751, 0x80F7BC7A);
    func_001FC308((s32)a0, 0x161, 0xB, 0, 0, 4, 0, 0x402760F5, 0x402760F5);
    func_001FBCB0(a0, 1, 5, 1, 0x1F3, 8, func_001F0A80(), 1);
    func_001F9438((s32)a0, 2, 0x165, 0x2A, 0x66, 0xF, 0x801EC8C8);
    func_001F9438((s32)a0, 2, 0x1D7, 0x2A, 0x67, 0xF, 0x801EC8C8);
    func_00202FC0(a0);
    j = 0;
    cur = func_001FD518(a0);
    id = func_001FD618(a0);
    y = func_001FD590(a0);
    cnt = *(s16 *)(a0 + 0xCC);
    func_001F8EE0(a0);
    for (; j < 9 && id < cnt; j++, y += 0x1C) {
        price = D_00646A0C[id];
        id++;
        if (func_00230698(price) < 0) {
            n = (j == cur) ? 3 : 2;
        } else {
            n = j == cur;
        }
        func_0020E1C0(a0, n, 0x114, y, 0xA4, price);
        func_00207E20(a0, n, 0x1BC, y, func_001EFDD0(price));
    }
    func_001F8F30();
    func_00206130((s32)a0, 0x108, 0x162, 0x24, 2, 0x80808080);
    func_001F9438((s32)a0, 0, 0x108, 0x164, 0x55, 0xC, 0x80808080);
    func_001FB428((s32)a0, 1, 2, 0, 0x12C, 0x164, D_00646A28, 0xC, 0x80808080);
    func_00206130((s32)a0, 0x108, 0x172, 0x24, 2, 0x80808080);
    func_001FC308((s32)a0, 0x108, 0x152, 0, 0, 0x11, 0, 0x60808080, 0x60808080);
    func_001FC308((s32)a0, 0x123, 0x152, 0, 0, 0x12, 0, 0x60808080, 0x60808080);
    func_001FC308((s32)a0, 0x1CF, 0x136, 0, 0, 0x19, 0, 0x26E6E6E6, 0x26E6E6E6);
    func_001FC308((s32)a0, 0x1CF, 0x136, 0, 0, 0x1A, 0, 0x4C000000, 0x4C000000);
    func_001FB428((s32)a0, 1, 2, 0, 0x1F1, 0x13B, func_001BC590(D_00646A0C[sel2]), 0xF, 0x80808080);
    func_001F9438_r((s32)a0, 1, 0x1A9, 0x15D, 0x68, 0xF, 0x80808080);
    func_001FBCB0(a0, 1, 0, 1, 0x1F0, 0x15C, D_00647640, 0xE);
}

INCLUDE_ASM("asm/nonmatchings/unsplit/file1298E0", func_00230E38);

s32 func_00230EC8(s32 a0) {
    if (a0 >= 0) {
        if (func_001F0A80() > 99998) {
            return -1;
        }
        return a0;
    }
    return -2;
}

INCLUDE_ASM("asm/nonmatchings/unsplit/file1298E0", func_00230F18);

s32 func_001BC578(void);
s32 func_001EFDE8(s32);
void func_001FD5E0(u8 *, s32);
void func_001FD610(u8 *, s32);
void func_001FD688(u8 *);
void func_00230E38(s32);
extern s32 D_00646A1C;
extern u8 D_003F78D8[];
void func_001FBCD8(u8 *, s32, s32, s32, s32, s32, s32, s32, s32);

void func_00231018(u8 *a0) {
    s32 ids[0xC0];
    s32 cnts[0xC0];
    s32 sel2;
    s32 n;
    s32 i;
    s32 total;
    s32 sel;
    s32 mx;
    s32 snd;
    s32 v;
    s32 cur;
    s32 k;
    s16 cnt;
    s32 y;
    s32 id;
    s32 c;
    void (*fn)(s32);

    i = 0;
    total = func_001BC578();
    n = 0;
    for (; i < total; i++) {
        if (func_001BC590(i) != 0 && func_001EFDE8(i) != 0) {
            ids[n] = i;
            cnts[n] = func_001BC590(i);
            n++;
        }
    }
    func_001FD5E0(a0, n);
    func_001FD610(a0, 8);
    func_001FD688(a0);
    if (func_001F42B8((s32)a0)) {
        if (D_003F7A68 != 0) {
            if (n != 0) {
                func_001FD858(a0);
                func_0020BD18((s32)a0, 8);
                sel = func_001FD548(a0);
                if (sel != *(s32 *)(a0 + 0x24)) {
                    D_00646A28 = 1;
                }
                mx = cnts[sel];
                snd = 0;
                if ((*(s32 *)(D_00425BC8 + 0x10) & 0x80000080) && !(*(s32 *)(D_00425BC8 + 0x10) & 0x20000020)) {
                    if (D_00646A28 >= 2) {
                        D_00646A28--;
                        snd = 1;
                        *(s32 *)(a0 + 0x24) = sel;
                    } else if (*(s32 *)(D_00425BC8 + 8) & 0x80000080) {
                        if (mx != 1) {
                            D_00646A28 = mx;
                            snd = 1;
                        }
                        *(s32 *)(a0 + 0x24) = sel;
                    }
                } else if ((*(s32 *)(D_00425BC8 + 0x10) & 0x20000020) && !(*(s32 *)(D_00425BC8 + 0x10) & 0x80000080)) {
                    if (D_00646A28 < mx) {
                        D_00646A28++;
                        snd = 1;
                        *(s32 *)(a0 + 0x24) = sel;
                    } else if (*(s32 *)(D_00425BC8 + 8) & 0x20000020) {
                        if (mx != 1) {
                            D_00646A28 = 1;
                            snd = 1;
                        }
                        *(s32 *)(a0 + 0x24) = sel;
                    }
                }
                if (snd) {
                    func_0011D598(1);
                }
            }
            if (func_001FE5A0(a0)) {
                if (n != 0) {
                    v = ids[func_001FD548(a0)];
                } else {
                    v = -1;
                }
                func_00230E38(v);
                if (D_00646A04 != NULL) {
                    D_00646A04(D_00646A1C);
                }
            }
        } else {
            func_0020BC48(8, 0x220, -0x20);
        }
    }
    sel2 = func_001FD548(a0);
    fn = D_00646A00;
    if (fn != NULL) {
        if (n != 0) {
            v = ids[sel2];
        } else {
            v = -1;
        }
        fn(v);
    }
    for (i = 0; (u32)i < 8; i++) {
        func_00205B30(a0, D_003F78D8 + i * 0x20);
    }
    func_001FC308((s32)a0, 0x104, 0xB, 0, 0, 0x3B, 0, 0x80FF5751, 0x80F7BC7A);
    func_001FC308((s32)a0, 0x161, 0xB, 0, 0, 4, 0, 0x402760F5, 0x402760F5);
    func_001FBCB0(a0, 1, 5, 1, 0x1F3, 8, func_001F0A80(), 1);
    func_001F9438((s32)a0, 2, 0x165, 0x2A, 0x66, 0xF, 0x801EC8C8);
    func_001F9438((s32)a0, 2, 0x1D7, 0x2A, 0x67, 0xF, 0x801EC8C8);
    if (n != 0) {
        func_00202FC0(a0);
        i = 0;
        cur = func_001FD518(a0);
        k = func_001FD618(a0);
        y = func_001FD590(a0);
        cnt = *(s16 *)(a0 + 0xCC);
        func_001F8EE0(a0);
        for (; i < 9 && k < cnt; i++, k++, y += 0x1C) {
            id = ids[k];
            if (func_00230EC8(id) < 0) {
                c = (i == cur) ? 3 : 2;
            } else {
                c = i == cur;
            }
            func_0020E1C0(a0, c, 0x114, y, 0xA4, id);
            func_00207E20(a0, c, 0x1BC, y, func_001EFDE8(id));
        }
        func_001F8F30();
    }
    func_00206130((s32)a0, 0x108, 0x162, 0x24, 2, 0x80808080);
    func_001F9438((s32)a0, 0, 0x108, 0x164, 0x55, 0xC, 0x80808080);
    func_001FB428((s32)a0, 1, 2, 0, 0x12C, 0x164, D_00646A28, 0xC, 0x80808080);
    func_00206130((s32)a0, 0x108, 0x172, 0x24, 2, 0x80808080);
    func_001FC308((s32)a0, 0x108, 0x152, 0, 0, 0x11, 0, 0x60808080, 0x60808080);
    func_001FC308((s32)a0, 0x123, 0x152, 0, 0, 0x12, 0, 0x60808080, 0x60808080);
    func_001FC308((s32)a0, 0x1CF, 0x136, 0, 0, 0x19, 0, 0x26E6E6E6, 0x26E6E6E6);
    func_001FC308((s32)a0, 0x1CF, 0x136, 0, 0, 0x1A, 0, 0x4C000000, 0x4C000000);
    if (n != 0) {
        func_001FB428((s32)a0, 1, 2, 0, 0x1F1, 0x13B, cnts[sel2], 0xF, 0x80808080);
    }
    func_001F9438((s32)a0, 1, 0x1A9, 0x15D, 0x68, 0xF, 0x80808080);
    func_001FBCD8(a0, 1, 0, 1, 0x1F0, 0x15C, D_00647640, 0xE, (n != 0) ? 0x80808080 : 0x80404040);
}

s32 func_002316F8(void) {
    if (func_001F40C8() != 0) {
        func_001F82B0();
        func_0020B998();
        return 0;
    }
    D_003F7A64 = 0;
    return 4;
}

INCLUDE_ASM("asm/nonmatchings/unsplit/file1298E0", func_00231740);

void func_00231908(s32 a0) {
    func_00231740(0, a0, 0, 0);
}

void func_00231930(s32 a0) {
    func_00231740(1, a0, 0, 0);
}

void func_00231958(void) {
    func_001F3840(D_00646A10);
    func_0020BE10(0x10);
}

void func_00231980(void) {
    func_00231958();
}

void func_00231998(void) {
    func_00231958();
}

void func_002319B0(void) {
    D_003F7A64 = 0;
}

void func_002319C0(void) {
    D_003F7A64 = 0;
}

INCLUDE_ASM("asm/nonmatchings/unsplit/file1298E0", func_002319D0);

void func_001EC380(s32);
extern s32 D_00647664;
extern s32 D_00647668;
extern s32 D_006476F4;

void func_00231A80(void) {
    s32 d = D_00647668 - D_006476F4;
    if (d < 4) {
        if (D_00647664 < 4) {
            func_001EC380(D_00647664 + 1);
        } else if (D_00647664 == 4) {
            if (d == 0) func_001EC380(5);
        } else if (D_00647664 == 5) {
            if (d == 0) func_001EC380(6);
        }
    }
}

s32 func_00231B10(void) {
    s32 t0 = func_001EC360();
    return ((t0 ^ 0x6) == 0);
}

s32 func_00231B38(s32 a0, s32 a1) {
    u8 *p = (u8 *)D_003010F8 + a0 * 0x74;
    s32 n = 0, k;
    for (k = 0; k < p[0x25]; k++) { if (p[0x26 + k] == a1) n++; }
    return n;
}

INCLUDE_ASM("asm/nonmatchings/unsplit/file1298E0", func_00231B98);

extern u16 D_003F7C48[];
extern s32 D_0064765C;
extern s32 D_00647660;
extern s32 D_00647670[];
extern u16 D_003F7A70[];
typedef struct { u8 pad[9]; u8 a[1]; } V231CD0;
void func_00231CD0(s32 a0) {
    u8 *c = (u8 *)&D_003F7C48[D_0064765C * 3];
    u16 *t;
    s32 n;

    if (c[4] == 1 && D_00647670[D_0064765C] != 0) {
        D_00647660 = -3;
        return;
    }
    t = &D_003F7A70[c[2] * 2];
    n = c[3];
    D_00647660 = a0;
    for (; n > 0; n--, t += 2) {
        if (((V231CD0 *)D_003010F8)->a[t[0] + 0x490] < t[1]) {
            D_00647660 = -1;
            return;
        }
    }
    if (((V231CD0 *)D_003010F8)->a[D_00647660 + 0x490] >= 99) D_00647660 = -2;
}

INCLUDE_ASM("asm/nonmatchings/unsplit/file1298E0", func_00231DD0);

/* func_00231EA0 is layout-sensitive (notes/f1.md F1/F24): ee-gcc 2.96 makes several tie decisions in it
 * (combine folding `lhu D_003F7C48(reg)`, two saved-register ties) that depend on how many declarations precede
 * it in the file; the D_lay2298E0 externs at the top of the file keep it matching. */
extern u16 D_003F7C48[];
extern s32 D_003F7E98;
extern s32 D_0064765C;
extern void (*D_0064764C)(s32);
extern s32 D_00647660;
extern void (*D_00647648)(s32);
extern s32 D_006476F4;
extern s32 D_00647670[];
extern s32 D_003F7D30[];
extern s32 D_003F7D40[];
extern s32 D_003F7D50[];
void func_00231CD0(s32);
s32 func_00231DD0(s32);

void func_00231EA0(u8 *a0) {
    s32 pos[2];
    s32 col[4];
    s32 item;
    s16 cnt;
    s32 j;
    s32 k;
    s32 y;
    s32 c;
    s32 x;
    s32 e;

    if (D_003F7E98 != 0 && func_001F42B8((s32)a0)) {
        func_001FD858(a0);
        func_0020BD18((s32)a0, 8);
        D_00647654 = func_001FD618(a0);
        D_00647658 = func_001FD518(a0);
        D_0064765C = func_001FD548(a0);
        if (func_001FE5A0(a0)) {
            func_00231CD0(D_003F7C48[D_0064765C * 3]);
            if (D_0064764C != NULL) {
                D_0064764C(D_00647660);
            }
        }
    }
    item = D_003F7C48[D_0064765C * 3];
    if (D_00647648 != NULL) {
        D_00647648(item);
    }
    cnt = *(s16 *)(a0 + 0xCC);
    D_003E8E08[0] = D_006476F4;
    D_003E8E08[1] = cnt;
    func_001F9438((s32)a0, 0, 0xA0, 0x2A, 0x1AE, 0xF, 0x80E6E6E6);
    j = 0;
    func_00202FC0(a0);
    k = D_00647654;
    y = func_001FD590(a0);
    func_001F8EE0(a0);
    for (; j < 7 && k < cnt; j++, k++) {
        if (((u8)D_003F7C48[k * 3 + 2] == 1 && D_00647670[k] != 0) || func_00231DD0(k) != 0) {
            c = (j == D_00647658) ? 3 : 2;
        } else {
            c = j == D_00647658;
        }
        func_0020DD38(a0, c, 0x1B, y, 0xCC, D_003F7C48[k * 3]);
        if (D_00647670[k] != 0) {
            func_001FC308((s32)a0, 0xBD, y + 7, 0, 0, 0x37, 0, 0x80009100, 0x8027E4D4);
        }
        y += 0x1C;
    }
    func_001F8F30();
    x = 0x12F;
    pos[0] = *(s32 *)(a0 + 0xB0) + 0x1410;
    pos[1] = *(s32 *)(a0 + 0xB4) + 0xEB0;
    col[0] = 0x80;
    col[1] = 0x80;
    col[2] = 0x80;
    col[3] = *(s32 *)(a0 + 0x90);
    for (j = 0; (u32)j < D_003E3D6C && (e = func_001F0BD8(j)) != 0; j++) {
        func_001FC308((s32)a0, x, 0xDA, 0, 0, 0x15, 0, 0x26E6E6E6, 0x26E6E6E6);
        func_001FC308((s32)a0, x, 0xDA, 0, 0, 0x16, 0, 0x4C000000, 0x4C000000);
        func_001FB428((s32)a0, 1, 0, 0, x + 0x21, 0x10D, func_001F0420(*(u8 *)(j + (s32)D_003010F8 + 0x48E), item), 0xF, 0x80808080);
        pos[0] += D_003F7D40[j];
        pos[1] += D_003F7D50[j];
        func_00242EF8(e, D_003F7D30[j], D_003F7D30[j], pos, col);
        pos[0] = pos[0] - D_003F7D40[j] + 0x300;
        pos[1] -= D_003F7D50[j];
        x += 0x30;
    }
    func_001FC308((s32)a0, x, 0xDA, 0, 0, 0x15, 0, 0x26E6E6E6, 0x26E6E6E6);
    func_001FC308((s32)a0, x, 0xDA, 0, 0, 0x16, 0, 0x4C000000, 0x4C000000);
    func_001FC308((s32)a0, x - 8, 0xE6, 0, 0, 7, 0, 0x80808080, 0x80808080);
    func_001FB428((s32)a0, 1, 0, 0, x + 0x21, 0x10D, func_001F03A0(item), 0xF, 0x80808080);
}

INCLUDE_ASM("asm/nonmatchings/unsplit/file1298E0", func_00232390);

s32 func_002325F8(void) {
    if (func_001F40C8() != 0) {
        func_001F82B0();
        func_0020B998();
        return 0;
    }
    D_003F7E94 = 0;
    func_00231A80();
    return 4;
}

INCLUDE_ASM("asm/nonmatchings/unsplit/file1298E0", func_00232640);

void func_00232758(void) {
    func_001F3840(D_00647650);
    func_0020BE10(0x10);
}

void func_00232780(void) {
    D_003F7E94 = 0;
}

void func_00232790(void) {
    D_003F7E94 = 0;
    D_00647654 = 0;
    D_00647658 = 0;
}

INCLUDE_ASM("asm/nonmatchings/unsplit/file1298E0", func_002327B0);

s32 func_00232960(void) {
    if (func_001F40C8() != 0) {
        func_001F82B0();
        return 0;
    }
    D_003F7EC4 = 0;
    return 4;
}

extern s32 D_003F7EC8;
extern s32 D_006476F8;
extern s32 D_006476FC;
extern s32 D_00647700;
extern s32 D_00647704;
extern s32 D_00647708;
typedef struct {
    u8 pad0[0xC];
    s16 unkC;
    s16 unkE;
    s16 unk10;
    s16 unk12;
    u8 pad14[4];
    s16 unk18;
} D3F7EA0_t;
extern D3F7EA0_t D_003F7EA0;


void func_002329A0(u8 *a0, s32 a1, s32 a2) {
    s32 x0, y0, w, h, e;
    func_001F3110((s32)a0);
    D_003F7EC4 = 1;
    D_003F7EC8 = 1;
    D_00647700 = (s32)a0;
    D_006476F8 = a1;
    D_006476FC = a2;
    D_00647704 = (s32)(a0 + 4);
    D_00647708 = (s32)(a0 + 0x644);
    x0 = (u32)(*(s32 *)(a0 + 0x664) - 0x7000) >> 4;
    y0 = (u32)(*(s32 *)(a0 + 0x668) - 0x7400) >> 4;
    w = ((u32)(*(s32 *)(a0 + 0x66C) - 0x7000) >> 4) - x0 + 1;
    h = ((u32)(*(s32 *)(a0 + 0x670) - 0x7400) >> 4) - y0 + 1;
    D_003F7EA0.unk10 = w;
    D_003F7EA0.unk12 = h;
    D_003F7EA0.unk18 = w - 0x28;
    D_003F7EA0.unkC = x0;
    D_003F7EA0.unkE = y0;
    e = (s32)func_001F3A20((u8 *)&D_003F7EA0, 0);
    D_0064770C = e;
    func_0011ED30(0x2C01A, func_00232960);
}

void func_00232AA8(void) {
    func_001F3840(D_0064770C);
}

void func_00232AC8(void) {
}
