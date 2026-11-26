// Code after xstuck (JP: the asm piece from 0x1DF198 to xquack; here 0x1DDF98-0x1EC7C0). Split out of seg_0DDC78.
#include "common.h"
extern u8 D_0062FB00[];
extern u8 D_0062FF00[];
extern u8 D_0062FA00;

void func_0011D588(void);
typedef struct {
    u8 pad[0x174];
    s32 unk_174[1];
} A2Script;
extern u8 D_00624960[];
u8 *func_0011EEB8(void *, s32, void *);
s32 func_001DE7C0();
typedef struct {
    u8 pad[0x10];
    u8 *unk_10;
    u8 pad14[0x14];
    s32 *unk_28;
} A2Obj1760;
A2Obj1760 *func_001760B0(s32);
A2Obj1760 *func_001760D0(s32);
A2Obj1760 *func_001760F0(s32);

extern u32 D_0038CD00[];

s32 func_001DDF98(void) {
    return ((s32)(*(u64 *)D_0038CD00 >> 44) & 1) ? 4 : 2;
}

INCLUDE_ASM("asm/nonmatchings/unsplit/file0DDF98", func_001DDFB8);

INCLUDE_ASM("asm/nonmatchings/unsplit/file0DDF98", func_001DE030);

INCLUDE_ASM("asm/nonmatchings/unsplit/file0DDF98", fm_func_001DE0B0);

INCLUDE_ASM("asm/nonmatchings/unsplit/file0DDF98", func_001DE130);

INCLUDE_ASM("asm/nonmatchings/unsplit/file0DDF98", func_001DE1E0);

s32 func_001DE290(A2Script *p) {
    A2Obj1760 *q = func_001760D0(p->unk_174[p->unk_174[3] + 1]);
    s32 n;

    if (q != NULL) {
        f32 *v = *(f32 **)q;
        f32 x, y, z;
        n = p->unk_174[3];
        x = (f32)p->unk_174[n + 2];
        y = (f32)p->unk_174[n + 3];
        z = (f32)p->unk_174[n + 4];
        v[0] = x;
        v[1] = y;
        v[2] = z;
    } else {
        n = p->unk_174[3];
    }
    p->unk_174[3] = n - 4;
    return 2;
}

s32 func_001DE328(A2Script *p) {
    A2Obj1760 *a = func_001760D0(p->unk_174[p->unk_174[3] + 1]);

    if (a != NULL) {
        s32 *r = *(s32 **)((u8 *)a + 4);
        r[0] = (f32)p->unk_174[p->unk_174[3] + 2] / 360.0f * 65535.0f;
        r[1] = (f32)p->unk_174[p->unk_174[3] + 3] / 360.0f * 65535.0f;
        r[2] = (f32)p->unk_174[p->unk_174[3] + 4] / 360.0f * 65535.0f;
    }
    p->unk_174[3] -= 4;
    return 2;
}

s32 func_001DE420(A2Script *p) {
    A2Obj1760 *q = func_001760D0(p->unk_174[p->unk_174[3] + 1]);
    s32 n;

    if (q != NULL) {
        f32 *v = *(f32 **)((u8 *)q + 8);
        f32 x, y, z;
        n = p->unk_174[3];
        x = (f32)p->unk_174[n + 2] / 100.0f;
        y = (f32)p->unk_174[n + 3] / 100.0f;
        z = (f32)p->unk_174[n + 4] / 100.0f;
        v[0] = x;
        v[1] = y;
        v[2] = z;
    } else {
        n = p->unk_174[3];
    }
    p->unk_174[3] = n - 4;
    return 2;
}

s32 func_001DE4E8(A2Script *p) {
    A2Obj1760 *q = func_001760D0(p->unk_174[p->unk_174[3] + 3]);

    if (q != NULL) {
        *q->unk_28 = p->unk_174[p->unk_174[3] + 4];
    }
    p->unk_174[3] -= 2;
    return 2;
}


s32 func_001DE558(A2Script *p) {
    A2Obj1760 *q = func_001760D0(p->unk_174[p->unk_174[3] + 4]);

    if (q != NULL) {
        *q->unk_10 = 1;
    }
    p->unk_174[3]--;
    return 2;
}

INCLUDE_ASM("asm/nonmatchings/unsplit/file0DDF98", func_001DE5B0);

s32 *func_001E98D0(s32, s32);
void func_001315C0(s32, s32, f32 *, f32);
void sceVu0CopyVector(f32 *, f32 *);

s32 func_001DE6A8(A2Script *p) {
    A2Obj1760 *a = func_001760D0(p->unk_174[p->unk_174[3] + 1]);
    s32 *b = func_001E98D0((s32)(*(u64 *)((u8 *)p + 0x328) >> 5) & 1, p->unk_174[p->unk_174[3] + 2]);
    f32 v[4] __attribute__((aligned(16)));

    if (a != NULL && b != NULL) {
        func_001315C0(b[1], p->unk_174[p->unk_174[3] + 3], v, (f32)p->unk_174[p->unk_174[3] + 4] * 0.5f);
        sceVu0CopyVector(*(f32 **)a, v);
    }
    p->unk_174[3] -= 4;
    return 2;
}

void sceVu0CopyVector(f32 *, f32 *);

s32 func_001DE778(A2Script *p) {
    A2Obj1760 *a = func_001760F0(p->unk_174[p->unk_174[3] + 1]);
    s32 *b = func_001E98D0((s32)(*(u64 *)((u8 *)p + 0x328) >> 5) & 1, p->unk_174[p->unk_174[3] + 2]);
    f32 v[4] __attribute__((aligned(16)));

    if (a != NULL && b != NULL) {
        func_001315C0(b[1], p->unk_174[p->unk_174[3] + 3], v, (f32)p->unk_174[p->unk_174[3] + 4] * 0.5f);
        sceVu0CopyVector(*(f32 **)a, v);
    }
    p->unk_174[3] -= 4;
    return 2;
}

u8 *func_0011EEB8_m(void *, s32, void *) __asm__("func_0011EEB8") __attribute__((malloc));
s32 *func_001E98D0(s32, s32);
s32 func_001DE5F0();

s32 func_001DE848(A2Script *p) {
    A2Obj1760 *a = func_001760F0(p->unk_174[p->unk_174[3] + 2]);
    s32 *b = func_001E98D0((s32)(*(u64 *)((u8 *)p + 0x328) >> 5) & 1, p->unk_174[p->unk_174[3] + 3]);

    if (a != NULL && b != NULL) {
        u8 *t = func_0011EEB8_m(D_00624960, 1, func_001DE5F0);
        *(A2Obj1760 **)(t + 0x10) = a;
        *(s32 **)(t + 0x14) = b;
        *(s32 *)(t + 0x18) = p->unk_174[*(volatile s32 *)&p->unk_174[3] + 4];
    }
    p->unk_174[3] -= 3;
    return 2;
}

INCLUDE_ASM("asm/nonmatchings/unsplit/file0DDF98", func_001DE910);

INCLUDE_ASM("asm/nonmatchings/unsplit/file0DDF98", func_001DE9E0);

INCLUDE_ASM("asm/nonmatchings/unsplit/file0DDF98", func_001DEAF8);

INCLUDE_ASM("asm/nonmatchings/unsplit/file0DDF98", func_001DEC10);

INCLUDE_ASM("asm/nonmatchings/unsplit/file0DDF98", func_001DED08);

extern f32 D_002DECF0[];
extern f32 D_002DECE0[];
f32 func_001E9E58(f32 *, f32 *);
void func_001E9D00(f32 *, f32 *, f32 *, f32);
void func_001E9DC8(f32 *, f32 *, f32 *);
void sceVu0SubVector(f32 *, f32 *, f32 *);
void sceVu0AddVector(f32 *, f32 *, f32 *);

