#include "common.h"
#include "sdk/ee/eetypes.h"

extern u64 D_006477B0[];
void func_00233AC8(void);
void func_00233A80(void) {
    u64* p;
    s32 i;

    sceMcInit();
    p = D_006477B0;
    for (i = 0x100; i > 0; i--) {
        *p++ = 0;
    }
    func_00233AC8();
}

INCLUDE_ASM("asm/nonmatchings/unsplit/memcard", func_00233AC8);

typedef struct { s32 a; s32 id; u8 pad[0x18]; } Q233D08;
extern Q233D08 D_006477B0_r[] __asm__("D_006477B0");
extern s32 D_00647FB8;
extern s32 D_00647FBC;
extern s32 D_00647FB0_r __asm__("D_00647FB0");
extern s32 D_00647FC4_r __asm__("D_00647FC4");
s32 func_00233D08(s32 id) {
    s32 i;

    if (id != 0) {
        for (i = D_00647FBC; i != D_00647FB8; i++, i &= 0x3F) {
            if (D_006477B0_r[i].id == id) {
                return 1;
            }
        }
        if (D_00647FB0_r != 0 && D_00647FC4_r == id) {
            return 1;
        }
    } else if (D_00647FB8 != D_00647FBC || D_00647FB0_r != 0) {
        return 1;
    }
    return 0;
}

typedef struct { s32 a; s32 id; u8 pad[0x18]; } Q132_20;
extern Q132_20 D_006477B0_q[] __asm__("D_006477B0");
extern s32 D_00647FB8;
extern s32 D_00647FBC;
extern s32 D_00647FB0_q __asm__("D_00647FB0");
extern s32 D_00647FC4_q __asm__("D_00647FC4");
void func_002365E0(void);
int sceGsSyncV(int);

void func_00233DB0(s32 id) {
    s32 i;

    if (id != 0) {
    again:
        for (i = D_00647FBC; i != D_00647FB8; i++, i &= 0x3F) {
            if (D_006477B0_q[i].id == id) {
                func_002365E0();
                sceGsSyncV(0);
                goto again;
            }
        }
        if (D_00647FB0_q != 0 && D_00647FC4_q == id) {
            do {
                func_002365E0();
                sceGsSyncV(0);
            } while (D_00647FB0_q != 0);
        }
    } else {
        while (D_00647FB8 != D_00647FBC || D_00647FB0_q != 0) {
            func_002365E0();
            sceGsSyncV(0);
        }
    }
}

extern s32 D_006477A8;

s32 func_00233EE8(void) {
    return D_006477A8;
}

extern s32 D_006477A8;
extern s32 D_00647FD4;
extern s32 D_00647FD8;
void func_00233EF8(s32 arg0) {
    D_006477A8 = 1;
    D_00647FD4 = arg0;
    D_00647FD8 = 0;
}

extern s32 D_006477A8;

void func_00233F18(void) {
    D_006477A8 = 0;
}

extern s32 D_00647FDC;
extern s32 D_00647FE0;

void func_00233F28(s32 arg0, s32 arg1) {
    D_00647FDC = arg0;
    D_00647FE0 = arg1;
}

extern s32 D_00425C48[];

s32 func_00233F40(s32 arg0, s32 arg1) {
    s32 *ptr = (s32 *)((s32)&D_00425C48 + (((arg0 * 4) + arg1) * 4));
    s32 val = *ptr;
    *ptr = 0;
    return val;
}

extern s32 D_00425C48[];

void func_00233F68(s32 arg0, s32 arg1) {
    s32 *ptr = (s32 *)((s32)&D_00425C48 + (((arg0 * 4) + arg1) * 4));
    *ptr = 0;
}

extern s32 D_00425C68[];

s32 func_00233F88(s32 arg0, s32 arg1) {
    s32 *ptr = (s32 *)((s32)&D_00425C68 + (((arg0 * 4) + arg1) * 4));
    s32 val = *ptr;
    *ptr = 0;
    return val;
}

extern s32 D_00425C68[];

void func_00233FB0(s32 arg0, s32 arg1) {
    *((s32 *)((s32)&D_00425C68 + (((arg0 * 4) + arg1) * 4))) = 0;
}

