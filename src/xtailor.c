#include "common.h"
#include "xtailor.h"
#include "xblade.h"
#include "xpeanut.h"

#include "libgraph.h"
#include "libvu0.h"
#include "sdk/libcdvd.h"

extern u64 D_002BC918;
extern s32 D_002BC980;

extern s32 D_002BBD48[];
extern s32 D_002BBD90[];

extern s32 D_004D6B20[];

extern s32 D_002A30D0;
extern s32 D_002B8170;
extern s32 D_002B8240;
extern s32 D_002B8280;
extern sceVu0FMATRIX D_002B8370;
extern sceVu0FMATRIX D_002B83B0;
extern sceVu0FMATRIX D_002B83F0;
extern sceVu0FMATRIX D_002B8430;
extern sceVu0FMATRIX D_002B8470;
extern sceVu0FMATRIX D_002B84B0;
extern sceVu0FMATRIX D_002B84F0;
extern sceVu0FMATRIX D_002B8530;
extern sceVu0FMATRIX D_002B8570;
extern s32 D_002B85C0[4];
extern s32 D_002B8210;
extern s32 D_002B8678;
extern s32 D_002B8680;

extern s32 D_002B9030;
extern s32 D_002B9084;
extern f32 D_002B9090[4];
extern s32 D_002B90A0[3];

extern char D_00486C40[];
extern char D_00486C50[];
extern char D_00486C60[];

extern s32 D_004CF580;
extern s32 D_004CF588;
extern s32 D_004CF58C;
extern s32 D_004CF590;
extern s32 D_004D0590;
extern sceVu0FMATRIX D_004D2590;
extern sceVu0FMATRIX D_004D25D0;
extern sceGsDispEnv D_004D2610;
extern s32 D_004D284C;
extern sceVu0FMATRIX D_004D2850;
extern sceVu0FMATRIX D_004D2890;
extern sceVu0FMATRIX D_004D28D0;
extern sceVu0FMATRIX D_004D2910;
extern sceVu0FMATRIX D_004D2950;
extern s32 D_004D2990;
extern s32 D_004D2994;

extern s32 func_F20000();
void func_00110F88(s32);

void func_0010F3D0(void) {
    func_00106948(&D_002B8170);
    sceGsSyncPath(0, 0);
}

void func_0010F3F8(void) {
    func_00106948(&D_002B8240);
    sceGsSyncPath(0, 0);
}

void func_0010F420(void) {
    func_00106948(&D_002B8280);
    sceGsSyncPath(0, 0);
}

#define DISPWIDTH 640

void func_0010F448(void) {
    sceGsSyncPath(0, 0);
    DPUT_GS_PMODE(SCE_GS_SET_PMODE(1, 1, 0, 0, 0, 0, 0xFF));
    DPUT_GS_DISPFB1(SCE_GS_SET_DISPFB1(0xD8000 / 2048, 512 / 64, SCE_GS_PSMCT32, 0, 0));
    DPUT_GS_DISPLAY1(SCE_GS_SET_DISPLAY1(0, 160, 4, 0, (DISPWIDTH * 4) - 1, 128 - 1));
}

