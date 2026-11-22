#include "ppp/pppKeLns.h"

typedef struct {
    /* 0x00 */ pppCDT cdt;
    /* 0x04 */ s32 shpIdx;
    /* 0x08 */ u8 col[4];
    /* 0x0C */ f32 unk_0C;
    /* 0x10 */ u8 unk_10[4];
    /* 0x14 */ u16 unk_14;
} PKeLnsClmDraw;

typedef struct {
    /* 0x00 */ KeLnsClm* clm;
    /* 0x04 */ u8 col[4];
    /* 0x08 */ sceVu0FVECTOR* scr;
    /* 0x0C */ f32 unk_0C;
    /* 0x10 */ f32 unk_10;
    /* 0x14 */ f32* scl;
} KeLnsClmDrawInfo;

void func_00193BC8(pppPObject* pobj, PKeLnsClmDraw* p, pppCtrlTable* ctbl);
void func_001A7C40(KeLnsClmDrawInfo* info, s32 arg1);

void pppKeLnsClmDraw(pppPObject* pobj, PKeLnsClmDraw* p, pppCtrlTable* ctbl) {
    KeLnsClmDrawInfo info;

    func_00193BC8(pobj, p, ctbl);
    info.unk_10 = p->unk_14;
    info.col[0] = p->col[0] * ppvMng->colorR;
    info.col[1] = p->col[1] * ppvMng->colorG;
    info.col[2] = p->col[2] * ppvMng->colorB;
    info.col[3] = p->col[3] * ppvMng->colorA;
    info.scr = ppvScreenMatrix;
    info.unk_0C = p->unk_0C;
    info.clm = (KeLnsClm*)&pobj->val[ctbl->useVal[0]];
    info.scl = ppvParScl;
    func_001A7C40(&info, 0);
}

void pppKeLnsClmCon(pppPObject* pobj, pppCtrlTable* ctbl) {
    KeLnsClm* clm = (KeLnsClm*)&pobj->val[ctbl->useVal[0]];
    
    KeLnsClm_Init(clm);
    clm->num = 4;
}

typedef struct {
    /* 0x0 */ pppCDT cdt;
    /* 0x4 */ s32 shpIdx;
} PKeLnsClm;

void func_001A84B8(KeLnsClm* p, pppShapeSt* shp);

void func_00193E80(pppPObject* pobj, PKeLnsClm* p, pppCtrlTable* ctbl) {
    KeLnsClm* clm = (KeLnsClm*)&pobj->val[ctbl->useVal[0]];
    pppShapeSt* shp;

    if (p->cdt.time == pobj->time) {
        *(s32*)&clm->lp = (s32)&pobj->val[ctbl->useVal[1]];
        if (p->shpIdx == 0xFFFF) {
            clm->shp = NULL;
        } else {
            shp = &ppvEnv->lpShape[p->shpIdx];
            if (shp != clm->shp) {
                func_001A84B8(clm, shp);
            }
        }
    }
}
