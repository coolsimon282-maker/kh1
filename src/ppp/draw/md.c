#include "common.h"
#include "ppp/draw.h"
#include "libgraph.h"

extern u64 D_00373060[];
extern u64 D_0061E800[];

s32 D_0036F4C0;
s32 D_0036F4F0;

void set_ztest_off(void) {
    sceGsSyncPath(0, 0);
    sceDmaSend(oa_dmagif, &D_0036F4C0);
}

void set_invisible(void) {
    sceGsSyncPath(0, 0);
    sceDmaSend(oa_dmagif, &D_0036F4F0);
}

void unset_test(void) {
    D_00373060[4] = D_0061E800[12];
    D_00373060[5] = D_0061E800[13];
    sceGsSyncPath(0, 0);
    sceDmaSend(oa_dmagif, D_00373060);
}

INCLUDE_ASM("asm/nonmatchings/ppp/draw/md", op1_md_draw);