extern s32 D_00425C88[];

s32 func_00233FD0(s32 arg0, s32 arg1) {
    s32 *ptr = (s32 *)((s32)&D_00425C88 + (((arg0 * 4) + arg1) * 4));
    s32 val = *ptr;
    *ptr = 0;
    return val;
}

extern s32 D_00425C88[];

void func_00233FF8(s32 arg0, s32 arg1) {
    *((s32 *)((s32)&D_00425C88 + (((arg0 * 4) + arg1) * 4))) = 0;
}

typedef struct { s32 type; s32 serial; s32 arg[6]; } Ent2340;
extern Ent2340 D_Ent2340[] __asm__("D_006477B0");
extern s32 D_00647FB8;
extern s32 D_00647FC0;

s32 func_00234018(s32 a0, s32 a1, s32 a2) {
    s32 s;
    D_Ent2340[D_00647FB8].type = 1;
    D_Ent2340[D_00647FB8].serial = D_00647FC0;
    D_Ent2340[D_00647FB8].arg[0] = a0;
    D_Ent2340[D_00647FB8].arg[1] = a1;
    D_Ent2340[D_00647FB8].arg[2] = a2;
    D_00647FB8 = (D_00647FB8 + 1) & 0x3F;
    s = D_00647FC0++;
    return s;
}

s32 func_00234098(s32 a0, s32 a1, s32 a2, s32 a3, s32 a4) {
    s32 s;
    D_Ent2340[D_00647FB8].type = 2;
    D_Ent2340[D_00647FB8].serial = D_00647FC0;
    D_Ent2340[D_00647FB8].arg[0] = a0;
    D_Ent2340[D_00647FB8].arg[1] = a1;
    D_Ent2340[D_00647FB8].arg[2] = a2;
    D_Ent2340[D_00647FB8].arg[3] = a3;
    D_Ent2340[D_00647FB8].arg[4] = a4;
    D_00647FB8 = (D_00647FB8 + 1) & 0x3F;
    s = D_00647FC0++;
    return s;
}

s32 func_00234148(s32 a0, s32 a1, s32 a2, s32 a3, s32 a4, s32 a5) {
    s32 s;
    D_Ent2340[D_00647FB8].type = 3;
    D_Ent2340[D_00647FB8].serial = D_00647FC0;
    D_Ent2340[D_00647FB8].arg[0] = a0;
    D_Ent2340[D_00647FB8].arg[1] = a1;
    D_Ent2340[D_00647FB8].arg[2] = a2;
    D_Ent2340[D_00647FB8].arg[3] = a3;
    D_Ent2340[D_00647FB8].arg[4] = a4;
    D_Ent2340[D_00647FB8].arg[5] = a5;
    D_00647FB8 = (D_00647FB8 + 1) & 0x3F;
    s = D_00647FC0++;
    return s;
}

s32 func_00234210(s32 a0, s32 a1, s32 a2) {
    s32 s;
    D_Ent2340[D_00647FB8].type = 4;
    D_Ent2340[D_00647FB8].serial = D_00647FC0;
    D_Ent2340[D_00647FB8].arg[0] = a0;
    D_Ent2340[D_00647FB8].arg[1] = a1;
    D_Ent2340[D_00647FB8].arg[2] = a2;
    D_00647FB8 = (D_00647FB8 + 1) & 0x3F;
    s = D_00647FC0++;
    return s;
}

s32 func_00234290(s32 a0, s32 a1, s32 a2) {
    s32 s;
    D_Ent2340[D_00647FB8].type = 5;
    D_Ent2340[D_00647FB8].serial = D_00647FC0;
    D_Ent2340[D_00647FB8].arg[0] = a0;
    D_Ent2340[D_00647FB8].arg[1] = a1;
    D_Ent2340[D_00647FB8].arg[2] = a2;
    D_00647FB8 = (D_00647FB8 + 1) & 0x3F;
    s = D_00647FC0++;
    return s;
}