#ifdef VERSION_FM
extern s32 D_002BBCC0;
extern s32 D_004D5B0C;
void func_001FD100(s32, s32);
void func_001F1ED8(s32, s32, s32, s32, s32);
void func_00207748(s32, s32, s32, s32);
void func_0010F4A8(u32 arg0) {
    if ((D_002C1EB8.u8 >> 3 & 3) == 0) {
        if (arg0 == 0) {
            sceGsSyncPath(0, 0);
            func_001102C0();
            DPUT_GS_PMODE(0x22);
        } else {
            sceGsSyncPath(0, 0);
            func_001102C0();
            if (arg0 & 4) {
                func_0010F3D0();
                func_00106948(&D_002BBCC0);
                if (D_004D5B0C == 0) {
                    func_001FD100(76, 11);
                    func_001F1ED8(0x64FFFFFF, 118, 16, func_001F0EF0(3), 15);
                    func_00207748(1, 351, 92, 90);
                } else {
                    func_001FD100(84, 30);
                    func_001F1ED8(0x64FFFFFF, 126, 39, func_001F0EF0(4), 15);
                    func_00207748(1, 351, 70, 90);
                }
                func_0010F3F8();
                func_00106948(&D_002BBCC0);
                func_0010F420();
                func_0010F448();
                return;
            }
            if (arg0 & 2) {
                func_0010F3D0();
                func_00106948(&D_002BBCC0);
                func_001FD100(96, 30);
                func_001F1ED8(0x64FFFFFF, 138, 39, func_001F0EF0(2), 15);
                func_0010F3F8();
                func_00106948(&D_002BBCC0);
                func_0010F420();
                func_0010F448();
                return;
            }
            if (arg0 & 1) {
                func_0010F3D0();
                func_00106948(&D_002BBCC0);
                func_001FD100(84, 30);
                func_001F1ED8(0x64FFFFFF, 126, 39, func_001F0EF0(1), 15);
                func_0010F3F8();
                func_00106948(&D_002BBCC0);
                func_0010F420();
                func_0010F448();
                return;
            }
        }
    }
}
#else
void func_0010F4A8(u32 arg0) {
    if ((D_002C1EB8.u8 >> 3 & 3) == 0) {
        if (arg0 == 0) {
            sceGsSyncPath(0, 0);
            func_001102C0();
            DPUT_GS_PMODE(0x22);
        } else {
            sceGsSyncPath(0, 0);
            func_001102C0();
            if (arg0 & 4) {
                func_0010F3D0();
                func_00106948(&D_002B8210);
                if (D_004CF58C == 0) {
                    func_001FD4C0(76, 11);
                    func_001F2EF8(0x64FFFFFF, 118, 16, func_001F0EF0(3), 15);
                    func_00207640(1, 351, 92, 90);
                } else {
                    func_001FD4C0(84, 30);
                    func_001F2EF8(0x64FFFFFF, 126, 39, func_001F0EF0(4), 15);
                    func_00207640(1, 351, 70, 90);
                }
                func_0010F3F8();
                func_00106948(&D_002B8210);
                func_0010F420();
                func_0010F448();
                return;
            }
            if (arg0 & 2) {
                func_0010F3D0();
                func_00106948(&D_002B8210);
                func_001FD4C0(104, 30);
                func_001F2EF8(0x64FFFFFF, 146, 39, func_001F0EF0(2), 15);
                func_0010F3F8();
                func_00106948(&D_002B8210);
                func_0010F420();
                func_0010F448();
                return;
            }
            if (arg0 & 1) {
                func_0010F3D0();
                func_00106948(&D_002B8210);
                func_001FD4C0(84, 30);
                func_001F2EF8(0x64FFFFFF, 126, 39, func_001F0EF0(1), 15);
                func_0010F3F8();
                func_00106948(&D_002B8210);
                func_0010F420();
                func_0010F448();
                return;
            }
        }
    }
}
#endif

s32 func_0010F6F0(void) {
    D_004CF580 = D_002C1EB8.s32;
}

void func_0010F708(void) {
    D_004CF588 = D_002C1EB8.s32;
}

void func_0010F720(u32 arg0) {
    func_0010F4A8(arg0);
    if (func_00110EA8() != 0) {
        func_00110F88(arg0);
    }
}

INCLUDE_ASM("asm/nonmatchings/xtailor", func_0010F768);

void func_0010FA30(s32* arg0) {
    s32* p = arg0 + 4;
    s32 i;

    for (i = 0; i < 17; i++) {
        D_002BBD48[i] = (s32)arg0 + p[0];
        D_002BBD90[i] = p[1];
        p += 2;
    }
}

void func_0010FA88(void) {
    void* src = func_00155ED8(0x34, 0xC);
    s32 size = func_00120438("allset.set", src);
    memcpy(&D_004CF590, src, size);
    func_0010FA30(&D_004CF590);
}

void func_0010FAE8(void) {
    void* src = func_00155ED8(0x34, 0xC);
    s32 size = func_00120438("allarea.nam", src);
    memcpy(&D_004D0590, src, size);
}

