// Placeholder for code that hasn't been assigned to a source file yet (Final Mix offset 0x132D60).
// Functions can be matched here like in any other file; the file may be split later.
#include "common.h"

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_0022F808);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_00232DA0);

extern struct {
    s32 unk0;
    s32 unk4;
} D_00425B80;

void func_0022F888(void) {
    D_00425B80.unk0 = 0x5153484B;
    D_00425B80.unk4 = 0x01317F14;
}

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_00232E08);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_00232F88);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_00232FC8);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_00233018);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_00233058);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_00233098);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_002330D8);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_00233118);

extern s32 D_00351E10;

void func_00233158(void) {
    D_00351E10 = 0;
}

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_00233168);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_002335D8);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_00233610);

extern s32 D_00647780;
extern s32 D_00647784;
extern s32 D_00647788;
void func_00233650(s32 arg0, s32 arg1) {
    D_00647780 = 1;
    D_00647784 = arg0;
    D_00647788 = arg1;
}

extern s32 D_00647780;

void func_00233670(void) {
    D_00647780 = 0;
}

extern s32 D_0064778C;
extern s32 D_00647790;
extern s32 D_00647794;
void func_00233680(s32 arg0, s32 arg1) {
    D_0064778C = 1;
    D_00647790 = arg0;
    D_00647794 = arg1;
}

extern s32 D_0064778C;

void func_002336A0(void) {
    D_0064778C = 0;
}

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_002336B0);

extern s32 D_00647798;

void func_002336C8(void) {
    D_00647798 = 0;
}

extern f32 D_006477A4;

void func_002336D8(void) {
    D_006477A4 = 0;
}

f32 func_002336E8(void) {
    return D_006477A4;
}

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_002336F8);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_00233A80);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_00233AC8);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_00233D08);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_00233DB0);

extern s32 D_006477A8;

s32 func_00233EE8(void) {
    return D_006477A8;
}

extern s32 D_006477A8;
extern s32 D_00647FD4;
extern s32 D_00647FD8;
void func_00233EF8(s32 arg0) {
    D_006477A8 = 1;
    D_00647FD4 = arg0;
    D_00647FD8 = 0;
}

extern s32 D_006477A8;

void func_00233F18(void) {
    D_006477A8 = 0;
}

extern s32 D_00647FDC;
extern s32 D_00647FE0;

void func_00233F28(s32 arg0, s32 arg1) {
    D_00647FDC = arg0;
    D_00647FE0 = arg1;
}

extern s32 D_00425C48[];

s32 func_00233F40(s32 arg0, s32 arg1) {
    s32 *ptr = (s32 *)((s32)&D_00425C48 + (((arg0 * 4) + arg1) * 4));
    s32 val = *ptr;
    *ptr = 0;
    return val;
}

extern s32 D_00425C48[];

void func_00233F68(s32 arg0, s32 arg1) {
    s32 *ptr = (s32 *)((s32)&D_00425C48 + (((arg0 * 4) + arg1) * 4));
    *ptr = 0;
}

extern s32 D_00425C68[];

s32 func_00233F88(s32 arg0, s32 arg1) {
    s32 *ptr = (s32 *)((s32)&D_00425C68 + (((arg0 * 4) + arg1) * 4));
    s32 val = *ptr;
    *ptr = 0;
    return val;
}

extern s32 D_00425C68[];

void func_00233FB0(s32 arg0, s32 arg1) {
    *((s32 *)((s32)&D_00425C68 + (((arg0 * 4) + arg1) * 4))) = 0;
}

extern s32 D_00425C88[];

s32 func_00233FD0(s32 arg0, s32 arg1) {
    s32 *ptr = (s32 *)((s32)&D_00425C88 + (((arg0 * 4) + arg1) * 4));
    s32 val = *ptr;
    *ptr = 0;
    return val;
}

extern s32 D_00425C88[];

void func_00233FF8(s32 arg0, s32 arg1) {
    *((s32 *)((s32)&D_00425C88 + (((arg0 * 4) + arg1) * 4))) = 0;
}

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_00234018);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_00234098);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_00234148);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_00234210);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_00234290);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_00234310);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_002343A8);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_00234440);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_00234508);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_002345A0);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_00234668);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_00234730);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_002347E0);

extern s32 D_00647FEC;

s32 func_00234840(void) {
    return D_00647FEC;
}

extern s32 D_00647FF0;

s32 func_00234850(void) {
    return D_00647FF0;
}

extern s32 D_00647FF4;

s32 func_00234860(void) {
    return D_00647FF4;
}

extern s32 D_00647FF8;

