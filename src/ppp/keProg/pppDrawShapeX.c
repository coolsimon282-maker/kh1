#include "ppp.h"

typedef struct {
    /* 0x0 */ u16 wait;
    /* 0x2 */ u16 seq;
    /* 0x4 */ u16 seq_now;
} VDrawShapeX;

void pppDrawShapeXCon(pppPObject* pobj, pppCtrlTable* ctbl) {
    VDrawShapeX* vds = (VDrawShapeX*)&pobj->val[ctbl->useVal[0]];
    vds->seq_now = 0;
    vds->seq = 0;
    vds->wait = 0;
}

typedef struct {
    /* 0x0 */ pppCDT cdt;
    /* 0x4 */ s32 shpIdx;
    /* 0x8 */ u16 speed;
} PDrawShapeX;

typedef struct {
    /* 0x0 */ s16 unk_00;
    /* 0x2 */ s16 time;
    /* 0x4 */ s8 flag;
    /* 0x5 */ char unk_05[3];
} ShapeXSeq;

typedef struct {
    /* 0x00 */ char unk_00[0x6];
    /* 0x06 */ s16 nseq;
    /* 0x08 */ char unk_08[0x8];
    /* 0x10 */ ShapeXSeq seq[1];
} ShapeXHdr;

void pppDrawShapeXCalc(pppPObject* pobj, PDrawShapeX* p, pppCtrlTable* ctbl) {
    VDrawShapeX* v;
    ShapeXHdr* shp;
    ShapeXSeq* e;
    s32 flag;

    if (ppvUserStopPartF != 0 || ppvMng->stop || ppvMng->unk_B4 != 0) {
        return;
    }
    v = (VDrawShapeX*)&pobj->val[ctbl->useVal[0]];
    if (p->shpIdx == 0xFFFF) {
        return;
    }
    {
        pppShapeSt* st = &ppvEnv->lpShape[p->shpIdx];
        shp = (ShapeXHdr*)st->shape;
    }
    e = &shp->seq[v->seq_now];
    v->seq_now = v->seq;
    v->wait += p->speed;
    if (v->wait < e->time) {
        return;
    }
    v->wait -= e->time;
    v->seq++;
    if (v->seq < shp->nseq) {
        return;
    }
    flag = e->flag & 0x80;
    v->wait = 0;
    if (flag) {
        v->seq = 0;
    } else {
        v->seq--;
    }
}

INCLUDE_ASM("asm/nonmatchings/ppp/keProg/pppDrawShapeX", pppDrawShapeXDraw);
