#include "common.h"
#include "libvu0.h"

typedef struct {
    /* 0x00*/ char unk_00[0x4];
    /* 0x04*/ s32 unk_04;
    /* 0x08*/ char unk_08[0x4];
    /* 0x0C*/ s32 unk_0C;
    /* 0x10*/ char unk_10[0xC];
    /* 0x1C*/ f32 unk_1C[4];
    /* 0x2C*/ f32 unk_2C[3];
    /* 0x38*/ f32 unk_38[3];
    /* 0x44*/ f32 unk_44;
    /* 0x48*/ char unk_48[0x4];
    /* 0x4C*/ u16 unk_4C;
    /* 0x4E*/ u16 unk_4E;
    /* 0x50*/ char unk_50[0x4];
    /* 0x54*/ s8 unk_54;
    /* 0x55*/ char unk_55[0x3];
    /* 0x58*/ u8 unk_58;
    /* 0x59*/ u8 unk_59;
    /* 0x5A*/ u8 unk_5A;
    /* 0x5B*/ char unk_5B[0x3];
    /* 0x5E*/ u8 unk_5E;
    /* 0x5F*/ u8 unk_5F;
} XToast;

typedef struct XToaster148 {
    /* 0x000 */ char unk_000[0x90];
    /* 0x090 */ s32 unk_090;
    /* 0x094 */ char unk_094[0x4C];
    /* 0x0E0 */ f32 unk_0E0;
    /* 0x0E4 */ char unk_0E4[0x70];
    /* 0x154 */ s32 unk_154;
    /* 0x158 */ char unk_158[0x8];
    /* 0x160 */ sceVu0FVECTOR unk_160;
    /* 0x170 */ char unk_170[0x10];
} XToaster148; /* size = 0x180 */

typedef struct XToaster {
    /* 0x000 */ s32 unk_000;
    /* 0x004 */ char unk_004[0x2];
    /* 0x006 */ u8 unk_006;
    /* 0x007 */ char unk_007[0x9];
    /* 0x010 */ sceVu0FVECTOR unk_010;
    /* 0x020 */ sceVu0FVECTOR unk_020;
    /* 0x030 */ sceVu0FVECTOR unk_030;
    /* 0x040 */ sceVu0FVECTOR unk_040;
    /* 0x050 */ sceVu0FVECTOR unk_050;
    /* 0x060 */ char unk_060[0xC];
    /* 0x06C */ u8* unk_06C;
    /* 0x070 */ char unk_070[0x4];
    /* 0x074 */ struct XToaster* unk_074;
    /* 0x078 */ s32 unk_078;
    /* 0x07C */ char unk_07C[0x4];
    /* 0x080 */ s32 unk_080;
    /* 0x084 */ char unk_084[0x4];
    /* 0x088 */ s32 unk_088;
    /* 0x08C */ char unk_08C[0xC];
    /* 0x098 */ s32 unk_098;
    /* 0x09C */ char unk_09C[0x24];
    /* 0x0C0 */ s32 unk_0C0;
    /* 0x0C4 */ f32 unk_0C4;
    /* 0x0C8 */ s32 unk_0C8;
    /* 0x0CC */ f32 unk_0CC;
    /* 0x0D0 */ char unk_0D0[0x50];
    /* 0x120 */ sceVu0FVECTOR unk_120;
    /* 0x130 */ XToast* unk_130;
    /* 0x134 */ u8* unk_134;
    /* 0x138 */ s32 unk_138;
    /* 0x13C */ char unk_13C[0x8];
    /* 0x144 */ s32 unk_144;
    /* 0x148 */ struct XToaster148* unk_148;
    /* 0x14C */ s32 unk_14C;
    /* 0x150 */ s32 unk_150;
    /* 0x154 */ s32 unk_154;
    /* 0x158 */ char unk_158[0x8];
    /* 0x160 */ u64 unk_160;
    /* 0x168 */ char unk_168[0x64];
    /* 0x1CC */ s32 unk_1CC;
    /* 0x1D0 */ s32 unk_1D0;
    /* 0x1D4 */ char unk_1D4[0xB0];
    /* 0x284 */ f32 unk_284;
    /* 0x288 */ char unk_288[0x18];
    /* 0x2A0 */ sceVu0FVECTOR unk_2A0;
    /* 0x2B0 */ char unk_2B0[0xA0];
    /* 0x350 */ s32 unk_350[4];
    /* 0x360 */ char unk_360[0x10];
    /* 0x370 */ u32 unk_370; /* low half of the u64 flags (XT_FLAGS) */
    /* 0x374 */ s32 unk_374;
    /* 0x378 */ s32 unk_378;
    /* 0x37C */ s32 unk_37C[3];
    /* 0x388 */ s32 unk_388;
    /* 0x38C */ char unk_38C[0x12];
    /* 0x39E */ u8 unk_39E;
    /* 0x39F */ char unk_39F[0x1];
    /* 0x3A0 */ s32 unk_3A0;
    /* 0x3A4 */ char unk_3A4[0x4];
    /* 0x3A8 */ s32 unk_3A8;
    /* 0x3AC */ char unk_3AC[0x4];
    /* 0x3B0 */ s32 unk_3B0;
    /* 0x3B4 */ f32 unk_3B4;
    /* 0x3B8 */ s32 unk_3B8;
    /* 0x3BC */ s32 unk_3BC;
    /* 0x3C0 */ sceVu0FVECTOR unk_3C0;
    /* 0x3D0 */ char unk_3D0[0x40];
    /* 0x410 */ f32 unk_410;
    /* 0x414 */ f32 unk_414;
    /* 0x418 */ char unk_418[0x28];
    /* 0x440 */ u64 unk_440;
    /* 0x448 */ char unk_448[0x8];
    /* 0x450 */ s32 unk_450;
    /* 0x454 */ s32 unk_454;
    /* 0x458 */ f32 unk_458;
    /* 0x45C */ char unk_45C[0x14];
    /* 0x470 */ s32 unk_470;
    /* 0x474 */ s32 unk_474;
    /* 0x478 */ char unk_478[0x8];
    /* 0x480 */ f32 unk_480;
    /* 0x484 */ char unk_484[0x28];
    /* 0x4AC */ f32 unk_4AC;
} XToaster; /* size = 0x4B0 */

