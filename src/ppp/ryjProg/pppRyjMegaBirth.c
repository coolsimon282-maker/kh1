#include "ppp.h"

typedef struct {
    /* 0x00 */ FMATRIX matPar;
    /* 0x40 */ sceVu0FVECTOR vecForce;
    /* 0x50 */ void* pvParticleData;
    /* 0x54 */ void* pvParticleWmat;
    /* 0x58 */ void* pvParticleColor;
    /* 0x5C */ u32 nParticle;
    /* 0x60 */ u16 ushTimingCt;
    /* 0x62 */ u16 ushIct;
} VRyjMegaBirth;

typedef struct {
    /* 0x00 */ f32 pos[4];
    /* 0x10 */ char unk_10[0x14];
    /* 0x24 */ u16 seq;
    /* 0x26 */ u16 life;
    /* 0x28 */ s8 col[4];
    /* 0x2C */ f32 rotZ;
    /* 0x30 */ char unk_30[0x8];
    /* 0x38 */ f32 sclX;
    /* 0x3C */ f32 sclY;
    /* 0x40 */ char unk_40[0x18];
    /* 0x58 */ f32 fade;
    /* 0x5C */ char unk_5C[0x4];
} RyjMegaBirthPt; // size = 0x60

typedef struct {
    /* 0x00 */ char unk_00[0x4];
    /* 0x04 */ s32 shpIdx;
    /* 0x08 */ char unk_08[0x4];
    /* 0x0C */ u8 unk_0C;
    /* 0x0D */ u8 unk_0D;
    /* 0x0E */ u8 unk_0E;
    /* 0x0F */ u8 unk_0F;
    /* 0x10 */ f32 unk_10[3];
    /* 0x1C */ u16 nParticle;
    /* 0x1E */ char unk_1E[0x8];
    /* 0x26 */ u8 unk_26;
    /* 0x27 */ char unk_27[0x71];
    /* 0x98 */ f32 force[3];
    /* 0xA4 */ char unk_A4[0x25];
    /* 0xC9 */ u8 bColor;
    /* 0xCA */ char unk_CA[0x2];
    /* 0xCC */ u8 unk_CC;
    /* 0xCD */ u8 unk_CD;
} PRyjMegaBirth;

extern sceVu0FMATRIX D_00615E70;
extern sceVu0FVECTOR D_003701D0;
s32 func_0019D840(VRyjMegaBirth* v, PRyjMegaBirth* p);
void func_0019E8B0(VRyjMegaBirth* v, PRyjMegaBirth* p, void* w);

void pppRyjMegaBirthCalc(pppPObject* pobj, PRyjMegaBirth* p, pppCtrlTable* ctbl) {
    VRyjMegaBirth* v = (VRyjMegaBirth*)&pobj->val[ctbl->useVal[2]];
    void* w = &pobj->val[ctbl->useVal[1]];

    if (v->pvParticleData == NULL) {
        v->nParticle = p->nParticle;
        v->pvParticleData = pppDbgAlloc(ppvEnv, v->nParticle * 0x60);
        if (v->pvParticleData != NULL) {
            memset(v->pvParticleData, 0, v->nParticle * 0x60);
        }
        if (p->unk_CC == 1 || p->unk_CC == 2) {
            v->pvParticleWmat = pppDbgAlloc(ppvEnv, v->nParticle * 64);
            if (v->pvParticleWmat != NULL) {
                memset(v->pvParticleWmat, 0, v->nParticle * 64);
            }
        }
        if (p->bColor) {
            v->pvParticleColor = pppDbgAlloc(ppvEnv, v->nParticle * 32);
            if (v->pvParticleColor != NULL) {
                memset(v->pvParticleColor, 0, v->nParticle * 32);
            }
        }
        v->vecForce[0] = p->force[0];
        v->vecForce[1] = p->force[1];
        v->vecForce[2] = p->force[2];
        v->vecForce[3] = 0.0f;
        sceVu0Normalize(v->vecForce, v->vecForce);
    }
    if (!func_0019D840(v, p)) {
        return;
    }
    switch (p->unk_26) {
        case 1:
        case 3:
        case 5:
        case 7:
        case 9:
            sceVu0UnitMatrix(v->matPar);
            sceVu0ScaleVectorXYZ(v->matPar[0], v->matPar[0], ppvParScl[0]);
            sceVu0ScaleVectorXYZ(v->matPar[1], v->matPar[1], ppvParScl[1]);
            sceVu0ScaleVectorXYZ(v->matPar[2], v->matPar[2], ppvParScl[2]);
            sceVu0CopyVector(v->matPar[3], D_003701D0);
            v->matPar[3][3] = 1.0f;
            break;
        default:
            sceVu0CopyMatrix(v->matPar, D_00615E70);
            break;
    }
    func_0019E8B0(v, p, w);
}

