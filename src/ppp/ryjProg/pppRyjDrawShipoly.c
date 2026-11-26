#include "ppp.h"

typedef struct {
    /* 0x0 */ u32 unFrameCt;
    /* 0x4 */ u8 bSmp;
    /* 0x5 */ u8 bStandby;
    /* 0x6 */ char dummy0[2];
    /* 0x8 */ pppFVECTOR* pvecSmp;
} VRyjDrawShipoly;

INCLUDE_ASM("asm/nonmatchings/ppp/ryjProg/pppRyjDrawShipoly", pppRyjDrawShipolyCalc);

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
} MdPrmR;

typedef struct {
    /* 0x00 */ pppCDT cdt;
    /* 0x04 */ u32 index;
    /* 0x08 */ u8 flag;
    /* 0x09 */ u8 unk_09;
    /* 0x0A */ u8 unk_0A;
    /* 0x0B */ u8 unk_0B;
    /* 0x0C */ u8 unk_0C;
    /* 0x0D */ u8 pad_0D[8];
    /* 0x15 */ u8 unk_15;
    /* 0x16 */ u8 pad_16[3];
    /* 0x19 */ u8 unk_19;
} PRyjDrawShipoly;

typedef struct {
    /* 0x0 */ char unk_00[8];
    /* 0x8 */ u8 col[4];
} VRyjDrawShipolyC;

extern char D_00616240[];
extern char D_00616140[];
extern char D_00616100[];
extern s32 D_00616224;
extern sceVu0FMATRIX D_00616180;
extern sceVu0FVECTOR D_003701D0;
s32 op1_md_draw(OMD_H* omd, MdPrmR* prm, s32 size);

void pppRyjDrawShipolyDraw(pppPObject* pobj, PRyjDrawShipoly* p, pppCtrlTable* ctbl) {
    VRyjDrawShipolyC* v;
    pppModelSt* mdl;
    OMD_H* omd;
    pppPObject* next;
    MdPrmR prm;
    sceVu0FMATRIX m;

    if (p->index == 0xFFFF) {
        return;
    }
    v = (VRyjDrawShipolyC*)&pobj->val[ctbl->useVal[1]];
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
    if (p->unk_15) {
        sceVu0UnitMatrix(ppvPObj.next->dmat);
        sceVu0CopyVectorXYZ(ppvPObj.next->dmat[3], D_003701D0);
        sceVu0MulMatrix(ppvPObj.next->dmat, D_00616180, ppvPObj.next->dmat);
        prm.dmat = &ppvPObj.next->dmat;
    } else {
        prm.dmat = (FMATRIX*)ppvSWMatrix;
    }
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
    prm.unk_4D = p->unk_19;
    D_00616224 = op1_md_draw(omd, &prm, mdl->nPacketSize);
}

void pppRyjDrawShipolyCon(pppPObject* pobj, pppCtrlTable* ctbl) {
    VRyjDrawShipoly* p = (VRyjDrawShipoly*)&pobj->val[ctbl->useVal[2]];
    p->pvecSmp = NULL;
    p->unFrameCt = 0;
    p->bSmp = FALSE;
    p->bStandby = TRUE;
}

void pppRyjDrawShipolyDes(pppPObject* pobj, pppCtrlTable* ctbl) {
    VRyjDrawShipoly* p = (VRyjDrawShipoly*)&pobj->val[ctbl->useVal[2]];

    if (p->pvecSmp != NULL) {
        pppFree(ppvEnv, p->pvecSmp);
        p->pvecSmp = NULL;
    }
}

INCLUDE_ASM("asm/nonmatchings/ppp/ryjProg/pppRyjDrawShipoly", func_0019C460);

#ifdef VERSION_FM
// .data (0x00372730-0x00372750)
sceVu0FVECTOR D_00372730 = {4.0f, -1.0f, 0.0f, 0.0f};
f32 D_00372740[4] = {3.0f, 2.0f, 0.0f, 0.0f};
#else
extern f32 D_00372740[4];
#endif

// Interpolates the 16-byte keys i and i + 1 of a and b at the fraction of t (VU0).
void RyjShipoly_LerpKey(f32* out, u8* a, u8* b, f32 t) {
    s32 i = t;
    f32* v = D_00372740;
    v[2] = t - (f32)i;
    a += i * 16;
    b += i * 16;
    __asm__ volatile(
        "lqc2 $vf1,0x0(%1)\n\t"
        "lqc2 $vf2,0x10(%1)\n\t"
        "lqc2 $vf3,0x0(%2)\n\t"
        "lqc2 $vf4,0x10(%2)\n\t"
        "lqc2 $vf5,0x0(%3)\n\t"
        "vsub.xyzw $vf10,$vf4,$vf3\n\t"
        "vmuly.xyzw $vf11,$vf3,$vf5y\n\t"
        "vmulx.xyzw $vf12,$vf3,$vf5x\n\t"
        "vsub.xyzw $vf13,$vf2,$vf1\n\t"
        "vmulz.xyzw $vf10,$vf10,$vf5z\n\t"
        "vadd.xyzw $vf11,$vf11,$vf4\n\t"
        "vadd.xyzw $vf10,$vf10,$vf12\n\t"
        "vsub.xyzw $vf13,$vf13,$vf11\n\t"
        "vmulz.xyzw $vf10,$vf10,$vf5z\n\t"
        "vadd.xyzw $vf10,$vf10,$vf13\n\t"
        "vmulz.xyzw $vf10,$vf10,$vf5z\n\t"
        "vadd.xyzw $vf10,$vf10,$vf1\n\t"
        "sqc2 $vf10,0x0(%0)"
        : : "r"(out), "r"(a), "r"(b), "r"(v) : "memory");
}

typedef struct {
    /* 0x00 */ char pad_00[0x21];
    /* 0x21 */ u8 w;
    /* 0x22 */ u8 h;
    /* 0x23 */ u8 x;
} PRyjShipolyTex;

// Texture rectangle (x0, x1, y0, y1 in 1/4096) from the parameter's width / height selection.
void RyjShipoly_GetTexRect(PRyjShipolyTex* p, s32* x0, s32* x1, s32* y0, s32* y1) {
    s32 x = 0;
    s32 w = 0x1000;
    s32 h = 0x1000;

    switch (p->w) {
        case 1:
            w = 0x800;
            break;
        case 2:
            w = 0x400;
            break;
    }
    switch (p->h) {
        case 1:
            h = 0x800;
            break;
        case 2:
            h = 0x400;
            break;
    }
    switch (p->x) {
        case 1:
            x = 0x400;
            w += 0x400;
            break;
        case 2:
            x = 0x800;
            w += 0x800;
            break;
        case 3:
            x = 0xC00;
            w += 0xC00;
            break;
    }
    *x0 = x + 0x10;
    *x1 = w - 0x10;
    *y0 = 0x10;
    *y1 = h - 0x10;
}

INCLUDE_ASM("asm/nonmatchings/ppp/ryjProg/pppRyjDrawShipoly", func_0019C770);
