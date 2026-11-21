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

INCLUDE_ASM("asm/nonmatchings/ppp/ryjProg/pppRyjMegaBirthModel", func_001A2F20);
