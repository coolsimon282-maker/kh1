#include "ppp.h"

typedef struct {
    /* 0x00 */ pppFVECTOR vecForce;
    /* 0x0C */ char unk_0C[0x4];
    /* 0x10 */ void* pvParticleData;
    /* 0x14 */ void* pvParticleWmat;
    /* 0x18 */ void* pvParticleColor;
    /* 0x1C */ u32 nParticle;
    /* 0x20 */ u16 ushTimingCt;
    /* 0x22 */ u16 ushIct;
} VRyjMegaBirthModel;

INCLUDE_ASM("asm/nonmatchings/ppp/ryjProg/pppRyjMegaBirthModel", pppRyjMegaBirthModelCalc);

INCLUDE_ASM("asm/nonmatchings/ppp/ryjProg/pppRyjMegaBirthModel", func_001A26D0);

INCLUDE_ASM("asm/nonmatchings/ppp/ryjProg/pppRyjMegaBirthModel", func_001A2798);

INCLUDE_ASM("asm/nonmatchings/ppp/ryjProg/pppRyjMegaBirthModel", pppRyjMegaBirthModelDraw);

void pppRyjMegaBirthModelCon(pppPObject* pobj, pppCtrlTable* ctbl) {
    VRyjMegaBirthModel* v = (VRyjMegaBirthModel*)&pobj->val[ctbl->useVal[2]];

    *(u_long128*)&v->vecForce = 0; // vecForce and the pad after it in one 128-bit store
    v->pvParticleData = NULL;
    v->pvParticleWmat = NULL;
    v->pvParticleColor = NULL;
    v->nParticle = 0;
    v->ushTimingCt = 0;
    v->ushIct = 0;
}

void pppRyjMegaBirthModelDes(pppPObject* pobj, pppCtrlTable* ctbl) {
    VRyjMegaBirthModel* v = (VRyjMegaBirthModel*)&pobj->val[ctbl->useVal[2]];
    
    if (v->pvParticleData != NULL) {
        pppFree(ppvEnv, v->pvParticleData);
        v->pvParticleData = NULL;
    }
    if (v->pvParticleWmat != NULL) {
        pppFree(ppvEnv, v->pvParticleWmat);
        v->pvParticleWmat = NULL;
    }
    if (v->pvParticleColor != NULL) {
        pppFree(ppvEnv, v->pvParticleColor);
        v->pvParticleColor = NULL;
    }
}

typedef struct {
    /* 0x00 */ u8 unk_00[0x31];
    /* 0x31 */ u8 uSel;
    /* 0x32 */ u8 vSel;
    /* 0x33 */ u8 uOfs;
} PRyjMegaBirthModelUv;

// texture coordinates of the 8 corners: width/height picked by uSel/vSel, the u offset by uOfs
void func_001A2F20(PRyjMegaBirthModelUv* p, sceVu0FVECTOR* uv) {
    f32 w;
    f32 h;
    f32 u;

    switch (p->uSel) {
    case 1:
        w = 0.49f;
        break;
    case 2:
        w = 0.24f;
        break;
    case 0:
    default:
        w = 0.99f;
        break;
    }
    switch (p->vSel) {
    case 1:
        h = 0.49f;
        break;
    case 2:
        h = 0.24f;
        break;
    case 0:
    default:
        h = 0.99f;
        break;
    }
    switch (p->uOfs) {
    case 1:
        u = 0.25f;
        break;
    case 2:
        u = 0.5f;
        break;
    case 3:
        u = 0.75f;
        break;
    case 0:
    default:
        u = 0.0f;
        break;
    }
    uv[0][0] = uv[1][0] = uv[6][0] = uv[7][0] = u + 0.01f;
    uv[2][0] = uv[3][0] = uv[4][0] = uv[5][0] = u + w;
    uv[1][1] = uv[3][1] = uv[5][1] = uv[7][1] = h;
    uv[0][1] = uv[2][1] = uv[4][1] = uv[6][1] = 0.01f;
    uv[0][2] = uv[1][2] = uv[2][2] = uv[3][2] = uv[4][2] = uv[5][2] = uv[6][2] = uv[7][2] = 1.0f;
}
