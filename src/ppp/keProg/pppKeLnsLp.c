#include "ppp/pppKeLns.h"

typedef struct {
    /* 0x0 */ pppCDT cdt;
    /* 0x4 */ f32 lWid;
    /* 0x8 */ f32 pow;
    /* 0xC */ u8 r;
    /* 0xD */ u8 md;
} PKeLnsLp;

typedef struct {
    KeLnsLp* lp;
    f32* pos;
    void* wm;
    void* sm;
} KeLnsLpInfo;
void func_001AB0F0(void* dst, void* src);
void func_001A76E8(KeLnsLpInfo* info);

void pppKeLnsLpDraw(pppPObject* pobj, PKeLnsLp* p, pppCtrlTable* ctbl) {
    KeLnsLp* lp = (KeLnsLp*)&pobj->val[ctbl->useVal[0]];
    sceVu0FVECTOR v;
    KeLnsLpInfo info;

    if (p->cdt.time == pobj->time) {
        lp->pow += p->pow;
        lp->r = p->r;
        lp->lVec[3] += p->lWid;
        lp->md = p->md;
    }
    if (lp->md) {
        *(u_long128*)v = 0;
        v[2] = 1.0f;
        v[3] = 1.0f;
        sceVu0ApplyMatrix(v, ppvPObj.next->cmat, v);
        func_001AB0F0(lp->lVec, v);
    }
    lp->lcPos[0] = ppvPObj.next->cmat[3][0];
    lp->lcPos[1] = ppvPObj.next->cmat[3][1];
    lp->lcPos[2] = ppvPObj.next->cmat[3][2];
    info.wm = ppvWorldMatrix;
    info.sm = ppvScreenMatrix;
    info.lp = lp;
    info.pos = ppvPObj.next->cmat[3];
    func_001A76E8(&info);
}

void pppKeLnsLpCon(pppPObject* pobj, pppCtrlTable* ctbl) {
    KeLnsLp* lp = (KeLnsLp*)&pobj->val[ctbl->useVal[0]];

    KeLnsLp_Init(lp);
    lp->lVec[3] = 0;
    lp->pow = 0;
}

void pppKeLnsLpCon2(pppPObject* pobj, pppCtrlTable* ctbl) {
    KeLnsLp* lp = (KeLnsLp*)&pobj->val[ctbl->useVal[0]];

    lp->lVec[3] = 0;
    lp->pow = 0;
}

typedef struct {
    /* 0x0 */ pppCDT cdt;
    /* 0x4 */ s32 shpNo;
} PKeLnsLpShp;

void func_00193978(pppPObject* pobj, PKeLnsLpShp* p, pppCtrlTable* ctbl) {
    KeLnsArnd* v = (KeLnsArnd*)&pobj->val[ctbl->useVal[0]];
    pppShapeSt* shp;

    if (p->cdt.time == pobj->time) {
        *(s32*)&v->lp = (s32)&pobj->val[ctbl->useVal[1]];
        if (p->shpNo == 0xFFFF) {
            v->shp = NULL;
            return;
        }
        shp = &ppvEnv->lpShape[p->shpNo];
        if (shp != v->shp) {
            *(s32*)&v->shp = (s32)shp;
            v->flr.cnt = ((u16*)*(s32*)shp)[9];
            v->flr.seqIdx = 0;
        }
    }
}
