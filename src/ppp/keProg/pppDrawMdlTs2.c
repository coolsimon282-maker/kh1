#include "ppp.h"

typedef struct {
    /* 0x00 */ f32 unk_00;
    /* 0x04 */ f32 unk_04;
    /* 0x08 */ f32 unk_08;
    /* 0x0C */ f32 unk_0C;
    /* 0x10 */ f32 unk_10;
    /* 0x14 */ f32 unk_14;
} VDrawMdlTs2;

void pppDrawMdlTs2Con(pppPObject* pobj, pppCtrlTable* ctbl) {
    VDrawMdlTs2* v = (VDrawMdlTs2*)&pobj->val[ctbl->useVal[2]];

    v->unk_00 = v->unk_04 = v->unk_08 = v->unk_0C = v->unk_10 = v->unk_14 = 0.0f;
}

typedef struct {
    /* 0x00 */ pppCDT cdt;
    /* 0x04 */ u32 index;
    /* 0x08 */ f32 add[6];
    /* 0x20 */ u8 flag;
    /* 0x21 */ u8 unk_21;
} PDrawMdlTs2;

void pppDrawMdlTs2Calc(pppPObject* pobj, PDrawMdlTs2* p, pppCtrlTable* ctbl) {
    VDrawMdlTs2* v = (VDrawMdlTs2*)&pobj->val[ctbl->useVal[2]];

    if (ppvUserStopPartF != 0 || ppvMng->stop || ppvMng->unk_B4 != 0) {
        return;
    }
    v->unk_04 += v->unk_08;
    v->unk_10 += v->unk_14;
    v->unk_00 += v->unk_04;
    v->unk_0C += v->unk_10;
    if (p->cdt.time != pobj->time) {
        return;
    }
    v->unk_00 += p->add[0];
    v->unk_04 += p->add[1];
    v->unk_08 += p->add[2];
    v->unk_0C += p->add[3];
    v->unk_10 += p->add[4];
    v->unk_14 += p->add[5];
}

// parameter block for op1_md_draw
typedef struct {
    /* 0x00 */ s32 mode;
    /* 0x04 */ void* unk_04;
    /* 0x08 */ u16 flag;
    /* 0x0A */ u8 unk_0A;
    /* 0x0C */ s32 unk_0C;
    /* 0x10 */ s32 unk_10[2];
    /* 0x18 */ u8 col[4];
    /* 0x1C */ s32 unk_1C;
    /* 0x20 */ FMATRIX* dmat;
    /* 0x24 */ void* unk_24;
    /* 0x28 */ void* unk_28;
    /* 0x2C */ FMATRIX* cmat;
    /* 0x30 */ s32 unk_30;
    /* 0x34 */ s32 unk_34;
    /* 0x38 */ pppSVECTOR* lpvert;
    /* 0x3C */ pppSVECTOR* lpnorm;
    /* 0x40 */ s32 unk_40;
    /* 0x44 */ FMATRIX* unk_44;
    /* 0x48 */ s32 unk_48;
    /* 0x4C */ u8 unk_4C;
    /* 0x4D */ u8 unk_4D;
    /* 0x4E */ char pad[0x12];
} MdPrm;

typedef struct {
    /* 0x0 */ char unk_00[8];
    /* 0x8 */ u8 col[4];
} VDrawMdl;

extern char D_00616240[];
extern char D_00616140[];
extern char D_00616100[];
extern s32 D_00616224;
s32 op1_md_draw(OMD_H* omd, MdPrm* prm, s32 size);

void pppDrawMdlTs2Draw(pppPObject* pobj, PDrawMdlTs2* p, pppCtrlTable* ctbl) {
    VDrawMdlTs2* ts = (VDrawMdlTs2*)&pobj->val[ctbl->useVal[2]];
    VDrawMdl* v;
    pppModelSt* mdl;
    OMD_H* omd;
    pppPObject* next;
    MdPrm prm;

    if (p->index == 0xFFFF) {
        return;
    }
    v = (VDrawMdl*)&pobj->val[ctbl->useVal[0]];
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
    next = ppvPObj.next;
    prm.flag = *(u16*)&omd->alpha;
    prm.unk_0A = 0;
    prm.unk_1C = 0;
    prm.lpvert = next->lpvert;
    prm.lpnorm = next->lpnorm;
    prm.unk_04 = D_00616240;
    prm.unk_0C = 0;
    prm.unk_10[0] = ts->unk_00 * 65536.0f;
    prm.unk_10[1] = ts->unk_0C * 65536.0f;
    prm.col[0] = v->col[0];
    prm.col[1] = v->col[1];
    prm.unk_40 = 0;
    prm.col[2] = v->col[2];
    prm.unk_44 = &next->dmat;
    prm.dmat = &next->dmat;
    prm.unk_24 = D_00616140;
    prm.unk_28 = D_00616100;
    prm.cmat = &next->cmat;
    prm.unk_34 = D_00616224;
    prm.unk_4C = 0;
    prm.unk_4D = p->unk_21;
    D_00616224 = op1_md_draw(omd, &prm, mdl->nPacketSize);
}
