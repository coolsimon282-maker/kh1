#include "ppp.h"

typedef struct {
    /* 0x0 */ s16 ict;
    /* 0x2 */ u16 aptct;
} VVertexApLc;

void pppVertexApLcCon(pppPObject* pobj, pppCtrlTable* ctbl) {
    VVertexApLc* v = (VVertexApLc*)&pobj->val[ctbl->useVal[0]];

    v->ict = 0;
    v->aptct = 0;
}

INCLUDE_ASM("asm/nonmatchings/ppp/eiProg/pppVertexApLc", func_001862E0);

INCLUDE_ASM("asm/nonmatchings/ppp/eiProg/pppVertexApLc", pppVertexApLcCalc);
