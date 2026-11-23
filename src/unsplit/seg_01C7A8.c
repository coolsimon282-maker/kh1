// Placeholder for code that hasn't been assigned to a source file yet (Final Mix offset 0x01C7A8).
// Functions can be matched here like in any other file; the file may be split later.
#include "common.h"
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
s32 func_0011E248(void);
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

void* func_0011C5F0(s32 arg0, s32 arg1, s32 arg2) {
    return func_001EE618(arg0, arg1, arg2);
}

void* func_0011C7D8(s32 arg0) {
    return func_001EE5D8(arg0);
}

void* func_0011C7F0(void* arg0) {
    return func_001EE660(arg0);
}

void* func_0011C808(void* arg0) {
    return func_001EE6B8(arg0);
}

s32 func_0011C820(void) {
    return func_001EE090();
}

void* func_0011C838(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    return func_001EE330(arg0, arg1, arg2, arg3, arg4);
}

void* func_0011C850(s32 arg0, s32 arg1, s32 arg2) {
    return func_001EE390(arg0, arg1, arg2);
}

void* func_0011C868(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    return func_001EE428(arg0, arg1, arg2, arg3, arg4);
}

void* func_0011C880(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    return func_001EE478(arg0, arg1, arg2, arg3, arg4);
}

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_01C7A8", func_0011C6C8);

void func_0011C9A0(void) {
    D_004E3A40 = 0;
}

void func_0011C9B0(void) {
    D_004E3A40 = 1;
}

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_01C7A8", func_0011C9C0);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_01C7A8", func_0011CA68);

void func_0011C938(char* a0) {
    char buf[16];
    *(Seg1C7A8Str10*)a0 = D_0048D130;
    worldfile_getAbbr(D_002B8678, buf);
    strcat(a0, buf);
    strcat(a0, D_0048D128);
}

s32 func_0011CB80(void* arg0) {
    return func_00120438(D_0048D140, arg0);
}

s32 func_0011CBA0(void) {
    if (func_001EE090() != 0) return 0;
    if (D_004E3430 != 0) D_004E3430();
    return 4;
}

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_01C7A8", func_0011CBE0);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_01C7A8", func_0011CD20);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_01C7A8", func_0011CC20);

void func_0011CF88(s32 arg0, s32 arg1, s32 arg2, s32 arg3, u8 arg4, Seg1C7A8Unk18* arg5, s32 arg6) {
    arg5->unk_00 = arg0;
    arg5->unk_10 = arg1;
    arg5->unk_04 = arg2;
    arg5->unk_08 = arg3;
    arg5->unk_16 = arg4;
    arg5->unk_15 = 0;
    arg5->unk_0C = arg6;
}

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

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_01C7A8", func_0011D028);

void func_0011D080(s32 a0, s32 a1) {
    func_0011C838(a0 < 1000 ? 2 : -8, a0, a1, 0x3FFF, 0x3FFF);
    func_0011D028(a0, a1);
}

void* func_0011D0D8(s32 arg0, s32 arg1) {
    return func_0011C850(arg0 < 1000 ? 2 : -8, arg0, arg1);
}

void* func_0011D108(s32 arg0, s32 arg1, s32 arg2) {
    return func_0011C868(arg0 < 1000 ? 2 : -8, arg0, arg1, -1, arg2);
}

void* func_0011D140(s32 arg0, s32 arg1) {
    return func_0011C838(arg0 < 1000 ? 2 : -1, arg0, arg1, 0x3FFF, 0x3FFF);
}

void* func_0011D178(s32 arg0, s32 arg1) {
    return func_0011C850(arg0 < 1000 ? 2 : -1, arg0, arg1);
}

void* func_0011D1A8(s32 arg0, s32 arg1, s32 arg2) {
    return func_0011C868(arg0 < 1000 ? 2 : -1, arg0, arg1, -1, arg2);
}

void func_0011D1E0(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    Seg1C7A8Unk18* p = func_0011CFA8(arg0, arg1, arg2, arg3, 0);

    if (p != NULL) {
        p->unk_14 = 1;
    }
}

void func_0011D210(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    Seg1C7A8Unk18* p = func_0011CFA8(arg0, arg1, arg2, arg3, 1);

    if (p != NULL) {
        p->unk_14 = 2;
    }
}

void func_0011D070(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    Seg1C7A8Unk18* p = func_0011CFA8(arg0, arg1, arg2, arg3, 2);

    if (p != NULL) {
        p->unk_14 = 1;
    }
}

