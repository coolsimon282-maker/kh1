#include "ppp.h"

typedef struct {
    /* 0x00 */ void* pvParticleData;
    /* 0x04 */ void* pvParticleColor;
    /* 0x08 */ u32 nParticle;
    /* 0x0C */ f32 fAlphaScale;
    /* 0x10 */ u16 ushTimingCt;
    /* 0x12 */ u8 bActive;
} VRyjMegaBirthFilter;

sceVu0FVECTOR g_vecCamDir;

f32 RyjMegaBirthFilter_Rand(void);

typedef struct {
    /* 0x00 */ char unk_00[0x4];
    /* 0x04 */ s32 shpIdx;
    /* 0x08 */ char unk_08[0x4];
    /* 0x0C */ u8 unk_0C;
    /* 0x0D */ char unk_0D[0x1];
    /* 0x0E */ u16 nParticle;
    /* 0x10 */ char unk_10[0x84];
    /* 0x94 */ f32 fZNear;
    /* 0x98 */ f32 fZFade;
    /* 0x9C */ char unk_9C[0x10];
    /* 0xAC */ f32 fDist;
    /* 0xB0 */ f32 fFade;
    /* 0xB4 */ u8 bDistFade;
    /* 0xB5 */ u8 unk_B5;
    /* 0xB6 */ u8 bColor;
} PRyjMegaBirthFilterCalc;

extern sceVu0FVECTOR D_003701D0;
s32 RyjDttFr_HasData(VRyjMegaBirthFilter* v, PRyjMegaBirthFilterCalc* p);
void func_001A4BC8(VRyjMegaBirthFilter* v, PRyjMegaBirthFilterCalc* p, void* w);

// |v.xyz| on VU0 (hand-written macro code)
static inline f32 vu0Length(f32* v) {
    f32 len;
    __asm__ volatile(
        "lqc2 $vf10, 0(%1)
"
        "vmul.xyz $vf10, $vf10, $vf10
"
        "vaddx.y $vf10, $vf10, $vf10x
"
        "vaddy.z $vf10, $vf10, $vf10y
"
        "vsqrt Q, $vf10z
"
        "vwaitq
"
        "vaddq.x $vf10, $vf0, Q
"
        "qmfc2.ni %0, $vf10
"
        : "=r"(len) : "r"(v) : "memory");
    return len;
}

void pppRyjMegaBirthFilterCalc(pppPObject* pobj, PRyjMegaBirthFilterCalc* p, pppCtrlTable* ctbl) {
    VRyjMegaBirthFilter* v = (VRyjMegaBirthFilter*)&pobj->val[ctbl->useVal[2]];
    void* w = &pobj->val[ctbl->useVal[1]];
    sceVu0FVECTOR d;
    f32 len;
    f32 f;

    if (v->pvParticleData == NULL) {
        v->nParticle = p->nParticle;
        v->pvParticleData = pppDbgAlloc(ppvEnv, v->nParticle * 0x60);
        if (v->pvParticleData != NULL) {
            memset(v->pvParticleData, 0, v->nParticle * 0x60);
        }
        if (p->bColor) {
            v->pvParticleColor = pppDbgAlloc(ppvEnv, v->nParticle * 32);
            if (v->pvParticleColor != NULL) {
                memset(v->pvParticleColor, 0, v->nParticle * 32);
            }
        }
    }
    if (!RyjDttFr_HasData(v, p)) {
        return;
    }
    if (p->bDistFade) {
        sceVu0SubVector(d, ppvEye, D_003701D0);
        len = vu0Length(d);
        if (p->fDist < len) {
            v->bActive = 0;
        } else {
            v->bActive = 1;
            f = p->fDist - len;
            if (f < p->fFade) {
                v->fAlphaScale = f / p->fFade;
            } else {
                v->fAlphaScale = 1.0f;
            }
        }
    }
    if (v->bActive) {
        func_001A4BC8(v, p, w);
    }
}

void func_001A4F70(sceVu0FMATRIX m, PRyjMegaBirthFilterCalc* p, VRyjMegaBirthFilter* v) {
}

