#include "common.h"
#include "sdk/ee/eetypes.h"

extern s32 D_00351E10;
s32 func_00234440(s32 a0, s32 a1, s32 a2, s32 a3, s32 a4, s32 a5);
s32 func_00234730(s32 a0, s32 a1, s32 a2, s32 a3, s32 a4);

extern s32 D_00648038[];
extern f32 D_00648050[];

void func_00236618(void) {
    D_00648038[0] = 1484;
    D_00648038[1] = 12345;
    D_00648038[2] = 54321;
    D_00648038[3] = 765;
    D_00648038[4] = 9999;
    D_00648050[0] = 1.234f;
    D_00648050[1] = 2.345f;
    D_00648050[2] = 3.456f;
    D_00648050[3] = 4.567f;
    D_00648050[4] = 5.678f;
}

extern s32 D_00648038[];
void func_002366A8(s32 arg0, s32 arg1) {
    D_00648038[arg0] = arg1;
}

extern s32 D_00648038[];

s32 func_002366C0(s32 arg0) {
    return D_00648038[arg0];
}

s32 func_002366D8(s32 i, s32 n) {
    s32 *seed = &D_00648038[i];
    s32 s = (*seed * 0x41C64E6DL + 12345) & 0x7FFFFFFF;
    *seed = s;
    return ((s / 0x10000) * n + ((long)(s & 0xFFFF) * n) / 0x10000) / 0x8000;
}

extern s32 D_00648038_b[] __asm__("D_00648038");
void func_002367A0(s32 i) {
    s32* p = &D_00648038_b[i];

    *p = ((s64)*p * 0x41C64E6D + 0x3039) & 0x7FFFFFFF;
}

s32 func_002367F8(s32 *seed, s32 n) {
    s32 s = (*seed * 0x41C64E6DL + 12345) & 0x7FFFFFFF;
    *seed = s;
    return ((s / 0x10000) * n + ((long)(s & 0xFFFF) * n) / 0x10000) / 0x8000;
}

void func_002368B0(s32* p) {
    *p = ((s64)*p * 0x41C64E6D + 0x3039) & 0x7FFFFFFF;
}

extern float D_00648050[];
void func_002368F8(s32 arg0, f32 arg1) {
    D_00648050[arg0] = arg1;
}

f32 func_00236910(s32 arg0) {
    return D_00648050[arg0];
}

extern float D_00648050[];

void func_00236928(s32 arg0) {
    f32 *ptr = &D_00648050[arg0];
    ptr[0] = (ptr[0] * 69069.0f + 1.0f) * 0x1.0p-32f;
}

f32 func_00236970(u32 *p) {
    *p = (u64)*p * 0x41C64E6D + 0x3039;
    return *p * (1.0f / 4294967296.0f);
}

f32 func_002369E8(u32 a) {
    a = (u64)a * 0x41C64E6D + 0x3039;
    return a * (1.0f / 4294967296.0f);
}

extern s32 D_a3pad_6a58_1;
typedef struct {
    sceVu0FMATRIX m0;
    sceVu0FMATRIX m40;
    sceVu0FMATRIX m80;
    sceVu0FMATRIX mC0;
    sceVu0FVECTOR pad100[4];
    sceVu0FVECTOR pos;
    sceVu0FVECTOR tgt;
    sceVu0FVECTOR v160;
    sceVu0FVECTOR v170;
    sceVu0FVECTOR rot;
    sceVu0FVECTOR dir;
    u8 pad1A0[0x40];
    s32 flag;
    f32 dist;
} Cam236A58;
extern Cam236A58 *D_00425F70;
extern f32 D_00425CE0[4][4];
f32 atan2f(f32, f32);
s32 func_00236D48(sceVu0FMATRIX arg0, sceVu0FMATRIX arg1, sceVu0FVECTOR arg2);

void func_00236A58(void) {
    sceVu0FMATRIX m;
    sceVu0FVECTOR d;
    sceVu0FVECTOR v0;
    sceVu0FVECTOR v1;
    f32 dx;
    f32 dy;
    f32 dz;

    if (D_00425F70->flag == 0) {
        dx = D_00425F70->tgt[0] - D_00425F70->pos[0];
        dz = D_00425F70->tgt[2] - D_00425F70->pos[2];
        dy = D_00425F70->tgt[1] - D_00425F70->pos[1];
        D_00425F70->rot[2] = 0.0f;
        D_00425F70->rot[0] = atan2f(-dy, _sqrtf(dx * dx + dz * dz));
        D_00425F70->rot[1] = atan2f(dx, dz);
    } else {
        Cam236A58 *c;
        func_00236D48(m, D_00425CE0, D_00425F70->rot);
        c = D_00425F70;
        d[0] = 0.0f;
        d[1] = 0.0f;
        d[2] = c->dist;
        d[3] = 1.0f;
        sceVu0ApplyMatrix(d, m, d);
        c = D_00425F70;
        c->pos[0] = c->tgt[0] + d[0];
        dx = c->tgt[0] - c->pos[0];
        c->pos[1] = c->tgt[1] + d[1];
        dy = c->tgt[1] - c->pos[1];
        c->pos[2] = c->tgt[2] + d[2];
        dz = c->tgt[2] - c->pos[2];
    }
    sceVu0RotMatrixX(m, D_00425CE0, D_00425F70->rot[0]);
    sceVu0RotMatrixY(m, m, D_00425F70->rot[1]);
    sceVu0ApplyMatrix(v0, m, D_00425F70->v160);
    sceVu0ApplyMatrix(v1, m, D_00425F70->v170);
    sceVu0CameraMatrix(D_00425F70->m80, D_00425F70->pos, v0, v1);
    sceVu0UnitMatrix(D_00425F70->mC0);
    func_00236D48(D_00425F70->mC0, D_00425F70->mC0, D_00425F70->rot);
    sceVu0MulMatrix(D_00425F70->m0, D_00425F70->m40, D_00425F70->m80);
    {
    Cam236A58 *e = D_00425F70;
    e->dir[0] = dx;
    e->dir[1] = dy;
    e->dir[2] = dz;
    e->dir[3] = 1.0f;
    sceVu0Normalize(e->dir, e->dir);
    }
}

extern f32 D_00425CE0[4][4];

void func_00236C68(sceVu0FMATRIX out, sceVu0FVECTOR a1, sceVu0FVECTOR a2, sceVu0FVECTOR a3, f32 *rot) {
    sceVu0FMATRIX m;
    sceVu0FVECTOR v0;
    sceVu0FVECTOR v1;
    sceVu0FVECTOR v2;

    sceVu0RotMatrixX(m, D_00425CE0, rot[0]);
    sceVu0RotMatrixY(m, m, rot[1]);
    sceVu0RotMatrixZ(m, m, rot[2]);
    sceVu0ApplyMatrix(v0, m, a2);
    sceVu0ApplyMatrix(v1, m, a3);
    sceVu0ApplyMatrix(v2, m, a1);
    sceVu0CameraMatrix(out, v2, v0, v1);
}

s32 func_00236D48(sceVu0FMATRIX arg0, sceVu0FMATRIX arg1, sceVu0FVECTOR arg2) {
    sceVu0RotMatrixZ(arg0, arg1, arg2[2]);
    sceVu0RotMatrixX(arg0, arg0, arg2[0]);
    sceVu0RotMatrixY(arg0, arg0, arg2[1]);
}

s32 func_00236D98(sceVu0FMATRIX arg0, sceVu0FMATRIX arg1, sceVu0FVECTOR arg2) {
    sceVu0RotMatrixX(arg0, arg1, arg2[0]);
    sceVu0RotMatrixY(arg0, arg0, arg2[1]);
    sceVu0RotMatrixZ(arg0, arg0, arg2[2]);
}

// func_00236DE8 (src/unsplit/seg_132D60.c)
void func_00236DE8(f32 (*arg0)[4], f32 fparg0) {
    sceVu0UnitMatrix(arg0);
    arg0[0][0] *= fparg0;
    arg0[1][1] *= fparg0;
    arg0[2][2] *= fparg0;
}

s32 func_00236E40(u32* p) {
    if (p[2] > 0xFFFF28) {
        return 1;
    }
    if (p[0] > 0xFFFF) {
        return 1;
    }
    return p[1] > 0xFFFF;
}

s32 func_00236E80(u32 *a, u32 *b, u32 *c, u32 *d) {
    if (func_00236E40(a) != 0) {
        return 1;
    }
    if (func_00236E40(b) != 0) {
        return 1;
    }
    if (func_00236E40(c) != 0) {
        return 1;
    }
    return func_00236E40(d) != 0;
}

void func_00239368(void);

// func_00236F00 (src/unsplit/seg_132D60.c)
void func_00236F00(void) {
    func_00239368();
}

extern u8 D_00425F80[];
extern u8 D_00425F88[];
extern s32 D_00425F78;
void func_0023B570(void); void func_0023C968(void); void func_00242A38(void); void func_00243A90(void);
void func_00244500(void); void func_00245148(void); void func_002456E8(void); void func_00245E40(void);
void func_00246438(void); void func_00246BC8(void); void fm_func_00247258(void); void func_00248400(void);
void func_00248EA0(void); void func_00249250(void);
void func_00236F18(void) {
    func_00237660(D_00425F80, (s32)D_00425F88, 8);
    func_0023B570();
    func_0023C968();
    func_00242A38();
    func_00243A90();
    func_00244500();
    func_00245148();
    func_002456E8();
    func_00245E40();
    func_00246438();
    func_00246BC8();
    fm_func_00247258();
    func_00248400();
    func_00248EA0();
    func_00249250();
    D_00425F78 = 0;
}

void func_00236FC0(void) {

}

void func_00236FC8(void) {

}

s32 func_00236FD0(void) {
    return 0;
}

void func_00236FD8(void *arg0, s32 arg1) {
    s64 val = ((((s32)(arg1 - (s32)(long)arg0) >> 4) - 1) | 0x8000) | ((s64)0x8000 << 45);
    ((s64 *)arg0)[1] = 0xE;
    ((s64 *)arg0)[0] = val;
}

// func_00237008 (src/unsplit/seg_132D60.c)
u64* func_00237008(u64 arg0, u64 arg1, u64* arg2) {
    arg2[0] = arg1;
    arg2[1] = arg0;
    return arg2 + 2;
}

INCLUDE_ASM("asm/nonmatchings/unsplit/file136618", func_00237018);

INCLUDE_ASM("asm/nonmatchings/unsplit/file136618", func_002370C8);

extern u8 D_006480D0;
extern void func_002370C8(void *);
extern void func_00237018(void *, s32, s32);

void func_002372E0(void) {
    func_002370C8(&D_006480D0);
    func_00237018(&D_006480D0, 0x16, 1);
}

extern u64 D_006480D0_q[] __asm__("D_006480D0");
void func_00237318(void) {
    D_006480D0_q[0x2] = 0xF000000000000001ULL;
    D_006480D0_q[0x3] = 0xEEEEEEEEEEEEEEEEULL;
    D_006480D0_q[0x4] = 0x800D0ULL;
    D_006480D0_q[0x5] = 0x4CULL;
    D_006480D0_q[0x6] = 0x31000070ULL;
    D_006480D0_q[0x7] = 0x4EULL;
    D_006480D0_q[0x8] = 0x740000007000ULL;
    D_006480D0_q[0x9] = 0x18ULL;
    D_006480D0_q[0xA] = 0x17F000001FF0000ULL;
    D_006480D0_q[0xB] = 0x40ULL;
    D_006480D0_q[0xC] = 0x5000DULL;
    D_006480D0_q[0xD] = 0x47ULL;
    D_006480D0_q[0xE] = 0x44ULL;
    D_006480D0_q[0xF] = 0x42ULL;
    D_006480D0_q[0x10] = 0x0ULL;
    D_006480D0_q[0x11] = 0x4AULL;
    D_006480D0_q[0x12] = 0x20000045DD308002ULL;
    D_006480D0_q[0x13] = 0x6ULL;
    D_006480D0_q[0x14] = 0x60ULL;
    D_006480D0_q[0x15] = 0x14ULL;
    D_006480D0_q[0x16] = 0x2000000001300000ULL;
    D_006480D0_q[0x17] = 0x16ULL;
    D_006480D0_q[0x18] = 0x0ULL;
    D_006480D0_q[0x19] = 0x34ULL;
    D_006480D0_q[0x1A] = 0x0ULL;
    D_006480D0_q[0x1B] = 0x36ULL;
    D_006480D0_q[0x1C] = 0x5ULL;
    D_006480D0_q[0x1D] = 0x8ULL;
    D_006480D0_q[0x1E] = 0x1ULL;
    D_006480D0_q[0x1F] = 0x1AULL;
    D_006480D0_q[0x20] = 0x1ULL;
    D_006480D0_q[0x21] = 0x46ULL;
    D_006480D0_q[0x22] = 0x4000000000008001ULL;
    D_006480D0_q[0x23] = 0xEEEEEEEEEEEEEEEEULL;
    D_006480D0_q[0x24] = 0x0ULL;
    D_006480D0_q[0x25] = 0x45ULL;
    D_006480D0_q[0x26] = -4;
    D_006480D0_q[0x27] = 0x44ULL;
    D_006480D0_q[0x28] = 0x0ULL;
    D_006480D0_q[0x29] = 0x49ULL;
    D_006480D0_q[0x2A] = 0x8000000080ULL;
    D_006480D0_q[0x2B] = 0x3BULL;
    func_00237018(D_006480D0_q, 0x16, 1);
}

void func_00237548(f32 *arg0, f32 *arg1, f32 *arg2, f32 (*arg3)[4]) {
    f32 sp[12];

    sceVu0ApplyMatrix(&sp[0], arg3, arg0);
    sceVu0ApplyMatrix(&sp[4], arg3, arg1);
    sceVu0ApplyMatrix(&sp[8], arg3, arg2);
    sceVu0DivVectorXYZ(&sp[0], &sp[0], sp[3]);
    sceVu0DivVectorXYZ(&sp[4], &sp[4], sp[7]);
    sceVu0DivVectorXYZ(&sp[8], &sp[8], sp[11]);
    sceVu0ClipScreen3(&sp[0], &sp[4], &sp[8]);
}

typedef struct { s32 shift; u8 *buf; } A2Tbl;

void func_00237600(void *arg0) {
    A2Tbl *t = arg0;
    s32 n = 1 << t->shift;
    u8 *p = t->buf;
    s32 i;
    for (i = 0; i < n; i++) {
        memset(p, 0, 8);
        p += 8;
    }
}

extern void func_00237600(void *arg0);

void func_00237660(void *arg0, s32 arg1, s32 arg2) {
    *(s32 *)((u8 *)arg0 + 0) = arg2;
    *(s32 *)((u8 *)arg0 + 4) = arg1;
    func_00237600(arg0);
}

typedef struct Seg132Node { struct Seg132Node* next; s32 pad; } Seg132Node;
typedef struct { s32 bits; Seg132Node* tbl; } Seg132Ot;
void func_00237680(Seg132Ot* ot, Seg132Node* n, s32 i) {
    s32 max = 1 << ot->bits;

    if (i < 0) {
        i = 0;
    }
    if (i >= max) {
        i = max - 1;
    }
    n->next = ot->tbl[i].next;
    ot->tbl[i].next = n;
}

INCLUDE_ASM("asm/nonmatchings/unsplit/file136618", func_002376C8);

INCLUDE_ASM("asm/nonmatchings/unsplit/file136618", func_00237790);

INCLUDE_ASM("asm/nonmatchings/unsplit/file136618", func_002378C8);

INCLUDE_ASM("asm/nonmatchings/unsplit/file136618", func_00237A48);

INCLUDE_ASM("asm/nonmatchings/unsplit/file136618", func_00237B30);

INCLUDE_ASM("asm/nonmatchings/unsplit/file136618", func_00237D48);

typedef struct {
    s32 unk_00;
    s32 unk_04;
    s32 n;
    s32 unk_0C;
    u_long128 q[1];
} A2QList;

u_long128* func_00237EC0(A2QList* a0, u_long128* a1) {
    s32 i;
    s32 k = 1;
    for (i = 0; i < a0->n; i++) {
        a1[k] = a0->q[i];
        k++;
    }
    a1[0] = 0;
    *(s32*)a1 = (k - 1) | 0x10000000;
    return a1 + k;
}

u32 *func_002378C8(Seg132Node *, u32 *, s32);
u32 *func_00237790_n(Seg132Node *, u32 *, s32) __asm__("func_00237790");
u32 *func_00237D48(Seg132Node *, u32 *, s32);
u32 *func_00237EC0_3(Seg132Node *, u32 *, s32) __asm__("func_00237EC0");
void *sceDmaGetChan(int);
void sceDmaSend(void *, void *);
void FlushCache(int);
int sceGsSyncPath(int mode, u_short timeout);

