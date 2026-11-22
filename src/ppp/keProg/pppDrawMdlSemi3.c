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
} MdPrm;

typedef struct {
    /* 0x0 */ pppCDT cdt;
    /* 0x4 */ u32 index;
    /* 0x8 */ u16 flag;
    /* 0xA */ u8 mode;
    /* 0xB */ u8 unk_0B;
    /* 0xC */ u8 unk_0C;
    /* 0xD */ u8 unk_0D;
    /* 0xE */ u8 unk_0E;
} PDrawMdlSemi3;

typedef struct {
    /* 0x0 */ char unk_00[8];
    /* 0x8 */ u8 col[4];
} VDrawMdl;

extern char D_00616240[];
extern char D_00616140[];
extern char D_00616100[];
extern s32 D_00616224;
s32 op1_md_draw(OMD_H* omd, MdPrm* prm, s32 size);

void pppDrawMdlSemi3Draw(pppPObject* pobj, PDrawMdlSemi3* p, pppCtrlTable* ctbl) {
    VDrawMdl* v;
    pppModelSt* mdl;
    OMD_H* omd;
    pppPObject* next;
    MdPrm prm;
    FMATRIX m;

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
    if (p->mode & 2) {
        prm.mode = 4;
        if (!(omd->flag & 1)) {
            prm.mode |= 8;
        }
    } else {
        if (p->mode & 1) {
            prm.mode = 0x80;
        }
        if (!(omd->flag & 1)) {
            prm.mode |= 8;
        }
    }
    if (!(omd->flag & 2)) {
        prm.mode |= 0x10;
    }
    if (p->unk_0B) {
        prm.mode |= 0x200;
    }
    if (p->unk_0D) {
        prm.mode |= 0x100;
    }
    if (p->unk_0C) {
        prm.mode |= 0x2000;
        prm.unk_30 = &m;
        sceVu0MulMatrix(m, ppvWorldMatrix, ppvPObj.next->cmat);
    }
    if (p->unk_0E) {
        prm.unk_44 = &pobj->val[ctbl->useVal[2]];
    } else {
        prm.unk_44 = 0;
    }
    prm.flag = p->flag;
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
    prm.unk_10 = 0;
    prm.unk_40 = 0;
    D_00616224 = op1_md_draw(omd, &prm, mdl->nPacketSize);
}
