#include "ppp.h"

#ifdef VERSION_FM
typedef struct {
    /* 0x0 */ pppCDT cdt;
    /* 0x4 */ pppParamPObj bornPt;
    /* 0xC */ u8 cmdContinue;
} PKeThHitBorn;

typedef struct ThHitNode {
    /* 0x00 */ struct ThHitNode* next;
    /* 0x04 */ char unk_04[0x32];
    /* 0x36 */ u8 idx;
    /* 0x37 */ char unk_37;
    /* 0x38 */ u64 unk_38 : 54;
    u64 noBorn : 1;
    u64 unk_38b : 4;
    u64 hit : 1;
    u64 unk_38c : 4;
    /* 0x40 */ u8 data[1][0x30];
} ThHitNode;

typedef union {
    pppPObject* p;
} PObjPtr;

pppPObject* pppCreatePObject(ppvmng* mng, void* pdt);
void op_vec_copy_xyz(void* dst, void* src);

void pppKeThHitBornCalc(pppPObject* pobj, PKeThHitBorn* p, pppCtrlTable* ctbl) {
    u8* v = (u8*)&pobj->val[ctbl->useVal[1]];
    ThHitNode* n;
    pppPObject* born;
    // no plain-C form found that puts pdt in $2 (ppvMng then lands in $5 like the target)
    register void* pdt asm("$2");

    if (pobj->time == p->cdt.time) {
        if (p->cmdContinue) {
            *v |= 2;
        } else {
            *v &= ~2;
        }
    }
    if (ppvUserStopPartF != 0 || ppvMng->stop || ppvMng->unk_B4 != 0) {
        return;
    }
    if (p->bornPt.pdtn == -1) {
        return;
    }
    n = *(ThHitNode**)&pobj->val[ctbl->useVal[0]];
    if (*v & 2) {
        for (; n != NULL; n = n->next) {
            if (*(u16*)((u8*)n + 0x3E) & 0x800) {
                born = NULL;
                pdt = (char*)ppvMng->unk_80 + p->bornPt.pdtn * 16;
                if (pdt != NULL) {
                    born = pppCreatePObject(ppvMng, pdt);
                    ((PObjPtr*)&born->ppobj)->p = pobj;
                }
                op_vec_copy_xyz(&born->val[p->bornPt.valoff], n->data[n->idx]);
            }
        }
    } else {
        for (; n != NULL; n = n->next) {
            if ((*(u64*)((u8*)n + 0x38) & 0x0840000000000000) == 0x0800000000000000) {
                born = NULL;
                pdt = (char*)ppvMng->unk_80 + p->bornPt.pdtn * 16;
                if (pdt != NULL) {
                    born = pppCreatePObject(ppvMng, pdt);
                    ((PObjPtr*)&born->ppobj)->p = pobj;
                }
                op_vec_copy_xyz(&born->val[p->bornPt.valoff], n->data[n->idx]);
            }
        }
    }
}

#else
INCLUDE_ASM("asm/nonmatchings/ppp/keProg/pppKeThHitBorn", pppKeThHitBornCalc);
#endif

void pppKeThHitBornCon(pppPObject* pobj, pppCtrlTable* ctbl) {
    u8* v = (u8*)&pobj->val[ctbl->useVal[1]];

    *v = 0;
}