void func_00237F20(Seg132Ot *ot, u32 *buf0, u32 *buf1, s32 a3, s32 a4) {
    Seg132Node *tbl = ot->tbl;
    Seg132Node *node;
    u32 *buf = buf0;
    u32 *r;
    s32 n;
    s32 cnt;
    u32 *ch;
    Seg132Node **pp;

    cnt = 1 << ot->bits;
    for (n = 0; n < cnt; n++, tbl++) {
        for (pp = &tbl->next; *pp != NULL; pp = &node->next) {
            node = *pp;
            r = buf;
            if (node->pad == 2) {
                r = func_002378C8(node, buf, a4);
            } else if (node->pad == 1) {
                r = func_00237790_n(node, buf, a4);
            } else if (node->pad == 3) {
                r = func_00237D48(node, buf, a4);
            } else if (node->pad == 4) {
                r = func_00237EC0_3(node, buf, 0);
            }
            if (r != buf) {
                *r |= 0x70000000;
                ch = sceDmaGetChan(2);
                *ch |= 0x40;
                FlushCache(0);
                sceGsSyncPath(0, 0);
                sceDmaSend(ch, buf);
                buf = (buf == buf0) ? buf1 : buf0;
            }
        }
    }
    sceGsSyncPath(0, 0);
}

NOTHROW(u_long128 *, func_00237790);
void func_002380C0(Seg132Ot *ot, u32 *buf0, u32 *buf1, s32 a3, s32 a4) {
    Seg132Node *tbl = ot->tbl;
    Seg132Node *node;
    u32 *buf = buf0;
    u32 *r;
    u32 *prev;
    u32 *last;
    s32 n;
    s32 cnt;
    u32 *ch;
    Seg132Node **pp;

    cnt = 1 << ot->bits;
    for (n = 0; n < cnt; n++, tbl++) {
        last = NULL;
        pp = &tbl->next;
        if (*pp != NULL) {
            r = buf;
            for (; *pp != NULL; pp = &node->next) {
                node = *pp;
                prev = r;
                if (node->pad == 2) {
                    r = func_002378C8(node, r, a4);
                } else if (node->pad == 1) {
                    r = (u32 *)func_00237790(node, r, a4);
                } else if (node->pad == 3) {
                    r = func_00237D48(node, r, a4);
                } else if (node->pad == 4) {
                    r = func_00237EC0_3(node, r, 0);
                }
                if (prev != r) {
                    last = prev;
                }
            }
            if (r != buf) {
                *last |= 0x70000000;
                ch = sceDmaGetChan(2);
                *ch |= 0x40;
                FlushCache(0);
                sceGsSyncPath(0, 0);
                sceDmaSend(ch, buf);
                buf = (buf == buf0) ? buf1 : buf0;
            }
        }
    }
    sceGsSyncPath(0, 0);
}

INCLUDE_ASM("asm/nonmatchings/unsplit/file136618", func_00238258);

extern u_long128 D_00648070[];
// (NOTHROW-declared above func_002380C0)
void func_00238440(u8 *p, s32 n, s32 a2) {
    s32 i;
    u_long128 *r;
    for (i = 0; i < n; i++) {
        r = func_00237790(p, D_00648070, a2);
        p += 0x50;
        if (r != D_00648070) {
            *(u32 *)D_00648070 |= 0x70000000;
            func_00237018(D_00648070, r - D_00648070, 1);
        }
    }
}

INCLUDE_ASM("asm/nonmatchings/unsplit/file136618", func_002384E0);

void func_002386C0(u_long128 *src, s32 n, u_long128 *dst) {
    s32 i;
    s32 k = 2;
    u_long128 *d;
    u_long128 *s;
    if (n > 0) {
        s = src;
        i = n;
        do {
            d = (u_long128 *)(k * 16 + (s32)dst);
            i--;
            d[0] = s[0];
            k += 6;
            d[1] = s[1];
            d[2] = s[2];
            d[3] = s[3];
            d[4] = s[4];
            d[5] = s[5];
            s += 6;
        } while (i != 0);
    }
    dst[1] = 0;
    ((u64 *)dst)[3] = 0x43413E;
    ((u64 *)dst)[2] = n | 0x8000 | ((u64)0x60AB4000 << 32);
    func_00237018(dst, k, 1);
}

INCLUDE_ASM("asm/nonmatchings/unsplit/file136618", func_00238768);

INCLUDE_ASM("asm/nonmatchings/unsplit/file136618", func_002388B8);

extern s32 D_00440994;

s32 func_002389F0(s32 n) {
    s32 i;
    s32 off = 0;
    for (i = 0; i < n; i++) {
        if (i == 5) {
            off += 0x4440;
        } else if (i == 8) {
            off += 0x4440;
        } else if (i == 9) {
            off += 0x1440;
        } else if (i >= 11 && i <= 20) {
            off += 0x1440;
        } else {
            off += 0x2080;
        }
    }
    return D_00440994 + off;
}

INCLUDE_ASM("asm/nonmatchings/unsplit/file136618", func_00238A70);

void func_00238A70(void);
void func_002499F0(void);
extern u_long128 D_00648230[];
int sceGsSetDefLoadImage(void *lp, short dbp, short dbw, short dpsm, short x, short y, short w, short h);
int sceGsExecLoadImage(void *lp, u_long128 *srcaddr);
int sceGsSyncPath(int mode, u_short timeout);
void FlushCache(int);

void func_00239368(void) {
    u_long128 li[6];

    func_00238A70();
    sceGsSetDefLoadImage(li, 0x3FD8, 1, 0, 0, 0, 0x10, 0x10);
    FlushCache(0);
    sceGsSyncPath(0, 0);
    sceGsExecLoadImage(li, D_00648230);
    func_002499F0();
}

INCLUDE_ASM("asm/nonmatchings/unsplit/file136618", func_002393D8);

#include "common.h"

extern void func_002452F0(void);
extern void func_00244B00(void);
extern void func_002444A0(void);
extern void func_00243668(void);
extern void func_002458E0(void);
extern void func_00246020(void);
extern void func_00246A60(void);
extern void func_00247350(void);
extern void func_00245140(void);
extern void func_00248B00(void);
extern void func_00249240(void);
extern void func_0023CFD8(void);

void func_00239488(void) {
    func_002452F0();
    func_00244B00();
    func_002444A0();
    func_00243668();
    func_002458E0();
    func_00246020();
    func_00246A60();
    func_00247350();
    func_00245140();
    func_00248B00();
    func_00249240();
    func_0023CFD8();
}

s32 func_002448D8(void);                                /* extern */
s32 func_00245228(void);                                /* extern */
s32 func_00243BD8(void);                                /* extern */
s32 func_00245F18(void);                                /* extern */
s32 func_002474A8(void);                                /* extern */
s32 func_00235F50(void) {
    if (func_002448D8() != 0) {
        return 1;
    }
    if (func_00245228() != 0) {
        return 1;
    }
    if (func_00243BD8() != 0) {
        return 1;
    }
    if (func_00245F18() != 0) {
        return 1;
    }
    return func_002474A8() != 0;
}

u8 *func_001478C8(s32 i);
s32 func_00147808(s32 n);
s32 func_001F0638_c(s32, s32, s32, s32, s32, s32) __asm__("func_001F0638");
extern s32 D_006488F0;
extern f32 D_00650DD0;

void func_00239558(s32 a0, s32 a1, s32 a2, u8 c) {
    u8 col[4];

    col[0] = c;
    col[1] = c;
    col[2] = c;
    col[3] = D_00650DD0 * 128.0f;
    D_006488F0 = func_001F0638_c(D_006488F0, 1, *(s32 *)col, ((a1 * 16 + 0x7100) >> 4) - 0x700,
                                 ((a2 * 16 + 0x7420) >> 4) - 0x740, func_00147808(*(u16 *)(func_001478C8(a0) + 4)));
}

typedef struct { s32 v[4]; } V4_9630;
typedef struct { u8 pad[0x60]; V4_9630 m[4]; struct { s32 a; s32 b; s32 c; s32 d; } n[4]; } Obj9630;
extern Obj9630 D_00648900_o __asm__("D_00648900");
extern f32 D_00650DD4;
void func_002475E8(s32, u8 *, s32);
s32 func_002388B8(u8 *, s32, s32);

void func_00239630(s32 a0, s32 a1, s32 x, s32 y, f32 f) {
    s32 i;
    s32 j;

    func_002475E8(a0, (u8 *)&D_00648900_o, a1);
    for (i = 0; i < 4; i++) {
        s32 *e = &D_00648900_o.n[i].b;
        e[-1] += x * 16;
        e[0] += y * 16;
    }
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 3; j++) {
            D_00648900_o.m[i].v[j] = D_00648900_o.m[i].v[j] * f;
        }
    }
    for (i = 0; i < 4; i++) {
        D_00648900_o.m[i].v[3] = D_00648900_o.m[i].v[3] * D_00650DD4;
    }
    D_006488F0 = func_002388B8((u8 *)&D_00648900_o, 1, D_006488F0);
}

void func_00239630(s32, s32, s32, s32, f32);

void func_00239778(s32 a0, s32 a1, s32 a2, s32 a3, s32 a4, s32 a5, f32 f) {
    if (a0 != 0) {
        func_002479A0(a1);
        if (a2 != 0) {
            func_002479A0(a2);
        }
    }
    func_00247AA0(a1);
    if (a2 != 0) {
        func_00247AA0(a2);
    }
    func_00239630(a1, a3, a4, a5, f);
    if (a2 != 0) {
        func_00239630(a2, a3, a4, a5, f);
    }
}

void func_00239860(s32 a0, s32 a1, s32 x, s32 y, f32 f, s32 a5, s32 col, s32 a7) {
    s32 i;
    s32 j;

    func_002475E8(a0, (u8 *)&D_00648900_o, a1);
    for (i = 0; i < 4; i++) {
        s32 *e = &D_00648900_o.n[i].b;
        e[-1] += x * 16;
        e[0] += y * 16;
    }
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) {
            if (a7 != 0 || j != 3) {
                D_00648900_o.m[i].v[j] = ((s32 *)col)[j];
            }
            if (a5 != 0) {
                D_00648900_o.m[i].v[j] = D_00648900_o.m[i].v[j] * f;
            }
        }
    }
    for (i = 0; i < 4; i++) {
        D_00648900_o.m[i].v[3] = D_00648900_o.m[i].v[3] * D_00650DD4;
    }
    D_006488F0 = func_002388B8((u8 *)&D_00648900_o, 1, D_006488F0);
}

extern void func_00239860(s32, s32, s32, s32, f32, s32, s32, s32);

void func_002399F0(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, f32 f) {
    if (arg0 != 0) {
        func_002479A0(arg1);
    }
    func_00247AA0(arg1);
    func_00239860(arg1, arg2, arg3, arg4, f, 1, arg5, 1);
}

void func_00239860(s32, s32, s32, s32, f32, s32, s32, s32);

void func_00239A80(s32 a0, s32 a1, s32 a2, s32 a3, s32 a4, s32 a5, s32 a6, f32 f) {
    if (a0 != 0) {
        func_002479A0(a1);
        if (a2 != 0) {
            func_002479A0(a2);
        }
    }
    func_00247AA0(a1);
    if (a2 != 0) {
        func_00247AA0(a2);
    }
    func_00239860(a1, a3, a4, a5, f, 0, a6, 0);
    if (a2 != 0) {
        func_00239860(a1, a3, a4, a5, f, 0, a6, 0);
    }
}

void func_00239B90(s32 a0, s32 a1, s32 x, s32 y, f32 f, s32 a5, s32 col, s32 a7) {
    s32 i;
    s32 j;

    func_002475E8(a0, (u8 *)&D_00648900_o, a1);
    for (i = 0; i < 4; i++) {
        s32 *e = &D_00648900_o.n[i].b;
        e[-1] += x * 16;
        e[0] += y * 16;
    }
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) {
            if (a7 != 0 || j != 3) {
                D_00648900_o.m[i].v[j] = ((s32 *)col)[i * 4 + j];
            }
            if (a5 != 0) {
                D_00648900_o.m[i].v[j] = D_00648900_o.m[i].v[j] * f;
            }
        }
    }
    for (i = 0; i < 4; i++) {
        D_00648900_o.m[i].v[3] = D_00648900_o.m[i].v[3] * D_00650DD4;
    }
    D_006488F0 = func_002388B8((u8 *)&D_00648900_o, 1, D_006488F0);
}

void func_00239B90(s32, s32, s32, s32, f32, s32, s32, s32);

void func_00239D20(s32 a0, s32 a1, s32 a2, s32 a3, s32 a4, s32 a5, s32 a6, f32 f) {
    if (a0 != 0) {
        func_002479A0(a1);
        if (a2 != 0) {
            func_002479A0(a2);
        }
    }
    func_00247AA0(a1);
    if (a2 != 0) {
        func_00247AA0(a2);
    }
    func_00239B90(a1, a3, a4, a5, f, 0, a6, 0);
    if (a2 != 0) {
        func_00239B90(a1, a3, a4, a5, f, 0, a6, 0);
    }
}

INCLUDE_ASM("asm/nonmatchings/unsplit/file136618", func_00239E30);

extern u64 D_00648630[];
extern u_long128 *D_006488F0_p __asm__("D_006488F0");
extern u_long128 *D_006488F4;
void func_0023BB98(s32, s32, s32, s32, u8 *, s32, s32, f32);
void func_00239E30(s32, s32, s32, s32, u8 *, s32, s32, f32);

void func_0023A318(s32 a0, s32 a1, s32 a2, s32 a3, u8 *a4, s32 a5, s32 a6, f32 f) {
    func_002370C8(D_00648630);
    D_00648630[0x1C] = 5;
    D_00648630[0xC] = 0x30003;
    func_00237018(D_00648630, 0x16, 1);
    D_006488F4 = (u_long128 *)&D_00351E10;
    D_006488F0_p = (u_long128 *)&D_00351E10 + 1;
    if (a0 == 0 && *(s32 *)(a4 + 0x1C4) == 0) {
        func_0023BB98(0, a1, a2, a3, a4, a5, a6, f);
    } else {
        func_00239E30(a0, a1, a2, a3, a4, a5, a6, f);
    }
    if (f != 0.0f) {
        func_00237018(D_006488F4, D_006488F0_p - D_006488F4, 1);
    }
}

typedef struct { u8 b[0xC0]; } Blk132_C0b;
extern Blk132_C0b D_0064FD60[5];
extern u8 D_00426820[];
extern u8 D_004267F0[];
void func_002477A8(u8 *, s32 *);

void func_0023A490(s32 a0, u8 *e, s32 x, s32 y, f32 f) {
    s32 buf[4];
    s32 i;
    s32 dy;

    D_00650DD4 = D_00650DD0 = f;
    func_00239630((s32)&D_0064FD60[0], (s32)D_00426820, x, y, 1.0f);
    func_00239630((s32)&D_0064FD60[1], (s32)D_004267F0, x, y, 1.0f);
    func_00239630((s32)&D_0064FD60[2], (s32)D_004267F0, x, y, 1.0f);
    func_00239630((s32)&D_0064FD60[3], (s32)D_004267F0, x, y, 1.0f);
    func_00239630((s32)&D_0064FD60[4], (s32)D_004267F0, x, y, 1.0f);
    func_002477A8(D_0064FD60[0].b, buf);
    dy = 0x14;
    for (i = 0; i < 3; i++) {
        func_00239558(e[0x14 + i], x + buf[0], y + dy + buf[1], (*(u32 *)(e + 4) & (1 << i)) ? 0x73 : 0xE6);
        dy += 0x16;
    }
}

extern u64 D_00648790[];
void func_0023A608(s32 a0, s32 a1, s32 a2, s32 a3, f32 f) {
    func_002370C8(D_00648790);
    D_00648790[0x1C] = 5;
    D_00648790[0xC] = 0x30003;
    func_00237018(D_00648790, 0x16, 1);
    D_006488F4 = (u_long128 *)&D_00351E10;
    D_006488F0_p = (u_long128 *)&D_00351E10 + 1;
    func_0023A490(a0, (u8 *)a1, a2, a3, f);
    if (f != 0.0f) {
        func_00237018(D_006488F4, D_006488F0_p - D_006488F4, 1);
    }
}

typedef struct {
    s32 unk0;
    u32 mask;
    s32 unk8;
    s32 unkC;
    s32 n;
    u8 pad14[0x10];
    u8 c[1];
} Seg132_2E3170;
extern Seg132_2E3170 *D_002E3170[];

void func_0023A720(void) {
    Seg132_2E3170 **pp = D_002E3170;
    Seg132_2E3170 *e;
    s32 i;

    for (; *pp != NULL; pp++) {
        e = *pp;
        if (pp[1] == NULL) {
            for (i = 0; i < e->n; i++) {
                if (e->mask & (1 << i)) {
                    e->c[i] = 0x73;
                } else {
                    e->c[i] = 0xE6;
                }
            }
        } else {
            for (i = 0; i < e->n; i++) {
                e->c[i] = 0x73;
            }
        }
    }
}

extern f32 D_002B8344;

void func_0023A7E8(void) {
    Seg132_2E3170 **pp = D_002E3170;
    Seg132_2E3170 *e;
    s32 i;
    s32 v;

    for (; *pp != NULL; pp++) {
        e = *pp;
        if (pp[1] == NULL) {
            for (i = 0; i < e->n; i++) {
                if (e->mask & (1 << i)) {
                    v = e->c[i];
                    v = v - D_002B8344 * 32.0f;
                    v = (v < 0x73) ? 0x73 : v;
                    e->c[i] = v;
                } else {
                    v = e->c[i];
                    v = v + D_002B8344 * 32.0f;
                    v = (v > 0xE6) ? 0xE6 : v;
                    e->c[i] = v;
                }
            }
        }
    }
}

