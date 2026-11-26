#include "common.h"
#include "sdk/ee/eetypes.h"

extern s32 D_00351E10;
void func_00236DE8(f32 (*arg0)[4], f32 fparg0);
void func_00246438(void); void func_00246BC8(void); void fm_func_00247258(void); void func_00248400(void);
void func_00248EA0(void); void func_00249250(void);
extern void func_002370C8(void *);
extern void func_00237018(void *, s32, s32);
void func_00237548(f32 *arg0, f32 *arg1, f32 *arg2, f32 (*arg3)[4]);
int sceGsSyncPath(int mode, u_short timeout);
void func_002499F0(void);
extern void func_00245140(void);
extern void func_00248B00(void);
extern void func_00249240(void);
s32 func_001F0638_c(s32, s32, s32, s32, s32, s32) __asm__("func_001F0638");
void func_002475E8(s32, u8 *, s32);
s32 func_002388B8(u8 *, s32, s32);
extern u8 D_004267F0[];
void func_002477A8(u8 *, s32 *);
extern sceVu0FMATRIX D_002DEC20;
s32 func_00249580(f32 *);
void func_00249558(void *, void *);
typedef struct {
    /* 0x00 */ u8 pad[0x60];
    /* 0x60 */ s64 field_60;
    /* 0x68 */ u8 pad2[0x78];
    /* 0xE0 */ s64 field_E0;
} DataStruct;
void func_002479A0(s32);
void func_00247AA0(s32);
extern void func_00249A48(void *arg0, s32 arg1);
s32 func_002492E8(f32 *, s32);
void func_002492D0(f32 *, f32, f32, f32, f32);
void func_00247668();
s32 func_0011ED60();
typedef struct { s32 a; s32 b; s32 c; } Seg132E12;
typedef struct { s32 cap; Seg132E12* buf; s32 cnt; s32 rd; } Seg132Q;
typedef struct { s32 a; s32 b; f32 c; } Seg132Msg;
typedef struct { s32 a; s32 b; s32 c; } Seg132V3;
typedef struct { s32 flag; Seg132V3 v; s32 z; } Seg132Slot;
void func_00247B60();
extern void func_002479A0(s32);
extern void func_00247AA0(s32);
void func_00246BC8(void);
void fm_func_00247258(void);
extern s32 D_006691D0;
void func_002474E8(s32 a0, u8 *a1, s32 x, s32 y, f32 f);
void func_002475D0(s32 x, s32 y, u8 *c, f32 f, char *s, s32 font);

INCLUDE_ASM("asm/nonmatchings/unsplit/xcapy", func_00247930);

extern s32 D_006693B0[];
extern u8 D_006692C0[];
extern void func_002476A0(void *arg0);
extern void func_00247930(void *arg0);

void func_00247B50(void *arg0) {
    s32 *ptr = D_006693B0;
    s32 counter = 7;

    do {
        s32 val = *ptr;
        ptr++;
        counter--;
        func_002474E8(val, D_006692C0, *(s32 *)((u8 *)arg0 + 0x24), *(s32 *)((u8 *)arg0 + 0x28), 1.0f);
    } while (counter >= 0);

    func_002476A0(arg0);
    func_00247930(arg0);
}

extern s32 D_00669390[];
extern u8 D_006692C0[];
extern void func_002474E8(s32 arg0, u8 *arg1, s32 arg2, s32 arg3, f32 arg4);
extern void func_002476A0(void *arg0);
extern void func_00247930(void *arg0);

void func_00247BD0(void *arg0) {
    s32 *ptr = &D_00669390;
    s32 counter = 7;

    do {
        s32 val = *ptr;
        ptr++;
        counter--;
        func_002474E8(val, D_006692C0, *(s32 *)((u8 *)arg0 + 0x24), *(s32 *)((u8 *)arg0 + 0x28), 1.0f);
    } while (counter >= 0);

    func_002476A0(arg0);
    func_00247930(arg0);
}

extern void func_002474E8(s32 arg0, u8 *arg1, s32 arg2, s32 arg3, f32 arg4);
extern void func_002476A0(void *arg0);

extern s32 D_006693D0[];
extern u8 D_006692C0[];

void func_00247C50(void *arg0) {
    s32 *ptr = &D_006693D0;
    s32 counter = 6;

    do {
        s32 val = *ptr;
        ptr++;
        counter--;
        func_002474E8(val, D_006692C0, *(s32 *)((u8 *)arg0 + 0x24), *(s32 *)((u8 *)arg0 + 0x28), 1.0f);
    } while (counter >= 0);

    func_002476A0(arg0);
}