extern sceVu0FMATRIX D_00615EB0;

void func_0019ECE8(sceVu0FMATRIX out, PRyjMegaBirth* p, sceVu0FMATRIX m) {
    if (p->unk_CC == 0) {
        sceVu0MulMatrix(out, m, ppvPObj.next->cmat);
        sceVu0MulMatrix(out, D_00615EB0, out);
    }
}

// The matrix products are hand-written VU0 code (asm blocks); the C around them is plain.
void func_0019ED48(
    sceVu0FMATRIX m0,
    sceVu0FMATRIX m,
    PRyjMegaBirth* p,
    VRyjMegaBirth* v,
    RyjMegaBirthPt* pt,
    sceVu0FMATRIX wmat,
    sceVu0FMATRIX out,
    u8 flag
) {
    sceVu0UnitMatrix(m);
    m[0][0] = pt->sclX * ppvParScl[0];
    m[1][1] = pt->sclY * ppvParScl[1];
    m[2][2] = pt->sclX * ppvParScl[0];
    if (pt->rotZ != 0.0f) {
        sceVu0RotMatrixZ(m, m, pt->rotZ * 3.1415926f / 180.0f);
    }
    sceVu0AddVector(m[3], m[3], pt->pos);
    switch (p->unk_CC) {
        case 0:
            __asm__ volatile(".set noreorder\n"
                             "lqc2 $vf1, 0x0(%0)\n"
                             "lqc2 $vf2, 0x10(%0)\n"
                             "lqc2 $vf3, 0x20(%0)\n"
                             "lqc2 $vf4, 0x30(%0)\n"
                             "lqc2 $vf9, 0x0(%1)\n"
                             "lqc2 $vf10, 0x10(%1)\n"
                             "lqc2 $vf11, 0x20(%1)\n"
                             "lqc2 $vf12, 0x30(%1)\n"
                             "lqc2 $vf5, 0x0(%2)\n"
                             "lqc2 $vf6, 0x10(%2)\n"
                             "lqc2 $vf7, 0x20(%2)\n"
                             "lqc2 $vf8, 0x30(%2)\n"
                             "vmulax.xyzw ACC, $vf9, $vf4x\n"
                             "vmadday.xyzw ACC, $vf10, $vf4y\n"
                             "vmaddaz.xyzw ACC, $vf11, $vf4z\n"
                             "vmaddw.xyzw $vf4, $vf12, $vf4w\n"
                             "beql $0, %3, 1f\n"
                             "nop\n"
                             "sqc2 $vf1, 0x0(%4)\n"
                             "sqc2 $vf2, 0x10(%4)\n"
                             "sqc2 $vf3, 0x20(%4)\n"
                             "sqc2 $vf4, 0x30(%4)\n"
                             "1:\n"
                             "vmulax.xyzw ACC, $vf5, $vf1x\n"
                             "vmadday.xyzw ACC, $vf6, $vf1y\n"
                             "vmaddaz.xyzw ACC, $vf7, $vf1z\n"
                             "vmaddw.xyzw $vf1, $vf8, $vf1w\n"
                             "vmulax.xyzw ACC, $vf5, $vf2x\n"
                             "vmadday.xyzw ACC, $vf6, $vf2y\n"
                             "vmaddaz.xyzw ACC, $vf7, $vf2z\n"
                             "vmaddw.xyzw $vf2, $vf8, $vf2w\n"
                             "vmulax.xyzw ACC, $vf5, $vf3x\n"
                             "vmadday.xyzw ACC, $vf6, $vf3y\n"
                             "vmaddaz.xyzw ACC, $vf7, $vf3z\n"
                             "vmaddw.xyzw $vf3, $vf8, $vf3w\n"
                             "vmulax.xyzw ACC, $vf5, $vf4x\n"
                             "vmadday.xyzw ACC, $vf6, $vf4y\n"
                             "vmaddaz.xyzw ACC, $vf7, $vf4z\n"
                             "vmaddw.xyzw $vf4, $vf8, $vf4w\n"
                             "sqc2 $vf1, 0x0(%0)\n"
                             "sqc2 $vf2, 0x10(%0)\n"
                             "sqc2 $vf3, 0x20(%0)\n"
                             "sqc2 $vf4, 0x30(%0)\n"
                             ".set reorder\n"
                             :
                             : "r"(m), "r"(m0), "r"(ppvScreenMatrix), "r"(flag), "r"(out)
                             : "memory");
            break;
        case 1:
            __asm__ volatile(".set noreorder\n"
                             "lqc2 $vf1, 0x0(%0)\n"
                             "lqc2 $vf2, 0x10(%0)\n"
                             "lqc2 $vf3, 0x20(%0)\n"
                             "lqc2 $vf4, 0x30(%0)\n"
                             "lqc2 $vf9, 0x0(%1)\n"
                             "lqc2 $vf10, 0x10(%1)\n"
                             "lqc2 $vf11, 0x20(%1)\n"
                             "lqc2 $vf12, 0x30(%1)\n"
                             "lqc2 $vf13, 0x0(%2)\n"
                             "lqc2 $vf14, 0x10(%2)\n"
                             "lqc2 $vf15, 0x20(%2)\n"
                             "lqc2 $vf16, 0x30(%2)\n"
                             "lqc2 $vf17, 0x0(%3)\n"
                             "lqc2 $vf18, 0x10(%3)\n"
                             "lqc2 $vf19, 0x20(%3)\n"
                             "lqc2 $vf20, 0x30(%3)\n"
                             "lqc2 $vf5, 0x0(%4)\n"
                             "lqc2 $vf6, 0x10(%4)\n"
                             "lqc2 $vf7, 0x20(%4)\n"
                             "lqc2 $vf8, 0x30(%4)\n"
                             "vmulax.xyzw ACC, $vf9, $vf17x\n"
                             "vmadday.xyzw ACC, $vf10, $vf17y\n"
                             "vmaddaz.xyzw ACC, $vf11, $vf17z\n"
                             "vmaddw.xyzw $vf17, $vf12, $vf17w\n"
                             "vmulax.xyzw ACC, $vf9, $vf18x\n"
                             "vmadday.xyzw ACC, $vf10, $vf18y\n"
                             "vmaddaz.xyzw ACC, $vf11, $vf18z\n"
                             "vmaddw.xyzw $vf18, $vf12, $vf18w\n"
                             "vmulax.xyzw ACC, $vf9, $vf19x\n"
                             "vmadday.xyzw ACC, $vf10, $vf19y\n"
                             "vmaddaz.xyzw ACC, $vf11, $vf19z\n"
                             "vmaddw.xyzw $vf19, $vf12, $vf19w\n"
                             "vmulax.xyzw ACC, $vf9, $vf20x\n"
                             "vmadday.xyzw ACC, $vf10, $vf20y\n"
                             "vmaddaz.xyzw ACC, $vf11, $vf20z\n"
                             "vmaddw.xyzw $vf20, $vf12, $vf20w\n"
                             "vmulax.xyzw ACC, $vf13, $vf17x\n"
                             "vmadday.xyzw ACC, $vf14, $vf17y\n"
                             "vmaddaz.xyzw ACC, $vf15, $vf17z\n"
                             "vmaddw.xyzw $vf9, $vf16, $vf17w\n"
                             "vmulax.xyzw ACC, $vf13, $vf18x\n"
                             "vmadday.xyzw ACC, $vf14, $vf18y\n"
                             "vmaddaz.xyzw ACC, $vf15, $vf18z\n"
                             "vmaddw.xyzw $vf10, $vf16, $vf18w\n"
                             "vmulax.xyzw ACC, $vf13, $vf19x\n"
                             "vmadday.xyzw ACC, $vf14, $vf19y\n"
                             "vmaddaz.xyzw ACC, $vf15, $vf19z\n"
                             "vmaddw.xyzw $vf11, $vf16, $vf19w\n"
                             "vmulax.xyzw ACC, $vf13, $vf20x\n"
                             "vmadday.xyzw ACC, $vf14, $vf20y\n"
                             "vmaddaz.xyzw ACC, $vf15, $vf20z\n"
                             "vmaddw.xyzw $vf12, $vf16, $vf20w\n"
                             "vmulax.xyzw ACC, $vf9, $vf4x\n"
                             "vmadday.xyzw ACC, $vf10, $vf4y\n"
                             "vmaddaz.xyzw ACC, $vf11, $vf4z\n"
                             "vmaddw.xyzw $vf4, $vf12, $vf4w\n"
                             "beql $0, %5, 1f\n"
                             "nop\n"
                             "sqc2 $vf1, 0x0(%6)\n"
                             "sqc2 $vf2, 0x10(%6)\n"
                             "sqc2 $vf3, 0x20(%6)\n"
                             "sqc2 $vf4, 0x30(%6)\n"
                             "1:\n"
                             "vmulax.xyzw ACC, $vf5, $vf1x\n"
                             "vmadday.xyzw ACC, $vf6, $vf1y\n"
                             "vmaddaz.xyzw ACC, $vf7, $vf1z\n"
                             "vmaddw.xyzw $vf1, $vf8, $vf1w\n"
                             "vmulax.xyzw ACC, $vf5, $vf2x\n"
                             "vmadday.xyzw ACC, $vf6, $vf2y\n"
                             "vmaddaz.xyzw ACC, $vf7, $vf2z\n"
                             "vmaddw.xyzw $vf2, $vf8, $vf2w\n"
                             "vmulax.xyzw ACC, $vf5, $vf3x\n"
                             "vmadday.xyzw ACC, $vf6, $vf3y\n"
                             "vmaddaz.xyzw ACC, $vf7, $vf3z\n"
                             "vmaddw.xyzw $vf3, $vf8, $vf3w\n"
                             "vmulax.xyzw ACC, $vf5, $vf4x\n"
                             "vmadday.xyzw ACC, $vf6, $vf4y\n"
                             "vmaddaz.xyzw ACC, $vf7, $vf4z\n"
                             "vmaddw.xyzw $vf4, $vf8, $vf4w\n"
                             "sqc2 $vf1, 0x0(%0)\n"
                             "sqc2 $vf2, 0x10(%0)\n"
                             "sqc2 $vf3, 0x20(%0)\n"
                             "sqc2 $vf4, 0x30(%0)\n"
                             ".set reorder\n"
                             :
                             : "r"(m), "r"(wmat), "r"(D_00615EB0), "r"(ppvPObj.next->cmat), "r"(ppvScreenMatrix),
                               "r"(flag), "r"(out)
                             : "memory");
            break;
        case 2:
            __asm__ volatile(".set noreorder\n"
                             "lqc2 $vf1, 0x0(%0)\n"
                             "lqc2 $vf2, 0x10(%0)\n"
                             "lqc2 $vf3, 0x20(%0)\n"
                             "lqc2 $vf4, 0x30(%0)\n"
                             "lqc2 $vf9, 0x0(%1)\n"
                             "lqc2 $vf10, 0x10(%1)\n"
                             "lqc2 $vf11, 0x20(%1)\n"
                             "lqc2 $vf12, 0x30(%1)\n"
                             "lqc2 $vf13, 0x0(%2)\n"
                             "lqc2 $vf14, 0x10(%2)\n"
                             "lqc2 $vf15, 0x20(%2)\n"
                             "lqc2 $vf16, 0x30(%2)\n"
                             "lqc2 $vf17, 0x0(%3)\n"
                             "lqc2 $vf18, 0x10(%3)\n"
                             "lqc2 $vf19, 0x20(%3)\n"
                             "lqc2 $vf20, 0x30(%3)\n"
                             "lqc2 $vf5, 0x0(%4)\n"
                             "lqc2 $vf6, 0x10(%4)\n"
                             "lqc2 $vf7, 0x20(%4)\n"
                             "lqc2 $vf8, 0x30(%4)\n"
                             "vmulax.xyzw ACC, $vf17, $vf9x\n"
                             "vmadday.xyzw ACC, $vf18, $vf9y\n"
                             "vmaddaz.xyzw ACC, $vf19, $vf9z\n"
                             "vmaddw.xyzw $vf9, $vf20, $vf9w\n"
                             "vmulax.xyzw ACC, $vf17, $vf10x\n"
                             "vmadday.xyzw ACC, $vf18, $vf10y\n"
                             "vmaddaz.xyzw ACC, $vf19, $vf10z\n"
                             "vmaddw.xyzw $vf10, $vf20, $vf10w\n"
                             "vmulax.xyzw ACC, $vf17, $vf11x\n"
                             "vmadday.xyzw ACC, $vf18, $vf11y\n"
                             "vmaddaz.xyzw ACC, $vf19, $vf11z\n"
                             "vmaddw.xyzw $vf11, $vf20, $vf11w\n"
                             "vmulax.xyzw ACC, $vf17, $vf12x\n"
                             "vmadday.xyzw ACC, $vf18, $vf12y\n"
                             "vmaddaz.xyzw ACC, $vf19, $vf12z\n"
                             "vmaddw.xyzw $vf12, $vf20, $vf12w\n"
                             "vmulax.xyzw ACC, $vf13, $vf9x\n"
                             "vmadday.xyzw ACC, $vf14, $vf9y\n"
                             "vmaddaz.xyzw ACC, $vf15, $vf9z\n"
                             "vmaddw.xyzw $vf9, $vf16, $vf9w\n"
                             "vmulax.xyzw ACC, $vf13, $vf10x\n"
                             "vmadday.xyzw ACC, $vf14, $vf10y\n"
                             "vmaddaz.xyzw ACC, $vf15, $vf10z\n"
                             "vmaddw.xyzw $vf10, $vf16, $vf10w\n"
                             "vmulax.xyzw ACC, $vf13, $vf11x\n"
                             "vmadday.xyzw ACC, $vf14, $vf11y\n"
                             "vmaddaz.xyzw ACC, $vf15, $vf11z\n"
                             "vmaddw.xyzw $vf11, $vf16, $vf11w\n"
                             "vmulax.xyzw ACC, $vf13, $vf12x\n"
                             "vmadday.xyzw ACC, $vf14, $vf12y\n"
                             "vmaddaz.xyzw ACC, $vf15, $vf12z\n"
                             "vmaddw.xyzw $vf12, $vf16, $vf12w\n"
                             "vmulax.xyzw ACC, $vf9, $vf4x\n"
                             "vmadday.xyzw ACC, $vf10, $vf4y\n"
                             "vmaddaz.xyzw ACC, $vf11, $vf4z\n"
                             "vmaddw.xyzw $vf4, $vf12, $vf4w\n"
                             "beql $0, %5, 1f\n"
                             "nop\n"
                             "sqc2 $vf1, 0x0(%6)\n"
                             "sqc2 $vf2, 0x10(%6)\n"
                             "sqc2 $vf3, 0x20(%6)\n"
                             "sqc2 $vf4, 0x30(%6)\n"
                             "1:\n"
                             "vmulax.xyzw ACC, $vf5, $vf1x\n"
                             "vmadday.xyzw ACC, $vf6, $vf1y\n"
                             "vmaddaz.xyzw ACC, $vf7, $vf1z\n"
                             "vmaddw.xyzw $vf1, $vf8, $vf1w\n"
                             "vmulax.xyzw ACC, $vf5, $vf2x\n"
                             "vmadday.xyzw ACC, $vf6, $vf2y\n"
                             "vmaddaz.xyzw ACC, $vf7, $vf2z\n"
                             "vmaddw.xyzw $vf2, $vf8, $vf2w\n"
                             "vmulax.xyzw ACC, $vf5, $vf3x\n"
                             "vmadday.xyzw ACC, $vf6, $vf3y\n"
                             "vmaddaz.xyzw ACC, $vf7, $vf3z\n"
                             "vmaddw.xyzw $vf3, $vf8, $vf3w\n"
                             "vmulax.xyzw ACC, $vf5, $vf4x\n"
                             "vmadday.xyzw ACC, $vf6, $vf4y\n"
                             "vmaddaz.xyzw ACC, $vf7, $vf4z\n"
                             "vmaddw.xyzw $vf4, $vf8, $vf4w\n"
                             "sqc2 $vf1, 0x0(%0)\n"
                             "sqc2 $vf2, 0x10(%0)\n"
                             "sqc2 $vf3, 0x20(%0)\n"
                             "sqc2 $vf4, 0x30(%0)\n"
                             ".set reorder\n"
                             :
                             : "r"(m), "r"(wmat), "r"(D_00615EB0), "r"(v->matPar), "r"(ppvScreenMatrix), "r"(flag),
                               "r"(out)
                             : "memory");
            break;
    }
}