s32 func_00234310(s32 a0, s32 a1, s32 a2, s32 a3) {
    s32 s;
    D_Ent2340[D_00647FB8].type = 6;
    D_Ent2340[D_00647FB8].serial = D_00647FC0;
    D_Ent2340[D_00647FB8].arg[0] = a0;
    D_Ent2340[D_00647FB8].arg[1] = a1;
    D_Ent2340[D_00647FB8].arg[2] = a2;
    D_Ent2340[D_00647FB8].arg[3] = a3;
    D_00647FB8 = (D_00647FB8 + 1) & 0x3F;
    s = D_00647FC0++;
    return s;
}

s32 func_002343A8(s32 a0, s32 a1, s32 a2, s32 a3) {
    s32 s;
    D_Ent2340[D_00647FB8].type = 7;
    D_Ent2340[D_00647FB8].serial = D_00647FC0;
    D_Ent2340[D_00647FB8].arg[0] = a0;
    D_Ent2340[D_00647FB8].arg[1] = a1;
    D_Ent2340[D_00647FB8].arg[2] = a2;
    D_Ent2340[D_00647FB8].arg[3] = a3;
    D_00647FB8 = (D_00647FB8 + 1) & 0x3F;
    s = D_00647FC0++;
    return s;
}

s32 func_00234440(s32 a0, s32 a1, s32 a2, s32 a3, s32 a4, s32 a5) {
    s32 s;
    D_Ent2340[D_00647FB8].type = 8;
    D_Ent2340[D_00647FB8].serial = D_00647FC0;
    D_Ent2340[D_00647FB8].arg[0] = a0;
    D_Ent2340[D_00647FB8].arg[1] = a1;
    D_Ent2340[D_00647FB8].arg[2] = a2;
    D_Ent2340[D_00647FB8].arg[3] = a3;
    D_Ent2340[D_00647FB8].arg[4] = a4;
    D_Ent2340[D_00647FB8].arg[5] = a5;
    D_00647FB8 = (D_00647FB8 + 1) & 0x3F;
    s = D_00647FC0++;
    return s;
}

s32 func_00234508(s32 a0, s32 a1, s32 a2, s32 a3) {
    s32 s;
    D_Ent2340[D_00647FB8].type = 9;
    D_Ent2340[D_00647FB8].serial = D_00647FC0;
    D_Ent2340[D_00647FB8].arg[0] = a0;
    D_Ent2340[D_00647FB8].arg[1] = a1;
    D_Ent2340[D_00647FB8].arg[2] = a2;
    D_Ent2340[D_00647FB8].arg[3] = a3;
    D_00647FB8 = (D_00647FB8 + 1) & 0x3F;
    s = D_00647FC0++;
    return s;
}

s32 func_002345A0(s32 a0, s32 a1, s32 a2, s32 a3, s32 a4, s32 a5) {
    s32 s;
    D_Ent2340[D_00647FB8].type = 10;
    D_Ent2340[D_00647FB8].serial = D_00647FC0;
    D_Ent2340[D_00647FB8].arg[0] = a0;
    D_Ent2340[D_00647FB8].arg[1] = a1;
    D_Ent2340[D_00647FB8].arg[2] = a2;
    D_Ent2340[D_00647FB8].arg[3] = a3;
    D_Ent2340[D_00647FB8].arg[4] = a4;
    D_Ent2340[D_00647FB8].arg[5] = a5;
    D_00647FB8 = (D_00647FB8 + 1) & 0x3F;
    s = D_00647FC0++;
    return s;
}

s32 func_00234668(s32 a0, s32 a1, s32 a2, s32 a3, s32 a4, s32 a5) {
    s32 s;
    D_Ent2340[D_00647FB8].type = 11;
    D_Ent2340[D_00647FB8].serial = D_00647FC0;
    D_Ent2340[D_00647FB8].arg[0] = a0;
    D_Ent2340[D_00647FB8].arg[1] = a1;
    D_Ent2340[D_00647FB8].arg[2] = a2;
    D_Ent2340[D_00647FB8].arg[3] = a3;
    D_Ent2340[D_00647FB8].arg[4] = a4;
    D_Ent2340[D_00647FB8].arg[5] = a5;
    D_00647FB8 = (D_00647FB8 + 1) & 0x3F;
    s = D_00647FC0++;
    return s;
}

