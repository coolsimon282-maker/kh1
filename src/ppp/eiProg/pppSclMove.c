#include "ppp.h"

typedef struct {
    /* 0x00 */ f32 x;
    /* 0x04 */ f32 y;
    /* 0x08 */ f32 z;
} VSclMove;

INCLUDE_ASM("asm/nonmatchings/ppp/eiProg/pppSclMove", pppSclMoveCalc);

void pppSclMoveCon(pppPObject* pobj, pppCtrlTable* ctbl) {
    VSclMove* v = (VSclMove*)&pobj->val[ctbl->useVal[1]];

    v->x = v->y = v->z = 0.0f;
}
