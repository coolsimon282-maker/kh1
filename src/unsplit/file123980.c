#include "common.h"

extern s32 D_003E8E08[];
extern u8 D_003F6D10[];
void func_00228E70(u8 *);
extern u8 D_003F6D40[];
extern s32 D_003F3488[];
extern s32 D_003F3468[];
extern u8 *D_003F6E18[];
void func_0020BB90(s32, s32);
void func_002293F0(u8 *);
void func_001F3110(s32);
extern s32 D_003F6BC8[];
extern u8 D_003F6BA0[];
extern u8 D_003F6A40[];
extern u8 D_003F6AA0[];
extern u8 D_003F6A10[];
extern u8 D_003F69E0[];
extern s32 D_00643758;
extern s32 D_0064373C;
void func_0020BDA8(s32);
void func_001F3D58(u8 *, s32);
void func_001F4058(u8 *, s32);
void func_00233EF8(s32);
void func_002246F8(s32);
void func_00233FF8(s32, s32);
s32 func_00233F40(s32, s32);
extern s32 D_003F6B98[];
extern s32 D_006436D4;
extern s32 D_00643740;
void func_00207BB0(s32, s32);
s32 func_001FE570(s32);
void func_0020BD18(s32, s32);
void func_0020A9B0(s32);
void func_0020B120(s32, s32, s32, s32, s32, s32);
extern u8 D_003F6DA8[];
s32 func_001FC308(s32, s32, s32, s32, s32, s32, s32, s32, s32);
void func_0020CCB0(s32);
void func_001F4690(u8 *, u8 *);
u8 *func_001F3A20(u8 *, s32);
void func_001F3758(s32);
s32 func_001F36B8(s32);
s32 func_001EFD98(s32);
void func_00132EC8(s32, void (*)(void));
extern s32 D_003F3500;
void *func_0011D598(s32);
extern u8 *D_00425BC8;
extern s32 D_00643734;
extern s32 D_003F34D4;
extern s32 D_00643794;
void func_0020AB88(s32);
extern s32 D_006436F8[];
extern s32 D_00643700[];
extern s32 D_006436F0;
extern u8 D_003ED728[];
extern s32 D_003F0DD8;
extern u8 D_003F34C0[];
extern u8 D_003F34FC[];
extern s32 D_003F6E30;
extern s32 D_006436D0;
extern s32 D_00643708;
extern u8 D_0064375C[];
extern s32 D_00643798;
void func_00109268(void);
void func_001F3840(s32);
s32 func_001F42B8(s32);
void func_001F9010(s32);
void func_001F9438(s32, s32, s32, s32, s32, s32, s32);
void func_00205E30(s32, u8 *);
void func_00206130(s32, s32, s32, s32, s32, s32);
void func_00207830(s32, s32, s32, s32, s32, s32, s32);
void func_0020BE10(s32);
void func_0020CA30(s32, s32, s32, s32);
void func_001F3DC0(u8 *);
void func_001FD858(u8 *);
s32 func_001FD518(u8 *);
extern s32 D_00643720[];   /* repeated on purpose: keeps func_00228760 matching with fm-a2's func_00220848 and fm-f1 together (a2 rule Q1) */
void func_00220848(s32 a0);
s32 func_001EF530(s32);

void func_00223980(s32 a0, s32 a1, s32 a2) {
    D_006436F0 = a0;
    D_006436F8[a0] = a1;
    D_00643700[a0] = a2;
}

void func_002239B0(s32 a0) {
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
    func_00207BB0(a0, 0x190);
}

void func_00223A30(u8 *a0) {
    s32 n = func_001EFD98(0x190) * 0x170;
    *(s32 *)(a0 + 0xB4) -= n;
    *(s16 *)(a0 + 0xBA) += n;
    *(s16 *)(a0 + 0xC0) += n;
}

INCLUDE_ASM("asm/nonmatchings/unsplit/file123980", func_00223A90);

void func_00223D98(s32 a0) {
    func_001F9010(0x17);
    func_001F9438(a0, 0, 0xAE, 0xC, 0x191, 0x11, 0x8078C850);
}

void func_00223DE0(void) {
    *(s32 *)(D_003F34FC + 0x0) = (*(s32 *)(D_003F34FC + 0x0) + 1);
    *(s32 *)(D_003ED728 + 0x0) = (*(s32 *)(D_003ED728 + 0x0) - 1);
}

void func_00223E10(void) {
    if (*(s32 *)D_003F34FC == 0) {
        *(s32 *)D_003F34FC = 1;
        (*(s32 *)D_003ED728)++;
        func_00132EC8(D_003F3500, func_00223DE0);
    }
}

void func_00223E68(void) {
    D_00643798++;
    D_00643794++;
    (*(s32 *)D_003ED728)--;
}

INCLUDE_ASM("asm/nonmatchings/unsplit/file123980", func_00223EA8);

void func_00224030(void) {
    *(s32 *)(D_0064375C + 0x0) = (*(s32 *)(D_0064375C + 0x0) + 1);
    *(s32 *)(D_003ED728 + 0x0) = (*(s32 *)(D_003ED728 + 0x0) - 1);
}