s32 func_00234730(s32 a0, s32 a1, s32 a2, s32 a3, s32 a4) {
    s32 s;
    D_Ent2340[D_00647FB8].type = 9;
    D_Ent2340[D_00647FB8].serial = D_00647FC0;
    D_Ent2340[D_00647FB8].arg[0] = a0;
    D_Ent2340[D_00647FB8].arg[1] = a1;
    D_Ent2340[D_00647FB8].arg[2] = a2;
    D_Ent2340[D_00647FB8].arg[3] = a3;
    D_Ent2340[D_00647FB8].arg[4] = a4;
    D_00647FB8 = (D_00647FB8 + 1) & 0x3F;
    s = D_00647FC0++;
    return s;
}

typedef struct { s32 type; s32 serial; s32 arg[6]; } Ent2347;
extern Ent2347 D_Ent2347[] __asm__("D_006477B0");
extern s32 D_00647FB8;
extern s32 D_00647FC0;
s32 func_002347E0(s32 a0) {
    s32 s;
    D_Ent2347[D_00647FB8].type = 0xD;
    D_Ent2347[D_00647FB8].serial = D_00647FC0;
    D_Ent2347[D_00647FB8].arg[0] = a0;
    D_00647FB8 = (D_00647FB8 + 1) & 0x3F;
    s = D_00647FC0++;
    return s;
}

extern s32 D_00647FEC;

s32 func_00234840(void) {
    return D_00647FEC;
}

extern s32 D_00647FF0;

s32 func_00234850(void) {
    return D_00647FF0;
}

extern s32 D_00647FF4;

s32 func_00234860(void) {
    return D_00647FF4;
}

extern s32 D_00647FF8;

s32 func_00234870(void) {
    return D_00647FF8;
}

extern s32 D_00647FFC;

s32 func_00234880(void) {
    return D_00647FFC;
}

extern s32 D_00648000;

s32 func_00234890(void) {
    return D_00648000;
}

extern s32 D_00648004;

s32 func_002348A0(void) {
    return D_00648004;
}

extern s32 D_00648008;

s32 func_002348B0(void) {
    return D_00648008;
}

extern s32 D_0064800C;

s32 func_002348C0(void) {
    return D_0064800C;
}

extern s32 D_00648010;

s32 func_002348D0(void) {
    return D_00648010;
}

extern s32 D_00648014;

s32 func_002348E0(void) {
    return D_00648014;
}

extern s32 D_00648018;

s32 func_002348F0(void) {
    return D_00648018;
}

extern s32 D_0064801C;

s32 func_00234900(void) {
    return D_0064801C;
}

INCLUDE_ASM("asm/nonmatchings/unsplit/memcard", func_00234910);

INCLUDE_ASM("asm/nonmatchings/unsplit/memcard", func_00234F80);

extern s32 D_00647FB4;
extern s32 D_00647FC8;
extern s32 D_00425C10;
extern s32 D_00425C14;
extern char D_004913F8[];
extern s32 D_00425CAC;
extern void *D_00425CA8;
extern s32 D_00647FB0_a __asm__("D_00647FB0");
extern s32 (*D_00648034_a)(s32) __asm__("D_00648034");
extern s32 D_00647FC4_a __asm__("D_00647FC4");
int sceMcGetDir(int, int, const char *, unsigned, int, void *);
int sceMcSync(int, int *, int *);

void func_00235228(void) {
    s32 *st = &D_00647FB4;
    s32 r;

    switch (*st) {
    case 0:
        sceMcGetDir(D_00425C10, D_00425C14, D_004913F8, 0, D_00425CAC, D_00425CA8);
        (*st)++;
        break;
    case 1:
        if (sceMcSync(1, NULL, &D_00647FC8) != 0) {
            (*st)++;
        }
        break;
    case 2:
        r = D_00647FC8;
        if (r >= 0) {
            D_00425CAC = r;
            D_00647FF0 = 0;
        } else if (r == -2) {
            D_00425CAC = -1;
            D_00647FF0 = 1;
        } else if (r == -4) {
            D_00425CAC = -1;
            D_00647FF0 = 2;
        } else {
            D_00425CAC = -1;
            D_00647FF0 = 3;
        }
        D_00647FB0_a = 0;
        D_00647FD8 = D_00647FD4;
        if (D_00648034_a != NULL) {
            D_00648034_a(D_00647FC4_a);
        }
        break;
    }
}