extern XToaster D_002C64A0[];
extern XToaster D_002E26A0[];

void func_00123AB8(XToaster* arg0);
XToaster* func_00123880(s32 arg0);
void func_00123C90(XToaster* arg0, s32 arg1);
void func_00124BC8(XToaster* arg0);
XToaster* func_001234A0(XToaster* arg0);
s32 func_00123768(XToaster* arg0);
void func_00124CD8(void);
void func_00136D38(XToaster* arg0);
void func_00162110(s32 arg0, void* arg1);
void func_00149860(XToaster* arg0);
void func_00123B20(XToaster* arg0);

#define XT_FLAGS(p) (*(u64*)&(p)->unk_370)
/* 3 XToaster* slots at 0x2E26A0 (right after the XToaster array) */
#define XT_SLOTS ((XToaster**)D_002E26A0)

INCLUDE_RODATA("asm/nonmatchings/xtoaster", D_00487018);

INCLUDE_RODATA("asm/nonmatchings/xtoaster", D_00487020);

INCLUDE_RODATA("asm/nonmatchings/xtoaster", D_00487028);

INCLUDE_RODATA("asm/nonmatchings/xtoaster", D_00487030);

INCLUDE_RODATA("asm/nonmatchings/xtoaster", D_00487038);

INCLUDE_RODATA("asm/nonmatchings/xtoaster", D_00487040);

INCLUDE_RODATA("asm/nonmatchings/xtoaster", D_00487048);

INCLUDE_RODATA("asm/nonmatchings/xtoaster", D_00487050);

INCLUDE_RODATA("asm/nonmatchings/xtoaster", D_00487058);

INCLUDE_RODATA("asm/nonmatchings/xtoaster", D_00487060);

INCLUDE_RODATA("asm/nonmatchings/xtoaster", D_00487068);

int sprintf(char*, const char*, ...);
int strlen(const char*);
XToast* func_001320A8(s32);
extern char D_00487018[];
extern char D_00487020[];
extern char D_00487028[];
extern char* D_002C6460[];
extern s32 D_002C648C;
extern char D_004F7150[4][32];
extern char D_0048B549[];

