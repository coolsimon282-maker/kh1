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

INCLUDE_ASM("asm/nonmatchings/ppp/ryjProg/pppRyjMegaBirthModelFilter", pppRyjMegaBirthModelFilterCalc);

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
