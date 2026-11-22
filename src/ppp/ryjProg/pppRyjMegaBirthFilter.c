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

INCLUDE_ASM("asm/nonmatchings/ppp/ryjProg/pppRyjMegaBirthFilter", func_001A4F78);

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

INCLUDE_ASM("asm/nonmatchings/ppp/ryjProg/pppRyjMegaBirthFilter", func_001A5EF8);

INCLUDE_ASM("asm/nonmatchings/ppp/ryjProg/pppRyjMegaBirthFilter", func_001A6040);

INCLUDE_ASM("asm/nonmatchings/ppp/ryjProg/pppRyjMegaBirthFilter", func_001A66B0);
