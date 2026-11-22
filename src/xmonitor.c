#include "common.h"
#include "eestruct.h"

typedef struct {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
    s32 unk10;
} MonitorSub;

typedef struct {
    u8 pad0[0x60];
    s32 unk60;
    MonitorSub sub[3];
} Monitor;

typedef struct {
    /* 0x00 */ s32 time;
    /* 0x04 */ u8 unk_04[0xC];
    /* 0x10 */ f32 col[4];
} MonitorKey; // size = 0x20

typedef struct {
    /* 0x00 */ s32 time;
    /* 0x04 */ u8 unk_04[0xC];
    /* 0x10 */ f32 col[4][4];
} MonitorKey50; // size = 0x50

extern char D_00491848[]; // "ttlib/ui.c"
extern char D_00491858[];
void __assert(const char* file, int line, const char* expr);

void func_00246B50(Monitor* m, s32 dt) {
    MonitorSub* s;

    if ((*(u64*)&m->unk60 & 0xA) == 0xA) {
        s = &m->sub[0];
        if (s == NULL) {
            __assert(D_00491848, 14, D_00491858);
        }
        if (s->unk4 < s->unk8 - 1) {
            s->unk0 += dt;
            do {
                s32 t = ((MonitorKey*)s->unkC)[s->unk4].time;

                if (s->unk0 < t) {
                    return;
                }
                s->unk0 -= t;
                s->unk4++;
            } while (s->unk4 != s->unk8 - 1);
            m->sub[0].unk10 |= 4;
        }
    }
}

void func_00246C28(Monitor* m) {
    m->unk60 |= 8;
    m->sub[0].unk10 |= 2;
}

void func_00246C48(Monitor* m) {
    m->sub[0].unk10 = 0;
    m->unk60 &= ~8;
}

void func_00246C60(Monitor* m) {
    MonitorSub* s = &m->sub[0];
    s->unk4 = 0;
    s->unk0 = 0;
    s->unk10 &= ~4;
}

void func_00246C80(Monitor* m, s32* out) {
    MonitorSub* s = &m->sub[0];
    MonitorKey* k;
    f32 r;
    s32 i;

    if (s->unk4 < s->unk8 - 1) {
        k = (MonitorKey*)(s->unk4 * 32 + s->unkC);
        r = (f32)s->unk0 / (f32)k->time;
        for (i = 0; i < 4; i++) {
            out[i] = k->col[i] + (k[1].col[i] - k->col[i]) * r;
        }
    } else {
        MonitorKey* e = &((MonitorKey*)s->unkC)[s->unk4];

        for (i = 0; i < 4; i++) {
            s32* o = &out[i];

            *o = e->col[i];
        }
    }
}

s32 func_00246D60(Monitor* m) {
    return m->sub[0].unk10;
}

void func_00246D68(Monitor* m, s32 dt) {
    MonitorSub* s;

    if ((*(u64*)&m->unk60 & 0xC0) == 0xC0) {
        s = &m->sub[1];
        if (s == NULL) {
            __assert(D_00491848, 100, D_00491858);
        }
        if (s->unk4 < s->unk8 - 1) {
            s->unk0 += dt;
            while (s->unk0 >= ((MonitorKey50*)s->unkC)[s->unk4].time) {
                s->unk0 -= ((MonitorKey50*)s->unkC)[s->unk4].time;
                s->unk4++;
                if (s->unk4 == s->unk8 - 1) {
                    m->sub[1].unk10 |= 4;
                    break;
                }
            }
        }
    }
}

void func_00246E80(Monitor* m) {
    MonitorSub* s = &m->sub[1];
    s->unk4 = 0;
    s->unk0 = 0;
    s->unk10 &= ~4;
}

void func_00246EA0(Monitor* m, s32 (*out)[4]) {
    MonitorSub* s = &m->sub[1];
    MonitorKey50* k;
    f32 r;
    s32 i;
    s32 j;

    if (s == NULL) {
        __assert(D_00491848, 0x89, D_00491858);
    }
    if (s->unk4 < s->unk8 - 1) {
        k = (MonitorKey50*)(s->unk4 * 80 + s->unkC);
        r = (f32)s->unk0 / (f32)k->time;
        for (i = 0; i < 4; i++) {
            for (j = 0; j < 4; j++) {
                out[i][j] = k->col[i][j] + (k[1].col[i][j] - k->col[i][j]) * r;
            }
        }
    } else {
        k = &((MonitorKey50*)s->unkC)[s->unk4];
        for (i = 0; i < 4; i++) {
            for (j = 0; j < 4; j++) {
                out[i][j] = k->col[i][j];
            }
        }
    }
}