typedef struct {
    /* 0x0 */ s16 seq;
    /* 0x2 */ s16 time;
    /* 0x4 */ s8 flag;
    /* 0x5 */ char unk_05[3];
} MBShpSeq;

typedef struct {
    /* 0x00 */ char unk_00[0x10];
    /* 0x10 */ MBShpSeq seq[1];
} MBShpHdr;

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
} MBDrawSt;

extern s32 D_00616224;
s32 func_001BA340(void* shape, MBDrawSt* st, s32 size);
s32 func_0019D840(VRyjMegaBirth* v, PRyjMegaBirth* p);
void func_0019ECE8(sceVu0FMATRIX out, PRyjMegaBirth* p, sceVu0FMATRIX m);

void pppRyjMegaBirthDraw(pppPObject* pobj, PRyjMegaBirth* p, pppCtrlTable* ctbl) {
    VRyjMegaBirth* v = (VRyjMegaBirth*)&pobj->val[ctbl->useVal[2]];
    u8* c = (u8*)&pobj->val[ctbl->useVal[1]];
    RyjMegaBirthPt* pt = v->pvParticleData;
    f32(*wmat)[4][4] = v->pvParticleWmat;
    f32(*col)[8] = v->pvParticleColor;
    s32 n = v->nParticle;
    sceVu0FMATRIX m0;
    sceVu0FMATRIX m;
    sceVu0FMATRIX m2;
    sceVu0FVECTOR ofs;
    MBDrawSt ds;
    pppShapeSt* st;
    MBShpHdr* shp;
    s32 r0, g0, b0, a0;
    s32 r, g, b, a;
    u8* data;
    s32 i;

    if (!func_0019D840(v, p)) {
        return;
    }
    if (p->shpIdx == 0xFFFF) {
        return;
    }
    func_0019ECE8(m0, p, v->matPar);
    st = &ppvEnv->lpShape[p->shpIdx];
    if (p->unk_0F == 0) {
        ds.flags = 0x80;
    } else {
        ds.flags = 0;
    }
    if (p->unk_CD == 1) {
        ds.flags |= 0x10;
    }
    if (p->unk_0C) {
        ds.flags |= 0x800;
    }
    if (p->unk_0D) {
        ds.flags |= 0x400;
    }
    if (p->unk_0E) {
        ds.unk_1C = m2;
        ofs[0] = p->unk_10[0];
        ofs[1] = p->unk_10[1];
        ofs[2] = p->unk_10[2];
        ofs[3] = 0.0f;
    } else {
        ds.unk_1C = NULL;
    }
    ds.unk_08 = 0;
    ds.unk_18 = 0;
    ds.mat = m[0];
    shp = (MBShpHdr*)st->shape;
    r0 = c[0x8];
    g0 = c[0x9];
    b0 = c[0xA];
    a0 = c[0xB];
    for (i = 0; i < n; i++) {
        if (pt->life != 0) {
            func_0019ED48(m0, m, p, v, pt, *wmat, m2, p->unk_0E);
            if (p->unk_0E) {
                sceVu0AddVector(m2[3], m2[3], ofs);
                sceVu0MulMatrix(m2, ppvScreenMatrix, m2);
            }
            // (pt->seq << 3) rather than shp->seq[pt->seq]: the target adds shp + index, not index + shp
            data = (u8*)shp + *(s16*)((u8*)shp + (pt->seq << 3) + 0x10);
            a = (f32)a0 + (f32)pt->col[3] - pt->fade;
            r = r0 + pt->col[0];
            g = g0 + pt->col[1];
            b = b0 + pt->col[2];
            if (col != NULL) {
                r += (s32)(*col)[0];
                g += (s32)(*col)[1];
                b += (s32)(*col)[2];
                a += (s32)(*col)[3];
            }
            if (r < 0) {
                r = 0;
            } else if (r > 0xFF) {
                r = 0xFF;
            }
            if (g < 0) {
                g = 0;
            } else if (g > 0xFF) {
                g = 0xFF;
            }
            if (b < 0) {
                b = 0;
            } else if (b > 0xFF) {
                b = 0xFF;
            }
            if (a < 0) {
                a = 0;
            } else if (a > 0x7F) {
                a = 0x7F;
            }
            ds.col[0] = r;
            ds.col[1] = g;
            ds.col[2] = b;
            ds.col[3] = a;
            ds.unk_14 = D_00616224;
            D_00616224 = func_001BA340(data, &ds, st->nPacketSize);
        }
        if (wmat != NULL) {
            wmat++;
        }
        if (col != NULL) {
            col++;
        }
        pt++;
    }
}