extern u32 D_002C1EA8;

void func_0023A8D0(void *arg0) {
    s32 var_5 = 0;

    if (D_002C1EA8 & 1) {
        if (*(u32 *)((u8 *)arg0 + 0x1C0) != ((u8 *)arg0 + 0x40)) {
            *(u32 *)((u8 *)arg0 + 0x1C0) = (u32)((u8 *)arg0 + 0x40);
            func_002479A0((u8 *)arg0 + 0x40);
            var_5 = 1;
            *(u32 *)((u8 *)arg0 + 0x1C4) = 0;
        }
    } else {
        if (*(u32 *)((u8 *)arg0 + 0x1C0) != ((u8 *)arg0 + 0x100)) {
            *(u32 *)((u8 *)arg0 + 0x1C0) = (u32)((u8 *)arg0 + 0x100);
            func_002479A0((u8 *)arg0 + 0x100);
            var_5 = 1;
            *(u32 *)((u8 *)arg0 + 0x1C4) = 1;
        }
    }

    if (var_5 == 0) {
        func_00247AA0(*(u32 *)((u8 *)arg0 + 0x1C0));
    }
}

INCLUDE_ASM("asm/nonmatchings/unsplit/file136618", func_0023A968);

INCLUDE_ASM("asm/nonmatchings/unsplit/file136618", func_0023AED0);

INCLUDE_ASM("asm/nonmatchings/unsplit/file136618", func_0023B4B8);

INCLUDE_ASM("asm/nonmatchings/unsplit/file136618", func_0023B570);

INCLUDE_ASM("asm/nonmatchings/unsplit/file136618", func_0023BB98);

s32 func_001233F8(s32);
void func_00141348(s32 *, s32 *);
void func_00246A70(s32 a0, s32 a1, s32 a2, s32 a3);

void func_0023C1B0(s32 *arg0, s32 arg1, s32 arg2) {
    s32 r[4];

    if (func_001233F8(*arg0) != 0) {
        func_00141348(arg0, r);
        if (r[0] != 0 && r[0] != 2) {
            func_00246A70(arg1, arg2, r[1], r[2]);
        }
    }
}

extern s32 D_00651310[];

s32 *func_0023C228(void) {
    s32 *ptr = D_00651310;
    int i;
    for (i = 0; i < 10; i++) {
        if (ptr[0] == 0) {
            ptr[0] = 1;
            ptr[1] = 0;
            return ptr;
        }
        ptr = (s32 *)((u8 *)ptr + 0xE0);
    }
    return NULL;
}

typedef struct { s32 a; s32 b; s32 c; s32 d; } V4_C270;
typedef struct { u8 pad[0x60]; V4_C270 m[4]; V4_C270 n[4]; } Obj_C270;
extern Obj_C270 D_00651210_o __asm__("D_00651210");
extern s32 D_00651200_i __asm__("D_00651200");
extern u8 D_00426850[];
extern sceVu0FMATRIX D_002DEC20;
extern f32 D_002B8344;
void func_0012EC60(s32, s32, f32 *);
s32 func_00249580(f32 *);
void func_00237A48(s32 *, sceVu0FMATRIX, f32 *, s32);
void func_002475E8(s32, u8 *, s32);
void func_00249558(void *, void *);
void func_002477A8(u8 *, s32 *);
s32 func_002388B8(u8 *, s32, s32);

s32 func_0023C270(u8 *e) {
    s32 w[4];
    s32 sz[4];
    sceVu0FVECTOR v;
    s32 x;
    s32 y;
    s32 i;
    s32 *h = (s32 *)(e + 0xD8);

    if (func_001233F8(h[0]) == 0) {
        return 1;
    }
    if (*(f32 *)(e + 4) == 0.0f) {
        func_002479A0((s32)(e + 0x10));
    }
    *(f32 *)(e + 4) += D_002B8344;
    func_0012EC60(h[0], h[1], v);
    if (func_00249580(v) != 0) {
        return 0;
    }
    func_00237A48(w, D_002DEC20, v, 1);
    func_002475E8((s32)(e + 0x10), (u8 *)&D_00651210_o, (s32)D_00426850);
    func_00249558(w, w);
    x = w[0];
    y = w[1];
    func_002477A8(e + 0x10, sz);
    x -= sz[2] / 2;
    y -= sz[3] / 2;
    for (i = 0; i < 4; i++) {
        s32 *p = &D_00651210_o.n[i].b;
        p[-1] += x * 16;
        p[0] += y * 16;
    }
    D_00651200_i = func_002388B8((u8 *)&D_00651210_o, 1, D_00651200_i);
    func_00247AA0((s32)(e + 0x10));
    return 0;
}

extern u64 D_00650DE0[];
extern u_long128 *D_00651200;
extern u_long128 *D_00651204;
typedef struct { s32 used; u8 pad4[0xDC]; } Ent132_E0s;
extern Ent132_E0s D_00651310_s[] __asm__("D_00651310");
s32 func_0023C270_e(Ent132_E0s *) __asm__("func_0023C270");

s32 func_0023C400(void) {
    s32 i;
    func_002370C8(D_00650DE0);
    D_00650DE0[0x1C] = 5;
    D_00650DE0[0xC] = 0x30003;
    func_00237018(D_00650DE0, 0x16, 1);
    D_00651204 = (u_long128 *)&D_00351E10;
    D_00651200 = (u_long128 *)&D_00351E10 + 1;
    for (i = 0; i < 10; i++) {
        if (D_00651310_s[i].used != 0) {
            func_0023C270_e(&D_00651310_s[i]);
        }
    }
    func_00237018(D_00651204, D_00651200 - D_00651204, 1);
    return 0;
}

typedef struct { u64 d[0x18]; } Blk132_C0;
typedef struct { s32 a; s32 b; } Pair132;
typedef struct {
    s32 used;
    s32 unk4;
    s32 unk8;
    s32 padC;
    Blk132_C0 blk;
    s32 unkD0;
    s32 unkD4;
    Pair132 pair;
} Ent132_E0;
extern Blk132_C0 *D_00651300;
extern Ent132_E0 D_00651310_e[] __asm__("D_00651310");

s32 func_0023C4D8(Pair132 *a0, s32 a1, s32 a2, s32 a3) {
    Ent132_E0 *e = (Ent132_E0 *)func_0023C228();
    s32 r = -1;
    if (e != NULL) {
        Blk132_C0 *s = D_00651300;
        e->unk8 = a1;
        e->blk = *s;
        e->unkD0 = a2;
        e->unkD4 = a3;
        r = e - D_00651310_e;
        e->pair = *a0;
    }
    return r;
}

extern s32 D_00651310[];

void func_0023C5A8(s32 arg0) {
    *((s32 *)((s32)&D_00651310 + (arg0 * 0xE0))) = 0;
}

s32 Actor_IsActive(s32);
void UiPart_GetCurrentRect(s32, s32 *);
void UiPart_StartAnims(s32);
void UiPart_StepAnims(s32);
void UiPart_BuildSprite8(s32, void *, u8 *);
extern s32 D_006512F0;
extern s32 D_006512F4;
extern s32 D_006512F8;
extern s32 D_006512FC;

void func_0023C5C8(s32 *a0, s32 a1, s32 a2) {
    s32 w[4];
    s32 r[4];
    sceVu0FVECTOR v;
    s32 o = 0;
    s32 x;
    s32 y;
    s32 i;

    if (Actor_IsActive(a0[0]) != 0) {
        func_0012EC60(a0[0], a0[1], v);
        if (func_00249580(v) == 0) {
            func_00237A48(w, D_002DEC20, v, 1);
            switch (a1) {
            case 1:
                o = D_006512F0;
                break;
            case 2:
                o = D_006512F8;
                break;
            case 3:
                o = D_006512F4;
                break;
            case 4:
                o = D_006512FC;
                break;
            }
            func_00249558(w, w);
            x = w[0];
            y = w[1];
            UiPart_GetCurrentRect(o, r);
            x -= r[2] / 2;
            y -= r[3] / 2;
            if (a2 != 0) {
                UiPart_StartAnims(o);
            }
            UiPart_BuildSprite8(o, &D_00651210_o, D_00426850);
            for (i = 0; i < 4; i++) {
                s32 *p = &D_00651210_o.n[i].b;
                p[-1] += x * 16;
                p[0] += y * 16;
            }
            D_00651200_i = func_002388B8((u8 *)&D_00651210_o, 1, D_00651200_i);
            UiPart_StepAnims(o);
        }
    }
}

INCLUDE_ASM("asm/nonmatchings/unsplit/file136618", func_0023C7A0);

extern void func_0023C7A0(void);
extern s32 D_00351E10;

typedef struct {
    /* 0x00 */ u8 pad[0x60];
    /* 0x60 */ s64 field_60;
    /* 0x68 */ u8 pad2[0x78];
    /* 0xE0 */ s64 field_E0;
} DataStruct;

extern DataStruct D_00650F40;
extern u8 *D_00651200_b __asm__("D_00651200");
extern u8 *D_00651204_b __asm__("D_00651204");

s32 func_0023C8C8(void) {
    func_002370C8(&D_00650F40);
    D_00650F40.field_E0 = 5;
    D_00650F40.field_60 = 0x30003;
    func_00237018(&D_00650F40, 0x16, 1);
    D_00651204_b = (u8 *)&D_00351E10;
    D_00651200_b = (u8 *)&D_00351E10 + 0x10;
    func_0023C7A0();
    func_00237018(D_00651204_b, (s32)(D_00651200_b - D_00651204_b) >> 4, 1);
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/unsplit/file136618", func_0023C968);

void func_0023CA48(s32 a0, s32 a1, s32 x, s32 y, f32 f) {
    s32 i;

    func_002475E8(a0, (u8 *)&D_00651210_o, a1);
    for (i = 0; i < 4; i++) {
        s32 *e = &D_00651210_o.n[i].b;
        e[-1] += x * 16;
        e[0] += y * 16;
    }
    for (i = 0; i < 4; i++) {
        D_00651210_o.m[i].d = D_00651210_o.m[i].d * f;
    }
    D_00651200_i = func_002388B8((u8 *)&D_00651210_o, 1, D_00651200_i);
}

INCLUDE_ASM("asm/nonmatchings/unsplit/file136618", func_0023CB30);

void func_002479A0(s32);
void func_00247AA0(s32);
void func_0023CB30(s32 *);
extern s32 D_00651BD8[3];
extern s32 D_00651BE8[3];
extern f32 D_002B8344;

void func_0023CC80(s32 *a0) {
    s32 i;

    switch (a0[0]) {
    case 1:
        *(f32 *)&a0[1] = 1.0f;
        for (i = 0; i < 3; i++) {
            func_002479A0(D_00651BD8[i]);
        }
        for (i = 0; i < 3; i++) {
            func_002479A0(D_00651BE8[i]);
        }
        a0[0]++;
        break;
    case 2:
        for (i = 0; i < 3; i++) {
            func_00247AA0(D_00651BD8[i]);
        }
        for (i = 0; i < 3; i++) {
            func_00247AA0(D_00651BE8[i]);
        }
        break;
    case 3:
        for (i = 0; i < 3; i++) {
            func_00247AA0(D_00651BD8[i]);
        }
        for (i = 0; i < 3; i++) {
            func_00247AA0(D_00651BE8[i]);
        }
        *(f32 *)&a0[1] = 1.0f;
        a0[0]++;
        break;
    case 4:
        for (i = 0; i < 3; i++) {
            func_00247AA0(D_00651BD8[i]);
        }
        for (i = 0; i < 3; i++) {
            func_00247AA0(D_00651BE8[i]);
        }
        *(f32 *)&a0[1] -= D_002B8344 * 0.16666666f;
        if (*(f32 *)&a0[1] <= 0.0f) {
            *(f32 *)&a0[1] = 0.0f;
            a0[0] = 0;
        }
        break;
    }
    func_0023CB30(a0);
}

extern s32 D_0044A820_a[] __asm__("D_0044A820");
void func_0023CC80(s32*);
s32 func_0023CEB0(void) {
    if (D_0044A820_a[0] == 0) {
        return 0;
    }
    func_0023CC80(D_0044A820_a);
    return 0;
}

extern s32 D_0044A820;

void func_0023CEE8(void) {
    if (D_0044A820 == 0) {
        D_0044A820 = 1;
    }
}

void func_0023CF08(void) {
    if (D_0044A820 == 2) {
        D_0044A820 = 3;
    }
}

extern s32 D_00449990;
extern s32 D_0044A800;
extern s32 D_0044A810;
extern s32 func_0023CEB0(void);

void func_0023CF30(void) {
    memset(&D_0044A820, 0, 8);
    func_00247B60(&D_0044A800, D_00651BD8, &D_00449990);
    func_00247B60(&D_0044A810, D_00651BE8, &D_00449990);
    if (func_0011ED60(func_0023CEB0) == 0) {
        func_0011ED30(0x28489, func_0023CEB0);
    }
}

extern s32 D_0044A820;

s32 func_0023CFC8(void) {
    return D_0044A820 != 0;
}

void func_0023CFD8(void) {
    D_0044A820 = 0;
}

INCLUDE_ASM("asm/nonmatchings/unsplit/file136618", func_0023CFE8);

extern void func_0011D790(s32, s32);

void func_0023D128(s32 arg0) {
    func_0011D790(45, arg0);
}

extern void func_0011D598(s32);
extern void func_0011D790(s32, s32);
extern s32 D_00651E50[];

void func_0023D148(s32 arg0) {
    if (D_00651E50[0x1048] == 0) {
        func_0011D598(0x2D);
        func_0011D790(0x2D, arg0);
        D_00651E50[0x1048] = 1;
    }
}

void func_0011D7C0(s32);
void func_0023D1A0(void) {
    if (D_00651E50[0x1048] == 1) {
        func_0011D7C0(0x2D);
        D_00651E50[0x1048] = 0;
    }
}

s32 func_0023D1E0(f32 a0) {
    return a0 / 0.7853981f;
}

INCLUDE_ASM("asm/nonmatchings/unsplit/file136618", func_0023D208);

extern s32 D_00454A20_w[] __asm__("D_00454A20");
s32 func_0023D490(u8* pp) {
    s32* p = (s32*)pp;
    u8* q;
    s32 c, d;
    if (p[0] == 4) {
        s32 r = 0;
        if (D_00454A20_w[3] >= 25) r = 1;
        if (D_00454A20_w[2] >= 4) r = 1;
        if (D_00454A20_w[3] >= 49) r = 2;
        if (D_00454A20_w[2] >= 7) r = 2;
        return r;
    }
    if (p[0] == 3) return 2;
    q = *(u8**)(*(u8**)(p + 1) + 0x6C);
    c = *(s32*)(q + 0x40);
    if (c >= 37) return 2;
    d = *(s32*)(q + 0x48);
    if (d >= 7) return 2;
    if (c >= 19) return 1;
    if (d >= 4) return 1;
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/unsplit/file136618", func_0023D528);

extern void func_00249A48(void *arg0, s32 arg1);
extern void *D_00426970;
extern void *D_0042B790;
extern void *D_004305B0;

void func_0023D698(s32 arg0) {
    if (arg0 == 0) {
        func_00249A48(&D_00426970, 1);
    } else if (arg0 == 1) {
        func_00249A48(&D_0042B790, 1);
    } else {
        func_00249A48(&D_004305B0, 1);
    }
}

INCLUDE_ASM("asm/nonmatchings/unsplit/file136618", func_0023D700);

#include "sdk/ee/eestruct.h"
typedef struct {
    u64 tag0;
    u64 reg0;
    u64 tag1;
    u64 reg1;
    struct { s32 u; s32 v; s32 pad[2]; } uv[4];
    s32 col[4][4];
    struct { s32 x; s32 y; s32 z; s32 w; } xyz[4];
} Pkt3D7E8;

s32 func_0023D7E8(s32 a0, s32 (*xy)[4], s32 (*uv)[4], s32 (*col)[4], u64 *tex, s32 a5) {
    Pkt3D7E8 o;
    s32 i;
    s32 j;

    o.tag0 = tex[3];
    ((sceGsTex0 *)&o.tag0)->CSA = 0;
    ((sceGsTex0 *)&o.tag0)->CLD = 1;
    ((sceGsTex0 *)&o.tag0)->PSM = 0x13;
    o.reg0 = 6;
    o.tag1 = tex[3];
    o.reg1 = 6;
    o.xyz[0].x = (xy[0][0] << 4) + 0x7000;
    o.xyz[0].y = (xy[0][1] << 4) + 0x7400;
    o.xyz[0].z = -0x100;
    o.xyz[0].w = 0;
    o.xyz[1].x = (xy[1][0] << 4) + 0x7000;
    o.xyz[1].y = (xy[1][1] << 4) + 0x7400;
    o.xyz[1].z = -0x100;
    o.xyz[1].w = 0;
    o.xyz[2].x = (xy[2][0] << 4) + 0x7000;
    o.xyz[2].y = (xy[2][1] << 4) + 0x7400;
    o.xyz[2].z = -0x100;
    o.xyz[2].w = 0;
    o.xyz[3].x = (xy[3][0] << 4) + 0x7000;
    o.xyz[3].y = (xy[3][1] << 4) + 0x7400;
    o.xyz[3].z = -0x100;
    o.xyz[3].w = 0;
    o.uv[0].u = (uv[0][0] << 4) + 8;
    o.uv[0].v = (uv[0][1] << 4) + 8;
    o.uv[1].u = (uv[1][0] << 4) + 8;
    o.uv[1].v = (uv[1][1] << 4) + 0x18;
    o.uv[2].u = (uv[2][0] << 4) + 0x18;
    o.uv[2].v = (uv[2][1] << 4) + 8;
    o.uv[3].u = (uv[3][0] << 4) + 0x18;
    o.uv[3].v = (uv[3][1] << 4) + 0x18;
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) {
            o.col[i][j] = col[i][j];
        }
    }
    return func_002388B8((u8 *)&o, 1, a5);
}