char* func_001231E0(s32 id, char* buf) {
    XToaster* p = func_00123880(id);
    XToast* t;
    s32 len;
    s32 i;

    if (p != NULL) {
        t = p->unk_130;
    } else {
        t = func_001320A8(id);
    }
    if (buf == NULL) {
        buf = D_004F7150[D_002C648C];
        D_002C648C = (D_002C648C + 1) % 4;
    }
    if (t != NULL) {
        sprintf(buf, D_00487018, D_002C6460[(u32)id >> 16 & 0xFF], (char*)t + 0x68);
    } else if (((u32)id >> 16 & 0xFF) < 11) {
        sprintf(buf, D_00487020, D_002C6460[(u32)id >> 16 & 0xFF], id);
    } else {
        sprintf(buf, D_00487028, (u32)id >> 16 & 0xFF, id);
    }
    len = strlen(buf);
    for (i = 0; i < len; i++) {
        s32 c = buf[i];
        if (*(D_0048B549 + c) & 2) {
            c -= 0x20;
        }
        buf[i] = c;
    }
    return buf;
}

void func_00123318(XToaster* arg0, s32* arg1) {
    arg1[0] = arg0->unk_154;
    if (arg0->unk_14C != 0) {
        arg1[1] = *(s32*)arg0->unk_14C;
    } else {
        arg1[1] = 0;
    }
    arg1[2] = arg0->unk_1D0;
}

void func_00123340(f32 arg0, XToaster* arg1) {
    arg1->unk_130->unk_44 = arg0;
}

/* Union access = alias set 0: the target reloads unk_130 after the float store, as if built with
   -fno-strict-aliasing. */
typedef union {
    f32 f;
} XToasterAnyF32;

void func_00123350(XToaster* arg0, f32 arg1, f32 arg2, f32 arg3) {
    ((XToasterAnyF32*)&arg0->unk_130->unk_44)->f = arg1;
    arg0->unk_130->unk_5E = (u32)arg2;
    arg0->unk_130->unk_5F = (u32)arg3;
}

static inline s32 xtoaster_inl_001233D0(XToaster* arg0) {
    if (arg0->unk_000 & 0x2000000) {
        return 0;
    }
    return 1;
}

s32 func_001233D0(XToaster* arg0) {
    s32 ret = 0;
    if (arg0->unk_130->unk_5F) {
        ret = xtoaster_inl_001233D0(arg0);
    }
    return ret;
}

s32 func_001233F8(XToaster* arg0) {
    s32 ret = 0;
    if (arg0 != NULL) {
        if ((XT_FLAGS(arg0) & 0x300000000) == 0x100000000) {
            ret = 1;
        }
    }
    return ret;
}

void func_00123430(XToaster* arg0, XToaster* arg1, s32 arg2) {
    XToaster* p = NULL;
    arg0->unk_074 = arg1;
    arg0->unk_078 = arg2;
    while ((p = func_001234A0(p)) != NULL) {
        p->unk_080 = 0;
    }
    while ((p = func_001234A0(p)) != NULL) {
        if (p->unk_074 != NULL) {
            p->unk_074->unk_080++;
        }
    }
}

XToaster* func_001234A0(XToaster* p) {
    if (p == NULL) {
        p = D_002C64A0;
    } else {
        p++;
    }
    for (; p < D_002E26A0; p++) {
        if ((XT_FLAGS(p) & 0x300000000) == 0x100000000) {
            return p;
        }
    }
    return NULL;
}

s64 func_00123518(XToaster* arg0, XToaster* arg1) {
    s64 ret = 0;
    if (!(arg1->unk_000 & 0x200)) {
        u64 t = (XT_FLAGS(arg1) >> 37) & 3;
        if (t != 0) {
            ret = t != ((XT_FLAGS(arg0) >> 37) & 3);
        }
    }
    return ret;
}

XToaster* func_00123558(XToaster* arg0, XToaster* p) {
    while ((p = func_001234A0(p)) != NULL) {
        if (func_00123518(arg0, p)) {
            return p;
        }
    }
    return NULL;
}

static inline u64 xtoaster_inl_team(XToaster* p) {
    return (XT_FLAGS(p) >> 37) & 3;
}

