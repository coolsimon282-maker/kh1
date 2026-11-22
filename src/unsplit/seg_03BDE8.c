// Placeholder for code that hasn't been assigned to a source file yet (Final Mix offset 0x03BDE8).
// Functions can be matched here like in any other file; the file may be split later.
#include "common.h"

typedef struct {
    char pad[0x5CC];
    u32 unk_5CC[0x9E];
    s8 unk_844[4];
    u16 unk_848[0x18];
    u64 unk_878;
    u8 unk_880;
} Seg3010F8;
typedef struct {
    s8 unk_00;
    s8 unk_01;
    s8 unk_02;
    s8 unk_03;
    char pad[0x10];
} Seg551670;
typedef struct {
    u8 b[16];
} Seg16;

extern s32 D_0052CB18;
extern s32 D_00304C70[];
extern u8* D_00547BB0;
extern u8 D_00533BA0[];
extern u8* D_00547BA0;
extern u8* D_00547BA8;
extern u8* D_00547BAC;
extern s32 D_0054B808[];
extern s32 D_0054F44C;
extern sceVu0FVECTOR D_002C58A0;
extern f32 D_002B8344;
extern s32 D_0054F970[];
extern s32 D_00551600;
extern s32 D_005516E8;
extern f32 D_00351B60[];
extern f32 D_00351B88[];
extern s32 D_002E26A0;
extern f32 D_00551D74;
extern void* D_00559DB0;
extern void* D_0055BDE0;
extern s32 D_00574FB4;
extern u8 D_00575788[];
extern s32 D_0035BD50[];
extern s32 D_0035BFC0[];
extern s32 D_0035C090[];
extern s32 D_0035C140[];
extern s32 D_0035C1F0[];
extern s32 D_0035C2C0[];
extern s32 D_0035C360[];
extern s32 D_0035C710[];
extern s32 D_0035FB20[];
extern s32 D_0035E710[];
extern s32 D_00360F30[];
extern sceVu0FVECTOR D_002DECE0;
extern sceVu0FVECTOR D_002DECF0;
extern s32 D_005758F0[];
extern s32 D_00575920[];
extern s32 D_00362690[];
extern s32 D_003626C0[];
extern s32 D_005759B0[];
extern s32 D_003626F0[];
extern f32 D_00362660[];
extern f32 D_00362680[];
extern sceVu0FVECTOR D_00362670;
extern sceVu0FVECTOR D_00362400;
extern s32 D_00362710;
extern s32 D_00304BF0[];
extern f32 D_00304D64[][2];
extern s32 D_00532B80;
extern s32 D_00308874[];
extern s32 D_00308CE0[];
extern s32 D_00348CE0[];
extern s32* D_00350CE0;
extern s32 D_0054C1B0[];
extern s32 D_0054C438;
extern s32 D_0054C43C;
extern s32 D_0054F440;
extern s32 D_00350D88[];
extern u8 D_00551608[];
extern Seg551670 D_00551670[];
extern s32 D_00351A48;
extern s32 D_00351AC0;
extern u8 D_00551970[][0x20];
extern s32 D_00358BE0;
extern s32 D_005757B0[];
extern u32 D_002C5960;
extern f32 D_00575900[];
extern u8* D_00362438;
extern s32 D_003626B0;
extern s32 D_00575894;
extern s32 D_002DED08;
extern s32 D_0036244C;
extern s32 D_00362450;
extern s32 D_00362454;
extern sceVu0FVECTOR D_00362410;
extern s32 D_00362704;

s32 fm_func_002193F0(void);
void func_0013F770(void);
void func_0013FD88(u8*, f32);
void sceVu0ScaleVector(f32*, f32*, f32);
void func_00140DB8(void);
void func_0013C458(s32);
void func_001418B8(s32*);
void sceVu0ScaleVectorXYZ(f32*, f32*, f32);
s32 func_001471E8(void);
s32 func_00147808(s32);
s32 func_00146B90(u8*, s32, s32, s32);
void func_00148570(s32);
s32 func_00148968(s32, s32, s32);
void func_001487F8(s32, s32, s32, s32);
void func_0011EF58(s32*, s32);
void func_00149170(s32, s32);
void func_001412F8(s32, s32);
s32 func_00141A40(u8*);
void sceVu0CopyVector(sceVu0FVECTOR v0, sceVu0FVECTOR v1);
void func_00137318(void);
void func_00130398(s32, s32, f32);
void func_00150AF0(void);
void func_00153C50(s32, s32);
s32 func_001320A8(void);
void func_00155760(s32);
void func_00157AD8(s32);
void func_00131498(s32, s32);
void func_00121EB0(s32);
void func_0015D1D0(void);
void sceVu0CopyVectorXYZ(f32* v0, f32* v1);
void* func_0011EEB8(void*, s32, s32);
s32 func_0022F578(s32 arg0);
void func_00215A88(void);
void func_00161A08(s32);
void func_001606D0(s32, s32, s32);
void func_001681B8(s32, s32);
void func_0016F640(void);
void func_00170E98(void);
void func_00175A98(void);
void* memset(void*, s32, u32);
void func_00175D60(s32*, s32);
void func_00175DA8(s32*, s32);
void func_001759C0(void);
void func_00175E38(s32*);
void func_001759E8(void);
void func_00175E80(s32*);
void func_00175EC8(s32*);
void func_00175F10(s32*);
void pppSetPrimPacket(u_long128* primPacketArea, s32 len);
void func_00181040(void);
void func_001810D0(void);
void func_00181110(void);
void func_00181200(s32);
void func_001812B0(void);
void func_00181340(void);
void func_001813F0(void);
void func_001814C8(void);
void func_001815A0(s32);
s32 func_00181600(s32 arg0);
void func_00181BA8(s32* arg0);
void func_001838E8(void);
void sceVu0OuterProduct(f32*, f32*, f32*);
void func_00108180(s32);
void func_001081A0(s32);
f32 func_001376E8(s32);
void func_00137688(s32, f32);
void* func_0022F768(s32);
void func_001315C0(s32, s32, void*, f32);
void func_001417A0(void*, s32);
void func_001586F0(void);
void func_001252F8(void);
void func_0016F7B8(void);
void func_00141EB8(void);
s32 func_001EE090(void);
s32 func_001468B0(void);
u8* func_001208E0(s32 (*)(void));
s32 func_00146A68(u8*, s32, s32, s32);
s32 func_001473A8(s32, s32, u8*, s32);
void func_0011D1F8(s32, s32, s32);
u8* func_00147A10(s32);
void func_00176BA8(u8*, s32);
u8* func_00148CB0(s32);
void func_00177908(s32*);
void func_001496C8(s32, s32);
void func_00149FA0(void);
void func_0014AA50(s32);
void func_00141AB8(s32);
void func_00152538(u8*);
u64* func_00156628(void);
void func_00157910(s32);
void func_001358B8(s32, s32);
s32 func_00158C78(void);
s32 func_00155A90(void);
void func_0014CCE0(s32);
void func_0014F658(s32, s32);
void sceVu0SubVector(f32*, f32*, f32*);
f32 sceVu0InnerProduct(f32*, f32*);
void func_0013DFB8(u8*, s32);
f32 func_001629E8(void);
void func_00176EA8(void);
s32 func_00176EE0(void);
void func_001831A0(void);
void func_00175BE0(s32*, s32, s32, s32, s32, s32, s32);
void func_0017F580(f32, f32, f32, f32, s32);
void func_00178140(s32);
void func_00176CC8(s32);
void func_0017D208(void);
void func_0017F178(void);
void func_0017F688(void);