INCLUDE_ASM("asm/nonmatchings/unsplit/file136618", func_0023DA08);

INCLUDE_ASM("asm/nonmatchings/unsplit/file136618", func_0023DD48);

void func_0023DD48(void);

// func_0023DFC0 (src/unsplit/seg_132D60.c)
void func_0023DFC0(void) {
    func_0023DD48();
}

INCLUDE_ASM("asm/nonmatchings/unsplit/file136618", func_0023DFD8);

INCLUDE_ASM("asm/nonmatchings/unsplit/file136618", func_0023E160);

typedef struct {
    u64 a;
    u64 b;
} A3V16;
typedef struct {
    s32 w[2];
    s32 c;
    s32 pad;
    u64 rest[0x16];
} A3Blk;
extern A3V16 D_004915A0;
s32 func_0023E160(u8 *, s32, A3V16 *, s32, f32, f32, f32);
void func_0023D528(u8 *, s32 *, s32 *);
s32 func_0023D700_f(s32, s32, s32, s32, s32, f32) __asm__("func_0023D700");

s32 func_0023E330(u8 *a0, s32 a1) {
    s32 bufA[4];
    s32 pos[4];
    A3Blk tmp;
    A3V16 col;
    f32 s;
    f32 f;

    s32 i;
    s32 n;
    s32 q;
    s32 m;

    col = D_004915A0;
    s = **(f32 **)(a0 + 0xA94) * 0.000174532892f;
    if (4.71238804f < s) {
        s = 4.71238804f;
    }
    a1 = func_0023E160(a0 + 0x80, *(s32 *)(a0 + 0x90) + 0x10, &col, a1, 0.0f, s, *(f32 *)(a0 + 0xA1C));
    s = **(f32 **)(a0 + 0xA94) * 0.000174532892f;
    if (s <= 4.71238804f) {
        return a1;
    }
    func_0023D528(a0, bufA, pos);
    n = **(f32 **)(a0 + 0xA94) - 27000.0f;
    q = n / 3000;
    for (i = 0; i < q; i++) {
        a1 = func_0023D700_f(*(s32 *)(a0 + 0x5C), *(s32 *)(a0 + 0x6C), pos[0], pos[1], a1, *(f32 *)(a0 + 0xA1C));
        pos[0] -= 0x1A;
    }
    m = n % 3000;
    if (m != 0) {
        f = m / 3000.0f;
        pos[0] = pos[0] + (1.0f - f) * 26.0f;
        tmp = **(A3Blk **)(a0 + 0x5C);
        tmp.c = tmp.c * (f + 0.0625f);
        a1 = func_0023D700_f((s32)&tmp, *(s32 *)(a0 + 0x6C), pos[0], pos[1], a1, *(f32 *)(a0 + 0xA1C));
    } else {
        pos[0] += 0x1A;
    }
    **(s32 **)(a0 + 0x64) = 0x19E;
    a1 = func_0023D700_f(*(s32 *)(a0 + 0x64), *(s32 *)(a0 + 0x6C), pos[0], pos[1], a1, *(f32 *)(a0 + 0xA1C));
    return a1;
}

extern A3V16 D_004915B0;

s32 func_0023E5B0(u8 *a0, s32 a1) {
    s32 bufA[4];
    s32 pos[4];
    A3Blk tmp;
    A3Blk blk;
    A3V16 col;
    f32 s;
    f32 f;

    s32 i;
    s32 n;
    s32 q;
    s32 m;

    col = D_004915B0;
    s = **(f32 **)(a0 + 0xA90) * 0.000174532892f;
    if (4.71238804f < s) {
        s = 4.71238804f;
    }
    a1 = func_0023E160(a0 + 0x80, *(s32 *)(a0 + 0x90), &col, a1, 0.0f, s, *(f32 *)(a0 + 0xA1C));
    s = **(f32 **)(a0 + 0xA90) * 0.000174532892f;
    if (s <= 4.71238804f) {
        return a1;
    }
    func_0023D528(a0, bufA, pos);
    blk = **(A3Blk **)(a0 + 0x58);
    blk.w[0] += 0x1A;
    n = **(f32 **)(a0 + 0xA90) - 27000.0f;
    q = n / 3000;
    for (i = 0; i < q; i++) {
        if (i == 0) {
            a1 = func_0023D700_f(*(s32 *)(a0 + 0x54), *(s32 *)(a0 + 0x6C), pos[0], pos[1], a1, *(f32 *)(a0 + 0xA1C));
        } else {
            a1 = func_0023D700_f((s32)&blk, *(s32 *)(a0 + 0x6C), pos[0], pos[1], a1, *(f32 *)(a0 + 0xA1C));
        }
        pos[0] -= 0x1A;
    }
    m = n % 3000;
    if (m != 0) {
        f = m / 3000.0f;
        pos[0] = pos[0] + (1.0f - f) * 26.0f;
        if (q == 0) {
            tmp = **(A3Blk **)(a0 + 0x54);
        } else {
            tmp = blk;
        }
        tmp.c = tmp.c * (f + 0.0625f);
        a1 = func_0023D700_f((s32)&tmp, *(s32 *)(a0 + 0x6C), pos[0], pos[1], a1, *(f32 *)(a0 + 0xA1C));
    } else {
        pos[0] += 0x1A;
    }
    **(s32 **)(a0 + 0x60) = 0x19E;
    a1 = func_0023D700_f(*(s32 *)(a0 + 0x60), *(s32 *)(a0 + 0x6C), pos[0], pos[1], a1, *(f32 *)(a0 + 0xA1C));
    return a1;
}

INCLUDE_ASM("asm/nonmatchings/unsplit/file136618", func_0023E8F0);

INCLUDE_ASM("asm/nonmatchings/unsplit/file136618", func_0023EC88);

INCLUDE_ASM("asm/nonmatchings/unsplit/file136618", func_0023EE80);

INCLUDE_ASM("asm/nonmatchings/unsplit/file136618", func_0023F0D8);

INCLUDE_ASM("asm/nonmatchings/unsplit/file136618", func_0023F250);

extern s32 func_0023F0D8(void *arg0, s32 arg1);
extern s32 func_0023F250(void *arg0, s32 arg1);
extern s32 D_00454A24;

s32 func_0023F688(s32 *arg0, s32 arg1) {
    s32 *p = arg0;
    s32 on;
    if (p[0] == 4) {
        on = D_00454A24;
    } else {
        on = *(s32 *)(*(u8 **)(p[1] + 0x6C) + 0x3C);
    }
    if (on != 0) {
        return func_0023F250(p, func_0023F0D8(arg0, arg1));
    }
    return arg1;
}

extern A3V16 D_004915F0;

s32 func_0023F700(u8 *a0, s32 a1) {
    A3V16 col;

    col = D_004915F0;
    a1 = func_0023E160(a0 + 0x80, *(s32 *)(a0 + 0x90) + 0x30, &col, a1, 0.0f, *(f32 *)(a0 + 0x9E4), *(f32 *)(a0 + 0xA1C));
    if (*(f32 *)(a0 + 0x9F0) != 0.0f) {
        s32 *c = (s32 *)&col;
        c[0] = c[1] = c[2] = *(f32 *)(a0 + 0x9EC);
        c[3] = 0x80;
        a1 = func_0023E160(a0 + 0x80, *(s32 *)(a0 + 0x90) + 0x30, &col, a1, *(f32 *)(a0 + 0x9E4), *(f32 *)(a0 + 0x9E8), *(f32 *)(a0 + 0xA1C));
    }
    return a1;
}

extern s32 D_00454A20_i __asm__("D_00454A20");

s32 func_0023F7D8(s32 *p, s32 a1) {
    s32 bufA[4];
    s32 pos[4];
    s32 n;
    s32 d;
    s32 k;
    s32 i;
    s32 step;
    f32 c;

    if (p[0] == 4) {
        d = 1;
        c = 0x1.0c152p-1f;
        n = D_00454A20_i;
    } else {
        c = 0x1.0c152p-1f;
        d = 1;
        n = *(s32 *)(*(u8 **)(p[1] + 0x6C) + 0x44);
        if (n > 20) {
            n = 20;
        }
    }
    if (c * n <= 0x1.2d97c4p+2f) {
        return a1;
    }
    if (p[0] == 0 || p[0] == 4) {
        step = 0x1A;
    } else {
        step = 0x11;
    }
    func_0023D528((u8 *)p, bufA, pos);
    pos[0] -= 1;
    k = (n - 9) / d;
    for (i = 0; i < k; i++) {
        a1 = func_0023D700_f(p[0x13], p[0x1C], pos[0], pos[1], a1, *(f32 *)((u8 *)p + 0xA1C));
        pos[0] -= step;
    }
    return a1;
}

extern s32 D_00454A20_v[] __asm__("D_00454A20");
s32 func_002492E8(f32 *, s32);
void func_002492D0(f32 *, f32, f32, f32, f32);
s32 func_0023F7D8(s32 *, s32);

s32 func_0023F920(u8 *a0, s32 a1) {
    s32 r;
    s32 old;
    f32 c;
    f32 a;
    f32 b;

    if (*(s32 *)a0 == 4) {
        c = 0x1.0c152p-1f;
        r = D_00454A20_v[0];
    } else {
        c = 0x1.0c152p-1f;
        r = *(s32 *)(*(u8 **)(*(u8 **)(a0 + 4) + 0x6C) + 0x44);
    }
    a = c * r;
    if (0x1.2d97c4p+2f < a) {
        a = 0x1.2d97c4p+2f;
    }
    old = *(s32 *)(a0 + 0x9E0);
    b = c * old;
    if (0x1.2d97c4p+2f < b) {
        b = 0x1.2d97c4p+2f;
    }
    if (r < old) {
        *(f32 *)(a0 + 0x9E4) = a;
        *(f32 *)(a0 + 0x9E8) = b;
        func_002492D0((f32 *)(a0 + 0x9EC), 128.0f, -0x1.999998p+3f, 0.0f, 128.0f);
    } else if (old < r) {
        *(f32 *)(a0 + 0x9E4) = b;
        *(f32 *)(a0 + 0x9E8) = a;
        func_002492D0((f32 *)(a0 + 0x9EC), 0.0f, 0x1.999998p+3f, 0.0f, 128.0f);
    }
    if (func_002492E8((f32 *)(a0 + 0x9EC), D_002B8344) == 1) {
        *(f32 *)(a0 + 0x9E4) = *(f32 *)(a0 + 0x9E8);
    }
    *(s32 *)(a0 + 0x9E0) = r;
    if (r == 0) {
        return a1;
    }
    return func_0023F7D8((s32 *)a0, func_0023F700(a0, a1));
}

extern A3V16 D_00491600;

s32 func_0023FAD0(u8 *a0, s32 a1) {
    A3V16 col;
    u8 *p = a0 + 0x80;

    col = D_00491600;
    a1 = func_0023E160(p, *(s32 *)(a0 + 0x90) + 0x40, &col, a1, 0.0f, *(f32 *)(a0 + 0xA00), *(f32 *)(a0 + 0xA1C));
    if (*(f32 *)(a0 + 0xA0C) != 0.0f) {
        s32 *c = (s32 *)&col;
        c[3] = *(f32 *)(a0 + 0xA08);
        c[0] = c[1] = c[2] = 0x80;
        return func_0023E160(p, *(s32 *)(a0 + 0x90) + 0x40, &col, a1, *(f32 *)(a0 + 0xA00), *(f32 *)(a0 + 0xA04), *(f32 *)(a0 + 0xA1C));
    }
    return a1;
}

s32 func_0023FB90(u8 *a0, s32 a1) {
    s32 bufA[4];
    s32 pos[4];
    A3Blk tmp;
    s32 r;
    s32 n;
    s32 k;
    s32 i;
    s32 m;
    f32 f;

    r = *(u16 *)(*(u8 **)(*(u8 **)(a0 + 4) + 0x6C) + 0xBE);
    if (r > 600) {
        r = 600;
    }
    if (r < 0x10F) {
        return a1;
    }
    if (*(s32 *)a0 != 0) {
        return a1;
    }
    func_0023D528(a0, bufA, pos);
    n = r - 0x10E;
    k = n / 30;
    for (i = 0; i < k; i++) {
        a1 = func_0023D700_f(*(s32 *)(a0 + 0x50), *(s32 *)(a0 + 0x70), pos[0], pos[1], a1, *(f32 *)(a0 + 0xA1C));
        pos[0] -= 0x1A;
    }
    m = n % 30;
    if (m == 0) {
        return a1;
    }
    {
        f = m / 30.0f;
        tmp = **(A3Blk **)(a0 + 0x50);
        tmp.w[0] = tmp.w[0] + (1.0f - f) * tmp.c;
        ((s32 *)&tmp)[4] = ((s32 *)&tmp)[4] + (((s32 *)&tmp)[6] - ((s32 *)&tmp)[4]) * f;
        tmp.c = tmp.c * f;
        return func_0023D700_f((s32)&tmp, *(s32 *)(a0 + 0x70), pos[0], pos[1], a1, *(f32 *)(a0 + 0xA1C));
    }
}

s32 func_002492E8(f32 *, s32);
s32 func_0023FAD0(u8 *, s32);
s32 func_0023FB90(u8 *, s32);
void func_002492D0(f32 *, f32, f32, f32, f32);

s32 func_0023FD58(u8 *a0, s32 a1) {
    s32 r;
    s32 old;
    f32 a;
    f32 b;

    r = *(u16 *)(*(u8 **)(*(u8 **)(a0 + 4) + 0x6C) + 0xBE);
    a = r * 0x1.1df466p-6f;
    if (0x1.2d97c4p+2f < a) {
        a = 0x1.2d97c4p+2f;
    }
    old = *(s32 *)(a0 + 0x9FC);
    b = old * 0x1.1df466p-6f;
    if (0x1.2d97c4p+2f < b) {
        b = 0x1.2d97c4p+2f;
    }
    if (r < old) {
        *(f32 *)(a0 + 0xA00) = a;
        *(f32 *)(a0 + 0xA04) = b;
        func_002492D0((f32 *)(a0 + 0xA08), 128.0f, -0x1.999998p+3f, 0.0f, 128.0f);
    } else if (old < r) {
        *(f32 *)(a0 + 0xA00) = b;
        *(f32 *)(a0 + 0xA04) = a;
        func_002492D0((f32 *)(a0 + 0xA08), 0.0f, 0x1.999998p+3f, 0.0f, 128.0f);
    }
    if (func_002492E8((f32 *)(a0 + 0xA08), D_002B8344) == 1) {
        *(f32 *)(a0 + 0xA00) = *(f32 *)(a0 + 0xA04);
    }
    a1 = func_0023FB90(a0, func_0023FAD0(a0, a1));
    *(s32 *)(a0 + 0x9FC) = r;
    return a1;
}

extern A3V16 D_00491610;
/* defined under another C name: the callers below declare it as s32 func_0023FEB8(void) */
s32 func_0023FEB8_d(u8 *a0, s32 a1) __asm__("func_0023FEB8");

s32 func_0023FEB8_d(u8 *a0, s32 a1) {
    A3V16 col;
    f32 s;

    col = D_00491610;
    s = **(f32 **)(a0 + 0xA88) * 0.000174532892f;
    if (4.71238804f < s) {
        s = 4.71238804f;
    }
    return func_0023E160(a0 + 0x80, *(s32 *)(a0 + 0x90) + 0x20, &col, a1, 0.0f, s, *(f32 *)(a0 + 0xA1C));
}

extern s32 D_a3pad_0023FF38_1;
s32 func_0023FF38(void *a0_, s32 a1) {
    u8 *a0 = a0_;
    s32 bufA[4];
    s32 pos[4];
    A3Blk tmp;
    f32 f;
    s32 i;
    s32 n;
    s32 q;
    s32 m;

    if (**(f32 **)(a0 + 0xA88) * 0.000174532892f <= 4.71238804f) {
        return a1;
    }
    func_0023D528(a0, bufA, pos);
    n = **(f32 **)(a0 + 0xA88) - 27000.0f;
    q = n / 3000;
    for (i = 0; i < q; i++) {
        a1 = func_0023D700_f(*(s32 *)(a0 + 0x48), *(s32 *)(a0 + 0x70), pos[0], pos[1], a1, *(f32 *)(a0 + 0xA1C));
        pos[0] -= 0x1A;
    }
    m = n % 3000;
    if (m == 0) {
        return a1;
    }
    f = m / 3000.0f;
    pos[0] = pos[0] + (1.0f - f) * 26.0f;
    tmp = **(A3Blk **)(a0 + 0x48);
    tmp.c = tmp.c * (f + 0.0625f);
    return func_0023D700_f((s32)&tmp, *(s32 *)(a0 + 0x70), pos[0], pos[1], a1, *(f32 *)(a0 + 0xA1C));
}