XToaster* func_001235B8(XToaster* arg0, XToaster* p) {
    while ((p = func_001234A0(p)) != NULL) {
        if (arg0 != p && xtoaster_inl_team(arg0) == xtoaster_inl_team(p)) {
            return p;
        }
    }
    return NULL;
}

XToaster* func_00123620(XToaster* p) {
    while ((p = func_001234A0(p)) != NULL) {
        if (p->unk_006 == 2 || p->unk_006 == 9 || p->unk_006 == 10 || ((s32)(XT_FLAGS(p) >> 37) & 3) == 2) {
            return p;
        }
    }
    return NULL;
}

s32 func_00123698(void) {
    s32 n = 0;
    XToaster* p = NULL;
    while ((p = func_001234A0(p)) != NULL) {
        if (((XT_FLAGS(p) >> 37) & 3) == 2) {
            n++;
        }
    }
    return n;
}

s32 func_001236F0(XToaster* arg0) {
    s32 ret = 0;
    if (arg0->unk_134 != NULL && arg0->unk_134[4] != 0 && arg0->unk_3A0 == 0) {
        if ((*(u64*)arg0 & 0x8010) == 0x8000) {
            ret = 1;
        }
    }
    return ret;
}

s32 func_00123730(XToaster* arg0) {
    s32 ret = 0;
    if (arg0->unk_134 != NULL && arg0->unk_134[5] != 0) {
        if ((*(u64*)arg0 & 0x8020) == 0x8000) {
            ret = 1;
        }
    }
    return ret;
}

s32 func_00123768(XToaster* p) {
    s32 i;
    s32 m;
    if (p->unk_134 == NULL || p->unk_134[6] == 0 || p->unk_006 == 2 || (*(u64*)p & 0x8048) != 0x8000) {
        return 0;
    }
    for (i = 0; i < p->unk_134[6]; i++) {
        m = 1 << i;
        if (!(p->unk_3A8 & m)) {
            return 1;
        }
    }
    return 0;
}

static inline s32 xtoaster_inl_001237E8(XToaster* arg0) {
    if (arg0->unk_000 & 0x1000080) {
        return 0;
    }
    return 1;
}

s32 func_001237E8(XToaster* arg0) {
    s32 ret = 0;
    if (func_00123768(arg0)) {
        ret = xtoaster_inl_001237E8(arg0);
    }
    return ret;
}

void func_00123830(XToaster* arg0, s32 arg1) {
    arg0->unk_37C[arg0->unk_388++] = arg0->unk_000;
    arg0->unk_000 = arg1;
}

void func_00123858(XToaster* arg0) {
    if (arg0->unk_388 > 0) {
        arg0->unk_000 = arg0->unk_37C[--arg0->unk_388];
    }
}

XToaster* func_00123880(s32 id) {
    XToaster* p;
    s32 i;
    s32 t = (u32)id >> 16 & 0xFF;

    switch (t) {
    case 1:
        for (i = 0; i < 3; i++) {
            p = XT_SLOTS[i];
            if (p != NULL && p->unk_130->unk_4C == (id & 0xFFFF)) {
                return p;
            }
        }
        p = NULL;
        while ((p = func_001234A0(p)) != NULL) {
            if (p->unk_130->unk_4C == (id & 0xFFFF)) {
                return p;
            }
        }
        break;
    case 0:
        switch (id & 0xFFFF) {
        case 0:
            return XT_SLOTS[0];
        case 1:
            return XT_SLOTS[1];
        case 2:
            return XT_SLOTS[2];
        }
        break;
    case 11:
        p = NULL;
        while ((p = func_001234A0(p)) != NULL) {
            if (p->unk_130->unk_4E == (id & 0xFFFF)) {
                return p;
            }
        }
        break;
    default:
        for (p = func_001234A0(NULL); p != NULL; p = func_001234A0(p)) {
            if (*(s32*)p->unk_004 == id) {
                return p;
            }
        }
        break;
    }
    return NULL;
}

s32 func_001239D8(s32 arg0) {
    XToaster* p = func_00123880(arg0);
    if (p != NULL) {
        return p->unk_130->unk_4C;
    }
    return 0xFF;
}

void func_00123A08(s32 arg0, s32 arg1) {
    func_00123880(arg0)->unk_000 |= 1 << arg1;
}

