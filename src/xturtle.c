/**
 * Sound front end: thin wrappers around the sound RPC calls in xquack, the sound slot tables (0x28 slots in static
 * memory, or 0x80 in work buffers 0x10/0x11), music and sound effect file names (amusic/music%3d.dat,
 * amusic/se%3d.dat, amusic/se000.dat), and the sound tasks. Built with strict aliasing.
 * JP/EU: 0x11C5D8-0x11EAF8. Final Mix (#ifdef VERSION_FM): 0x11C7A8-0x11ECD8; functions paired with JP's by address
 * order and size where they correspond.
 */
#include "common.h"

#ifdef VERSION_FM
extern s32 D_002A3F44;
typedef struct { s32 a; s32 p4; s32 p8; s32 c; s32 b; s32 p14; } E3458;
extern E3458 D_004E3458[];
extern s32 D_002BD8B8[];
void* func_001EE3D8(s32, s32, s32, s32);
void* func_001EE1E0(s32, s32);
void* func_001EE518(s32, s32, s32);
extern s32 D_002B8678;
const char* worldfile_getAbbr(int idx, char* dest);
typedef struct {
    char c[10];
} Seg1C7A8Str10;
extern Seg1C7A8Str10 D_0048D130;
extern char D_0048D128[];
char* strcat(char*, const char*);
typedef struct {
    s32 unk_00;
    u8 unk_04[8];
    s32 unk_0C;
    s32 unk_10;
    u8 unk_14;
    u8 unk_15[3];
} Seg1C7A8Ent18;
extern Seg1C7A8Ent18* D_004E3450;
void func_0011C850_v(s32, s32, s32) __asm__("func_0011C850");
void func_0011C5F0_v(s32, s32, s32) __asm__("func_0011C5F0");
void func_0011C868_v(s32, s32, s32, s32, s32) __asm__("func_0011C868");
extern s32 D_002A0520[];
extern s32 D_002B9040[];
typedef struct {
    s32 unk_00;
    s32 unk_04;
} Seg1C7A8Pair;
typedef struct {
    s32 unk_00;
    s32 unk_04;
    s32 unk_08;
} Seg1C7A8Ent0C;
extern volatile s32 D_002BBDE0;
extern s32 D_002C1310[];
extern Seg1C7A8Pair D_004E39F8[];
extern s32 D_004E344C;
extern Seg1C7A8Ent0C* D_004E3454;
void func_0011D028(s32, s32);
extern s32 D_002BD8D8;
extern s32 D_004E3444;
extern void (*D_004E3434)(void);
void func_0011E610(void);
void func_0011C7A8_v(s32, s32, s32, s32, s32, s32) __asm__("func_0011C7A8");
extern s32 D_002C1364;
extern void (*D_004E3430)(void);

#include "xquack.h"

typedef struct {
    s32 unk_00;
    s32 unk_04;
    s32 unk_08;
    s32 unk_0C;
    s32 unk_10;
    u8 unk_14;
    u8 unk_15;
    u8 unk_16;
} Seg1C7A8Unk18;
void* func_001EE618(s32, s32, s32);
void* func_001EE390(s32, s32, s32);
extern s32 D_004E3A40;
extern char D_0048D140[];
Seg1C7A8Unk18* func_0011CFA8(s32, s32, s32, s32, s32);
void* func_001EDD20(void*, s32, s32, s32);
void func_0011E1C8(void*);
s32 func_0011E248();
extern s32 D_002C1394;
extern s32 D_002C1390;
void func_00101528(void);
void func_0011CBE0(s32, s32, s32, void (*)(void));
void func_0011E700(void);
void func_0011E7F8(void);
extern s32 D_002C1378;
extern s32 D_002C137C;
void func_0011E8D0(s32, s32, s32, s32, s32, s32);

void* func_0011C7A8(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5) {
    return func_001EE570(arg0, arg1, arg2, arg3, arg4, arg5);
}
#else
#include "common_funcs.h"
#include "xquack.h"
#include "xturtle.h"

typedef struct XTurtle {
    /* 0x00 */ s32 unk_00;
    /* 0x04 */ s32 unk_04;
    /* 0x08 */ s32 unk_08;
    /* 0x0C */ s32 unk_0C;
    /* 0x10 */ s32 unk_10;
    /* 0x14 */ u8 unk_14;
    /* 0x15 */ u8 unk_15;
    /* 0x16 */ u8 unk_16;
    /* 0x17 */ char unk_17;
} XTurtle;

typedef struct XScale {
    /* 0x00 */ s32 unk_00;
    /* 0x04 */ s32 unk_04;
} XScale; // size = 0x8

typedef struct XShell {
    /* 0x00 */ s32 unk_00;
    /* 0x04 */ s32 unk_04;
    /* 0x08 */ s32 unk_08;
} XShell; // size = 0xC

extern s32 D_002A0514;
extern s32 D_002BD8B4;
extern s32 D_002BD8B8[2];
extern s32 D_002BD8C8;
extern s32 D_002BD8CC;
extern s32 D_002BD8E0;
extern s32 D_002BD8E4;

const char D_00486E40[] = "%3d";
const char D_00486E48[] = "amusic/music";
const char D_00486E58[] = ".dat";
const char D_00486E60[] = "amusic/se";

void (*D_004DCB70)(void);
extern s32 D_004DCB8C;
extern XTurtle* D_004DCB90;
extern XShell* D_004DCB94;
extern XTurtle* D_004DCB98;
extern XTurtle* D_004DCF58;
extern XScale* D_004DD138;
extern s32 D_004DD180;

XTurtle* func_0011CDD8(s32, s32, s32, s32, s32);

void func_0011C5D8(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5) {
    func_001EE570(arg0, arg1, arg2, arg3, arg4, arg5);
}
#endif

#ifdef VERSION_FM
void* func_0011C5F0(s32 arg0, s32 arg1, s32 arg2) {
    return func_001EE618(arg0, arg1, arg2);
}
#else
s32 func_0011C5F0(s32 arg0, s32 arg1, s32 arg2) {
    return func_001EE618(arg0, arg1, arg2);
}
#endif

