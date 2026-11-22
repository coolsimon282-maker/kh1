#include "common.h"

#include "ppp/pppUtil.h"
#include "ppp/pppKeLns.h"

#include "libvu0.h"

s32 func_001AAF80(void);

// calls func n times with vertices of the model taken from vsf entry vsfNo (random ones if rnd); *idx keeps the
// position between calls
void KeBornRnd2(pppPObject* pobj, void* p, void (*func)(pppPObject*, void*, pppSVECTOR*), u16* idx, s16 vsfNo,
                u8 rnd, u8 n) {
    pppVsfSt* vsf = &ppvEnv->lpVsf[vsfNo];
    pppSVECTOR* vert = ppvPObj.next->lpvert;
    s32 i;

    if (vert == NULL) {
        vert = ppvEnv->lpModel[(s16)vsf->modelNo].vert;
    }
    if (rnd) {
        i = func_001AAF80() % (s16)vsf->indexN;
    } else {
        i = *idx;
    }
    while (n) {
        func(pobj, p, &vert[(u16)vsf->index[i]]);
        i++;
        if (rnd) {
            i = func_001AAF80() % (s16)vsf->indexN;
        } else if (i >= (s16)vsf->indexN) {
            i = 0;
        }
        n--;
    }
    *idx = i;
}

// reads the u16 at 0x12 of the shape data (a count; maybe its number of frames)
void func_001A75B0(KeLnsFlr* flr, pppShapeSt* shp) {
    flr->cnt = ((u16*)shp->shape)[9];
    flr->seqIdx = 0;
}

// shape animation frames: 8-byte entries from 0x10 of the shape data; the frame count is the s16 at 0x6
typedef struct {
    /* 0x0 */ s16 unk_0;
    /* 0x2 */ s16 time;
    /* 0x4 */ s8 flag; // 0x80: loop back to the first frame
    /* 0x5 */ u8 unk_5[3];
} KeLnsSeq; // size = 0x8

typedef struct {
    /* 0x0 */ pppShapeSt* shp;
    /* 0x4 */ KeLnsFlr* flr;
} KeLnsFlrRef;

// steps the shape animation by 0x200
void func_001A75C8(KeLnsFlrRef* p) {
    KeLnsFlr* flr = p->flr;
    KeLnsSeq* seq = (KeLnsSeq*)(p->shp->shape + 1) + flr->seqIdx;

    flr->cnt += 0x200;
    if (flr->cnt >= seq->time) {
        flr->cnt -= seq->time;
        flr->seqIdx++;
        if (flr->seqIdx >= ((s16*)p->shp->shape)[3]) {
            if (seq->flag & 0x80) {
                flr->seqIdx = 0;
                flr->cnt = 0;
            } else {
                flr->cnt = 0;
                flr->seqIdx--;
            }
        }
    }
}

typedef struct {
    /* 0x00 */ pppShapeSt* shp;
    /* 0x04 */ KeLnsFlr* flr;
    /* 0x08 */ u8 unk_08[8];
    /* 0x10 */ u16 unk_10;
    /* 0x12 */ u16 unk_12;
    /* 0x14 */ s32 unk_14;
    /* 0x18 */ s32 unk_18;
    /* 0x1C */ s16 unk_1C;
    /* 0x1E */ s16 unk_1E;
    /* 0x20 */ s32 unk_20;
    /* 0x24 */ s32 unk_24;
    /* 0x28 */ u8 unk_28;
} KeLnsShpDraw;

extern s32 D_00616224;

s32 func_001BA340(void*, void*, s32);

// sets up the draw of the current shape frame (func_001BA340 is in ppp/draw/md0)
void func_001A7668(KeLnsShpDraw* p) {
    KeLnsSeq* seq = (KeLnsSeq*)(p->shp->shape + 1) + p->flr->seqIdx;

    p->unk_18 = 0;
    p->unk_28 = 0;
    p->unk_24 = D_00616224;
    p->unk_12 |= 0x30;
    p->unk_1C = 0x12;
    D_00616224 = func_001BA340((u8*)p->shp->shape + seq->unk_0, &p->unk_10, 0);
}

INCLUDE_ASM("asm/nonmatchings/ppp/xberry", func_001A76E8);

void KeLnsLp_Init(KeLnsLp* lp) {
    ppvMng->drawPriority = 2;
    sceVu0UnitMatrix(lp->zMat);
    lp->preHidePow = 1.0f;
}

INCLUDE_ASM("asm/nonmatchings/ppp/xberry", func_001A7C40);

// flag bit 0 is written with plain byte ops but read as a bitfield
typedef union {
    u8 b;
    struct {
        u8 seeded : 1;
        u8 rest : 7;
    } f;
} KeLnsClmFlag;

// sets the shape of every flare and, once, their random phases (rdPr) from seed
void func_001A7F48(KeLnsClm* p, pppShapeSt* shp, s32 seed) {
    s32 i;
    s32 r;

    p->shp = shp;
    for (i = 0; i < p->num; i++) {
        func_001A75B0(&p->flr[i].flr, shp);
    }
    if (!((KeLnsClmFlag*)&p->flag)->f.seeded) {
        r = seed;
        for (i = 0; i < p->num; i++) {
            r = (r * 0x80D + 7) & 0xFFFF;
            p->flr[i].rdPr = r / 65535.0f;
        }
        p->flag |= 1;
    }
}