INCLUDE_ASM("asm/nonmatchings/unsplit/file123980", func_00224060);

void func_002245A8(void) {
    *(s32 *)(D_003F34C0 + 0x0) = (*(s32 *)(D_003F34C0 + 0x0) & -3);
}

void func_002245C8(s32 a0) {
    func_001F9010(0x17);
    func_001F9438(a0, 0, 0xAE, 0xC, 0x188, 0x11, 0x8078C850);
}

void func_00224610(s32 a0) {
    if (func_001F42B8(a0)) {
        if (*(s32 *)(D_00425BC8 + 0x8) & 0x4000) {
            func_001F3758(D_00643740);
            func_0011D598(0x3);
        } else {
            func_0020BD18(a0, 0x8);
            if (func_001FE570(a0)) {
                func_001F3758(D_00643740);
            }
        }
    }
    func_00207BB0(a0, 0x18F);
}

void func_00224698(u8 *a0) {
    s32 n = func_001EFD98(0x18F) * 0x170;
    *(s32 *)(a0 + 0xB4) -= n;
    *(s16 *)(a0 + 0xBA) += n;
    *(s16 *)(a0 + 0xC0) += n;
}

INCLUDE_ASM("asm/nonmatchings/unsplit/file123980", func_002246F8);

void func_001FDFD0(s32);
s32 func_001FD538(s32);
void func_00207C28(s32, s32);
extern u8 D_003F6920[];
void func_00233FB0(s32, s32);
void func_00233F18(void);
void UiObject_InsertAfter(u8 *, u8 *);
void func_002247C8(s32 a0) {
    u8 *e;

    if (func_001F42B8(a0)) {
        if (func_00233F40(D_006436D4, 0)) {
            func_00233FF8(D_006436D4, 0);
            func_002246F8(a0);
        } else if (*(s32 *)(D_00425BC8 + 0x8) & 0x4000) {
            func_001F36B8(a0);
            func_0011D598(3);
        } else {
            func_001FDFD0(a0);
            func_0020BD18(a0, 8);
            if (func_001FE570(a0)) {
                switch (func_001FD538(a0)) {
                case 0:
                    func_001F3758(*(s32 *)(*(u8 **)(a0 + 0xC) + 0xC));
                    if ((e = func_001F3A20(D_003F6920, 6)) != NULL) {
                        UiObject_InsertAfter(e, (u8 *)a0);
                        func_001F3DC0((u8 *)D_00643740);
                    }
                    func_0020BE10(0x10);
                    D_00643734 = 0x47;
                    func_00233F18();
                    break;
                case 1:
                    func_001F36B8(a0);
                    break;
                }
            }
        }
    }
    func_00207C28(a0, 0x189);
}

void func_00224920(u8 *a0) {
    s32 n = func_001EFD98(0x189) * 0x170;
    *(s32 *)(a0 + 0xB4) -= n;
    *(s16 *)(a0 + 0xBA) += n;
    *(s16 *)(a0 + 0xC0) += n;
}

void func_00224980(s32 a0) {
    u8 *e;

    if (func_001F42B8(a0)) {
        if (func_00233F40(D_006436D4, 0)) {
            func_00233FF8(D_006436D4, 0);
            func_002246F8(a0);
        } else if (*(s32 *)(D_00425BC8 + 0x8) & 0x4000) {
            func_001F36B8(a0);
            func_0011D598(3);
        } else {
            func_001FDFD0(a0);
            func_0020BD18(a0, 8);
            if (func_001FE570(a0)) {
                switch (func_001FD538(a0)) {
                case 0:
                    func_001F3758(*(s32 *)(*(u8 **)(a0 + 0xC) + 0xC));
                    if ((e = func_001F3A20(D_003F6920, 6)) != NULL) {
                        UiObject_InsertAfter(e, (u8 *)a0);
                        func_001F3DC0((u8 *)D_00643740);
                    }
                    func_0020BE10(0x10);
                    D_00643734 = 0x37;
                    func_00233F18();
                    break;
                case 1:
                    func_001F36B8(a0);
                    break;
                }
            }
        }
    }
    func_00207C28(a0, 0x18A);
}

void func_00224AD8(u8 *a0) {
    s32 n = func_001EFD98(0x18A) * 0x170;
    *(s32 *)(a0 + 0xB4) -= n;
    *(s16 *)(a0 + 0xBA) += n;
    *(s16 *)(a0 + 0xC0) += n;
}