#ifdef VERSION_FM
void* func_0011C7D8(s32 arg0) {
    return func_001EE5D8(arg0);
}
#else
void* func_0011C608(s32 arg0) {
    return func_001EE5D8(arg0);
}
#endif

#ifdef VERSION_FM
void* func_0011C7F0(void* arg0) {
    return func_001EE660(arg0);
}
#else
void* func_0011C620(void* arg0) {
    return func_001EE660(arg0);
}
#endif

#ifdef VERSION_FM
void* func_0011C808(void* arg0) {
    return func_001EE6B8(arg0);
}
#else
void* func_0011C638(void* arg0) {
    return func_001EE6B8(arg0);
}
#endif

#ifdef VERSION_FM
s32 func_0011C820(void) {
    return func_001EE090();
}
#else
s32 func_0011C650(void) {
    return func_001EE090();
}
#endif

#ifdef VERSION_FM
void* func_0011C838(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    return func_001EE330(arg0, arg1, arg2, arg3, arg4);
}
#else
void* func_0011C668(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    return func_001EE330(arg0, arg1, arg2, arg3, arg4);
}
#endif

#ifdef VERSION_FM
void* func_0011C850(s32 arg0, s32 arg1, s32 arg2) {
    return func_001EE390(arg0, arg1, arg2);
}
#else
s32 func_0011C680(s32 arg0, s32 arg1, s32 arg2) {
    return func_001EE390(arg0, arg1, arg2);
}
#endif

#ifdef VERSION_FM
void* func_0011C868(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    return func_001EE428(arg0, arg1, arg2, arg3, arg4);
}
#else
void* func_0011C698(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    return func_001EE428(arg0, arg1, arg2, arg3, arg4);
}
#endif

#ifdef VERSION_FM
void* func_0011C880(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    return func_001EE478(arg0, arg1, arg2, arg3, arg4);
}
#else
void* func_0011C6B0(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    return func_001EE478(arg0, arg1, arg2, arg3, arg4);
}
#endif

#ifdef VERSION_FM
extern u8 D_004E3818[];
void func_0011C6C8(s32 a0) {
    Seg1C7A8Ent18 *p;
    Seg1C7A8Ent0C *q;
    Seg1C7A8Pair *r;
    s32 i;
    s32 t;

    if (a0 == 0) {
        D_004E3450 = (Seg1C7A8Ent18 *)D_004E3458;
        D_004E3454 = (Seg1C7A8Ent0C *)D_004E3818;
        D_004E344C = 0x28;
    } else {
        D_004E3450 = (Seg1C7A8Ent18 *)func_00155ED8(0x10, 1);
        D_004E3454 = (Seg1C7A8Ent0C *)func_00155ED8(0x11, 1);
        D_004E344C = 0x80;
    }
    p = D_004E3450;
    q = D_004E3454;
    i = 0;
    if (i < D_004E344C) {
        do {
            p->unk_14 = 0;
            p++;
            q->unk_00 = 0;
            i++;
            t = i < D_004E344C;
            q->unk_04 = 0;
            q->unk_08 = 0;
            q++;
        } while (t);
    }
    r = D_004E39F8;
    for (i = 3; i >= 0; i--) {
        r->unk_00 = 0;
        r->unk_04 = 0;
        r++;
    }
}
#else
void func_0011C6C8(s32 arg0) {
    XScale* var_2;
    XTurtle* var_3;
    XShell* var_4;
    s32 i;

    if (arg0 == 0) {
        D_004DCB90 = &D_004DCB98;
        D_004DCB94 = &D_004DCF58;
        D_004DCB8C = 0x28;
    } else {
        D_004DCB90 = func_00155ED8(0x10, 1);
        D_004DCB94 = func_00155ED8(0x11, 1);
        D_004DCB8C = 0x80;
    }

    var_3 = D_004DCB90;
    var_4 = D_004DCB94;
    for (i = 0; i < D_004DCB8C; i++) {
        var_3->unk_14 = 0;
        var_4->unk_00 = 0;
        var_4->unk_04 = 0;
        var_4->unk_08 = 0;
        var_3++;
        var_4++;
    }

    var_2 = &D_004DD138;
    for (i = 0; i < 4; i++) {
        var_2->unk_00 = 0;
        var_2->unk_04 = 0;
        var_2++;
    }
}
#endif

#ifdef VERSION_FM
void func_0011C9A0(void) {
    D_004E3A40 = 0;
}
#else
void func_0011C7D0(void) {
    D_004DD180 = 0;
}
#endif

#ifdef VERSION_FM
void func_0011C9B0(void) {
    D_004E3A40 = 1;
}
#else
void func_0011C7E0(void) {
    D_004DD180 = 1;
}
#endif

#ifdef VERSION_FM
void func_001EE228(s32);
void func_00113A10(s32);
void func_001EEC58(void);

void func_0011C9C0(void) {
    func_0011C9A0();
    func_0011C6C8(0);
    func_001EE5D8(0);
    func_001EE5D8(1);
    func_001EE390(-100, -1, -1);
    func_001EE1E0(0, 0);
    func_001EE1E0(0, 1);
    func_001EE1E0(1, 0);
    func_001EE1E0(1, 1);
    func_001EE1E0(0, -8);
    func_001EE1E0(3, -8);
    func_001EE228(10);
    func_00113A10(0);
    func_001EEC58();
    func_00101528();
}
#else
void func_0011C7F0(void) {
    func_0011C7D0();
    func_0011C6C8(0);
    func_001EE5D8(0);
    func_001EE5D8(1);
    func_001EE390(-100, -1, -1);
    func_001EE1E0(0, 0);
    func_001EE1E0(0, 1);
    func_001EE1E0(1, 0);
    func_001EE1E0(1, 1);
    func_001EE1E0(0, -8);
    func_001EE1E0(3, -8);
    func_001EE228(10);
    func_00113A10(0);
    func_001EEC58();
    func_00101528();
}
#endif