void pppRyjMegaBirthCon(pppPObject* pobj, pppCtrlTable* ctbl) {
    VRyjMegaBirth* v = (VRyjMegaBirth*)&pobj->val[ctbl->useVal[2]];

    sceVu0UnitMatrix(v->matPar);
    *(u_long128*)v->vecForce = 0;
    v->pvParticleData = 0;
    v->pvParticleWmat = 0;
    v->pvParticleColor = 0;
    v->nParticle = 0;
    v->ushTimingCt = 0;
    v->ushIct = 0;
    sceVu0UnitMatrix(g_matUnit);
}

void pppRyjMegaBirthDes(pppPObject* pobj, pppCtrlTable* ctbl) {
    VRyjMegaBirth* data = (VRyjMegaBirth*)&pobj->val[ctbl->useVal[2]];

    if (data->pvParticleData != NULL) {
        pppFree(ppvEnv, data->pvParticleData);
        data->pvParticleData = NULL;
    }
    if (data->pvParticleWmat != NULL) {
        pppFree(ppvEnv, data->pvParticleWmat);
        data->pvParticleWmat = NULL;
    }
    if (data->pvParticleColor != NULL) {
        pppFree(ppvEnv, data->pvParticleColor);
        data->pvParticleColor = NULL;
    }
}
