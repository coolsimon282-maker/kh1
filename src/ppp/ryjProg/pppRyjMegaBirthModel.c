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
    /* 0x01E */ char unk_1E[0x8];
    /* 0x026 */ u8 unk_26;
    /* 0x027 */ char unk_27[0xA9];
    /* 0x0D0 */ f32 force[3];
    /* 0x0DC */ char unk_DC[0x25];
    /* 0x101 */ u8 bColor;
    /* 0x102 */ char unk_102[3];
    /* 0x105 */ u8 unk_105;
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

void func_001A26D0(sceVu0FMATRIX out, PRyjMegaBirthModel* p, VRyjMegaBirthModel* v) {
    void* w = v->pvParticleWmat;

    sceVu0UnitMatrix(out);
    switch (p->unk_26) {
        case 0:
        case 2:
        case 4:
        case 6:
        case 8:
        default:
            if (w == NULL) {
                sceVu0MulMatrix(out, ppvWorldMatrix, ppvPObj.next->cmat);
                return;
            }
            break;
        case 1:
        case 3:
        case 5:
        case 7:
        case 9:
            sceVu0MulMatrix(out, ppvWorldMatrix, ppvPObj.next->cmat);
            return;
    }
}

typedef struct {
    /* 0x00 */ sceVu0FMATRIX m;
    /* 0x40 */ char unk_40[8];
    /* 0x48 */ s32 rot[3];
    /* 0x54 */ char unk_54[0x18];
    /* 0x6C */ f32 scl[3];
} RyjMegaBirthModelPt;

extern sceVu0FMATRIX D_00615EB0;
extern sceVu0FMATRIX D_00616000;

void func_001A2798(sceVu0FMATRIX a, sceVu0FMATRIX m, PRyjMegaBirthModel* p, RyjMegaBirthModelPt* pt,
                   sceVu0FMATRIX wmat, sceVu0FMATRIX out, u8 flag) {
    sceVu0FVECTOR pos;
    sceVu0FMATRIX tmp;
    sceVu0FMATRIX rot;
    sceVu0FVECTOR ang;
    f32* trans;
    f32* sc;
    s32 i;
    f32 (*mat)[4];

    if (p->unk_105) {
        sceVu0CopyMatrix(m, pt->m);
        trans = m[3];
    } else {
        sceVu0UnitMatrix(m);
        trans = m[3];
        sceVu0CopyVector(trans, pt->m[3]);
    }
    if (*(s64*)pt->rot != 0 || pt->rot[2] != 0) {
        for (i = 0; i < 3; i++) {
            ang[i] = (f32)pt->rot[i] * 3.1415925026f * (1.0f / 32768.0f);
        }
        sceVu0UnitMatrix(rot);
        sceVu0RotMatrix(rot, rot, ang);
        sceVu0MulMatrix(m, m, rot);
    }
    sc = pt->scl;
    for (i = 0; i < 3; i++) {
        sceVu0ScaleVector(m[i], m[i], *sc++);
    }
    switch (p->unk_26) {
        case 0:
        case 2:
        case 4:
        case 6:
        case 8:
        default:
            if (wmat == NULL) {
                sceVu0CopyVector(pos, trans);
                sceVu0MulMatrix(m, ppvWorldMatrix, m);
                sceVu0ApplyMatrix(trans, a, pos);
                if (flag) {
                    sceVu0CopyMatrix(out, m);
                }
                sceVu0MulMatrix(m, ppvScreenMatrix, m);
            } else {
                sceVu0MulMatrix(tmp, wmat, ppvPObj.next->cmat);
                sceVu0MulMatrix(tmp, D_00615EB0, tmp);
                sceVu0CopyVector(pos, trans);
                sceVu0MulMatrix(m, ppvWorldMatrix, m);
                sceVu0ApplyMatrix(trans, tmp, pos);
                if (flag) {
                    sceVu0CopyMatrix(out, m);
                }
                sceVu0MulMatrix(m, ppvScreenMatrix, m);
            }
            break;
        case 1:
        case 3:
        case 5:
        case 7:
        case 9:
            sceVu0ApplyMatrix(pos, a, trans);
            sceVu0MulMatrix(m, D_00616000, m);
            sceVu0CopyVector(trans, pos);
            if (flag) {
                sceVu0CopyMatrix(out, m);
            }
            sceVu0MulMatrix(m, ppvScreenMatrix, m);
            break;
    }
}

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