extern u8 D_003F6920[];
void func_00233FB0(s32, s32);
void func_00233F18(void);
void UiObject_InsertAfter(u8 *, u8 *);
void func_00224B38(s32 a0) {
    u8 *e;

    if (func_001F42B8(a0)) {
        if (func_00233F40(D_006436D4, 0)) {
            func_00233FB0(D_006436D4, 0);
            func_0011D598(2);
            func_001F3758(a0);
            func_0020BE10(0x10);
            D_00643734 = 0;
            func_00233F18();
            if ((e = func_001F3A20(D_003F6920, 6)) != NULL) {
                UiObject_InsertAfter(e, (u8 *)a0);
                func_001F3DC0((u8 *)D_00643740);
            }
        } else if (*(s32 *)(D_00425BC8 + 0x8) & 0x4000) {
            func_001F3758(D_00643740);
            func_0011D598(3);
        } else {
            func_0020BD18(a0, 8);
            if (func_001FE570(a0)) {
                func_001F3758(D_00643740);
            }
        }
    }
    func_00207BB0(a0, 0x18B);
}

void func_00224C48(u8 *a0) {
    s32 n = func_001EFD98(0x18B) * 0x170;
    *(s32 *)(a0 + 0xB4) -= n;
    *(s16 *)(a0 + 0xBA) += n;
    *(s16 *)(a0 + 0xC0) += n;
}

void func_00224CA8(s32 a0) {
    if (func_001F42B8(a0)) {
        if (func_00233F40(D_006436D4, 0)) {
            func_00233FF8(D_006436D4, 0);
            func_002246F8(a0);
        } else if (*(s32 *)(D_00425BC8 + 0x8) & 0x4000) {
            func_001F3758(D_00643740);
            func_0011D598(0x3);
        } else {
            func_0020BD18(a0, 0x8);
            if (func_001FE570(a0)) {
                func_001F3758(D_00643740);
            }
        }
    }
    func_00207BB0(a0, 0x176);
}

void func_00224D68(u8 *a0) {
    s32 n = func_001EFD98(0x176) * 0x170;
    *(s32 *)(a0 + 0xB4) -= n;
    *(s16 *)(a0 + 0xBA) += n;
    *(s16 *)(a0 + 0xC0) += n;
}

void func_00224DC8(s32 a0) {
    if (func_001F42B8(a0)) {
        if (func_00233F40(D_006436D4, 0)) {
            func_00233FF8(D_006436D4, 0);
            func_002246F8(a0);
        } else if (*(s32 *)(D_00425BC8 + 0x8) & 0x4000) {
            func_001F3758(D_00643740);
            func_0011D598(0x3);
        } else {
            func_0020BD18(a0, 0x8);
            if (func_001FE570(a0)) {
                func_001F3758(D_00643740);
            }
        }
    }
    func_00207BB0(a0, 0x17E);
}

void func_00224E88(u8 *a0) {
    s32 n = func_001EFD98(0x17E) * 0x170;
    *(s32 *)(a0 + 0xB4) -= n;
    *(s16 *)(a0 + 0xBA) += n;
    *(s16 *)(a0 + 0xC0) += n;
}

extern s32 D_003F6C90[];   /* repeated on purpose: keeps func_00228760 matching (a2 rule Q1) */
void func_001FDFD0(s32);
s32 func_001FD538(s32);
void func_00207C28(s32, s32);
void func_00224EE8(s32 a0) {
    u8 *e;

    if (func_001F42B8(a0)) {
        if (func_00233F40(D_006436D4, 0)) {
            func_00233FF8(D_006436D4, 0);
            func_002246F8(a0);
        } else if (*(s32 *)(D_00425BC8 + 0x8) & 0x4000) {
            func_001F3758(D_00643740);
            func_0011D598(3);
        } else {
            func_001FDFD0(a0);
            func_0020BD18(a0, 8);
            if (func_001FE570(a0)) {
                switch (func_001FD538(a0)) {
                case 0:
                    func_001F36B8(a0);
                    func_0020BE10(0x10);
                    D_00643734 = 6;
                    if ((e = func_001F3A20(D_003F6920, 6)) != NULL) {
                        UiObject_InsertAfter(e, (u8 *)a0);
                        func_001F3DC0((u8 *)D_00643740);
                    }
                    break;
                case 1:
                    func_001F3758(D_00643740);
                    break;
                }
            }
        }
    }
    func_00207C28(a0, 0x18C);
}

void func_00225030(u8 *a0) {
    s32 n = func_001EFD98(0x18C) * 0x170;
    *(s32 *)(a0 + 0xB4) -= n;
    *(s16 *)(a0 + 0xBA) += n;
    *(s16 *)(a0 + 0xC0) += n;
}

void func_00225090(s32 a0) {
    if (func_001F42B8(a0)) {
        if (func_00233F40(D_006436D4, 0)) {
            func_00233FF8(D_006436D4, 0);
            func_002246F8(a0);
        } else if (*(s32 *)(D_00425BC8 + 0x8) & 0x4000) {
            func_001F3758(D_00643740);
            func_0011D598(0x3);
        } else {
            func_0020BD18(a0, 0x8);
            if (func_001FE570(a0)) {
                func_001F3758(D_00643740);
            }
        }
    }
    func_00207BB0(a0, 0x18D);
}

void func_00225150(u8 *a0) {
    s32 n = func_001EFD98(0x18D) * 0x170;
    *(s32 *)(a0 + 0xB4) -= n;
    *(s16 *)(a0 + 0xBA) += n;
    *(s16 *)(a0 + 0xC0) += n;
}