typedef struct {
    /* 0x00 */ f32 pos[4];
    /* 0x10 */ char unk_10[0x14];
    /* 0x24 */ u16 seq;
    /* 0x26 */ u16 life;
    /* 0x28 */ s8 col[4];
    /* 0x2C */ f32 rotZ;
    /* 0x30 */ char unk_30[0x8];
    /* 0x38 */ f32 sclX;
    /* 0x3C */ f32 sclY;
    /* 0x40 */ char unk_40[0x14];
    /* 0x54 */ f32 alpha;
    /* 0x58 */ u64 flags;
} RyjMegaBirthFilterPt; // size = 0x60

typedef struct {
    /* 0x00 */ char unk_00[0xA4];
    /* 0xA4 */ f32 unk_A4;
    /* 0xA8 */ f32 unk_A8;
} RyjMegaBirthFilterObj;

extern sceVu0FMATRIX D_00615EB0;

f32 func_001A4F78(void* a0, sceVu0FMATRIX m, RyjMegaBirthFilterObj* obj, void* a3, RyjMegaBirthFilterPt* pt) {
    f32 z;

    sceVu0UnitMatrix(m);
    m[0][0] = pt->sclX * ppvParScl[0];
    m[1][1] = pt->sclY * ppvParScl[1];
    m[2][2] = pt->sclX * ppvParScl[0];
    if (pt->rotZ != 0.0f) {
        sceVu0RotMatrixZ(m, m, pt->rotZ * 3.1415926f / 180.0f);
    }
    sceVu0CopyVector(m[3], pt->pos);
    sceVu0ApplyMatrix(m[3], D_00615EB0, m[3]);
    m[3][1] *= obj->unk_A4;
    z = m[3][2];
    m[3][1] += obj->unk_A8;
    sceVu0MulMatrix(m, ppvScreenMatrix, m);
    return z;
}

typedef struct {
    /* 0x00 */ s16 unk_00;
    /* 0x02 */ u16 flags;
    /* 0x04 */ u8 col[4];
    /* 0x08 */ u64 unk_08;
    /* 0x10 */ f32* mat;
    /* 0x14 */ s32 unk_14;
    /* 0x18 */ u8 unk_18;
    /* 0x1C */ void* unk_1C;
    /* 0x20 */ char unk_20[0x10];
} MBFDrawSt;

extern s32 D_00616224;
s32 func_001BA340(void* shape, MBFDrawSt* st, s32 size);