void func_0013BD88(s32* p, s32 a, s32 b) {
    p[0] = a;
    p[1] = b;
    p[2] = 0;
    p[3] = 0;
}

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_0013BDA0);

void func_0013BEF0(s32 a) {
    func_00137688(a, func_001376E8(a));
}

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", fm_func_0013BF20);

s32 func_0013BF68(void) {
    return fm_func_002193F0() == 2;
}

void func_0013BF20(s32 a) {
    if (a != 0) {
        ((Seg3010F8*)D_003010F8)->unk_880 = 1;
    } else {
        ((Seg3010F8*)D_003010F8)->unk_880 = 0;
    }
}

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_0013BFB8);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_0013C008);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_0013C108);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_0013C188);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_0013C148);

void func_0013C1E0(s32 a) {
    ((u8*)D_003010F8)[0x48C] = a;
}

void func_0013C1F0(s32 a) {
    ((u8*)D_003010F8)[0x48D] = a;
}

void func_0013C270(s32 i, s32 a) {
    ((Seg3010F8*)D_003010F8)->unk_844[i] = a;
}

s8 func_0013C288(s32 i) {
    return ((Seg3010F8*)D_003010F8)->unk_844[i];
}

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_0013C230);

s32 func_0013C280(s32 n) {
    return ((Seg3010F8*)D_003010F8)->unk_878 & ((u64)1 << n);
}

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_0013C2A8);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_0013C360);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_0013C338);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_0013C3F8);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_0013C458);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_0013C548);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_0013C598);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_0013C638);

s32 func_0013C6A8(u32 n) {
    return ((Seg3010F8*)D_003010F8)->unk_5CC[n >> 2] & (1 << (n & 3));
}

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_0013C668);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_0013C778);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_0013C768);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_0013C7D0);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_0013C858);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_0013C968);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_0013C9E0);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_0013CAE8);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_0013CB18);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_0013CE98);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_0013CEC8);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_0013CF28);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_0013CF78);

u32 func_0013CFC0(u8* p) {
    u32 n;
    *(u32**)(p + 8) -= 1;
    n = **(u32**)(p + 8);
    *(u32**)(p + 8) -= n >> 2;
    return n;
}

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_0013CFE8);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_0013DAA8);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_0013DA88);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_0013DB30);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_0013DBB0);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_0013DBE0);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_0013DC10);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_0013DD40);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_0013DF40);

void func_0013DFA0(s32* p) {
    *p &= ~0x4000;
}

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_0013DFB8);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_0013E000);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_0013E1F8);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_0013E558);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_0013E638);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_0013E978);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_0013EAB0);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_0013ECF8);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_0013ED88);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_0013EE40);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_0013F0C0);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_0013F108);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_0013F198);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_0013F2C0);

s32 func_0013F330(u8* p, s32 a) {
    if (*(f32*)(*(u8**)(p + 0x148) + 0x50) > 25.0f) {
        a += 9;
    }
    return a;
}

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_0013F358);

void func_0013F450(s32* p) {
    p[0] &= ~0x200000;
    p[0x1CC / 4] |= 1;
}

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_0013F478);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_0013F510);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_0013F618);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_0013F6D0);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_0013F770);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_0013F8A8);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_0013F910);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_0013FBA0);

s32 func_0013FC08(void) {
    func_0013F770();
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_0013FC28);

s32 func_0013FC68(u8* p, s32 a) {
    if (a == 0) {
        return 0;
    }
    return *(s32*)(p + 0x70);
}

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_0013FC80);

void func_0013FD10(s32* p) {
    *p |= 0x30;
}

void func_0013FD20(s32* p) {
    *p &= ~0x30;
}

void func_0013FD38(s32* p) {
    p[0] |= 0x200000;
    p[0x1CC / 4] &= ~1;
}

void func_0013FD60(s32* p) {
    p[0] &= ~0x200000;
    p[0x1CC / 4] |= 1;
}

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_0013FD88);