void* func_0010FB38(s32 arg0, s32 arg1) {
    u8* p = (u8*)&D_004D0590 + D_004D6B20[arg0 * 2];
    s32* q = (s32*)(p + 0x10);

    return p + q[arg1 * 2];
}

void* func_0010FB68(void) {
    return func_0010FB38(D_002B8678, D_002B8680);
}

#ifdef VERSION_FM
typedef struct {
    u64 unk_00[14];
} XTailorSave;
extern XTailorSave D_002BCA00[2];
extern XTailorSave D_002C5AD0[2];
void func_0011F4B8(void);
void func_001BA4A8(void);

void func_0010FB90(void) {
    s32 i;

    func_0010F6F0();
    if (D_004D2990) {
        for (i = 0; i < 2; i++) {
            D_002C5AD0[i] = D_002BCA00[i];
        }
    }
    func_0011F4B8();
    for (i = 0; i < 2; i++) {
        D_002BCA00[i] = D_002C5AD0[i];
    }
    if (D_004D2990 != 0) {
        func_001BA4A8();
    }
}

#else
INCLUDE_ASM("asm/nonmatchings/xtailor", func_0010FB90);
#endif

void func_0010FCD0(void) {
    D_004D2990 = 0;
}

void func_0010FCE0(void) {
    D_004D2990 = 1;
}

extern f32 D_002BBDEC;
extern volatile u32 D_004D90F0;

void func_0010FCF0(void) {
    if (D_002BBDEC == 1.0f) {
        D_004D90F0 = 0x14996C4;
    } else {
        D_004D90F0 = 0x112A84E;
    }
}

void func_0010FD40(s16 w, s16 h) {
    D_004D284C = 0;
    sceGsSetDefDispEnv(&D_004D2610, 1, w, h, 0, 0);
    D_004D2610.dispfb.FBP &= 0xFFFFFE00;
    FlushCache(WRITEBACK_DCACHE);
    sceGsSyncPath(0, 0);
    sceGsPutDispEnv(&D_004D2610);
}

void func_0010FDB8(s32 arg0) {
    D_002BC918 = SCE_GS_SET_RGBAQ(arg0, arg0, arg0, 0x80, 1);
    func_00106948(&D_002BC980);
    func_0010FD40(0x200, 0x1BF);
}

void func_0010FE10(u32* x, u32* y) {
    *x = D_004D2610.display.DX;
    *y = D_004D2610.display.DY;
}

void func_0010FE38(void) {
    sceGsResetGraph(1, 1, 2, 0);
    DPUT_GS_EXTWRITE(0);
    sceGsPutDispEnv(&D_004D2610);
}

void func_0010FE78(s32 x, s32 y) {
    D_004D2610.display.DX = x;
    D_004D2610.display.DY = y;
    D_004D284C = 1;
}

#ifdef VERSION_FM
extern f32 D_002BBDEC;
int sceDmaReset(int mode);
void func_0010FCF0(void);

void fm_func_00110068(void) {
    sceGsResetPath();
    sceDmaReset(1);
    sceVpu0Reset();
    D_002BBDEC = 1.0f;
    func_0010FCF0();
}
#endif

#ifdef VERSION_FM
typedef struct {
    sceGifTag tag;
    u64 a[13][2];
    u64 b[13][2];
    u64 c[5][2];
} XTailorDrawEnv;
extern XTailorDrawEnv D_004D8EF0;
extern u64 D_002BC750[13];
extern u64 D_002BC7C0[13];
extern u64 D_002BC830[13];

void func_0010FEC0(void) {
    s32 i;

    for (i = 0; i < 13; i++) {
        D_004D8EF0.a[i][0] = D_002BC830[i];
        D_004D8EF0.a[i][1] = D_002BC750[i];
        D_004D8EF0.b[i][0] = D_002BC830[i];
        D_004D8EF0.b[i][1] = D_002BC7C0[i];
    }
    SCE_GIF_CLEAR_TAG(&D_004D8EF0.tag);
    D_004D8EF0.tag.NLOOP = 31;
    D_004D8EF0.tag.EOP = 1;
    D_004D8EF0.tag.NREG = 1;
    D_004D8EF0.tag.REGS0 = 0xE;
    D_004D8EF0.c[0][0] = 1;
    D_004D8EF0.c[0][1] = 0x1A;
    D_004D8EF0.c[1][0] = 1;
    D_004D8EF0.c[1][1] = 0x46;
    D_004D8EF0.c[2][0] = 0;
    D_004D8EF0.c[2][1] = 0x45;
    D_004D8EF0.c[3][0] = 0;
    D_004D8EF0.c[3][1] = 0x49;
    D_004D8EF0.c[4][0] = -4;
    D_004D8EF0.c[4][1] = 0x44;
    FlushCache(0);
    sceGsSyncPath(0, 0);
    sceGsPutDrawEnv(&D_004D8EF0.tag);
}

