#include "ppp.h"

typedef struct {
    /* 0x0 */ pppCDT cdt;
    /* 0x4 */ pppHCVECTOR col;
} PColor;

typedef struct {
    /* 0x0 */ pppHCVECTOR col;
    /* 0x8 */ pppCVECTOR release_col;
} VColor;

// release_col = (u8)((col * ppvMng->color) >> 7) per channel (hand-written MMI/VU0 code)
static inline void colorRelease(VColor* v, f32* color) {
    __asm__ volatile(
        "lw $2, 4(%0)
"
        "pextlw $2, $2, $0
"
        "lw $3, 0(%0)
"
        "or $2, $2, $3
"
        "pextlh $2, $0, $2
"
        "qmtc2.ni $2, $vf1
"
        "vitof0.xyzw $vf1, $vf1
"
        "lqc2 $vf2, 0(%1)
"
        "vmul.xyzw $vf1, $vf1, $vf2
"
        "vftoi0.xyzw $vf1, $vf1
"
        "qmfc2.ni $2, $vf1
"
        "psrlw $2, $2, 7
"
        "ppach $2, $0, $2
"
        "ppacb $2, $0, $2
"
        "sw $2, 8(%0)
"
        : : "r"(v), "r"(color) : "$2", "$3");
}

void pppColorCalc(pppPObject* pobj, PColor* p, pppCtrlTable* ctbl) {
    VColor* v = (VColor*)&pobj->val[ctbl->useVal[0]];

    if (ppvUserStopPartF != 0 || ppvMng->stop || ppvMng->unk_B4 != 0) {
        return;
    }
    if (p->cdt.time == pobj->time) {
        v->col.r += p->col.r;
        v->col.g += p->col.g;
        v->col.b += p->col.b;
        v->col.a += p->col.a;
    }
    colorRelease(v, &ppvMng->colorR);
}

void pppColorCon(pppPObject* pobj, pppCtrlTable* ctbl) {
    VColor* v = (VColor*)&pobj->val[ctbl->useVal[0]];
    
    v->col.r = v->col.g = v->col.b = v->col.a = 0;
}