extern void func_00249A48(void *, s32);
extern u8 D_00431F30[];

void func_00247CC8(s32 arg0) {
    func_00249A48((void *)((u8 *)&D_00431F30 + arg0 * 0x1770), 1);
}

typedef struct { u8 pad[8]; s32 unk8; s32 unkC; s32 unk10; s32 unk14; } Seg132_7CF8;
int sprintf(char *, const char *, ...);
void func_002475D0(s32 x, s32 y, u8 *col, f32 f, char *s, s32 font);
extern s32 D_00467408;
extern char D_004917D8[];
extern char D_004917F0[];
extern char D_004917F8[];
extern char D_00491800[];
extern char D_00491808[];

void func_00247CF8(Seg132_7CF8 *a0) {
    char buf[16];
    u8 col[3];

    col[0] = 0xFF;
    col[1] = 0xFF;
    col[2] = 0xFF;
    switch (a0->unkC) {
    case 1:
        sprintf(buf, D_004917F0, a0->unk10);
        func_002475D0(0x45, 0x16, col, 1.0f, buf, D_00467408);
        if (a0->unk8 != 0) {
            sprintf(buf, D_004917F8);
            func_002475D0(0x54, 0x16, col, 1.0f, buf, D_00467408);
            sprintf(buf, D_004917F0, a0->unk14);
            func_002475D0(0x61, 0x16, col, 1.0f, buf, D_00467408);
        }
        break;
    case 2:
        sprintf(buf, D_004917D8, a0->unk10);
        func_002475D0(0x45, 0x16, col, 1.0f, buf, D_00467408);
        if (a0->unk8 != 0) {
            sprintf(buf, D_004917F8);
            func_002475D0(0x61, 0x16, col, 1.0f, buf, D_00467408);
            sprintf(buf, D_004917D8, a0->unk14);
            func_002475D0(0x6E, 0x16, col, 1.0f, buf, D_00467408);
        }
        break;
    case 3:
        sprintf(buf, D_00491800, a0->unk10);
        func_002475D0(0x45, 0x16, col, 1.0f, buf, D_00467408);
        if (a0->unk8 != 0) {
            sprintf(buf, D_004917F8);
            func_002475D0(0x6E, 0x16, col, 1.0f, buf, D_00467408);
            sprintf(buf, D_00491800, a0->unk14);
            func_002475D0(0x7B, 0x16, col, 1.0f, buf, D_00467408);
        }
        break;
    case 4:
        sprintf(buf, D_00491808, a0->unk10);
        func_002475D0(0x45, 0x16, col, 1.0f, buf, D_00467408);
        if (a0->unk8 != 0) {
            sprintf(buf, D_004917F8);
            func_002475D0(0x7B, 0x16, col, 1.0f, buf, D_00467408);
            sprintf(buf, D_00491808, a0->unk14);
            func_002475D0(0x88, 0x16, col, 1.0f, buf, D_00467408);
        }
        break;
    }
}

extern char D_00491810[];
extern char D_00491818[];
extern s32 D_0046740C;

void func_00248010(Seg132_7CF8 *a0) {
    char buf[16];
    u8 col[3];
    s32 x;

    col[0] = 0xFF;
    col[1] = 0xFF;
    col[2] = 0xFF;
    sprintf(buf, D_00491810, *(s32 *)((u8 *)a0 + 0x1C));
    func_002475D0(0x45, 0x16, col, 1.0f, buf, D_00467408);
    x = 0x45;
    x += strlen(buf) * 13;
    sprintf(buf, D_00491818);
    func_002475D0(x + 2, 0x18, col, 1.0f, buf, D_0046740C);
}

extern u8 D_00669320[];
extern s32 D_00669388[];

void fm_func_002480D8(void) {
    s32 i;
    for (i = 0; i < 2; i++) {
        func_002474E8(D_00669388[i], D_00669320, 0, 0, 1.0f);
    }
}

extern u_long128 *D_006691D0_p __asm__("D_006691D0");
extern u_long128 *D_006691D4;
void func_002393D8(void);
void func_00247B50(void *);
void fm_func_002480D8_a(void *) __asm__("fm_func_002480D8");

