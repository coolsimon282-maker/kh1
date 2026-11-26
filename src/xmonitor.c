/**
 * Part of ttlib/ui.c (the assert file name): UI parts with three key-frame tracks (colour, four corner colours,
 * rectangle), sprite packet building, and relocating a UI file. Struct Monitor is a UI part.
 */
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

// Advances the part's colour key track (track 0, flags 0xA) by dt; sets "ended" (4) at the last key.
void UiPart_StepColorAnim(Monitor* m, s32 dt) {
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

// Turns the colour track on (flags 8, track state 2).
void UiPart_StartColorAnim(Monitor* m) {
    m->unk60 |= 8;
    m->sub[0].unk10 |= 2;
}

// Turns the colour track off.
void UiPart_StopColorAnim(Monitor* m) {
    m->sub[0].unk10 = 0;
    m->unk60 &= ~8;
}

// Rewinds the colour track to its first key.
void UiPart_RewindColorAnim(Monitor* m) {
    MonitorSub* s = &m->sub[0];
    s->unk4 = 0;
    s->unk0 = 0;
    s->unk10 &= ~4;
}

// Colour of the colour track now (linear between the current and next key).
void UiPart_GetColor(Monitor* m, s32* out) {
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

// State of the colour track (2 running, 4 ended).
s32 UiPart_GetColorAnimState(Monitor* m) {
    return m->sub[0].unk10;
}

// Advances the four-corner colour track (track 1, flags 0xC0) by dt.
void UiPart_StepGradientAnim(Monitor* m, s32 dt) {
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

// Rewinds the four-corner colour track.
void UiPart_RewindGradientAnim(Monitor* m) {
    MonitorSub* s = &m->sub[1];
    s->unk4 = 0;
    s->unk0 = 0;
    s->unk10 &= ~4;
}

// The four corner colours of track 1 now (interpolated).
void UiPart_GetGradient(Monitor* m, s32 (*out)[4]) {
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

// Turns the four-corner colour track on.
void UiPart_StartGradientAnim(Monitor* m) {
    m->unk60 |= 0x80;
    m->sub[1].unk10 |= 2;
}

// Turns the four-corner colour track off.
void UiPart_StopGradientAnim(Monitor* m) {
    m->sub[1].unk10 = 0;
    m->unk60 &= ~0x80;
}

// State of the four-corner colour track.
s32 UiPart_GetGradientAnimState(Monitor* m) {
    return m->sub[1].unk10;
}

// Advances the rectangle track (track 2, flags 0x14) by dt.
void UiPart_StepRectAnim(Monitor* m, s32 dt) {
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

// Rewinds the rectangle track.
void UiPart_RewindRectAnim(Monitor* m) {
    MonitorSub* s = &m->sub[2];
    s->unk4 = 0;
    s->unk0 = 0;
    s->unk10 &= ~4;
}

// Rectangle (x, y, w, h) of track 2 now (interpolated).
void UiPart_GetRect(Monitor* m, s32* out) {
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

// Turns the rectangle track on.
void UiPart_StartRectAnim(Monitor* m) {
    m->unk60 |= 0x10;
    m->sub[2].unk10 |= 2;
}

// Turns the rectangle track off.
void UiPart_StopRectAnim(Monitor* m) {
    m->sub[2].unk10 = 0;
    m->unk60 &= ~0x10;
}

// State of the rectangle track.
s32 UiPart_GetRectAnimState(Monitor* m) {
    return m->sub[2].unk10;
}

void UiPart_BuildSprite(sceGsTex0* tex, s32 arg1, u64 arg2);

typedef struct {
    /* 0x00 */ s32 x;
    /* 0x04 */ s32 y;
    /* 0x08 */ s32 w;
    /* 0x0C */ s32 h;
    /* 0x10 */ s32 u0;
    /* 0x14 */ s32 v0;
    /* 0x18 */ s32 u1;
    /* 0x1C */ s32 v1;
    /* 0x20 */ s32 col[4][4];
    /* 0x60 */ s32 flags;
} MonitorG;

typedef struct {
    /* 0x00 */ s32 u;
    /* 0x04 */ s32 v;
    /* 0x08 */ s32 pad[2];
} MonitorUV;

typedef struct {
    /* 0x00 */ s32 x;
    /* 0x04 */ s32 y;
    /* 0x08 */ s32 z;
    /* 0x0C */ s32 w;
} MonitorXYZ;

typedef struct {
    /* 0x00 */ u64 tag0;
    /* 0x08 */ u64 reg0;
    /* 0x10 */ u64 tag1;
    /* 0x18 */ u64 reg1;
    /* 0x20 */ MonitorUV uv[4];
    /* 0x60 */ s32 col[4][4];
    /* 0xA0 */ MonitorXYZ xyz[4];
} MonitorPkt;

static inline void MonitorSetXYZ(MonitorPkt* o, s32 x, s32 y, s32 w, s32 h) {
    s32 x0 = (x << 4) + 0x7000;
    s32 y0 = (y << 4) + 0x7400;
    s32 y1 = ((y + h) << 4) + 0x7400;
    s32 x1 = ((x + w) << 4) + 0x7000;

    o->xyz[0].x = x0;
    o->xyz[0].y = y0;
    o->xyz[0].z = -0x100;
    o->xyz[0].w = 0;
    o->xyz[1].x = x0;
    o->xyz[1].y = y1;
    o->xyz[1].z = -0x100;
    o->xyz[1].w = 0;
    o->xyz[2].x = x1;
    o->xyz[2].y = y0;
    o->xyz[2].z = -0x100;
    o->xyz[2].w = 0;
    o->xyz[3].x = x1;
    o->xyz[3].y = y1;
    o->xyz[3].z = -0x100;
    o->xyz[3].w = 0;
}

// Fills a sprite packet (colours from the tracks or the part, XYZ from the rectangle, UV with half-texel offsets) for part arg1.
void UiPart_BuildSprite(sceGsTex0* tex, s32 arg1, u64 arg2) {
    MonitorPkt* o = (MonitorPkt*)tex;
    MonitorG* m = (MonitorG*)arg1;
    s32 c[4];
    s32 r[4];
    s32 cm[4][4];
    s32 i;
    s32 j;
    u64 fl;

    o->tag0 = arg2;
    o->reg0 = 6;
    o->tag1 = arg2;
    o->reg1 = 6;
    fl = *(u64*)&m->flags;
    if ((fl & 0xA) == 0xA) {
        UiPart_GetColor((Monitor*)m, c);
        for (i = 0; i < 4; i++) {
            for (j = 0; j < 4; j++) {
                o->col[i][j] = c[j];
            }
        }
    } else if ((fl & 0xC0) == 0xC0) {
        UiPart_GetGradient((Monitor*)m, cm);
        for (i = 0; i < 4; i++) {
            for (j = 0; j < 4; j++) {
                o->col[i][j] = cm[i][j];
            }
        }
    } else if (m->flags & 0x20) {
        for (i = 0; i < 4; i++) {
            for (j = 0; j < 4; j++) {
                o->col[i][j] = m->col[i][j];
            }
        }
    } else {
        for (i = 0; i < 4; i++) {
            for (j = 0; j < 4; j++) {
                o->col[i][j] = m->col[0][j];
            }
        }
    }
    if ((*(u64*)&m->flags & 0x14) == 0x14) {
        UiPart_GetRect((Monitor*)m, r);
        MonitorSetXYZ(o, r[0], r[1], r[2], r[3]);
    } else {
        MonitorSetXYZ(o, m->x, m->y, m->w, m->h);
    }
    if (m->u0 < m->u1) {
        o->uv[0].u = (m->u0 << 4) + 8;
        o->uv[1].u = (m->u0 << 4) + 8;
        o->uv[2].u = (m->u1 << 4) + 0x18;
        o->uv[3].u = (m->u1 << 4) + 0x18;
    } else {
        o->uv[0].u = (m->u0 << 4) + 8;
        o->uv[1].u = (m->u0 << 4) + 8;
        o->uv[2].u = (m->u1 << 4) - 8;
        o->uv[3].u = (m->u1 << 4) - 8;
    }
    if (m->v0 < m->v1) {
        o->uv[0].v = (m->v0 << 4) + 8;
        o->uv[1].v = (m->v1 << 4) + 0x18;
        o->uv[2].v = (m->v0 << 4) + 8;
        o->uv[3].v = (m->v1 << 4) + 0x18;
    } else {
        o->uv[0].v = (m->v0 << 4) + 8;
        o->uv[1].v = (m->v1 << 4) - 8;
        o->uv[2].v = (m->v0 << 4) + 8;
        o->uv[3].v = (m->v1 << 4) - 8;
    }
}

// UiPart_BuildSprite with TEX0 set for an 8-bit CLUT texture (PSM 0x13, CLD 1).
void UiPart_BuildSprite8(s32 arg0, sceGsTex0* tex, u64* arg2) {
    UiPart_BuildSprite(tex, arg0, arg2[3]);
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

// Turns the key track offsets of every part in a UI file into pointers (asserts 16-byte alignment).
void UiFile_Relocate(MonitorFile* f) {
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
