#include "ppp.h"

typedef struct {
    /* 0x0 */ u16 wait;
    /* 0x2 */ u16 seq;
    /* 0x4 */ u16 seq_now;
} VDrawShape;

void pppDrawShapeCon(pppPObject* pobj, pppCtrlTable* ctbl) {
    VDrawShape* vds = (VDrawShape*)&pobj->val[ctbl->useVal[0]];
    vds->seq_now = 0;
    vds->seq = 0;
    vds->wait = 0;
}

typedef struct {
    /* 0x0 */ pppCDT cdt;
    /* 0x4 */ s32 shapeNo;
    /* 0x8 */ u16 speed;
} PDrawShape;

typedef struct {
    /* 0x0 */ s16 ofs;
    /* 0x2 */ s16 time;
    /* 0x4 */ s8 flag;
    /* 0x5 */ char pad[3];
} ShpAnm;

void pppDrawShapeCalc(pppPObject* pobj, PDrawShape* p, pppCtrlTable* ctbl) {
    VDrawShape* vds;
    u8* shp;
    ShpAnm* anm;
    pppShapeSt* lp;

    if (ppvUserStopPartF != 0 || ppvMng->stop || ppvMng->unk_B4 != 0) {
        return;
    }
    vds = (VDrawShape*)&pobj->val[ctbl->useVal[0]];
    if (p->shapeNo == 0xFFFF) {
        return;
    }
    lp = ppvEnv->lpShape;
    lp += p->shapeNo;
    shp = (u8*)lp->shape;
    anm = (ShpAnm*)(shp + 0x10) + vds->seq_now;
    vds->seq_now = vds->seq;
    vds->wait += p->speed;
    if (vds->wait >= anm->time) {
        vds->wait -= anm->time;
        vds->seq++;
        if (vds->seq >= *(s16*)(shp + 6)) {
            if (anm->flag & 0x80) {
                vds->seq = 0;
                vds->wait = 0;
            } else {
                vds->seq--;
                vds->wait = 0;
            }
        }
    }
}


INCLUDE_ASM("asm/nonmatchings/ppp/eiProg/pppDrawShape", pppDrawShapeDraw);
