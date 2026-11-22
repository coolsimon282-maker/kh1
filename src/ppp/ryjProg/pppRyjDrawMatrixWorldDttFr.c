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

INCLUDE_ASM("asm/nonmatchings/ppp/ryjProg/pppRyjDrawMatrixWorldDttFr", func_001A3F98);

f32 func_001A3F98(void);
s8 func_001A3FE0(u8 a) {
    f32 r = func_001A3F98();
    return (a * 2) * r - (a >> 1);
}

s32 func_001A4040(s32* arg0, ppvmng* arg1) {
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
        out[0] = d * func_001A3F98() - r;
        out[1] = d * func_001A3F98() - r;
        out[2] = d * func_001A3F98() - r;
    } while (vu0Length(out) > r);
    out[3] = 1.0f;
    sceVu0ApplyMatrix(out, D_00615F30, out);
    func_001A4070(p, out, w);
}

#else
INCLUDE_ASM("asm/nonmatchings/ppp/ryjProg/pppRyjDrawMatrixWorldDttFr", func_001A4538);
#endif

INCLUDE_ASM("asm/nonmatchings/ppp/ryjProg/pppRyjDrawMatrixWorldDttFr", func_001A4680);

INCLUDE_ASM("asm/nonmatchings/ppp/ryjProg/pppRyjDrawMatrixWorldDttFr", func_001A4BC8);
