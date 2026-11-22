#include "ppp.h"

typedef struct {
    /* 0x00 */ FMATRIX matPar;
    /* 0x40 */ sceVu0FVECTOR vecForce;
    /* 0x50 */ void* pvParticleData;
    /* 0x54 */ void* pvParticleWmat;
    /* 0x58 */ void* pvParticleColor;
    /* 0x5C */ u32 nParticle;
    /* 0x60 */ u16 ushTimingCt;
    /* 0x62 */ u16 ushIct;
} VRyjMegaBirth;

INCLUDE_ASM("asm/nonmatchings/ppp/ryjProg/pppRyjMegaBirth", pppRyjMegaBirthCalc);

typedef struct {
    /* 0x00 */ char unk_00[0xCC];
    /* 0xCC */ u8 unk_CC;
} PRyjMegaBirthCC;

extern sceVu0FMATRIX D_00615EB0;

void func_0019ECE8(sceVu0FMATRIX out, PRyjMegaBirthCC* p, sceVu0FMATRIX m) {
    if (p->unk_CC == 0) {
        sceVu0MulMatrix(out, m, ppvPObj.next->cmat);
        sceVu0MulMatrix(out, D_00615EB0, out);
    }
}

INCLUDE_ASM("asm/nonmatchings/ppp/ryjProg/pppRyjMegaBirth", func_0019ED48);

INCLUDE_ASM("asm/nonmatchings/ppp/ryjProg/pppRyjMegaBirth", pppRyjMegaBirthDraw);

void pppRyjMegaBirthCon(pppPObject* pobj, pppCtrlTable* ctbl) {
    VRyjMegaBirth* v = (VRyjMegaBirth*)&pobj->val[ctbl->useVal[2]];

    sceVu0UnitMatrix(v->matPar);
    *(u_long128*)v->vecForce = 0;
    v->pvParticleData = 0;
    v->pvParticleWmat = 0;
    v->pvParticleColor = 0;
    v->nParticle = 0;
    v->ushTimingCt = 0;
    v->ushIct = 0;
    sceVu0UnitMatrix(g_matUnit);
}

void pppRyjMegaBirthDes(pppPObject* pobj, pppCtrlTable* ctbl) {
    VRyjMegaBirth* data = (VRyjMegaBirth*)&pobj->val[ctbl->useVal[2]];

    if (data->pvParticleData != NULL) {
        pppFree(ppvEnv, data->pvParticleData);
        data->pvParticleData = NULL;
    }
    if (data->pvParticleWmat != NULL) {
        pppFree(ppvEnv, data->pvParticleWmat);
        data->pvParticleWmat = NULL;
    }
    if (data->pvParticleColor != NULL) {
        pppFree(ppvEnv, data->pvParticleColor);
        data->pvParticleColor = NULL;
    }
}
