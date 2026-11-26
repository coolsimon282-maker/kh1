#include "ppp/pppKeLns.h"

typedef struct {
    /* 0x00 */ pppCDT cdt;
    /* 0x04 */ s32 shpIdx;
    /* 0x08 */ u8 col[4];
    /* 0x0C */ f32 scale;
} PKeLnsArndDraw;

typedef struct {
    /* 0x00 */ void* shp;
    /* 0x04 */ u8 col[4];
    /* 0x08 */ f32 (*mat)[4];
    /* 0x0C */ f32 scale;
    /* 0x10 */ f32* scl;
} KeLnsArndArg;

void KeLnsLp_Start(pppPObject* pobj, PKeLnsArndDraw* p, pppCtrlTable* ctbl);
void KeLnsShp_Draw(KeLnsArndArg* arg, s32 arg1);

void pppKeLnsArndDraw(pppPObject* pobj, PKeLnsArndDraw* p, pppCtrlTable* ctbl) {
    KeLnsArndArg arg;

    KeLnsLp_Start(pobj, p, ctbl);
    arg.col[0] = p->col[0] * ppvMng->colorR;
    arg.col[1] = p->col[1] * ppvMng->colorG;
    arg.col[2] = p->col[2] * ppvMng->colorB;
    arg.col[3] = p->col[3] * ppvMng->colorA;
    arg.mat = ppvScreenMatrix;
    arg.scl = ppvParScl;
    arg.scale = p->scale;
    arg.shp = &pobj->val[ctbl->useVal[0]];
    KeLnsShp_Draw(&arg, 0);
}

void pppKeLnsArndCon(pppPObject* pobj, pppCtrlTable* ctbl) {
    KeLnsArnd* arnd = (KeLnsArnd*)&pobj->val[ctbl->useVal[0]];
    
    KeLnsArnd_Init(arnd);
}

typedef struct {
    /* 0x00 */ pppCDT cdt;
    /* 0x04 */ s32 shpIdx;
    /* 0x08 */ u8 unk_08[8];
    /* 0x10 */ u16 unk_10;
    /* 0x12 */ u16 unk_12;
    /* 0x14 */ u8 unk_14[2];
    /* 0x16 */ u8 unk_16;
    /* 0x17 */ u8 unk_17;
} PKeLnsArnd;

// KeLnsArnd as this function uses it (the header's version stops at 0xC)
typedef struct {
    /* 0x00 */ KeLnsFlr* lp;
    /* 0x04 */ pppShapeSt* shp;
    /* 0x08 */ u8 unk_08[2];
    /* 0x0A */ u16 unk_0A;
    /* 0x0C */ u16 unk_0C;
    /* 0x0E */ u8 unk_0E;
} VKeLnsArnd;

void KeLnsClm_SetShape(VKeLnsArnd* p, pppShapeSt* shp, u8 arg2); // ppp/xberry

// At the start time: links the work to its second value block and sets the shape (KeLnsClm_SetShape) and parameters.
void KeLnsArnd_Start(pppPObject* pobj, PKeLnsArnd* p, pppCtrlTable* ctbl) {
    VKeLnsArnd* arnd = (VKeLnsArnd*)&pobj->val[ctbl->useVal[0]];
    pppShapeSt* shp;

    if (p->cdt.time == pobj->time) {
        *(s32*)&arnd->lp = (s32)&pobj->val[ctbl->useVal[1]];
        if (p->shpIdx == 0xFFFF) {
            arnd->shp = NULL;
        } else {
            shp = &ppvEnv->lpShape[p->shpIdx];
            if (shp != arnd->shp) {
                KeLnsClm_SetShape(arnd, shp, p->unk_16);
            }
        }
        arnd->unk_0A = p->unk_12;
        arnd->unk_0C = p->unk_10;
        arnd->unk_0E = p->unk_17;
    }
}
