#include "ppp.h"

// parameter block for op1_md_draw
typedef struct {
    /* 0x00 */ s32 mode;
    /* 0x04 */ void* unk_04;
    /* 0x08 */ u16 flag;
    /* 0x0A */ u8 unk_0A;
    /* 0x0C */ s32 unk_0C;
    /* 0x10 */ u64 unk_10;
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
    /* 0x44 */ s32 unk_44;
    /* 0x48 */ char pad[0x18];
} MdPrm;

typedef struct {
    /* 0x0 */ pppCDT cdt;
    /* 0x4 */ u32 index;
    /* 0x8 */ u16 flag;
} PDrawMdlSemi;

typedef struct {
    /* 0x0 */ u16 col[4];
} VDrawMdlSemi;

extern char D_00616240[];
extern char D_00616140[];
extern char D_00616100[];
extern s32 D_00616224;
s32 op1_md_draw(OMD_H* omd, MdPrm* prm, s32 size);

void pppDrawMdlSemiDraw(pppPObject* pobj, PDrawMdlSemi* p, pppCtrlTable* ctbl) {
    VDrawMdlSemi* v;
    pppModelSt* mdl;
    MdPrm prm;
    OMD_H* omd;
    pppPObject* next;

    if (p->index == 0xFFFF) {
        return;
    }
    v = (VDrawMdlSemi*)&pobj->val[ctbl->useVal[0]];
    prm.col[3] = (s16)v->col[3] >> 7;
    if (prm.col[3] == 0) {
        return;
    }
    mdl = &ppvEnv->lpModel[p->index];
    omd = mdl->omd;
    prm.mode = 0x80;
    if (!(omd->flag & 2)) {
        prm.mode = 0x90;
    }
    next = ppvPObj.next;
    prm.flag = p->flag;
    prm.unk_0A = 0;
    prm.unk_1C = 0;
    prm.lpvert = next->lpvert;
    prm.lpnorm = next->lpnorm;
    prm.unk_0C = 0;
    prm.unk_04 = D_00616240;
    prm.unk_10 = 0;
    prm.col[0] = v->col[0] >> 7;
    prm.col[1] = v->col[1] >> 7;
    prm.col[2] = v->col[2] >> 7;
    prm.unk_40 = 0;
    prm.dmat = &next->dmat;
    prm.unk_24 = D_00616140;
    prm.unk_44 = 0;
    prm.unk_28 = D_00616100;
    prm.cmat = &next->cmat;
    prm.unk_34 = D_00616224;
    D_00616224 = op1_md_draw(omd, &prm, mdl->nPacketSize);
}
