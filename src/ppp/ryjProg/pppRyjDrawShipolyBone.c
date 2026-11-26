#include "ppp.h"

s32 D_006105A4;

typedef struct {
    /* 0x00 */ u32 unFrameCt;
    /* 0x04 */ u8 bSmp;
    /* 0x05 */ u8 bStandby;
    /* 0x06 */ char dummy0[2];
    /* 0x08 */ sceVu0FVECTOR* pvecSmp;
    /* 0x0C */ char dummy1[4];
    /* 0x10 */ f32 avecBonePos[2][4];
} VRyjDrawShipolyBone;

void pppRyjDrawShipolyBoneCalc(void) {
}

INCLUDE_ASM("asm/nonmatchings/ppp/ryjProg/pppRyjDrawShipolyBone", func_0019D100);

INCLUDE_ASM("asm/nonmatchings/ppp/ryjProg/pppRyjDrawShipolyBone", pppRyjDrawShipolyBoneDraw);

void pppRyjDrawShipolyBoneCon(pppPObject* pobj, pppCtrlTable* ctbl) {
    VRyjDrawShipolyBone* p = (VRyjDrawShipolyBone*)&pobj->val[ctbl->useVal[1]];

    p->unFrameCt = 0;
    p->bSmp = 0;
    p->bStandby = 1;
    p->pvecSmp = NULL;
    ppvMng->unk_B3 = 1;
}

void pppRyjDrawShipolyBoneDes(pppPObject* pobj, pppCtrlTable* ctbl) {
    VRyjDrawShipolyBone* p = (VRyjDrawShipolyBone*)&pobj->val[ctbl->useVal[1]];

    if (p->pvecSmp != NULL) {
        pppFree(ppvEnv, p->pvecSmp);
        p->pvecSmp = NULL;
    }
}

static inline f32 vu0Rand(void) {
    f32 r;
    __asm__ volatile(
        "addi $8, $0, -1\n"
        "qmtc2.ni $8, $vf2\n"
        "vrxor R, $vf2x\n"
        "vrnext.x $vf1, R\n"
        "vrxor R, $vf2x\n"
        "vrnext.x $vf1, R\n"
        "vrxor R, $vf2x\n"
        "vrnext.x $vf1, R\n"
        "vrxor R, $vf2x\n"
        "vrnext.x $vf1, R\n"
        "vrxor R, $vf2x\n"
        "vrnext.x $vf1, R\n"
        "vitof0.x $vf2, $vf2\n"
        "vadd.x $vf1, $vf1, $vf2\n"
        "qmfc2.ni %0, $vf1\n"
        : "=r"(r) : : "$8");
    return r;
}

// VU0 random number in [0, 1)
f32 RyjShipolyBone_Rand(void) {
    return vu0Rand();
}

f32 RyjShipolyBone_Rand(void); // VU0 random number in [0, 1)

// a random value in about [-a / 2, a * 3 / 2)
s8 RyjShipolyBone_RandSpread(u8 a) {
    return (a * 2) * RyjShipolyBone_Rand() - (a / 2);
}

typedef struct {
    /* 0x00 */ u8 unk_00[0x50];
    /* 0x50 */ s32 unk_50;
    /* 0x54 */ s32 unk_54;
    /* 0x58 */ s32 unk_58;
} RyjShipolyUnk1;

typedef struct {
    /* 0x00 */ u8 unk_00[0xC9];
    /* 0xC9 */ u8 unk_C9;
    /* 0xCA */ u8 unk_CA[2];
    /* 0xCC */ u8 unk_CC;
} RyjShipolyUnk2;

// True when the part data needed by the parameters is there.
s32 RyjShipolyBone_HasData(RyjShipolyUnk1* a, RyjShipolyUnk2* b) {
    if (a->unk_50 == 0) {
        return 0;
    }
    if ((b->unk_CC == 1 || b->unk_CC == 2) && a->unk_54 == 0) {
        return 0;
    }
    if (b->unk_C9 != 0 && a->unk_58 == 0) {
        return 0;
    }
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/ppp/ryjProg/pppRyjDrawShipolyBone", func_0019D898);

INCLUDE_ASM("asm/nonmatchings/ppp/ryjProg/pppRyjDrawShipolyBone", func_0019E520);

typedef struct {
    /* 0x00 */ s16 unk_00;
    /* 0x02 */ s16 time;
    /* 0x04 */ s8 flag;
    /* 0x05 */ char unk_05[3];
} RyjShpSeq;

typedef struct {
    /* 0x00 */ char unk_00[0x6];
    /* 0x06 */ s16 nseq;
    /* 0x08 */ char unk_08[0x8];
    /* 0x10 */ RyjShpSeq seq[1];
} RyjShpHdr;

typedef struct {
    /* 0x00 */ char unk_00[0x20];
    /* 0x20 */ u16 wait;
    /* 0x22 */ u16 seq;
    /* 0x24 */ u16 seq_now;
    /* 0x26 */ u16 active;
    /* 0x28 */ char unk_28[0x38];
} RyjShpPart;

typedef struct {
    /* 0x00 */ char unk_00[0x50];
    /* 0x50 */ RyjShpPart* part;
    /* 0x54 */ u8* wmat;
    /* 0x58 */ u8* col;
    /* 0x5C */ s32 nPart;
    /* 0x60 */ u16 count;
} RyjShpV;

typedef struct {
    /* 0x00 */ char unk_00[0x4];
    /* 0x04 */ s32 shpIdx;
    /* 0x08 */ u16 speed;
    /* 0x0A */ char unk_0A[0x14];
    /* 0x1E */ u16 nBirth;
    /* 0x20 */ u16 interval;
} RyjShpP;

void func_0019E520(RyjShpV* v, RyjShpP* p, RyjShpPart* e, void* c, u8* s);
NOTHROW(void, func_0019D898);

void func_0019E8B0(RyjShpV* v, RyjShpP* p, void* c) {
    RyjShpPart* e = v->part;
    u8* t = v->wmat;
    u8* s = v->col;
    s32 n = v->nPart;
    s32 cnt = 0;
    s32 i;

    if (ppvUserStopPartF != 0 || ppvMng->stop || ppvMng->unk_B4 != 0) {
        return;
    }
    if (p->shpIdx == 0xFFFF) {
        return;
    }
    v->count++;
    for (i = 0; i < n; i++) {
        if (e->active != 0) {
            pppShapeSt* st;
            RyjShpHdr* shp;
            RyjShpSeq* q;

            func_0019E520(v, p, e, c, s);
            st = &ppvEnv->lpShape[p->shpIdx];
            shp = (RyjShpHdr*)st->shape;
            q = &shp->seq[e->seq_now];
            e->seq_now = e->seq;
            e->wait += p->speed;
            if (e->wait >= q->time) {
                e->wait -= q->time;
                e->seq++;
                if (e->seq >= shp->nseq) {
                    if (q->flag & 0x80) {
                        e->seq = 0;
                        e->wait = 0;
                    } else {
                        e->wait = 0;
                        e->seq--;
                    }
                }
            }
        } else if (p->interval <= v->count && cnt < p->nBirth) {
            func_0019D898(v, p, c, e, t, s);
            cnt++;
        }
        if (t != NULL) {
            t += 0x40;
        }
        if (s != NULL) {
            s += 0x20;
        }
        e++;
    }
    if (cnt > 0) {
        v->count = 0;
    }
}