void func_00248140(u8 *a0) {
    u8 *s;

    D_006691D4 = (u_long128 *)&D_00351E10;
    D_006691D0_p = (u_long128 *)&D_00351E10 + 1;
    s = *(u8 **)(a0 + 4);
    func_002393D8();
    if (*(s32 *)(s + 0x20) != 0) {
        if (*(s32 *)(s + 0x30) == 0) {
            func_00247C50(s);
        } else if (*(s32 *)(s + 0x2C) == 0) {
            func_00247BD0(s);
        } else {
            func_00247B50(s);
        }
    }
    if (*(s32 *)(s + 4) != 0 || *(s32 *)(s + 0x18) != 0) {
        fm_func_002480D8_a(s);
    }
    if (*(s32 *)(s + 4) != 0) {
        func_00247CF8((Seg132_7CF8 *)s);
    }
    if (*(s32 *)(s + 0x18) != 0) {
        func_00248010((Seg132_7CF8 *)s);
    }
    func_00237018(D_006691D4, D_006691D0_p - D_006691D4, 1);
}

typedef struct {
    s32 a[8];
    s32 c[4][4];
} Seg132_6693F0;
extern Seg132_6693F0 D_006693F0;
extern u64 D_00669490;
extern u64 D_00491820;
extern u8 D_00431D50[][0x30];

void func_00248238(u8 *a0) {
    Seg132_7CF8 *s = *(Seg132_7CF8 **)(a0 + 4);
    s32 i;

    if (*(s32 *)((u8 *)s + 4) != 0 || *(s32 *)((u8 *)s + 0x18) != 0) {
        D_006691D4 = (u_long128 *)&D_00351E10;
        D_006691D0_p = (u_long128 *)&D_00351E10 + 1;
        func_00247CC8(*(s32 *)s);
        D_006693F0.a[0] = 0xC;
        D_006693F0.a[1] = 0xF;
        D_006693F0.a[2] = 0x40;
        D_006693F0.a[3] = 0x40;
        D_006693F0.a[4] = 0;
        D_006693F0.a[5] = 0;
        D_006693F0.a[6] = 0x3F;
        D_006693F0.a[7] = 0x3F;
        for (i = 0; i < 4; i++) {
            D_006693F0.c[i][0] = 0x80;
            D_006693F0.c[i][1] = 0x80;
            D_006693F0.c[i][2] = 0x80;
            D_006693F0.c[i][3] = 0x80;
        }
        D_00669490 = D_00491820;
        func_002474E8((s32)((u8 *)&D_00669490 - 0xA0), D_00431D50[*(s32 *)s], 0, 0, 1.0f);
        func_00237018(D_006691D4, D_006691D0_p - D_006691D4, 1);
    }
}

extern void func_00248140_v(void **) __asm__("func_00248140");
extern void func_00248238_v(void **) __asm__("func_00248238");
extern void *D_00669350;
extern DataStruct D_00669070;

s32 func_00248380(void) {
    if (D_00669350 == NULL) {
        return 0;
    }
    func_002370C8(&D_00669070);
    D_00669070.field_E0 = 5;
    D_00669070.field_60 = 0x30003;
    func_00237018(&D_00669070, 0x16, 1);
    func_00248140_v(&D_00669350);
    func_00248238_v(&D_00669350);
    return 0;
}

extern u8 D_00669350_b[] __asm__("D_00669350");
extern u8 D_00669358[];
extern u64 D_006692D8;
extern u64 D_00669308;
extern u64 D_00669338;
extern u8 D_004656A0[];
extern u8 D_00465FD0[];
extern u8 D_00466180[];
extern u8 D_004667B0[];
extern u8 D_00466DE0[];
extern u8 D_00467350[];
extern u8 D_00467388[];
extern u8 D_00467398[];
extern u8 D_004673C0[];
extern u8 D_004673E8[];
extern s32 D_006693B0[];
s32 func_00248380();

void func_00248400(void) {
    memset(D_00669350_b, 0, 8);
    func_00247668(D_004656A0);
    func_00247668(D_00465FD0);
    func_00247668(D_00466180);
    func_00247668(D_004667B0);
    func_00247668(D_00466DE0);
    func_00247B60(D_00467350, D_00669358, D_004656A0);
    func_00247B60(D_00467388, D_00669388, D_00465FD0);
    func_00247B60(D_00467398, D_00669390, D_00466180);
    func_00247B60(D_004673C0, D_006693B0, D_004667B0);
    func_00247B60(D_004673E8, D_006693D0, D_00466DE0);
    D_006692D8 = 0x0007400621413600;
    D_00669308 = 0x0207400621413600;
    D_00669338 = 0x0607400621413600;
    if (func_0011ED60(func_00248380) == 0) {
        func_0011ED30(0x28489, func_00248380);
    }
}