void func_0013FE10(u8* p) {
    func_0013FD88(p, *(f32*)(p + 0x14));
}

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_0013FE28);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_0013FE80);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_0013FF00);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00140070);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_001401D8);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00140370);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_001404D8);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_001406D0);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00140838);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00140960);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00140D50);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00140DB8);

void func_00140EE0(u8* p, f32* v) {
    sceVu0ScaleVector(v, (f32*)(p + 0x20), D_002B8344);
}

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00140F08);

s32 func_00140F88(void) {
    func_00140DB8();
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00140FA8);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00141018);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00141078);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_001410D8);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00141138);

s32 func_00141200(u8* p, s32 bit) {
    return (*(s32*)(*(u8**)(p + 0x6C) + 0x70) >> bit) & 1;
}

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00141218);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00141288);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_001412F8);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00141348);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00141448);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00141468);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00141668);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00141608);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00141720);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_001417A0);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00141858);

void func_00141898(u8* p) {
    func_0013C458(*(u16*)(*(u8**)(p + 0x130) + 0x4C));
}

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_001418B8);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00141A40);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00141AB8);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00141B10);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00141E68);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00141EB8);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00141F10);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00142000);

void func_00142030(void) {
    D_0052CB18 = 0;
    func_001418B8(D_00304C70);
}

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00142058);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_001421D0);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00142240);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_001424E8);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00142340);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00142388);

void func_00142470(u8* p, u_long128* v) {
    *(u_long128*)(p + 0x350) = *v;
}

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00142480);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_001425D0);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00142618);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_001426A8);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00142730);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_001427D0);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_001429F8);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00142B30);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00142C80);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00142CF0);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00142E30);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00142FE0);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00143080);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00143180);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00143660);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00143818);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00143A70);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00143D20);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00143EB8);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00144060);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_001441B8);

void func_00144350(u8* p) {
    *(s32*)(*(u8**)(p + 0x148) + 0xBC) = 0;
    *(s32*)(*(u8**)(p + 0x148) + 0xB0) = 0;
}

f32 func_00144368(u8* p) {
    return *(f32*)(p + 0x324) - *(f32*)(p + 0x2D4);
}

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00144378);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_001443A8);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00144410);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00144510);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00144650);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_001447A0);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00144810);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00144958);

void func_00144CE0(u8* p, f32* v) {
    sceVu0ScaleVectorXYZ(v, (f32*)(p + 0x20), D_002B8344);
}

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00144D08);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00144E38);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00144E88);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00144EB0);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00145008);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_001452E0);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00145398);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00145188);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00145240);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_001452A0);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_001453A8);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00145528);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00145858);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00145AA0);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00145CE8);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_001460B8);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00146188);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00146610);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00146740);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00146508);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00146590);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00146600);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00146678);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00146718);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00146778);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_001467E8);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00146878);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_001468B0);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_001468F8);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00146BC8);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00146998);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00146A68);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00146B90);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00146BD0);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00146C98);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00146FB8);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00146FF0);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00147138);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_001471E8);

s32 func_00147240(void) {
    return func_001471E8() != 0;
}

void func_00147260(u64* p) {
    *p &= ~1;
}

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00147278);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00147300);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00147338);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_001473A8);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00147410);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_001474A0);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00147870);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00147730);

void func_00147760(s32 a) {
    func_00147808(a + 0x127);
}

u8* func_00147778(s32 i) {
    return D_00547BB0 + i * 2;
}

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00147790);

u8* func_00147A10(s32 i) {
    return D_00533BA0 + i;
}

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_001477E0);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00147808);

u8* func_00147A88(s32 i) {
    return D_00547BA0 + i * 20 - 20;
}

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00147860);

u8* func_00147AE8(s32 i) {
    i &= ~0x80;
    return D_00547BA8 + i * 12 - 12;
}

u8* func_001478C8(s32 i) {
    return D_00547BAC + i * 16;
}

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_001478E0);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00147A68);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00147B08);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00147BE0);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00147C30);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00147C98);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00147D18);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00147D50);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00147E08);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00147ED8);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00147F20);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00147F88);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00147FF0);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00148068);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_001480D0);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00148438);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_001484C8);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00148570);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00148600);

s32 func_001486B0(s32 a) {
    func_00148570(a);
    return a;
}

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_001486D8);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00148768);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_001487F8);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00148878);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00148908);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00148968);

s32 func_00148A40(u8* p, s32 b) {
    return func_00148968((s32)p, *(s32*)(p + 0x68), b);
}

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00148A60);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00148B70);

void func_00148B98(u8* p, s32 b, s32 c) {
    func_001487F8(*(s32*)(p + 0x68), b, (s32)p, c);
}

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00148BC0);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00148CB0);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00148D18);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00148D50);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00148DB0);

s32 func_00148DF8(void) {
    func_0011EF58(D_0054B808, 0);
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00148E20);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00148E60);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00148E98);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00148F08);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00148FB0);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00149090);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00149170);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_001495C8);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00149600);

void func_00149660(s32 a, u8* b) {
    func_00149170(a, *(s32*)(b + 4));
}

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00149678);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_001496C8);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00149740);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00149780);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_001497C8);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00149810);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00149860);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00149968);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_001499A0);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00149A88);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00149B40);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00149BD0);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00149E38);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00149E60);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_0014A070);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00149F10);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00149FA0);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_0014A058);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_0014A248);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_0014A0F0);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_0014A1B0);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_0014A238);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_0014A330);

void func_0014A380(s32 a, u8* b) {
    func_001412F8(a, *(s32*)(b + 0x30));
}

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_0014A398);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_0014A408);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_0014A450);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_0014A4A8);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_0014A898);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_0014A908);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_0014AA10);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_0014AA50);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_0014AAB0);

