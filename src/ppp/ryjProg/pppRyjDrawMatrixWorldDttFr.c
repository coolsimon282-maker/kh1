#include "ppp.h"

extern sceVu0FVECTOR D_003701D0;

void pppRyjDrawMatrixWorldDttFrCon(pppPObject* pobj, pppCtrlTable* ctbl) {
    u8* v = (u8*)&pobj->val[ctbl->useVal[1]];

    sceVu0CopyVector((f32*)(v + 0x40), D_003701D0);
    sceVu0CopyVector((f32*)(v + 0x50), ppvParScl);
}

#ifdef VERSION_FM
extern sceVu0FMATRIX D_00615EB0;

void pppRyjDrawMatrixWorldDttFrCalc(pppPObject* pobj, s32 param, pppCtrlTable* ctbl) {
    u8* v = (u8*)&pobj->val[ctbl->useVal[1]];
    sceVu0FMATRIX m;

    sceVu0UnitMatrix(m);
    m[3][0] = ((f32*)(v + 0x40))[0];
    m[3][1] = ((f32*)(v + 0x40))[1];
    m[3][2] = ((f32*)(v + 0x40))[2];
    sceVu0MulMatrix(m, D_00615EB0, m);
    sceVu0ScaleVector(ppvPObj.next->dmat[0], ppvPObj.next->cmat[0], ((f32*)(v + 0x50))[0]);
    sceVu0ScaleVector(ppvPObj.next->dmat[1], ppvPObj.next->cmat[1], ((f32*)(v + 0x50))[1]);
    sceVu0ScaleVector(ppvPObj.next->dmat[2], ppvPObj.next->cmat[2], ((f32*)(v + 0x50))[2]);
    sceVu0ApplyMatrix(ppvPObj.next->dmat[3], m, ppvPObj.next->cmat[3]);
    sceVu0CopyMatrix((void*)v, ppvPObj.next->dmat);
    sceVu0MulMatrix(ppvPObj.next->dmat, ppvScreenMatrix, ppvPObj.next->dmat);
}
#else
INCLUDE_ASM("asm/nonmatchings/ppp/ryjProg/pppRyjDrawMatrixWorldDttFr", pppRyjDrawMatrixWorldDttFrCalc);
#endif

#ifdef VERSION_FM
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

// VU0 random number 0..1.
f32 RyjDttFr_Rand(void) {
    return vu0Rand();
}

#else
INCLUDE_ASM("asm/nonmatchings/ppp/ryjProg/pppRyjDrawMatrixWorldDttFr", RyjDttFr_Rand);
#endif

f32 RyjDttFr_Rand(void);
// Random value in about -a/2 .. 1.5 a (a * 2 * rand - a / 2).
s8 RyjDttFr_RandSpread(u8 a) {
    f32 r = RyjDttFr_Rand();
    return (a * 2) * r - (a >> 1);
}