extern s32 D_00669350_w[] __asm__("D_00669350");
void func_002485B8(s32 arg0) {
    D_00669350_w[0] = 1;
    D_00669350_w[1] = arg0;
}

extern void* D_00669350;

void func_00245130(void) {
    D_00669350 = NULL;
}

extern void* D_00669350;

void func_00245140(void) {
    D_00669350 = NULL;
}

s32 func_002485F0(void) {
    s32 r = 0;
    s32* p;

    if (D_00669350_w[0] == 1) {
        p = (s32*)D_00669350_w[1];
        r = p[8] != 0;
        if (p[1] != 0) {
            r |= 2;
        }
    }
    return r;
}

void func_00248628(void *arg0, s32 arg1, s32 arg2) {
    memset(arg0, 0, 0x10);
    ((s32 *)arg0)[0] = arg1;
    ((s32 *)arg0)[1] = arg2;
}

void func_00248678(Seg132Q* q, Seg132E12* e) {
    if (q->cnt != q->cap) {
        q->buf[q->cnt] = *e;
        q->cnt++;
    }
}

s32 func_002486C8(Seg132Q* q, Seg132E12* e) {
    if (q->cnt == q->rd) {
        return 0;
    }
    *e = q->buf[q->rd];
    q->rd++;
    if (q->cnt == q->rd) {
        q->rd = 0;
        q->cnt = 0;
    }
    return 1;
}

s32 func_00248738(Seg132Q* q, Seg132E12* e) {
    if (q->cnt == q->rd) {
        return 0;
    }
    *e = q->buf[q->rd];
    return 1;
}

void func_00248788(void *arg0) {
    *(u32 *)((u8 *)arg0 + 12) = 0;
    *(u32 *)((u8 *)arg0 + 8) = 0;
}

extern u8 D_00669620[];
extern s32 D_00669610;

void func_00248798(s32 a0, s32 a1, s32 a2, s32 a3) {
    s32 i;
    s32 *p;

    func_002475E8(a0, D_00669620, a1);
    p = (s32 *)(D_00669620 + 0xA4);
    for (i = 0; i < 4; i++) {
        p[i * 4 - 1] += a2 * 16;
        p[i * 4] += a3 * 16;
    }
    D_00669610 = func_002388B8(D_00669620, 1, D_00669610);
}

void func_00248798(s32, s32, s32, s32);                /* extern */

void func_00248840(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    if (arg0 != 0) {
        func_002479A0(arg1);
    }
    func_00247AA0(arg1);
    func_00248798(arg1, arg2, arg3, arg4);
}

extern s32 D_00469C94;
extern s32 D_00469C98;
extern s32 D_00669610;

void func_002488A8(s32 x, s32 y, s32 a2, s32 a3, f32 f) {
    u8 col[4];
    u8 *a;

    if (a3 != 0) {
        col[0] = 0x73;
        col[1] = 0x73;
        col[2] = 0x73;
        a = &col[3];
        *a = f * 128.0f;
    } else {
        col[0] = 0xE6;
        col[1] = 0xE6;
        col[2] = 0xE6;
        a = &col[3];
        *a = f * 128.0f;
    }
    D_00669610 = func_001F0638_c(D_00669610, 1, *(s32 *)col, (((x + D_00469C94) * 16 + 0x7000) >> 4) - 0x700,
                                 (((y + D_00469C98) * 16 + 0x7400) >> 4) - 0x740, a2);
}

void func_002477A8(u8 *, s32 *);
void func_002488A8(s32, s32, s32, s32, f32);

void func_002489C8(s32 a0, u8 *a1, s32 a2, s32 a3, s32 a4, s32 a5, s32 a6, s32 a7, f32 f) {
    s32 buf[4];
    s32 i;
    u8 *q = a1;

    for (i = 0; i < 7; i++) {
        func_00248840(a0, (s32)a1, a2, a4, a5);
        a1 += 0xC0;
    }
    func_00248840(a0, (s32)a1, a3, a4, a5);
    if (a6 != 0) {
        func_002477A8(q, buf);
        func_002488A8(a4 + buf[0], a5 + buf[1], a6, a7, f);
    }
}