void func_00123A40(s32 arg0, s32 arg1) {
    func_00123880(arg0)->unk_000 &= ~(1 << arg1);
}

s32 func_00123A80(s32 arg0, s32 arg1) {
    return func_00123880(arg0)->unk_000 & (1 << arg1);
}

void func_00123AB8(XToaster* arg0) {
    if (!((XT_FLAGS(arg0) >> 39) & 1)) {
        if (arg0->unk_154 != 0) {
            func_00162110(arg0->unk_154, &arg0->unk_158[4]);
            if (arg0->unk_14C != 0) {
                func_00149860(arg0);
            }
            arg0->unk_154 = 0;
            arg0->unk_134 = NULL;
        }
    }
}

void func_00123B20(XToaster* arg0) {
    func_00123AB8(arg0);
    arg0->unk_000 = 0;
    arg0->unk_374 = 0;
}

s32 func_00123B50(void) {
    XToaster* p = D_002C64A0;
    s32 i;

    for (i = 0; i < 96; i++, p++) {
        if ((XT_FLAGS(p) & 0x80000200000000) == 0x200000000) {
            func_00123B20(p);
        }
    }
    return 0;
}

void* memset(void*, s32, u32);
extern XToaster* D_002E26AC;

XToaster* func_00123BD0(void) {
    s32 i;
    for (i = 0; i < 96; i++) {
        XToaster* p = D_002E26AC;
        D_002E26AC = p + 1;
        if (D_002E26AC >= D_002E26A0) {
            D_002E26AC = D_002C64A0;
        }
        if (!((s32)(XT_FLAGS(p) >> 32) & 1)) {
            memset(p, 0, sizeof(XToaster));
            XT_FLAGS(p) |= 0x100000000;
            return p;
        }
    }
    return NULL;
}

void func_00123C80(XToaster* arg0, f32 arg1, f32 arg2) {
    arg0->unk_410 = arg1;
    arg0->unk_414 = arg2;
}

typedef struct {
    /* 0x00 */ u64 unk_00;
    /* 0x08 */ char unk_08[0x88];
    /* 0x90 */ XToaster* unk_90;
} XToasterObj;

f32 func_00120AC8(f32);
f32 sinf(f32);
f32 cosf(f32);
void func_00116660(sceVu0FVECTOR);
XToasterObj* func_0014A398(XToasterObj*);
extern sceVu0FVECTOR D_002C58A0;

void func_00123C90(XToaster* p, s32 arg1) {
    f32* v = (f32*)arg1;
    XToasterObj* q;
    f32 a;

    sceVu0CopyVector(p->unk_010, v);
    p->unk_010[3] = 1.0f;
    sceVu0CopyVector(p->unk_050, p->unk_010);
    if (!((XT_FLAGS(p) >> 44) & 1)) {
        a = func_00120AC8(v[3]);
        p->unk_030[0] = sinf(a);
        p->unk_030[1] = 0.0f;
        p->unk_030[2] = cosf(a);
        *(f32*)&p->unk_150 = a;
        p->unk_030[3] = a;
        sceVu0CopyVector(p->unk_020, p->unk_030);
    }
    p->unk_020[3] = 0.0f;
    p->unk_3B4 = v[1];
    p->unk_3B0 = 0;
    p->unk_3B8 = 0;
    p->unk_3BC = 0;
    p->unk_0C0 = 0;
    p->unk_0C4 = 1.0f;
    p->unk_0C8 = 0;
    p->unk_0CC = 1.0f;
    func_00136D38(p);
    sceVu0CopyVector(p->unk_2A0, p->unk_010);
    func_00116660(p->unk_2A0);
    if (!(p->unk_130->unk_04 & 0x40000)) {
        p->unk_350[0] = p->unk_350[1] = p->unk_350[2] = p->unk_350[3] = 0x80;
    }
    p->unk_39E = 0;
    XT_FLAGS(p) &= ~0x400000000000;
    sceVu0CopyVector(p->unk_120, D_002C58A0);
    q = NULL;
    while ((q = func_0014A398(q)) != NULL) {
        if (q->unk_90 == p && (*(s32*)&q->unk_00 & 3) == 1) {
            q->unk_00 &= ~0x10000;
        }
    }
}

void func_00123E48(s32 arg0, s32 arg1) {
    func_00123C90(func_00123880(arg0), arg1);
}