extern s32 func_0023FEB8(void);
extern s32 func_0023FF38(void *arg0, s32 arg1);

s32 func_00240118(void *arg0, s32 arg1) {
    struct {
        char _[0xA88];
        f32 *field_0A88;
    } *s = arg0;
    if (*s->field_0A88 != 0.0f) {
        return func_0023FF38(arg0, func_0023FEB8());
    }
    return arg1;
}

extern A3V16 D_00491620;
/* defined under another C name: the callers below declare it as s32 func_00240170(void) */
s32 func_00240170_d(u8 *a0, s32 a1) __asm__("func_00240170");

s32 func_00240170_d(u8 *a0, s32 a1) {
    A3V16 col;
    f32 s;

    col = D_00491620;
    s = **(f32 **)(a0 + 0xA8C) * 0.000174532892f;
    if (4.71238804f < s) {
        s = 4.71238804f;
    }
    return func_0023E160(a0 + 0x80, *(s32 *)(a0 + 0x90) + 0x30, &col, a1, 0.0f, s, *(f32 *)(a0 + 0xA1C));
}

s32 func_002401F0(u8 *a0, s32 a1) {
    s32 bufA[4];
    s32 pos[4];
    A3Blk tmp;
    f32 f;
    s32 i;
    s32 n;
    s32 q;
    s32 m;

    if (**(f32 **)(a0 + 0xA8C) * 0.000174532892f <= 4.71238804f) {
        return a1;
    }
    func_0023D528(a0, bufA, pos);
    n = **(f32 **)(a0 + 0xA8C) - 27000.0f;
    q = n / 3000;
    for (i = 0; i < q; i++) {
        a1 = func_0023D700_f(*(s32 *)(a0 + 0x4C), *(s32 *)(a0 + 0x70), pos[0], pos[1], a1, *(f32 *)(a0 + 0xA1C));
        pos[0] -= 0x1A;
    }
    m = n % 3000;
    if (m == 0) {
        return a1;
    }
    f = m / 3000.0f;
    pos[0] = pos[0] + (1.0f - f) * 26.0f;
    tmp = **(A3Blk **)(a0 + 0x4C);
    tmp.c = tmp.c * (f + 0.0625f);
    return func_0023D700_f((s32)&tmp, *(s32 *)(a0 + 0x70), pos[0], pos[1], a1, *(f32 *)(a0 + 0xA1C));
}

extern s32 func_00240170(void);
extern s32 func_002401F0();

void func_002403D0(s32 arg0) {
    func_002401F0(arg0, func_00240170());
}

INCLUDE_ASM("asm/nonmatchings/unsplit/file136618", func_00240400);

INCLUDE_ASM("asm/nonmatchings/unsplit/file136618", func_002407B0);

typedef struct { s32 unk0; s32 unk4; s32 unk8; s32 unkC; } Seg132_454A20;
extern Seg132_454A20 D_00454A20;

s32 func_00240810(s32 *a0) {
    s32 r;
    s32 q;
    s32 n;
    u8 *p;

    if (a0[0] == 4) {
        r = 0;
        if (D_00454A20.unk4 != 0) {
            if ((f32)D_00454A20.unk4 < (f32)D_00454A20.unkC * 0x1.333332p-2f) {
                r = 1;
            }
        }
    } else {
        r = 0;
        if (a0[0] != 3) {
            p = *(u8 **)(*(u8 **)(a0 + 1) + 0x6C);
            q = *(s32 *)(p + 0x3C);
            if (q > 0) {
                n = *(s32 *)(p + 0x40);
                r = q < 9;
                if (n >= 45) {
                    r = (f32)q / (f32)n < 0x1.999998p-3f;
                }
            }
        }
    }
    return r;
}

/* layout note (notes/f1.md F1): func_002408D8 (and the function at 0x2414A8) flip with the code above them: after
 * func_0023C8C8 one unused `extern s32 D_2408D8_layout0;` here was needed, after func_00234440..func_00234730 none
 * (q1, 25 Nov). If they differ again, try 0-n such externs here. */
extern u8 D_00651E70;
extern s32 func_00240810(s32 *);

void func_002408D8(s32 arg0) {
    func_00240810((void *)((u8 *)&D_00651E70 + arg0 * 0xD00));
}

INCLUDE_ASM("asm/nonmatchings/unsplit/file136618", func_00240910);

extern void *func_00240910(void);

void func_00240978(void) {
    void *temp = func_00240910();
    if (temp != NULL && *(s32 *)((u8 *)temp + 0x9D0) == 0) {
        *(s32 *)((u8 *)temp + 0x9D0) = 1;
    }
}

extern void *func_00240910(void);

void func_002409B0(void) {
    void *temp = func_00240910();
    if (temp != NULL) {
        *(s32 *)((u8 *)temp + 0x9D4) = 1;
    }
}

INCLUDE_ASM("asm/nonmatchings/unsplit/file136618", func_002409E0);

extern u8 D_00426850[];
s32 func_0023D700(s32, u8*, s32, s32, s32);
s32 func_00240AE0(s32* a0, s32 a1, s32 a2, s32 a3) {
    if (a0[0x94] == 0) {
        return a3;
    }
    return func_0023D700(a0[0], D_00426850, a1, a2, a3);
}

extern f32 D_002B8344;
s32 func_00240B28(u8* a0) {
    s32 r;
    if (*(s32*)(a0 + 0xA30) > 0) {
        *(s32*)(a0 + 0xA30) -= D_002B8344;
        r = 1;
    } else {
        r = 2;
        if (*(s32*)(a0 + 0xA24) == 0) r = 0;
    }
    return r;
}

INCLUDE_ASM("asm/nonmatchings/unsplit/file136618", func_00240B68);

extern s32 D_00651D60;
extern s32 D_00651D64;
void func_00240B68(u8 *);
s32 func_0023EE80(u8 *, s32);
s32 func_0023DFC0_r(u8 *, s32) __asm__("func_0023DFC0");
s32 func_0023DFD8(u8 *, s32);
s32 func_00240400(u8 *, s32);
s32 func_0023F920(u8 *, s32);

void func_00240FA0(u8 *a0) {
    D_00651D64 = (s32)&D_00351E10;
    D_00651D60 = (s32)((u_long128 *)&D_00351E10 + 1);
    func_00240B68(a0);
    D_00651D60 = func_0023EE80(a0, D_00651D60);
    D_00651D60 = func_0023DFC0_r(a0, D_00651D60);
    ((u64 *)D_00651D60)[0] = 0x1000000000008001;
    ((u64 *)D_00651D60)[1] = 0xE;
    D_00651D60 += 0x10;
    ((u64 *)D_00651D60)[0] = *(u64 *)(*(u8 **)(a0 + 0x70) + 0x18);
    ((u64 *)D_00651D60)[1] = 6;
    D_00651D60 += 0x10;
    D_00651D60 = func_0023F920(a0, D_00651D60);
    D_00651D60 = func_0023F688((s32 *)a0, D_00651D60);
    D_00651D60 = func_0023DFD8(a0, D_00651D60);
    D_00651D60 = func_00240400(a0, D_00651D60);
    func_00237018((void *)D_00651D64, (D_00651D60 - D_00651D64) >> 4, 1);
}

extern s32 D_a3pad_002410B8_1;
extern s32 D_a3pad_002410B8_2;
s32 func_002403D0_r(u8 *, s32) __asm__("func_002403D0");
s32 func_00240AE0_f(s32 *, s32, s32, s32, f32) __asm__("func_00240AE0");
void func_002410B8(u8 *a0) {
    s32 a[4];
    s32 b[4];
    s32 p;

    D_00651D64 = (s32)&D_00351E10;
    D_00651D60 = (s32)((u_long128 *)&D_00351E10 + 1);
    func_00240B68(a0);
    D_00651D60 = func_0023EE80(a0, D_00651D60);
    D_00651D60 = func_0023DFC0_r(a0, D_00651D60);
    ((u64 *)D_00651D60)[0] = 0x1000000000008001;
    ((u64 *)D_00651D60)[1] = 0xE;
    D_00651D60 += 0x10;
    ((u64 *)D_00651D60)[0] = *(u64 *)(*(u8 **)(a0 + 0x70) + 0x18);
    ((u64 *)D_00651D60)[1] = 6;
    D_00651D60 += 0x10;
    D_00651D60 = func_00240118(a0, D_00651D60);
    if (*(s32 *)(a0 + 0xA8C) != 0) {
        D_00651D60 = func_002403D0_r(a0, D_00651D60);
    }
    p = D_00651D60;
    D_00651D60 += 0x10;
    D_00651D60 = (s32)func_00237008(0x42, 0x8000000048, (u64 *)D_00651D60);
    func_00236FD8((void *)p, D_00651D60);
    func_0023D528(a0, a, b);
    p = func_00240AE0_f((s32 *)(a0 + 0xAA0), b[0], b[1], D_00651D60, *(f32 *)(a0 + 0xA1C));
    D_00651D60 = p + 0x10;
    D_00651D60 = (s32)func_00237008(0x42, 0x8000000044, (u64 *)D_00651D60);
    func_00236FD8((void *)p, D_00651D60);
    func_00237018((void *)D_00651D64, (D_00651D60 - D_00651D64) >> 4, 1);
}

INCLUDE_ASM("asm/nonmatchings/unsplit/file136618", func_00241260);

typedef struct { u8 pad[0xA1C]; f32 a; f32 b; u8 pad2[0xD00 - 0xA24]; } S651E70;
void func_0023E0B0(s32 a0, s32 a1) {
    S651E70 *p = (S651E70 *)&D_00651E70 + a0;

    switch (a1) {
    case 0:
        p->a = 1.0f;
        p->b = -0.0999999940395355224609375f;
        break;
    case 1:
        p->a = 0.0f;
        p->b = 0.0999999940395355224609375f;
        break;
    case 2:
        p->b = 0.0f;
        p->a = 1.0f;
        break;
    case 3:
        p->b = 0.0f;
        p->a = 0.0f;
        break;
    }
}

s32 func_001233F8(s32);
void func_00241560(void) {
    s32 i;
    u8 *e = (u8 *)&D_00651E70;
    s32 *f = (s32 *)(e - 0x20);
    for (i = 4; i >= 0; i--) {
        if (*f != 0 && *(u32 *)e < 3 && func_001233F8(*(s32 *)(e + 4)) == 0) {
            *f = 0;
            if (*(s32 *)e == 0) {
                func_0023D1A0();
            }
        }
        f++;
        e += 0xD00;
    }
}

extern u8 D_00426940[];
void func_002415F0(u8 *a0) {
    s32 bufA[4];
    s32 pos[4];
    s32 x, y;
    D_00651D64 = (s32)&D_00351E10;
    D_00651D60 = (s32)((u_long128 *)&D_00351E10 + 1);
    func_0023D528(a0, bufA, pos);
    x = pos[0];
    y = pos[1];
    func_0023D698(2);
    D_00651D60 = func_0023D700_f(*(s32 *)(a0 + 0xA84), (s32)D_00426940, x, y, D_00651D60, *(f32 *)(a0 + 0xA1C));
    func_00237018((void *)D_00651D64, (D_00651D60 - D_00651D64) >> 4, 1);
}

INCLUDE_ASM("asm/nonmatchings/unsplit/file136618", func_002416A8);

INCLUDE_ASM("asm/nonmatchings/unsplit/file136618", func_00241948);

extern u32 D_00652888[];

void func_00241A10(s32 arg0, u32 arg1) {
    D_00652888[arg0 * 0x340] = arg1;
}

void func_002492D0(f32 *, f32, f32, f32, f32);

void func_00241A38(s32 a0) {
    u8 *p;
    u8 *q;
    s32 t;
    u16 r;
    s32 w;

    if (D_00651E50[a0] != 0) {
        p = (u8 *)D_00651E50 + 0x20 + a0 * 0xD00;
        t = *(s32 *)p;
        if (t != 4) if (t != 3) {
            q = *(u8 **)(*(u8 **)(p + 4) + 0x6C);
            w = *(s32 *)(q + 0x44);
            r = *(u16 *)(q + 0xBE);
            *(s32 *)(p + 0x9E0) = w;
            *(f32 *)(p + 0x9E4) = w * 0.5235987f;
            func_002492D0((f32 *)(p + 0x9EC), 0.0f, 0.0f, 0.0f, 128.0f);
            *(s32 *)(p + 0x9FC) = r;
            *(f32 *)(p + 0xA00) = r * 0.017453289f;
            func_002492D0((f32 *)(p + 0xA08), 0.0f, 0.0f, 0.0f, 128.0f);
        }
    }
}

extern s32 func_0023D490(u8 *);
extern void func_0023E0B0(s32, s32);

u8 *func_00241B60(s32 a0, s32 a1) {
    u8 *p;
    s32 r;
    s32 *base = D_00651E50;
    p = (u8 *)D_00651E50 + 0x20 + a0 * 0xD00;
    base[a0] = 1;
    *(s32 *)((u8 *)base + a0 * 0xD00 + 0x24) = a1;
    *(s32 *)(p + 0xA18) = 1;
    *(s32 *)p = a0;
    r = func_0023D490(p);
    *(s32 *)(p + 0x94) = r;
    *(s32 *)(p + 0x98) = r;
    *(s32 *)(p + 0xA24) = 0;
    *(s32 *)(p + 0x770) = 0;
    *(s32 *)(p + 0x9D0) = 0;
    *(s32 *)(p + 0x9C) = 0;
    func_0023E0B0(a0, 1);
    return p;
}

u8 *func_00241B60(s32, s32);

void func_00241C00(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    u8 *p = func_00241B60(3, arg4);
    *(s32 *)(p + 0xA88) = arg0;
    *(s32 *)(p + 0xA8C) = arg1;
    *(s32 *)(p + 0xA90) = arg2;
    *(s32 *)(p + 0xA94) = arg3;
}

extern s32 D_00454A20_c[] __asm__("D_00454A20");
extern u8 D_00451040[];
void func_0023D1A0(void);
void func_00242BD0(void);

void func_00241C60(s32 a0, s32 a1) {
    u8 *p;

    if (a0 == 0 && a1 != 4) {
        D_00651E50[a1] = 0;
        return;
    }
    p = func_00241B60(a1, a0);
    if (a1 == 0) {
        func_0023D1A0();
        func_00242BD0();
    }
    if (a1 == 4) {
        *(s32 *)(p + 0x9E0) = D_00454A20_c[0];
        *(f32 *)(p + 0x9E4) = D_00454A20_c[0] * 0x1.0c152p-1f;
        func_002492D0((f32 *)(p + 0x9EC), 0.0f, 0.0f, 0.0f, 128.0f);
        func_0023CFE8(p + 0xA34, D_00454A20_c[4], (s32)D_00451040);
    } else {
        func_00241A38(a1);
        *(s32 *)(p + 0xA2C) = 0;
        *(s32 *)(p + 0xA30) = 0;
    }
}

INCLUDE_ASM("asm/nonmatchings/unsplit/file136618", func_00241D60);

extern u8 D_0044A830[];
extern u8 D_0044C5A0[];
extern u8 D_0044DFD0[];
extern u8 D_0044F380[];
extern u8 D_0044F4D0[];
extern u8 D_00451040[];
extern u32 D_002C1EA8;
void func_00247668();
s32 func_0011ED60();
s32 func_002416A8();
void func_00241D60();

void func_00242A38(void) {
    func_00247668(D_0044A830);
    func_00247668(D_0044C5A0);
    func_00247668(D_0044DFD0);
    func_00247668(D_0044F380);
    func_00247668(D_0044F4D0);
    func_00247668(D_00451040);
    memset(D_00651E50, 0, 0x4130);
    D_00651E50[0x1049] = (D_002C1EA8 >> 3) & 1;
    func_00241D60();
    if (func_0011ED60(func_002416A8) == 0) {
        func_0011ED30(0x29811, func_002416A8);
    }
}

extern void *func_00240910(void);

void func_00242B00(void) {
    void *temp = func_00240910();
    if (temp != NULL) {
        if (*(s32 *)((u8 *)temp + 0x770) == 0) {
            *(s32 *)((u8 *)temp + 0x770) = 1;
        }
    }
}

extern void *func_00240910(void);

void func_00242B38(void) {
    void *temp = func_00240910();
    if (temp != NULL) {
        *(s32 *)((u8 *)temp + 0x774) = 1;
    }
}

extern void func_0023D1A0(void);
extern s32 D_00651E50[];

void func_00242B68(s32 arg0) {
    D_00651E50[arg0] = 0;
    if (arg0 == 4) {
        func_0023D1A0();
    }
}

extern struct {
    char _[0xCF0];
    s32 field_0CF0;
} D_00654570;

