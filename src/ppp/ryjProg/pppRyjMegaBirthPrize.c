#include "ppp.h"

typedef struct {
    /* 0x00 */ s32 shapeNo;
    /* 0x04 */ u8 col[4];
    /* 0x08 */ f32 scale;
} PrizeEnt;

typedef struct {
    /* 0x00 */ char unk_00[0x4];
    /* 0x04 */ PrizeEnt ent[10];
    /* 0x7C */ u16 speed;
    /* 0x7E */ u16 unk_7E;
    /* 0x80 */ u8 unk_80;
    /* 0x81 */ u8 unk_81;
} PRyjMegaBirthPrize;

typedef struct {
    /* 0x00 */ sceVu0FVECTOR pos;
    /* 0x10 */ f32 scale;
    /* 0x14 */ f32 alpha;
    /* 0x18 */ union {
        u64 flags;
        struct {
            u8 kind;
            u8 unk_19[3];
            s16 timer;
            s16 frame;
        } s;
    } u;
} PrizeObj;

typedef struct {
    /* 0x0 */ s16 seq;
    /* 0x2 */ s16 time;
    /* 0x4 */ s8 flag;
    /* 0x5 */ char unk_05[3];
} PrizeShpSeq;

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
} PrizeDrawSt;

extern s32 D_00616224;
extern sceVu0FMATRIX D_00615EB0;
extern PrizeObj* D_0061E310[];
extern s32 D_0061E710;
void func_0019F810(void);
s32 func_001BA340(void* shape, PrizeDrawSt* st, s32 size);

void pppRyjMegaBirthPrizeDraw(pppPObject* pobj, PRyjMegaBirthPrize* p, pppCtrlTable* ctbl) {
    sceVu0FMATRIX mtx[10];
    PrizeDrawSt ds;
    PrizeObj* e;
    PrizeEnt* ent;
    PrizeEnt* ents;
    pppShapeSt* lp;
    u8* shp;
    PrizeShpSeq* anm;
    u8* data;
    s32 kind;
    u16 old;
    s16 seq;
    f32(*m)[4];
    s16 frame;
    f32 alpha;
    s32 i;

    ds.flags = 0;
    ents = p->ent;
    if (p->unk_80) {
        ds.flags = 0x800;
    }
    if (p->unk_81) {
        ds.flags |= 0x400;
    }
    ds.unk_1C = NULL;
    ds.unk_08 = 0;
    ds.unk_18 = 0;
    ds.mat = ppvPObj.next->dmat[0];
    for (i = 0; i < 10; i++) {
        ent = &ents[i];
        sceVu0UnitMatrix(mtx[i]);
        sceVu0ScaleVector(mtx[i][0], mtx[i][0], ent->scale);
        sceVu0ScaleVector(mtx[i][1], mtx[i][1], ent->scale);
        sceVu0ScaleVector(mtx[i][2], mtx[i][2], ent->scale);
    }
    func_0019F810();
    for (i = 0; i < D_0061E710; i++) {
        e = D_0061E310[i];
        if (e->u.flags & 0x400) {
            e->u.s.timer = 0;
            e->u.s.frame = 0;
            e->u.flags &= ~0x400;
        }
        kind = e->u.s.kind;
        alpha = e->alpha;
        ent = (PrizeEnt*)(kind * 12 + (s32)ents);
        frame = e->u.s.frame;
        if (ent->shapeNo == 0xFFFF) {
            continue;
        }
        m = mtx[kind];
        lp = &ppvEnv->lpShape[ent->shapeNo];
        ds.col[0] = ent->col[0];
        ds.col[1] = ent->col[1];
        ds.col[2] = ent->col[2];
        ds.col[3] = ent->col[3] * alpha;
        shp = (u8*)lp->shape;
        anm = (PrizeShpSeq*)(shp + frame * 8 + 0x10);
        seq = anm->seq;
        sceVu0CopyMatrix(ppvPObj.next->dmat, m);
        data = shp + seq;
        sceVu0ApplyMatrix(ppvPObj.next->dmat[3], D_00615EB0, e->pos);
        sceVu0ScaleVector(ppvPObj.next->dmat[0], ppvPObj.next->dmat[0], e->scale);
        sceVu0ScaleVector(ppvPObj.next->dmat[1], ppvPObj.next->dmat[1], e->scale);
        sceVu0ScaleVector(ppvPObj.next->dmat[2], ppvPObj.next->dmat[2], e->scale);
        sceVu0MulMatrix(ppvPObj.next->dmat, ppvScreenMatrix, ppvPObj.next->dmat);
        ds.unk_14 = D_00616224;
        D_00616224 = func_001BA340(data, &ds, lp->nPacketSize);
        if (ppvUserStopPartF != 0 || ppvMng->stop || ppvMng->unk_B4 != 0) {
            continue;
        }
        e->u.s.timer += p->speed;
        if (e->u.s.timer >= anm->time) {
            e->u.s.timer -= anm->time;
            old = e->u.s.frame;
            e->u.s.frame = old + 1;
            if (e->u.s.frame >= *(s16*)(shp + 6)) {
                if (anm->flag & 0x80) {
                    e->u.s.frame = 0;
                    e->u.s.timer = 0;
                } else {
                    e->u.s.frame = old;
                    e->u.s.timer = 0;
                }
            }
        }
    }
}

extern u8 D_0035C710[];

void pppRyjMegaBirthPrizeCon(void) {
    memset(D_0035C710, 0, 0x2000);
    ppvMng->unk_B3 = 1;
    ppvMng->drawPriority = 1;
}