extern s32 D_00643750;
void func_002251B0(s32 a0) {
    if (func_001F42B8(a0)) {
        if (func_00233F40(D_006436D4, 0)) {
            func_00233FF8(D_006436D4, 0);
            func_002246F8(a0);
        } else if (*(s32 *)(D_00425BC8 + 8) & 0x4000) {
            func_001F36B8(a0);
            func_0011D598(3);
        } else {
            func_0020BD18(a0, 8);
            if (func_001FE570(a0)) {
                func_001F36B8(a0);
            }
        }
    }
    D_003E8E08[1] = 0x84;
    D_003E8E08[0] = D_00643750;
    func_00207BB0(a0, 0x18E);
}

void func_00225288(u8 *a0) {
    s32 n = func_001EFD98(0x18E) * 0x170;
    *(s32 *)(a0 + 0xB4) -= n;
    *(s16 *)(a0 + 0xBA) += n;
    *(s16 *)(a0 + 0xC0) += n;
}

void func_002252E8(s32 a0) {
    func_001F9010(0x17);
    func_001F9438(a0, 0, 0xAE, 0xC, 0x187, 0x11, 0x8078C850);
}

typedef struct {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
    s32 unk10;
    u8 unk14[0x24];
    s32 unk38;
} SaveSlot351E10;
typedef struct {
    u8 pad[0x18C0];
    s32 used[100];
    SaveSlot351E10 slot[1];
} SaveData351E10;
extern SaveData351E10 D_00351E10;
extern s32 D_006436D8[];
extern s32 D_006436E0[];
extern s32 D_006436E8;
extern s32 D_00643750;
extern u8 D_003F6980[];
extern u8 D_003F69B0[];
extern u8 D_003F6AD0[];
extern u8 D_003F6920[];
extern s32 D_003F6B28[];
u8 *func_001F3520(u8 *, s32);
s32 func_001FD618(u8 *);
s32 func_001FD548(u8 *);
s32 func_001FE5A0();
void func_00233F18(void);
void func_001F3DC0(u8 *);
void func_00202FC0(u8 *);
s32 func_001FD590(u8 *);
void func_001F8BA8(u8 *);
void func_001F8F30(void);
void func_001FF488(u8 *, s32, s32, s32, s32, s32);
s32 fm_func_001EE428_r(s32) __asm__("fm_func_001EE428");
void func_00224920(u8 *);
void func_00224AD8(u8 *);
void func_00225288(u8 *);
s32 func_001EF530(s32);