void func_00242BA0(void) {
    if (D_00654570.field_0CF0 == 0) {
        D_00654570.field_0CF0 = 1;
    }
}

extern s32 D_00655264;

// func_00242BC0 (src/unsplit/seg_132D60.c)
void func_00242BC0(void) {
    D_00655264 = 1;
}

extern s32 D_00652898;

void func_00242BD0(void) {
    D_00652898 = 0;
}

extern s32 D_00652898;

// func_0023F758 (src/unsplit/seg_132D60.c)
void func_0023F758(void) {
    D_00652898 = 1;
}

extern s32 D_00651E50[];

s32 func_00242BF0(s32 arg0) {
    return D_00651E50[arg0];
}

typedef struct { s32 w; s32 h; u8 pad[8]; u8 clut[0x400]; u8 img[1]; } Seg132Tex;
typedef struct { u8 pad[0x140]; Seg132Tex *tex; } Seg132TexOwner;
typedef struct { s32 x; s32 y; s32 z; s32 w; } Seg132QW;
u32 func_00122048(s32 a, u32 b);
u_long128 *func_0011F9E8(s32 dbp, s32 dbw, s32 dpsm, s32 dsax, s32 dsay, s32 rrw, s32 rrh, s32 qwc, s32 src, u_long128 *pkt);
u64 *func_0011F970(u64 arg0, u64 arg1, u64 *arg2);
void func_0011F9B0(u_long128 *arg0, s32 arg1, u_long128 *arg2);
void *sceDmaGetChan(int);
void sceDmaSend(void *, void *);
void func_001220B8(u32);

void func_00242C08(Seg132TexOwner *a0, s32 a1, s32 *a2, f32 f) {
    Seg132Tex *t = a0->tex;
    u32 buf;
    u_long128 *p;
    Seg132QW *v;
    s32 n;

    if (t == NULL) {
        return;
    }
    buf = func_00122048(0, 0x10);
    p = func_0011F9E8(0x3C00, 0, 0, 0, 0, 0x10, 0x10, 0x40, (s32)t->clut, (u_long128 *)buf);
    p = func_0011F9E8(0x3A00, 4, 0x13, 0, 0, t->w, t->h, t->w * t->h / 16, (s32)t->img, p);
    v = (Seg132QW *)p;
    v++;
    ((u64 *)v)[0] = 0x80AB400000008001;
    ((u64 *)v)[1] = 0x53531EEE;
    v++;
    v = (Seg132QW *)func_0011F970(0x3F, 0, (u64 *)v);
    v = (Seg132QW *)func_0011F970(6, 0x20078005A1313A00, (u64 *)v);
    v = (Seg132QW *)func_0011F970(0x14, 0, (u64 *)v);
    v->x = 0x80;
    v->y = 0x80;
    v->z = 0x80;
    v->w = (u32)(f * 128.0f);
    v++;
    n = a1 + 1;
    v->x = t->h * a1 * 16;
    v->y = 0;
    v++;
    v->x = a2[0] - t->h / 2 * 16;
    v->y = a2[1] - t->h / 2 * 16;
    v->z = 0;
    v->w = 0x8000;
    v++;
    v->x = t->h * n * 16;
    v->y = t->h * 16;
    v++;
    v->x = a2[0] + t->h / 2 * 16;
    v->y = a2[1] + t->h / 2 * 16;
    v->z = 0;
    v->w = 0;
    v++;
    func_0011F9B0(p, 7, (u_long128 *)v);
    FlushCache(0);
    sceDmaSend(sceDmaGetChan(2), (void *)((buf & 0x0FFFFFFF) | 0x80000000));
    sceGsSyncPath(0, 0);
    func_001220B8(buf);
}

void func_00242EF8(Seg132TexOwner *a0, s32 a1, s32 a2, s32 *a3, s32 *col) {
    Seg132Tex *t = a0->tex;
    u32 buf;
    u_long128 *p;
    Seg132QW *v;
    s32 d;

    if (t == NULL) {
        return;
    }
    v = (Seg132QW *)func_00122048(0, 0x10);
    buf = (u32)v;
    p = func_0011F9E8(0x3C00, 0, 0, 0, 0, 0x10, 0x10, 0x40, (s32)t->clut, (u_long128 *)buf);
    v = (Seg132QW *)func_0011F9E8(0x3A00, 4, 0x13, 0, 0, t->w, t->h, t->w * t->h / 16, (s32)t->img, p);
    p = (u_long128 *)v;
    v++;
    ((u64 *)v)[0] = 0x80AB400000008001;
    ((u64 *)v)[1] = 0x53531EEE;
    v++;
    v = (Seg132QW *)func_0011F970(0x3F, 0, (u64 *)v);
    v = (Seg132QW *)func_0011F970(6, 0x20078005A1313A00, (u64 *)v);
    v = (Seg132QW *)func_0011F970(0x14, 0, (u64 *)v);
    v->x = col[0];
    d = a1 / 2 * 16;
    v->y = col[1];
    v->z = col[2];
    v->w = col[3];
    v++;
    v->x = 0;
    v->y = 0;
    v++;
    v->x = a3[0] - d;
    v->y = a3[1] - d;
    v->z = 0;
    v->w = 0x8000;
    v++;
    v->x = t->h * 16;
    v->y = t->h * 16;
    v++;
    v->x = a3[0] + d;
    v->y = a3[1] + d;
    v->z = 0;
    v->w = 0;
    v++;
    func_0011F9B0(p, 7, (u_long128 *)v);
    FlushCache(0);
    sceDmaSend(sceDmaGetChan(2), (void *)((buf & 0x0FFFFFFF) | 0x80000000));
    sceGsSyncPath(0, 0);
    func_001220B8(buf);
}

void func_00243168(void *arg0, s32 arg1, s32 arg2) {
    memset(arg0, 0, 0x10);
    ((s32 *)arg0)[0] = arg1;
    ((s32 *)arg0)[1] = arg2;
}

typedef struct { s32 a; s32 b; s32 c; } Seg132E12;
typedef struct { s32 cap; Seg132E12* buf; s32 cnt; s32 rd; } Seg132Q;
void func_002431B8(Seg132Q* q, Seg132E12* e) {
    if (q->cnt != q->cap) {
        q->buf[q->cnt] = *e;
        q->cnt++;
    }
}

s32 func_00243208(Seg132Q* q, Seg132E12* e) {
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

s32 func_00243278(Seg132Q* q, Seg132E12* e) {
    if (q->cnt == q->rd) {
        return 0;
    }
    *e = q->buf[q->rd];
    return 1;
}

void func_002432C8(void *arg0) {
    *(u32 *)((u8 *)arg0 + 12) = 0;
    *(u32 *)((u8 *)arg0 + 8) = 0;
}

extern u8 D_006560F0[];
extern s32 D_006560E0;

void func_002432D8(s32 a0, s32 a1, s32 a2, s32 a3) {
    s32 i;
    s32 *p;

    func_002475E8(a0, D_006560F0, a1);
    p = (s32 *)(D_006560F0 + 0xA4);
    for (i = 0; i < 4; i++) {
        p[i * 4 - 1] += a2 * 16;
        p[i * 4] += a3 * 16;
    }
    D_006560E0 = func_002388B8(D_006560F0, 1, D_006560E0);
}

void func_002432D8(s32, s32, s32, s32);                /* extern */

void func_00243380(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    if (arg0 != 0) {
        func_002479A0(arg1);
    }
    func_00247AA0(arg1);
    func_002432D8(arg1, arg2, arg3, arg4);
}

extern s32 D_00458548;
extern s32 D_0045854C;
extern s32 D_006560E0;

void func_002433E8(s32 x, s32 y, s32 a2, s32 a3, f32 f) {
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
    D_006560E0 = func_001F0638_c(D_006560E0, 1, *(s32 *)col, (((x + D_00458548) * 16 + 0x7000) >> 4) - 0x700,
                                 (((y + D_0045854C) * 16 + 0x7400) >> 4) - 0x740, a2);
}

void func_002477A8(u8 *, s32 *);
u8 *func_00147A88(s32);

void func_00243508(s32 a0, u8 *a1, s32 a2, s32 a3, s32 a4, s32 a5, s32 a6, s32 a7, f32 f) {
    s32 buf[4];
    s32 i;
    s32 n;
    u8 *q = a1;

    for (i = 0; i < 7; i++) {
        func_00243380(a0, (s32)a1, a2, a4, a5);
        a1 += 0xC0;
    }
    for (i = 0; i < 2; i++) {
        func_00243380(a0, (s32)a1, a3, a4, a5);
        a1 += 0xC0;
    }
    if (a6 != 0) {
        n = func_00147808(*(u16 *)func_00147A88(a6));
        func_002477A8(q, buf);
        func_002433E8(a4 + buf[0], a5 + buf[1], n, a7, f);
    }
}

typedef struct { s32 a; s32 b; f32 c; } Seg132Msg;
extern u8 D_006561E4[];
void func_00243630(s32 a0, s32 a1) {
    Seg132Msg m;

    m.b = a1;
    m.a = a0;
    m.c = 1.0f;
    func_002431B8((Seg132Q*)D_006561E4, (Seg132E12*)&m);
}

extern s32 D_006561D0;

void func_00243668(void) {
    D_006561D0 = 0;
    func_002432C8((u8 *)&D_006561D0 + 0x14);
}

typedef struct { s32 a; s32 b; s32 c; } Seg132V3;
typedef struct { s32 flag; Seg132V3 v; s32 z; } Seg132Slot;
extern Seg132Slot D_006561D0_s __asm__("D_006561D0");
void func_00243690(Seg132V3* a0) {
    D_006561D0_s.z = 0;
    D_006561D0_s.v = *a0;
    D_006561D0_s.flag = 1;
}

INCLUDE_ASM("asm/nonmatchings/unsplit/file136618", func_002436C0);

void func_002436C0(s32);

s32 func_00243A20(void) {
    Seg132E12 e;
    s32 r = 0;
    s32 *d = &D_006561D0;

    if (*d == 0) {
        if (func_00243208((Seg132Q *)(d + 5), &e) == 0) {
            return 0;
        }
        func_00243690((Seg132V3 *)&e);
    } else {
        r = func_00243278((Seg132Q *)(d + 5), &e) != 0;
    }
    func_002436C0(r);
    return 0;
}

extern u8 D_00454A40[];
extern u8 D_00455A10[];
extern u8 D_004569E0[];
extern u8 D_004577D0[];
extern u8 D_00458520[];
extern u8 D_00656230[];

void func_00243A90(void) {
    memset(&D_006561D0, 0, 0x60);
    func_00243168((u8 *)&D_006561D0 + 0x14, 5, (s32)((u8 *)&D_006561D0 + 0x24));
    D_006561D0 = 0;
    func_00247668(D_00454A40);
    func_00247668(D_00455A10);
    func_00247668(D_004569E0);
    func_00247668(D_004577D0);
    func_00247B60(D_00458520, D_00656230, D_00454A40);
    func_00247B60(D_00458520, D_00656230 + 0x24, D_00455A10);
    func_00247B60(D_00458520, D_00656230 + 0x48, D_004569E0);
    func_00247B60(D_00458520, D_00656230 + 0x6C, D_004577D0);
    if (func_0011ED60(func_00243A20) == 0) {
        func_0011ED30(0x29811, func_00243A20);
    }
}

extern s32 D_006561D0_w[] __asm__("D_006561D0");
s32 func_00243BD8(void) {
    s32 buf[4];

    if (D_006561D0_w[0] != 0) {
        return 1;
    }
    return func_00243278((Seg132Q*)&D_006561D0_w[5], (Seg132E12*)buf) != 0;
}

INCLUDE_ASM("asm/nonmatchings/unsplit/file136618", func_00243C10);

void func_00243C10(s32 arg0, s32 arg1, s32 arg2, s32 arg3, f32 arg4, s32 arg5);
void func_00247AA0(s32);

void func_00243D18(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, f32 fparg0, s32 arg5) {
    if (arg0 != 0) {
        func_002479A0(arg1);
    }
    func_00247AA0(arg1);
    func_00243C10(arg1, arg2, arg3, arg4, fparg0, arg5);
}

extern s32 D_00656420;
void func_00243DA0(s32 x, s32 y, s32 a2, s32 *c, f32 f) {
    u8 col[4];
    u8 *a;
    col[0] = c[0];
    col[1] = c[1];
    col[2] = c[2];
    a = &col[3];
    *a = f * 128.0f;
    D_00656420 = func_001F0638_c(D_00656420, 1, *(s32 *)col, ((x * 16 + 0x7000) >> 4) - 0x700,
                                 ((y * 16 + 0x7400) >> 4) - 0x740, a2);
}

extern s32 D_00656420;
extern s32 func_001F0868(s32, s32, s32, s32, s32, s32, s32, s32);
void func_00243E58(s32 a0, s32 a1, s32 a2, s32 *c, f32 f) {
    u8 col[4];
    u8 *a;
    col[0] = c[0];
    col[1] = c[1];
    col[2] = c[2];
    a = &col[3];
    *a = f * 128.0f;
    D_00656420 = func_001F0868(D_00656420, 1, 1, *(s32 *)col, a0, a1, a2, 12);
}

INCLUDE_ASM("asm/nonmatchings/unsplit/file136618", func_00243EF8);

INCLUDE_ASM("asm/nonmatchings/unsplit/file136618", func_00244188);

INCLUDE_ASM("asm/nonmatchings/unsplit/file136618", func_00244298);

typedef struct { char pad0[0x10]; s32 unk_10; char pad14[0xA00 - 0x14]; } A2Ent_A00;
extern A2Ent_A00 D_00656510[3][5];

void func_002444A0(void) {
    s32 i, j;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 5; j++) {
            D_00656510[i][j].unk_10 = 0;
        }
    }
}

extern u8 D_00458560[];
extern u8 D_00459C50[];
extern u8 D_00459C68[];
extern u8 D_00459C78[];
extern u8 D_00459C98[];
s32 func_00244298();

void func_00244500(void) {
    s32 i;
    s32 j;
    u8 *p;
    memset(D_00656510, 0, 0x9620);
    func_00247668(D_00458560);
    for (i = 0; i < 3; i++) {
        p = (u8 *)D_00656510 + 0x10 + ((i << 13) + i * 0x1200);
        for (j = 0; j < 5; j++) {
            func_00247AE0(D_00459C50, p + 0x30, D_00458560);
            func_00247AE0(D_00459C68, p + 0x330, D_00458560);
            func_00247AE0(D_00459C78, p + 0x4B0, D_00458560);
            func_00247AE0(D_00459C98, p + 0x930, D_00458560);
            p += 0xA00;
        }
    }
    if (func_0011ED60(func_00244298) == 0) {
        func_0011ED30(0x29811, func_00244298);
    }
}

INCLUDE_ASM("asm/nonmatchings/unsplit/file136618", func_00244670);

typedef struct { s32 unk_00; char pad04[0xA00 - 4]; } A2Ent2_A00;
typedef struct { s32 count[4]; A2Ent2_A00 ent[3][5]; } A2Tbl_656510;
extern A2Tbl_656510 D_00656510_t __asm__("D_00656510");

s32 func_002448D8(void) {
    s32 i, j;
    A2Ent2_A00 *row;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < D_00656510_t.count[i]; j++) {
            row = D_00656510_t.ent[i];
            if (row[j].unk_00 != 0) {
                return 1;
            }
        }
    }
    return 0;
}

void func_00244960(void) {

}

extern u8 D_0065FCA0[];
extern s32 D_0065FC90_i __asm__("D_0065FC90");

/* defined under another C name: fm declares it below as func_00244968(Mon132_C0 *, u8 *, s32, s32) */
void func_00244968_d(s32 a0, s32 a1, s32 a2, s32 a3) __asm__("func_00244968");
void func_00244968_d(s32 a0, s32 a1, s32 a2, s32 a3) {
    s32 i;
    s32 *p;

    func_002475E8(a0, D_0065FCA0, a1);
    p = (s32 *)(D_0065FCA0 + 0xA4);
    for (i = 0; i < 4; i++) {
        p[i * 4 - 1] += a2 * 16;
        p[i * 4] += a3 * 16;
    }
    D_0065FC90_i = func_002388B8(D_0065FCA0, 1, D_0065FC90_i);
}

typedef struct { u8 b[0xC0]; } Mon132_C0a;
extern Mon132_C0a D_0065FD80_a[5][10] __asm__("D_0065FD80");
extern Mon132_C0a D_00662300_a[3] __asm__("D_00662300");
extern s32 D_00662540_w[] __asm__("D_00662540");
void func_00247A30(Mon132_C0a *);

void func_00244A10(s32 a0, s32 a1) {
    s32 *d = D_00662540_w;
    s32 i;
    s32 j;

    if (d[0] == 0) {
        d[1] = a1;
        d[0] = 1;
        d[5] = a0;
        for (i = 0; i < 5; i++) {
            for (j = 0; j < 10; j++) {
                func_00247A30(&D_0065FD80_a[i][j]);
            }
        }
        for (i = 0; i < 3; i++) {
            func_00247A30(&D_00662300_a[i]);
        }
    } else {
        d[1] += a1;
    }
    d[2] = 0;
}

extern void* D_00662540;

void func_00244B00(void) {
    D_00662540 = NULL;
}

