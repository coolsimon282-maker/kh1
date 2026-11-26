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

// parameter block for op1_md_draw
typedef struct {
    /* 0x00 */ s32 mode;
    /* 0x04 */ void* unk_04;
    /* 0x08 */ u16 flag;
    /* 0x0A */ u8 unk_0A;
    /* 0x0C */ s32 unk_0C;
    /* 0x10 */ u64 unk_10;
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
    /* 0x44 */ FMATRIX* unk_44;
    /* 0x48 */ s32 unk_48;
    /* 0x4C */ u8 unk_4C;
    /* 0x4D */ u8 unk_4D;
    /* 0x4E */ char pad[0x12];
} MdPrmB;

typedef struct {
    /* 0x00 */ pppCDT cdt;
    /* 0x04 */ u32 index;
    /* 0x08 */ u8 flag;
    /* 0x09 */ u8 unk_09;
    /* 0x0A */ u8 unk_0A;
    /* 0x0B */ u8 unk_0B;
    /* 0x0C */ u8 unk_0C;
    /* 0x0D */ u8 pad_0D[8];
    /* 0x15 */ u8 pad_15[0xF];
    /* 0x24 */ u8 unk_24;
} PRyjDrawShipolyB;

typedef struct {
    /* 0x0 */ char unk_00[8];
    /* 0x8 */ u8 col[4];
} VRyjDrawShipolyBC;

extern char D_00616240[];
extern char D_00616140[];
extern char D_00616100[];
extern s32 D_00616224;
extern sceVu0FMATRIX D_00616180;
extern sceVu0FVECTOR D_003701D0;
s32 op1_md_draw(OMD_H* omd, MdPrmB* prm, s32 size);

void func_0019D100(pppPObject* pobj, PRyjDrawShipolyB* p, pppCtrlTable* ctbl);
extern u8* D_002E26A0;

void pppRyjDrawShipolyBoneDraw(pppPObject* pobj, PRyjDrawShipolyB* p, pppCtrlTable* ctbl) {
    u8* obj;
    VRyjDrawShipolyBC* v;
    pppModelSt* mdl;
    OMD_H* omd;
    pppPObject* next;
    MdPrmB prm;
    sceVu0FMATRIX m;

    func_0019D100(pobj, p, ctbl);
    if (p->index == 0xFFFF) {
        return;
    }
    v = (VRyjDrawShipolyBC*)&pobj->val[ctbl->useVal[0]];
    obj = D_002E26A0;
    if (*(u8**)ppvMng->unk_A0 != NULL) {
        obj = *(u8**)ppvMng->unk_A0;
    }
    prm.col[3] = v->col[3];
    if (prm.col[3] == 0) {
        return;
    }
    mdl = &ppvEnv->lpModel[p->index];
    omd = mdl->omd;
    prm.mode = 0;
    if (p->flag & 2) {
        prm.mode = 4;
        if (!(omd->flag & 1)) {
            prm.mode |= 8;
        }
    } else {
        if (p->flag & 1) {
            prm.mode = 0x80;
        }
        if (!(omd->flag & 1)) {
            prm.mode |= 8;
        }
    }
    if (!(omd->flag & 2)) {
        prm.mode |= 0x10;
    }
    if (p->unk_09) {
        prm.mode |= 0x200;
    }
    if (p->unk_0B) {
        prm.mode |= 0x100;
    }
    if (p->unk_0A) {
        prm.mode |= 0x2000;
        prm.unk_30 = (FMATRIX*)m;
        sceVu0MulMatrix(m, ppvWorldMatrix, ppvPObj.next->cmat);
    }
    prm.unk_44 = 0;
    next = ppvPObj.next;
    prm.flag = *(u16*)&omd->alpha;
    prm.unk_0A = 0;
    prm.unk_1C = 0;
    prm.lpvert = next->lpvert;
    prm.lpnorm = next->lpnorm;
    prm.unk_04 = D_00616240;
    sceVu0UnitMatrix(ppvPObj.next->dmat);
    sceVu0CopyVector(ppvPObj.next->dmat[3], *(sceVu0FVECTOR*)(obj + 0x10));
    sceVu0MulMatrix(ppvPObj.next->dmat, D_00616180, ppvPObj.next->dmat);
    prm.dmat = &ppvPObj.next->dmat;
    prm.col[0] = v->col[0];
    prm.col[1] = v->col[1];
    prm.col[2] = v->col[2];
    prm.unk_24 = D_00616140;
    prm.unk_28 = D_00616100;
    prm.unk_0C = 0;
    prm.unk_10 = 0;
    prm.unk_40 = 0;
    prm.cmat = &ppvPObj.next->cmat;
    prm.unk_34 = D_00616224;
    prm.unk_4C = p->unk_0C;
    prm.unk_4D = p->unk_24;
    D_00616224 = op1_md_draw(omd, &prm, mdl->nPacketSize);
}

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