// True when the particle data is there (and the colour data when the parameters need it).
s32 RyjDttFr_HasData(s32* arg0, ppvmng* arg1) {
    if (arg0[0] == 0) {
        return 0;
    }
    if (arg1->unk_B6 != 0) {
        if (arg0[1] == 0) {
            return 0;
        }
    }
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/ppp/ryjProg/pppRyjDrawMatrixWorldDttFr", func_001A4070);

#ifdef VERSION_FM
// |v.xyz| on VU0 (hand-written macro code)
static inline f32 vu0Length(f32* v) {
    f32 len;
    __asm__ volatile(
        "lqc2 $vf10, 0(%1)\n"
        "vmul.xyz $vf10, $vf10, $vf10\n"
        "vaddx.y $vf10, $vf10, $vf10x\n"
        "vaddy.z $vf10, $vf10, $vf10y\n"
        "vsqrt Q, $vf10z\n"
        "vwaitq\n"
        "vaddq.x $vf10, $vf0, Q\n"
        "qmfc2.ni %0, $vf10\n"
        : "=r"(len) : "r"(v) : "memory");
    return len;
}

typedef struct {
    /* 0x00 */ char unk_00[0x7C];
    /* 0x7C */ f32 unk_7C;
    /* 0x80 */ f32 unk_80;
    /* 0x84 */ f32 unk_84;
    /* 0x88 */ char unk_88[0x14];
    /* 0x9C */ f32 unk_9C;
    /* 0xA0 */ f32 unk_A0;
} PRyjDttFr;

extern sceVu0FMATRIX D_00615F30;
void* memset(void*, int, unsigned int);
void func_001A4070(PRyjDttFr*, f32*, void*);

void func_001A4538(s32 arg0, PRyjDttFr* p, f32* out, void* w) {
    sceVu0FVECTOR v;
    f32 r;
    f32 d;

    memset(out, 0, 0x60);
    if (w != NULL) {
        memset(w, 0, 0x20);
    }
    v[0] = p->unk_7C;
    v[1] = p->unk_80;
    v[2] = p->unk_84;
    v[3] = 1.0f;
    sceVu0Normalize(out + 4, v);
    r = p->unk_9C + p->unk_A0;
    d = r + r;
    do {
        out[0] = d * RyjDttFr_Rand() - r;
        out[1] = d * RyjDttFr_Rand() - r;
        out[2] = d * RyjDttFr_Rand() - r;
    } while (vu0Length(out) > r);
    out[3] = 1.0f;
    sceVu0ApplyMatrix(out, D_00615F30, out);
    func_001A4070(p, out, w);
}

#else
INCLUDE_ASM("asm/nonmatchings/ppp/ryjProg/pppRyjDrawMatrixWorldDttFr", func_001A4538);
#endif

INCLUDE_ASM("asm/nonmatchings/ppp/ryjProg/pppRyjDrawMatrixWorldDttFr", func_001A4680);

#ifdef VERSION_FM
typedef struct {
    /* 0x00 */ s32 unk_00;
    /* 0x04 */ s32 shapeNo;
    /* 0x08 */ u16 speed;
    /* 0x0A */ char unk_0A[0x6];
    /* 0x10 */ u16 unk_10;
    /* 0x12 */ u16 unk_12;
} PRyjDttFrP;

typedef struct {
    /* 0x00 */ f32 pos[4];
    /* 0x10 */ f32 dir[4];
    /* 0x20 */ u16 wait;
    /* 0x22 */ u16 seq;
    /* 0x24 */ u16 seq_now;
    /* 0x26 */ u16 alive;
    /* 0x28 */ char unk_28[0x38];
} PRyjPart;

typedef struct {
    /* 0x00 */ PRyjPart* parts;
    /* 0x04 */ u8* w;
    /* 0x08 */ s32 num;
    /* 0x0C */ s32 unk_0C;
    /* 0x10 */ u16 cnt;
} PRyjWork;

typedef struct {
    /* 0x0 */ s16 ofs;
    /* 0x2 */ s16 time;
    /* 0x4 */ s8 flag;
    /* 0x5 */ char pad[3];
} RyjShpAnm;

void func_001A4680(PRyjWork*, PRyjDttFrP*, PRyjPart*, s32, u8*);

void func_001A4BC8(PRyjWork* work, PRyjDttFrP* p, s32 arg2) {
    PRyjPart* part = work->parts;
    u8* w = work->w;
    s32 n = work->num;
    s32 born = 0;
    s32 i;
    u8* shp;
    RyjShpAnm* anm;
    pppShapeSt* lp;

    if (ppvUserStopPartF != 0 || ppvMng->stop || ppvMng->unk_B4 != 0) {
        return;
    }
    if (p->shapeNo == 0xFFFF) {
        return;
    }
    work->cnt++;
    for (i = 0; i < n; i++) {
        if (part->alive) {
            func_001A4680(work, p, part, arg2, w);
            lp = ppvEnv->lpShape;
            lp += p->shapeNo;
            shp = (u8*)lp->shape;
            anm = (RyjShpAnm*)(shp + 0x10) + part->seq_now;
            part->seq_now = part->seq;
            part->wait += p->speed;
            if (part->wait >= anm->time) {
                part->wait -= anm->time;
                part->seq++;
                if (part->seq >= *(s16*)(shp + 6)) {
                    if (anm->flag & 0x80) {
                        part->seq = 0;
                        part->wait = 0;
                    } else {
                        part->seq--;
                        part->wait = 0;
                    }
                }
            }
        } else if (p->unk_12 <= work->cnt && born < p->unk_10) {
            born++;
            func_001A4538((s32)work, (PRyjDttFr*)p, (f32*)part, w);
        }
        part++;
        if (w != NULL) {
            w += 0x20;
        }
    }
    if (born > 0) {
        work->cnt = 0;
    }
}

#else
INCLUDE_ASM("asm/nonmatchings/ppp/ryjProg/pppRyjDrawMatrixWorldDttFr", func_001A4BC8);
#endif