void pppRyjMegaBirthFilterDraw(pppPObject* pobj, PRyjMegaBirthFilterCalc* p, pppCtrlTable* ctbl) {
    VRyjMegaBirthFilter* v = (VRyjMegaBirthFilter*)&pobj->val[ctbl->useVal[2]];
    u8* c = (u8*)&pobj->val[ctbl->useVal[1]];
    RyjMegaBirthFilterPt* pt = v->pvParticleData;
    f32(*col)[8] = v->pvParticleColor;
    s32 n = v->nParticle;
    sceVu0FMATRIX m0;
    sceVu0FMATRIX m;
    MBFDrawSt ds;
    pppShapeSt* st;
    u8* shp;
    s32 r0, g0, b0, a0;
    s32 r, g, b, a;
    u8* data;
    s32 idx;
    s32 i;
    f32 z;

    if (!RyjDttFr_HasData(v, p)) {
        return;
    }
    if (!v->bActive) {
        return;
    }
    idx = p->shpIdx;
    if (idx == 0xFFFF) {
        return;
    }
    func_001A4F70(m0, p, v);
    st = &ppvEnv->lpShape[idx];
    ds.flags = 0x10;
    if (p->unk_0C) {
        ds.flags = 0x810;
    }
    ds.unk_1C = NULL;
    ds.unk_08 = 0;
    ds.unk_18 = 0;
    ds.mat = m[0];
    shp = (u8*)st->shape;
    r0 = c[0x8];
    g0 = c[0x9];
    b0 = c[0xA];
    a0 = c[0xB];
    for (i = 0; i < n; i++) {
        if (pt->life != 0 && !(pt->flags & 0x100)) {
            z = func_001A4F78(m0, m, (RyjMegaBirthFilterObj*)p, v, pt);
            if (z < p->fZNear - p->fZFade) {
                pt->alpha = 0.0f;
            } else if (z < p->fZNear) {
                pt->alpha *= 1.0f - (p->fZNear - z) / p->fZFade;
            }
            data = shp + *(s16*)(shp + (pt->seq << 3) + 0x10);
            r = r0 + pt->col[0];
            g = g0 + pt->col[1];
            b = b0 + pt->col[2];
            a = a0 + pt->col[3];
            if (col != NULL) {
                r += (s32)(*col)[0];
                g += (s32)(*col)[1];
                b += (s32)(*col)[2];
                a += (s32)(*col)[3];
            }
            if (r < 0) {
                r = 0;
            } else if (r > 0xFF) {
                r = 0xFF;
            }
            if (g < 0) {
                g = 0;
            } else if (g > 0xFF) {
                g = 0xFF;
            }
            if (b < 0) {
                b = 0;
            } else if (b > 0xFF) {
                b = 0xFF;
            }
            if (a < 0) {
                a = 0;
            } else if (a > 0x7F) {
                a = 0x7F;
            }
            ds.col[3] = a;
            ds.col[0] = r;
            ds.col[1] = g;
            ds.col[2] = b;
            ds.col[3] = ds.col[3] * pt->alpha * v->fAlphaScale;
            if (ds.col[3] != 0) {
                ds.unk_14 = D_00616224;
                D_00616224 = func_001BA340(data, &ds, st->nPacketSize);
            }
        }
        if (col != NULL) {
            col++;
        }
        pt++;
    }
}


void pppRyjMegaBirthFilterSta(void) {
    sceVu0SubVector(g_vecCamDir, ppvAt, ppvEye);
    sceVu0Normalize(g_vecCamDir, g_vecCamDir);
    g_vecCamDir[3] = 1.0f;
}

void pppRyjMegaBirthFilterCon(pppPObject* pobj, pppCtrlTable* ctbl) {
    VRyjMegaBirthFilter* v = (VRyjMegaBirthFilter*)&pobj->val[ctbl->useVal[2]];
    
    v->pvParticleData = NULL;
    v->pvParticleColor = NULL;
    v->nParticle = 0;
    v->fAlphaScale = 1.0f;
    v->ushTimingCt = 0;
    v->bActive = TRUE;
    ppvMng->unk_B3 = 1;
}

void pppRyjMegaBirthFilterDes(pppPObject* pobj, pppCtrlTable* ctbl) {
    VRyjMegaBirthFilter* v = (VRyjMegaBirthFilter*)&pobj->val[ctbl->useVal[2]];
    
    if (v->pvParticleData != NULL) {
        pppFree(ppvEnv, v->pvParticleData);
        v->pvParticleData = NULL;
    }
    if (v->pvParticleColor != NULL) {
        pppFree(ppvEnv, v->pvParticleColor);
        v->pvParticleColor = NULL;
    }
}

static inline f32 vu0Rand(void) {
    f32 r;
    __asm__ volatile(
        "addi $8, $0, -1
"
        "qmtc2.ni $8, $vf2
"
        "vrxor R, $vf2x
"
        "vrnext.x $vf1, R
"
        "vrxor R, $vf2x
"
        "vrnext.x $vf1, R
"
        "vrxor R, $vf2x
"
        "vrnext.x $vf1, R
"
        "vrxor R, $vf2x
"
        "vrnext.x $vf1, R
"
        "vrxor R, $vf2x
"
        "vrnext.x $vf1, R
"
        "vitof0.x $vf2, $vf2
"
        "vadd.x $vf1, $vf1, $vf2
"
        "qmfc2.ni %0, $vf1
"
        : "=r"(r) : : "$8");
    return r;
}

// VU0 random number 0..1.
f32 RyjMegaBirthFilter_Rand(void) {
    return vu0Rand();
}