void func_0014AAF0(u64* p) {
    if (!((s32)(*p >> 8) & 1)) {
        *p |= 0x200000;
    }
}

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_0014AB18);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_0014AB48);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_0014AB78);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_0014AC00);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_0014AC50);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_0014ADE0);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_0014AF60);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_0014B090);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_0014B3E0);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_0014B550);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_0014B768);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_0014B958);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_0014B9E0);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_0014BBA8);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_0014BDC0);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_0014C130);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_0014C330);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_0014C378);

void func_0014C400(u8* p) {
    *(f32*)(*(u8**)(p + 0x148) + 0x100) = 46.0f;
    *(s32*)(p + 0x1CC) &= ~1;
}

void func_0014C428(u8* p) {
    *(f32*)(*(u8**)(p + 0x148) + 0x100) = 24.0f;
    *(s32*)(p + 0x1CC) |= 1;
}

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_0014C448);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_0014C4A8);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_0014C530);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_0014C580);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_0014C5C8);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_0014C6C0);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_0014C850);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_0014CA38);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_0014CB38);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_0014CB90);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_0014CC38);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_0014CC88);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_0014CCE0);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_0014CD38);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_0014CDC8);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_0014CEE8);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_0014D070);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_0014D180);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_0014D210);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_0014D330);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_0014D3C8);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_0014D428);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_0014D4F8);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_0014D570);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_0014D6B0);

s32 func_0014D760(u8* p, s32 a) {
    if (a == 0) {
        return 0;
    }
    return *(s32*)(p + 0x70);
}

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_0014D778);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_0014D7B8);

s32 func_0014D878(u8* p, s32 a) {
    if (a != 0) {
        return 2;
    }
    return *(s32*)(p + 0x70);
}

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_0014D890);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_0014D988);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_0014DAB8);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_0014DB20);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_0014DB78);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_0014DC08);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_0014DC90);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_0014DCD8);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_0014DD48);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_0014DF60);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_0014E160);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_0014E3A0);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_0014E400);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_0014E4B8);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_0014E510);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_0014E5B8);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_0014E668);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_0014E878);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_0014EAB0);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_0014EB60);

void func_0014EE50(s32 n) {
    s32* p = &D_0054F44C;
    *p &= ~(1 << (n - 1));
}

void func_0014EE78(s32 n) {
    s32* p = &D_0054F44C;
    *p |= 1 << (n - 1);
}

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_0014EC60);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_0014ED30);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_0014EE08);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_0014EE88);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_0014EFE0);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_0014F028);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_0014F1B8);

s32 func_0014F370(u8* p) {
    return *(s32*)(p + 0x6C) = func_00141A40(p);
}

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_0014F398);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_0014F3D0);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_0014F410);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_0014F5C8);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_0014F600);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_0014F658);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_0014F6F8);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_0014F748);

void func_0014F778(s32 a, f32* v) {
    sceVu0CopyVector(v, D_002C58A0);
}

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_0014F798);

s32 func_0014F828(u8* p) {
    return *(s32*)(p + 0x70);
}

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_0014F830);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_0014F868);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_0014F948);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_0014F9B0);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_0014FA38);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_0014FAB0);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_0014FC68);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_0014FE48);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_001501C0);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00150208);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_001502E8);

void func_00150660(void) {
    func_00137318();
}

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00150678);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_001507D0);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00150930);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00150AF0);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00150B70);

void func_00150BF8(s32 a) {
    func_00130398(a, 0xBF, 0.0f);
}

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00150C18);

s32 func_00150CB0(u8* p) {
    return *(s32*)(p + 0x70);
}

s32 func_00150CB8(void) {
    func_00150AF0();
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00150CD8);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00150D30);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00150D70);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00150DE0);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00150EC8);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00151010);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00151148);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00151208);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00151268);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_001515D0);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00151808);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00151860);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00151940);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_001519C0);

void func_00151B90(void) {
}

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00151B98);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00151CD0);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00151D20);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00151E28);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00151FA0);

void func_001520C0(u8* p) {
    *(f32*)(*(u8**)(p + 0x144) + 8) += D_002B8344;
}

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_001520E0);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00152140);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00152250);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00152370);

void func_001523E8(s32 a, f32* v) {
    sceVu0CopyVector(v, D_002C58A0);
}

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00152408);

void func_001524A8(void) {
}

void func_001524B0(void) {
    func_00137318();
}

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_001524C8);

void func_00152520(u8* a, u8* b) {
    *(u8**)(a + 0x98) = b;
    *(u8**)(b + 0x98) = a;
    *(s32*)a |= 0x200;
}

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00152538);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00152598);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_001525F0);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00152648);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00152688);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00152730);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00152770);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00152880);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_001528F0);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00152928);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00152BA8);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00152C28);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00152D50);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00152DC8);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00152E10);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00152F10);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00152FF8);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_001531C0);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00153210);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_001532C8);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00153300);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00153360);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_001533D0);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00153418);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00153500);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00153668);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_001538D8);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_001539C0);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00153B68);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00153BB0);

s32 func_00153C38(u8* p, s32 a) {
    if (a != 0) {
        return 2;
    }
    return *(s32*)(p + 0x70);
}

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00153C50);

s32 func_00153D08(s32 a) {
    func_00153C50(a, 0);
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00153D28);

s32 func_00153D78(u8* p) {
    return *(s32*)(p + 0x88) & 0x30;
}

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00153D88);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00153E80);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00153F88);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_001541A8);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00154258);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_001542F8);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_001543F8);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_001544A0);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00154548);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_001545F0);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_001546B8);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00154768);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00154880);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_001549B8);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00154AF8);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00154BE0);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00154C60);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00154D60);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00154E38);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_001550A0);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00155630);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_001556A8);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00155730);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00155760);

