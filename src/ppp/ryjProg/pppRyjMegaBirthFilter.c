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

f32 func_001A5500(void);

INCLUDE_ASM("asm/nonmatchings/ppp/ryjProg/pppRyjMegaBirthFilter", pppRyjMegaBirthFilterCalc);

void func_001A4F70(void) {
}

typedef struct {
    /* 0x00 */ f32 pos[4];
    /* 0x10 */ char unk_10[0x1C];
    /* 0x2C */ f32 rotZ;
    /* 0x30 */ char unk_30[0x8];
    /* 0x38 */ f32 sclX;
    /* 0x3C */ f32 sclY;
} RyjMegaBirthFilterPt;

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

INCLUDE_ASM("asm/nonmatchings/ppp/ryjProg/pppRyjMegaBirthFilter", pppRyjMegaBirthFilterDraw);

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

f32 func_001A5500(void) {
    return vu0Rand();
}

s8 func_001A5548(u8 a) {
    f32 r = func_001A5500();
    return (a * 2) * r - (a >> 1);
}

s32 func_001A55A8(VRyjMegaBirthFilter* v, u8* arg1) {
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
        data[0] = d * func_001A5500() - r;
        data[1] = d * func_001A5500() - r;
        data[2] = d * func_001A5500() - r;
    } while (r < vu0Length(data));
    data[3] = 1.0f;
    sceVu0ApplyMatrix(data, D_00615F30, data);
    func_001A55D8(p, data, color);
}

INCLUDE_ASM("asm/nonmatchings/ppp/ryjProg/pppRyjMegaBirthFilter", func_001A6040);

INCLUDE_ASM("asm/nonmatchings/ppp/ryjProg/pppRyjMegaBirthFilter", func_001A66B0);