#else
INCLUDE_ASM("asm/nonmatchings/xtailor", func_0010FEC0);
#endif

#ifdef VERSION_FM
void fm_func_001101E8(void) {
    sceGsResetGraph(0, 1, 2, 0);
    func_001102A0();
    func_0010FEC0();
}
#endif

#ifdef VERSION_FM
extern s32 D_002BBDE8;
extern volatile s32 D_002B9664;
extern s32 D_002B9174;
extern volatile s32 D_002BBDF0;
extern volatile u32 D_002BBDF4;
extern volatile u32 D_004D90F0;
extern volatile s32 D_002B8340;
extern volatile s32 D_004D90F4;
s32 func_001115A0(void);
void func_001115C0(void);
void func_0010C110(void);

s32 func_00110038(s32 arg0) {
    if (DGET_GS_CSR() & 0x2000) {
        D_002BBDE8 = 1;
    } else {
        D_002BBDE8 = 0;
    }
    if (D_002B9664 == 0 && D_002B9174 == 0) {
        D_002BBDF0++;
    }
    if (D_002BBDF4 < D_004D90F0) {
        D_002BBDF4++;
    } else if (func_001115A0() < 3) {
        if (D_004D90F0 + 60 > D_002BBDF4) {
            D_002BBDF4++;
        } else {
            func_001115C0();
            D_002BBDF4 = 0;
        }
    } else {
        D_002BBDF4 = D_004D90F0;
    }
    D_002B8340++;
    /* volatile read, plain store (the store sits in the jal delay slot) */
    *(s32*)&D_004D90F4 = D_004D90F4 + 1;
    func_0010C110();
    return 0;
}

#else
INCLUDE_ASM("asm/nonmatchings/xtailor", func_00110038);
s32 func_00110038(s32);
#endif

void func_00110150(void) {
    D_002B85C0[3] = 128;
    D_002B85C0[2] = 128;
    D_002B85C0[1] = 128;
    D_002B85C0[0] = 128;
}

void func_00110170(void) {
    D_002B85C0[3] = 0;
    D_002B85C0[2] = 0;
    D_002B85C0[1] = 0;
    D_002B85C0[0] = 0;
}

#ifdef VERSION_FM
extern s32 D_002B834C;
extern s32 D_002BBE14;
extern s32 D_002BBE18;
extern s32 D_002A6208;
extern s32 D_002A2740;
extern s32 D_002B8C88;
extern s32 D_002A6204;
extern s32 D_002A61F0;
extern s32 D_002BC060[4];
extern s32 D_002BC080[4];
extern s32 D_002BC0B0[4];

void func_00110190(void) {
    D_002B834C = 0;
    D_002BBE14 = 0;
    D_002BBE18 = 0;
    D_002A6208 = 0;
    D_002A2740 = 0;
    D_002B8C88 = 0;
    D_002A6204 = 0;
    D_002A61F0 = 0;
    D_002BC060[2] = 0;
    D_002BC060[1] = 0;
    D_002BC060[0] = 0;
    D_002BC060[3] = 0x80;
    D_002BC080[2] = 0x80;
    D_002BC080[1] = 0x80;
    D_002BC080[0] = 0x80;
    D_002BC080[3] = 0x60;
    D_002BC0B0[2] = 0xFF;
    D_002BC0B0[1] = 0xFF;
    D_002BC0B0[0] = 0xFF;
    D_002BC0B0[3] = 0;
    func_00110150();
}

#else
INCLUDE_ASM("asm/nonmatchings/xtailor", func_00110190);
#endif