void func_001557B0(void) {
    func_00155760(func_001320A8());
}

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_001557D0);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00155878);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_001559A8);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00155ED8);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00155A50);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00155A90);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00155AD8);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00155B70);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_001560C8);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00155C68);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00155CF8);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00155D70);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00155E48);

void func_00155EE8(u8* p) {
    p[3]++;
}

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00155EF8);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_001560F8);

s32 func_00156188(void) {
    func_0011EF58(D_0054F970, 0);
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_001561B0);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_001561F8);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00156260);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_001562D0);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_001563E0);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_001564E0);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00156628);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00156B70);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00156BA0);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_001566D8);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00156768);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_001568E8);

void func_00156C18(s32 a) {
    D_00551600 = a;
}

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00157158);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00156C68);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00156D88);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00156E88);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00157090);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_001570D0);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_001571A8);

s32 func_001573D8(u8* p) {
    (*(void (**)(s32))(p + 0x48))(-1);
    return 4;
}

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00157400);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_001574B0);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_001574F0);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00157528);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00157560);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00157AD8);

void func_00157648(u8* p) {
    func_00157AD8(*(s8*)(*(u8**)(p + 0x6C) + 0xBD));
}

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00157B90);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_001576A8);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_001577A0);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00157818);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00157910);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00157978);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00157A00);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00157A30);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00157C60);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00157DC8);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00157EA8);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00157F70);

void func_00158050(u8* p) {
    *(f32*)(*(u8**)(p + 0x6C) + 0xCC) = 0.19634955f;
}

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00158068);

void func_001580E8(s32* p) {
    *p &= ~0x20;
}

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00158100);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_001581D8);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_001584C0);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00158648);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_001586A8);

u16 func_00158C30(s32 i) {
    return ((Seg3010F8*)D_003010F8)->unk_848[i];
}

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_001586F0);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00158780);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00158960);

void func_00158AD0(s32 a) {
    func_00131498(a, D_005516E8);
}

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00158AF0);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00158B88);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00158C78);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00158D30);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00158D70);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00158DB0);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00158DF8);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00158EC8);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_001590A8);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00159148);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00159178);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00159258);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00159350);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_001593F8);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00159440);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_001595A8);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00159740);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00159808);

s32 func_001598C8(u8* p, s32 a) {
    if (a == 0) {
        return 0x1E;
    }
    return *(s32*)(p + 0x70);
}

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_001598E0);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00159978);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00159B48);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00159C10);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00159CD8);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00159EA8);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00159F78);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_0015A258);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_0015A348);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_0015A3D8);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_0015A418);

s32 func_0015A470(u8* p, s32 b, s32 c) {
    if (c == -2) {
        func_00176310(*(s32*)(p + 0x144));
    }
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_0015A498);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_0015A520);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_0015A5B8);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_0015A758);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_0015A8F0);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_0015A990);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_0015AA30);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_0015AAC0);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_0015AB50);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_0015ABD0);

void func_0015AC30(u8* p) {
    *(f32*)(p + 0x3C0) = *(f32*)(p + 0x30) * 4.0f;
    *(f32*)(p + 0x3C8) = *(f32*)(p + 0x38) * 4.0f;
}

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_0015AC58);

s32 func_0015ACE0(u8* p, s32 b, s32 c) {
    if (c == -2) {
        func_00121EB0(*(s32*)(p + 0x144));
    }
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_0015AD08);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_0015AE48);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_0015B060);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_0015B098);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_0015B268);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_0015B438);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_0015B4A8);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_0015B550);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_0015B628);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_0015B6C0);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_0015B7E8);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_0015B8E0);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_0015B998);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_0015BAD0);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_0015BB88);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_0015BCB8);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_0015BD78);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_0015BEB0);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_0015BFF8);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_0015C128);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_0015C1F8);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_0015C3A0);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_0015C508);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_0015C5D0);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_0015C738);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_0015C960);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_0015C9F8);

f32 func_0015CA50(u8* p) {
    return D_00351B60[*(u16*)(*(u8**)(p + 0x130) + 0x4C)];
}

f32 func_0015CA70(u8* p) {
    return D_00351B88[*(u16*)(*(u8**)(p + 0x130) + 0x4C)];
}

void func_0015CA90(s32* p) {
    *p |= 0x200000;
}

void func_0015CAA8(s32* p) {
    *p &= ~0x200000;
}

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_0015CAC0);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_0015CB48);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_0015CC48);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_0015D1D0);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_0015D248);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_0015D2C8);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_0015D3B8);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_0015D4E0);

void func_0015D518(s32 a, f32* v) {
    sceVu0CopyVector(v, D_002C58A0);
}

s32 func_0015D538(u8* p) {
    return *(s32*)(p + 0x70);
}

s32 func_0015D540(void) {
    func_0015D1D0();
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_0015D560);

void func_0015D5C0(u8* p) {
    *(s32*)(p + 0x1CC) |= 2;
}

void func_0015D5D0(u8* p) {
    *(s32*)(p + 0x1CC) &= ~2;
}

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_0015D5E8);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_0015D6C8);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_0015D770);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_0015D7B8);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_0015D848);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_0015DA70);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_0015DAC0);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_0015DB80);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_0015DBF8);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_0015DC50);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_0015DCC8);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_0015DD50);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_0015DE88);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_0015DEF8);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_0015DFF8);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_0015E0A8);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_0015E128);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_0015E178);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_0015E438);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_0015E5C8);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_0015E7A8);

void func_0015E7F8(s32 a) {
    if (D_002E26A0 == a) {
        D_00551D74 = 30.0f;
    }
}

void func_0015E820(u8* p) {
    sceVu0CopyVectorXYZ((f32*)(p + 0x3C0), (f32*)(p + 0x30));
}

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_0015E840);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_0015E8D8);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_0015E9C8);

