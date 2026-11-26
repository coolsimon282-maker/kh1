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
    /* 0xA */ char pad_0A[2];
    /* 0xC */ u8 unk_0C;
    /* 0xD */ u8 unk_0D;
    /* 0xE */ u8 unk_0E;
    /* 0xF */ u8 unk_0F;
    /* 0x10 */ u8 unk_10;
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

typedef struct {
    /* 0x00 */ s16 unk_00;
    /* 0x02 */ u16 flags;
    /* 0x04 */ u8 col[4];
    /* 0x08 */ u64 unk_08;
    /* 0x10 */ f32* mat;
    /* 0x14 */ s32 unk_14;
    /* 0x18 */ u8 unk_18;
    /* 0x1C */ void* unk_1C;
    /* 0x20 */ char unk_20[0x10];
} ShapeXDrawSt;

typedef struct {
    /* 0x0 */ char unk_00[0x8];
    /* 0x8 */ u8 col[4];
} VDrawShapeXCol;

extern s32 D_00616224;
s32 op_shape_draw(void* shape, ShapeXDrawSt* st, s32 size);

void pppDrawShapeXDraw(pppPObject* pobj, PDrawShapeX* p, pppCtrlTable* ctbl) {
    VDrawShapeX* v = (VDrawShapeX*)&pobj->val[ctbl->useVal[0]];
    VDrawShapeXCol* c = (VDrawShapeXCol*)&pobj->val[ctbl->useVal[1]];
    pppShapeSt* st;
    ShapeXHdr* shp;
    u8* data;
    ShapeXSeq* e;
    ShapeXDrawSt ds;

    if (p->shpIdx == 0xFFFF) {
        return;
    }
    st = &ppvEnv->lpShape[p->shpIdx];
    if (p->unk_0F == 0) {
        ds.flags = 0x80;
    } else {
        ds.flags = 0;
    }
    if (p->unk_10 == 1) {
        ds.flags |= 0x10;
    }
    if (p->unk_0C) {
        ds.flags |= 0x800;
    }
    if (p->unk_0D) {
        ds.flags |= 0x400;
    }
    if (p->unk_0E) {
        ds.unk_1C = &pobj->val[ctbl->useVal[3]];
    } else {
        ds.unk_1C = NULL;
    }
    ds.mat = ppvPObj.next->dmat[0];
    ds.col[0] = c->col[0];
    ds.col[1] = c->col[1];
    ds.col[2] = c->col[2];
    ds.col[3] = c->col[3];
    ds.unk_08 = 0;
    ds.unk_18 = 0;
    shp = (ShapeXHdr*)st->shape;
    e = &shp->seq[v->seq_now];
    data = (u8*)shp + e->unk_00;
    ds.unk_14 = D_00616224;
    D_00616224 = op_shape_draw(data, &ds, st->nPacketSize);
}
