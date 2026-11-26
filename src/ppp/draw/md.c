#include "common.h"
#include "ppp/draw.h"
#include "libgraph.h"

extern u64 D_00373060[];
extern u64 D_0061E800[];

#ifdef VERSION_FM
// .data (0x00373000-0x00373090): DMA end tag + GIF tag + one A+D register write each
u64 D_0036F4C0[6] __attribute__((aligned(16))) = {
    0x70000002, 0x0,
    0x1000000000008001ULL, 0xE,
    0x3000D, 0x47,
};
u64 D_0036F4F0[6] __attribute__((aligned(16))) = {
    0x70000002, 0x0,
    0x1000000000008001ULL, 0xE,
    0x72001, 0x47,
};
u64 D_00373060[6] __attribute__((aligned(16))) = {
    0x70000002, 0x0,
    0x1000000000008001ULL, 0xE,
    0x0, 0x0,
};
#else
s32 D_0036F4C0;
s32 D_0036F4F0;
#endif

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

#ifdef VERSION_FM
typedef struct {
    /* 0x00 */ u32 flag;
    /* 0x04 */ char pad_04[0x48];
    /* 0x4C */ s8 invisible;
    /* 0x4D */ s8 ztestOff;
} MdDrawSt;

extern s32 D_00616224;
extern s32 ppvCurPrimpLen;
extern s32 ppvPrimpLen;
s32 func_001B8AA0(s32 pkt, MdDrawSt* st);
s32 func_001B59C0(s32 pkt, MdDrawSt* st);
s32 func_001B0118(s32 pkt, MdDrawSt* st);
s32 op_md_ot8(s32 pkt, MdDrawSt* st);
s32 func_001B3C00(s32 pkt, MdDrawSt* st);
s32 func_001B1BF8(s32 pkt, MdDrawSt* st);

s32 op1_md_draw(s32 pkt, MdDrawSt* st, s32 size) {
    u32 flag = st->flag;
    s32 r;

    if (flag & 4) {
        if (st->ztestOff) {
            set_ztest_off();
        } else if (st->invisible) {
            set_invisible();
        }
        if (st->flag & 0x300) {
            r = func_001B8AA0(pkt, st);
        } else {
            r = func_001B59C0(pkt, st);
        }
        if (*(u16*)&st->invisible) {
            unset_test();
        }
    } else {
        if (ppvCurPrimpLen + size >= ppvPrimpLen) {
            return D_00616224;
        }
        if (flag & 0x80) {
            if (flag & 0x300) {
                r = func_001B0118(pkt, st);
            } else {
                r = op_md_ot8(pkt, st);
            }
        } else {
            if (flag & 0x300) {
                r = func_001B3C00(pkt, st);
            } else {
                r = func_001B1BF8(pkt, st);
            }
        }
        ppvCurPrimpLen += r - D_00616224;
    }
    return r;
}

#else
INCLUDE_ASM("asm/nonmatchings/ppp/draw/md", op1_md_draw);
#endif