void func_00110230(s32 a0) {
    D_002BBDF4 = a0;
}

extern f32 D_002B8344;
extern s32 D_002B8354;
extern s32 D_002BBE10;
extern sceVu0FMATRIX D_002B9040;
extern s32 D_002B2CC4;
extern s32 D_002B9660;

void func_00110240(void) {
    D_002BBDF0 = 0;
    D_002B8340 = 0;
    D_002BBE10 = 0;
    D_002B8354 = 0;
    D_002B8344 = D_002BBDEC;
    sceVu0UnitMatrix(D_002B9040);
    D_002B2CC4 = 0;
    D_002B9660 = 0;
}

void func_001102A0(void) {
    sceGsSyncVCallback(func_00110038);
}

#ifdef VERSION_FM
extern volatile s32 D_004D90F4;
extern f32 D_002B8344;
extern f32 D_002B8348;
extern s32 D_002B8354;
extern s32 D_002BBE10;
extern s32 D_002B8C90;
void func_0010C0E0(void);

void func_001102C0(void) {
    s32 i;

    func_0010C0E0();
    D_002B8344 = D_004D90F4 * D_002BBDEC;
    if (D_004D90F4 < D_002B8354 + 1) {
        for (i = 0; i < D_002B8354; i++) {
            func_0010C0E0();
            D_002B8344 = D_004D90F4 * D_002BBDEC;
        }
    }
    if (D_002BBE10 != 0) {
        D_002B8344 = D_002BBDEC + D_002BBDEC;
    }
    D_002B8344 *= D_002B8348;
    if (D_002B8C90 != 1) {
        if (D_002B8344 > 5.0f) {
            D_002B8344 = 5.0f;
        }
    } else {
        D_002B8344 = 128.0f;
    }
    D_004D90F4 = 0;
}

#else
INCLUDE_ASM("asm/nonmatchings/xtailor", func_001102C0);
#endif

INCLUDE_ASM("asm/nonmatchings/xtailor", func_00110410);

#ifdef VERSION_FM
extern f32 D_004D90F8;
void func_00110AE0(void);
void func_00110410(sceVu0FMATRIX, sceVu0FMATRIX, sceVu0FMATRIX, sceVu0FMATRIX, sceVu0FMATRIX, sceVu0FMATRIX, f32, f32,
                   f32, f32, f32, f32, f32, f32, f32, f32);

void func_00110848(f32 arg0) {
    func_00110AE0();
    sceVu0CopyMatrix(D_004D2590, D_002B8370);
    sceVu0CopyMatrix(D_004D2850, D_002B83B0);
    sceVu0CopyMatrix(D_004D2890, D_002B83F0);
    sceVu0CopyMatrix(D_004D28D0, D_002B8430);
    sceVu0CopyMatrix(D_004D2910, D_002B8470);
    sceVu0CopyMatrix(D_004D25D0, D_002B84B0);
    func_00110410(D_002B8370, D_002B83B0, D_002B83F0, D_002B8430, D_002B8470, D_002B84B0, arg0, 0.79999996f,
                  0.8399998546f, 2048.0f, 2048.0f, 1.0f, 16777000.0f, 1.0f, 400000000.0f, D_004D90F8);
}

#else
INCLUDE_ASM("asm/nonmatchings/xtailor", func_00110848);
#endif

void func_001109A8(void) {
    sceVu0CopyMatrix(D_004D2950, D_002B84F0);
    sceVu0MulMatrix(D_002B84F0, D_002B83B0, D_002DEC60);
    sceVu0MulMatrix(D_002B8530, D_002B8430, D_002DEC60);
    sceVu0MulMatrix(D_002B8570, D_002B8470, D_002DEC60);
}

void func_00110A30(void) {
    sceVu0CopyMatrix(D_002B8370, D_004D2590);
    sceVu0CopyMatrix(D_002B83B0, D_004D2850);
    sceVu0CopyMatrix(D_002B83F0, D_004D2890);
    sceVu0CopyMatrix(D_002B8430, D_004D28D0);
    sceVu0CopyMatrix(D_002B8470, D_004D2910);
    sceVu0CopyMatrix(D_002B84B0, D_004D25D0);
    sceVu0MulMatrix(D_002B84F0, D_002B83B0, D_002DEC60);
}