s32 func_00244B10(s32 n, s32 *d) {
    s32 i;
    s32 r = 5;

    d[0] = n / 10000;
    d[1] = n % 10000 / 1000;
    d[2] = n % 1000 / 100;
    d[3] = n % 100 / 10;
    d[4] = n % 10;
    for (i = 0; i < 4; i++) {
        if (d[i] != 0) {
            break;
        }
        r--;
    }
    return r;
}

extern u8 D_00426820[];
extern u8 D_004267F0[];
typedef struct { u8 b[0xC0]; } Mon132_C0;
extern Mon132_C0 D_0065FD80_m[5][10] __asm__("D_0065FD80");
extern Mon132_C0 D_00662300_m[3] __asm__("D_00662300");
void func_00244968(Mon132_C0 *, u8 *, s32, s32);

void func_00244BE0(s32 a0, s32 a1, s32 a2) {
    s32 x;
    s32 d[5];
    s32 k;
    s32 i;

    k = func_00244B10(a0, d);
    x = a1;
    for (i = 0; i < k; i++) {
        func_00244968(&D_0065FD80_m[i][d[5 - k + i]], D_00426820, x, a2);
        x += 0xD;
    }
    x += 2;
    func_00244968(&D_00662300_m[0], D_004267F0, x, a2);
    func_00244968(a0 < 2 ? &D_00662300_m[1] : &D_00662300_m[2], D_004267F0, x, a2);
}

typedef struct {
    u8 pad[0x60];
    s32 flags;
    u8 pad64[0x5C];
} A3Mon;
extern A3Mon D_0065FD80[5][10];
extern A3Mon D_00662300[3];
void func_00247108(A3Mon *);
void func_00247218(A3Mon *);
void func_00246C60(A3Mon *);
void func_00246C28(A3Mon *);
void func_00246E80(A3Mon *);
void func_00246FF0(A3Mon *);
void func_00247AA0_m(A3Mon *) __asm__("func_00247AA0");

void func_00244D00(s32 a0, s32 a1) {
    s32 i;
    s32 j;
    A3Mon *p;

    if (a0) {
        for (i = 0; i < 5; i++) {
            for (j = 0; j < 10; j++) {
                func_00247108(&D_0065FD80[i][j]);
                func_00247218(&D_0065FD80[i][j]);
            }
        }
        p = D_00662300;
        for (i = 0; i < 3; i++, p++) {
            func_00247108(p);
            func_00247218(p);
        }
    }
    if (a1) {
        for (i = 0; i < 5; i++) {
            for (j = 0; j < 10; j++) {
                if (D_0065FD80[i][j].flags & 2) {
                    func_00246C60(&D_0065FD80[i][j]);
                    func_00246C28(&D_0065FD80[i][j]);
                }
                if (D_0065FD80[i][j].flags & 0x40) {
                    func_00246E80(&D_0065FD80[i][j]);
                    func_00246FF0(&D_0065FD80[i][j]);
                }
            }
        }
        p = D_00662300;
        for (i = 0; i < 3; i++, p++) {
            if (p->flags & 2) {
                func_00246C60(p);
                func_00246C28(p);
            }
            if (p->flags & 0x40) {
                func_00246E80(p);
                func_00246FF0(p);
            }
        }
    }
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 10; j++) {
            func_00247AA0_m(&D_0065FD80[i][j]);
        }
    }
    p = D_00662300;
    for (i = 0; i < 3; i++, p++) {
        func_00247AA0_m(p);
    }
}

INCLUDE_ASM("asm/nonmatchings/unsplit/file136618", func_00244F28);

extern u64 D_0065FB30[];
extern u_long128 *D_0065FC90;
extern u_long128 *D_0065FC94;
void func_00244F28(void);

s32 func_00245090(void) {
    func_002370C8(D_0065FB30);
    D_0065FB30[0x1C] = 5;
    D_0065FB30[0xC] = 0x30003;
    D_0065FB30[0xE] = 0x8000000048;
    func_00237018(D_0065FB30, 0x16, 1);
    func_00244960();
    D_0065FC94 = (u_long128 *)&D_00351E10;
    D_0065FC90 = (u_long128 *)&D_00351E10 + 1;
    func_00244F28();
    func_00237018(D_0065FC94, D_0065FC90 - D_0065FC94, 1);
    return 0;
}

extern u8 D_00459D40[];
extern u8 D_0045B770[];
extern u8 D_0045B780[];
void func_00247AE0();

void func_00245148(void) {
    s32 i;
    memset(&D_00662540, 0, 0x18);
    func_00247668(D_00459D40);
    func_00247AE0(D_0045B770, D_00662300, D_00459D40);
    for (i = 0; i < 5; i++) {
        func_00247AE0(D_0045B780, D_0065FD80[i], D_00459D40);
    }
    if (func_0011ED60(func_00245090) == 0) {
        func_0011ED30(0x28489, func_00245090);
    }
}

s32 func_00245228(void) {
    return D_00662540 != 0;
}

typedef struct {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    f32 unkC;
    s32 unk10;
} Struct_006627B0;

extern Struct_006627B0 D_006627B0;

void func_00245238(s32 arg0, s32 arg1) {
    D_006627B0.unk10 = 1;
    if (D_006627B0.unk8 == 0 || D_006627B0.unk0 != arg0) {
        D_006627B0.unk0 = arg0;
        D_006627B0.unk4 = arg1;
        D_006627B0.unk8 = 1;
        D_006627B0.unkC = 1.0f;
    }
}

typedef struct {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    f32 unkC;
    s32 unk10;
    s32 unk14;
} Struct_006627B0_b;
extern Struct_006627B0_b D_006627B0_b __asm__("D_006627B0");
void func_00245280(s32 arg0, s32 arg1) {
    D_006627B0_b.unk10 = 1;
    D_006627B0_b.unk14 = 1;
    if (D_006627B0_b.unk8 == 0 || D_006627B0_b.unk0 != arg0) {
        D_006627B0_b.unk0 = arg0;
        D_006627B0_b.unk4 = arg1;
        D_006627B0_b.unk8 = 1;
        D_006627B0_b.unkC = 1.0f;
    }
}

void func_002452C8(void) {
    if (D_006627B0.unk8 != 0 && D_006627B0.unk8 < 4) {
        D_006627B0.unk8 = 4;
    }
}

extern void* D_006627B8;

void func_002452F0(void) {
    D_006627B8 = NULL;
}

extern u8 D_006626D0[];
extern s32 D_006626C0;
void func_002475E8(s32, u8 *, s32);
s32 func_002388B8(u8 *, s32, s32);
typedef struct { s32 a; s32 b; s32 c; s32 d; } V4_5300;
typedef struct { u8 pad[0x60]; V4_5300 m[4]; V4_5300 n[4]; } Obj5300;
extern Obj5300 D_006626D0_o __asm__("D_006626D0");

void func_00245300(s32 a0, s32 a1, s32 x, s32 y, f32 f) {
    s32 i;

    func_002475E8(a0, (u8 *)&D_006626D0_o, a1);
    for (i = 0; i < 4; i++) {
        s32 *e = &D_006626D0_o.n[i].b;
        e[-1] += x * 16;
        e[0] += y * 16;
    }
    for (i = 0; i < 4; i++) {
        D_006626D0_o.m[i].d = D_006626D0_o.m[i].d * f;
    }
    D_006626C0 = func_002388B8((u8 *)&D_006626D0_o, 1, D_006626C0);
}

extern s32 D_006627C8;
extern s32 D_006627D0;
extern s32 D_006627D8;
extern u8 D_00431D20[];
extern sceVu0FMATRIX D_002DEC20;
extern void *func_001315C0(s32, s32, f32 *, f32);
void func_00237A48(s32 *, sceVu0FMATRIX, f32 *, s32);
s32 func_00249580(f32 *);
void func_00249558(void *, void *);

void func_002453E8(s32 a0, f32 f) {
    sceVu0FVECTOR v;
    s32 w[4];
    Struct_006627B0 *s = &D_006627B0;
    s32 o = 0;

    switch (s->unk0) {
    case 0:
        o = D_006627C8;
        break;
    case 1:
        o = D_006627D0;
        break;
    case 2:
        o = D_006627D8;
        break;
    }
    if (a0 != 0) {
        func_002479A0(o);
    }
    func_00247AA0(o);
    func_001315C0(s->unk4, 0x8004, v, 0.0f);
    if (func_00249580(v) == 0) {
        func_00237A48(w, D_002DEC20, v, 1);
        func_00249558(w, w);
        w[1] -= 0x36;
        func_00245300(o, (s32)D_00431D20, w[0], w[1], f);
    }
}

extern u64 D_00662560[];
extern u_long128 *D_006626C0_p __asm__("D_006626C0");
extern u_long128 *D_006626C4;
void func_002453E8(s32, f32);
void func_00245508(s32 a0, f32 f) {
    func_002370C8(D_00662560);
    D_00662560[0x1C] = 5;
    D_00662560[0xC] = 0x30003;
    func_00237018(D_00662560, 0x16, 1);
    D_006626C4 = (u_long128 *)&D_00351E10;
    D_006626C0_p = (u_long128 *)&D_00351E10 + 1;
    func_002453E8(a0, f);
    func_00237018(D_006626C4, D_006626C0_p - D_006626C4, 1);
}

INCLUDE_ASM("asm/nonmatchings/unsplit/file136618", func_002455C0);

extern u8 D_0045B7B0[];
extern u8 D_0045BC00[];
extern s32 D_006627C8;
extern s32 D_006627D0;
extern s32 D_006627D8;
void func_00247668();
void func_00247B60();
s32 func_0011ED60();
s32 func_002455C0();

void func_002456E8(void) {
    s32 buf[4];
    memset(&D_006627B0, 0, 0x18);
    D_006627B0.unk8 = 0;
    func_00247668(D_0045B7B0);
    func_00247B60(D_0045BC00, buf, D_0045B7B0);
    D_006627C8 = buf[2];
    D_006627D0 = buf[1];
    D_006627D8 = buf[0];
    if (func_0011ED60(func_002455C0) == 0) {
        func_0011ED30(0x28489, func_002455C0);
    }
}

void func_00245798(void *arg0, s32 arg1, f32 *arg2) {
    *(s32 *)((u8 *)arg0 + 8) = arg1;
    *(s32 *)arg0 = 1;
    *(s32 *)((u8 *)arg0 + 4) = 0;
    sceVu0CopyVector((u8 *)arg0 + 0x10, arg2);
}

typedef struct { s32 used; s32 age; u8 pad[0x858]; } A2Ent860;
extern u8 D_00662A30[];
extern A2Ent860 D_00662A30_a[10] __asm__("D_00662A30");

void *func_002457C8(void) {
    s32 i;
    A2Ent860 *best = NULL;
    s32 m = -1;
    A2Ent860 *e;

    e = D_00662A30_a;
    for (i = 0; i < 10; i++, e++) {
        if (e->used == 0) {
            return e;
        }
    }
    e = (A2Ent860 *)D_00662A30;
    for (i = 0; i < 10; i++, e++) {
        if (m < e->age) {
            m = e->age;
            best = e;
        }
    }
    return best;
}

extern void *func_001315C0(s32, s32, f32 *, f32);
void func_00245840(s32 arg0, s32 arg1) {
    void *temp;
    f32 tempf;
    temp = func_002457C8();
    func_001315C0(arg0, 0x8004, &tempf, 0.0f);
    func_00245798(temp, arg1, &tempf);
}

extern void *func_002457C8(void);
extern void func_00245798(void *arg0, s32 arg1, f32 *arg2);

void func_002458A0(f32 *arg0, s32 arg1) {
    void *ret = func_002457C8();
    func_00245798(ret, arg1, arg0);
}

extern u8 D_00662A30[];

void func_002458E0(void) {
    u8 *p;
    s32 i;

    p = D_00662A30;
    goto offset;
offset:
    p += 0x4B60;
    for (i = 9; i >= 0; i--) {
        *(void **)p = NULL;
        p -= 0x860;
    }
}

void func_00245918(void) {

}

extern s32 D_00662940;
extern Obj5300 D_00662950_o __asm__("D_00662950");

void func_00245920(s32 a0, s32 a1, s32 x, s32 y, f32 f) {
    s32 i;

    func_002475E8(a0, (u8 *)&D_00662950_o, a1);
    for (i = 0; i < 4; i++) {
        s32 *e = &D_00662950_o.n[i].b;
        e[-1] += x * 16;
        e[0] += y * 16;
    }
    for (i = 0; i < 4; i++) {
        D_00662950_o.m[i].d = D_00662950_o.m[i].d * f;
    }
    D_00662940 = func_002388B8((u8 *)&D_00662950_o, 1, D_00662940);
}

s32 func_00245A08(s32 n, s32 *d) {
    s32 i;
    s32 r = 5;

    d[0] = n / 10000;
    d[1] = n % 10000 / 1000;
    d[2] = n % 1000 / 100;
    d[3] = n % 100 / 10;
    d[4] = n % 10;
    for (i = 0; i < 4; i++) {
        if (d[i] != 0) {
            break;
        }
        r--;
    }
    return r;
}

extern void func_002479A0(s32);
extern void func_00247AA0(s32);

void func_00245AD8(s32 arg0, s32 arg1) {
    if (arg0 != 0) {
        func_002479A0(arg1);
    }
    func_00247AA0(arg1);
}

extern u_long128 *D_00662940_p __asm__("D_00662940");
extern u_long128 *D_00662944;
void func_00249558(void *, void *);

void func_00245B08(s32 a0, u8 *e) {
    s32 d[5];
    s32 w[4];
    s32 i;
    s32 k;
    s32 x;
    s32 y;
    u8 *p;

    p = e + 0xE0;
    for (i = 0; i < 10; i++) {
        func_00245AD8(a0, (s32)p);
        p += 0xC0;
    }
    func_00245AD8(a0, (s32)(e + 0x20));
    if (func_00249580((f32 *)(e + 0x10)) != 0) {
        return;
    }
    k = func_00245A08(*(s32 *)(e + 8), d);
    func_00237A48(w, D_002DEC20, (f32 *)(e + 0x10), 1);
    func_00249558(w, w);
    x = w[0] -= (k * 16 + 9) / 2;
    y = w[1] -= 0x14;
    D_00662944 = (u_long128 *)&D_00351E10;
    D_00662940_p = (u_long128 *)&D_00351E10 + 1;
    for (i = 0; i < k; i++) {
        func_00245920((s32)(e + 0xE0 + d[5 - k + i] * 0xC0), (s32)D_00426820, x, y, 1.0f);
        x += 0xD;
    }
    func_00245920((s32)(e + 0x20), (s32)D_004267F0, x + 2, y, 1.0f);
    func_00237018(D_00662944, D_00662940_p - D_00662944, 1);
}

INCLUDE_ASM("asm/nonmatchings/unsplit/file136618", func_00245CD0);

extern u64 D_006627E0[];
typedef struct { s32 used; u8 pad[0x85C]; } E245DA0;
extern E245DA0 D_00662A30_q[] __asm__("D_00662A30");
void func_00245918(void);
void func_00245CD0(E245DA0 *);
s32 func_00245DA0(void) {
    s32 i;
    func_002370C8(D_006627E0);
    D_006627E0[0x1C] = 5;
    D_006627E0[0xC] = 0x30003;
    D_006627E0[0xE] = 0x8000000048;
    func_00237018(D_006627E0, 0x16, 1);
    func_00245918();
    for (i = 0; i < 10; i++) {
        if (D_00662A30_q[i].used != 0) {
            func_00245CD0(&D_00662A30_q[i]);
        }
    }
    return 0;
}

extern u8 D_0045BC10[];
extern u8 D_0045D240[];
extern u8 D_0045D248[];
void func_00247AE0();
s32 func_00245DA0();

void func_00245E40(void) {
    s32 i;
    u8 *p;
    func_00247668(D_0045BC10);
    p = D_00662A30;
    for (i = 0; i < 10; i++) {
        func_00247AE0(D_0045D240, p + 0x20, D_0045BC10);
        func_00247AE0(D_0045D248, p + 0xE0, D_0045BC10);
        p += 0x860;
    }
    if (func_0011ED60(func_00245DA0) == 0) {
        func_0011ED30(0x28489, func_00245DA0);
    }
}

typedef struct { s32 unk0; u8 pad[0x85C]; } Seg132_662A30;
extern Seg132_662A30 D_00662A30_e[] __asm__("D_00662A30");
s32 func_00245F18(void) {
    s32 i;

    for (i = 0; i < 10; i++) {
        if (D_00662A30_e[i].unk0 != 0) {
            return 1;
        }
    }
    return 0;
}

typedef struct { s32 v[4]; } Seg132_668040e;
extern Seg132_668040e D_00668040_e[] __asm__("D_00668040");
s32 func_0013DAA8(s32);
s32* func_00245F58(a0)
    u8* a0;
{
    s32 i = func_0013DAA8(*(u16*)(*(u8**)(a0 + 0x130) + 0x4C)) != 1;
    return D_00668040_e[i].v;
}

typedef struct { s32 used; f32 f; s32 a; s32 b; } A2Slot10;

