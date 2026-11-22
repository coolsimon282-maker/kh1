#include "ppp/pppKeLns.h"

INCLUDE_ASM("asm/nonmatchings/ppp/keProg/pppKeLnsArnd", pppKeLnsArndDraw);

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

void func_001A7F48(VKeLnsArnd* p, pppShapeSt* shp, u8 arg2); // ppp/xberry

void func_00193BC8(pppPObject* pobj, PKeLnsArnd* p, pppCtrlTable* ctbl) {
    VKeLnsArnd* arnd = (VKeLnsArnd*)&pobj->val[ctbl->useVal[0]];
    pppShapeSt* shp;

    if (p->cdt.time == pobj->time) {
        *(s32*)&arnd->lp = (s32)&pobj->val[ctbl->useVal[1]];
        if (p->shpIdx == 0xFFFF) {
            arnd->shp = NULL;
        } else {
            shp = &ppvEnv->lpShape[p->shpIdx];
            if (shp != arnd->shp) {
                func_001A7F48(arnd, shp, p->unk_16);
            }
        }
        arnd->unk_0A = p->unk_12;
        arnd->unk_0C = p->unk_10;
        arnd->unk_0E = p->unk_17;
    }
}