void func_00123E78(s32 arg0, sceVu0FVECTOR arg1) {
    XToaster* p = func_00123880(arg0);
    XT_FLAGS(p) |= 0x100000000000;
    sceVu0CopyVector(p->unk_030, arg1);
    func_00136D38(p);
}

void func_00123ED0(s32 arg0, sceVu0FVECTOR arg1) {
    sceVu0CopyVector(func_00123880(arg0)->unk_040, arg1);
}

void World_GetSpawnPos0(sceVu0FVECTOR);
void World_GetSpawnPos1(sceVu0FVECTOR);
void World_GetSpawnPos2(sceVu0FVECTOR);
void func_0014EAB0(XToaster*, sceVu0FVECTOR);
void func_0014EB60(XToaster*, sceVu0FVECTOR);
void func_0014E668(sceVu0FVECTOR, s32, sceVu0FVECTOR, f32, f32);
f32 atan2f(f32, f32);

void func_00123F00(XToaster* p, f32* v) {
    XToast* t = p->unk_130;
    sceVu0FVECTOR w;
    sceVu0FVECTOR d;
    f32 x;

    switch (t->unk_54) {
    case 0:
        World_GetSpawnPos0(v);
        break;
    case 1:
        if (XT_SLOTS[1] == p) {
            World_GetSpawnPos1(v);
        } else {
            World_GetSpawnPos2(v);
        }
        break;
    default:
        switch (p->unk_006) {
        case 4:
        case 5:
            v[0] = t->unk_1C[0];
            v[1] = t->unk_1C[1];
            v[2] = t->unk_1C[2];
            v[3] = 0.0f;
            p->unk_040[0] = t->unk_2C[0];
            p->unk_040[1] = t->unk_2C[1];
            p->unk_040[2] = t->unk_2C[2];
            w[0] = t->unk_38[0];
            w[1] = t->unk_38[1];
            w[2] = t->unk_38[2];
            func_00123E78(*(s32*)p->unk_004, w);
            break;
        default:
            v[0] = t->unk_1C[0];
            v[1] = t->unk_1C[1];
            v[2] = t->unk_1C[2];
            v[3] = t->unk_1C[3];
            switch (t->unk_5A) {
            case 2:
                if (XT_SLOTS[0] != NULL) {
                    func_0014EAB0(p, v);
                    sceVu0SubVector(d, XT_SLOTS[0]->unk_010, v);
                    v[3] = atan2f(d[0], d[2]);
                }
                break;
            case 3:
                if (XT_SLOTS[0] != NULL) {
                    func_0014EB60(p, v);
                    sceVu0SubVector(d, XT_SLOTS[0]->unk_010, v);
                    v[3] = atan2f(d[0], d[2]);
                }
                break;
            case 4:
                sceVu0CopyVector(d, v);
                func_0014E668(d, p->unk_130->unk_58, v, 0.0f, 500.0f);
                break;
            }
        }
        break;
    }
}

s32 func_001499A0(void);
s32 Party_FindCharacterSlot(s32);
void func_00141E68(XToaster*);
void func_00153D88(XToaster*);
void func_00241C60(XToaster*, s32);
s32* func_00157818(XToaster*, s32);
extern XToaster148 D_004F71D0[];
extern s32 curWorldNo;
extern s32 curRoomNo;
extern s32 D_002B8684;

void func_00124108(XToaster* p) {
    s32 n;
    s32 k;
    XToaster** slots;
    XToaster148* e;

    p->unk_14C = func_001499A0();
    n = Party_FindCharacterSlot(p->unk_130->unk_4C);
    k = n;
    if ((u32)n < 3 && p->unk_006 == 3) {
        if (n > 0) {
            slots = XT_SLOTS;
            k = slots[1] == NULL ? 1 : 2;
        }
        XT_SLOTS[k] = p;
        e = &D_004F71D0[k];
        p->unk_148 = e;
        e->unk_154 = 0;
        p->unk_1CC = 1;
        XT_FLAGS(p) = (XT_FLAGS(p) & ~0x6000000000) | 0x2000000000;
        p->unk_06C[0xBD] = k;
        func_00141E68(p);
        func_00153D88(p);
        *(u16*)((u8*)D_003010F8 + 0x83E) |= 1 << p->unk_130->unk_4C;
        func_001358B8(p, 0xC);
        func_00241C60(p, n);
        if ((curWorldNo == 0x10 && curRoomNo == 0x25 && D_002B8684 == 0xD && p->unk_130->unk_4C == 2) ||
            (curWorldNo == 0x10 && curRoomNo == 0x26 && D_002B8684 == 0xD && p->unk_130->unk_4C == 1)) {
            func_00157818(p, 0)[4] = 0x3000;
        }
    }
}