extern s32 D_00647FB4;
extern s32 D_00647FC8;
extern s32 D_00425C10;
extern s32 D_00425C14;
extern char *D_00648020;
extern s32 D_00425CAC;
extern void *D_00425CA8;
extern s32 D_00647FB0_a __asm__("D_00647FB0");
extern s32 (*D_00648034_a)(s32) __asm__("D_00648034");
extern s32 D_00647FC4_a __asm__("D_00647FC4");
int sceMcGetDir(int, int, const char *, unsigned, int, void *);
int sceMcSync(int, int *, int *);

void func_002353A8(void) {
    s32 *st = &D_00647FB4;
    s32 r;

    switch (*st) {
    case 0:
        sceMcGetDir(D_00425C10, D_00425C14, D_00648020, 0, D_00425CAC, D_00425CA8);
        (*st)++;
        break;
    case 1:
        if (sceMcSync(1, NULL, &D_00647FC8) != 0) {
            (*st)++;
        }
        break;
    case 2:
        r = D_00647FC8;
        if (r >= 0) {
            D_00425CAC = r;
            D_00647FF4 = 0;
        } else if (r == -2) {
            D_00425CAC = -1;
            D_00647FF4 = 2;
        } else if (r == -4) {
            D_00425CAC = -1;
            D_00647FF4 = 3;
        } else {
            D_00425CAC = -1;
            D_00647FF4 = 4;
        }
        D_00647FB0_a = 0;
        D_00647FD8 = D_00647FD4;
        if (D_00648034_a != NULL) {
            D_00648034_a(D_00647FC4_a);
        }
        break;
    }
}

extern s32 D_00647FB4;
extern s32 D_00647FC8;
extern s32 D_00647FCC;
extern s32 D_00647FD0;
extern s32 D_00425C10;
extern s32 D_00425C14;
extern s32 D_00647FB0_a __asm__("D_00647FB0");
extern s32 (*D_00648034_a)(s32) __asm__("D_00648034");
extern s32 D_00647FC4_a __asm__("D_00647FC4");
int sceMcFormat(int, int);
int sceMcSync(int, int *, int *);

void func_00235520(void) {
    s32 *st = &D_00647FB4;

    switch (*st) {
    case 0:
        sceMcFormat(D_00425C10, D_00425C14);
        (*st)++;
        break;
    case 1:
        if (sceMcSync(1, NULL, &D_00647FC8) != 0) {
            (*st)++;
        }
        break;
    case 2:
        if (D_00647FC8 != 0) {
            if (D_00647FCC != 0) {
                D_00647FCC--;
                D_00647FD0 = 0x3C;
                *st = 3;
                break;
            }
            D_00647FF8 = 1;
        } else {
            D_00647FF8 = 0;
        }
        D_00647FB0_a = 0;
        D_00647FD8 = D_00647FD4;
        if (D_00648034_a != NULL) {
            D_00648034_a(D_00647FC4_a);
        }
        break;
    case 3:
        if (D_00647FD0 != 0) {
            D_00647FD0--;
        } else {
            *st = 0;
        }
        break;
    }
}

extern s32 D_00647FB4;
extern s32 D_00647FC8;
extern s32 D_00647FCC;
extern s32 D_00647FD0;
extern s32 D_00425C10;
extern s32 D_00425C14;
extern s32 D_00647FB0_a __asm__("D_00647FB0");
extern s32 (*D_00648034_a)(s32) __asm__("D_00648034");
extern s32 D_00647FC4_a __asm__("D_00647FC4");
int sceMcUnformat(int, int);
int sceMcSync(int, int *, int *);

void func_00235688(void) {
    s32 *st = &D_00647FB4;

    switch (*st) {
    case 0:
        sceMcUnformat(D_00425C10, D_00425C14);
        (*st)++;
        break;
    case 1:
        if (sceMcSync(1, NULL, &D_00647FC8) != 0) {
            (*st)++;
        }
        break;
    case 2:
        if (D_00647FC8 != 0) {
            if (D_00647FCC != 0) {
                D_00647FCC--;
                D_00647FD0 = 0x3C;
                *st = 3;
                break;
            }
            D_00647FFC = 1;
        } else {
            D_00647FFC = 0;
        }
        D_00647FB0_a = 0;
        D_00647FD8 = D_00647FD4;
        if (D_00648034_a != NULL) {
            D_00648034_a(D_00647FC4_a);
        }
        break;
    case 3:
        if (D_00647FD0 != 0) {
            D_00647FD0--;
        } else {
            *st = 0;
        }
        break;
    }
}