extern u8 D_00669714[];
void func_00248AC8(s32 a0, s32 a1) {
    Seg132Msg m;

    m.b = a1;
    m.a = a0;
    m.c = 1.0f;
    func_00248678((Seg132Q*)D_00669714, (Seg132E12*)&m);
}

extern s32 D_00669700;

void func_00248B00(void) {
    D_00669700 = 0;
    func_00248788((u8 *)&D_00669700 + 0x14);
}

extern Seg132Slot D_00669700_s __asm__("D_00669700");
void func_00248B28(Seg132V3* a0) {
    D_00669700_s.z = 0;
    D_00669700_s.v = *a0;
    D_00669700_s.flag = 1;
}

INCLUDE_ASM("asm/nonmatchings/unsplit/xcapy", func_00248B58);

void func_00248B58(s32);

s32 func_00248E30(void) {
    Seg132E12 e;
    s32 r = 0;
    s32 *d = &D_00669700;

    if (*d == 0) {
        if (func_002486C8((Seg132Q *)(d + 5), &e) == 0) {
            return 0;
        }
        func_00248B28((Seg132V3 *)&e);
    } else {
        r = func_00248738((Seg132Q *)(d + 5), &e) != 0;
    }
    func_00248B58(r);
    return 0;
}

extern u8 D_00467410[];
extern u8 D_00468220[];
extern u8 D_00468E10[];
extern u8 D_00469C20[];
extern u8 D_00469C48[];
extern u8 D_00469C70[];
extern u8 D_00669760[];

void func_00248EA0(void) {
    memset(&D_00669700, 0, 0x60);
    func_00248628((u8 *)&D_00669700 + 0x14, 5, (s32)((u8 *)&D_00669700 + 0x24));
    D_00669700 = 0;
    func_00247668(D_00467410);
    func_00247668(D_00468220);
    func_00247668(D_00468E10);
    func_00247B60(D_00469C20, D_00669760, D_00467410);
    func_00247B60(D_00469C48, D_00669760 + 0x20, D_00468220);
    func_00247B60(D_00469C70, D_00669760 + 0x40, D_00468E10);
    if (func_0011ED60(func_00248E30) == 0) {
        func_0011ED30(0x29811, func_00248E30);
    }
}

extern u8 D_00669930[];
extern s32 D_00669920;
void func_002475E8(s32, u8*, s32);
s32 func_002388B8(u8*, s32, s32);
void func_00248FB8(s32 a0, s32 a1) {
    func_002475E8(a0, D_00669930, a1);
    D_00669920 = func_002388B8(D_00669930, 1, D_00669920);
}

extern u64 D_006697C0[];
extern u_long128 *D_00669924;
extern u_long128 *D_00669920_p __asm__("D_00669920");
extern s32 D_00669A10[];
extern u8 D_004267F0[];

void func_00249010(void) {
    s32 *p;
    s32 i;
    func_002370C8(D_006697C0);
    D_006697C0[0x1C] = 5;
    D_006697C0[0xC] = 0x30003;
    D_006697C0[0xE] = 0x8000000048;
    func_00237018(D_006697C0, 0x16, 1);
    D_00669924 = (u_long128 *)&D_00351E10;
    D_00669920_p = (u_long128 *)&D_00351E10 + 1;
    for (i = 0; i < 2; i++) {
        func_00248FB8(D_00669A10[i], (s32)D_004267F0);
    }
    func_00237018(D_00669924, D_00669920_p - D_00669924, 1);
}

s32 func_00246D60(s32);

void func_002490F0(void **a0) {
    s32 *st = (s32 *)a0;
    s32 i;

    switch (*st) {
    case 1:
        for (i = 0; i < 2; i++) {
            func_002479A0(D_00669A10[i]);
        }
        (*st)++;
        break;
    case 2:
        for (i = 0; i < 2; i++) {
            func_00247AA0(D_00669A10[i]);
        }
        if (func_00246D60(D_00669A10[0]) & 4) {
            (*st)++;
        }
        break;
    case 3:
        *st = 0;
        return;
    }
    func_00249010();
}

extern void* D_00469F60;
extern void func_002490F0(void **);

s32 func_002491F8(void) {
    if (D_00469F60 == NULL) {
        return 0;
    }
    func_002490F0(&D_00469F60);
    return 0;
}

extern void* D_00469F60;