typedef struct {
    /* 0x00 */ char unk_00[0x8];
    /* 0x08 */ s32 unk_08;
    /* 0x0C */ char unk_0C[0x4];
    /* 0x10 */ sceVu0FVECTOR unk_10;
    /* 0x20 */ char unk_20[0x30];
} RyjPrize; // size = 0x50

typedef struct {
    /* 0x00 */ s32 unk_00;
    /* 0x04 */ s32 unk_04;
} RyjPrizeHdr;

typedef struct {
    /* 0x00 */ s32 unk_00;
    /* 0x04 */ RyjPrizeHdr* unk_04;
    /* 0x08 */ RyjPrize* unk_08;
} RyjPrizeMng;

extern RyjPrizeMng D_0035E710;

RyjPrize* func_0019FD18(s32 arg0) {
    RyjPrize* e = D_0035E710.unk_08;
    RyjPrize* ret = NULL;
    s32 i;
    if (e != NULL) {
        for (i = 0; i < D_0035E710.unk_04->unk_04; i++, e++) {
            if (arg0 == e->unk_08) {
                ret = e;
                break;
            }
        }
    }
    return ret;
}

typedef struct {
    /* 0x00 */ char unk_00[0x4];
    /* 0x04 */ s32 unk_04;
    /* 0x08 */ char unk_08[0x18];
    /* 0x20 */ f32 unk_20;
    /* 0x24 */ f32 unk_24;
    /* 0x28 */ f32 unk_28;
} RyjPrizeSrc;

typedef struct {
    /* 0x00 */ sceVu0FVECTOR pos;
    /* 0x10 */ RyjPrizeSrc* src;
    /* 0x14 */ RyjPrize* prize;
    /* 0x18 */ char unk_18[0x8];
} RyjPrizeSlot; // size = 0x20

typedef struct {
    /* 0x00 */ u32 unk_00;
    /* 0x04 */ u32 unk_04;
    /* 0x08 */ char unk_08[0x4];
    /* 0x0C */ RyjPrizeSlot* unk_0C;
    /* 0x10 */ RyjPrizeSlot* unk_10;
} RyjPrizeList;

s32 func_0019FD78(RyjPrizeList* l, RyjPrizeSrc* s) {
    u32 i;
    RyjPrizeSlot* e;

    if (l->unk_0C == NULL) {
        return 0;
    }
    for (i = 0; i < l->unk_00; i++) {
        e = &l->unk_0C[i];
        if (e->src == NULL) {
            e->src = s;
            e->prize = func_0019FD18(s->unk_04);
            sceVu0CopyVector(e->pos, e->prize->unk_10);
            e->pos[0] += s->unk_20;
            e->pos[1] += s->unk_24;
            e->pos[2] += s->unk_28;
            e->pos[3] = 1.0f;
            break;
        }
    }
    return 1;
}

s32 func_0019FE58(RyjPrizeList* l, RyjPrizeSrc* s) {
    u32 i;
    RyjPrizeSlot* e;

    if (l->unk_10 == NULL) {
        return 0;
    }
    for (i = 0; i < l->unk_04; i++) {
        e = &l->unk_10[i];
        if (e->src == NULL) {
            e->src = s;
            e->prize = func_0019FD18(s->unk_04);
            sceVu0CopyVector(e->pos, e->prize->unk_10);
            e->pos[0] += s->unk_20;
            e->pos[1] += s->unk_24;
            e->pos[2] += s->unk_28;
            e->pos[3] = 1.0f;
            break;
        }
    }
    return 1;
}

typedef struct {
    /* 0x00 */ char unk_00[0x4];
    /* 0x04 */ s32 unk_04;
    /* 0x08 */ char unk_08[0x1C];
    /* 0x24 */ f32 unk_24;
    /* 0x28 */ f32 unk_28;
    /* 0x2C */ f32 unk_2C;
    /* 0x30 */ char unk_30[0x10];
    /* 0x40 */ u8 unk_40;
    /* 0x41 */ u8 unk_41;
    /* 0x42 */ u8 unk_42;
} RyjPrizeSrc2;

typedef struct {
    /* 0x00 */ sceVu0FVECTOR pos;
    /* 0x10 */ RyjPrizeSrc2* src;
    /* 0x14 */ RyjPrize* prize;
    /* 0x18 */ char unk_18[0x4];
    /* 0x1C */ u8 unk_1C;
    /* 0x1D */ u8 unk_1D;
    /* 0x1E */ s16 unk_1E;
    /* 0x20 */ char unk_20[0x10];
} RyjPrizeSlot2; // size = 0x30

typedef struct {
    /* 0x00 */ char unk_00[0x8];
    /* 0x08 */ u32 unk_08;
    /* 0x0C */ char unk_0C[0x8];
    /* 0x14 */ RyjPrizeSlot2* unk_14;
} RyjPrizeList2;

s32 func_0019FF38(RyjPrizeList2* l, RyjPrizeSrc2* s) {
    u32 i;
    RyjPrizeSlot2* e;

    if (l->unk_14 == NULL) {
        return 0;
    }
    for (i = 0; i < l->unk_08; i++) {
        e = &l->unk_14[i];
        if (e->src == NULL) {
            e->src = s;
            e->prize = func_0019FD18(s->unk_04);
            e->unk_1C = s->unk_40;
            e->unk_1D = s->unk_41;
            e->unk_1E = 0x7FFF / s->unk_42;
            sceVu0CopyVector(e->pos, e->prize->unk_10);
            e->pos[0] += s->unk_24;
            e->pos[1] += s->unk_28;
            e->pos[2] += s->unk_2C;
            e->pos[3] = 1.0f;
            break;
        }
    }
    return 1;
}
