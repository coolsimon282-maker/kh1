#include "ppp.h"

typedef struct {
    /* 0x0 */ pppCDT cdt;
    /* 0x4 */ s32 dataNo;
    /* 0x8 */ s32 valOfs;
} PPObjPoint;

typedef struct {
    /* 0x0 */ f32 x;
    /* 0x4 */ f32 y;
    /* 0x8 */ f32 z;
    /* 0xC */ f32* src;
} VPObjPoint;

// follows a position kept in another particle object's values (ppvDbgTemp when there is none)
void pppPObjPointCalc(pppPObject* pobj, PPObjPoint* p, pppCtrlTable* ctbl) {
    VPObjPoint* v;

    if (ppvUserStopPartF != 0 || ppvMng->stop || ppvMng->unk_B4 != 0) {
        return;
    }
    v = (VPObjPoint*)&pobj->val[ctbl->useVal[0]];
    if (p->cdt.time == pobj->time) {
        v->src = (p->dataNo != -1)
                     ? (f32*)&((pppPDataVal*)ppvMng->unk_80)[p->dataNo].pobj->val[p->valOfs]
                     : (f32*)&ppvDbgTemp;
    }
    v->x = v->src[0];
    v->y = v->src[1];
    v->z = v->src[2];
}