// func_00249230 (src/unsplit/seg_132D60.c)
void func_00249230(void) {
    D_00469F60 = (void *)1;
}

extern void* D_00469F60;

void func_00249240(void) {
    D_00469F60 = NULL;
}

extern u8 D_00469CA0[];
extern u8 D_00469F50[];
extern s32 D_00669A10[];

void func_00249250(void) {
    D_00469F60 = NULL;
    func_00247668(D_00469CA0);
    func_00247B60(D_00469F50, D_00669A10, D_00469CA0);
    if (func_0011ED60(func_002491F8) == 0) {
        func_0011ED30(0x28489, func_002491F8);
    }
}

void func_002492D0(f32* v, f32 x, f32 y, f32 z, f32 w) {
    v[0] = x;
    v[1] = y;
    v[3] = z;
    v[2] = w;
}

extern s32 D_002C5960;

s32 func_002492E8(f32 *arg0, s32 arg1) {
    if (arg0[1] != 0.0f) {
        if ((D_002C5960 & 1) == 0) {
            f32 tmp = (f32)arg1;
            arg0[0] += arg0[1] * tmp;
        }
        if (arg0[0] <= 0.0f) {
            arg0[0] = 0.0f;
            arg0[1] = 0.0f;
            return 2;
        }
        if (arg0[0] >= 128.0f) {
            arg0[0] = 128.0f;
            arg0[1] = 0.0f;
            return 1;
        }
    }
    return 0;
}

s32 func_00249370(sceVu0FMATRIX arg0, sceVu0FMATRIX arg1, sceVu0FVECTOR arg2) {
    sceVu0RotMatrixZ(arg0, arg1, arg2[2]);
    sceVu0RotMatrixX(arg0, arg0, arg2[0]);
    sceVu0RotMatrixY(arg0, arg0, arg2[1]);
}

void func_002493C0(sceVu0FMATRIX out, sceVu0FVECTOR tv, sceVu0FVECTOR rot) {
    sceVu0FMATRIX m;

    sceVu0UnitMatrix(m);
    func_00249370(m, m, rot);
    sceVu0TransMatrix(out, m, tv);
}

INCLUDE_ASM("asm/nonmatchings/unsplit/xcapy", func_00249420);

void func_00249518(sceVu0FMATRIX arg0, f32 arg1) {
    sceVu0UnitMatrix(arg0);
    arg0[2][2] = arg1;
    arg0[1][1] = arg1;
    arg0[0][0] = arg1;
}

void func_00249558(void *arg0, void *arg1) {
    *(s32 *)arg0 = (*(s32 *)arg1 - 0x7000) >> 4;
    *(s32 *)((u8 *)arg0 + 4) = (*(s32 *)((u8 *)arg1 + 4) - 0x7400) >> 4;
}

extern sceVu0FVECTOR D_00469F90;
extern sceVu0FVECTOR D_00469FA0;
extern sceVu0FMATRIX D_002DEC20;
s32 func_00249580(f32* a0) {
    sceVu0FVECTOR v;

    sceVu0CopyVector(v, a0);
    return sceVu0ClipAll(D_00469F90, D_00469FA0, D_002DEC20, (sceVu0FVECTOR*)v, 1) != 0;
}

// func_002495C8 (src/unsplit/seg_132D60.c)
void func_002495C8(void *arg0, f32 fparg0, f32 fparg1, f32 fparg2, f32 fparg3) {
    f32 t, u, v;
    t = fparg0 * -3.0f;
    u = fparg0 + fparg0;
    v = fparg1 * 3.0f;
    t = t + v;
    ((f32 *)arg0)[3] = fparg0;
    ((f32 *)arg0)[2] = fparg2;
    t = t - (fparg2 + fparg2);
    u = u - (fparg1 + fparg1);
    t = t - fparg3;
    u = u + fparg2;
    ((f32 *)arg0)[1] = t;
    u = u + fparg3;
    ((f32 *)arg0)[0] = u;
}

INCLUDE_ASM("asm/nonmatchings/unsplit/xcapy", func_00249618);

INCLUDE_ASM("asm/nonmatchings/unsplit/xcapy", func_00249718);

void func_002497B8(sceVu0FVECTOR v, sceVu0FVECTOR d, f32 s) {
    sceVu0FVECTOR t;
    sceVu0FVECTOR u;

    sceVu0CopyVector(t, d);
    t[3] = 0.0f;
    sceVu0ScaleVectorXYZ(u, t, s);
    sceVu0AddVector(v, v, u);
}

