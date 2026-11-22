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
    /* 0x00 */ char unk_00[0x4];
    /* 0x04 */ s32 mdlIdx;
    /* 0x08 */ u8 unk_08;
    /* 0x09 */ char unk_09[0x1];
    /* 0x0A */ u16 nParticle;
    /* 0x0C */ char unk_0C[0xC4];
    /* 0xD0 */ f32 unk_D0;
    /* 0xD4 */ f32 unk_D4;
    /* 0xD8 */ char unk_D8[0x10];
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

void func_001A69A8(sceVu0FMATRIX m, PRyjMegaBirthModelFilter* p, VRyjMegaBirthModelFilter* v) {
}

typedef struct {
    /* 0x00 */ f32 pos[4];
    /* 0x10 */ char unk_10[0x10];
    /* 0x20 */ u16 life;
    /* 0x22 */ s8 col[4];
    /* 0x26 */ char unk_26[0x2];
    /* 0x28 */ s32 rot[3];
    /* 0x34 */ char unk_34[0x20];
    /* 0x54 */ f32 scale[3];
    /* 0x60 */ char unk_60[0x1C];
    /* 0x7C */ f32 unk_7C;
    /* 0x80 */ f32 unk_80;
    /* 0x84 */ char unk_84[0x10];
    /* 0x94 */ f32 alpha;
    /* 0x98 */ u64 flags;
} MBMFParticle; // size = 0xA0

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

// parameter block for op1_md_draw (same layout as in pppDrawMdl.c)
typedef struct {
    /* 0x00 */ s32 mode;
    /* 0x04 */ void* unk_04;
    /* 0x08 */ u16 flag;
    /* 0x0A */ u8 unk_0A;
    /* 0x0C */ s32 unk_0C;
    /* 0x10 */ union {
        u64 d;
        s32 w[2];
    } unk_10;
    /* 0x18 */ u8 col[4];
    /* 0x1C */ s32 unk_1C;
    /* 0x20 */ FMATRIX* dmat;
    /* 0x24 */ void* unk_24;
    /* 0x28 */ void* unk_28;
    /* 0x2C */ void* unk_2C;
    /* 0x30 */ s32 unk_30;
    /* 0x34 */ s32 unk_34;
    /* 0x38 */ pppSVECTOR* lpvert;
    /* 0x3C */ pppSVECTOR* lpnorm;
    /* 0x40 */ s32 unk_40;
    /* 0x44 */ s32 unk_44;
    /* 0x48 */ s32 unk_48;
    /* 0x4C */ u8 unk_4C;
    /* 0x4D */ u8 unk_4D;
    /* 0x4E */ char pad[0x12];
} MdPrm;

extern char D_00616240[];
extern s32 D_00616224;
s32 op1_md_draw(OMD_H* omd, MdPrm* prm, s32 size);

void pppRyjMegaBirthModelFilterDraw(pppPObject* pobj, PRyjMegaBirthModelFilter* p, pppCtrlTable* ctbl) {
    VRyjMegaBirthModelFilter* v = (VRyjMegaBirthModelFilter*)&pobj->val[ctbl->useVal[2]];
    u8* c = (u8*)&pobj->val[ctbl->useVal[1]];
    MBMFParticle* pt = v->pvParticleData;
    f32(*col)[8] = v->pvParticleColor;
    s32 n = v->nParticle;
    sceVu0FMATRIX m0;
    sceVu0FMATRIX m;
    MdPrm prm;
    pppModelSt* mdl;
    OMD_H* omd;
    pppPObject* next;
    s32 r0, g0, b0, a0;
    s32 r, g, b, a;
    s32 idx;
    s32 i;
    f32 z;

    if (!func_001A55A8(v, p)) {
        return;
    }
    if (!v->bActive) {
        return;
    }
    idx = p->mdlIdx;
    if (idx == 0xFFFF) {
        return;
    }
    func_001A69A8(m0, p, v);
    mdl = &ppvEnv->lpModel[idx];
// statement order found by search (it sets the store schedule)
    omd = mdl->omd;
    prm.unk_44 = 0;
    prm.unk_2C = 0;
    prm.unk_28 = 0;
    next = ppvPObj.next;
    prm.unk_24 = 0;
    prm.unk_0A = 0;
    prm.unk_1C = 0;
    prm.lpvert = next->lpvert;
    prm.lpnorm = next->lpnorm;
    prm.dmat = (FMATRIX*)m;
    prm.unk_0C = 0;
    prm.unk_04 = D_00616240;
    prm.unk_10.d = 0;
    prm.unk_40 = 0;
    prm.mode = 4;
    if (p->unk_08) {
        prm.mode = 0x204;
    }
    prm.unk_4D = 1;
    r0 = c[0x8];
    g0 = c[0x9];
    prm.flag = *(u16*)&omd->alpha;
    b0 = c[0xA];
    a0 = c[0xB];
    for (i = 0; i < n; i++) {
        if (pt->life != 0 && !(pt->flags & 0x100)) {
            z = func_001A69B0((s32)m0, m, (MBMFParam*)p, (s32)v, pt);
            if (z < p->unk_D0 - p->unk_D4) {
                pt->alpha = 0.0f;
            } else if (z < p->unk_D0) {
                pt->alpha *= 1.0f - (p->unk_D0 - z) / p->unk_D4;
            }
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
            prm.col[3] = a;
            prm.col[0] = r;
            prm.col[1] = g;
            prm.col[2] = b;
            prm.col[3] = prm.col[3] * pt->alpha * v->fAlphaScale;
            prm.unk_10.w[0] = pt->unk_7C * 65536.0f;
            prm.unk_10.w[1] = pt->unk_80 * 65536.0f;
            if (prm.col[3] != 0) {
                prm.unk_34 = D_00616224;
                D_00616224 = op1_md_draw(omd, &prm, mdl->nPacketSize);
            }
        }
        if (col != NULL) {
            col++;
        }
        pt++;
    }
}

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
