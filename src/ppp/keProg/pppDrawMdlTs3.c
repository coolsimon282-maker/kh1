#include "ppp.h"

void pppDrawMdlTs3Con(pppPObject* pobj, pppCtrlTable* ctbl) {
    f32* v = (f32*)&pobj->val[ctbl->useVal[2]];

    v[0] = v[1] = v[2] = v[3] = v[4] = v[5] = 0.0f;
}

typedef struct {
    /* 0x00 */ pppCDT cdt;
    /* 0x04 */ s32 unk_04;
    /* 0x08 */ f32 d[6];
} PDrawMdlTs3;

typedef union {
    f32 f;
    s32 i;
} FI;

void pppDrawMdlTs3Calc(pppPObject* pobj, PDrawMdlTs3* p, pppCtrlTable* ctbl) {
    FI* v = (FI*)&pobj->val[ctbl->useVal[2]];

    if (ppvUserStopPartF != 0 || ppvMng->stop || ppvMng->unk_B4 != 0) {
        return;
    }

    v[1].f += v[2].f;
    v[0].f += v[1].f;
    v[4].f += v[5].f;
    v[3].f += v[4].f;

    if (p->cdt.time == pobj->time) {
        v[0].f += p->d[0];
        v[1].f += p->d[1];
        v[2].f += p->d[2];
        v[3].f += p->d[3];
        v[4].f += p->d[4];
        v[5].f += p->d[5];
    }
}

// parameter block for op1_md_draw (as in pppDrawMdl3.c, with unk_10 as two words)
typedef struct {
    /* 0x00 */ s32 mode;
    /* 0x04 */ void* unk_04;
    /* 0x08 */ u16 flag;
    /* 0x0A */ u8 unk_0A;
    /* 0x0C */ s32 unk_0C;
    /* 0x10 */ s32 unk_10;
    /* 0x14 */ s32 unk_14;
    /* 0x18 */ u8 col[4];
    /* 0x1C */ s32 unk_1C;
    /* 0x20 */ FMATRIX* dmat;
    /* 0x24 */ void* unk_24;
    /* 0x28 */ void* unk_28;
    /* 0x2C */ FMATRIX* cmat;
    /* 0x30 */ FMATRIX* unk_30;
    /* 0x34 */ s32 unk_34;
    /* 0x38 */ pppSVECTOR* lpvert;
    /* 0x3C */ pppSVECTOR* lpnorm;
    /* 0x40 */ s32 unk_40;
    /* 0x44 */ void* unk_44;
    /* 0x48 */ s32 unk_48;
    /* 0x4C */ u8 unk_4C;
    /* 0x4D */ u8 unk_4D;
    /* 0x4E */ char pad[0x12];
} MdPrmTs3;

typedef struct {
    /* 0x00 */ pppCDT cdt;
    /* 0x04 */ u32 index;
    /* 0x08 */ f32 d[6];
    /* 0x20 */ u8 flag;
    /* 0x21 */ u8 unk_21;
    /* 0x22 */ u8 unk_22;
    /* 0x23 */ u8 unk_23;
    /* 0x24 */ u8 unk_24;
    /* 0x25 */ u8 unk_25;
} PDrawMdlTs3D;

typedef struct {
    /* 0x0 */ char unk_00[8];
    /* 0x8 */ u8 col[4];
} VDrawMdlTs3;

extern char D_00616240[];
extern char D_00616140[];
extern char D_00616100[];
extern s32 D_00616224;
s32 op1_md_draw(OMD_H* omd, MdPrmTs3* prm, s32 size);

void pppDrawMdlTs3Draw(pppPObject* pobj, PDrawMdlTs3D* p, pppCtrlTable* ctbl) {
    f32* t = (f32*)&pobj->val[ctbl->useVal[2]];
    VDrawMdlTs3* v;
    pppModelSt* mdl;
    OMD_H* omd;
    pppPObject* next;
    MdPrmTs3 prm;
    FMATRIX m;

    if (p->index == 0xFFFF) {
        return;
    }
    v = (VDrawMdlTs3*)&pobj->val[ctbl->useVal[0]];
    prm.col[3] = v->col[3];
    if (prm.col[3] == 0) {
        return;
    }
    mdl = &ppvEnv->lpModel[p->index];
    omd = mdl->omd;
    prm.mode = 0;
    if (p->flag & 2) {
        prm.mode = 4;
        if (!(omd->flag & 1)) {
            prm.mode |= 8;
        }
    } else {
        if (p->flag & 1) {
            prm.mode = 0x80;
        }
        if (!(omd->flag & 1)) {
            prm.mode |= 8;
        }
    }
    if (!(omd->flag & 2)) {
        prm.mode |= 0x10;
    }
    if (p->unk_21) {
        prm.mode |= 0x200;
    }
    if (p->unk_23) {
        prm.mode |= 0x100;
    }
    if (p->unk_22) {
        prm.mode |= 0x2000;
        prm.unk_30 = &m;
        sceVu0MulMatrix(m, ppvWorldMatrix, ppvPObj.next->cmat);
    }
    if (p->unk_24) {
        prm.unk_44 = &pobj->val[ctbl->useVal[3]];
    } else {
        prm.unk_44 = 0;
    }
    prm.flag = *(u16*)&omd->alpha; // alpha and alphaFix as one u16
    prm.unk_0A = 0;
    prm.unk_1C = 0;
    next = ppvPObj.next;
    prm.lpvert = next->lpvert;
    prm.lpnorm = next->lpnorm;
    prm.unk_04 = D_00616240;
    prm.col[0] = v->col[0];
    prm.col[1] = v->col[1];
    prm.col[2] = v->col[2];
    prm.dmat = &next->dmat;
    prm.unk_24 = D_00616140;
    prm.unk_28 = D_00616100;
    prm.cmat = &next->cmat;
    prm.unk_0C = 0;
    prm.unk_34 = D_00616224;
    prm.unk_10 = t[0] * 65536.0f;
    prm.unk_14 = t[3] * 65536.0f;
    prm.unk_40 = 0;
    prm.unk_4C = 0;
    prm.unk_4D = p->unk_25;
    D_00616224 = op1_md_draw(omd, &prm, mdl->nPacketSize);
}