INCLUDE_ASM("asm/nonmatchings/xtailor", func_00110AE0);

void func_00110C40(f32 arg0, f32 arg1, f32 arg2, f32 arg3) {
    D_002B9090[0] = arg0;
    D_002B9090[1] = arg1;
    D_002B9090[2] = arg2;
    D_002B9090[3] = arg3;
    D_002B90A0[0] = 0;
    D_002B90A0[1] = 0;
    D_002B90A0[2] = 0;
}

#ifdef VERSION_FM
extern sceVu0FVECTOR D_002BC190;
void func_00176110(f32*);
void func_00176150(f32*);

void func_00110C70(sceVu0FVECTOR arg0) {
    register s32 i asm("$18");
    f32* ang;
    f32* v = D_002BC190;
    register f32* s asm("$17");

    sceVu0CopyVector(v, arg0);
    if (D_002B9090[3] != 1.0f) {
        ang = (f32*)D_002B90A0;
        for (i = 0; i < 3; i++) {
            ang[i] += D_002B9090[3];
            if (ang[i] > 3.1415928f) {
                ang[i] -= 6.28318548203f;
            }
            if (ang[i] < -3.1415928f) {
                ang[i] += 6.28318548203f;
            }
            s = &D_002B9090[i];
            *v *= *s + (1.0f - *s) * cosf(ang[i]);
            v++;
        }
    }
    func_00176110(arg0);
    func_00176150(arg0);
}
#else
INCLUDE_ASM("asm/nonmatchings/xtailor", func_00110C70);
#endif

void func_00110DE0() {
    D_002B9030 = 1;
    FlushCache(2);
    func_F20000(0, D_004D2994);
}

void func_00110E18(void) {
    D_002A30D0 = 0;
    D_002B9030 = 0;
    D_002B9084 = 0;
}

s32 func_00110E38(s32 arg0) {
    D_002B9030 = 0;
    D_004D2994 = arg0;
    return func_00120590("dkmovie.x", &func_F20000, func_00110DE0, NULL);
}

void func_00110E78(void) {
    func_00113A40(2);
    func_001EEC00(0x7B);
    func_F20000(1, 0);
}

s32 func_00110EA8(void) {
    if (D_002B9030 == 0) {
        return 0;
    }
    return func_F20000(2, 0);
}

#ifndef VERSION_FM
INCLUDE_ASM("asm/nonmatchings/xtailor", func_00110ED8);
#endif

void func_00110EE8(void) {
    func_F20000(3, 0);
}

void func_00110F08(void) {
    func_F20000(8, 0);
}

void func_00110F28(void) {
    func_F20000(9, 0);
}

void func_00110F48(void) {
    func_F20000(4, 0);
}

void func_00110F68(void) {
    func_F20000(5, 0);
}

void func_00110F88(s32 arg0) {
    func_F20000(6, arg0);
}

void func_00110FA8(void) {
    func_F20000(7, 0);
}

#ifdef VERSION_FM
extern volatile s32 D_002BBDE0;
extern s32 D_002A3F44;
extern s32 D_002B834C;
extern s32 D_002BBE18;
void func_001016B8(void);
s32 func_001EEC00(s32);
void func_00114430(void);
void func_00113A40(s32);

void func_00110FC8(void) {
    if (D_002BBDE0 == 3 && D_002A3F44 == 1) {
        D_002A3F44 = 0;
        func_001016B8();
    }
    func_001EEC00(9);
    func_00114430();
    D_002B834C = 3;
    D_002BBE18 = 0;
    func_00110F48();
    D_002B9030 = 0;
    D_002B9084 = 1;
    func_00113A40(0);
}
#else
INCLUDE_ASM("asm/nonmatchings/xtailor", func_00110FC8);
#endif

void func_00111050(void) {
    sceCdRead(0, 0, NULL, NULL);
    func_00247CD8();
    sceCdStatus();
    sceCdBreak();
    sceCdGetError();
    sceIpuInit();
    sceIpuSync();
}