void func_0011D270(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    Seg1C7A8Unk18* p = func_0011CFA8(arg0, arg1, arg2, arg3, 3);

    if (p != NULL) {
        p->unk_14 = 2;
    }
}

void func_0011D2A0(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    Seg1C7A8Unk18* p = func_0011CFA8(arg0, arg1, arg2, arg3, 4);

    if (p != NULL) {
        p->unk_14 = 2;
    }
}

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

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_01C7A8", func_0011D310);

void func_0011D588(void) {
    s32 i;
    for (i = 0; i < 2; i++) {
        func_0011D070(D_002A0520[i], i, (s32)D_002B9040, 0x3FFF);
    }
}

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

void func_0011D4B8(s32 a0) {
    s32 i;
    for (i = 0; i < 2; i++) {
        func_0011C868_v(-1, D_002A0520[i], i, -1, a0);
    }
}

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

void* func_0011D598(s32 arg0) {
    return func_0011C838(2, arg0, 0, 0x3FFF, 0x3FFF);
}

void* func_0011D790(s32 arg0, s32 arg1) {
    s32 v = arg1 == 0 ? 0x3FFF : 0x1FFF;

    return func_0011C880(2, arg0, 0, v, v);
}

void* func_0011D7C0(s32 arg0) {
    return func_0011C850(2, arg0, 0);
}

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_01C7A8", func_0011D7E0);

void func_0011DB50(s32* a, s32* b) {
    if (*a < 0) *a = 0;
    if (*b < 0) *b = 0;
    if (*a >= 0x4000) *a = 0x3FFF;
    if (*b >= 0x4000) *b = 0x3FFF;
}

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

void func_0011DC98(u8* a0) {
    s32 i;
    if (D_002BBDE0 != 3) {
        for (i = 0; i < 4; i++) {
            if (*(s32*)a0 == D_002C1310[i]) a0[0x14] = 0;
        }
    }
}

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_01C7A8", func_0011DCF0);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_01C7A8", func_0011DDD0);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_01C7A8", func_0011DE90);

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

void func_0011E220(void* arg0, s32 arg1, s32 arg2, s32 arg3) {
    func_001EDD20(arg0, arg1, arg2, arg3);
    func_0011E1C8(arg0);
}

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_01C7A8", func_0011E248);

void fm_func_0011E340(void) {
    D_002C1394 = func_0011E248();
}

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_01C7A8", func_0011E368);

void func_0011E480(void) {
    func_0011C5F0(0, 0, 0x3C0);
    func_0011C7A8_v(1, 0, 0x3000, 0xF0, 0, 0xF0);
    D_002C1364 = 1;
}

void func_0011E4D0(void) {
    func_0011C5F0(1, 0, 0x2D0);
    func_0011C7A8_v(0, 0, 0x3000, 0x1E0, 1, 0xF0);
    D_002C1364 = 0;
}

void func_0011E340(void) {
    D_002C1390 = 1;
}

void func_0011E528(void) {
    D_002C1390 = 0;
}

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_01C7A8", func_0011E360);

void func_0011E5F0(void) {
    func_0011C9A0();
    func_00101528();
}

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

void fm_func_0011E7C8(s32 arg0, s32 arg1, s32 arg2) {
    func_0011CBE0(0, arg2, D_002C1378, func_0011E700);
}

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_01C7A8", func_0011E7F8);

void func_0011E8A0(s32 arg0, s32 arg1, s32 arg2) {
    func_0011CBE0(1, arg2, D_002C137C, func_0011E7F8);
}

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_01C7A8", func_0011E8D0);

void func_0011E7C8(s32 arg0, s32 arg1) {
    func_0011E8D0(0, 0x3000, 0, arg0, 0, arg1);
}

void func_0011E9D8(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    func_0011E8D0(1, arg0, arg1, arg2, 0, arg3);
}

void func_0011E830(s32 arg0, s32 arg1) {
    func_0011E8D0(0, 0x3000, 0, arg0, 1, arg1);
}

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_01C7A8", func_0011EA40);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_01C7A8", func_0011EAE0);

void* func_0011EB88(s32 a0, s32 a1, s32 a2, void (*a3)(void)) {
    D_002BD8B8[a0] = -1;
    D_004E3430 = a3;
    func_001EE1E0(1, a0);
    func_001EE518(a0, a1, a2);
    return func_0011ED30(10000, func_0011CBA0);
}

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_01C7A8", func_0011EC08);