void func_00246FF0(Monitor* m) {
    m->unk60 |= 0x80;
    m->sub[1].unk10 |= 2;
}

void func_00247010(Monitor* m) {
    m->sub[1].unk10 = 0;
    m->unk60 &= ~0x80;
}

s32 func_00247028(Monitor* m) {
    return m->sub[1].unk10;
}

void func_00247030(Monitor* m, s32 dt) {
    MonitorSub* s;

    if ((*(u64*)&m->unk60 & 0x14) == 0x14) {
        s = &m->sub[2];
        if (s == NULL) {
            __assert(D_00491848, 199, D_00491858);
        }
        if (s->unk4 < s->unk8 - 1) {
            s->unk0 += dt;
            do {
                s32 t = ((MonitorKey*)s->unkC)[s->unk4].time;

                if (s->unk0 < t) {
                    return;
                }
                s->unk0 -= t;
                s->unk4++;
            } while (s->unk4 != s->unk8 - 1);
            m->sub[2].unk10 |= 4;
        }
    }
}

void func_00247108(Monitor* m) {
    MonitorSub* s = &m->sub[2];
    s->unk4 = 0;
    s->unk0 = 0;
    s->unk10 &= ~4;
}

void func_00247128(Monitor* m, s32* out) {
    MonitorSub* s = &m->sub[2];
    MonitorKey* k;
    f32 r;
    s32 i;
    f32 a[4];
    f32 b[4];

    if (s->unk4 < s->unk8 - 1) {
        k = (MonitorKey*)(s->unk4 * 32 + s->unkC);
        r = (f32)s->unk0 / (f32)k->time;
        for (i = 0; i < 4; i++) {
            a[i] = k->col[i];
            b[i] = k[1].col[i];
            out[i] = a[i] + (b[i] - a[i]) * r;
        }
    } else {
        MonitorKey* e = &((MonitorKey*)s->unkC)[s->unk4];

        for (i = 0; i < 4; i++) {
            s32* o = &out[i];

            *o = e->col[i];
        }
    }
}

void func_00247218(Monitor* m) {
    m->unk60 |= 0x10;
    m->sub[2].unk10 |= 2;
}

void func_00247238(Monitor* m) {
    m->sub[2].unk10 = 0;
    m->unk60 &= ~0x10;
}

s32 func_00247250(Monitor* m) {
    return m->sub[2].unk10;
}

INCLUDE_ASM("asm/nonmatchings/xmonitor", func_00247258);

void func_00247258(sceGsTex0* tex, s32 arg1, u64 arg2);

void func_002475E8(s32 arg0, sceGsTex0* tex, u64* arg2) {
    func_00247258(tex, arg0, arg2[3]);
    tex->CSA = 0;
    tex->CLD = 1;
    tex->PSM = 0x13;
}

typedef struct {
    u8 pad0[8];
    s32 unk8;
    u32 unkC;
    s32 unk10;
    s32 pad14;
    s32 unk18;
    s32 pad1C;
    s32 unk20;
} MonitorFile;
typedef struct {
    Monitor m;
    u8 pad[0x20];
} MonitorEntry;
extern char D_00491860[];

void func_00247668(MonitorFile* f) {
    MonitorEntry* e;
    u8* b0;
    u8* b1;
    u8* b2;
    s32 n;
    s32 i;

    if ((u32)f & 0xF) {
        __assert(D_00491848, 0x20C, D_00491860);
    }
    n = f->unkC / sizeof(MonitorEntry);
    i = f->unkC / sizeof(MonitorKey50); // unused; leaves a dead `li 0x50`
    e = (MonitorEntry*)((u8*)f + f->unk8);
    b0 = (u8*)f + f->unk10;
    b1 = (u8*)f + f->unk18;
    b2 = (u8*)f + f->unk20;
    for (i = 0; i < n; i++, e++) {
        s32 fl = e->m.unk60;

        if (fl & 2) {
            if (e->m.sub[0].unkC < 0x100000) {
                e->m.sub[0].unkC = (s32)(b0 + e->m.sub[0].unkC * 0x20);
            }
        }
        if (fl & 0x40) {
            if (e->m.sub[1].unkC < 0x100000) {
                e->m.sub[1].unkC = (s32)(b1 + e->m.sub[1].unkC * 0x50);
            }
        }
        if (fl & 4) {
            if (e->m.sub[2].unkC < 0x100000) {
                e->m.sub[2].unkC = (s32)(b2 + e->m.sub[2].unkC * 0x20);
            }
        }
    }
}