s32 func_0012B888(s32);
void func_0012BA30(s32, void*, s32);
s32 func_00132008(XToaster*);
void func_00170400(XToaster*);

void func_001242E8(XToaster* p) {
    XToast* t = p->unk_130;
    s8 k = t->unk_54;

    if (k >= 0) {
        switch (k) {
        case 1:
            func_00170400(p);
            break;
        case 6:
            p->unk_3A0 = func_00132008(p);
            break;
        case 2:
        case 5:
            XT_FLAGS(p) |= 0x1000000000000;
            break;
        }
    } else {
        p->unk_138 = t->unk_0C;
        XT_FLAGS(p) |= 0x1000000000000;
    }
    if ((s32)(XT_FLAGS(p) >> 48) & 1) {
        if (p->unk_138 == 0) {
            XT_FLAGS(p) &= ~0x1000000000000;
        } else {
            p->unk_144 = func_0012B888(p->unk_138);
            func_0012BA30(p->unk_144, &p, 4);
        }
    }
}

typedef struct {
    /* 0x00 */ char unk_00[0x1C];
    /* 0x1C */ s32 unk_1C;
    /* 0x20 */ char unk_20[0x4];
    /* 0x24 */ s32 unk_24;
} XToaster14C;

void func_00145240(void);
void func_001358B8(XToaster*, s32);
void func_00176310(s32);
s32 func_0014F5C8(XToaster*);
s32 func_0014F658(void*, s32);
s32 func_00134928(XToaster*);
void func_001350D0(s32);
void func_00137448(XToaster*);
extern sceVu0FVECTOR D_002C58B0;

void func_00124420(XToaster* p, s32 arg1) {
    f32 f;
    s32 r;

    if (p->unk_148 != NULL) {
        p->unk_148->unk_090 = 0xFFFF;
        f = p->unk_148->unk_0E0;
        if (f > 0.0f) {
            (*(f32**)(p->unk_134 + 0x10))[3] = f;
            p->unk_148->unk_0E0 = 0.0f;
        }
        func_00145240();
        sceVu0CopyVector(p->unk_148->unk_160, D_002C58B0);
        func_001358B8(p, 0xC);
    }
    if (p->unk_14C != 0) {
        if (((XToaster14C*)p->unk_14C)->unk_1C != 0) {
            func_00176310(((XToaster14C*)p->unk_14C)->unk_1C);
            ((XToaster14C*)p->unk_14C)->unk_1C = 0;
        }
        ((XToaster14C*)p->unk_14C)->unk_24 = -1;
    }
    if (func_0014F5C8(p) == 0) {
        func_0014F658(p, 0);
    }
    p->unk_388 = 0;
    p->unk_480 = 1.0f;
    p->unk_000 = (p->unk_000 & 0x1004083) | 0x8000;
    p->unk_088 = 0;
    while ((r = func_00134928(p)) != 0) {
        func_001350D0(r);
    }
    p->unk_160 &= ~0x10;
    p->unk_284 = 1.0f;
    p->unk_458 = -1.0f;
    p->unk_470 = 0;
    p->unk_450 = 0;
    p->unk_454 = 0;
    p->unk_474 = 0;
    p->unk_098 = 0;
    func_00137448(p);
    p->unk_4AC = 60.0f;
    func_00123C90(p, arg1);
    sceVu0CopyVector(p->unk_3C0, D_002C58B0);
    sceVu0CopyVector(p->unk_120, D_002C58B0);
}

INCLUDE_ASM("asm/nonmatchings/xtoaster", func_001245F0);

s32 func_0014F658(void*, s32);
void func_001574B0(s32);
void func_00170E48(XToaster*);
void func_0014ED30(XToaster*);
extern s32 D_00350D80[];

