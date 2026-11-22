#include "ppp/pppKeLns.h"

typedef struct {
    /* 0x00 */ pppCDT cdt;
    /* 0x04 */ s32 shpIdx;
    /* 0x08 */ u8 col[4];
    /* 0x0C */ f32 unk_0C;
    /* 0x10 */ u16 unk_10;
    /* 0x12 */ u16 unk_12;
} PKeLnsCrnDraw;

typedef struct {
    /* 0x00 */ KeLnsCrn* crn;
    /* 0x04 */ u8 col[4];
    /* 0x08 */ sceVu0FVECTOR* scr;
    /* 0x0C */ f32 unk_0C;
    /* 0x10 */ u16 unk_10;
    /* 0x12 */ u16 unk_12;
    /* 0x14 */ f32* scl;
} KeLnsCrnDrawInfo;

void func_00193E80(pppPObject* pobj, PKeLnsCrnDraw* p, pppCtrlTable* ctbl);
void func_001A8248(KeLnsCrnDrawInfo* info, s32 arg1);

void pppKeLnsCrnDraw(pppPObject* pobj, PKeLnsCrnDraw* p, pppCtrlTable* ctbl) {
    KeLnsCrnDrawInfo info;

    func_00193E80(pobj, p, ctbl);
    info.col[0] = p->col[0] * ppvMng->colorR;
    info.col[1] = p->col[1] * ppvMng->colorG;
    info.col[2] = p->col[2] * ppvMng->colorB;
    info.col[3] = p->col[3] * ppvMng->colorA;
    info.unk_10 = p->unk_10;
    info.unk_12 = p->unk_12;
    info.scr = ppvScreenMatrix;
    info.unk_0C = p->unk_0C;
    info.crn = (KeLnsCrn*)&pobj->val[ctbl->useVal[0]];
    info.scl = ppvParScl;
    func_001A8248(&info, 0);
}

void pppKeLnsCrnCon(pppPObject* pobj, pppCtrlTable* ctbl) {
    KeLnsCrn* crn = (KeLnsCrn*)&pobj->val[ctbl->useVal[0]];

    KeLnsCrn_Init(crn);
}

typedef struct {
    /* 0x0 */ pppCDT cdt;
    /* 0x4 */ s32 shpNo;
} PKeLnsCrnShp;

void func_001940F0(pppPObject* pobj, PKeLnsCrnShp* p, pppCtrlTable* ctbl) {
    KeLnsCrn* v = (KeLnsCrn*)&pobj->val[ctbl->useVal[0]];
    pppShapeSt* shp;

    if (p->cdt.time == pobj->time) {
        *(s32*)&v->lp = (s32)&pobj->val[ctbl->useVal[1]];
        if (p->shpNo == 0xFFFF) {
            v->shp = NULL;
            return;
        }
        shp = &ppvEnv->lpShape[p->shpNo];
        if (shp != v->shp) {
            *(s32*)&v->shp = (s32)shp;
            v->flr.cnt = ((u16*)*(s32*)shp)[9];
            v->flr.seqIdx = 0;
        }
    }
}