s32 func_00234870(void) {
    return D_00647FF8;
}

extern s32 D_00647FFC;

s32 func_00234880(void) {
    return D_00647FFC;
}

extern s32 D_00648000;

s32 func_00234890(void) {
    return D_00648000;
}

extern s32 D_00648004;

s32 func_002348A0(void) {
    return D_00648004;
}

extern s32 D_00648008;

s32 func_002348B0(void) {
    return D_00648008;
}

extern s32 D_0064800C;

s32 func_002348C0(void) {
    return D_0064800C;
}

extern s32 D_00648010;

s32 func_002348D0(void) {
    return D_00648010;
}

extern s32 D_00648014;

s32 func_002348E0(void) {
    return D_00648014;
}

extern s32 D_00648018;

s32 func_002348F0(void) {
    return D_00648018;
}

extern s32 D_0064801C;

s32 func_00234900(void) {
    return D_0064801C;
}

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_00234910);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_00234F80);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_00235228);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_002353A8);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_00235520);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_00235688);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_002357F0);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_00235950);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_00235AB0);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_00235D70);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_00235EE8);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_00236190);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_00236450);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_00236598);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_002365E0);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_00236618);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_002366A8);

extern s32 D_00648038[];

s32 func_002366C0(s32 arg0) {
    return D_00648038[arg0];
}

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_002366D8);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_002367A0);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_002367F8);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_002368B0);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_002368F8);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_00236910);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_00236928);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_00236970);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_002369E8);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_00236A58);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_00236C68);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_00236D48);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_00236D98);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_00236DE8);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_00236E40);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_00236E80);

void func_00239368(void);

// func_00236F00 (src/unsplit/seg_132D60.c)
void func_00236F00(void) {
    func_00239368();
}

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_00236F18);

void func_00236FC0(void) {

}

void func_00236FC8(void) {

}

s32 func_00236FD0(void) {
    return 0;
}

void func_00236FD8(void *arg0, s32 arg1) {
    s64 val = ((((s32)(arg1 - (s32)(long)arg0) >> 4) - 1) | 0x8000) | ((s64)0x8000 << 45);
    ((s64 *)arg0)[1] = 0xE;
    ((s64 *)arg0)[0] = val;
}

// func_00237008 (src/unsplit/seg_132D60.c)
u64* func_00237008(u64 arg0, u64 arg1, u64* arg2) {
    arg2[0] = arg1;
    arg2[1] = arg0;
    return arg2 + 2;
}

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_00237018);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_002370C8);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_002372E0);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_00237318);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_00237548);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_00237600);

extern void func_00237600(void *arg0);

void func_00237660(void *arg0, s32 arg1, s32 arg2) {
    *(s32 *)((u8 *)arg0 + 0) = arg2;
    *(s32 *)((u8 *)arg0 + 4) = arg1;
    func_00237600(arg0);
}

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_00237680);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_002376C8);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_00237790);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_002378C8);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_00237A48);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_00237B30);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_00237D48);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_00237EC0);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_00237F20);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_002380C0);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_00238258);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_00238440);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_002384E0);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_002386C0);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_00238768);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_002388B8);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_002389F0);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_00238A70);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_00239368);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_002393D8);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_00239488);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_00235F50);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_00239558);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_00239630);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_00239778);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_00239860);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_002399F0);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_00239A80);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_00239B90);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_00239D20);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_00239E30);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_0023A318);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_0023A490);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_0023A608);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_0023A720);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_0023A7E8);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_0023A8D0);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_0023A968);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_0023AED0);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_0023B4B8);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_0023B570);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_0023BB98);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_0023C1B0);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_0023C228);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_0023C270);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_0023C400);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_0023C4D8);

extern s32 D_00651310[];

void func_0023C5A8(s32 arg0) {
    *((s32 *)((s32)&D_00651310 + (arg0 * 0xE0))) = 0;
}

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_0023C5C8);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_0023C7A0);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_0023C8C8);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_0023C968);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_0023CA48);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_0023CB30);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_0023CC80);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_0023CEB0);

extern s32 D_0044A820;

void func_0023CEE8(void) {
    if (D_0044A820 == 0) {
        D_0044A820 = 1;
    }
}

void func_0023CF08(void) {
    if (D_0044A820 == 2) {
        D_0044A820 = 3;
    }
}

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_0023CF30);

extern s32 D_0044A820;

s32 func_0023CFC8(void) {
    return D_0044A820 != 0;
}

void func_0023CFD8(void) {
    D_0044A820 = 0;
}

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_0023CFE8);

extern void func_0011D790(s32, s32);

