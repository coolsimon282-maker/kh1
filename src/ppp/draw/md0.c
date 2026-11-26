/**
 * Model drawing kernels for op1_md_draw (md.c): ordering-table and direct variants by draw flags, and the shape
 * drawing used by the shape effects. All still assembly.
 */
#include "common.h"

INCLUDE_ASM("asm/nonmatchings/ppp/draw/md0", op_md_ot8);

// op_md_ot8 variant for flags 0x80 with 0x300.
INCLUDE_ASM("asm/nonmatchings/ppp/draw/md0", op_md_ot8_x300);

// Model draw into the ordering table (op1_md_draw, flags without 0x80 and 0x300).
INCLUDE_ASM("asm/nonmatchings/ppp/draw/md0", op_md_ot);

// Model draw into the ordering table with flags 0x300.
INCLUDE_ASM("asm/nonmatchings/ppp/draw/md0", op_md_ot_x300);

// Model draw sent directly (op1_md_draw flag 4, without 0x300).
INCLUDE_ASM("asm/nonmatchings/ppp/draw/md0", op_md_direct);

// Model draw sent directly with flags 0x300.
INCLUDE_ASM("asm/nonmatchings/ppp/draw/md0", op_md_direct_x300);

// Shape drawing used by pppDrawShapeDraw and pppKeShpTail(2)Draw, probably.
INCLUDE_ASM("asm/nonmatchings/ppp/draw/md0", op_shape_draw);

INCLUDE_ASM("asm/nonmatchings/ppp/draw/md0", func_001BBB60);

#ifdef VERSION_FM
void* WorkBuffers_Get(s32);
void func_001BC048(void);

void fm_func_001B9B30(void) {
    s32* p = WorkBuffers_Get(4);

    if (p[0] != 0x494D5547 || p[1] != 0x101) {
        func_001BC048();
    }
}
#endif