void func_00225330(u8 *a0) {
    u8 *e;
    SaveSlot351E10 *sv;
    s32 n;
    s32 cur;
    s32 i;
    s32 y;

    if (func_001F42B8((s32)a0)) {
        if (func_00233F40(D_006436D4, 0)) {
            func_00233FF8(D_006436D4, 0);
            func_001F3D58(a0, 6);
            func_002246F8((s32)a0);
        } else if (*(s32 *)(D_00425BC8 + 8) & 0x4000) {
            func_001F3D58(a0, 6);
            func_001F3758(D_00643740);
            func_0011D598(3);
            D_0064373C = 0;
        } else {
            func_001FD858(a0);
            func_0020BD18((s32)a0, 8);
            D_006436D8[D_006436D4] = func_001FD618(a0);
            D_006436E0[D_006436D4] = func_001FD518(a0);
            D_006436E8 = func_001FD548(a0);
            if (func_001FE5A0(a0)) {
                if (D_00351E10.used[D_006436E8] != 0) {
                    if (D_00351E10.slot[D_006436E8].unk0 != 0x5153484B || D_00351E10.slot[D_006436E8].unk4 != 0x1317F14) {
                        if (D_00643750 != 0) {
                            func_0011D598(6);
                            if ((e = func_001F3520(D_003F6980, 6)) != NULL) {
                                func_001F4690(e, *(u8 **)(a0 + 0x10));
                                func_001F4058(e, 1);
                                func_001F3D58(e, 6);
                                func_00224920(e);
                                *(s16 *)(e + 0xDA) = 0x10;
                            }
                        } else {
                            func_0011D598(4);
                            if ((e = func_001F3A20(D_003F6AD0, 6)) != NULL) {
                                func_001F4690(e, *(u8 **)(a0 + 0x10));
                                func_001F4058(e, 1);
                                func_001F3D58(e, 6);
                                func_00225288(e);
                            }
                        }
                    } else {
                        func_0011D598(6);
                        if ((e = func_001F3520(D_003F69B0, 6)) != NULL) {
                            func_001F4690(e, *(u8 **)(a0 + 0x10));
                            func_001F4058(e, 1);
                            func_001F3D58(e, 6);
                            func_00224AD8(e);
                            *(s16 *)(e + 0xDA) = 0x10;
                        }
                    }
                } else {
                    if (D_00643750 == 0) {
                        func_0011D598(4);
                        if ((e = func_001F3A20(D_003F6AD0, 6)) != NULL) {
                            func_001F4690(e, *(u8 **)(a0 + 0x10));
                            func_001F4058(e, 1);
                            func_001F3D58(e, 6);
                            func_00225288(e);
                        }
                    } else {
                        func_0011D598(2);
                        func_001F3758((s32)a0);
                        func_0020BE10(0x10);
                        D_00643734 = 0x1A;
                        func_00233F18();
                        if ((e = func_001F3A20(D_003F6920, 6)) != NULL) {
                            func_001F4690(e, a0);
                            func_001F3DC0((u8 *)D_00643740);
                        }
                    }
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
        if (D_0064373C != 0) {
            if (D_00351E10.used[i] != 0) {
                sv = &D_00351E10.slot[i];
                if (sv->unk0 == 0x5153484B && sv->unk4 == 0x1317F14) {
                    func_001FB428((s32)a0, 0, 2, 1, 0xA, y + 0x12, i + 1, 0xF, 0x80399BFF);
                    func_001F9E48((s32)a0, 0, 0x34, y + 5, (s32)sv->unk14, 0xF, 0x80399BFF);
                    func_001F9438((s32)a0, 0, 0x105, y + 5, D_003F6B28[sv->unk38], 0xF, 0x80399BFF);
                    D_003E8E08[0] = fm_func_001EE428_r(sv->unk10);
                    D_003E8E08[1] = func_001EF530(sv->unk10);
                    D_003E8E08[2] = sv->unkC;
                    D_003E8E08[3] = sv->unk8;
                    func_001F9438((s32)a0, 0, 0x34, y + 0x1E, 0x186, 0xF, 0x80399BFF);
                } else {
                    func_001FB428((s32)a0, 0, 2, 1, 0xA, y + 0x12, i + 1, 0xF, 0x804040C0);
                    func_001F9438((s32)a0, 0, 0x34, y + 0x12, 0x182, 0xF, 0x804040C0);
                }
            } else if (D_00643750 == 0) {
                func_001FB428((s32)a0, 0, 2, 1, 0xA, y + 0x12, i + 1, 0xF, 0x802B803F);
                func_001F9438((s32)a0, 0, 0x34, y + 0x12, 0x184, 0xF, 0x802B803F);
            } else {
                func_001FB428((s32)a0, 0, 2, 1, 0xA, y + 0x12, i + 1, 0xF, 0x802B803F);
                func_001F9438((s32)a0, 0, 0x34, y + 0x12, 0x185, 0xF, 0x802B803F);
            }
        }
    }
    func_001F8F30();
}

void func_00225988(void) {
    D_003F34D4++;
    D_00643734++;
    (*(s32 *)D_003ED728)--;
}

extern s32 D_003F6950[];
void func_002259C8(u8 *a0) {
    u8 *e;
    func_001F36B8(*(s32 *)(a0 + 0x10));
    func_0011D598(3);
    D_0064373C = 0;
    D_00643758 = 0;
    func_00223980(D_006436D4, 0, 0);
    func_00233EF8(0);
    e = func_001F3A20(D_003F6950, 6);
    if (e != NULL) {
        func_001F4690(e, a0);
        func_001F4058(e, 1);
        func_001F3D58(e, 6);
        func_00224698(e);
        func_0020BDA8(0x10);
    }
}

void func_00225A90(u8 *a0) {
    u8 *e;
    func_001F36B8(*(s32 *)(a0 + 0x10));
    func_0011D598(0x4);
    D_00643734 = 0;
    D_0064373C = 0;
    D_00643758 = 0;
    func_00223980(D_006436D4, 0, 0);
    func_00233EF8(0);
    e = func_001F3A20(D_003F69E0, 0x6);
    if (e != NULL) {
        func_001F4690(e, a0);
        func_001F4058(e, 0x1);
        func_001F3D58(e, 0x6);
        func_00224C48(e);
        func_0020BDA8(0x10);
    }
}

void func_00225B60(u8 *a0) {
    u8 *e;
    func_001F36B8(*(s32 *)(a0 + 0x10));
    func_0011D598(0x4);
    D_00643734 = 0;
    D_0064373C = 0;
    D_00643758 = 0;
    func_00223980(D_006436D4, 0, 0);
    func_00233EF8(0);
    e = func_001F3A20(D_003F6A10, 0x6);
    if (e != NULL) {
        func_001F4690(e, a0);
        func_001F4058(e, 0x1);
        func_001F3D58(e, 0x6);
        func_00224D68(e);
        func_0020BDA8(0x10);
    }
}

extern u8 D_003F6A70[];

void func_00225C30(u8 *arg0) {
    u8 *temp_2;
    func_001F36B8(*(s32 *)(arg0 + 0x10));
    func_0011D598(6);
    D_00643734 = 0;
    D_0064373C = 0;
    D_00643758 = 0;
    func_00233EF8(0);
    func_00223980(D_006436D4, 0, 0);
    temp_2 = func_001F3520(D_003F6A70, 6);
    if (temp_2 != NULL) {
        func_001F4690(temp_2, arg0);
        func_001F4058(temp_2, 1);
        func_001F3D58(temp_2, 6);
        func_00225030(temp_2);
        *(u16 *)(temp_2 + 0xDA) = 0x10;
        func_0020BDA8(0x10);
    }
}

void func_00225D08(u8 *a0) {
    u8 *e;
    func_001F36B8(*(s32 *)(a0 + 0x10));
    func_0011D598(0x4);
    D_00643734 = 0;
    D_0064373C = 0;
    D_00643758 = 0;
    func_00223980(D_006436D4, 0, 0);
    func_00233EF8(0);
    e = func_001F3A20(D_003F6AA0, 0x6);
    if (e != NULL) {
        func_001F4690(e, a0);
        func_001F4058(e, 0x1);
        func_001F3D58(e, 0x6);
        func_00225150(e);
        func_0020BDA8(0x10);
    }
}

void func_00225DD8(u8 *a0) {
    u8 *e;
    func_001F36B8(*(s32 *)(a0 + 0x10));
    func_0011D598(0x4);
    D_00643734 = 0;
    D_0064373C = 0;
    D_00643758 = 0;
    func_00223980(D_006436D4, 0, 0);
    func_00233EF8(0);
    e = func_001F3A20(D_003F6A40, 0x6);
    if (e != NULL) {
        func_001F4690(e, a0);
        func_001F4058(e, 0x1);
        func_001F3D58(e, 0x6);
        func_00224E88(e);
        func_0020BDA8(0x10);
    }
}

INCLUDE_ASM("asm/nonmatchings/unsplit/file123980", func_00225EA8);

void func_00227EF8(s32 a0) {
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
    func_00207BB0(a0, D_003F6B98[D_006436D4]);
}

void func_00227F90(u8 *a0) {
    u8 *e;
    func_0011D598(0x4);
    e = func_001F3A20(D_003F6BA0, 0x6);
    if (e != NULL) {
        s32 n;
        func_001F4690(e, a0);
        func_001F4058(e, 0x1);
        func_001F3D58(e, 0x6);
        n = func_001EFD98(D_003F6BC8[D_006436D4]) * 0x170;
        *(s32 *)(e + 0xB4) -= n;
        *(s16 *)(e + 0xBA) += n;
        *(s16 *)(e + 0xC0) += n;
        func_0020BDA8(0x10);
    }
}

void func_00228078(s32 a0) {
    func_001F9010(0x17);
    func_001F9438(a0, 0, 0xAE, 0xC, 0x173, 0x11, 0x8078C850);
}

s32 func_001F44A0(u8 *);
void func_001FD858(u8 *);
s32 func_001FD518(u8 *);
s32 func_001FE5A0();
void func_00233F28(s32, s32);
void func_00233FB0(s32, s32);
void func_00233F18(void);
void func_001F3DC0(u8 *);
void func_00209340(u8 *, s32, u8 *);
extern u8 D_003F6A70[];
extern u8 D_003F6BF8[];
extern u8 D_003F6BD0[];
extern u8 D_003F6B70[];
extern u8 D_003F6920[];
typedef struct {
    s32 unk0;
    s32 pad[3];
} A3Slot425C28;
extern A3Slot425C28 D_00425C28[];
extern s32 D_006436EC;
extern s32 D_00643738;

void func_002280C0(u8 *a0) {
    u8 *e[2];

    if (func_001F42B8((s32)a0)) {
        if (func_001F44A0(D_003F6A70) == 0) {
            if (*(s32 *)(D_00425BC8 + 8) & 0x4000) {
                func_001F3758(*(s32 *)(a0 + 0xC));
                func_0011D598(3);
            } else {
                if (*(s32 *)(a0 + 0x10) == 0) {
                    if ((e[0] = func_001F3A20(D_003F6BD0, 6)) != NULL) {
                        func_001F4690(e[0], a0);
                        func_001F3DC0(a0);
                    }
                }
                func_001FD858(a0);
                func_0020BD18((s32)a0, 8);
                D_006436D4 = func_001FD518(a0);
                func_00233F28(D_006436D4, 0);
                D_00425C28[D_006436D4 ^ 1].unk0 = 3;
                if (func_001FE5A0(a0)) {
                    if (D_00425C28[D_006436D4].unk0 != 3) {
                        if (func_00233F40(D_006436D4, 0)) {
                            func_00233FB0(D_006436D4, 0);
                            func_00233FF8(D_006436D4, 0);
                            func_00223980(D_006436D4, 0, 0);
                            D_00643758 = 0;
                        }
                        if (D_006436EC != D_006436D4) {
                            D_00643758 = 0;
                        }
                        func_0011D598(2);
                        func_00233F18();
                        D_00643734 = 0;
                        D_00643738 = 0;
                        func_001F36B8(*(s32 *)(a0 + 0x10));
                        if ((e[0] = func_001F3A20(D_003F6B70, 0)) != NULL) {
                            func_001F4690(e[0], a0);
                            D_00643740 = (s32)e[0];
                            if ((e[1] = func_001F3A20(D_003F6920, 6)) != NULL) {
                                func_001F4690(e[1], e[0]);
                                func_001F3DC0(e[0]);
                            }
                        }
                    } else {
                        func_00227F90(a0);
                    }
                }
            }
        }
    }
    func_00209340(a0, 2, D_003F6BF8);
}

void func_002282F8(void) {
    func_00109268();
    *(s32 *)(D_003F34C0 + 0x0) = (*(s32 *)(D_003F34C0 + 0x0) & -3);
}

INCLUDE_ASM("asm/nonmatchings/unsplit/file123980", func_00228330);

INCLUDE_ASM("asm/nonmatchings/unsplit/file123980", func_00228588);

void func_00228700(u8 *a0) {
    s32 n = func_001EFD98(0x16D) * 0x170;
    *(s32 *)(a0 + 0xB4) -= n;
    *(s16 *)(a0 + 0xBA) += n;
    *(s16 *)(a0 + 0xC0) += n;
}

extern s32 D_006436D0;
extern s32 D_00643720[];
extern s32 D_003F6C90[];
extern s32 D_003F6E2C;

void func_00228760(s32 arg0) {
    s32 var_16;
    var_16 = D_003F6C90[D_00643720[D_006436D0]];
    if (var_16 == 0x16A) {
        var_16 = ((D_003F6E2C ^ 3) != 0) ? 0x16C : var_16;
    }
    func_001F9010(0x17);
    func_001F9438((void *)(long)arg0, 0, 0xAE, 0xC, var_16, 0x11, 0x8078C850);
}

INCLUDE_ASM("asm/nonmatchings/unsplit/file123980", func_002287F8);

void func_00228E18(s32 a0) {
    if (func_001F42B8(a0)) {
        func_001F3840(a0);
        func_0020BE10(0x10);
    }
    func_00207830(a0, 4, 2, 0, 0, 0x7A, 0x165);
}

INCLUDE_ASM("asm/nonmatchings/unsplit/file123980", func_00228E70);

extern u8 D_003F6CE0[];
extern u8 D_003F6CA0[];
extern u16 D_00643730;

void func_00229088(s32 a0) {
    u8 *e[2];
    u8 *p;
    u16 v;
    if (func_001F42B8(a0)) {
        if ((e[0] = func_001F3A20(D_003F6CE0, 6)) != NULL) {
            func_001F4690(e[0], (u8 *)a0);
            p = e[0];
            v = D_00643730;
            *(u16 *)(p + 0xCE) = v;
            *(u16 *)(p + 0xCC) = v;
            *(s16 *)(p + 0xD2) = *(u16 *)&D_006436D0 * 16;
            if ((e[1] = func_001F3A20(D_003F6CA0, 6)) != NULL) {
                func_001F4690(e[1], e[0]);
                func_001F3DC0(e[0]);
            }
        }
    }
    func_00207830(a0, 4, 2, 0, 0, 0x7A, 0x70);
}

extern u8 D_003F6D68[];
s32 func_0010FB68(void);
void func_0020B3D8(s32, s32, s32);

void func_00229150(s32 a0) {
    func_00205E30(a0, D_003F6D68);
    func_00206130(a0, 0, 0x3E, 0x200, 2, 0x8078C850);
    func_0020CA30(a0, 0, 0x80283212, 0x8050C846);
    func_001FC308(a0, 0xA0, 0x23, 0, 0x13, 0x14, 0, 0x80399BFF, 0x80399BFF);
    func_001F9E48(a0, 0, 0xAD, 0x23, func_0010FB68(), 0x13, 0x80399BFF);
    func_0020B3D8(a0, 0x191, 4);
}

void func_00229220(s32 a0) {
    func_00205E30(a0, D_003F6DA8);
    func_00206130(a0, 0, 0, 0x200, 0x2, 0x8078C850);
    func_0020CCB0(a0);
    func_001FC308(a0, 0xA0, 0xC, 0, 0x3F, 0x14, 0, 0x4078C850, 0x4078C850);
}

void func_002292A8(u8 *a0) {
    s32 v = *(s32 *)(a0 + 0x90);
    func_0020B120(0x2, v, 0x80080808, 0x80080808, 0x80080808, 0x80080808);
    func_0020B120(0x1, v, 0x80101010, 0x80101010, 0x80101010, 0x80101010);
    func_0020B120(0x2, v, 0x80080808, 0x80080808, 0x80080808, 0x80080808);
    func_0020A9B0(v);
    func_0020AB88(v);
}

void UiObject_InsertAfter(u8 *, u8 *);
u8 *func_00229338(u8 *a0) {
    u8 *o[3];
    s32 i;
    u8 *last = a0;

    for (i = 0; i < 3; i++) {
        o[i] = func_001F3A20(D_003F6E18[i], 1);
        if (o[i] != NULL) {
            UiObject_InsertAfter(o[i], last);
            func_001F3D58(o[i], D_003F3488[i]);
            last = o[i];
        }
    }
    return last;
}

extern u8 *D_00643718;
void func_002293F0(u8 *a0) {
    u8 *e[2];
    u8 *p;
    u16 v;
    if ((e[0] = func_001F3A20(D_003F6CE0, 6)) != NULL) {
        func_001F4690(e[0], (u8 *)a0);
        p = e[0];
        v = D_00643730;
        *(u16 *)(p + 0xCE) = v;
        *(u16 *)(p + 0xCC) = v;
        *(s16 *)(p + 0xD2) = *(u16 *)&D_006436D0 * 16;
        if ((e[1] = func_001F3A20(D_003F6CA0, 6)) != NULL) {
            func_001F4690(e[1], e[0]);
            func_001F3DC0(e[0]);
        }
    }
    D_00643718 = a0;
}

void func_00229490(u8 *a0) {
    u8 *e[3];
    s32 i;
    for (i = 0; i < 3; i++) {
        e[i] = func_001F3A20(D_003F6E18[i], D_003F3468[i]);
        if (e[i] != NULL) {
            func_001F4690(e[i], a0);
            func_001F3D58(e[i], D_003F3488[i]);
            a0 = e[i];
        }
    }
    e[0] = func_001F3A20(D_003F6D40, 0x4);
    if (e[0] != NULL) {
        func_001F4690(e[0], a0);
        func_002293F0(e[0]);
    }
    func_0020BB90(0x85, 0);
    func_0020BD18((s32)e[0], 0x8);
    func_0020BDA8(0x10);
}

extern s32 D_003F34A8;
extern s32 D_003F34C4;
extern s32 D_003F6E24;
extern s32 D_003F6E2C;
extern s32 D_00643730_w __asm__("D_00643730");
void func_0020D530(void);
s32 func_0020D030_r(void) __asm__("func_0020D030");
s32 func_0020D2F8(void);
void func_00229490(u8 *a0);

void func_002295A0(s32 a0, s32 a1) {
    s32 e;
    func_001F3110(a0);
    D_003F34A8 = 1;
    func_0020D530();
    D_003F6E24 = 1;
    D_003F6E2C = a1;
    if (a1 != 1) {
        D_00643720[1] = 1;
        D_00643720[2] = 2;
        D_00643720[0] = 0;
        D_00643720[3] = 3;
        D_00643730_w = 4;
    } else {
        D_00643730_w = 3;
        D_00643720[1] = a1;
        D_00643720[2] = 3;
        D_00643720[0] = 0;
    }
    func_0011D598(6);
    e = func_0020D030_r();
    D_003F34C4 = e;
    if (e != 0) func_00229490((u8 *)e);
    *(s16 *)((u8 *)func_0011ED30(0x270FF, func_0020D2F8) + 2) = a0;
}

void func_00229690(u8 *a0) {
    u8 *e[3];
    s32 i;
    for (i = 0; i < 3; i++) {
        e[i] = func_001F3A20(D_003F6E18[i], D_003F3468[i]);
        if (e[i] != NULL) {
            func_001F4690(e[i], a0);
            func_001F3D58(e[i], D_003F3488[i]);
            a0 = e[i];
        }
    }
    e[0] = func_001F3A20(D_003F6D10, 0x4);
    if (e[0] != NULL) {
        func_001F4690(e[0], a0);
        func_00228E70(e[0]);
    }
    func_0020BB90(0x85, 0);
    func_0020BD18((s32)e[0], 0x8);
    func_0020BDA8(0x10);
}

extern s32 D_003F34A8;
extern s32 D_003F34C4;
void func_0020D530(void);
s32 func_0020D030_r(void) __asm__("func_0020D030");
s32 func_0020D2F8(void);

void func_002297A0(s32 a0) {
    s32 e;
    func_001F3110(a0);
    D_003F34A8 = 2;
    func_0020D530();
    D_00643708 = 0;
    func_0011D598(6);
    e = func_0020D030_r();
    D_003F34C4 = e;
    if (e != 0) func_00229690((u8 *)e);
    *(s16 *)((u8 *)func_0011ED30(0x270FF, func_0020D2F8) + 2) = a0;
}

void func_00229820(void) {
    D_00643798 = 0;
    D_003F6E30 = 0;
    D_003F0DD8 = 0;
    D_006436D0 = 0;
    D_00643708 = 0;
}

extern s32 D_006436D8[];
extern s32 D_006436E0[];
extern s32 D_006436E8;
extern s32 D_006436EC;
extern s32 D_0064370C;
extern s32 D_003F6E24;
void func_00229850(void) {
    D_006436D0 = 0;
    D_006436D4 = 0;
    D_006436D8[0] = 0;
    D_006436D8[1] = 0;
    D_006436E0[0] = 0;
    D_006436E0[1] = 0;
    D_006436E8 = 0;
    D_006436EC = 0;
    D_006436F0 = 0;
    D_006436F8[0] = 0;
    D_006436F8[1] = 0;
    D_00643700[0] = 0;
    D_00643700[1] = 0;
    D_00643708 = 0;
    D_0064370C = 0;
    D_003F6E24 = 0;
    D_003F0DD8 = 0;
}
