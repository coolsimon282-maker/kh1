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

typedef struct {
    /* 0x000 */ char unk_00[0x1C];
    /* 0x01C */ u16 nParticle;
    /* 0x01E */ char unk_1E[0xB2];
    /* 0x0D0 */ f32 force[3];
    /* 0x0DC */ char unk_DC[0x25];
    /* 0x101 */ u8 bColor;
    /* 0x102 */ char unk_102[4];
    /* 0x106 */ u8 bWmat;
} PRyjMegaBirthModel;

s32 func_001A0F10(VRyjMegaBirthModel* v, PRyjMegaBirthModel* p);
void func_001A23F0(VRyjMegaBirthModel* v, PRyjMegaBirthModel* p, void* w);

void pppRyjMegaBirthModelCalc(pppPObject* pobj, PRyjMegaBirthModel* p, pppCtrlTable* ctbl) {
    VRyjMegaBirthModel* v = (VRyjMegaBirthModel*)&pobj->val[ctbl->useVal[2]];
    void* w = &pobj->val[ctbl->useVal[1]];

    if (v->pvParticleData == NULL) {
        v->nParticle = p->nParticle;
        v->pvParticleData = pppDbgAlloc(ppvEnv, v->nParticle * 0xB0);
        if (v->pvParticleData != NULL) {
            memset(v->pvParticleData, 0, v->nParticle * 0xB0);
        }
        if (p->bWmat) {
            v->pvParticleWmat = pppDbgAlloc(ppvEnv, v->nParticle * 64);
            if (v->pvParticleWmat != NULL) {
                memset(v->pvParticleWmat, 0, v->nParticle * 64);
            }
        }
        if (p->bColor) {
            v->pvParticleColor = pppDbgAlloc(ppvEnv, v->nParticle * 32);
            if (v->pvParticleColor != NULL) {
                memset(v->pvParticleColor, 0, v->nParticle * 32);
            }
        }
        v->vecForce.x = p->force[0];
        v->vecForce.y = p->force[1];
        v->vecForce.z = p->force[2];
        *(s32*)v->unk_0C = 0;
        sceVu0Normalize((f32*)&v->vecForce, (f32*)&v->vecForce);
    }
    if (func_001A0F10(v, p)) {
        func_001A23F0(v, p, w);
    }
}

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