s32 func_0015EA38(u8* p) {
    return *(s32*)(p + 0x70);
}

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_0015EA40);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_0015EA98);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_0015EB78);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00122110);

void func_0015ED80(s32 a, s32 b) {
    func_0011EEB8(D_00559DB0, a, b);
}

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_0015EDA8);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_0015EE10);

void func_0015EE78(s32 a, s32 b) {
    func_0011EEB8(D_0055BDE0, a, b);
}

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_0015EEA0);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00122250);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_0015EFC0);

void func_0015F010(void) {
}

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_0015F018);

void func_001601A8(void) {
    func_0022F578(6);
    func_00215A88();
}

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_0015F128);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_0015F388);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_0015F488);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_0015F798);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_0015F8C8);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_0015FA20);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_0015FC00);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_0015FD20);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_0015FF78);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00160370);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_001606D0);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_001617C0);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00161A08);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00161DE8);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00161F80);

void func_00162058(s32 a) {
    func_00161A08(a);
}

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00162070);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00162110);

void func_001621E0(s32 a, s32 b, s32 c) {
    func_001606D0(a, b, c);
}

void func_001621F8(u8* p) {
    if (p != NULL) {
        *(u64*)(p + 0x48) |= 0x20000;
    }
}

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00162218);

s32 func_00162338(s16*** p) {
    return ***p;
}

s32 func_00162348(u8*** p, s32 i) {
    return ((s32*)(*(u8**)(**p + 8) + 0x10))[i];
}

s32 func_00162368(u8*** p, s32 i) {
    return *(s32*)(*(u8**)(**p + 4) + i * 48 + 0x2C) & 0x3FF;
}

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00162390);

void func_001623D0(u8* p, s32* out) {
    *out = *(s32*)(p + 0x30);
}

s32 func_001623E0(u8* p) {
    return *(s32*)(p + 0x154);
}

u32 func_001623E8(u8* p) {
    return *(u32*)(p + 0xC) >> 4;
}

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_001623F8);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00162428);

void func_001624F8(void) {
}

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00162500);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_001625C8);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_001626F0);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_001627D0);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_001627E8);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00162808);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00162818);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00162848);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00162878);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_001628A0);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00162950);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00162978);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_001629B0);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_001629E8);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00162A58);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00162A88);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00162AB8);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00162C20);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00162C5C);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00162CD0);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00162D00);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00163150);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00163490);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_001636D0);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00164768);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00164BA8);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00164E00);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00164F18);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00165450);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_001655E0);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00165CF8);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00166248);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00166570);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_001675C0);

s32 func_00167678(u8* p) {
    return *(s32*)(p + 0xC);
}

s32 func_00167680(u8* p) {
    return *(s32*)(p + 0xC);
}

void func_00167688(u8* p, s32 a, s32 b) {
    *(s32*)(p + 0xC) = a;
    *(s32*)(p + 0x88) = b;
}

s32 func_00167698(s32* p) {
    if (p == NULL) {
        return 0;
    }
    return p[1];
}

void func_001676B0(u8* p, f32* out) {
    out[0] = *(f32*)(p + 0x90);
    out[1] = *(f32*)(p + 0x94);
    out[2] = *(f32*)(p + 0x98);
    out[3] = *(f32*)(p + 0x9C);
}

void func_001676D8(u8* p, f32* v) {
    sceVu0CopyVector(v, (f32*)(p + 0xC0));
}

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_001676F8);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_001677E0);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00167840);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00167978);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00167AC0);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00167C40);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00167D70);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00167F68);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00167FD0);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_001680D8);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_001681B8);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00168318);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_001683B0);

void func_001684E0(s32 a) {
    func_001681B8(a, 0x41584554);
}

void func_00168500(void) {
    func_0016F640();
}

void func_00168518(void) {
    func_00170E98();
}

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00168530);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00168618);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_001687D8);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_001689D0);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00168B30);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00168D20);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00169008);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00169210);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_001693C8);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00169510);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00169688);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00169F28);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_0016A3F8);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_0016ABC0);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_0016B1F0);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_0016B670);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_0016BB68);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_0016BFE8);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_0016C480);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_0016C650);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_0016CB98);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_0016CE10);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_0016D040);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_0016D2D0);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_0016D768);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_0016DB80);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_0016DD30);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_0016DF30);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_0016E0D0);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_0016E1F0);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_0016E3F8);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_0016EA58);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_0016F1F0);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_0016F3D0);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_0016F548);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_0016F640);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_0016F7B8);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_0016F8B8);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_0016FA10);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_0016FC60);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_0016FD98);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00170170);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00170400);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_001705C0);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_001707D0);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00170D60);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00170DD8);

s32 func_00170E30(s32 a) {
    s32* p = &D_00574FB4;
    s32 old = *p;
    *p = a;
    return old;
}

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00170E48);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00170E98);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00170F08);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00170F50);

s32 func_00170F90(u8* a, u8* b) {
    return *(s32*)(b + 0x4C) == *(s32*)(a + 0x164);
}

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00170FA8);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00171078);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00171098);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_001710D8);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00171118);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_001711D0);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00171320);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_001713F8);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00171460);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00171498);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_001714F0);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_001715B0);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00171680);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00171790);

s32 func_00171890(s32 a, u8* p, s32 n) {
    switch (n) {
    case 0:
    case 1:
    case 2:
        return 1;
    }
    return n == *(s32*)(p + 0x4C);
}

s32 func_001718B8(s32 a, u8* p, s32 n) {
    switch (n) {
    case 0x75:
    case 0x76:
    case 0x77:
    case 0x78:
    case 0x79:
    case 0x7A:
    case 0x7B:
        return 1;
    }
    return n == *(s32*)(p + 0x4C);
}

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_001718E0);

