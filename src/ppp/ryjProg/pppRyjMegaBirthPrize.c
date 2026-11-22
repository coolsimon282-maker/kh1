#include "ppp.h"

INCLUDE_ASM("asm/nonmatchings/ppp/ryjProg/pppRyjMegaBirthPrize", pppRyjMegaBirthPrizeDraw);

extern u8 D_0035C710[];

void pppRyjMegaBirthPrizeCon(void) {
    memset(D_0035C710, 0, 0x2000);
    ppvMng->unk_B3 = 1;
    ppvMng->drawPriority = 1;
}

typedef struct {
    /* 0x00 */ char unk_00[0x8];
    /* 0x08 */ s32 unk_08;
    /* 0x0C */ char unk_0C[0x44];
} RyjPrize; // size = 0x50

typedef struct {
    /* 0x00 */ s32 unk_00;
    /* 0x04 */ s32 unk_04;
} RyjPrizeHdr;

typedef struct {
    /* 0x00 */ s32 unk_00;
    /* 0x04 */ RyjPrizeHdr* unk_04;
    /* 0x08 */ RyjPrize* unk_08;
} RyjPrizeMng;

extern RyjPrizeMng D_0035E710;

RyjPrize* func_0019FD18(s32 arg0) {
    RyjPrize* e = D_0035E710.unk_08;
    RyjPrize* ret = NULL;
    s32 i;
    if (e != NULL) {
        for (i = 0; i < D_0035E710.unk_04->unk_04; i++, e++) {
            if (arg0 == e->unk_08) {
                ret = e;
                break;
            }
        }
    }
    return ret;
}

INCLUDE_ASM("asm/nonmatchings/ppp/ryjProg/pppRyjMegaBirthPrize", func_0019FD78);

INCLUDE_ASM("asm/nonmatchings/ppp/ryjProg/pppRyjMegaBirthPrize", func_0019FE58);

INCLUDE_ASM("asm/nonmatchings/ppp/ryjProg/pppRyjMegaBirthPrize", func_0019FF38);