s32 func_001DEDD8(u8 *a0) {
    f32 v[4] __attribute__((aligned(16)));
    f32 r[4] __attribute__((aligned(16)));
    f32 w[4] __attribute__((aligned(16)));
    f32 len;
    f32 z;

    if (*(s32 *)(*(u8 **)(a0 + 0x10) + 0x14) & 2) {
        return 4;
    }
    len = func_001E9E58(D_002DECF0, D_002DECE0);
    sceVu0SubVector(v, D_002DECF0, D_002DECE0);
    v[0] = v[0] / len * *(f32 *)(a0 + 0x1C);
    v[1] = v[1] / len * *(f32 *)(a0 + 0x1C);
    v[2] = v[2] / len * *(f32 *)(a0 + 0x1C);
    z = 0.0f;
    sceVu0AddVector(v, D_002DECE0, v);
    func_001E9D00(r, D_002DECF0, D_002DECE0, z);
    w[0] = *(f32 *)(a0 + 0x20);
    w[1] = *(f32 *)(a0 + 0x24);
    w[2] = z;
    w[3] = 1.0f;
    func_001E9DC8(v, r, w);
    sceVu0CopyVector(**(f32 ***)(a0 + 0x10), v);
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/unsplit/file0DDF98", func_001DEF20);


s32 func_001DF130(void) {
    u8 *p = func_0011EEB8(D_00624960, 0, func_001DE7C0);

    *(s32 *)(p + 0x28) = 0;
    *(s32 *)(p + 0x2C) = 1;
    return 2;
}

s32 func_001DF170(A2Script *s) {
    u8 *p = func_0011EEB8(D_00624960, 0, func_001DE7C0);

    *(s32 *)(p + 0x2C) = 2;
    *(s32 *)(p + 0x28) = s->unk_174[s->unk_174[3] + 4];
    s->unk_174[3]--;
    return 2;
}

INCLUDE_ASM("asm/nonmatchings/unsplit/file0DDF98", func_001DF1D8);

s32 func_001DF268(void) {
    u8 *p = func_0011EEB8(D_00624960, 0, func_001DE7C0);

    *(s32 *)(p + 0x28) = 0;
    *(s32 *)(p + 0x2C) = 4;
    return 2;
}

s32 func_001DF2A8(A2Script *s) {
    u8 *p = func_0011EEB8(D_00624960, 0, func_001DE7C0);

    *(s32 *)(p + 0x2C) = 5;
    *(s32 *)(p + 0x28) = s->unk_174[s->unk_174[3] + 4];
    s->unk_174[3]--;
    return 2;
}

s32 func_001DF310(A2Script *p) {
    A2Obj1760 *q = func_001760F0(p->unk_174[p->unk_174[3] + 1]);
    s32 n;

    if (q != NULL) {
        f32 *v = *(f32 **)q;
        f32 x, y, z;
        n = p->unk_174[3];
        x = (f32)p->unk_174[n + 2];
        y = (f32)p->unk_174[n + 3];
        z = (f32)p->unk_174[n + 4];
        v[0] = x;
        v[1] = y;
        v[2] = z;
    } else {
        n = p->unk_174[3];
    }
    p->unk_174[3] = n - 4;
    return 2;
}

s32 func_001DF3A8(A2Script *p) {
    A2Obj1760 *a = func_001760F0(p->unk_174[p->unk_174[3] + 1]);

    if (a != NULL) {
        s32 *r = *(s32 **)((u8 *)a + 4);
        r[0] = (f32)p->unk_174[p->unk_174[3] + 2] / 360.0f * 65535.0f;
        r[1] = (f32)p->unk_174[p->unk_174[3] + 3] / 360.0f * 65535.0f;
        r[2] = (f32)p->unk_174[p->unk_174[3] + 4] / 360.0f * 65535.0f;
    }
    p->unk_174[3] -= 4;
    return 2;
}

s32 func_001DF4A0(A2Script *p) {
    A2Obj1760 *q = func_001760F0(p->unk_174[p->unk_174[3] + 1]);
    s32 n;

    if (q != NULL) {
        f32 *v = *(f32 **)((u8 *)q + 8);
        f32 x, y, z;
        n = p->unk_174[3];
        x = (f32)p->unk_174[n + 2] / 100.0f;
        y = (f32)p->unk_174[n + 3] / 100.0f;
        z = (f32)p->unk_174[n + 4] / 100.0f;
        v[0] = x;
        v[1] = y;
        v[2] = z;
    } else {
        n = p->unk_174[3];
    }
    p->unk_174[3] = n - 4;
    return 2;
}

s32 func_001DF568(A2Script *p) {
    A2Obj1760 *q = func_001760F0(p->unk_174[p->unk_174[3] + 3]);

    if (q != NULL) {
        *q->unk_28 = p->unk_174[p->unk_174[3] + 4];
    }
    p->unk_174[3] -= 2;
    return 2;
}

A2Obj1760 *func_001760F0(s32);

s32 func_001DF5D8(A2Script *p) {
    A2Obj1760 *q = func_001760F0(p->unk_174[p->unk_174[3] + 4]);

    if (q != NULL) {
        *q->unk_10 = 1;
    }
    p->unk_174[3]--;
    return 2;
}

s32 func_001DF630(A2Script *s) {
    u8 *p = func_0011EEB8(D_00624960, 0, func_001DE7C0);

    *(s32 *)(p + 0x2C) = 6;
    *(s32 *)(p + 0x28) = s->unk_174[s->unk_174[3] + 4];
    s->unk_174[3]--;
    return 2;
}

typedef struct {
    f32 *unk_00;
    u8 pad[0x10];
    s32 unk_14;
} A2DF698a;
typedef struct {
    s32 unk_00;
    s32 unk_04;
} A2DF698b;
typedef struct {
    u8 pad[0x10];
    A2DF698a *unk_10;
    A2DF698b *unk_14;
    s32 unk_18;
    f32 unk_1C;
} A2DF698;
void func_001315C0(s32, s32, f32 *, f32);

s32 func_001DF698(A2DF698 *o) {
    f32 v[4];
    f32 *d;

    if (o->unk_10->unk_14 & 2) {
        return 4;
    }
    func_001315C0(o->unk_14->unk_04, o->unk_18, v, o->unk_1C);
    d = o->unk_10->unk_00;
    d[0] = v[0];
    d[1] = v[1];
    d[2] = v[2];
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/unsplit/file0DDF98", func_001DF708);

INCLUDE_ASM("asm/nonmatchings/unsplit/file0DDF98", func_001DF7E0);

INCLUDE_ASM("asm/nonmatchings/unsplit/file0DDF98", func_001DF890);

extern f32 *D_0062A430;
s32 func_001DF940(A2Script *s) {
    s32 n = s->unk_174[3];
    f32 *v = D_0062A430;
    f32 x = s->unk_174[n + 2];
    f32 y = s->unk_174[n + 3];
    f32 z = s->unk_174[n + 4];
    s->unk_174[3] = n - 4;
    v[2] = z / 100.0f;
    v[1] = y / 100.0f;
    v[0] = x / 100.0f;
    return 2;
}

INCLUDE_ASM("asm/nonmatchings/unsplit/file0DDF98", func_001DF9C0);

s32 func_001DFA38(A2Script *s) {
    u8 *p = func_0011EEB8(D_00624960, 0, func_001DE7C0);

    *(s32 *)(p + 0x2C) = 9;
    *(s32 *)(p + 0x28) = s->unk_174[s->unk_174[3] + 4];
    s->unk_174[3]--;
    return 2;
}

extern s32 D_0029B410;
extern s32 D_0029B414;

s32 func_001DFAA0(A2Script *s) {
    if (D_0029B410 != 0 && D_0029B414 != 0) {
        u8 *p = func_0011EEB8(D_00624960, 0, func_001DE7C0);

        *(s32 *)(p + 0x2C) = 0xB;
        *(s32 *)(p + 0x28) = s->unk_174[s->unk_174[3] + 4];
    }
    s->unk_174[3]--;
    return 2;
}

s32 func_001DFB20(A2Script *p) {
    A2Obj1760 *q = func_001760B0(p->unk_174[p->unk_174[3] + 1]);
    s32 n;

    if (q != NULL) {
        f32 *v = *(f32 **)q;
        f32 x, y, z;
        n = p->unk_174[3];
        x = (f32)p->unk_174[n + 2];
        y = (f32)p->unk_174[n + 3];
        z = (f32)p->unk_174[n + 4];
        v[0] = x;
        v[1] = y;
        v[2] = z;
    } else {
        n = p->unk_174[3];
    }
    p->unk_174[3] = n - 4;
    return 2;
}

s32 func_001DFBB8(A2Script *p) {
    A2Obj1760 *a = func_001760B0(p->unk_174[p->unk_174[3] + 1]);

    if (a != NULL) {
        s32 *r = *(s32 **)((u8 *)a + 4);
        r[0] = (f32)p->unk_174[p->unk_174[3] + 2] / 360.0f * 65535.0f;
        r[1] = (f32)p->unk_174[p->unk_174[3] + 3] / 360.0f * 65535.0f;
        r[2] = (f32)p->unk_174[p->unk_174[3] + 4] / 360.0f * 65535.0f;
    }
    p->unk_174[3] -= 4;
    return 2;
}

s32 func_001DFCB0(A2Script *p) {
    A2Obj1760 *q = func_001760B0(p->unk_174[p->unk_174[3] + 1]);
    s32 n;

    if (q != NULL) {
        f32 *v = *(f32 **)((u8 *)q + 8);
        f32 x, y, z;
        n = p->unk_174[3];
        x = (f32)p->unk_174[n + 2] / 100.0f;
        y = (f32)p->unk_174[n + 3] / 100.0f;
        z = (f32)p->unk_174[n + 4] / 100.0f;
        v[0] = x;
        v[1] = y;
        v[2] = z;
    } else {
        n = p->unk_174[3];
    }
    p->unk_174[3] = n - 4;
    return 2;
}

s32 func_001DFD78(A2Script *s) {
    u8 *p = func_0011EEB8(D_00624960, 0, func_001DE7C0);

    *(s32 *)(p + 0x2C) = 0xC;
    *(s32 *)(p + 0x28) = s->unk_174[s->unk_174[3] + 4];
    s->unk_174[3]--;
    return 2;
}

s32 func_001DFDE0(A2Script *p) {
    A2Obj1760 *q = func_001760B0(p->unk_174[p->unk_174[3] + 3]);

    if (q != NULL) {
        *q->unk_28 = p->unk_174[p->unk_174[3] + 4];
    }
    p->unk_174[3] -= 2;
    return 2;
}

A2Obj1760 *func_001760B0(s32);

s32 func_001DFE50(A2Script *p) {
    A2Obj1760 *q = func_001760B0(p->unk_174[p->unk_174[3] + 4]);

    if (q != NULL) {
        *q->unk_10 = 1;
    }
    p->unk_174[3]--;
    return 2;
}

INCLUDE_ASM("asm/nonmatchings/unsplit/file0DDF98", func_001DFEA8);

s32 func_001DFFA0(A2Script *p) {
    if (*(s32 *)((u8 *)p + 4) != 0) {
        u8 *q = func_0011EEB8(D_00624960, 0, func_001DE7C0);

        *(s32 *)(q + 0x2C) = 0xD;
        *(A2Script **)(q + 0x14) = p;
        *(s32 *)(q + 0x28) = p->unk_174[p->unk_174[3] + 4];
    }
    p->unk_174[3]--;
    return 2;
}

s32 func_001E0010(A2Script *s) {
    u8 *p = func_0011EEB8(D_00624960, 0, func_001DE7C0);

    *(s32 *)(p + 0x2C) = 0xE;
    *(s32 *)(p + 0x28) = s->unk_174[s->unk_174[3] + 4];
    s->unk_174[3]--;
    return 2;
}

typedef struct {
    u8 pad[0x3070];
    u64 unk_3070;
    u64 unk_3078;
} A2Big3854E0;
extern A2Big3854E0 D_003854E0;

s32 func_001E0078(A2Script *s) {
    u8 *p = func_0011EEB8(D_00624960, 0, func_001DE7C0);
    s32 id;
    f32 x, y, z, n;

    *(s32 *)(p + 0x2C) = 0xF;
    id = s->unk_174[s->unk_174[3]];
    *(s32 *)(p + 0x28) = id;
    n = (f32)s->unk_174[s->unk_174[3] + 4];
    x = (f32)s->unk_174[s->unk_174[3] + 1];
    y = (f32)s->unk_174[s->unk_174[3] + 2];
    z = (f32)s->unk_174[s->unk_174[3] + 3];
    *(f32 *)(p + 0x30) = n + n;
    *(f32 *)(p + 0x40) = (x - 255.0f) / 255.0f / n;
    *(f32 *)(p + 0x44) = (y - 255.0f) / 255.0f / n;
    *(f32 *)(p + 0x48) = (z - 255.0f) / 255.0f / n;
    *(A2Obj1760 **)(p + 0x10) = func_001760F0(id);
    D_003854E0.unk_3078 |= 8;
    s->unk_174[3] -= 5;
    return 2;
}

extern s32 D_003DACA0;

void func_001E01B8(void) {
    s32 *p = &D_003DACA0;

    *p = func_00155ED8(0x3C, 4);
}


void func_001E01F0(void) {
    D_003854E0.unk_3070 &= ~((u64)1 << 52);
}

extern s32 D_00375BC0;
extern char D_00490820[];
extern char D_003DAC40[][6];
s32 fm_func_0011E340(s32);
s32 func_00155ED8(s32, s32);

s32 func_001E0220(A2Script *p) {
    char buf[0x200];
    s32 *q;

    if (!(D_00375BC0 & 1)) {
        if (fm_func_0011E340(0) == 0) {
            sprintf(buf, D_00490820, D_003DAC40[p->unk_174[p->unk_174[3] + 3]], p->unk_174[p->unk_174[3] + 4]);
            q = &D_003DACA0;
            *q = func_00155ED8(0x3C, 4);
            func_00120590(buf, *q, (s32 (*)(void))func_001E01F0, 0);
            D_003854E0.unk_3070 |= (u64)1 << 52;
        } else {
            return 4;
        }
    }
    p->unk_174[3] -= 2;
    return 2;
}

s32 func_001E0318(void) {
    return ((s32)(*(u64 *)D_0038CD00 >> 52) & 1) ? 4 : 2;
}

double ceil(double);
void func_0011E220(s32, s32, s32, s32);

s32 func_001E0338(A2Script *p) {
    s32 t = D_003DACA0;
    s32 a = p->unk_174[p->unk_174[3] + 2];
    f32 x = (f32)p->unk_174[p->unk_174[3] + 3] / 100.0f;
    f32 y = (f32)p->unk_174[p->unk_174[3] + 4] / 100.0f;
    s32 *tab = (s32 *)(*(s32 *)(t + 4) * 4 + t);
    s32 v = ((s32 *)t)[a + 2];
    s32 q = t + tab[a + 2];

    if (!(D_00375BC0 & 1)) {
        func_0011E220(q, v, (s32)ceil(x * 16383.0f), (s32)ceil(y * 16383.0f));
    }
    *(u64 *)((u8 *)p + 0x328) |= 4;
    *(f32 *)((u8 *)p + 0x2F4) = 4.0f;
    p->unk_174[3] -= 3;
    return 6;
}

void* func_001EE768(s32 arg0);
s32 func_001E0498(A2Script *p) {
    s32 v = p->unk_174[p->unk_174[3] + 4];
    if (v == -1) {
        func_001EE768(-1);
        p->unk_174[3]--;
        return 2;
    }
    {
        s32 t = D_003DACA0;
        s32 *tab = (s32 *)(*(s32 *)(t + 4) * 4 + t);
        func_001EE768(t + tab[v + 2]);
    }
    p->unk_174[3]--;
    return 2;
}

INCLUDE_ASM("asm/nonmatchings/unsplit/file0DDF98", func_001E0528);

void *sceDmaGetChan(int);
void FlushCache(int);
int sceGsSyncPath(int, u16);
int sceDmaSend(void *, void *);

void func_001E05A8(void *buf) {
    void *c = sceDmaGetChan(2);

    FlushCache(0);
    sceGsSyncPath(0, 0);
    sceDmaSend(c, buf);
    sceGsSyncPath(0, 0);
}

extern u8 D_0062F670[];
void func_F20000(void);

void func_001E0608(void) {
    sceGsSetDefLoadImage(&D_0062F670, 0xE00, 8, 1, 0, 0, 0x200, 0xC0);
    FlushCache(0);
    sceGsSyncPath(0, 0);
    sceGsExecLoadImage(&D_0062F670, &func_F20000);
    sceGsSetDefLoadImage(&D_0062F670, 0x1400, 8, 1, 0, 0, 0x200, 0xC0);
    FlushCache(0);
    sceGsSyncPath(0, 0);
    sceGsExecLoadImage(&D_0062F670, &func_F20000 + 0x48000);
}

void func_001E06C8(s32 a0) {
    u8 *p;
    sceGsSetDefLoadImage(&D_0062F670, 0xE00, 8, 1, 0, 0, 0x200, 0xC0);
    p = (u8 *)&func_F20000 + a0 * 0x600;
    FlushCache(0);
    sceGsSyncPath(0, 0);
    sceGsExecLoadImage(&D_0062F670, p);
    sceGsSetDefLoadImage(&D_0062F670, 0x1400, 8, 1, 0, 0, 0x200, 0xC0);
    FlushCache(0);
    sceGsSyncPath(0, 0);
    sceGsExecLoadImage(&D_0062F670, p + 0x48000);
}

extern u8 *D_003DABD0[];

void func_001E07A8(s32 n) {
    sceGsSetDefLoadImage(&D_0062F670, 0xE00, 8, 1, 0, 0, 0x200, 0xC0);
    FlushCache(0);
    sceGsSyncPath(0, 0);
    sceGsExecLoadImage(&D_0062F670, D_003DABD0[1] + n * 0x600);
    sceGsSetDefLoadImage(&D_0062F670, 0x1400, 8, 1, 0, 0, 0x200, 0xC0);
    FlushCache(0);
    sceGsSyncPath(0, 0);
    sceGsExecLoadImage(&D_0062F670, D_003DABD0[1] + n * 0x600 + 0x48000);
}

extern s32 D_003DAD38;
extern u8 D_003DAE30[];
void func_001E0608(void);
void func_001E05A8(void *);

s32 func_001E0898(void) {
    if (D_003DAD38 == 0) {
        return 4;
    }
    func_001E0608();
    func_001E05A8(D_003DAE30);
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/unsplit/file0DDF98", func_001E08D8);

INCLUDE_ASM("asm/nonmatchings/unsplit/file0DDF98", func_001E0AB0);

extern s32 D_0062F6D0;
void *func_0011ED30(s32, s32 (*func)(void));
s32 func_001E0AB0(void);

void func_001E0D68(s32 x) {
    D_0062F6D0 = x;
    func_0011ED30(0x2E630, func_001E0AB0);
}

INCLUDE_ASM("asm/nonmatchings/unsplit/file0DDF98", func_001E0D98);

extern s32 D_0062F6D0;
void *func_0011ED30(s32, s32 (*func)(void));
s32 func_001E0D98(void);

void func_001E1F78(s32 x) {
    D_0062F6D0 = x;
    func_0011ED30(0x2E630, func_001E0D98);
}

extern s32 D_003DAD38;

s32 func_001E10B8(void) {
    D_003DAD38 = 0;
    return 4;
}

extern s32 D_0062F6D0;
void *func_0011ED30(s32, s32 (*func)(void));
s32 func_001E10B8(void);

void func_001E22B0(s32 x) {
    D_0062F6D0 = x;
    func_0011ED30(0x2E630, func_001E10B8);
}

INCLUDE_ASM("asm/nonmatchings/unsplit/file0DDF98", func_001E10F8);

extern s32 D_0062F6D0;
void *func_0011ED30(s32, s32 (*func)(void));
s32 func_001E10F8(void);

void func_001E22F0(s32 x) {
    D_0062F6D0 = x;
    func_0011ED30(0x2E630, func_001E10F8);
}

extern s32 D_003DACB8;
extern s32 D_003DACBC;

void func_001E1418(s32 a, s32 b) {
    D_003DACB8 = a * 16;
    D_003DACBC = b * 16;
}

extern f32 D_003DACB0;
extern f32 D_003DACB4;

void func_001E1438(s32 a, s32 b) {
    D_003DACB0 = (f32)a / 100.0f;
    D_003DACB4 = (f32)b / 100.0f;
}

typedef unsigned int A2Qword __attribute__((mode(TI)));
void sceGsSetDefStoreImage(void *, int, int, int, int, int, int, int);
int sceGsExecStoreImage(void *, void *);
void func_F20000(void);

void func_001E1480(void) {
    A2Qword si[7];

    sceGsSetDefStoreImage(si, 0x1A00, 8, 1, 0, 0, 0x200, 0x180);
    FlushCache(0);
    sceGsSyncPath(0, 0);
    sceGsExecStoreImage(si, func_F20000);
}

void func_001E14E0(void) {
    sceGsSetDefLoadImage(&D_0062F670, 0xE00, 8, 1, 0, 0, 0x200, 0xC0);
    FlushCache(0);
    sceGsSyncPath(0, 0);
    sceGsExecLoadImage(&D_0062F670, &func_F20000);
    sceGsSetDefLoadImage(&D_0062F670, 0x1400, 8, 1, 0, 0, 0x200, 0xC0);
    FlushCache(0);
    sceGsSyncPath(0, 0);
    sceGsExecLoadImage(&D_0062F670, &func_F20000 + 0x48000);
}

extern s32 D_003DACC0[];
extern s32 D_003DACD0;
extern u64 D_003DB028;
extern u8 D_003DB050[];
void func_001E05A8(void *);

s32 func_001E15A0(void) {
    u8 *p;
    s32 x, y;

    D_003DACC0[3] += D_003DACD0;
    if (D_003DACC0[3] > 0x80) {
        D_003DACC0[3] = 0x80;
    } else if (D_003DACC0[3] < 0) {
        return 4;
    }
    D_003DB028 = (u64)D_003DACC0[0] | ((u64)D_003DACC0[1] << 8) | ((u64)D_003DACC0[2] << 16) | ((u64)D_003DACC0[3] << 24) | ((u64)1 << 32);
    func_001E1480();
    p = (u8 *)func_F20000;
    for (y = 0; y < 0x180; y++) {
        for (x = 0; x < 0x200; x++) {
            p[2] = p[0] = p[1];
            p += 3;
        }
    }
    func_001E14E0();
    func_001E05A8(D_003DB050);
    return 0;
}

void *func_0011ED30(s32, s32 (*func)(void));
s32 func_001E15A0(void);

void func_001E1688(void) {
    func_0011ED30(0x280A0, func_001E15A0);
}

INCLUDE_ASM("asm/nonmatchings/unsplit/file0DDF98", func_001E16B0);

extern s32 D_003DACCC;

s32 func_001E1748(u8 *p) {
    s32 v = *(s32 *)(p + 0x184 + *(s32 *)(p + 0x180) * 4);

    if (v > 0) {
        D_003DACD0 = 0x80 / v;
        D_003DACCC = 0;
    } else {
        D_003DACD0 = 0;
        D_003DACCC = 0x80;
    }
    func_0011ED30(0x280A0, func_001E15A0);
    *(s32 *)(p + 0x180) -= 1;
    return 2;
}

extern s32 D_003DACD0;

s32 func_001E17E0(u8 *p) {
    s32 v = *(s32 *)(p + 0x184 + *(s32 *)(p + 0x180) * 4);

    if (v > 0) {
        D_003DACD0 = -0x80 / v;
    } else {
        D_003DACD0 = -0x80;
    }
    *(s32 *)(p + 0x180) -= 1;
    return 2;
}

INCLUDE_ASM("asm/nonmatchings/unsplit/file0DDF98", func_001E1838);

void *func_0011ED30(s32, s32 (*func)(void));
s32 func_001E1838(void);

void func_001E1BF8(void) {
    func_0011ED30(0x280A0, func_001E1838);
}

INCLUDE_ASM("asm/nonmatchings/unsplit/file0DDF98", func_001E1C20);

void *func_0011ED30(s32, s32 (*func)(void));
s32 func_001E1C20(void);

void func_001E2470(void) {
    func_0011ED30(0x280A0, func_001E1C20);
}

void func_001E2498(void) {
    D_003854E0.unk_3070 &= ~((u64)1 << 50);
}

typedef struct {
    u32 a;
    u16 b;
    u8 c;
} A2Str7;
extern A2Str7 D_00490890;
extern char D_00490898[];
extern char D_003DACD8[][6];
char *strcat(char *, const char *);
int sprintf(char *, const char *, ...);
s32 func_00120590(char *, s32, s32 (*)(void), s32);
void func_F20000(void);

s32 func_001E24C8(A2Script *p) {
    char buf[0x100];
    char num[0x10];

    ((A2Str7 *)buf)->a = D_00490890.a;
    ((A2Str7 *)buf)->b = D_00490890.b;
    ((A2Str7 *)buf)->c = D_00490890.c;
    strcat(buf, D_003DACD8[p->unk_174[p->unk_174[3] + 3]]);
    sprintf(num, D_00490898, p->unk_174[p->unk_174[3] + 4]);
    strcat(buf, num);
    func_00120590(buf, (s32)func_F20000, (s32 (*)(void))func_001E2498, 0);
    D_003854E0.unk_3070 |= (u64)1 << 50;
    p->unk_174[3] -= 2;
    return 2;
}

s32 func_001E25C8(void) {
    return ((s32)(*(u64 *)D_0038CD00 >> 50) & 1) ? 4 : 2;
}

extern s32 D_003DAD38;
extern s32 D_003DAD3C;
s32 func_001E0898(void);

s32 func_001E25E8(void) {
    func_0011ED30(0x2E630, func_001E0898);
    D_003DAD3C = 0;
    D_003DAD38 = 1;
    return 2;
}

s32 func_001E08D8(void);

s32 func_001E2628(void) {
    func_0011ED30(0x2E630, func_001E08D8);
    D_003DAD3C = 0;
    D_003DAD38 = 1;
    return 2;
}

s32 func_001E2668(void) {
    D_003DAD38 = 0;
    return 2;
}

extern f32 D_003DAD40;
extern s32 D_003DAD44;

s32 func_001E2678(void) {
    *(f32 *)&D_003DAD3C += D_003DAD40;
    if (--D_003DAD44 > 0) {
        return 0;
    }
    return 4;
}

s32 func_001E26B8(A2Script *p) {
    f32 a = p->unk_174[p->unk_174[3] + 3];
    f32 b = p->unk_174[p->unk_174[3] + 4];

    D_003DAD44 = b;
    D_003DAD40 = (a - *(f32 *)&D_003DAD3C) / b;
    func_0011ED30(50000, func_001E2678);
    p->unk_174[3] -= 2;
    return 2;
}

extern s32 D_002BBBA0;

void func_001E2748(void) {
    D_002BBBA0 = 1;
    D_003854E0.unk_3070 |= (u64)1 << 46;
}

void func_001E2778(void) {
    D_002BBBA0 = 0;
    D_003854E0.unk_3070 &= ~((u64)1 << 46);
}

extern u8 D_003E1CB0[];
extern u8 D_003E3700[];
void func_001C4598(void *, void *, void *);

void func_001E27B0(void) {
    u8 buf[16];

    func_001C4598(D_003E1CB0, buf, D_0062FB00);
    func_001C4598(D_003E3700, buf, D_0062FF00);
    D_0062FA00 = 0;
}

s32 func_001E2800(s32 x) {
    return (u32)(x - 1) < 16;
}

extern s32 D_003DC470;
extern s32 D_003DC474;
extern s32 D_003DC478;
extern s32 D_003DC47C;
extern s32 D_003DC494;
extern u8 D_003DC468[];
extern u8 D_0062F760[];
extern u8 D_0062F6E0[];
void func_0010E230(void *);
void func_001EA128(void *, void *);
void func_001EA268(void *, s32);
void func_0010EDA0(void *, void *, s32);
extern u8 D_003DD278[];
extern u8 D_006304E0[];
typedef struct {
    u8 *a;
    u8 *b;
} A2StrPair6038;
extern A2StrPair6038 D_006310C8_p[] __asm__("D_006310C8");
void func_001E2810(void) {
    s32 v = D_003DC470;
    if (v != D_003DC474 && v != 0) {
        D_003DC474 = v;
        if (D_003DC478 == 0) {
            func_0010E230(D_0062F760);
            func_001EA128(&D_0062FA00, D_003DC468);
            if (D_003DC494 != 0) {
                func_001EA268(&D_0062FA00, ((s32 *)D_0062FF00)[D_003DC470]);
            } else {
                func_001EA268(&D_0062FA00, ((s32 *)D_0062FB00)[D_003DC470]);
            }
            func_0010EDA0(D_0062F6E0, &D_0062FA00, (s32)func_001E2810);
        } else {
            D_003DC47C = 0;
        }
    }
}

extern s32 D_003F7A68;
s32 func_001E2920(void) {
    if (D_003DC478 == 0) {
        return 4;
    }
    if (--D_003DC47C < 0) {
        D_003DC478 = 0;
        if (D_003F7A68 == 1 && D_003DC470 != 0) {
            func_0010E230(D_0062F760);
            func_001EA128(&D_0062FA00, D_003DC468);
            if (D_003DC494 != 0) {
                func_001EA268(&D_0062FA00, ((s32 *)D_0062FF00)[D_003DC470]);
            } else {
                func_001EA268(&D_0062FA00, ((s32 *)D_0062FB00)[D_003DC470]);
            }
            func_0010EDA0(D_0062F6E0, &D_0062FA00, (s32)func_001E2810);
        }
        return 4;
    }
    return 0;
}

extern s32 D_003DC484;

void func_001E2A30(s32 x) {
    D_003DC484 = x;
}

extern s32 D_002E26A0[];
void func_0022EEE0(s32);

void func_001E2A40(s32 x) {
    if (x == 3) {
        if (D_002E26A0[1] == 0) {
            x = 2;
        }
        if (D_002E26A0[2] == 0) {
            x = x - 1;
        }
    }
    func_0022EEE0(x);
}

INCLUDE_ASM("asm/nonmatchings/unsplit/file0DDF98", func_001E2A88);

INCLUDE_ASM("asm/nonmatchings/unsplit/file0DDF98", func_001E2D08);

extern s32 D_003DC484;

void func_001E2F88(s32 x) {
    D_003DC484 = x;
}

extern u8 D_0062F790[];
extern s32 D_003DC480;
extern u8 D_003DC2A8[];
extern u8 D_003DC368[];
extern s32 D_003DC490;
void func_0010BB10_w(void *, void *) __asm__("func_0010BB10");
void func_001E3F00();
void func_00230728(void);
s32 func_001F0A80(void);
s32 func_001BC370(s32);
void func_0022EE08(void);

void func_001E2F98(void) {
    D_003DC490 = 0;
    func_0010BB10_w(D_0062F790, func_001E3F00);
    if (D_003DC484 == 1) {
        if (D_003DC494 != 0) {
            s32 a;

            func_00230728();
            a = func_001F0A80();
            if (a - func_001BC370(D_003DC480) < 0) {
                func_0010E230(D_0062F6E0 + 0x80);
                func_0010EDA0(D_0062F6E0, D_003DC2A8, (s32)func_001E2810);
            } else {
                func_0010E230(D_0062F6E0 + 0x80);
                func_0010EDA0(D_0062F6E0, D_003DC368, (s32)func_001E2810);
            }
        } else {
            func_0022EE08();
            func_0010E230(D_0062F6E0 + 0x80);
            func_0010EDA0(D_0062F6E0, D_003DC368, (s32)func_001E2810);
        }
        D_003DC478 = 1;
        D_003DC47C = 0x3C;
        func_0011ED30(50000, func_001E2920);
    }
}

void func_0010EDA0(void *, void *, s32);
extern s32 D_003DC490;
extern u8 D_0062F790[];
extern u8 D_003DC1E8[];
extern s32 D_0062F8F0[];
void func_0010F3B8(void *, void *, s32);
void func_001E2F98();
void func_001E2F88();

void func_001E30F8(void) {
    D_003DC490 = 1;
    func_0010EDA0(D_0062F790, D_003DC1E8, (s32)func_001E2F98);
    D_0062F8F0[0] = 1;
    D_0062F8F0[1] = 2;
    D_0062F8F0[2] = (s32)func_001E2F88;
    func_0010F3B8(D_0062F8F0, D_0062F790, 1);
}

extern s32 D_003F7A64;

s32 func_001E3178(void) {
    if (D_003F7A64 == 0) {
        func_001E2778();
        return 4;
    }
    return 0;
}

void func_001E31B0(void) {
}

extern s32 D_002C2108;
extern s32 D_003DC490;
extern s32 D_003DC48C;
extern u8 D_003DBA68[];
extern u8 D_0062F790[];
void func_0011D598(s32);
void func_0010BB10_v(void *, void *) __asm__("func_0010BB10");
void func_00231980_v(void) __asm__("func_00231980");
void func_0010F380_v(void) __asm__("func_0010F380");
s32 func_001E3178(void);
void func_001E31B0(void);
void func_001E3F00();

s32 func_001E31B8(void) {
    if (D_002C2108 & 2) {
        if (D_003DC490 == 0) {
            return 0;
        }
        func_0011D598(3);
        if (D_003F7A68 != 0) {
            D_003DC478 = 0;
            func_0010BB10_v(D_0062F6E0, func_001E31B0);
            func_00231980_v();
            func_0011ED30(50000, func_001E3178);
            return 4;
        }
        if (D_003DC48C != 0) {
            D_003DC490 = 0;
            func_0010BB10_v(D_0062F790, func_001E3F00);
            func_0010F380_v();
            func_0010E230(D_0062F6E0 + 0x80);
            func_0010EDA0(D_0062F6E0, D_003DBA68, (s32)func_001E2810);
            D_003DC478 = 1;
            D_003DC47C = 0x3C;
            func_0011ED30(50000, func_001E2920);
        }
    }
    return 0;
}

extern s32 D_003DC470;

void func_001E32C8(s32 x) {
    D_003DC470 = x;
}

void func_0011D598(s32);
void func_0010BB50();
s32 func_001E2920(void);
void func_001E2D08();
extern s32 D_003F7A68;
extern s32 D_003DC48C;
void func_001E2810();
extern s32 D_003DC478;
extern s32 D_003DC47C;
extern s32 D_003DC480;
extern s32 D_003DC494;
extern u8 D_003DC2A8[];
extern u8 D_003DC2F8[];
extern u8 D_003DC370[];
extern u8 D_0062F6E0[];

void func_001E32D8(s32 a0) {
    s32 r;
    u8 *p;
    u8 *q;
    u8 *t;

    D_003F7A68 = 0;
    D_003DC478 = 0;
    D_003DC480 = a0;
    D_003DC48C = 1;
    func_0011D598(2);
    if (D_003DC494 != 0) {
        if (a0 == -1) {
            func_0011D598(4);
            func_0010E230(D_0062F6E0 + 0x80);
            func_0010EDA0(D_0062F6E0, D_003DC2A8, (s32)func_001E2810);
            D_003DC478 = 1;
            D_003DC47C = 0x3C;
            func_0011ED30(0xC350, func_001E2920);
            D_003F7A68 = 1;
            D_003DC48C = 0;
        } else if (a0 == -2) {
            func_0011D598(4);
            func_0010E230(D_0062F6E0 + 0x80);
            func_0010EDA0(D_0062F6E0, D_003DC2F8, (s32)func_001E2810);
            D_003DC478 = 1;
            D_003DC47C = 0x3C;
            func_0011ED30(0xC350, func_001E2920);
            D_003F7A68 = 1;
            D_003DC48C = 0;
        } else if (a0 == -3) {
            func_0011D598(4);
            func_0010E230(D_0062F6E0 + 0x80);
            func_0010EDA0(D_0062F6E0, D_003DC2F8, (s32)func_001E2810);
            D_003DC478 = 1;
            D_003DC47C = 0x3C;
            func_0011ED30(0xC350, func_001E2920);
            D_003F7A68 = 1;
            D_003DC48C = 0;
        } else if (a0 == -4) {
            func_0011D598(4);
            func_0010E230(D_0062F6E0 + 0x80);
            func_0010EDA0(D_0062F6E0, D_003DC2F8, (s32)func_001E2810);
            D_003DC478 = 1;
            D_003DC47C = 0x3C;
            func_0011ED30(0xC350, func_001E2920);
            D_003F7A68 = 1;
            D_003DC48C = 0;
        } else {
            p = D_0062F790;
            *(f32 *)(p + 0x44) = 1.5f;
            D_003DC490 = 0;
            func_0010BB50(p, func_001E30F8);
        }
    } else {
        if (a0 == -1) {
            func_0011D598(4);
            func_0010E230(D_0062F6E0 + 0x80);
            func_0010EDA0(D_0062F6E0, D_003DC2A8, (s32)func_001E2810);
            D_003DC478 = 1;
            D_003DC47C = 0x3C;
            func_0011ED30(0xC350, func_001E2920);
            D_003F7A68 = 1;
            D_003DC48C = 0;
        } else if (a0 == -2) {
            func_0011D598(4);
            func_0010E230(D_0062F6E0 + 0x80);
            func_0010EDA0(D_0062F6E0, D_003DC370, (s32)func_001E2810);
            D_003DC478 = 1;
            D_003DC47C = 0x3C;
            func_0011ED30(0xC350, func_001E2920);
            D_003F7A68 = 1;
            D_003DC48C = 0;
        } else if (a0 == -3) {
            func_0011D598(4);
            func_0010E230(D_0062F6E0 + 0x80);
            func_0010EDA0(D_0062F6E0, D_003DC370, (s32)func_001E2810);
            D_003DC478 = 1;
            D_003DC47C = 0x3C;
            func_0011ED30(0xC350, func_001E2920);
            D_003F7A68 = 1;
            D_003DC48C = 0;
        } else if (a0 == -4) {
            func_0011D598(4);
            func_0010E230(D_0062F6E0 + 0x80);
            func_0010EDA0(D_0062F6E0, D_003DC370, (s32)func_001E2810);
            D_003DC478 = 1;
            D_003DC47C = 0x3C;
            func_0011ED30(0xC350, func_001E2920);
            D_003F7A68 = 1;
            D_003DC48C = 0;
        } else {
            r = func_001E2800(D_003DC480);
            q = D_0062F790;
            *(f32 *)(q + 0x44) = 1.5f;
            if (r) {
                *(f32 *)(q + 0x44) = 2.0f;
            }
            if (D_002E26A0[1] && r) {
                *(f32 *)(q + 0x44) = 3.0f;
            }
            if (D_002E26A0[2] && r) {
                t = D_0062F790;
                *(f32 *)(t + 0x44) = 4.0f;
            }
            D_003DC490 = 0;
            func_0010BB50(D_0062F790, func_001E2D08);
        }
    }
}

INCLUDE_ASM("asm/nonmatchings/unsplit/file0DDF98", func_001E3600);

extern u8 D_0062F6E0[];
extern u8 D_003DBA68[];
extern s32 D_003F7A68;
extern s32 D_003DC490;
void func_0010EDA0(void *, void *, s32);
void func_001E2810();

void func_001E3728(void) {
    func_0010EDA0(D_0062F6E0, D_003DBA68, (s32)func_001E2810);
    D_003F7A68 = 1;
    D_003DC490 = 1;
}

extern u8 D_003DB078[];
void func_001E3600();
void func_00231740(s32, s32, s32, s32);
s32 func_001E31B8(void);

s32 func_001E3770(A2Script *s) {
    s32 t;
    s32 v;

    D_002C1EA8 |= 0xC;
    func_001E27B0();
    func_001E3600();
    func_0010BB50(D_0062F6E0, func_001E3728);
    func_00231740(0, (s32)(D_003DB078 + s->unk_174[s->unk_174[3] + 4] * 0xD4), (s32)func_001E32C8, (s32)func_001E32D8);
    D_003F7A68 = 0;
    D_003DC478 = 1;
    D_003DC47C = 0x3C;
    func_0011ED30(50000, func_001E2920);
    func_0011ED30(50000, func_001E31B8);
    D_003DC494 = 0;
    D_003DC48C = 0;
    D_003DC490 = 0;
    func_001E2748();
    t = s->unk_174[3];
    v = *(s32 *)(D_003DB078 + s->unk_174[t + 4] * 0xD4 + 4);
    D_003DC470 = D_003DC474 = v;
    s->unk_174[3] = t - 1;
    return 2;
}

extern u8 D_003DB718[];

s32 func_001E38B0(A2Script *s) {
    s32 t;
    s32 v;

    D_002C1EA8 |= 0xC;
    func_001E27B0();
    func_001E3600();
    func_0010BB50(D_0062F6E0, func_001E3728);
    func_00231740(2, (s32)(D_003DB718 + s->unk_174[s->unk_174[3] + 4] * 0xD4), (s32)func_001E32C8, (s32)func_001E32D8);
    D_003DC478 = 1;
    D_003DC47C = 0x3C;
    func_0011ED30(50000, func_001E2920);
    func_0011ED30(50000, func_001E31B8);
    D_003F7A68 = 0;
    D_003DC494 = 1;
    D_003DC490 = 0;
    func_001E2748();
    t = s->unk_174[3];
    v = *(s32 *)(D_003DB718 + s->unk_174[t + 4] * 0xD4 + 4);
    D_003DC470 = D_003DC474 = v;
    s->unk_174[3] = t - 1;
    return 2;
}

extern s32 D_003F7E98;

void func_001E39F0(void) {
    D_003F7E98 = 1;
}

INCLUDE_ASM("asm/nonmatchings/unsplit/file0DDF98", func_001E3A00);

extern s32 D_003DC484;

void func_001E3A98(s32 x) {
    D_003DC484 = x;
}

extern s32 D_003DC48C;
extern u8 D_0062F840[];
extern u8 D_003DC268[];
extern s32 D_0062F8F0[];
void func_0010F3B8(void *, void *, s32);
void func_001E3A00();
void func_001E3A98();

void func_001E3AA8(void) {
    D_003DC48C = 1;
    func_0010EDA0(D_0062F840, D_003DC268, (s32)func_001E3A00);
    D_0062F8F0[0] = 1;
    D_0062F8F0[1] = 2;
    D_0062F8F0[2] = (s32)func_001E3A98;
    func_0010F3B8(D_0062F8F0, D_0062F840, 1);
}

void func_001E2778(void);

void func_001E3B28(void) {
    func_001E2778();
}

extern s32 D_002C2108;
extern s32 D_003F7E98;
extern u8 D_003DC390[];
extern u8 D_0062F840[];
void func_00232758(void);
void func_001E39F0();
void func_001E3B28();

s32 func_001E3B40(void) {
    s32 *p;

    if (D_002C2108 & 2) {
        if (D_003F7E98 != 0) {
            func_00232758();
            func_0010BB10(D_0062F790, (s32)func_001E3B28);
            func_0011D598(3);
            return 4;
        }
        p = &D_003DC48C;
        if (*p != 0) {
            func_0010E230(D_0062F790 + 0x80);
            func_0010EDA0(D_0062F790, D_003DC390, 0);
            func_0010BB10(D_0062F840, (s32)func_001E39F0);
            func_0011D598(3);
            *p = 0;
        }
    }
    return 0;
}

extern s32 D_003DC470;
extern s32 D_003DC474;
void func_0010E230(void *);
extern u8 D_0062F790[];
extern u8 D_003DC390[];

void func_001E3C08(s32 x) {
    D_003DC470 = x;
    if (x != D_003DC474) {
        D_003DC474 = x;
        func_0010E230(D_0062F790 + 0x80);
        func_0010EDA0(D_0062F790, D_003DC390, 0);
    }
}

extern u8 D_003DC3D0[];
extern u8 D_003DC408[];
extern u8 D_003DC428[];

void func_001E3C70(s32 a0) {
    if (a0 == -1) {
        func_0010E230(D_0062F790 + 0x80);
        func_0010EDA0(D_0062F790, D_003DC3D0, 0);
        func_0011D598(4);
    } else if (a0 == -2) {
        func_0010E230(D_0062F790 + 0x80);
        func_0010EDA0(D_0062F790, D_003DC408, 0);
        func_0011D598(4);
    } else if (a0 == -3) {
        func_0010E230(D_0062F790 + 0x80);
        func_0010EDA0(D_0062F790, D_003DC428, 0);
        func_0011D598(4);
    } else {
        u8 *p = D_0062F840;

        D_003F7E98 = 0;
        *(f32 *)(p + 0x30) = 90.0f;
        *(f32 *)(p + 0x34) = 140.0f;
        *(f32 *)(p + 0x40) = 6.0f;
        *(f32 *)(p + 0x44) = 1.5f;
        func_0010BB50(p, func_001E3AA8);
        func_0011D598(2);
    }
}

extern u8 D_0062F790[];
extern u8 D_003DC390[];
void func_0010EDA0(void *, void *, s32);

void func_001E3DA8(void) {
    func_0010EDA0(D_0062F790, D_003DC390, 0);
}

void func_00232780(void);
void func_001E3600_nt() __asm__("func_001E3600");
extern inline void func_001E3600_nt(nothrow_arg_) double nothrow_arg_; {}
void func_00232640(void *, void *);
void func_001E3C08();
void func_001E3C70();
void func_001E3DA8();

s32 func_001E3DD0(A2Script *s) {
    u8 *p;

    D_002C1EA8 |= 0xC;
    func_001E3600_nt();
    D_003DC48C = 0;
    func_00232780();
    func_00232640(func_001E3C08, func_001E3C70);
    p = D_0062F790;
    *(f32 *)(p + 0x30) = 80.0f;
    *(f32 *)(p + 0x34) = 150.0f;
    *(f32 *)(p + 0x40) = 12.0f;
    *(f32 *)(p + 0x44) = 1.8f;
    *(s16 *)(p + 4) = 2;
    *(s16 *)(p + 6) = 1;
    *(s16 *)(p + 8) = 17;
    *(f32 *)(p + 0x1C) = 270.0f;
    func_0010BB50(p, (s32)func_001E3DA8);
    func_0011ED30(0xC350, func_001E3B40);
    func_001E2748();
    D_003DC474 = D_003DC470 = 0;
    s->unk_174[3]--;
    return 2;
}

s32 func_001E3ED0(void) {
    return ((s32)(*(u64 *)D_0038CD00 >> 46) & 1) ? 4 : 2;
}

extern s32 D_003DC484;

void func_001E3EF0(s32 x) {
    D_003DC484 = x;
}

extern s32 D_003F7A68;
extern s32 D_003DC48C;
extern s32 D_003DC490;

void func_001E3F00(void) {
    D_003F7A68 = 1;
    D_003DC48C = 0;
    D_003DC490 = 1;
}

INCLUDE_ASM("asm/nonmatchings/unsplit/file0DDF98", func_001E3F20);

extern s32 D_003DC490;
extern u8 D_0062F790[];
extern u8 D_003DC228[];
extern s32 D_0062F8F0[];
void func_0010F3B8(void *, void *, s32);
void func_001E3F20();
void func_001E3EF0();

void func_001E3FC8(void) {
    D_003DC490 = 1;
    func_0010EDA0(D_0062F790, D_003DC228, (s32)func_001E3F20);
    D_0062F8F0[0] = 1;
    D_0062F8F0[1] = 2;
    D_0062F8F0[2] = (s32)func_001E3EF0;
    func_0010F3B8(D_0062F8F0, D_0062F790, 1);
}

extern s32 D_003DC470;
extern s32 D_003DC474;

void func_001E4048(s32 x) {
    D_003DC470 = x;
    if (D_003DC474 == 0) {
        D_003DC474 = x;
    }
}

void func_001E4070(s32 a0) {
    extern s32 D_003DC488;
    extern u8 D_003DC2B8[];
    extern u8 D_003DC358[];
    extern u8 D_003DC380[];
    extern u8 D_003DC2C8[];
    extern u8 D_003DC338[];
    extern void func_001E3FC8();
    extern struct {
        u8 pad[0x44];
        f32 unk_44;
    } D_0062F790_s __asm__("D_0062F790");

    if (a0 == -1) {
        func_0010EDA0(D_0062F6E0, D_003DC2B8, 0);
        func_0011D598(4);
        return;
    }
    if (a0 == -2) {
        if (D_003DC494 != 0) {
            func_0010EDA0(D_0062F6E0, D_003DC358, 0);
            func_0011D598(4);
        } else {
            func_0010EDA0(D_0062F6E0, D_003DC380, 0);
            func_0011D598(4);
        }
        return;
    }
    if (a0 == -3) {
        if (D_003DC494 != 0) {
            func_0010EDA0(D_0062F6E0, D_003DC2C8, 0);
            func_0011D598(4);
        } else if (D_003DC488 - 1 == D_003DC480) {
            func_0010EDA0(D_0062F6E0, D_003DC2C8, 0);
            func_0011D598(4);
        } else {
            func_0010EDA0(D_0062F6E0, D_003DC338, 0);
            func_0011D598(4);
        }
        return;
    }
    func_0011D598(2);
    if (D_003DC494 != 0) {
        D_003DC490 = 0;
        D_003F7A68 = 0;
        D_003DC48C = 1;
        D_0062F790_s.unk_44 = 1.5f;
        func_0010BB50(&D_0062F790_s, func_001E3FC8);
        return;
    } else {
        D_003DC490 = 0;
        D_003F7A68 = 0;
        D_0062F790_s.unk_44 = 1.5f;
        func_0010BB50(&D_0062F790_s, func_001E3FC8);
    }
}

void func_001E4250(void) {
    func_001E2778();
}

extern u8 D_003DBD68[];

void func_001E4268(void) {
    D_003DC490 = 1;
    D_003F7A68 = 1;
    D_003DC48C = 0;
    func_0010EDA0(D_0062F6E0, D_003DBD68, 0);
}

void func_0010BB50();
void func_001E4578();

void func_001E42B0(void) {
    u8 *p = D_0062F790;

    *(f32 *)(p + 0x44) = 2.0f;
    if (D_002E26A0[1] != 0) {
        *(f32 *)(p + 0x44) = 3.0f;
    }
    if (D_002E26A0[2] != 0) {
        *(f32 *)(p + 0x44) = 4.0f;
    }
    func_0010BB50(p, (s32)func_001E4578);
}

INCLUDE_ASM("asm/nonmatchings/unsplit/file0DDF98", func_001E4318);

extern s32 D_003DC488;
extern s32 D_003DC480;
void func_00231958(void);
void func_0022FC88(s32);

void func_001E44E0(s32 x) {
    D_003DC490 = 0;
    if (D_003DC488 == x) {
        func_001E2778();
        func_00231958();
        return;
    }
    D_003DC480 = x;
    func_0022FC88(x - 1);
    func_0010BB50(D_0062F6E0, (s32)func_001E4268);
    D_003DC470 = 0;
    D_003DC474 = 0;
}

extern u8 D_0062F790[];
void func_0010BB10(void *, s32);

void func_001E4558(void) {
    func_0010BB10(D_0062F790, 0);
}

void func_001E4578(void) {
    extern u8 D_0062F900[];
    extern u8 D_003DC068[];
    extern u8 D_003DC0A8[];
    extern u8 D_003DC0E8[];
    extern u8 D_003DC1A8[];
    extern u8 D_003DC128[];
    extern u8 D_003DC460[];
    extern u8 *D_003010F8_u __asm__("D_003010F8");
    extern s32 func_001E4318(void);
    extern s32 func_0010EDA0_s(void *, void *, s32) __asm__("func_0010EDA0");
    s32 n;
    s32 k;
    s32 t;

    D_003DC488 = 0;
    D_003DC490 = 1;
    func_001EA128(D_0062F900, D_003DC468);
    func_001EA268(D_0062F900, (s32)D_003DC068);
    t = D_003DC488;
    k = D_003010F8_u[0x48F];
    D_003DC488 = t + 1;
    n = 2;
    if (k == 1) {
        func_001EA268(D_0062F900, (s32)(D_003DC068 + 0x40));
        n = 3;
        D_003DC488++;
    } else if (k == 2) {
        func_001EA268(D_0062F900, (s32)(D_003DC068 + 0x80));
        n = 3;
        D_003DC488++;
    } else if (k == 5) {
        func_001EA268(D_0062F900, (s32)(D_003DC068 + 0x140));
        n = 3;
        D_003DC488++;
    }
    if (D_003010F8_u[0x490] == 1) {
        func_001EA268(D_0062F900, (s32)D_003DC0A8);
        n++;
        D_003DC488++;
    } else if (D_003010F8_u[0x490] == 2) {
        func_001EA268(D_0062F900, (s32)D_003DC0E8);
        n++;
        D_003DC488++;
    } else if (D_003010F8_u[0x490] == 5) {
        func_001EA268(D_0062F900, (s32)D_003DC1A8);
        n++;
        D_003DC488++;
    }
    func_001EA268(D_0062F900, (s32)D_003DC128);
    D_003DC488++;
    func_001EA268(D_0062F900, (s32)(D_003DC128 + 0x40));
    D_003DC488++;
    func_001EA268(D_0062F900, (s32)D_003DC460);
    func_0010EDA0_s(D_0062F790, D_0062F900, (s32)func_001E4558);
    D_0062F8F0[0] = 1;
    D_0062F8F0[1] = D_003DC488;
    D_0062F8F0[2] = (s32)func_001E44E0;
    func_0010F3B8(D_0062F8F0, D_0062F790, n);
    func_0011ED30(50000, func_001E4318);
}

void func_001E3600();
void func_00231740(s32, s32, s32, s32);
void func_001E4070();

s32 func_001E4790(void) {
    u8 *p;

    D_002C1EA8 |= 0xC;
    func_001E27B0();
    func_001E3600();
    p = D_0062F790;
    *(f32 *)(p + 0x44) = 2.0f;
    if (D_002E26A0[1] != 0) {
        *(f32 *)(p + 0x44) = 3.0f;
    }
    if (D_002E26A0[2] != 0) {
        *(f32 *)(p + 0x44) = 4.0f;
    }
    func_0010BB50(p, (s32)func_001E4578);
    func_00231740(1, 0, (s32)func_001E4048, (s32)func_001E4070);
    D_003F7A68 = 0;
    D_003DC494 = 0;
    D_003DC48C = 1;
    D_003DC490 = 0;
    func_001E2748();
    return 2;
}

extern s32 D_003DC470;
extern s32 D_003DC474;
s32 func_001E4318();

s32 func_001E4868(void) {
    D_002C1EA8 |= 0xC;
    func_001E27B0();
    func_001E3600();
    func_0010BB50(D_0062F6E0, (s32)func_001E4268);
    func_00231740(3, 0, (s32)func_001E4048, (s32)func_001E4070);
    func_0011ED30(0xC350, func_001E4318);
    D_003F7A68 = 0;
    D_003DC494 = 1;
    D_003DC48C = 0;
    D_003DC490 = 0;
    func_001E2748();
    D_003DC474 = 0;
    D_003DC470 = 0;
    return 2;
}

extern u8 D_003E0D20[];
extern u8 D_003E0F40[];
extern u8 D_003E1150[];
extern u8 D_003E12E0[];
extern u8 D_006310C8[];
extern u8 D_00631148[];
extern u8 D_006311C8[];
extern u8 D_00631248[];

void func_001E4918(void) {
    u8 buf[16];

    func_001C4598(D_003E0D20, buf, D_006310C8);
    func_001C4598(D_003E0F40, buf, D_00631148);
    func_001C4598(D_003E1150, buf, D_006311C8);
    func_001C4598(D_003E12E0, buf, D_00631248);
}

extern s32 D_003F7EC8;
extern u8 D_006307C8[];
extern s32 D_006305C0[];
extern s32 D_006305CC;
extern u8 D_00630300[];
extern s32 D_003DD25C;
extern s8 D_006314C8_s __asm__("D_006314C8");
void func_001E5198();
void func_001E5788(s32);

void func_001E4990(void) {
    D_003F7EC8 = 1;
    func_0010E230(D_00630300 + 0x80);
    func_0010EDA0(D_00630300, D_006307C8, (s32)func_001E5198);
    if (D_003DD25C == 3) {
        D_006305C0[0] = 3;
        if (D_006305CC == 4 || D_006305CC == 0) {
            D_006305C0[1] = 13;
        } else {
            D_006305C0[1] = 14;
        }
    } else {
        D_006305C0[0] = 4;
        D_006305C0[1] = 13;
    }
    D_006305C0[2] = (s32)func_001E5788;
    func_0010F3B8(D_006305C0, D_00630300, D_006314C8_s);
}

extern u8 D_006303B0[];
extern s32 D_003DD264;
void func_00232AA8(void);

s32 func_001E4A68(void) {
    s32 *p;
    if (D_002C2108 & 2) {
        p = &D_003DD264;
        if (*p == 1) {
            func_0010BB10(D_006303B0, (s32)func_001E4990);
            *p = 0;
        } else {
            func_0010BB10(D_00630300, 0);
            func_00232AA8();
            D_003854E0.unk_3078 &= ~0x10;
            return 4;
        }
    }
    return 0;
}

extern u8 D_006305D0[][10];
void func_001E4B08(void) {
    s32 i;
    for (i = 0; i < 50; i++) {
        if (i < 9) {
            D_006305D0[i][0] = 0xF;
            D_006305D0[i][1] = 2;
            D_006305D0[i][2] = 1;
            D_006305D0[i][3] = i + 0x22;
            D_006305D0[i][4] = 1;
            D_006305D0[i][5] = 0xF;
            D_006305D0[i][6] = 3;
            D_006305D0[i][7] = 0;
        } else {
            D_006305D0[i][0] = 0xF;
            D_006305D0[i][1] = 2;
            D_006305D0[i][2] = (i + 1) / 10 + 0x21;
            D_006305D0[i][3] = (i + 1) % 10 + 0x21;
            D_006305D0[i][4] = 1;
            D_006305D0[i][5] = 0xF;
            D_006305D0[i][6] = 3;
            D_006305D0[i][7] = 0;
        }
    }
}

INCLUDE_ASM("asm/nonmatchings/unsplit/file0DDF98", func_001E4C20);

extern u8 D_006303B0[];
extern s32 D_003DD264;
void func_0010BB10(void *, s32);
void func_001E4990();

void func_001E4D20(void) {
    D_003DD264 = 0;
    func_0010BB10(D_006303B0, (s32)func_001E4990);
}

INCLUDE_ASM("asm/nonmatchings/unsplit/file0DDF98", func_001E4D50);

INCLUDE_ASM("asm/nonmatchings/unsplit/file0DDF98", func_001E5198);

extern u8 D_006314C8;
extern s32 D_003DD25C;
extern s32 D_003DD258;
void func_001E4D50();

void func_001E5788(s32 x) {
    D_006314C8 = x;
    if (D_003DD25C == 3) {
        D_003DD258 = x - 3;
        if (x - 3 < 10) {
            func_0010BB50(D_006303B0, (s32)func_001E4D50);
            D_003DD264 = 1;
        }
    } else {
        D_003DD258 = x - 4;
        func_0010BB50(D_006303B0, (s32)func_001E4D50);
        D_003DD264 = 1;
    }
}

INCLUDE_ASM("asm/nonmatchings/unsplit/file0DDF98", func_001E5810);

INCLUDE_ASM("asm/nonmatchings/unsplit/file0DDF98", func_001E58C0);

extern s32 D_003DD264;
extern u8 D_006307C8[];
extern u8 D_00630300[];
void func_001E4C20(void);
void func_001EA268_b(void *, u8 *) __asm__("func_001EA268");
void func_001E5810();

s32 func_001E5D78(void) {
    u8 buf[16];
    s32 i;
    s32 o;
    u8 *p;

    D_003DD264 = 0;
    D_002C1EA8 |= 0xC;
    func_001E4B08();
    for (i = 0, o = 0x7D0; i < 10; i++, o += 2) {
        u8 *b = (u8 *)D_003010F8 + 8;
        u16 *q = (u16 *)(b + o);
        if (*q < 9) {
            buf[0] = 1;
            buf[1] = 1;
            buf[2] = *(u8 *)q + 0x21;
            buf[3] = 1;
            buf[4] = 0;
        } else {
            buf[0] = (*q + 1) / 10 + 0x21;
            buf[1] = (*q + 1) % 10 + 0x21;
            buf[2] = 1;
            buf[3] = 0;
        }
        func_001EA268_b(D_006307C8, buf);
    }
    func_001E4C20();
    p = D_00630300;
    *(f32 *)(p + 0x30) = -60.0f;
    *(f32 *)(p + 0x34) = -30.0f;
    *(f32 *)(p + 0x40) = 10.0f;
    *(f32 *)(p + 0x44) = 11.0f;
    func_0010BB50(p, func_001E5810);
    return 2;
}

INCLUDE_ASM("asm/nonmatchings/unsplit/file0DDF98", func_001E5EE0);

extern s32 D_003DD284;
extern s32 D_003DD288;
extern u8 D_00630FC8[];
extern u8 D_003DD270[];
extern u8 D_003DCB90[];
extern u8 D_003DD230[];

s32 func_001E6038(void) {
    u8 *w = (u8 *)func_0022F768(1);

    if (D_003DD284 == 0) {
        return 4;
    }
    if (--D_003DD288 < 0) {
        D_003DD284 = 0;
        func_001EA128(D_00630FC8, D_003DD270);
        if (*(u8 *)(D_003DD258 + (s32)w + 0xA80) == 0) {
            func_001EA268_b(D_00630FC8, D_006305D0[D_003DD258 + 1]);
            func_001EA268_b(D_00630FC8, D_003DCB90);
        } else {
            func_001EA268_b(D_00630FC8, D_006305D0[D_003DD258 + 1]);
            func_001EA268_b(D_00630FC8, D_006310C8_p[*(u8 *)(D_003DD258 + (s32)w + 0xA80) - 1].a);
            func_001EA268_b(D_00630FC8, D_003DD230);
            func_001EA268_b(D_00630FC8, D_003DD278);
            func_001EA268_b(D_00630FC8, D_006310C8_p[*(u8 *)(D_003DD258 + (s32)w + 0xA80) - 1].b);
        }
        func_0010E230(D_006304E0);
        func_0010EDA0(D_006304E0 - 0x80, D_00630FC8, 0);
        return 4;
    }
    return 0;
}

void func_001E61C0(s32 a0, void *a1) {
    extern s32 D_003DD258;
    extern s32 D_003DD25C;
    extern s32 D_003DD27C;
    extern s32 D_003DD280;
    extern u8 D_00630460[];
    extern u8 D_00630510[];
    extern u8 D_00630300[];
    extern u8 D_003DC498[];
    extern u8 D_003DCEF0[];
    extern void func_0010BB10(void *, s32);
    extern void func_002329A0(void *, void *, void *);
    extern void func_001E6578(void);
    extern void func_001E6580(void);
    extern void func_001E6BA8(void);
    extern void func_001E6E20(void);
    s32 ok = 0;
    u8 *w = (u8 *)func_0022F768(1);

    switch (D_003DD258) {
    case 1:
        func_0010BB10(D_00630460, 0);
        return;
    case 2:
        switch (D_003DD25C) {
        case 0:
            if (*(s32 *)(w + 0xAD0) & 1) {
                ok = 1;
            }
            break;
        case 1:
            if (*(s32 *)(w + 0xAD0) & 2) {
                ok = 1;
            }
            break;
        case 2:
            if (*(s32 *)(w + 0xAD0) & 4) {
                ok = 1;
            }
            break;
        case 3:
            if (*(s32 *)(w + 0xAD0) & 8) {
                ok = 1;
            }
            break;
        }
        if (ok == 1) {
            func_002329A0(D_003DC498, func_001E6578, func_001E6580);
            func_0010BB50(D_00630300, func_001E6BA8);
            func_0010E230(D_006304E0);
            func_0010EDA0(D_006304E0 - 0x80, D_003DCEF0, 0);
            D_003DD284 = ok;
            D_003DD288 = 60;
            func_0011ED30(0xC350, func_001E6038);
            D_003DD280 = 0;
            D_003DD27C = 0;
        } else {
            func_0010E230(D_006304E0);
            func_0010EDA0(D_006304E0 - 0x80, D_00630FC8, 0);
            func_0010BB50(D_00630510, func_001E6E20);
        }
        break;
    }
}

extern u8 D_00630510[];
void func_001E61C0(s32, void *);

void func_001E6388(void) {
    func_001E61C0(0, D_00630510);
}

extern s32 D_002C2108;
extern s32 D_003DD258;
extern s32 D_003DD28C;
extern u8 D_00630510[];
void func_001E6388(void);

s32 func_001E63A8(void) {
    if (D_003DD28C == 0) {
        return 4;
    }
    if (D_002C2108 & 2) {
        D_003DD28C = 0;
        D_003DD258 = 2;
        func_0010BB10(D_00630510, (s32)func_001E6388);
        return 4;
    }
    return 0;
}

extern u8 D_00630510[];
void func_0010BB10(void *, s32);
void func_001E61C0(s32, void *);

void func_001E6410(void) {
    func_0010BB10(D_00630510, (s32)func_001E61C0);
}

extern s32 D_003DD258;
extern s32 D_003DD28C;

void func_001E6438(s32 x) {
    D_003DD28C = 0;
    D_003DD258 = x;
}

extern s32 D_003DCEB0[];
extern s32 D_006305C0[];
extern s32 D_003DD28C;
extern u8 D_00630510[];

void func_001E6450(void) {
    func_0010EDA0(D_00630510, D_003DCEB0, (s32)func_001E6410);
    D_006305C0[0] = 1;
    D_006305C0[1] = 2;
    D_006305C0[2] = (s32)func_001E6438;
    func_0010F3B8(D_006305C0, D_00630510, 1);
    func_0011ED30(0xC350, func_001E63A8);
    D_003DD28C = 1;
}

void func_001E64E0(void) {
    D_003854E0.unk_3078 &= ~0x10;
}

extern s32 D_003DD260;
extern u8 D_00630300[];

s32 func_001E6500(void) {
    if (D_003DD28C == 0) {
        return 4;
    }
    if (D_002C2108 & 2) {
        func_0010BB10(D_00630300, (s32)func_001E64E0);
        D_003DD28C = 0;
        D_003DD260 = -1;
        return 4;
    }
    return 0;
}

void func_001E6578(void) {
}

extern s32 D_006305CC;
extern u8 D_00630300[];

extern s32 D_003DD260;

void func_001E6580(s32 a) {
    D_003DD28C = 0;
    D_003DD260 = a + D_006305CC * 10;
    func_0010BB10(D_00630300, (s32)func_001E64E0);
}

INCLUDE_ASM("asm/nonmatchings/unsplit/file0DDF98", func_001E65D0);

extern s32 D_003DD25C;
extern s32 D_003DD260;

void func_001E6B70(s32 x) {
    if (D_003DD25C == 3) {
        D_003DD260 = x - 1;
    } else {
        D_003DD260 = x - 2;
    }
}

INCLUDE_ASM("asm/nonmatchings/unsplit/file0DDF98", func_001E6BA8);

extern u8 D_00630510[];
void func_0010BB50();
s32 func_001E72A0(void);

void func_001E6C68(void) {
    func_0010BB50(D_00630510, (s32)func_001E72A0);
}

extern u8 D_006304E0[];
extern u8 D_003DCD70[];

s32 func_001E6C90(void) {
    s32 *p = &D_003DD28C;
    if (*p == 0) {
        return 4;
    }
    if (D_002C2108 & 2) {
        func_0010E230(D_006304E0);
        func_0010EDA0(D_006304E0 - 0x80, D_003DCD70, 0);
        func_0010BB10(D_00630510, (s32)func_001E6C68);
        *p = 0;
        return 4;
    }
    return 0;
}

extern u8 D_00630460[];
extern u8 D_003DCF30[];
extern u8 D_003DCD70[];
s32 func_0010BB50_r() __asm__("func_0010BB50");

s32 func_001E6D20(void) {
    switch (D_003DD258) {
    case 1:
        func_0010E230(D_00630460 + 0x80);
        func_0010EDA0(D_00630460, D_003DCF30, 0);
        return func_0010BB50_r(D_00630510, func_001E6450);
    case 2:
        func_0010E230(D_00630460 + 0x80);
        func_0010EDA0(D_00630460, D_003DCD70, 0);
        func_0010BB50(D_00630510, func_001E72A0);
        break;
    }
}

extern u8 D_00630510[];
void func_0010BB10();
s32 func_001E6D20(void);

void func_001E6DE0(void) {
    func_0010BB10(D_00630510, (s32)func_001E6D20);
}

void func_001E6E08(s32 x) {
    D_003DD28C = 0;
    D_003DD258 = x;
}

s32 func_001E6C90(void);

void func_001E6E20(void) {
    func_0010EDA0(D_00630510, D_003DCEB0, (s32)func_001E6DE0);
    D_006305C0[0] = 1;
    D_006305C0[1] = 2;
    D_006305C0[2] = (s32)func_001E6E08;
    func_0010F3B8(D_006305C0, D_00630510, 1);
    func_0011ED30(0xC350, func_001E6C90);
    D_003DD28C = 1;
}

extern u8 D_00630460[];

s32 func_001E6EB0(void) {
    if (D_003DD28C == 0) {
        return 4;
    }
    if (D_002C2108 & 2) {
        func_0010BB10(D_00630510, 0);
        func_0010BB10(D_00630460, 0);
        D_003DD28C = 0;
        return 4;
    }
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/unsplit/file0DDF98", func_001E6F28);

extern s32 D_003DD268;
extern u8 D_00630460[];

void func_001E7228(s32 x) {
    D_003DD28C = 0;
    D_003DD258 = x;
    if (D_003DD268 < x) {
        func_0010BB10(D_00630460, 0);
    }
}

extern u8 D_00630510[];
void func_0010BB10();
s32 func_001E6F28(void);

void func_001E7278(void) {
    func_0010BB10(D_00630510, (s32)func_001E6F28);
}

INCLUDE_ASM("asm/nonmatchings/unsplit/file0DDF98", func_001E72A0);

extern s32 D_003DD260;

s32 func_001E7488(A2Script *arg0) {
    arg0->unk_174[3]++;
    arg0->unk_174[arg0->unk_174[3] + 4] = D_003DD260;
    return 2;
}

INCLUDE_ASM("asm/nonmatchings/unsplit/file0DDF98", func_001E86A0);

INCLUDE_ASM("asm/nonmatchings/unsplit/file0DDF98", func_001E7800);

void func_001E78D8(void) {
    func_0010BB10(D_00630460, 0);
    D_003854E0.unk_3070 &= ~((u64)1 << 53);
}

void func_001E7928(void) {
}

extern u8 D_003DCFF0[];
extern s32 D_006305C0[];
void func_0010F3B8(void *, void *, s32);
void func_001E78D8();
void func_001E7928();

void func_001E7930(void) {
    func_0010EDA0(D_00630460, D_003DCFF0, (s32)func_001E78D8);
    D_006305C0[0] = 1;
    D_006305C0[1] = 2;
    D_006305C0[2] = (s32)func_001E7928;
    func_0010F3B8(D_006305C0, D_00630460, 1);
}

void func_001E7800(void);

s32 func_001E79A0(void) {
    u8 *p;

    D_002C1EA8 |= 0xC;
    func_001E7800();
    p = D_00630460;
    *(s16 *)(p + 4) = 1;
    func_0010BB50(p, (s32)func_001E7930);
    D_003854E0.unk_3070 |= (u64)1 << 53;
    return 6;
}

void func_001E7A10(void) {
    func_0010BB10(D_00630460, 0);
    D_003854E0.unk_3070 &= ~((u64)1 << 53);
}

void func_001E7A60(void) {
}

extern u8 D_003DD030[];
extern s32 D_006305C0[];
void func_0010F3B8(void *, void *, s32);
void func_001E7A10();
void func_001E7A60();

void func_001E7A68(void) {
    func_0010EDA0(D_00630460, D_003DD030, (s32)func_001E7A10);
    D_006305C0[0] = 1;
    D_006305C0[1] = 2;
    D_006305C0[2] = (s32)func_001E7A60;
    func_0010F3B8(D_006305C0, D_00630460, 1);
}

void func_001E7800(void);

s32 func_001E7AD8(void) {
    u8 *p;

    D_002C1EA8 |= 0xC;
    func_001E7800();
    p = D_00630460;
    *(s16 *)(p + 4) = 1;
    func_0010BB50(p, (s32)func_001E7A68);
    D_003854E0.unk_3070 |= (u64)1 << 53;
    return 6;
}

void func_001E7B48(void) {
}

void func_00232AA8(void);

void func_001E7B50(void) {
    func_00232AA8();
    func_0010BB10(D_00630300, 0);
    D_003854E0.unk_3070 &= ~((u64)1 << 53);
}

INCLUDE_ASM("asm/nonmatchings/unsplit/file0DDF98", func_001E7BA8);

extern u8 D_00630460[];
void func_0010BB10();
s32 func_001E7BA8(void);

void func_001E7D58(void) {
    func_0010BB10(D_00630460, (s32)func_001E7BA8);
}

extern s32 D_003DD258;

void func_001E7D80(s32 x) {
    D_003DD258 = x;
}

extern u8 D_003DD070[];
extern s32 D_006305C0[];
void func_0010F3B8(void *, void *, s32);
void func_001E7D58();
void func_001E7D80();

void func_001E7D90(void) {
    func_0010EDA0(D_00630460, D_003DD070, (s32)func_001E7D58);
    D_006305C0[0] = 1;
    D_006305C0[1] = 3;
    D_006305C0[2] = (s32)func_001E7D80;
    func_0010F3B8(D_006305C0, D_00630460, 1);
}

void func_001E4B08(void);

s32 func_001E7E00(void) {
    u8 *p;

    D_002C1EA8 |= 0xC;
    func_001E7800();
    func_001E4B08();
    p = D_00630460;
    *(s16 *)(p + 4) = 1;
    func_0010BB50(p, (s32)func_001E7D90);
    D_003854E0.unk_3070 |= (u64)1 << 53;
    return 6;
}

extern s32 D_006314D4;
void func_0011C7A8(s32, s32, s32, s32, s32, s32);

void func_001E7E78(void) {
    func_0011C7A8(D_006314D4, 0, 0x3000, 0, 0, 0);
}

extern s32 D_002C1364;

s32 func_001E7EA8(A2Script *p) {
    D_006314D4 = p->unk_174[p->unk_174[3] + 4] - 1;
    func_0011C7D8(D_002C1364);
    func_001E7E78();
    p->unk_174[3]--;
    return 2;
}

s32 func_001E7F08(A2Script *p) {
    s32 a, b;

    a = (f32)(p->unk_174[p->unk_174[3] + 3] * 0x3000) / 100.0f;
    b = p->unk_174[p->unk_174[3] + 4] * 8;
    D_006314D4 = p->unk_174[p->unk_174[3] + 2] - 1;
    func_0011C7D8(D_002C1364);
    func_0011C7A8(D_006314D4, 0, a, b, 0, 0);
    p->unk_174[3] -= 3;
    return 2;
}

void func_001E7FE0(void) {
    D_003854E0.unk_3070 &= ~((u64)1 << 56);
}

extern s32 D_006314D0;
extern s32 D_006314D8;
void func_0011EC08(s32, s32, s32, void *);
void func_F20000(void);

s32 func_001E8010(void) {
    if (fm_func_0011E340(0) == 0) {
        func_0011EC08(D_006314D0, (s32)func_F20000, D_006314D8, func_001E7FE0);
        return 4;
    }
    return 0;
}

void func_001E8060(s32 x) {
    D_006314D8 = x;
    if (fm_func_0011E340(0) == 0) {
        func_0011EC08(D_006314D0, (s32)func_F20000, D_006314D8, func_001E7FE0);
        return;
    }
    func_0011ED30(0xC352, func_001E8010);
}

void func_0011EAE0(s32, char *);

s32 func_001E80D0(A2Script *p) {
    char buf[0x100];
    s32 n;

    func_0011EAE0(p->unk_174[p->unk_174[3] + 4], buf);
    func_00120590(buf, (s32)func_F20000, (s32 (*)(void))func_001E8060, 0);
    D_003854E0.unk_3070 |= (u64)1 << 56;
    n = p->unk_174[3];
    D_006314D0 = p->unk_174[n + 3] - 1;
    p->unk_174[3] = n - 2;
    return 2;
}

extern s32 D_006314D0;
extern s32 D_006314D8;
extern s32 D_003D55DC;
void func_0011EC08(s32, s32, s32, void *);

s32 func_001E8178(void) {
    if (fm_func_0011E340(0) != 0) {
        return 0;
    }
    func_0011EC08(D_006314D0, D_003D55DC, D_006314D8, func_001E7FE0);
    return 4;
}

void func_001E81C8(s32 x) {
    D_006314D8 = x;
    if (fm_func_0011E340(0) == 0) {
        func_0011EC08(D_006314D0, D_003D55DC, D_006314D8, func_001E7FE0);
        return;
    }
    func_0011ED30(0xC352, func_001E8178);
}

s32 func_001E8238(A2Script *p) {
    char buf[0x100];
    s32 n;

    func_0011EAE0(p->unk_174[p->unk_174[3] + 4], buf);
    func_00120590(buf, D_003D55DC, (s32 (*)(void))func_001E81C8, 0);
    D_003854E0.unk_3070 |= (u64)1 << 56;
    n = p->unk_174[3];
    D_006314D0 = p->unk_174[n + 3] - 1;
    p->unk_174[3] = n - 2;
    return 2;
}

extern u32 D_0038CD00[];

s32 func_001E82E0(void) {
    return ((s32)(*(u64 *)D_0038CD00 >> 56) & 1) ? 4 : 2;
}

void func_001E8308(void) {
    D_003854E0.unk_3070 &= ~((u64)1 << 51);
}

extern s32 D_006314CC;
extern s32 D_006314DC;
void func_0011EB88(s32, s32, s32, void *);

s32 func_001E8338(void) {
    if (fm_func_0011E340(0) == 0) {
        func_0011EB88(D_006314CC, (s32)func_F20000, D_006314DC, func_001E8308);
        return 4;
    }
    return 0;
}

s32 func_001E8338();

void func_001E8388(s32 x) {
    D_006314DC = x;
    if (fm_func_0011E340(0) == 0) {
        func_0011EB88(D_006314CC, (s32)func_F20000, D_006314DC, func_001E8308);
        return;
    }
    func_0011ED30(0xC352, func_001E8338);
}

void func_0011EA40(s32, char *);

s32 func_001E83F8(A2Script *p) {
    char buf[0x100];
    s32 n;

    func_0011EA40(p->unk_174[p->unk_174[3] + 4], buf);
    func_00120590(buf, (s32)func_F20000, (s32 (*)(void))func_001E8388, 0);
    D_003854E0.unk_3070 |= (u64)1 << 51;
    n = p->unk_174[3];
    D_006314CC = p->unk_174[n + 3] - 1;
    p->unk_174[3] = n - 2;
    return 2;
}

extern s32 D_006314CC;
extern s32 D_006314DC;
void func_0011EB88(s32, s32, s32, void *);

s32 func_001E84A0(void) {
    if (fm_func_0011E340(0) != 0) {
        return 0;
    }
    func_0011EB88(D_006314CC, D_003D55DC, D_006314DC, func_001E8308);
    return 4;
}

void func_001E84F0(s32 x) {
    D_006314DC = x;
    if (fm_func_0011E340(0) == 0) {
        func_0011EB88(D_006314CC, D_003D55DC, D_006314DC, func_001E8308);
        return;
    }
    func_0011ED30(0xC352, func_001E84A0);
}

s32 func_001E8560(A2Script *p) {
    char buf[0x100];
    s32 n;

    func_0011EA40(p->unk_174[p->unk_174[3] + 4], buf);
    func_00120590(buf, D_003D55DC, (s32 (*)(void))func_001E84F0, 0);
    D_003854E0.unk_3070 |= (u64)1 << 51;
    n = p->unk_174[3];
    D_006314CC = p->unk_174[n + 3] - 1;
    p->unk_174[3] = n - 2;
    return 2;
}

s32 func_001E8608(void) {
    return ((s32)(*(u64 *)D_0038CD00 >> 51) & 1) ? 4 : 2;
}

void func_001E8628(void) {
    D_003854E0.unk_3070 &= ~((u64)1 << 57);
}

void func_F20000(void);
void func_0011E7C8(void *, s32);

s32 func_001E8658(void) {
    if (fm_func_0011E340(0) == 0) {
        func_0011E7C8(func_001E8628, (s32)func_F20000);
        return 4;
    }
    return 0;
}

void fm_func_001E86A0(void) {
    if (fm_func_0011E340(0) == 0) {
        func_0011E7C8(func_001E8628, (s32)func_F20000);
        return;
    }
    func_0011ED30(0xC352, func_001E8658);
}

extern s32 D_003D55DC;
void func_0011E7C8(void *, s32);
void func_001E8628(void);

s32 func_001E86E8(void) {
    if (fm_func_0011E340(0) == 0) {
        func_0011E7C8(func_001E8628, D_003D55DC);
        return 4;
    }
    return 0;
}

void func_001E8728(void) {
    if (fm_func_0011E340(0) == 0) {
        func_0011E7C8(func_001E8628, D_003D55DC);
        return;
    }
    func_0011ED30(0xC352, func_001E86E8);
}

void func_0011C7D8(s32);

s32 func_001E8770(void) {
    func_0011C7D8(D_006314D4);
    D_003854E0.unk_3070 |= (u64)1 << 57;
    fm_func_001E86A0();
    return 2;
}

s32 func_001E87B8(void) {
    func_0011C7D8(D_006314D4);
    D_003854E0.unk_3070 |= (u64)1 << 57;
    func_001E8728();
    return 2;
}

void func_0011E9D8(s32, s32, s32, s32);
void func_001E8628();

s32 func_001E8800(A2Script *p) {
    s32 a = (f32)(p->unk_174[p->unk_174[3] + 3] * 0x3000) / 100.0f;
    s32 b = p->unk_174[p->unk_174[3] + 4] * 8;

    if (fm_func_0011E340(0) == 0) {
        func_0011E9D8(a, b, (s32)func_001E8628, (s32)func_F20000);
        D_003854E0.unk_3070 |= (u64)1 << 57;
        p->unk_174[3] -= 2;
        return 2;
    }
    return 4;
}

extern s32 D_003D55DC;

s32 func_001E88E0(A2Script *p) {
    s32 a = (f32)(p->unk_174[p->unk_174[3] + 3] * 0x3000) / 100.0f;
    s32 b = p->unk_174[p->unk_174[3] + 4] * 8;

    if (fm_func_0011E340(0) == 0) {
        func_0011E9D8(a, b, (s32)func_001E8628, D_003D55DC);
        D_003854E0.unk_3070 |= (u64)1 << 57;
        p->unk_174[3] -= 2;
        return 2;
    }
    return 4;
}

s32 func_001E89C0(void) {
    return ((s32)(*(u64 *)D_0038CD00 >> 57) & 1) ? 4 : 2;
}

void func_0011E340();
void func_0011C7D8(s32);

s32 func_001E89E0(void) {
    func_0011E340();
    func_0011C7D8(0);
    func_0011C7D8(1);
    return 2;
}

void func_0011E340();

s32 func_001E8A10(void) {
    func_0011E340();
    return 2;
}

void func_0011E528();

s32 func_001E8A30(void) {
    func_0011E528();
    return 2;
}

INCLUDE_ASM("asm/nonmatchings/unsplit/file0DDF98", func_001E8A50);

void func_0011C7F0(s32);

s32 func_001E8B08(A2Script *p) {
    func_0011C7F0(p->unk_174[p->unk_174[3] + 4] - 1);
    p->unk_174[3]--;
    return 2;
}

extern s32 D_002C58C0;
s32 func_0011C808(s32);

s32 func_001E8B50(A2Script *p) {
    s32 v = p->unk_174[p->unk_174[3] + 4];

    D_002C58C0 |= 0x8000;
    if (func_0011C808(v - 1) == 0) {
        return 4;
    }
    p->unk_174[3]--;
    return 2;
}

s32 func_001E8BC0(u8 *a) {
    *(s32 *)(a + 0x180) -= 4;
    return 2;
}

INCLUDE_ASM("asm/nonmatchings/unsplit/file0DDF98", func_001E8BD8);

extern s32 D_00375BC0;
void func_0011D080(s32, s32);

s32 func_001E8C88(A2Script *p) {
    s32 a = p->unk_174[p->unk_174[3] + 3];
    s32 b = p->unk_174[p->unk_174[3] + 4];

    if (!(D_00375BC0 & 1)) {
        func_0011D080(a, b);
    }
    p->unk_174[3] -= 2;
    return 2;
}

void func_0011D0D8(s32, s32);

s32 func_001E8CF0(A2Script *p) {
    func_0011D0D8(p->unk_174[p->unk_174[3] + 3], p->unk_174[p->unk_174[3] + 4]);
    p->unk_174[3] -= 2;
    return 2;
}

void func_0011D108(s32, s32, s32);

s32 func_001E8D40(A2Script *p) {
    func_0011D108(p->unk_174[p->unk_174[3] + 2], p->unk_174[p->unk_174[3] + 3], p->unk_174[p->unk_174[3] + 4] * 8);
    p->unk_174[3] -= 3;
    return 2;
}

s32 func_001E8DA0(A2Script *s) {
    s32 r; s32 d;
    d = func_0011E368(s->unk_174[s->unk_174[3] + 3], s->unk_174[s->unk_174[3] + 4]); r = 2; if (d != 0) { d = 4; r = d; } return r;
}

void func_0011D350(s32, s32);

s32 func_001E8DE8(A2Script *p) {
    func_0011D350(p->unk_174[p->unk_174[3] + 3], p->unk_174[p->unk_174[3] + 4]);
    p->unk_174[3] -= 2;
    return 2;
}

void func_001E8E38(void) {
    D_003854E0.unk_3070 &= ~((u64)1 << 55);
}

extern s32 D_00631560;
void func_00146BC8(s32);
void func_0011CC20(s32, s32, void *);

s32 func_001E8E68(void) {
    if (fm_func_0011E340(0) == 0) {
        func_00146BC8(-6);
        func_00146BC8(-7);
        D_002C1EA8 |= 0x40000;
        func_0011CC20(-8, D_00631560, func_001E8E38);
        return 4;
    }
    return 0;
}

void func_001E8ED8(s32 a0, s32 a1, s32 x) {
    D_00631560 = x;
    if (fm_func_0011E340(0) == 0) {
        func_00146BC8(-6);
        func_00146BC8(-7);
        D_002C1EA8 |= 0x40000;
        func_0011CC20(-8, D_00631560, func_001E8E38);
        return;
    }
    func_0011ED30(0xC352, func_001E8E68);
}

INCLUDE_ASM("asm/nonmatchings/unsplit/file0DDF98", func_001E8F68);

s32 func_001E9028(void) {
    return ((s32)(*(u64 *)D_0038CD00 >> 55) & 1) ? 4 : 2;
}

void func_00155878(void);

s32 func_001E9048(u8 *p) {
    if (fm_func_0011E340(0) == 0 && func_0011E368(-1, -1) == 0) {
        D_002C1EA8 &= ~0x40000;
        func_00155878();
        *(u64 *)(p + 0x328) |= 0x2000;
        return 6;
    }
    return 4;
}

s32 func_001E90C8(void) {
    return 2;
}

s32 func_001E90D0(u8 *a0) {
    func_0011D588();
    *(s32 *)(a0 + 0x180) = (*(s32 *)(a0 + 0x180) - 1);
    return 2;
}

void func_0011D4B8(s32);

s32 func_001E9108(A2Script *p) {
    func_0011D4B8(p->unk_174[p->unk_174[3] + 4] * 8);
    p->unk_174[3]--;
    return 2;
}

void func_0011C9A0();

s32 func_001E9150(void) {
    func_0011C9A0();
    return 2;
}

void func_0011C9B0();

s32 func_001E9170(void) {
    func_0011C9B0();
    return 2;
}

void func_0011C9B0();
void func_00101628(s32);
void func_0011D448();

s32 func_001E9190(void) {
    func_0011C9B0();
    func_00101628(0);
    func_0011D448();
    return 2;
}

s32 fm_func_0011E340(s32);
void func_001557D0();

s32 func_001E91C0(void) {
    if (fm_func_0011E340(0) == 0) {
        func_001557D0();
        return 2;
    }
    return 4;
}

typedef struct {
    u8 pad[0x180];
    s32 n;
    s32 stk[1];
} A2Stk;
void func_001557B0(s32);

s32 func_001E91F0(A2Stk *p) {
    func_001557B0(p->stk[p->n]);
    p->n--;
    return 2;
}

s32 func_00123558(s32, s32);

s32 func_001E9238(void) {
    s32 r;

    for (r = func_00123558(D_002E26A0[0], 0); r != 0; r = func_00123558(D_002E26A0[0], r)) {
    }
    return 2;
}

s32 func_0011C820();

s32 func_001E9288(void) {
    if (func_0011C820() != 0) {
        return 4;
    }
    return 2;
}

extern u8 D_00631570[];
void func_0010BB10(void *, s32);
void func_001E9650(void);

void func_001E92B8(void) {
    func_0010BB10(D_00631570, 0);
    func_001E9650();
}

extern u8 D_00631570[];
extern u8 D_003DD2F0[];
void func_0010EDA0(void *, void *, s32);
void func_001E92B8(void);

void func_001E92E0(void) {
    func_0010EDA0(D_00631570, D_003DD2F0, (s32)func_001E92B8);
}

INCLUDE_ASM("asm/nonmatchings/unsplit/file0DDF98", func_001E9310);

extern u8 D_00631620[];
void *sceDmaGetChan(int);
void FlushCache(int);
int sceGsSyncPath(int, u16);
int sceDmaSend(void *, void *);

s32 func_001E93C8(void) {
    void *c = sceDmaGetChan(2);

    FlushCache(0);
    sceGsSyncPath(0, 0);
    sceDmaSend(c, D_00631620);
    return 4;
}

INCLUDE_ASM("asm/nonmatchings/unsplit/file0DDF98", func_001E9418);

extern s32 D_003DD310;
extern s32 D_003DD314;

void func_001E9650(void) {
    D_003DD310 = -4;
    D_003DD314 = -2;
}

INCLUDE_ASM("asm/nonmatchings/unsplit/file0DDF98", func_001E9670);

void func_001E97D8(s32 a, s32 b, s32 c, s32 d) {
    s32 *q = (s32 *)D_00631620;
    s32 x0 = (a + 0x700) << 4;
    s32 y0 = (b + 0x740) << 4;
    s32 x1 = (a + c + 0x700) << 4;
    s32 y1 = (b + d + 0x740) << 4;

    q[0x60 / 4] = x0;
    q[0x64 / 4] = y0;
    q[0x80 / 4] = x1;
    q[0x84 / 4] = y0;
    q[0xA0 / 4] = x0;
    q[0xA4 / 4] = y1;
    q[0xC0 / 4] = x1;
    q[0xC4 / 4] = y1;
}

s32 func_001E9830(double x) {
    s32 i = x;
    double d = x - i;
    if (d >= 0.5) {
        i++;
    } else if (d <= -0.5) {
        i--;
    }
    return i;
}

INCLUDE_ASM("asm/nonmatchings/unsplit/file0DDF98", func_001E98D0);

INCLUDE_ASM("asm/nonmatchings/unsplit/file0DDF98", func_001E99E8);

INCLUDE_ASM("asm/nonmatchings/unsplit/file0DDF98", func_001E9B98);

double sqrt(double);
f32 atan2f(f32, f32);

void func_001E9D00(f32 *out, f32 *a, f32 *b, f32 roll) {
    f32 dz = a[2] - b[2];
    f32 dx = a[0] - b[0];

    out[0] = atan2f(-(a[1] - b[1]), sqrt(dz * dz + dx * dx));
    out[1] = atan2f(a[0] - b[0], a[2] - b[2]);
    out[2] = roll;
}

void func_001E9DC8(sceVu0FVECTOR a0, f32 *rot, sceVu0FVECTOR v) {
    sceVu0FMATRIX m;
    sceVu0UnitMatrix(m);
    sceVu0RotMatrixX(m, m, rot[0]);
    sceVu0RotMatrixY(m, m, rot[1]);
    sceVu0RotMatrixZ(m, m, rot[2]);
    sceVu0ApplyMatrix(v, m, v);
    sceVu0AddVector(a0, a0, v);
}

double sqrt(double);

f32 func_001E9E58(f32 *a, f32 *b) {
    f32 dx = a[0] - b[0];
    f32 dy = a[1] - b[1];
    f32 dz = a[2] - b[2];

    return sqrt(dx * dx + dy * dy + dz * dz);
}

double sqrt(double);

f32 func_001E9EC0(f32 *a, f32 *b) {
    f32 dx = a[0] - b[0];
    f32 dz = a[2] - b[2];

    return sqrt(dx * dx + dz * dz);
}

void sceVu0UnitMatrix(f32 (*)[4]);
void sceVu0RotMatrixX(f32 (*)[4], f32 (*)[4], f32);
void sceVu0RotMatrixY(f32 (*)[4], f32 (*)[4], f32);
void sceVu0ApplyMatrix(f32 *, f32 (*)[4], f32 *);

void func_001E9F18(f32 *o, f32 *pos, f32 *rot, f32 dist) {
    f32 m[4][4] __attribute__((aligned(16)));

    o[0] = 0.0f;
    o[1] = 0.0f;
    o[2] = dist;
    o[3] = 1.0f;
    sceVu0UnitMatrix(m);
    sceVu0RotMatrixX(m, m, rot[0]);
    sceVu0RotMatrixY(m, m, rot[1]);
    sceVu0ApplyMatrix(o, m, o);
    o[0] = -o[0];
    o[1] = -o[1];
    o[2] = -o[2];
    o[0] += pos[0];
    o[1] += pos[1];
    o[2] += pos[2];
}

void func_001E9FE8(f32 *d, f32 *s) {
    d[0] = s[0];
    d[1] = s[1];
    d[2] = s[2];
    for (;;) {
        if (d[0] > 3.1415928f) {
            d[0] -= 6.2831855f;
        } else if (d[0] < -3.1415928f) {
            d[0] += 6.2831855f;
        } else {
            break;
        }
    }
    for (;;) {
        if (d[1] > 3.1415928f) {
            d[1] -= 6.2831855f;
        } else if (d[1] < -3.1415928f) {
            d[1] += 6.2831855f;
        } else {
            break;
        }
    }
    for (;;) {
        if (d[2] > 3.1415928f) {
            d[2] -= 6.2831855f;
        } else if (d[2] < -3.1415928f) {
            d[2] += 6.2831855f;
        } else {
            break;
        }
    }
}

INCLUDE_ASM("asm/nonmatchings/unsplit/file0DDF98", func_001EA128);

INCLUDE_ASM("asm/nonmatchings/unsplit/file0DDF98", func_001EA268);

void func_001EA430(void) {
}

s32 func_001EA438(void) {
    D_003854E0.unk_3070 &= ~((u64)1 << 54);
    return 2;
}

s32 func_001EA470(void) {
    D_003854E0.unk_3070 |= (u64)1 << 54;
    return 2;
}

void func_001CCA88(void);
void func_001C5918(void *, s32);
void func_001C4740(s32, s32);
extern s32 D_002B9334;
extern u8 D_003DD320[];
typedef struct {
    u8 pad[0x3070];
    u64 unk_3070;
    u8 pad3078[0x34D0 - 0x3078];
    s32 unk_34D0;
} A2Big34D0;
extern A2Big34D0 D_003854E0_b __asm__("D_003854E0");

void func_001EA498(s32 a0) {
    u8 *o = (u8 *)D_002E26A0[0];

    *(f32 *)(o + 0x60) = 1.0f;
    *(s32 *)(o + 0x64) = 0;
    *(s32 *)o |= 1;
    func_001CCA88();
    D_003854E0_b.unk_34D0 = a0;
    if (!((D_003854E0_b.unk_3070 >> 54) & 1)) {
        D_003854E0_b.unk_3070 |= (u64)1 << 40;
        func_001C5918(D_003DD320, 0);
        D_00375BC0 |= 2;
        D_003854E0_b.unk_3070 &= ~((u64)1 << 59);
    } else {
        func_001C4740(D_002B9334, 0x63);
    }
}

s32 func_00123880(s32);

s32 func_001EA580(A2Script *p) {
    u8 *b = (u8 *)p;
    u8 c;

    *(s32 *)b = p->unk_174[p->unk_174[3] + 4];
    c = b[2];
    if (c == 1) {
        b[2] = 0;
    } else if (c == 0) {
        b[2] = 1;
    }
    *(s32 *)(b + 4) = func_00123880(*(s32 *)b);
    p->unk_174[3]--;
    return 2;
}

INCLUDE_ASM("asm/nonmatchings/unsplit/file0DDF98", func_001EA5F8);

INCLUDE_ASM("asm/nonmatchings/unsplit/file0DDF98", func_001EA658);

typedef struct {
    u64 unk_00 : 8;
    u64 unk_01 : 24;
    s32 unk_04;
    s32 unk_08[2];
    f32 unk_10[4];
} A2Msg;
s32 func_001C4640(A2Msg *);

s32 func_001EA6B8(A2Script *p) {
    A2Msg msg;
    s32 *q = func_001E98D0((s32)(*(u64 *)((u8 *)p + 0x328) >> 5) & 1, p->unk_174[p->unk_174[3] + 4]);

    if (q != NULL) {
        msg.unk_00 = 0xD;
        msg.unk_01 = 0;
        msg.unk_10[3] = 1.0f;
        msg.unk_10[0] = 0.0f;
        msg.unk_10[1] = 0.0f;
        msg.unk_04 = *q;
        msg.unk_10[2] = 0.0f;
        func_001C4640(&msg);
    }
    p->unk_174[3]--;
    return 2;
}

s32 func_001EA760(A2Script *p) {
    A2Msg msg;
    s32 *q = func_001E98D0((s32)(*(u64 *)((u8 *)p + 0x328) >> 5) & 1, p->unk_174[p->unk_174[3] + 4]);

    if (q != NULL) {
        msg.unk_00 = 0xE;
        msg.unk_01 = 0;
        msg.unk_10[3] = 1.0f;
        msg.unk_10[0] = 0.0f;
        msg.unk_10[1] = 0.0f;
        msg.unk_04 = *q;
        msg.unk_10[2] = 0.0f;
        func_001C4640(&msg);
    }
    p->unk_174[3]--;
    return 2;
}

s32 func_001EA808(A2Script *arg0) {
    A2Msg msg;

    msg.unk_00 = 0x23;
    msg.unk_01 = 0;
    msg.unk_04 = *(s32 *)arg0;
    func_001C4640(&msg);
    msg.unk_00 = 0x2A;
    msg.unk_01 = 0;
    msg.unk_04 = *(s32 *)arg0;
    func_001C4640(&msg);
    return 2;
}

s32 func_001EA888(A2Script *arg0) {
    A2Msg msg;

    msg.unk_00 = 0x24;
    msg.unk_01 = 0;
    msg.unk_04 = *(s32 *)arg0;
    func_001C4640(&msg);
    msg.unk_00 = 0x2B;
    msg.unk_01 = 0;
    msg.unk_04 = *(s32 *)arg0;
    func_001C4640(&msg);
    return 2;
}

s32 *func_001E98D0(s32, s32);

s32 func_001EA908(A2Script *p) {
    A2Msg msg;
    s32 *q = func_001E98D0((s32)(*(u64 *)((u8 *)p + 0x328) >> 5) & 1, p->unk_174[p->unk_174[3] + 4]);

    if (q != NULL) {
        msg.unk_00 = 0x23;
        msg.unk_01 = 0;
        msg.unk_04 = *q;
        func_001C4640(&msg);
        msg.unk_00 = 0x2A;
        msg.unk_01 = 0;
        msg.unk_04 = *q;
        func_001C4640(&msg);
    }
    p->unk_174[3]--;
    return 2;
}

s32 func_001EA9C8(A2Script *p) {
    A2Msg msg;
    s32 *q = func_001E98D0((s32)(*(u64 *)((u8 *)p + 0x328) >> 5) & 1, p->unk_174[p->unk_174[3] + 4]);

    if (q != NULL) {
        msg.unk_00 = 0x24;
        msg.unk_01 = 0;
        msg.unk_04 = *q;
        func_001C4640(&msg);
        msg.unk_00 = 0x2B;
        msg.unk_01 = 0;
        msg.unk_04 = *q;
        func_001C4640(&msg);
    }
    p->unk_174[3]--;
    return 2;
}

u8 *func_001234A0(u8 *);
s32 func_001239D8(s32);

s32 func_001EAA88(void) {
    A2Msg msg;
    u8 *p;

    for (p = func_001234A0(NULL); p != NULL; p = func_001234A0(p)) {
        if (func_001239D8(*(s32 *)(p + 4)) >= 0 && func_001239D8(*(s32 *)(p + 4)) < 10 && p[6] == 3) {
            msg.unk_00 = 0x23;
            msg.unk_01 = 0;
            msg.unk_04 = *(s32 *)(p + 4);
            func_001C4640(&msg);
            msg.unk_00 = 0x2A;
            msg.unk_01 = 0;
            msg.unk_04 = *(s32 *)(p + 4);
            func_001C4640(&msg);
        }
    }
    return 2;
}

s32 func_001EAB78(void) {
    A2Msg msg;
    u8 *p;

    for (p = func_001234A0(NULL); p != NULL; p = func_001234A0(p)) {
        if (func_001239D8(*(s32 *)(p + 4)) >= 0 && func_001239D8(*(s32 *)(p + 4)) < 10 && p[6] == 3) {
            msg.unk_00 = 0x24;
            msg.unk_01 = 0;
            msg.unk_04 = *(s32 *)(p + 4);
            func_001C4640(&msg);
            msg.unk_00 = 0x2B;
            msg.unk_01 = 0;
            msg.unk_04 = *(s32 *)(p + 4);
            func_001C4640(&msg);
        }
    }
    return 2;
}

typedef struct {
    u8 b[10];
} A2Bytes10;
extern A2Bytes10 D_004908E0;

void func_001EAC68(void) {
    A2Bytes10 buf = D_004908E0;
    u8 *d = (u8 *)func_0022F768(1) + 0xAD1;
    u32 i;

    for (i = 0; i < 10; i++) {
        *d++ = buf.b[i];
    }
}

INCLUDE_ASM("asm/nonmatchings/unsplit/file0DDF98", func_001EBEB0);

void *func_0022F768(s32);

u8 *func_001EAFD8(void) {
    return (u8 *)func_0022F768(1) + 0xAD1;
}

void *func_0022F768(s32);

u8 *func_001EAFF8(void) {
    return (u8 *)func_0022F768(1) + 0x904;
}

void *func_0022F768(s32);

u8 *func_001EB018(void) {
    return (u8 *)func_0022F768(1) + 0x909;
}

typedef struct {
    u8 pad[0xAE3];
    u8 bits[1];
} A2BitsAE3;

s32 func_001EB038(s32 i) {
    s32 idx = i / 8;
    s32 sh = 7 - i % 8;
    A2BitsAE3 *q = func_0022F768(1);

    return (q->bits[idx] >> sh) & 1;
}

void func_001EB0A0(s32 k, s32 set) {
    s32 q = k / 8;
    s32 b = 7 - (k - q * 8);
    s32 f = (s32)func_0022F768(1);

    if (set) {
        *(u8 *)(q + f + 0xAE3) |= 1 << b;
    } else {
        *(u8 *)(q + f + 0xAE3) &= ~(1 << b);
    }
}

s32 func_001EB140(A2Script *p) {
    s32 k = p->unk_174[p->unk_174[3] + 4];
    s32 q = k / 8;
    s32 b = 7 - (k - q * 8);

    *(u8 *)(q + (s32)func_0022F768(1) + 0xAE3) |= 1 << b;
    p->unk_174[3]--;
    return 2;
}

s32 func_001EB1D8(A2Script *p) {
    s32 k = p->unk_174[p->unk_174[3] + 4];
    s32 q = k / 8;
    s32 b = 7 - (k - q * 8);

    *(u8 *)(q + (s32)func_0022F768(1) + 0xAE3) &= ~(1 << b);
    p->unk_174[3]--;
    return 2;
}

s32 func_001EB278(A2Script *p) {
    s32 k = p->unk_174[p->unk_174[3] + 4];
    s32 q = k / 8;
    s32 b = 7 - (k - q * 8);
    s32 f = (s32)func_0022F768(1);

    p->unk_174[p->unk_174[3] + 4] = (*(u8 *)(q + f + 0xAE3) >> b) & 1;
    return 2;
}

typedef struct {
    u8 pad[0xB03];
    u8 bits[1];
} A2BitsB03;

s32 func_001EB318(s32 i) {
    s32 idx = i / 8;
    s32 sh = 7 - i % 8;
    A2BitsB03 *q = func_0022F768(1);

    return (q->bits[idx] >> sh) & 1;
}

s32 func_001EB380(A2Script *p) {
    s32 k = p->unk_174[p->unk_174[3] + 4];
    s32 q = k / 8;
    s32 b = 7 - (k - q * 8);

    *(u8 *)(q + (s32)func_0022F768(1) + 0xB03) |= 1 << b;
    p->unk_174[3]--;
    return 2;
}

void func_001EB418(s32 k, s32 set) {
    s32 q = k / 8;
    s32 b = 7 - (k - q * 8);
    s32 f = (s32)func_0022F768(1);

    if (set) {
        *(u8 *)(q + f + 0xB03) |= 1 << b;
    } else {
        *(u8 *)(q + f + 0xB03) &= ~(1 << b);
    }
}

s32 func_001EB4B8(A2Script *p) {
    s32 k = p->unk_174[p->unk_174[3] + 4];
    s32 q = k / 8;
    s32 b = 7 - (k - q * 8);
    s32 f = (s32)func_0022F768(1);

    p->unk_174[p->unk_174[3] + 4] = (*(u8 *)(q + f + 0xB03) >> b) & 1;
    return 2;
}

s32 func_001EB558(A2Script *p) {
    s32 n = 0;
    s32 k;
    A2BitsB03 *f = func_0022F768(1);

    for (k = 0; k < 100; k++) {
        s32 q = k / 8;
        s32 b = 7 - (k - q * 8);
        n += (f->bits[q] >> b) & 1;
    }
    p->unk_174[3]++;
    p->unk_174[p->unk_174[3] + 4] = n;
    return 2;
}

typedef struct {
    u8 pad[0xB14];
    s32 tbl[1][5];
} A2ObjB14;

s32 func_001EB5F0(s32 a, s32 b) {
    return ((A2ObjB14 *)func_0022F768(1))->tbl[a][b];
}

void func_001EB640(s32 a, s32 b, s32 v) {
    ((A2ObjB14 *)func_0022F768(1))->tbl[a][b] = v;
}

typedef struct {
    u8 pad[0xB10];
    u32 t[1][5];
} A2RankB698;

s32 func_001EB698(A2Script *s) {
    s32 a = s->unk_174[s->unk_174[3] + 2];
    s32 d = s->unk_174[s->unk_174[3] + 3];
    u32 v = s->unk_174[s->unk_174[3] + 4];
    A2RankB698 *r = (A2RankB698 *)((u8 *)func_0022F768(1) + 4);
    s32 i, j;

    for (i = 0; i < 5; i++) {
        u32 e = r->t[a][i];
        if (e == -1 || (d == 0 && e < v) || (d == 1 && v < e)) {
            for (j = 4; i < j; j--) {
                r->t[a][j] = r->t[a][j - 1];
            }
            r->t[a][i] = v;
            break;
        }
    }
    s->unk_174[3] -= 3;
    return 2;
}

INCLUDE_ASM("asm/nonmatchings/unsplit/file0DDF98", func_001EB7B0);

s32 func_001EB910(A2Script *p) {
    s32 i = p->unk_174[p->unk_174[3] + 3];
    s32 j = p->unk_174[p->unk_174[3] + 4] - 1;
    s32 *f = func_0022F768(1);
    p->unk_174[3]--;
    p->unk_174[p->unk_174[3] + 4] = f[i * 5 + j + 0x2C5];
    return 2;
}

typedef struct {
    u8 pad[0xD94];
    u32 bits[1];
} A2ObjD94;

s32 func_001EB9A8(s32 a, s32 b) {
    s32 sh = 31 - b;
    A2ObjD94 *q = func_0022F768(1);

    return (q->bits[a] >> sh) & 1;
}

void func_001EB9F8(s32 a, s32 b, s32 on) {
    s32 sh = 31 - b;
    A2ObjD94 *q = func_0022F768(1);

    if (on) {
        q->bits[a] |= 1 << sh;
    } else {
        q->bits[a] &= ~(1 << sh);
    }
}

s32 func_001EBA80(A2Script *p) {
    s32 i = p->unk_174[p->unk_174[3] + 3];
    s32 b = 0x20 - p->unk_174[p->unk_174[3] + 4];

    ((s32 *)func_0022F768(1))[i + 0x365] |= 1 << b;
    p->unk_174[3] -= 2;
    return 2;
}

s32 func_001EBB10(A2Script *p) {
    s32 i = p->unk_174[p->unk_174[3] + 3];
    s32 b = 0x20 - p->unk_174[p->unk_174[3] + 4];

    ((s32 *)func_0022F768(1))[i + 0x365] &= ~(1 << b);
    p->unk_174[3] -= 2;
    return 2;
}

s32 func_001EBBA0(A2Script *p) {
    s32 i = p->unk_174[p->unk_174[3] + 3];
    s32 b = 0x20 - p->unk_174[p->unk_174[3] + 4];
    u32 *f = func_0022F768(1);

    p->unk_174[3]--;
    p->unk_174[p->unk_174[3] + 4] = (f[i + 0x365] >> b) & 1;
    return 2;
}

typedef struct {
    u8 pad[0xDC0];
    u8 bits[1];
} A2BitsDC0;

s32 func_001EBC38(s32 i) {
    s32 idx = i / 8;
    s32 sh = 7 - i % 8;
    A2BitsDC0 *q = func_0022F768(1);

    return (q->bits[idx] >> sh) & 1;
}

INCLUDE_ASM("asm/nonmatchings/unsplit/file0DDF98", func_001EBCA0);

s32 func_001EBD48(A2Script *p) {
    s32 k = p->unk_174[p->unk_174[3] + 4];
    s32 q = k / 8;
    s32 b = 7 - (k - q * 8);

    q += 0xDC0;
    ((u8 *)func_0022F768(1))[q] |= 1 << b;
    p->unk_174[3]--;
    return 2;
}

s32 func_001EBDE0(A2Script *p) {
    s32 k = p->unk_174[p->unk_174[3] + 4];
    s32 q = k / 8;
    s32 b = 7 - (k - q * 8);
    s32 f = (s32)func_0022F768(1);

    p->unk_174[p->unk_174[3] + 4] = (*(u8 *)(q + f + 0xDC0) >> b) & 1;
    return 2;
}

typedef struct {
    u8 pad[0xDC4];
    u32 unk_DC4;
} A2Obj22F768;
void *func_0022F768(s32);

s32 func_001EBE80(void) {
    return ((A2Obj22F768 *)func_0022F768(1))->unk_DC4 & 1;
}

void *func_0022F768(s32);

s32 func_001EBEA8(void) {
    return (((A2Obj22F768 *)func_0022F768(1))->unk_DC4 >> 2) & 1;
}

void func_001EBED0(s32 a) {
    A2Obj22F768 *p = func_0022F768(1);
    p->unk_DC4 = (p->unk_DC4 & ~4) | ((a & 1) << 2);
}

s32 func_001EBF18(void) {
    ((A2Obj22F768 *)func_0022F768(1))->unk_DC4 |= 4;
    return 2;
}

s32 func_001EBF48(A2Script *p) {
    A2Obj22F768 *q = func_0022F768(1);

    p->unk_174[3]++;
    p->unk_174[p->unk_174[3] + 4] = q->unk_DC4 & 1;
    return 2;
}

s32 func_001EBF98(void) {
    ((A2Obj22F768 *)func_0022F768(1))->unk_DC4 |= 1;
    return 2;
}

void *func_0022F768(s32);

s32 func_001EBFC8(void) {
    return (((A2Obj22F768 *)func_0022F768(1))->unk_DC4 >> 1) & 1;
}

s32 func_001EBFF0(A2Script *p) {
    A2Obj22F768 *q = func_0022F768(1);

    p->unk_174[3]++;
    p->unk_174[p->unk_174[3] + 4] = (q->unk_DC4 >> 1) & 1;
    return 2;
}

s32 func_001EC040(A2Script *p) {
    A2Obj22F768 *q = func_0022F768(1);

    if (p->unk_174[p->unk_174[3] + 4]) {
        q->unk_DC4 |= 2;
    } else {
        q->unk_DC4 &= ~2;
    }
    p->unk_174[3]--;
    return 2;
}

void *func_0022F768(s32);

void func_001EC0B0(void) {
    ((A2Obj22F768 *)func_0022F768(1))->unk_DC4 |= 2;
}

typedef struct {
    u8 pad[0xAD0];
    u32 flags;
} A2FlagsAD0s;

s32 func_001EC0D8(A2Stk *p) {
    A2FlagsAD0s *q = func_0022F768(1);

    switch (p->stk[p->n]) {
    case 0:
        q->flags |= 1;
        break;
    case 1:
        q->flags |= 2;
        break;
    case 2:
        q->flags |= 4;
        break;
    case 3:
        q->flags |= 8;
        break;
    }
    p->n--;
    return 2;
}

typedef struct {
    u8 pad[0xAD0];
    u32 flags;
} A2FlagsAD0;

s32 func_001EC1A0(A2Stk *p) {
    A2FlagsAD0 *q = func_0022F768(1);

    switch (p->stk[p->n]) {
    case 0:
        p->stk[p->n] = *(u8 *)&q->flags & 1;
        break;
    case 1:
        p->stk[p->n] = (q->flags >> 1) & 1;
        break;
    case 2:
        p->stk[p->n] = (q->flags >> 2) & 1;
        break;
    case 3:
        p->stk[p->n] = (q->flags >> 3) & 1;
        break;
    }
    return 2;
}

typedef struct {
    u8 pad[0xDC8];
    u8 bits[1];
} A2BitsDC8;

s32 func_001EC258(s32 i) {
    s32 idx = i / 8;
    s32 sh = 7 - i % 8;
    A2BitsDC8 *q = func_0022F768(1);

    return (q->bits[idx] >> sh) & 1;
}

void func_001EC2C0(s32 k, s32 set) {
    s32 q = k / 8;
    s32 b = 7 - (k - q * 8);
    s32 f = (s32)func_0022F768(1);

    if (set) {
        *(u8 *)(q + f + 0xDC8) |= 1 << b;
    } else {
        *(u8 *)(q + f + 0xDC8) &= ~(1 << b);
    }
}

void *func_0022F768(s32);

u8 func_001EC360(void) {
    return ((u8 *)func_0022F768(1))[0xDD0];
}

void func_001EC380(s32 x) {
    ((u8 *)func_0022F768(1))[0xDD0] = x;
}

s32 func_001EC3B0(A2Script *p) {
    u8 *q = func_0022F768(1);

    p->unk_174[3]++;
    p->unk_174[p->unk_174[3] + 4] = q[0xDD0];
    return 2;
}

s32 func_001EC3F8(A2Script *p) {
    A2Obj22F768 *q = func_0022F768(1);

    if (p->unk_174[p->unk_174[3] + 4]) {
        q->unk_DC4 |= 8;
    } else {
        q->unk_DC4 &= ~8;
    }
    p->unk_174[3]--;
    return 2;
}

s32 func_001EC468(A2Script *p) {
    A2Obj22F768 *q = func_0022F768(1);

    p->unk_174[3]++;
    p->unk_174[p->unk_174[3] + 4] = (q->unk_DC4 >> 3) & 1;
    return 2;
}

void *func_0022F768(s32);

void func_001EC4B8(void) {
    ((A2Obj22F768 *)func_0022F768(1))->unk_DC4 |= 8;
}

void func_001EC4E0(void) {
    ((A2Obj22F768 *)func_0022F768(1))->unk_DC4 &= ~8;
}

void *func_0022F768(s32);

s32 func_001EC510(void) {
    return (((A2Obj22F768 *)func_0022F768(1))->unk_DC4 >> 3) & 1;
}

s32 func_001EC538(s32 i) {
    return (*(u32 *)((u8 *)func_0022F768(1) + 0xDD4) >> (31 - i)) & 1;
}

void func_001ED6F0(s32 s, s32 on) {
    u8 *q = func_0022F768(1);

    if (on) {
        *(u32 *)(q + 0xDD4) |= 1 << (31 - s);
    } else {
        *(u32 *)(q + 0xDD4) &= ~(1 << (31 - s));
    }
}

s32 func_001EC5D8(s32 i) {
    return (((s8 *)func_0022F768(2))[0x1B] >> i) & 1;
}

void func_001EC610(s32 s, s32 on) {
    u8 *q = func_0022F768(2);

    if (on) {
        q[0x1B] |= 1 << s;
    } else {
        q[0x1B] &= ~(1 << s);
    }
}

extern A2Bytes10 D_00490900;
void func_001BA2A8(s32, u8 *);

s32 func_001EC678(void) {
    A2Bytes10 buf = D_00490900;
    u8 *q = func_0022F768(1);
    u32 i;

    for (i = 0; i < 10; i++) {
        q[0xAD1 + i] = buf.b[i];
    }
    func_001BA2A8(0, q + 0xAD1);
    return 2;
}

INCLUDE_ASM("asm/nonmatchings/unsplit/file0DDF98", func_001EC6F8);

INCLUDE_ASM("asm/nonmatchings/unsplit/file0DDF98", func_001EC758);