s32 func_00171920(s32 a, u8* p, s32 n) {
    switch (n) {
    case 0x2D:
    case 0x2E:
    case 0x2F:
    case 0x30:
        return 1;
    }
    return n == *(s32*)(p + 0x4C);
}

s32 func_00171948(s32 a, u8* p, s32 n) {
    switch (n) {
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
    case 8:
    case 9:
    case 0xA:
    case 0xB:
    case 0xC:
        return 1;
    }
    return n == *(s32*)(p + 0x4C);
}

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00171970);

s32 func_00171A88(s32 a, s32 b, s32 n) {
    return ((u32)D_00575788[n >> 3] >> (n & 7)) & 1;
}

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00171AA8);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00171AE8);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00171B18);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00171B80);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00171C80);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00171D80);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00171E50);

void func_00171E90(s32 a, u8* p) {
    *(u64*)(p + 0x38) |= 0x10;
}

void func_00171EA8(s32 a, u8* p) {
    *(u64*)(p + 0x38) &= ~0x10;
}

void func_00171EC0(s32 a, u8* p) {
    *(u64*)(p + 0x38) |= 0x20;
}

void func_00171ED8(s32 a, u8* p) {
    *(u64*)(p + 0x38) &= ~0x20;
}

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00171EF0);

s32 func_00171F30(void) {
    return 0;
}

void func_00171F38(s32 a, s32* p) {
    if (p != NULL && *p == a) {
        *p = 0;
    }
}

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00171F58);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00171FA0);

void func_00172010(s32 a, u8* p) {
    *(s32*)(p + 0x18) = 0xF;
    *(s32**)(p + 0x1C) = D_0035BD50;
}

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00172028);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00172118);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_001722E8);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_001724B8);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00172690);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00172810);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00172998);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00172BC8);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00172D90);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00172DF8);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00172F00);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00173008);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_001730F0);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_001731F8);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_001732B0);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00173360);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00173478);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_001734F8);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00173610);

s32 func_00173718(u8* p) {
    s32 v = *(s32*)(p + 0x164);
    if (v == 0x3F || v == 0x8C) {
        return 1;
    }
    return 0;
}

void func_00173740(s32 a, u8* p) {
    *(s32*)(p + 0x18) = 0xC;
    *(s32**)(p + 0x1C) = D_0035BFC0;
}

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00173758);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00173860);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00173968);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00173A20);

void func_00173AD8(s32 a, u8* p) {
    *(s32*)(p + 0x18) = 0xA;
    *(s32**)(p + 0x1C) = D_0035C090;
}

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00173AF0);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00173BF8);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00173D00);

void func_00173EA8(s32 a, u8* p) {
    *(s32*)(p + 0x18) = 0xA;
    *(s32**)(p + 0x1C) = D_0035C140;
}

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00173EC0);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00173F78);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00174030);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_001740E8);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_001741A0);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_001742B0);

void func_00174398(s32 a, u8* p) {
    *(s32*)(p + 0x18) = 0xC;
    *(s32**)(p + 0x1C) = D_0035C1F0;
}

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_001743B0);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_001744B8);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00174570);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00174628);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_001746E0);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00174798);

void func_00174950(s32 a, u8* p) {
    *(s32*)(p + 0x18) = 9;
    *(s32**)(p + 0x1C) = D_0035C2C0;
}

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00174968);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00174A20);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00174AD8);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00174B90);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00174CA8);

void func_00174D98(s32 a, u8* p) {
    *(s32*)(p + 0x18) = 0xB;
    *(s32**)(p + 0x1C) = D_0035C360;
}

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00174DB0);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00174EB8);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00174FC0);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_001752A0);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00175600);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00175708);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00175820);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00176E30);

void func_00176E98(void) {
    func_00176EA8();
    func_0011ED30(0x4E21, func_00176EE0);
}

void func_001759A8(void) {
    func_00175A98();
}

void func_001759C0(void) {
    memset(D_0035E710, 0, 0x1410);
}

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_001759E8);

void func_00175A20(void) {
    memset(D_0035C710, 0, 0x2000);
}

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00175A48);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00175A98);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00175AF0);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00175B70);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00175BA0);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00175BE0);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00175D60);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00175DA8);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00175E38);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00175E80);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00175EC8);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00175F10);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00175F58);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00175F98);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00175FD0);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00176008);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00176040);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00176078);

void func_001760B0(s32 a) {
    func_00175D60(D_0035E710, a);
}

void func_001760D0(s32 a) {
    func_00175D60(D_0035FB20, a);
}

void func_001760F0(s32 a) {
    func_00175D60(D_00360F30, a);
}

void func_00176110(s32 a) {
    func_00175DA8(D_0035E710, a);
}

void func_00176130(s32 a) {
    func_00175DA8(D_0035FB20, a);
}

void func_00176150(s32 a) {
    func_00175DA8(D_00360F30, a);
}

void func_00177688(void) {
    func_00175E38(D_0035E710);
    func_001759C0();
}

void func_00176190(void) {
    func_00175E38(D_0035FB20);
    func_001759E8();
}

void func_001776C8(void) {
    func_00175E38(D_00360F30);
    func_001759E8();
}

void func_001761D0(void) {
    func_00175E80(D_0035FB20);
}

void func_00177708(void) {
    func_00175EC8(D_0035E710);
}

void func_00176210(void) {
    func_00175EC8(D_0035FB20);
}

void func_00177748(void) {
    func_00175EC8(D_00360F30);
}

void func_00177768(void) {
    func_00175F10(D_0035E710);
}

void func_00176270(void) {
    func_00175F10(D_0035FB20);
}

void func_001777A8(void) {
    func_00175F10(D_00360F30);
}

void func_001762B0(u_long128* primPacketArea, s32 len) {
    pppSetPrimPacket(primPacketArea, len);
}

void func_001762C8(void) {
    func_00181040();
}

void func_001762E0(void) {
    func_001810D0();
}