extern s32 D_00647FB4;
extern s32 D_00647FC8;
extern s32 D_00425C10;
extern s32 D_00425C14;
extern char *D_00648020;
extern char D_00425CB0[];
extern s32 D_00647FB0_a __asm__("D_00647FB0");
extern s32 (*D_00648034_a)(s32) __asm__("D_00648034");
extern s32 D_00647FC4_a __asm__("D_00647FC4");
int sceMcChdir(int, int, const char *, char *);
int sceMcSync(int, int *, int *);

void func_002357F0(void) {
    s32 *st = &D_00647FB4;

    switch (*st) {
    case 0:
        sceMcChdir(D_00425C10, D_00425C14, D_00648020, D_00425CB0);
        (*st)++;
        break;
    case 1:
        if (sceMcSync(1, NULL, &D_00647FC8) != 0) {
            (*st)++;
        }
        break;
    case 2:
        switch (D_00647FC8) {
        case 0:
            D_00648000 = 0;
            break;
        case -2:
            D_00648000 = 1;
            break;
        case -4:
            D_00648000 = 2;
            break;
        default:
            D_00648000 = 3;
            break;
        }
        D_00647FB0_a = 0;
        D_00647FD8 = D_00647FD4;
        if (D_00648034_a != NULL) {
            D_00648034_a(D_00647FC4_a);
        }
        break;
    }
}

INCLUDE_ASM("asm/nonmatchings/unsplit/memcard", func_00235950);

INCLUDE_ASM("asm/nonmatchings/unsplit/memcard", func_00235AB0);

INCLUDE_ASM("asm/nonmatchings/unsplit/memcard", func_00235D70);

INCLUDE_ASM("asm/nonmatchings/unsplit/memcard", func_00235EE8);

INCLUDE_ASM("asm/nonmatchings/unsplit/memcard", func_00236190);

extern s32 D_00647FB4;
extern s32 D_00647FC8;
extern s32 D_00425C10;
extern s32 D_00425C14;
extern char *D_00648020;
extern char *D_00648024;
extern s32 D_00647FB0_a __asm__("D_00647FB0");
extern s32 (*D_00648034_a)(s32) __asm__("D_00648034");
extern s32 D_00647FC4_a __asm__("D_00647FC4");
int sceMcRename(int, int, const char *, const char *);
int sceMcSync(int, int *, int *);

void func_00236450(void) {
    s32 *st = &D_00647FB4;
    s32 r;

    switch (*st) {
    case 0:
        sceMcRename(D_00425C10, D_00425C14, D_00648020, D_00648024);
        (*st)++;
        break;
    case 1:
        if (sceMcSync(1, NULL, &D_00647FC8) != 0) {
            (*st)++;
        }
        break;
    case 2:
        r = D_00647FC8;
        if (r == 0) {
            D_00648018 = 0;
        } else if (r == -2) {
            D_00648018 = 1;
        } else if (r == -4) {
            D_00648018 = 2;
        } else {
            D_00648018 = 3;
        }
        D_00647FB0_a = 0;
        D_00647FD8 = D_00647FD4;
        if (D_00648034_a != NULL) {
            D_00648034_a(D_00647FC4_a);
        }
        break;
    }
}

extern s32 D_00647FB0_b __asm__("D_00647FB0");
extern s32 D_0064801C_b __asm__("D_0064801C");
extern s32 (*D_00648034)(s32);
extern s32 D_00647FC4;
void func_00236598(void) {
    D_00647FB0_b = 0;
    D_00647FD8 = D_00647FD4;
    D_0064801C_b = D_00648034(D_00647FC4);
}

extern s32 D_00647FB0;
extern void (*D_00425BD0[])(void);
void func_002365E0(void) {
    D_00425BD0[D_00647FB0]();
}
