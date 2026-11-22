#include "common.h"

INCLUDE_ASM("asm/nonmatchings/ppp/draw/md0", op_md_ot8);

INCLUDE_ASM("asm/nonmatchings/ppp/draw/md0", func_001B0118);

INCLUDE_ASM("asm/nonmatchings/ppp/draw/md0", func_001B1BF8);

INCLUDE_ASM("asm/nonmatchings/ppp/draw/md0", func_001B3C00);

INCLUDE_ASM("asm/nonmatchings/ppp/draw/md0", func_001B59C0);

INCLUDE_ASM("asm/nonmatchings/ppp/draw/md0", func_001B8AA0);

INCLUDE_ASM("asm/nonmatchings/ppp/draw/md0", func_001BA340);

INCLUDE_ASM("asm/nonmatchings/ppp/draw/md0", func_001BBB60);

#ifdef VERSION_FM
void* func_0022F768(s32);
void func_001BC048(void);

void fm_func_001B9B30(void) {
    s32* p = func_0022F768(4);

    if (p[0] != 0x494D5547 || p[1] != 0x101) {
        func_001BC048();
    }
}
#endif