void func_001762F8(void) {
    func_00181110();
}

void func_00176310(s32 a) {
    func_00181200(a);
}

void func_00176328(void) {
    func_001812B0();
}

void func_00176340(void) {
    func_00181340();
}

void func_00176358(void) {
    func_001813F0();
}

void func_00176370(void) {
    func_001814C8();
}

void func_001778A0(s32 a) {
    func_001815A0(a);
}

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_001763A0);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00177908);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00176488);

s32 func_00176528(u8* p) {
    return *(s32*)(p + 0xC);
}

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00176530);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00176578);

s32 func_001765F8(s32 arg0) {
    return func_00181600(arg0);
}

u16 func_00176610(u8* p) {
    return *(u16*)(*(u8**)(*(u8**)(p + 0x2C) + 0x8C) + 0xFC);
}

s32 func_00176620(u8* p) {
    return *(s32*)(*(u8**)(p + 0x2C) + 0xA8);
}

s32 func_00176630(u8* p) {
    return *(s32*)(*(u8**)(p + 0x2C) + 0x8C);
}

void func_00176640(s32* arg0) {
    func_00181BA8(arg0);
}

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00176658);

void func_00176838(void) {
    func_001838E8();
}

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00177D68);

void func_00176898(void) {
}

void func_001768A0(void) {
}

void func_001768A8(void) {
}

void func_001768B0(void) {
}

void func_001768B8(void) {
}

void func_001768C0(void) {
}

void func_001768C8(u8** p) {
    if (*p != NULL) {
        **(u8**)(*p + 0x10) = 1;
    }
    *p = NULL;
}

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_001768E8);

void func_00176920(f32** p) {
    sceVu0CopyVector(p[1], *(f32**)p[0]);
}

void func_00176940(f32** p) {
    sceVu0CopyVector(p[1], ((f32**)p[0])[2]);
}

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00176960);

void func_001769F0(f32** p) {
    sceVu0OuterProduct(p[0], p[0], p[1]);
}

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00176A18);

void func_00176A60(f32** p) {
    sceVu0CopyVector(*p, D_002DECE0);
}

void func_00176A80(f32** p) {
    sceVu0CopyVector(*p, D_002DECF0);
}

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00176AA0);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00176AF0);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00176B20);

void func_00176B50(s32* p) {
    func_00108180(*p);
}

void func_00176B68(s32* p) {
    func_001081A0(*p);
}

void func_00176B80(u8** p) {
    u8* q = *p;
    *(s32*)(*(u8**)(q + 0x6C) + 0x3C) = 1;
    *(s32*)(*(u8**)(q + 0x6C) + 0x44) = 0;
    *(s16*)(*(u8**)(q + 0x6C) + 0xBE) = 0;
}

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00176BA8);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00178140);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00176CC8);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00176EA8);

s32 func_00176EE0(void) {
    func_00176CC8(0);
    func_00176CC8(1);
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00176F08);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00177070);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_001770B8);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00177168);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00177218);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00177258);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00177288);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_001772C8);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_001772F8);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00177358);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_001773B0);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00177440);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00177488);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00177608);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00177680);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00177740);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00177900);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_001779E8);

void func_00177A98(void) {
    memset(D_005758F0, 0, 0x10);
}

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00177AC0);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00177EF8);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00178468);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_001784B0);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_001784C8);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00178890);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00178A98);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00178D90);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00178E10);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00178EF8);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00179690);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00179700);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00179A80);

void func_00179D08(void) {
    memset(D_00575920, 0, 0x20);
}

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00179D30);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00179EE8);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_0017A510);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_0017A6C0);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_0017A7B0);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_0017A958);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_0017ADF8);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_0017AE48);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_0017B0E0);

void func_0017B120(void) {
    memset(D_00362690, 0, 0x30);
}

void func_0017B148(void) {
    memset(D_003626C0, 0, 0x30);
}

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_0017B170);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_0017B200);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_0017B250);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_0017B308);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_0017B4F8);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_0017B668);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_0017B740);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_0017B7E8);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_0017B860);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_0017BA80);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_0017BC90);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_0017BFE8);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_0017C110);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_0017C190);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_0017C4C8);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_0017C550);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_0017C7F0);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_0017C8E8);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_0017C9A8);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_0017CB88);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_0017CF08);

void func_0017D1E0(void) {
    if (!(*(s32*)(D_00362438 + 0x18) & 0x10)) {
        D_003626B0 = 1;
    }
}

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_0017D208);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_0017D238);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_0017D570);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_0017D5A0);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_0017D5D0);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_0017D628);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_0017D9C8);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_0017DB68);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_0017DBB8);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_0017DC40);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_0017DD00);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_0017DE80);

void func_0017DEE0(void) {
    memset(D_005759B0, 0, 0x50);
}

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_0017DF08);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_0017E170);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_0017E428);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_0017FED8);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_0017E7D8);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_0017E840);

void func_0017E8A0(void) {
    memset(D_003626F0, 0, 8);
}

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00180038);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00180080);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_0017EAA0);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_0017EB20);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_0017EB88);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_0017EBD0);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_0017EC00);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_0017ECF8);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_0017EF40);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_0017EFF8);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_001807B0);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_00180848);

void func_0017F150(void) {
    sceVu0CopyVector(D_00362660, D_00362410);
    func_0017F178();
}

void func_0017F178(void) {
    D_00362680[0] = D_00362660[0];
    D_00362680[3] = D_00362660[3];
}

void func_0017F1A0(void) {
    sceVu0CopyVector(D_00362670, D_00362400);
}

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_0017F1C8);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_001809C8);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_0017F440);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_0017F510);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_0017F580);

void func_00180CE0(void) {
    D_00362710 = 0;
}

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_0017F688);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_03BDE8", func_0017F8E0);