void func_00245F90(s32 arg0, s32 arg1) {
    A2Slot10 *s = (A2Slot10 *)func_00245F58(arg1);
    if (s->used == 0) {
        s->a = arg0; //P
        s->b = arg1; //P
        s->used = 1; //P
        s->f = 1.0f; //P
    }
}

extern s32 *func_00245F58();

void func_00245FF0(void) {
    s32 *ptr = func_00245F58();
    if (*ptr != 0) {
        *ptr = 4;
    }
}

typedef struct { s32 unk0; s32 pad[3]; s32 unk10; } Seg132_668040;
extern Seg132_668040 D_00668040;
void func_00246020(void) {
    D_00668040.unk10 = 0;
    D_00668040.unk0 = 0;
}

extern s32 D_00667F50;
extern Obj5300 D_00667F60_o __asm__("D_00667F60");

void func_00246038(s32 a0, s32 a1, s32 x, s32 y, f32 f) {
    s32 i;

    func_002475E8(a0, (u8 *)&D_00667F60_o, a1);
    for (i = 0; i < 4; i++) {
        s32 *e = &D_00667F60_o.n[i].b;
        e[-1] += x * 16;
        e[0] += y * 16;
    }
    for (i = 0; i < 4; i++) {
        D_00667F60_o.m[i].d = D_00667F60_o.m[i].d * f;
    }
    D_00667F50 = func_002388B8((u8 *)&D_00667F60_o, 1, D_00667F50);
}

extern u8 D_00668060[];
extern u8 D_00431D20[];
extern sceVu0FMATRIX D_002DEC20;
void func_00237A48(s32 *, sceVu0FMATRIX, f32 *, s32);
s32 func_00249580(f32 *);
void func_00249558(void *, void *);

void func_00246120(u8 *a0, s32 a1, f32 f) {
    sceVu0FVECTOR v;
    s32 w[4];
    s32 o = 0;

    if (*(s32 *)(a0 + 8) == 0) {
        o = (s32)D_00668060;
    }
    if (a1 != 0) {
        func_002479A0(o);
    }
    func_00247AA0(o);
    func_001315C0(*(s32 *)(a0 + 0xC), 0x8004, v, 0.0f);
    if (func_00249580(v) == 0) {
        func_00237A48(w, D_002DEC20, v, 1);
        func_00249558(w, w);
        w[1] -= 0x36;
        func_00246038(o, (s32)D_00431D20, w[0], w[1], f);
    }
}

extern u64 D_00667DF0[];
extern u_long128 *D_00667F50_p __asm__("D_00667F50");
extern u_long128 *D_00667F54;
s32 func_0013C2A8(s32);

void func_002461F8(u8 *a0, s32 a1, f32 f) {
    s32 r;
    s32 n;

    func_002370C8(D_00667DF0);
    D_00667DF0[0x1C] = 5;
    D_00667DF0[0xC] = 0x30003;
    func_00237018(D_00667DF0, 0x16, 1);
    D_00667F54 = (u_long128 *)&D_00351E10;
    D_00667F50_p = (u_long128 *)&D_00351E10 + 1;
    func_00246120(a0, a1, f);
    r = func_0013C2A8(*(u16 *)(*(u8 **)(*(u8 **)(a0 + 0xC) + 0x130) + 0x4C));
    if (r == 1) {
        n = 1;
    } else if (r == 2) {
        n = 2;
    }
    if (func_00242BF0(n) != 0) {
        func_00237018(D_00667F54, D_00667F50_p - D_00667F54, 1);
    }
}

INCLUDE_ASM("asm/nonmatchings/unsplit/file136618", func_00246320);

typedef struct { u64 d[0x18]; } A3Ent6438;
extern A3Ent6438 D_00668060_e __asm__("D_00668060");
extern u8 D_0045D280[];
extern s32 D_0045D6D0[];
void UiFile_Relocate(void *);
void UiFile_CopyParts(s32 *, A3Ent6438 *, void *);
s32 TaskSystem_FindTask(s32 (*)(void));
s32 func_00246320(void);
void func_00246438(void) {
    A3Ent6438 e[3];

    memset(&D_00668040, 0, 0x20);
    UiFile_Relocate(D_0045D280);
    UiFile_CopyParts(D_0045D6D0, e, D_0045D280);
    D_00668060_e = e[2];
    if (TaskSystem_FindTask(func_00246320) == 0) {
        func_0011ED30(0x28489, func_00246320);
    }
}

void func_002464F8(s32 *out) {
    s32 i;
    for (i = 0; i < 2; i++) {
        switch (D_00668040_e[i].v[0]) {
        case 0:
            out[i] = 0;
            break;
        case 4:
            out[i] = 0;
            break;
        case 5:
            out[i] = 0;
            break;
        case 6:
            out[i] = 0;
            break;
        default:
            out[i] = 1;
            break;
        }
    }
}

extern s32 D_00668280;
extern Obj5300 D_00668290_o __asm__("D_00668290");

void func_00246570(s32 a0, s32 a1, s32 x, s32 y, f32 f) {
    s32 i;

    func_002475E8(a0, (u8 *)&D_00668290_o, a1);
    for (i = 0; i < 4; i++) {
        s32 *e = &D_00668290_o.n[i].b;
        e[-1] += x * 16;
        e[0] += y * 16;
    }
    for (i = 0; i < 4; i++) {
        D_00668290_o.m[i].d = D_00668290_o.m[i].d * f;
    }
    D_00668280 = func_002388B8((u8 *)&D_00668290_o, 1, D_00668280);
}

INCLUDE_ASM("asm/nonmatchings/unsplit/file136618", func_00246658);

s32 func_002466E8(u32 arg0) {
    s32 temp_3;
    temp_3 = (s32) ((arg0 >> 0x1F) + arg0) >> 1;
    return (temp_3 < 0x97) ? temp_3 : 0x96;
}

typedef struct { u64 d[0x18]; } Seg132Blk;
void func_00246708(Seg132Blk* a0, Seg132Blk* a1, s32 a2) {
    *a0 = *a1;
    *(s32*)((u8*)a0 + 8) = a2;
}

INCLUDE_ASM("asm/nonmatchings/unsplit/file136618", func_00246750);

extern void* D_00668370;

void func_00246A60(void) {
    D_00668370 = NULL;
}

typedef struct { s32 unk0; s32 pad4[2]; s32 unkC; s32 unk10; u8 pad14[0xA8C]; s32 unkAA0; s32 unkAA4; s32 unkAA8; } Seg132_668370;
extern Seg132_668370 D_00668370_s __asm__("D_00668370");
void func_00246A70(s32 a0, s32 a1, s32 a2, s32 a3) {
    D_00668370_s.unkC = a2;
    D_00668370_s.unk10 = a3;
    D_00668370_s.unkAA4 = a0;
    D_00668370_s.unkAA8 = a1;
    D_00668370_s.unkAA0 = 1;
    if (D_00668370_s.unk0 == 0) {
        D_00668370_s.unk0 = 1;
    }
}

INCLUDE_ASM("asm/nonmatchings/unsplit/file136618", func_00246AA8);

extern u8 D_00668370_b[] __asm__("D_00668370");
extern u8 D_0045D6E0[];
extern u8 D_0045E190[];
extern u8 D_0045E198[];
extern u8 D_0045E1A0[];
extern u8 D_0045E1A8[];
extern u8 D_0045E1B8[];
extern u8 D_0045E1C0[];
extern u8 D_0045E1C8[];
extern u8 D_0045E1E0[];
s32 func_00246AA8();

void func_00246BC8(void) {
    memset(D_00668370_b, 0, 0xAB0);
    func_00247668(D_0045D6E0);
    func_00247AE0(D_0045E190, D_00668370_b + 0x20, D_0045D6E0);
    func_00247AE0(D_0045E198, D_00668370_b + 0xE0, D_0045D6E0);
    func_00247AE0(D_0045E1A0, D_00668370_b + 0x1A0, D_0045D6E0);
    func_00247AE0(D_0045E1A8, D_00668370_b + 0x260, D_0045D6E0);
    func_00247AE0(D_0045E1B8, D_00668370_b + 0x4A0, D_0045D6E0);
    func_00247AE0(D_0045E1C0, D_00668370_b + 0x560, D_0045D6E0);
    func_00247AE0(D_0045E1C8, D_00668370_b + 0x620, D_0045D6E0);
    func_00247AE0(D_0045E1E0, D_00668370_b + 0x9E0, D_0045D6E0);
    if (func_0011ED60(func_00246AA8) == 0) {
        func_0011ED30(0x28489, func_00246AA8);
    }
}

s32 func_00246CF0(s32 n, s32 *d) {
    s32 i;
    s32 r = 5;

    d[0] = n / 10000;
    d[1] = n % 10000 / 1000;
    d[2] = n % 1000 / 100;
    d[3] = n % 100 / 10;
    d[4] = n % 10;
    for (i = 0; i < 4; i++) {
        if (d[i] != 0) {
            break;
        }
        r--;
    }
    return r;
}

extern s32 D_00668F80;
extern Obj5300 D_00668F90_o __asm__("D_00668F90");

void func_00246DC0(s32 a0, s32 a1, s32 x, s32 y, f32 f) {
    s32 i;

    func_002475E8(a0, (u8 *)&D_00668F90_o, a1);
    for (i = 0; i < 4; i++) {
        s32 *e = &D_00668F90_o.n[i].b;
        e[-1] += x * 16;
        e[0] += y * 16;
    }
    for (i = 0; i < 4; i++) {
        D_00668F90_o.m[i].d = D_00668F90_o.m[i].d * f;
    }
    D_00668F80 = func_002388B8((u8 *)&D_00668F90_o, 1, D_00668F80);
}

void func_00246EA8(s32 arg0, s32 arg1) {
    if (arg0 != 0) {
        func_002479A0(arg1);
    }
    func_00247AA0(arg1);
}

INCLUDE_ASM("asm/nonmatchings/unsplit/file136618", func_00246ED8);

typedef struct { u8 b[0x930]; } Ent247190;
s32 UiPart_GetColorAnimState(u8 *);
void func_00246ED8(s32, Ent247190 *);
void func_002470D0(Ent247190 *a0) {
    s32 *p = (s32 *)a0;
    s32 f = 0;

    switch (p[0]) {
    case 0:
        return;
    case 1:
        p[0] = 2;
        f = 1;
        break;
    case 2:
        if (UiPart_GetColorAnimState(a0->b + 0x30) & 4) {
            p[0]++;
        }
        break;
    case 3:
        p[0] = 0;
        break;
    }
    p[1]++;
    func_00246ED8(f, a0);
}

extern Ent247190 D_0045FAC0_u[] __asm__("D_0045FAC0");
extern u64 D_00668E20[];
extern void func_002470D0(Ent247190 *);

s32 func_00247190(void) {
    s32 i;

    func_002370C8(D_00668E20);
    D_00668E20[0x1C] = 5;
    D_00668E20[0xC] = 0x30003;
    D_00668E20[0xE] = 0x8000000048ULL;
    func_00237018(D_00668E20, 0x16, 1);
    for (i = 0; i < 10; i++) {
        func_002470D0(&D_0045FAC0_u[i]);
    }
    return 0;
}

void func_00247228(void *arg0, s32 arg1, f32 *arg2) {
    s32 *p = arg0;
    p[0x20 / 4] = arg1;
    p[0x0 / 4] = 1;
    p[0x4 / 4] = 0;
    sceVu0CopyVector((f32 *)((char *)arg0 + 0x10), arg2);
}

extern u8 D_0045E1F0[];
extern u8 D_0045FA80[];
extern u8 D_0045FA88[];
extern u8 D_0045FA90[];
extern u8 D_0045FAC0[];
s32 func_00247190();

void fm_func_00247258(void) {
    s32 i;
    u8 *p;
    func_00247668(D_0045E1F0);
    p = D_0045FAC0;
    for (i = 0; i < 10; i++) {
        func_00247AE0(D_0045FA80, p + 0x30, D_0045E1F0);
        func_00247AE0(D_0045FA88, p + 0xF0, D_0045E1F0);
        func_00247AE0(D_0045FA90, p + 0x1B0, D_0045E1F0);
        p += 0x930;
    }
    if (func_0011ED60(func_00247190) == 0) {
        func_0011ED30(0x28489, func_00247190);
    }
}

extern u8 D_0045FAC0[];

// func_00247350 (src/unsplit/seg_132D60.c)
void func_00247350(void) {
    u8* var_2;
    s32 var_3;
    volatile u8* tmp = D_0045FAC0;
    var_3 = 9;
    var_2 = (u8*)tmp + 0x52B0;
    do {
        var_3--;
        *(void**)var_2 = NULL;
        var_2 -= 0x930;
    } while (var_3 >= 0);
}

INCLUDE_ASM("asm/nonmatchings/unsplit/file136618", func_00247388);

extern void *func_00247388(void);
extern void *func_001315C0(s32, s32, f32 *, f32);
extern void func_00247228(void *arg0, s32 arg1, f32 *arg2);

void func_00247408(s32 arg0, s32 arg1) {
    void *temp;
    f32 tempf;
    temp = func_00247388();
    func_001315C0(arg0, 0x8004, &tempf, 0.0f);
    func_00247228(temp, arg1, &tempf);
}

extern void *func_00247388(void);
extern void func_00247228(void *arg0, s32 arg1, f32 *arg2);

void func_00247468(f32 *arg0, s32 arg1) {
    void *ret = func_00247388();
    func_00247228(ret, arg1, arg0);
}

extern u8 D_0045FAC0_e[] __asm__("D_0045FAC0");
s32 func_002474A8(void) {
    s32 p = (s32)D_0045FAC0_e;

    do {
        if (*(s32*)p != 0) {
            return 1;
        }
        p += 0x930;
    } while (p < (s32)D_0045FAC0_e + 0x5BE0);
    return 0;
}

extern s32 D_006691D0;
extern Obj5300 D_006691E0_o __asm__("D_006691E0");

void func_002474E8(s32 a0, u8 *a1, s32 x, s32 y, f32 f) {
    s32 i;

    func_002475E8(a0, (u8 *)&D_006691E0_o, (s32)a1);
    for (i = 0; i < 4; i++) {
        s32 *e = &D_006691E0_o.n[i].b;
        e[-1] += x * 16;
        e[0] += y * 16;
    }
    for (i = 0; i < 4; i++) {
        D_006691E0_o.m[i].d = D_006691E0_o.m[i].d * f;
    }
    D_006691D0 = func_002388B8((u8 *)&D_006691E0_o, 1, D_006691D0);
}

extern s32 D_006691D0;
s32 func_001F12C0(s32, s32, s32, s32, s32, s32, s32);
void func_002475D0(s32 x, s32 y, u8 *c, f32 f, char *s, s32 font) {
    u8 col[4];
    col[0] = *c++;
    col[1] = *c++;
    col[2] = *c;
    col[3] = f * 128.0f;
    D_006691D0 = func_001F12C0(D_006691D0, 1, *(s32 *)col, x, y, (s32)s, font);
}

void func_00247678(s32 arg0, s32 *arg1, s32 *arg2) {
    *arg1 = arg0 / 10;
    *arg2 = arg0 % 10;
}

extern s32 D_00669358_w[] __asm__("D_00669358");
extern u8 D_006692F0[];

void func_002476A0(void *arg0) {
    s32 d0;
    s32 d1;
    s32 x;
    s32 y;

    x = *(s32 *)((u8 *)arg0 + 0x24);
    x += 0x49;
    y = *(s32 *)((u8 *)arg0 + 0x28);
    if (*(s32 *)((u8 *)arg0 + 0x2C) != 0) {
        func_00247678(*(s32 *)((u8 *)arg0 + 0x40), &d0, &d1);
        func_002474E8(D_00669358_w[d0], D_006692F0, x, y, 1.0f);
        x += 0xF;
        func_002474E8(D_00669358_w[d1], D_006692F0, x, y, 1.0f);
        x += 0x10;
        func_002474E8(D_00669358_w[10], D_006692F0, x, y, 1.0f);
        x += 0xD;
    }
    func_00247678(*(s32 *)((u8 *)arg0 + 0x3C), &d0, &d1);
    func_002474E8(D_00669358_w[d0], D_006692F0, x, y, 1.0f);
    x += 0xF;
    func_002474E8(D_00669358_w[d1], D_006692F0, x, y, 1.0f);
    x += 0x11;
    func_002474E8(D_00669358_w[11], D_006692F0, x, y, 1.0f);
    x += 9;
    func_00247678(*(s32 *)((u8 *)arg0 + 0x38), &d0, &d1);
    func_002474E8(D_00669358_w[d0], D_006692F0, x, y, 1.0f);
    x += 0xF;
    func_002474E8(D_00669358_w[d1], D_006692F0, x, y, 1.0f);
    x += 0x11;
    func_002474E8(D_00669358_w[11], D_006692F0, x, y, 1.0f);
    x += 5;
    func_002474E8(D_00669358_w[11], D_006692F0, x, y, 1.0f);
    x += 4;
    func_00247678(*(s32 *)((u8 *)arg0 + 0x34), &d0, &d1);
    func_002474E8(D_00669358_w[d0], D_006692F0, x, y, 1.0f);
    x += 0xF;
    func_002474E8(D_00669358_w[d1], D_006692F0, x, y, 1.0f);
}