// a * 2 * rand - a / 2.
s8 RyjMegaBirthFilter_RandSpread(u8 a) {
    f32 r = RyjMegaBirthFilter_Rand();
    return (a * 2) * r - (a >> 1);
}

// True when the particle data (and colour data when needed) is there.
s32 RyjMegaBirthFilter_HasData(VRyjMegaBirthFilter* v, u8* arg1) {
    if (v->pvParticleData == NULL) {
        return FALSE;
    }
    if (arg1[0xF2] != 0) {
        if (v->pvParticleColor == NULL) {
            return FALSE;
        }
    }
    return TRUE;
}

INCLUDE_ASM("asm/nonmatchings/ppp/ryjProg/pppRyjMegaBirthFilter", func_001A55D8);

typedef struct {
    /* 0x00 */ char unk_00[0xB8];
    /* 0xB8 */ f32 dir[3];
    /* 0xC4 */ char unk_C4[0x14];
    /* 0xD8 */ f32 rad;
    /* 0xDC */ f32 radAdd;
} PRyjMegaBirthFilterB;

extern sceVu0FMATRIX D_00615F30;
void func_001A55D8(PRyjMegaBirthFilterB* p, f32* data, u8* color);

void func_001A5EF8(void* v, PRyjMegaBirthFilterB* p, f32* data, u8* color) {
    sceVu0FVECTOR dir;
    f32 r;
    f32 d;

    memset(data, 0, 0xA0);
    if (color != NULL) {
        memset(color, 0, 0x20);
    }
    dir[0] = p->dir[0];
    dir[1] = p->dir[1];
    dir[2] = p->dir[2];
    dir[3] = 1.0f;
    sceVu0Normalize(&data[4], dir);
    r = p->rad + p->radAdd;
    d = r + r;
    do {
        data[0] = d * RyjMegaBirthFilter_Rand() - r;
        data[1] = d * RyjMegaBirthFilter_Rand() - r;
        data[2] = d * RyjMegaBirthFilter_Rand() - r;
    } while (r < vu0Length(data));
    data[3] = 1.0f;
    sceVu0ApplyMatrix(data, D_00615F30, data);
    func_001A55D8(p, data, color);
}

INCLUDE_ASM("asm/nonmatchings/ppp/ryjProg/pppRyjMegaBirthFilter", func_001A6040);

typedef struct {
    /* 0x00 */ u8* data;
    /* 0x04 */ u8* color;
    /* 0x08 */ s32 n;
    /* 0x0C */ char unk_0C[4];
    /* 0x10 */ u16 interval;
} VRyjMegaBirthFilterC;

typedef struct {
    /* 0x00 */ char unk_00[4];
    /* 0x04 */ s32 shpIdx;
    /* 0x08 */ char unk_08[4];
    /* 0x0C */ u16 max;
    /* 0x0E */ u16 timing;
} PRyjMegaBirthFilterC;

void func_001A6040(VRyjMegaBirthFilterC* v, PRyjMegaBirthFilterC* p, u8* data, void* w, u8* color);

void func_001A66B0(VRyjMegaBirthFilterC* v, PRyjMegaBirthFilterC* p, void* w) {
    u8* data = v->data;
    u8* color = v->color;
    s32 n = v->n;
    s32 cnt = 0;
    s32 i;

    if (ppvUserStopPartF != 0 || ppvMng->stop || ppvMng->unk_B4 != 0) {
        return;
    }
    if (p->shpIdx == 0xFFFF) {
        return;
    }
    v->interval++;
    for (i = 0; i < n; i++) {
        if (*(u16*)(data + 0x20) != 0) {
            func_001A6040(v, p, data, w, color);
        } else if (p->timing <= v->interval && cnt < p->max) {
            func_001A5EF8(v, (PRyjMegaBirthFilterB*)p, (f32*)data, color);
            cnt++;
        }
        if (color != NULL) {
            color += 0x20;
        }
        data += 0xA0;
    }
    if (cnt > 0) {
        v->interval = 0;
    }
}