void func_00124BC8(XToaster* p) {
    s32 i;
    if (func_001233F8(p)) {
        func_0014F658(p, 0);
        for (i = 0; i < 3; i++) {
            if (((XToaster**)D_002E26A0)[i] == p) {
                func_001574B0(p->unk_130->unk_4C);
                if (p->unk_130->unk_54 == 1) {
                    func_00170E48(p);
                }
                ((XToaster**)D_002E26A0)[i] = NULL;
            }
        }
        XT_FLAGS(p) |= 0x200000000;
        if (!((XT_FLAGS(p) >> 54) & 1)) {
            XToast* t = p->unk_130;
            D_00350D80[0] -= t->unk_59;
        }
        func_0014ED30(p);
    }
}

void func_00124CA0(s32 arg0) {
    XToaster* p = func_00123880(arg0);
    if (p != NULL) {
        func_00124BC8(p);
    }
}

typedef struct {
    /* 0x00 */ char unk_00[0x8];
    /* 0x08 */ u32 unk_08;
    /* 0x0C */ char unk_0C[0x68];
} XTPartyChar; /* size = 0x74, at D_003010F8 + 0x30 */

#define XT_PARTY_CHAR(o) ((XTPartyChar*)(*(s32*)&D_003010F8 + (o)))

void func_00124CD8(void) {
    s32 i;
    s32 o;
    for (i = 0; i < 10; i++) {
        o = i * sizeof(XTPartyChar) + 0x30;
        XT_PARTY_CHAR(o)->unk_08 &= ~0x10000;
    }
    for (i = 0; i < 3; i++) {
        XToaster* p = XT_SLOTS[i];
        if (p != NULL && (p->unk_000 & 0x4000)) {
            o = p->unk_130->unk_4C * sizeof(XTPartyChar) + 0x30;
            XT_PARTY_CHAR(o)->unk_08 |= 0x10000;
        }
    }
}

#ifdef VERSION_FM
void fm_func_001249D8(void) {
    XToaster* p = NULL;
    func_00124CD8();
    while ((p = func_001234A0(p)) != NULL) {
        func_00124BC8(p);
    }
}
#endif

void func_0012B850(s32);
void func_00130340(XToaster*, f32, s32);
void func_00131500(XToaster*);
void func_00142480(sceVu0FVECTOR, void*, s32, sceVu0FVECTOR);
s32 func_001236F0(XToaster*);
extern char D_002C6490[];

void func_00124DD0(void) {
    sceVu0FVECTOR v;
    XToaster* p = NULL;

    while ((p = func_001234A0(p)) != NULL) {
        switch (p->unk_006) {
        case 3:
            if (((s32)(XT_FLAGS(p) >> 48) & 1) && !((s32)(p->unk_440 >> 32) & 1)) {
                func_00124BC8(p);
            } else {
                sceVu0CopyVector(v, p->unk_010);
                if (!func_0014F5C8(p) && func_001236F0(p)) {
                    v[1] -= (*(f32**)(p->unk_134 + 0x10))[2];
                    func_00142480(v, D_002C6490, 0, v);
                }
                v[3] = p->unk_030[3];
                func_00124420(p, (s32)v);
                func_00131500(p);
                func_00130340(p, 0.0f, 0);
            }
            break;
        case 7:
            func_00124BC8(p);
            break;
        }
        if ((s32)(XT_FLAGS(p) >> 48) & 1) {
            if (p->unk_144 != 0) {
                func_0012B850(p->unk_144);
                p->unk_144 = 0;
            }
        }
    }
}

s32 func_00123B50(void);
void func_001372A0(void);
void func_00138738(void);
s32 TaskSystem_FindTask(s32 (*func)(void));

void func_00124F38(void) {
    s32 i;
    for (i = 0; i < 96; i++) {
        (&D_002C64A0[0].unk_374)[i * (sizeof(XToaster) / 4)] = 0;
    }
    D_002E26AC = D_002C64A0;
    for (i = 0; i < 3; i++) {
        XT_SLOTS[i] = NULL;
    }
    func_001372A0();
    func_00138738();
    if (!TaskSystem_FindTask(func_00123B50)) {
        TaskSystem_AddTask(163001, func_00123B50);
    }
}
