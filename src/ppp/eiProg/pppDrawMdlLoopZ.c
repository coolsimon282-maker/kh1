#include "ppp.h"

#include "gcc/math.h"

typedef struct {
    /* 0x00 */ pppCDT cdt;
    /* 0x04 */ s32 m_model;
    /* 0x08 */ f32 m_tu;
    /* 0x0C */ f32 m_dtu;
    /* 0x10 */ f32 m_ddtu;
    /* 0x14 */ f32 m_tv;
    /* 0x18 */ f32 m_dtv;
    /* 0x1C */ f32 m_ddtv;
    /* 0x20 */ u8 m_acalc;
    /* 0x21 */ u8 m_afix;
    /* 0x22 */ u8 m_draw;
    /* 0x23 */ u8 m_fog;
    /* 0x24 */ u8 m_near;
    /* 0x25 */ u8 m_scis;
    /* 0x26 */ u8 m_26;
} PDrawMdlLoopZ;

typedef struct {
    /* 0x0 */ void* m_pp;
    /* 0x4 */ f32 m_tu;
    /* 0x8 */ f32 m_dtu;
    /* 0xC */ f32 m_ddtu;
    /* 0x10 */ f32 m_tv;
    /* 0x14 */ f32 m_dtv;
    /* 0x18 */ f32 m_ddtv;
    /* 0x1C */ f32 m_uv;
} VDrawMdlLoopZ;

void func_0018CC58(PDrawMdlLoopZ* p, VDrawMdlLoopZ* v) {
    v->m_tu = p->m_tu;
    v->m_tv = p->m_tv;
    v->m_dtu = v->m_ddtu = v->m_dtv = v->m_ddtv = 0.0f;
    v->m_pp = p;
}

void pppDrawMdlLoopZCon(pppPObject* pobj, pppCtrlTable* ctbl) {
    ((VDrawMdlLoopZ*)&pobj->val[ctbl->useVal[2]])->m_pp = NULL;
}

void pppDrawMdlLoopZCon2(pppPObject* pobj, pppCtrlTable* ctbl) {
    VDrawMdlLoopZ* vmdl = (VDrawMdlLoopZ*)&pobj->val[ctbl->useVal[2]];

    vmdl->m_dtu = vmdl->m_ddtu = vmdl->m_dtv = vmdl->m_ddtv = 0;
}

void pppDrawMdlLoopZDes(void) {
}

void pppDrawMdlLoopZCalc(pppPObject* pobj, PDrawMdlLoopZ* p, pppCtrlTable* ctbl) {
    VDrawMdlLoopZ* vmdl = (VDrawMdlLoopZ*)&pobj->val[ctbl->useVal[2]];
    PDrawMdlLoopZ* pmdl = (PDrawMdlLoopZ*)&pobj->val[ctbl->useVal[2]];

    if (vmdl->m_pp == NULL) {
        func_0018CC58(p, vmdl);
    }

    if (ppvUserStopPartF != 0 || ppvMng->stop || ppvMng->unk_B4 != 0) {
        return;
    }

    if (p->cdt.time == pobj->time) {
        pmdl->m_tu += p->m_dtu;
        pmdl->m_dtu += p->m_ddtu;
        pmdl->m_tv += p->m_dtv;
        pmdl->m_dtv += p->m_ddtv;
    }

    if (!ppvEmptyLoop) {
        vmdl->m_dtu += vmdl->m_ddtu;
        vmdl->m_dtv += vmdl->m_ddtv;
        vmdl->m_tu += vmdl->m_dtu;
        vmdl->m_tv += vmdl->m_dtv;
        vmdl->m_tu = fmodf(vmdl->m_tu, 32768.0f);
        vmdl->m_tv = fmodf(vmdl->m_tv, 32768.0f);
    }
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
    /* 0x0 */ char unk_00[8];
    /* 0x8 */ u8 col[4];
} VDrawMdl;

extern char D_00616240[];
extern char D_00616140[];
extern char D_00616100[];
extern s32 D_00616224;
s32 op1_md_draw(OMD_H* omd, MdPrm* prm, s32 size);

void pppDrawMdlLoopZDraw(pppPObject* pobj, PDrawMdlLoopZ* p, pppCtrlTable* ctbl) {
    VDrawMdlLoopZ* vmdl = (VDrawMdlLoopZ*)&pobj->val[ctbl->useVal[2]];
    VDrawMdl* v;
    OMD_H* omd;
    pppPObject* next;
    MdPrm prm;
    FMATRIX m;

    if (p->m_model == 0xFFFF) {
        return;
    }
    v = (VDrawMdl*)&pobj->val[ctbl->useVal[0]];
    omd = ppvEnv->lpModel[p->m_model].omd;
    prm.col[0] = v->col[0];
    prm.col[1] = v->col[1];
    prm.col[3] = v->col[3];
    prm.col[2] = v->col[2];
    if (prm.col[3] == 0) {
        return;
    }
    prm.mode = 0;
    if (p->m_draw & 2) {
        prm.mode = 4;
    } else if (p->m_draw & 1) {
        prm.mode = 0x80;
    }
    if (!(omd->flag & 1)) {
        prm.mode |= 8;
    }
    if (!(omd->flag & 2)) {
        prm.mode |= 0x10;
    }
    if (p->m_fog) {
        prm.mode |= 0x200;
    }
    if (p->m_near) {
        prm.mode |= 0x100;
    }
    if (p->m_scis) {
        prm.mode = (prm.mode & ~0x10) | 0x2000;
        prm.unk_30 = &m;
        sceVu0MulMatrix(m, ppvWorldMatrix, ppvPObj.next->cmat);
    } else {
        prm.unk_30 = 0;
    }
    prm.unk_04 = D_00616240;
    if (p->m_acalc == 0xFF) {
        prm.flag = *(u16*)&omd->alpha;
    } else {
        prm.flag = *(u16*)&p->m_acalc;
    }
    prm.unk_0A = 0;
    prm.unk_0C = 0;
    prm.unk_10[0] = vmdl->m_tu * 65536.0f;
    prm.unk_10[1] = vmdl->m_tv * 65536.0f;
    if (p->m_26) {
        prm.unk_44 = &pobj->val[ctbl->useVal[3]];
    } else {
        prm.unk_44 = 0;
    }
    prm.unk_1C = 0;
    next = ppvPObj.next;
    prm.dmat = &next->dmat;
    prm.unk_24 = D_00616140;
    prm.cmat = &next->cmat;
    prm.unk_28 = D_00616100;
    prm.unk_34 = D_00616224;
    prm.lpvert = next->lpvert;
    prm.lpnorm = next->lpnorm;
    prm.unk_40 = 0;
    prm.unk_4C = 0;
    prm.unk_4D = 0;
    D_00616224 = op1_md_draw(omd, &prm, ppvEnv->lpModel[p->m_model].nPacketSize);
}
