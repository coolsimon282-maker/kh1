#include "ppp.h"

typedef struct {
    /* 0x00 */ void* pvParticleData;
    /* 0x04 */ void* pvParticleColor;
    /* 0x08 */ u32 nParticle;
    /* 0x0C */ f32 fAlphaScale;
    /* 0x10 */ u16 ushTimingCt;
    /* 0x12 */ u8 bActive;
} VRyjMegaBirthModelFilter; // size = 0x14

sceVu0FVECTOR g_vecCamDirM;

typedef struct {
    /* 0x00 */ char unk_00[0xA];
    /* 0x0A */ u16 nParticle;
    /* 0x0C */ char unk_0C[0xDC];
    /* 0xE8 */ f32 fDist;
    /* 0xEC */ f32 fFade;
    /* 0xF0 */ u8 bDistFade;
    /* 0xF1 */ u8 unk_F1;
    /* 0xF2 */ u8 bColor;
} PRyjMegaBirthModelFilter;

extern sceVu0FVECTOR D_003701D0;
s32 func_001A55A8(VRyjMegaBirthModelFilter* v, PRyjMegaBirthModelFilter* p);
void func_001A66B0(VRyjMegaBirthModelFilter* v, PRyjMegaBirthModelFilter* p, void* w);

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

void pppRyjMegaBirthModelFilterCalc(pppPObject* pobj, PRyjMegaBirthModelFilter* p, pppCtrlTable* ctbl) {
    VRyjMegaBirthModelFilter* v = (VRyjMegaBirthModelFilter*)&pobj->val[ctbl->useVal[2]];
    void* w = &pobj->val[ctbl->useVal[1]];
    sceVu0FVECTOR d;
    f32 len;
    f32 f;

    if (v->pvParticleData == NULL) {
        v->nParticle = p->nParticle;
        v->pvParticleData = pppDbgAlloc(ppvEnv, v->nParticle * 0xA0);
        if (v->pvParticleData != NULL) {
            memset(v->pvParticleData, 0, v->nParticle * 0xA0);
        }
        if (p->bColor) {
            v->pvParticleColor = pppDbgAlloc(ppvEnv, v->nParticle * 32);
            if (v->pvParticleColor != NULL) {
                memset(v->pvParticleColor, 0, v->nParticle * 32);
            }
        }
    }
    if (!func_001A55A8(v, p)) {
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
        func_001A66B0(v, p, w);
    }
}

void func_001A69A8(void) {
}

typedef struct {
    /* 0x00 */ f32 pos[4];
    /* 0x10 */ char unk_10[0x18];
    /* 0x28 */ s32 rot[3];
    /* 0x34 */ char unk_34[0x20];
    /* 0x54 */ f32 scale[3];
} MBMFParticle;

typedef struct {
    /* 0x00 */ char unk_00[0xE0];
    /* 0xE0 */ f32 unk_E0;
    /* 0xE4 */ f32 unk_E4;
} MBMFParam;

extern sceVu0FMATRIX D_00615EB0;
extern sceVu0FVECTOR D_006161C0;

f32 func_001A69B0(s32 arg0, sceVu0FMATRIX m, MBMFParam* q, s32 arg3, MBMFParticle* pt) {
    sceVu0FMATRIX rm;
    sceVu0FVECTOR ang;
    s32 i;
    f32 z;

    sceVu0UnitMatrix(m);
    if (*(u64*)&pt->rot[0] != 0 || pt->rot[2] != 0) {
        for (i = 0; i < 3; i++) {
            ang[i] = pt->rot[i] * 3.1415926f * (1.0f / 32768.0f);
        }
        sceVu0RotMatrix(rm, D_006161C0, ang);
        sceVu0MulMatrix(m, m, rm);
    }
    for (i = 0; i < 3; i++) {
        sceVu0ScaleVector(m[i], m[i], pt->scale[i]);
    }
    sceVu0CopyVector(m[3], pt->pos);
    sceVu0ApplyMatrix(m[3], D_00615EB0, m[3]);
    m[3][1] *= q->unk_E0;
    z = m[3][2];
    m[3][1] += q->unk_E4;
    sceVu0MulMatrix(m, ppvScreenMatrix, m);
    return z;
}

INCLUDE_ASM("asm/nonmatchings/ppp/ryjProg/pppRyjMegaBirthModelFilter", pppRyjMegaBirthModelFilterDraw);

void pppRyjMegaBirthModelFilterSta(void) {
    sceVu0SubVector(g_vecCamDirM, ppvAt, ppvEye);
    sceVu0Normalize(g_vecCamDirM, g_vecCamDirM);
    g_vecCamDirM[3] = 1.0f;
}

void pppRyjMegaBirthModelFilterCon(pppPObject* pobj, pppCtrlTable* ctbl) {
    VRyjMegaBirthModelFilter* v = (VRyjMegaBirthModelFilter*)&pobj->val[ctbl->useVal[2]];

    v->pvParticleData = NULL;
    v->pvParticleColor = NULL;
    v->nParticle = 0;
    v->fAlphaScale = 1.0f;
    v->ushTimingCt = 0;
    v->bActive = 1;
    
    ppvMng->unk_B3 = 1;
}

void pppRyjMegaBirthModelFilterDes(pppPObject* pobj, pppCtrlTable* ctbl) {
    VRyjMegaBirthModelFilter* v = (VRyjMegaBirthModelFilter*)&pobj->val[ctbl->useVal[2]];

    if (v->pvParticleData != NULL) {
        pppFree(ppvEnv, v->pvParticleData);
        v->pvParticleData = NULL;
    }
    if (v->pvParticleColor != NULL) {
        pppFree(ppvEnv, v->pvParticleColor);
        v->pvParticleColor = NULL;
    }
}