void func_00249820(s32 *dst, s32 *src) {
    s32 i;
    for (i = 0; i < 4; i++) {
        dst[i] = src[i];
    }
}

void func_00249858(f32 *arg0, f32 *arg1) {
    sceVu0CopyVector(arg0, (f32 *)((u8 *)arg1 + 0x20));
}

void func_00249870(void) {
    ((void (*)(void))sceVu0CopyVector)();
}

void func_00249888(f32 *arg0, f32 *arg1) {
    sceVu0CopyVector(arg0, (f32 *)((u8 *)arg1 + 0x10));
}

void func_002498A0(f32 *v) {
    if (*v < 3.1415926f) {
        *v += 6.2831853f;
    }
    if (*v > 3.1415926f) {
        *v += -6.2831853f;
    }
}

// func_00249900 (src/unsplit/seg_132D60.c)
void func_00249900(f32 *arg0, f32 *arg1) {
    sceVu0FVECTOR temp;
    sceVu0CopyVector(temp, arg0);
    sceVu0CopyVector(arg0, arg1);
    sceVu0CopyVector(arg1, temp);
}

f32 func_00249950(f32 *arg0, f32 fparg0, f32 fparg1) {
    f32 var_f0;
    var_f0 = *arg0;
    if (var_f0 < fparg0) {
        *arg0 = fparg0;
        var_f0 = fparg0;
    }
    if (fparg1 < var_f0) {
        *arg0 = fparg1;
        var_f0 = fparg1;
    }
    return var_f0;
}

void func_00249988(sceVu0FVECTOR out, sceVu0FVECTOR a, sceVu0FVECTOR b, f32 t) {
    sceVu0FVECTOR d;

    sceVu0SubVector(d, b, a);
    sceVu0ScaleVectorXYZ(d, d, t);
    sceVu0AddVector(out, a, d);
}

void func_002499F0(void) {
    u64 buf[6];

    sceGsSyncPath(0, 0);
    buf[2] = 0x1000000000008001;
    buf[3] = 0xE;
    buf[4] = 0;
    buf[5] = 0x3F;
    func_00237018(buf, 3, 1);
}

INCLUDE_ASM("asm/nonmatchings/unsplit/xcapy", func_00249A48);

extern void func_00249D48(s32 *);

void func_00249C48(void) {
    ((void (*)(void))func_00249D48)();
}

INCLUDE_ASM("asm/nonmatchings/unsplit/xcapy", func_00249C60);

typedef struct { s32 n; s32 e[1]; } Seg132_249D20;
s32 func_00249D20(Seg132_249D20* p, s32 a1) {
    p->e[p->n] = a1;
    p->n++;
    return a1 + 0x10;
}

void func_00249D48(s32 *arg0) {
    *arg0 = 0;
}

typedef struct { u64 x : 14; u64 pad : 23; u64 y : 14; } Seg132_249D50;
void func_00249D50(u8* p, s32 x, s32 y) {
    Seg132_249D50* f = (Seg132_249D50*)(p + 0x28);

    f->x = x;
    f->y = y;
}

s32 func_00249DA0(s32 arg0) {
    return arg0 + 0x10;
}

extern char D_00491840[];

void func_00249DA8(const char *s1) {
    strncmp(s1, D_00491840, 4);
}

INCLUDE_ASM("asm/nonmatchings/unsplit/xcapy", func_00249DC8);

void func_00249EB8(void *arg0, void *arg1) {
    u8 *src;
    u8 *dst;
    int i;
    s32 offset;
    src = (u8 *)arg1 + 0x40;
    offset = *(u32 *)((u8 *)arg1 + 0x18);
    src += offset;
    dst = (u8 *)arg0;
    for (i = 0; i < 64; i++) {
        if (i < 32) {
            dst[i] = src[i];
        } else {
            dst[i + 0x20] = src[i];
        }
    }
}

#include "sdk/ee/eestruct.h"
u8 *func_00249F08(u8 *p, s32 tbp, s32 psm, s32 cbp, s32 csa, s32 cld) {
    sceGsTex0 *t = (sceGsTex0 *)(p + 0x28);
    t->TBP0 = tbp;
    t->PSM = psm;
    t->CBP = cbp;
    t->CSA = csa;
    t->CLD = cld;
    return p + 0x10;
}