#ifdef VERSION_FM
INCLUDE_ASM("asm/nonmatchings/xturtle", func_0011CA68);
#else
INCLUDE_ASM("asm/nonmatchings/xturtle", func_0011C898);
#endif

#ifdef VERSION_FM
void func_0011C938(char* a0) {
    char buf[16];
    *(Seg1C7A8Str10*)a0 = D_0048D130;
    worldfile_getAbbr(D_002B8678, buf);
    strcat(a0, buf);
    strcat(a0, D_0048D128);
}
#else
INCLUDE_ASM("asm/nonmatchings/xturtle", func_0011C938);
#endif

#ifdef VERSION_FM
s32 func_0011CB80(void* arg0) {
    return func_00120438(D_0048D140, arg0);
}
#else
s32 func_0011C9B0(void* arg0) {
    return func_00120438("amusic/se000.dat", arg0); // in xkingdom.c
}
#endif

#ifdef VERSION_FM
s32 func_0011CBA0(void) {
    if (func_001EE090() != 0) return 0;
    if (D_004E3430 != 0) D_004E3430();
    return 4;
}
#else
s32 func_0011C9D0(void) {
    if (func_001EE090()) {
        return 0;
    }

    if (D_004DCB70 != NULL) {
        D_004DCB70();
    }

    return 4;
}
#endif

#ifdef VERSION_FM
typedef struct {
    s32 off;
    s32 size;
} A2SecCBE0;
void func_001EE710(s32, u8 *, s32);
void *func_0011ED30(s32, s32 (*)(void));

void func_0011CBE0(s32 a0, s32 a1_, s32 a2, void (*cb)(void)) {
    u8 *a1 = (u8 *)a1_;
    A2SecCBE0 *s;
    u8 *p0;
    u8 *p1;
    s32 size0, size1;

    s = (A2SecCBE0 *)(a1 + 0x10);
    p0 = a1 + s->off;
    size0 = s->size;
    s = (A2SecCBE0 *)(a1 + 0x18);
    p1 = a1 + s->off;
    size1 = s->size;
    D_004E3430 = cb;
    if (*(s32 *)(p1 + 4) > 0x7547F) {
        func_001EE1E0(0, 0);
        func_001EE1E0(1, 0);
        func_001EE1E0(0, 1);
        func_001EE1E0(1, 1);
        D_002BD8B8[0] = -2;
        D_002BD8B8[1] = -2;
        if (a0 == 1) {
            a0 = 0;
            goto skip;
        }
    }
    D_002BD8B8[a0] = a2;
    func_001EE1E0(0, a0);
    func_001EE1E0(1, a0);
skip:
    func_001EE518(a0, (s32)p0, size0);
    func_001EE710(a0, p1, size1);
    func_0011ED30(10000, func_0011CBA0);
}
#else
INCLUDE_ASM("asm/nonmatchings/xturtle", func_0011CA10);
#endif

#ifdef VERSION_FM
typedef struct {
    s32 off;
    s32 size;
} A2Sec;
void func_001EE2D8(s32, u8 *, s32);
void func_001EE710(s32, u8 *, s32);
void func_001EEC58(void);
void func_001102C0(void);