void func_0023D128(s32 arg0) {
    func_0011D790(45, arg0);
}

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_0023D148);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_0023D1A0);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_0023D1E0);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_0023D208);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_0023D490);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_0023D528);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_0023D698);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_0023D700);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_0023D7E8);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_0023DA08);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_0023DD48);

void func_0023DD48(void);

// func_0023DFC0 (src/unsplit/seg_132D60.c)
void func_0023DFC0(void) {
    func_0023DD48();
}

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_0023DFD8);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_0023E160);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_0023E330);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_0023E5B0);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_0023E8F0);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_0023EC88);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_0023EE80);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_0023F0D8);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_0023F250);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_0023F688);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_0023F700);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_0023F7D8);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_0023F920);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_0023FAD0);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_0023FB90);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_0023FD58);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_0023FEB8);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_0023FF38);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_00240118);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_00240170);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_002401F0);

extern s32 func_00240170(void);
extern void func_002401F0(s32, s32);

void func_002403D0(s32 arg0) {
    func_002401F0(arg0, func_00240170());
}

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_00240400);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_002407B0);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_00240810);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_002408D8);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_00240910);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_00240978);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_002409B0);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_002409E0);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_00240AE0);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_00240B28);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_00240B68);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_00240FA0);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_002410B8);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_00241260);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_0023E0B0);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_00241560);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_002415F0);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_002416A8);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_00241948);

extern u32 D_00652888[];

void func_00241A10(s32 arg0, u32 arg1) {
    D_00652888[arg0 * 0x340] = arg1;
}

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_00241A38);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_00241B60);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_00241C00);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_00241C60);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_00241D60);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_00242A38);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_00242B00);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_00242B38);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_00242B68);

extern struct {
    char _[0xCF0];
    s32 field_0CF0;
} D_00654570;

void func_00242BA0(void) {
    if (D_00654570.field_0CF0 == 0) {
        D_00654570.field_0CF0 = 1;
    }
}

extern s32 D_00655264;

// func_00242BC0 (src/unsplit/seg_132D60.c)
void func_00242BC0(void) {
    D_00655264 = 1;
}

extern s32 D_00652898;

void func_00242BD0(void) {
    D_00652898 = 0;
}

extern s32 D_00652898;

// func_0023F758 (src/unsplit/seg_132D60.c)
void func_0023F758(void) {
    D_00652898 = 1;
}

extern s32 D_00651E50[];

s32 func_00242BF0(s32 arg0) {
    return D_00651E50[arg0];
}

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_00242C08);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_00242EF8);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_00243168);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_002431B8);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_00243208);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_00243278);

void func_002432C8(void *arg0) {
    *(u32 *)((u8 *)arg0 + 12) = 0;
    *(u32 *)((u8 *)arg0 + 8) = 0;
}

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_002432D8);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_00243380);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_002433E8);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_00243508);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_00243630);

extern s32 D_006561D0;

void func_00243668(void) {
    D_006561D0 = 0;
    func_002432C8((u8 *)&D_006561D0 + 0x14);
}

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_00243690);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_002436C0);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_00243A20);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_00243A90);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_00243BD8);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_00243C10);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_00243D18);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_00243DA0);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_00243E58);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_00243EF8);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_00244188);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_00244298);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_002444A0);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_00244500);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_00244670);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_002448D8);

void func_00244960(void) {

}

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_00244968);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_00244A10);

extern void* D_00662540;

void func_00244B00(void) {
    D_00662540 = NULL;
}

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_00244B10);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_00244BE0);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_00244D00);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_00244F28);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_00245090);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_00245148);

s32 func_00245228(void) {
    return D_00662540 != 0;
}

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_00245238);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_00245280);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_002452C8);

extern void* D_006627B8;

void func_002452F0(void) {
    D_006627B8 = NULL;
}

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_00245300);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_002453E8);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_00245508);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_002455C0);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_002456E8);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_00245798);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_002457C8);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_00245840);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_002458A0);

extern u8 D_00662A30[];

void func_002458E0(void) {
    u8 *p;
    s32 i;

    p = D_00662A30;
    goto offset;
offset:
    p += 0x4B60;
    for (i = 9; i >= 0; i--) {
        *(void **)p = NULL;
        p -= 0x860;
    }
}

void func_00245918(void) {

}

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_00245920);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_00245A08);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_00245AD8);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_00245B08);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_00245CD0);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_00245DA0);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_00245E40);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_00245F18);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_00245F58);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_00245F90);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_00245FF0);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_00246020);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_00246038);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_00246120);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_002461F8);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_00246320);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_00246438);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_002464F8);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_00246570);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_00246658);