void KeLnsClm_Init(KeLnsClm* p) {
    p->flag = 0;
    p->lp = &ppvDbgTemp;
    p->shp = NULL;
}

typedef struct {
    /* 0x0 */ KeLnsLp* lp;
    /* 0x4 */ pppShapeSt* shp;
    /* 0x8 */ KeLnsFlr flr;
} KeLnsShp;

typedef struct {
    /* 0x00 */ KeLnsShp* shp;
    /* 0x04 */ s32 col;
    /* 0x08 */ f32 (*mat)[4];
    /* 0x0C */ f32 scale;
    /* 0x10 */ f32* scl;
} KeLnsShpArg;

// KeLnsShpDraw as filled here
typedef struct {
    /* 0x00 */ pppShapeSt* shp;
    /* 0x04 */ KeLnsFlr* flr;
    /* 0x08 */ u8 unk_08[8];
    /* 0x10 */ u16 unk_10;
    /* 0x12 */ u16 unk_12;
    /* 0x14 */ u8 col[4];
    /* 0x18 */ s32 unk_18;
    /* 0x1C */ s32 unk_1C;
    /* 0x20 */ f32 (*mat)[4];
    /* 0x24 */ s32 unk_24;
    /* 0x28 */ s32 unk_28;
    /* 0x2C */ s32 unk_2C;
    /* 0x30 */ u8 unk_30[0x10];
} KeLnsShpPrm;

// draws a flare shape at the lens position, scaled, with its alpha scaled by the lens power
void func_001A8060(KeLnsShpArg* arg, s32 arg1) {
    sceVu0FMATRIX m;
    KeLnsShpPrm prm;
    KeLnsShp* shp = arg->shp;
    KeLnsLp* lp = shp->lp;
    f32 s;

    if (lp == (KeLnsLp*)&ppvDbgTemp) {
        return;
    }
    if (shp->shp == NULL) {
        return;
    }
    if (lp->vPow == 0.0f) {
        return;
    }
    if (lp->md) {
        sceVu0CopyMatrix(m, lp->mat);
    } else {
        sceVu0UnitMatrix(m);
        m[3][0] = ppvWorldMatrix[3][0] + lp->lcPos[0];
        m[3][1] = ppvWorldMatrix[3][1] + lp->lcPos[1];
        m[3][2] = ppvWorldMatrix[3][2] + lp->lcPos[2];
    }
    s = arg->scale;
    m[0][0] *= s;
    m[1][1] *= s;
    sceVu0ScaleVector(m[0], m[0], arg->scl[0]);
    sceVu0ScaleVector(m[1], m[1], arg->scl[1]);
    sceVu0ScaleVector(m[2], m[2], arg->scl[2]);
    sceVu0MulMatrix(m, arg->mat, m);
    *(s32*)prm.col = arg->col;
    prm.col[3] = prm.col[3] * lp->vPow;
    prm.shp = shp->shp;
    prm.flr = &shp->flr;
    func_001A75C8((KeLnsFlrRef*)&prm);
    prm.unk_12 = arg1;
    prm.mat = m;
    prm.unk_2C = 0;
    prm.unk_18 = 0;
    prm.unk_1C = 0;
    func_001A7668((KeLnsShpDraw*)&prm);
}

void KeLnsArnd_Init(KeLnsArnd* p) {
    p->shp = NULL;
    p->lp = &ppvDbgTemp;
}

INCLUDE_ASM("asm/nonmatchings/ppp/xberry", func_001A8248);

void func_001A84B8(KeLnsCrn* p, pppShapeSt* shp) {
    p->shp = shp;
    func_001A75B0(&p->flr, shp);
}

void KeLnsCrn_Init(KeLnsCrn* p) {
    p->shp = NULL;
    p->lp = &ppvDbgTemp;
}

INCLUDE_ASM("asm/nonmatchings/ppp/xberry", KeLnsFls_Draw);

void KeLnsFls_Init(KeLnsFls* p) {
    p->shp = NULL;
    p->lp = &ppvDbgTemp;
}

typedef struct XBerryNode {
    /* 0x00 */ u8 unk_00[0x8];
    /* 0x08 */ struct XBerryNode* next;
    /* 0x0C */ s32 unk_0C;
    /* 0x10 */ u8 unk_10[0x2E];
    /* 0x3E */ u16 flags;
} XBerryNode;

typedef struct {
    /* 0x00 */ u8 unk_00[0x18];
    /* 0x18 */ XBerryNode* list;
} XBerryNodeOwner;

void func_001A8770(XBerryNodeOwner* arg0, s32 flags) {
    XBerryNode* node = arg0->list;

    flags |= 8;
    while (node != NULL) {
        node->unk_0C = 0;
        node->flags |= flags;
        node = node->next;
    }
}