void func_0011CD20(s32 a0, u8 *a1, void (*cb)(void)) {
    A2Sec *s;
    u8 *p0;
    s32 size0, size1;

    s = (A2Sec *)(a1 + 0x10);
    p0 = a1 + s->off;
    size0 = s->size;
    s = (A2Sec *)(a1 + 0x18);
    a1 += s->off;
    size1 = s->size;
    D_004E3430 = cb;
    func_001EE1E0(0, 2);
    func_001EE1E0(2, 2);
    func_001EE2D8(a0, p0, size0);
    func_001EE710(a0, a1, size1);
    func_001EEC58();
    while (func_001EE090() == 0) {
        func_001102C0();
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/xturtle", func_0011CB50);
#endif

INCLUDE_ASM("asm/nonmatchings/xturtle", func_0011CC20);

#ifdef VERSION_FM
void func_0011CF88(s32 arg0, s32 arg1, s32 arg2, s32 arg3, u8 arg4, Seg1C7A8Unk18* arg5, s32 arg6) {
    arg5->unk_00 = arg0;
    arg5->unk_10 = arg1;
    arg5->unk_04 = arg2;
    arg5->unk_08 = arg3;
    arg5->unk_16 = arg4;
    arg5->unk_15 = 0;
    arg5->unk_0C = arg6;
}
#else
void func_0011CDB8(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, XTurtle* arg5, s32 arg6) {
    arg5->unk_0C = arg6;
    arg5->unk_00 = arg0;
    arg5->unk_10 = arg1;
    arg5->unk_04 = arg2;
    arg5->unk_08 = arg3;
    arg5->unk_16 = arg4;
    arg5->unk_15 = 0;
}
#endif

#ifdef VERSION_FM
void func_0011CF88_x(s32, s32, s32, s32, s32, Seg1C7A8Unk18*, s32) __asm__("func_0011CF88");
Seg1C7A8Unk18* func_0011CFA8(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    Seg1C7A8Unk18 *e = (Seg1C7A8Unk18*)D_004E3450;
    s32 i;
    for (i = 0; i < D_004E344C; i++, e++) {
        if (e->unk_14 == 0) {
            func_0011CF88_x(arg0, arg1, arg2, arg3, arg4, e, arg0 < 1000 ? 2 : -1);
            return e;
        }
    }
    return NULL;
}
#else
XTurtle* func_0011CDD8(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    XTurtle* it = D_004DCB90;
    s32 i;

    for (i = 0; i < D_004DCB8C; i++, it++) {
        s32 val = (arg0 < 1000) ? 2 : -1;

        if (it->unk_14 == 0) {
            func_0011CDB8(arg0, arg1, arg2, arg3, arg4, it, val);
            return it;
        }
    }

    return NULL;
}
#endif

#ifdef VERSION_FM
void func_0011D028(s32 a0, s32 a1) {
    Seg1C7A8Ent0C *e = D_004E3454;
    s32 i;
    for (i = 0; i < D_004E344C; i++, e++) {
        if (e->unk_00 == 0) {
            goto found;
        }
    }
found:
    e->unk_00 = a0;
    e->unk_04 = a1;
    e->unk_08 = 2;
}
#else
INCLUDE_ASM("asm/nonmatchings/xturtle", func_0011CE58);
#endif

#ifdef VERSION_FM
void func_0011D080(s32 a0, s32 a1) {
    func_0011C838(a0 < 1000 ? 2 : -8, a0, a1, 0x3FFF, 0x3FFF);
    func_0011D028(a0, a1);
}
#else
void func_0011CEB0(s32 arg0, s32 arg1) {
    s32 val = arg0 < 1000 ? 2 : -8;

    func_0011C668(val, arg0, arg1, 0x3FFF, 0x3FFF);
    func_0011CE58(arg0, arg1);
}
#endif

#ifdef VERSION_FM
void* func_0011D0D8(s32 arg0, s32 arg1) {
    return func_0011C850(arg0 < 1000 ? 2 : -8, arg0, arg1);
}
#else
s32 func_0011CF08(s32 arg0, s32 arg1) {
    s32 val = arg0 < 1000 ? 2 : -8;

    return func_0011C680(val, arg0, arg1);
}
#endif

#ifdef VERSION_FM
void* func_0011D108(s32 arg0, s32 arg1, s32 arg2) {
    return func_0011C868(arg0 < 1000 ? 2 : -8, arg0, arg1, -1, arg2);
}
#else
void* func_0011CF38(s32 arg0, s32 arg1, s32 arg2) {
    s32 val = arg0 < 1000 ? 2 : -8;

    return func_0011C698(val, arg0, arg1, -1, arg2);
}
#endif

#ifdef VERSION_FM
void* func_0011D140(s32 arg0, s32 arg1) {
    return func_0011C838(arg0 < 1000 ? 2 : -1, arg0, arg1, 0x3FFF, 0x3FFF);
}
#else
void* func_0011CF70(s32 arg0, s32 arg1) {
    s32 val = arg0 < 1000 ? 2 : -1;

    return func_0011C668(val, arg0, arg1, 0x3FFF, 0x3FFF);
}
#endif

#ifdef VERSION_FM
void* func_0011D178(s32 arg0, s32 arg1) {
    return func_0011C850(arg0 < 1000 ? 2 : -1, arg0, arg1);
}
#else
s32 func_0011CFA8(s32 arg0, s32 arg1) {
    s32 val = arg0 < 1000 ? 2 : -1;

    return func_0011C680(val, arg0, arg1);
}
#endif

#ifdef VERSION_FM
void* func_0011D1A8(s32 arg0, s32 arg1, s32 arg2) {
    return func_0011C868(arg0 < 1000 ? 2 : -1, arg0, arg1, -1, arg2);
}
#else
void* func_0011CFD8(s32 arg0, s32 arg1, s32 arg2) {
    s32 val = arg0 < 1000 ? 2 : -1;

    return func_0011C698(val, arg0, arg1, -1, arg2);
}
#endif

#ifdef VERSION_FM
void func_0011D1E0(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    Seg1C7A8Unk18* p = func_0011CFA8(arg0, arg1, arg2, arg3, 0);

    if (p != NULL) {
        p->unk_14 = 1;
    }
}
#else
void func_0011D010(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    XTurtle* bleb = func_0011CDD8(arg0, arg1, arg2, arg3, 0);

    if (bleb != NULL) {
        bleb->unk_14 = 1;
    }
}
#endif

#ifdef VERSION_FM
void func_0011D210(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    Seg1C7A8Unk18* p = func_0011CFA8(arg0, arg1, arg2, arg3, 1);

    if (p != NULL) {
        p->unk_14 = 2;
    }
}
#else
void func_0011D040(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    XTurtle* bleb = func_0011CDD8(arg0, arg1, arg2, arg3, 1);

    if (bleb != NULL) {
        bleb->unk_14 = 2;
    }
}
#endif

#ifdef VERSION_FM
void func_0011D070(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    Seg1C7A8Unk18* p = func_0011CFA8(arg0, arg1, arg2, arg3, 2);

    if (p != NULL) {
        p->unk_14 = 1;
    }
}
#else
void func_0011D070(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    XTurtle* bleb = func_0011CDD8(arg0, arg1, arg2, arg3, 2);

    if (bleb != NULL) {
        bleb->unk_14 = 1;
    }
}
#endif

#ifdef VERSION_FM
void func_0011D270(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    Seg1C7A8Unk18* p = func_0011CFA8(arg0, arg1, arg2, arg3, 3);

    if (p != NULL) {
        p->unk_14 = 2;
    }
}
#else
void func_0011D0A0(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    XTurtle* bleb = func_0011CDD8(arg0, arg1, arg2, arg3, 3);

    if (bleb != NULL) {
        bleb->unk_14 = 2;
    }
}
#endif

#ifdef VERSION_FM
void func_0011D2A0(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    Seg1C7A8Unk18* p = func_0011CFA8(arg0, arg1, arg2, arg3, 4);

    if (p != NULL) {
        p->unk_14 = 2;
    }
}
#else
void func_0011D0D0(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    XTurtle* bleb = func_0011CDD8(arg0, arg1, arg2, arg3, 4);

    if (bleb != NULL) {
        bleb->unk_14 = 2;
    }
}
#endif

#ifdef VERSION_FM
void func_0011D2D0(s32 a0, s32 a1, s32 a2) {
    s32 i;
    E3458* e = D_004E3458;
    for (i = 0; i < D_004E344C; i++, e++) {
        if (e->a == a0 && e->b == a1) {
            func_001EE3D8(e->c, a0, a1, a2);
            return;
        }
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/xturtle", func_0011D100);
#endif

#ifdef VERSION_FM
void func_0011D350(s32 arg0, s32 arg1) {
    Seg1C7A8Ent18 *e = D_004E3450;
    s32 i;
    for (i = 0; i < D_004E344C; i++, e++) {
        if (e->unk_00 == arg0 && e->unk_10 == arg1) {
            e->unk_14 = 0;
            func_0011C850(e->unk_0C, arg0, arg1);
            return;
        }
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/xturtle", func_0011D180);
#endif

#ifdef VERSION_FM
void func_0011D1F8(s32 arg0, s32 arg1, s32 arg2) {
    Seg1C7A8Ent18 *e = D_004E3450;
    s32 i;
    for (i = 0; i < D_004E344C; i++, e++) {
        if (e->unk_00 == arg0 && e->unk_10 == arg1) {
            e->unk_14 = 0;
            func_0011C868(e->unk_0C, arg0, arg1, -1, arg2);
            return;
        }
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/xturtle", func_0011D1F8);
#endif

#ifdef VERSION_FM
void func_0011D448(void) {
    Seg1C7A8Ent18 *e = D_004E3450;
    s32 i;
    for (i = 0; i < D_004E344C; i++, e++) {
        if (e->unk_14 != 0 && e->unk_15[1] == 4) {
            e->unk_14 = 0;
            func_0011C850(e->unk_0C, e->unk_00, e->unk_10);
        }
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/xturtle", func_0011D278);
#endif

#ifdef VERSION_FM
void func_0011D310(s32 arg0) {
    Seg1C7A8Ent18 *e = D_004E3450;
    s32 i;
    for (i = 0; i < D_004E344C; i++, e++) {
        if (e->unk_14 != 0 && e->unk_15[1] == 4) {
            e->unk_14 = 0;
            func_0011C868(e->unk_0C, e->unk_00, e->unk_10, -1, arg0);
        }
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/xturtle", func_0011D310);
#endif

#ifdef VERSION_FM
void func_0011D588(void) {
    s32 i;
    for (i = 0; i < 2; i++) {
        func_0011D070(D_002A0520[i], i, (s32)D_002B9040, 0x3FFF);
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/xturtle", func_0011D3B8);
#endif

#ifdef VERSION_FM
void func_0011D5F0(void) {
    Seg1C7A8Ent18 *e = D_004E3450;
    s32 i;
    for (i = 0; i < D_004E344C; i++, e++) {
        if (e->unk_14 != 0 && e->unk_15[1] == 2) {
            e->unk_14 = 0;
            func_0011C850(e->unk_0C, e->unk_00, e->unk_10);
        }
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/xturtle", func_0011D420);
#endif

#ifdef VERSION_FM
void func_0011D4B8(s32 a0) {
    s32 i;
    for (i = 0; i < 2; i++) {
        func_0011C868_v(-1, D_002A0520[i], i, -1, a0);
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/xturtle", func_0011D4B8);
#endif

#ifdef VERSION_FM
s32 func_001EDBC0(s32, s32, s32);
s32 func_0011D6F0(s32 arg0, s32 arg1) {
    Seg1C7A8Ent18 *e = D_004E3450;
    s32 i;
    for (i = 0; i < D_004E344C; i++, e++) {
        if (e->unk_00 == arg0 && e->unk_10 == arg1) {
            return func_001EDBC0(e->unk_0C, arg0, arg1);
        }
    }
    return 0;
}
#else
INCLUDE_ASM("asm/nonmatchings/xturtle", func_0011D520);
#endif

#ifdef VERSION_FM
void* func_0011D598(s32 arg0) {
    return func_0011C838(2, arg0, 0, 0x3FFF, 0x3FFF);
}
#else
void* func_0011D598(s32 arg0) {
    return func_0011C668(2, arg0, 0, 0x3FFF, 0x3FFF);
}
#endif

#ifdef VERSION_FM
void* func_0011D790(s32 arg0, s32 arg1) {
    s32 v = arg1 == 0 ? 0x3FFF : 0x1FFF;

    return func_0011C880(2, arg0, 0, v, v);
}
#else
void* func_0011D5C0(s32 arg0, s32 arg1) {
    s32 val = 0x3FFF;
    if (arg1 != 0) {
        val = 0x1FFF;
    }

    return func_0011C6B0(2, arg0, 0, val, val);
}
#endif

#ifdef VERSION_FM
void* func_0011D7C0(s32 arg0) {
    return func_0011C850(2, arg0, 0);
}
#else
s32 func_0011D5F0(s32 arg0) {
    return func_0011C680(2, arg0, 0);
}
#endif

#ifdef VERSION_FM
INCLUDE_ASM("asm/nonmatchings/xturtle", func_0011D7E0);
#else
INCLUDE_ASM("asm/nonmatchings/xturtle", func_0011D610);
#endif

#ifdef VERSION_FM
void func_0011DB50(s32* a, s32* b) {
    if (*a < 0) *a = 0;
    if (*b < 0) *b = 0;
    if (*a >= 0x4000) *a = 0x3FFF;
    if (*b >= 0x4000) *b = 0x3FFF;
}
#else
void func_0011D978(s32* arg0, s32* arg1) {
    s32 val;

    if (*arg0 < 0) {
        *arg0 = 0;
    }
    if (*arg1 < 0) {
        *arg1 = 0;
    }
    if (*arg0 < 0x4000) {
        val = *arg1;
    } else {
        *arg0 = 0x3FFF;
        val = *arg1;
    }
    if (val > 0x3FFF) {
        *arg1 = 0x3FFF;
    }
}
#endif

#ifdef VERSION_FM
void func_0011DBA0(s32* a, s32* b, s32 v, s32 mode) {
    if (mode == 2 && D_002A3F44 != 0) {
        *a = 0;
        *b = 0;
        return;
    }
    if (v == 0x3FFF) {
        *a = v;
        *b = v;
        return;
    }
    *a += v;
    *b += v;
    func_0011DB50(a, b);
}
#else
void func_0011D9C8(s32* arg0, s32* arg1, s32 arg2, s32 arg3) {
    if ((arg3 == 2) && (D_002A0514 != 0)) {
        *arg0 = 0;
        *arg1 = 0;
    } else if (arg2 == 0x3FFF) {
        *arg0 = 0x3FFF;
        *arg1 = 0x3FFF;
    } else {
        *arg0 = *arg0 + arg2;
        *arg1 = *arg1 + arg2;
        func_0011D978(arg0, arg1);
    }
}
#endif

#ifdef VERSION_FM
void func_0011DC28(s32* a0, s32* a1, s32* a2) {
    s32 i;
    if (D_002BBDE0 != 3) {
        for (i = 0; i < 4; i++) {
            if (*a0 == D_002C1310[i] && *a1 < 0x2400 && *a2 < 0x2400) {
                *a1 = 0x2400;
                *a2 = 0x2400;
            }
        }
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/xturtle", func_0011DA50);
#endif

#ifdef VERSION_FM
void func_0011DC98(u8* a0) {
    s32 i;
    if (D_002BBDE0 != 3) {
        for (i = 0; i < 4; i++) {
            if (*(s32*)a0 == D_002C1310[i]) a0[0x14] = 0;
        }
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/xturtle", func_0011DAC0);
#endif

#ifdef VERSION_FM
extern s32 D_002C1360;
extern sceVu0FVECTOR D_004E3A20;
extern sceVu0FVECTOR D_004E3A30;
void func_0011DB50(s32 *, s32 *);

static inline f32 Seg1C7A8_Dist(f32 *a, f32 *b) {
    f32 d;
    __asm__ volatile("lqc2 $vf6,0x0(%1)\n\tlqc2 $vf4,0x0(%2)\n\tvsub.xyzw $vf5,$vf6,$vf4\n\tvmove.xyzw $vf4,$vf5\n\tvmul.xyz $vf5,$vf4,$vf5\n\tvaddy.x $vf5,$vf5,$vf5y\n\tvaddz.x $vf5,$vf5,$vf5z\n\tvsqrt Q,$vf5x\n\tvwaitq\n\tvaddq.x $vf5,$vf0,Q\n\tqmfc2.ni $2,$vf5\n\tmtc1 $2,%0" : "=f"(d) : "r"(a), "r"(b) : "$2", "memory");
    return d;
}

void func_0011DCF0(f32 *p, s32 *a, s32 *b) {
    f32 r = D_002C1360;
    f32 d;
    d = Seg1C7A8_Dist(D_004E3A20, p);
    *a = 16383.0f - d * d / r;
    d = Seg1C7A8_Dist(D_004E3A30, p);
    *b = 16383.0f - d * d / r;
    func_0011DB50(a, b);
}
#else
INCLUDE_ASM("asm/nonmatchings/xturtle", func_0011DB18);
#endif

#ifdef VERSION_FM
void sceVu0InversMatrix(f32 (*)[4], f32 (*)[4]);
void sceVu0ApplyMatrix(f32 *, f32 (*)[4], f32 *);
extern f32 (*D_002BC140)[4];
extern f32 D_002C1320[];
extern f32 D_002C1330[];
extern f32 D_002C1340[];
extern f32 D_002C1350[];
extern f32 D_004E3A20[];
extern f32 D_004E3A30[];

void func_0011DDD0(void) {
    f32 m[4][4] __attribute__((aligned(16)));

    sceVu0InversMatrix(m, D_002BC140);
    if (D_002BBDE0 == 3) {
        sceVu0ApplyMatrix(D_004E3A30, m, D_002C1350);
        sceVu0ApplyMatrix(D_004E3A20, m, D_002C1340);
    } else {
        sceVu0ApplyMatrix(D_004E3A30, m, D_002C1330);
        sceVu0ApplyMatrix(D_004E3A20, m, D_002C1320);
        D_004E3A30[2] = 1000.0f;
        D_004E3A20[2] = 1000.0f;
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/xturtle", func_0011DBF8);
#endif

#ifdef VERSION_FM
INCLUDE_ASM("asm/nonmatchings/xturtle", func_0011DE90);
#else
INCLUDE_ASM("asm/nonmatchings/xturtle", func_0011DCB8);
#endif

#ifdef VERSION_FM
void func_0011E1C8(void* a0) {
    s32 i;
    i = 0;
    do {
        if (D_004E39F8[i].unk_00 == 0) break;
        i++;
    } while (i < 4);
    D_004E39F8[i].unk_00 = (s32)a0;
    D_004E39F8[i].unk_04 = 2;
}
#else
INCLUDE_ASM("asm/nonmatchings/xturtle", func_0011DFF0);
#endif

#ifndef VERSION_FM
void func_0011E048(s32 arg0) {
    func_001EDD20(arg0);
    func_0011DFF0(arg0);
}
#endif

#ifdef VERSION_FM
void func_0011E220(void* arg0, s32 arg1, s32 arg2, s32 arg3) {
    func_001EDD20(arg0, arg1, arg2, arg3);
    func_0011E1C8(arg0);
}
#else
INCLUDE_ASM("asm/nonmatchings/xturtle", func_0011E070);
#endif

#ifdef VERSION_FM
s32 func_00157090(void);
s32 func_001EDDC0(s32, s32, s32);
extern s32 D_004E3A18;

s32 func_0011E248(a0)
    s32 a0;
{
    Seg1C7A8Pair *p;
    s32 i;
    s32 r;

    if (func_00157090() != 0) {
        return 8;
    }
    if (a0 == 0) {
        if (D_004E3A18 != 0) {
            return 9;
        }
        r = func_001EDDC0(-1, -1, 0);
        if (r == 0) {
            for (i = 3; i >= 0; i--) {
                D_004E39F8[i].unk_00 = 0;
            }
        }
        return r;
    }
    p = D_004E39F8;
    for (i = 0; i < 4; i++, p++) {
        if (p->unk_00 == a0) {
            if (p->unk_04 != 0) {
                return 9;
            }
            r = func_001EDDC0(-1, -1, a0);
            if (r == 0) {
                p->unk_00 = 0;
            }
            return r;
        }
    }
    return 0;
}

void fm_func_0011E340(void) {
    D_002C1394 = func_0011E248();
}
#else
s32 func_0011E168(s32 arg0) {
    D_002BD8E4 = func_0011E070(arg0);
    return D_002BD8E4;
}
#endif

#ifdef VERSION_FM
extern s32 D_004E3A1C;
s32 func_001EDBC0(s32, s32, s32);

s32 func_0011E368(s32 a0, s32 a1) {
    Seg1C7A8Ent0C *e = D_004E3454;
    s32 i;
    s32 r;

    if (a0 == -1) {
        if (D_004E3A1C != 0) {
            return 1;
        }
        r = func_001EDBC0(-8, -1, -1);
        if (r == 0) {
            s32 n = D_004E344C;
            for (i = 0; i < n; i++) {
                e->unk_00 = 0;
                e->unk_04 = 0;
            }
        }
        return r;
    }
    for (i = 0; i < D_004E344C; i++, e++) {
        if (e->unk_00 == a0 && e->unk_04 == a1) {
            if (e->unk_08 != 0) {
                return 1;
            }
            r = func_001EDBC0(-8, a0, a1);
            if (r == 0) {
                e->unk_00 = 0;
                e->unk_04 = 0;
            }
            return r;
        }
    }
    return 0;
}
#else
INCLUDE_ASM("asm/nonmatchings/xturtle", func_0011E190);
#endif

#ifdef VERSION_FM
void func_0011E480(void) {
    func_0011C5F0(0, 0, 0x3C0);
    func_0011C7A8_v(1, 0, 0x3000, 0xF0, 0, 0xF0);
    D_002C1364 = 1;
}
#else
void func_0011E2A8(void) {
    func_0011C5F0(0, 0, 960);
    func_0011C5D8(1, 0, 0x3000, 240, 0, 240);
    D_002BD8B4 = 1;
}
#endif

#ifdef VERSION_FM
void func_0011E4D0(void) {
    func_0011C5F0(1, 0, 0x2D0);
    func_0011C7A8_v(0, 0, 0x3000, 0x1E0, 1, 0xF0);
    D_002C1364 = 0;
}
#else
void func_0011E2F8(void) {
    func_0011C5F0(1, 0, 720);
    func_0011C5D8(0, 0, 0x3000, 480, 1, 240);
    D_002BD8B4 = 0;
}
#endif

#ifdef VERSION_FM
void func_0011E340(void) {
    D_002C1390 = 1;
}
#else
void func_0011E340(void) {
    D_002BD8E0 = 1;
}
#endif

#ifdef VERSION_FM
void func_0011E528(void) {
    D_002C1390 = 0;
}
#else
void func_0011E350(void) {
    D_002BD8E0 = 0;
}
#endif

#ifdef VERSION_FM
extern s32 D_002B9314;
extern s32 D_002BD8DC;

void func_0011E360(void) {
    if (D_002B9314 == 0) {
        if (D_002C1390 == 0 && D_002BD8B8[0] != D_002BD8B8[1]) {
            s32 t = D_002C1EA8 & 1;

            if (t == 1) {
                if (D_002BD8DC == 0) {
                    func_0011E480();
                }
            } else if (D_002BD8DC == 1) {
                func_0011E4D0();
            }
        }
        D_002BD8DC = D_002C1EA8 & 1;
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/xturtle", func_0011E360);
#endif

#ifdef VERSION_FM
void func_0011E5F0(void) {
    func_0011C9A0();
    func_00101528();
}
#else
#ifdef VERSION_EU
void func_0011E418(void);
INCLUDE_ASM("asm/nonmatchings/xturtle", func_0011E418);
#else
void func_0011E418(void) {
    func_00101528();
}
#endif
#endif

#ifdef VERSION_FM
extern s32 D_004E3440;
extern s32 D_004E3438;
extern s32 D_004E343C;
void func_0011E610(void) {
    s32 t = D_002C1EA8 & 1;

    if (t == 1) {
        func_0011C5F0_v(0, 0, 0xF0);
        if (D_004E3440 == 0) {
            func_0011C7A8(1, 0x3000, 0x3000, 0, 0, 0x78);
        } else {
            func_0011C7A8(1, 0, D_004E3438, D_004E343C, 0, 0x78);
        }
        D_002C1364 = 1;
    } else {
        func_0011C5F0_v(1, 0, 0xF0);
        if (D_004E3440 == 0) {
            func_0011C7A8(0, 0x3000, 0x3000, 0, 0, 0x78);
        } else {
            func_0011C7A8(0, 0, D_004E3438, D_004E343C, 0, 0x78);
        }
        D_002C1364 = 0;
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/xturtle", func_0011E430);
#endif

#ifdef VERSION_FM
extern s32 D_002BD8D8;
extern s32 D_004E3444;
extern void (*D_004E3434)(void);
void func_0011E700(void) {
    if (D_002BD8D8 == 0) {
        func_0011E528();
    }
    if (D_004E3444 == 0) {
        func_0011E610();
    }
    if (D_004E3434 != NULL) {
        D_004E3434();
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/xturtle", func_0011E520);
#endif

#ifdef VERSION_FM
void func_0011E758(void) {
    if (D_002BD8D8 == 0) {
        func_0011E528();
    }
    if (D_004E3444 == 0 && D_002BD8D8 == 0) {
        func_0011E610();
    }
    if (D_004E3434 != NULL) {
        D_004E3434();
    }
}
#else
void func_0011E520();

INCLUDE_ASM("asm/nonmatchings/xturtle", func_0011E578);
#endif

#ifdef VERSION_FM
void fm_func_0011E7C8(s32 arg0, s32 arg1, s32 arg2) {
    func_0011CBE0(0, arg2, D_002C1378, func_0011E700);
}
#else
s32 func_0011E5E8(UNK_TYPE arg0, UNK_TYPE arg1, s32 arg2) {
    return func_0011CA10(0, arg2, D_002BD8C8, func_0011E520);
}
#endif

#ifdef VERSION_FM
void func_0011CA68(s32, char*);
extern s32 D_004E3448;
void func_0011E7F8(void) {
    char buf[0x40];

    if (D_002BD8B8[0] != D_002C1378 && D_002C1378 != 0) {
        if (D_002BD8B8[1] == -2) {
            func_0011C7D8(0);
        } else {
            func_0011C5F0(0, 0, 0x64);
        }
        func_0011CA68(D_002C1378, buf);
        func_00120590(buf, D_004E3448, (s32 (*)(void))fm_func_0011E7C8, 0);
        return;
    }
    func_0011E758();
}
#else
INCLUDE_ASM("asm/nonmatchings/xturtle", func_0011E618);
#endif

#ifdef VERSION_FM
void func_0011E8A0(s32 arg0, s32 arg1, s32 arg2) {
    func_0011CBE0(1, arg2, D_002C137C, func_0011E7F8);
}
#else
void func_0011E618();

s32 func_0011E6C0(UNK_TYPE arg0, UNK_TYPE arg1, s32 arg2) {
    return func_0011CA10(1, arg2, D_002BD8CC, func_0011E618);
}
#endif

#ifdef VERSION_FM
extern s32 D_002C136C;
void func_0011CA68_nt() __asm__("func_0011CA68");
extern inline void func_0011CA68_nt(nothrow_arg_) double nothrow_arg_; {}
extern s32 D_004E3434_i __asm__("D_004E3434");
extern s32 D_002C1378_a[] __asm__("D_002C1378");

void func_0011E8D0(s32 a0, s32 a1, s32 a2, s32 a3, s32 a4, s32 a5) {
    char buf[0x40];

    D_004E3434_i = a3;
    D_004E3438 = a1;
    D_004E343C = a2;
    D_004E3440 = a0;
    D_004E3444 = a4;
    D_004E3448 = a5;
    if (D_002C136C != D_002C1378_a[1] && D_002C1378_a[1] != 0) {
        if (D_002C136C == -2) {
            func_0011C7D8(0);
        } else {
            func_0011C5F0(1, 0, 0x64);
        }
        func_0011CA68_nt(D_002C1378_a[1], buf);
        func_00120590(buf, D_004E3448, (s32 (*)(void))func_0011E8A0, 0);
        return;
    }
    func_0011E7F8();
}
#else
INCLUDE_ASM("asm/nonmatchings/xturtle", func_0011E6F0);
#endif

#ifdef VERSION_FM
void func_0011E7C8(s32 arg0, s32 arg1) {
    func_0011E8D0(0, 0x3000, 0, arg0, 0, arg1);
}
#else
void func_0011E7C8(s32 arg0, void* arg1) {
    func_0011E6F0(0, 0x3000, 0, arg0, 0, arg1);
}
#endif

#ifdef VERSION_FM
void func_0011E9D8(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    func_0011E8D0(1, arg0, arg1, arg2, 0, arg3);
}
#else
void func_0011E7F8(s32 arg0, s32 arg1, s32 arg2, void* arg3) {
    func_0011E6F0(1, arg0, arg1, arg2, 0, arg3);
}
#endif

#ifdef VERSION_FM
void func_0011E830(s32 arg0, s32 arg1) {
    func_0011E8D0(0, 0x3000, 0, arg0, 1, arg1);
}
#else
void func_0011E830(s32 arg0, void* arg1) {
    func_0011E6F0(0, 0x3000, 0, arg0, 1, arg1);
}
#endif

#ifdef VERSION_FM
INCLUDE_ASM("asm/nonmatchings/xturtle", func_0011EA40);
#else
INCLUDE_ASM("asm/nonmatchings/xturtle", func_0011E860);
#endif

#ifdef VERSION_FM
INCLUDE_ASM("asm/nonmatchings/xturtle", func_0011EAE0);
#else
INCLUDE_ASM("asm/nonmatchings/xturtle", func_0011E900);
#endif

#ifdef VERSION_FM
void* func_0011EB88(s32 a0, s32 a1, s32 a2, void (*a3)(void)) {
    D_002BD8B8[a0] = -1;
    D_004E3430 = a3;
    func_001EE1E0(1, a0);
    func_001EE518(a0, a1, a2);
    return func_0011ED30(10000, func_0011CBA0);
}
#else
void* func_0011E9A8(s32 arg0, s32 arg1, s32 arg2, void* arg3) {
    D_002BD8B8[arg0] = -1;
    D_004DCB70 = arg3;
    func_001EE1E0(1, arg0);
    func_001EE518(arg0, arg1, arg2);
    return TaskSystem_AddTask(10000, func_0011C9D0);
}
#endif

#ifdef VERSION_FM
void func_001EE710(s32, u8 *, s32);
void *func_0011ED30(s32, s32 (*)(void));

void func_0011EC08(s32 a0, u8 *a1, s32 a2, void (*cb)(void)) {
    D_004E3430 = cb;
    if (*(s32 *)(a1 + 4) > 0x7547F) {
        D_002BD8B8[0] = -2;
        D_002BD8B8[1] = -2;
        func_001EE1E0(0, 0);
        func_001EE1E0(0, 1);
        if (a0 == 1) {
            a0 = 0;
        }
    } else {
        D_002BD8B8[a0] = -1;
        func_001EE1E0(0, a0);
    }
    func_001EE710(a0, a1, a2);
    func_0011ED30(10000, func_0011CBA0);
}
#else
INCLUDE_ASM("asm/nonmatchings/xturtle", func_0011EA28);
#endif