s32 func_002466E8(u32 arg0) {
    s32 temp_3;
    temp_3 = (s32) ((arg0 >> 0x1F) + arg0) >> 1;
    return (temp_3 < 0x97) ? temp_3 : 0x96;
}

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_00246708);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_00246750);

extern void* D_00668370;

void func_00246A60(void) {
    D_00668370 = NULL;
}

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_00246A70);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_00246AA8);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_00246BC8);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_00246CF0);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_00246DC0);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_00246EA8);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_00246ED8);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_002470D0);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_00247190);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_00247228);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", fm_func_00247258);

extern u8 D_0045FAC0[];

// func_00247350 (src/unsplit/seg_132D60.c)
void func_00247350(void) {
    u8* var_2;
    s32 var_3;
    volatile u8* tmp = D_0045FAC0;
    var_3 = 9;
    var_2 = (u8*)tmp + 0x52B0;
    do {
        var_3--;
        *(void**)var_2 = NULL;
        var_2 -= 0x930;
    } while (var_3 >= 0);
}

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_00247388);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_00247408);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_00247468);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_002474A8);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_002474E8);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_002475D0);

void func_00247678(s32 arg0, s32 *arg1, s32 *arg2) {
    *arg1 = arg0 / 10;
    *arg2 = arg0 % 10;
}

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_002476A0);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_00247930);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_00247B50);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_00247BD0);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_00247C50);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_00247CC8);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_00247CF8);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_00248010);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", fm_func_002480D8);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_00248140);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_00248238);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_00248380);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_00248400);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_002485B8);

extern void* D_00669350;

void func_00245130(void) {
    D_00669350 = NULL;
}

extern void* D_00669350;

void func_00245140(void) {
    D_00669350 = NULL;
}

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_002485F0);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_00248628);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_00248678);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_002486C8);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_00248738);

void func_00248788(void *arg0) {
    *(u32 *)((u8 *)arg0 + 12) = 0;
    *(u32 *)((u8 *)arg0 + 8) = 0;
}

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_00248798);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_00248840);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_002488A8);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_002489C8);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_00248AC8);

extern s32 D_00669700;

void func_00248B00(void) {
    D_00669700 = 0;
    func_00248788((u8 *)&D_00669700 + 0x14);
}

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_00248B28);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_00248B58);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_00248E30);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_00248EA0);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_00248FB8);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_00249010);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_002490F0);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_002491F8);

extern void* D_00469F60;

// func_00249230 (src/unsplit/seg_132D60.c)
void func_00249230(void) {
    D_00469F60 = (void *)1;
}

extern void* D_00469F60;

void func_00249240(void) {
    D_00469F60 = NULL;
}

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_00249250);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_002492D0);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_002492E8);

s32 func_00249370(sceVu0FMATRIX arg0, sceVu0FMATRIX arg1, sceVu0FVECTOR arg2) {
    sceVu0RotMatrixZ(arg0, arg1, arg2[2]);
    sceVu0RotMatrixX(arg0, arg0, arg2[0]);
    sceVu0RotMatrixY(arg0, arg0, arg2[1]);
}

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_002493C0);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_00249420);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_00249518);

void func_00249558(void *arg0, void *arg1) {
    *(s32 *)arg0 = (*(s32 *)arg1 - 0x7000) >> 4;
    *(s32 *)((u8 *)arg0 + 4) = (*(s32 *)((u8 *)arg1 + 4) - 0x7400) >> 4;
}

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_00249580);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_002495C8);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_00249618);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_00249718);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_002497B8);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_00249820);

void func_00249858(f32 *arg0, f32 *arg1) {
    sceVu0CopyVector(arg0, (f32 *)((u8 *)arg1 + 0x20));
}

void func_00249870(void) {
    ((void (*)(void))sceVu0CopyVector)();
}

void func_00249888(f32 *arg0, f32 *arg1) {
    sceVu0CopyVector(arg0, (f32 *)((u8 *)arg1 + 0x10));
}

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_002498A0);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_00249900);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_00249950);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_00249988);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_002499F0);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_00249A48);

extern void func_00249D48(s32 *);

void func_00249C48(void) {
    ((void (*)(void))func_00249D48)();
}

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_00249C60);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_00249D20);

void func_00249D48(s32 *arg0) {
    *arg0 = 0;
}

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_00249D50);

s32 func_00249DA0(s32 arg0) {
    return arg0 + 0x10;
}

extern char D_00491840[];

void func_00249DA8(const char *s1) {
    strncmp(s1, D_00491840, 4);
}

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_00249DC8);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_00249EB8);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_00249F08);
