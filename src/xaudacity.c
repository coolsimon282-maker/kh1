#include "common.h"
#include "math.h"

extern s32 D_002979E8;
extern f32 D_002B8344[];
extern f32 D_002B8348;

extern s32 D_002DF430;
extern s32 D_002DF43C;

extern f32 func_00120AC8(f32);
extern f32 func_00177D68(void);
extern s32 func_00147A10(s32);

typedef struct XAud6C {
    /* 0x00 */ char unk_00[0xBD];
    /* 0xBD */ u8 unk_BD;
    /* 0xBE */ char unk_BE[0xE];
    /* 0xCC */ f32 unk_CC;
} XAud6C;

typedef struct XAud130 {
    /* 0x00 */ char unk_00[0x18];
    /* 0x18 */ f32 unk_18;
    /* 0x1C */ char unk_1C[0x30];
    /* 0x4C */ u16 unk_4C;
    /* 0x4E */ u16 unk_4E;
    /* 0x50 */ char unk_50[0x8];
    /* 0x58 */ u8 unk_58;
    /* 0x59 */ u8 unk_59;
    /* 0x5A */ u8 unk_5A;
} XAud130;

typedef struct XAud14C_18 {
    /* 0x00 */ char unk_00[0x24];
    /* 0x24 */ f32 unk_24;
} XAud14C_18;

typedef struct XAud14C {
    /* 0x00 */ char unk_00[0x18];
    /* 0x18 */ XAud14C_18* unk_18;
} XAud14C;

typedef struct XAud398 {
    /* 0x00 */ s32 unk_00;
    /* 0x04 */ s32 unk_04;
} XAud398;

typedef struct XAud370Bits {
    u64 unk_00 : 35;
    u64 unk_35 : 1;
    u64 unk_36 : 1;
    u64 unk_37 : 2;
    u64 unk_39 : 12;
    u64 unk_51 : 1;
    u64 unk_52 : 1;
    u64 unk_53 : 1;
    u64 unk_54 : 1;
    u64 unk_55 : 9;
} XAud370Bits;

typedef union XAud370 {
    u64 raw;
    XAud370Bits b;
} XAud370;

typedef struct XAudObj {
    /* 0x000 */ char unk_000[0x10];
    /* 0x010 */ f32 unk_010[4];
    /* 0x020 */ char unk_020[0xC];
    /* 0x02C */ struct XAudObj* unk_02C;
    /* 0x030 */ char unk_030[0x3C];
    /* 0x06C */ XAud6C* unk_06C;
    /* 0x070 */ char unk_070[0x18];
    /* 0x088 */ s32 unk_088;
    /* 0x08C */ char unk_08C[0x94];
    /* 0x120 */ f32 unk_120[4];
    /* 0x130 */ XAud130* unk_130;
    /* 0x134 */ char unk_134[0x18];
    /* 0x14C */ XAud14C* unk_14C;
    /* 0x150 */ f32 unk_150;
    /* 0x154 */ char unk_154[0x10];
    /* 0x164 */ s32 unk_164;
    /* 0x168 */ char unk_168[0x10];
    /* 0x178 */ s32 unk_178;
    /* 0x17C */ char unk_17C[0x50];
    /* 0x1CC */ s32 unk_1CC;
    /* 0x1D0 */ char unk_1D0[0xC];
    /* 0x1DC */ s32* unk_1DC;
    /* 0x1E0 */ char unk_1E0[0xA4];
    /* 0x284 */ f32 unk_284;
    /* 0x288 */ char unk_288[0xE8];
    /* 0x370 */ XAud370 unk_370;
    /* 0x378 */ char unk_378[0x20];
    /* 0x398 */ XAud398* unk_398;
    /* 0x39C */ char unk_39C[0x2];
    /* 0x39E */ u8 unk_39E;
    /* 0x39F */ char unk_39F[0x5];
    /* 0x3A4 */ s32 unk_3A4;
    /* 0x3A8 */ s32 unk_3A8;
    /* 0x3AC */ s32 unk_3AC;
    /* 0x3B0 */ char unk_3B0[0x10];
    /* 0x3C0 */ f32 unk_3C0[4];
    /* 0x3D0 */ s32 unk_3D0;
    /* 0x3D4 */ f32 unk_3D4;
    /* 0x3D8 */ char unk_3D8[0xC];
    /* 0x3E4 */ s32 unk_3E4;
    /* 0x3E8 */ char unk_3E8[0xA8];
    /* 0x490 */ f32 unk_490[4];
} XAudObj;

// arg0[0] seen as a block of pointers
typedef struct XAudPtrs {
    /* 0x00 */ void* unk_00;
    /* 0x04 */ void* unk_04;
    /* 0x08 */ void* unk_08;
} XAudPtrs;

// arg0[0] seen as a u64 of flags
typedef struct XAudFlags0 {
    u64 unk_00 : 2;
    u64 unk_02 : 2;
    u64 unk_04 : 7;
    u64 unk_0B : 1;
    u64 unk_0C : 2;
} XAudFlags0;

// arg0[1] with a u64 of flags at 0x8
typedef struct XAudB8 {
    /* 0x00 */ u64 unk_00;
    /* 0x08 */ u64 unk_08 : 43;
    u64 unk_43 : 1;
} XAudB8;

typedef union XAudArg {
    s32 s;
    u32 u;
    f32 f;
    void* p;
    XAudObj* obj;
    XAudPtrs* ptrs;
    XAudFlags0* flags;
    XAudB8* b8;
} XAudArg;

INCLUDE_ASM("asm/nonmatchings/xaudacity", func_00128E28);
// void func_00128E28(f32* arg0) {
//     f32 x = func_00120AC8((*arg0 / 180.0f) * PI);
//     *arg0 = sinf(x);
// }

INCLUDE_ASM("asm/nonmatchings/xaudacity", func_00128E80);
// void func_00128E80(f32* arg0) {
//     f32 x = func_00120AC8((*arg0 / 180.0f) * PI);
//     *arg0 = cosf(x);
// }

void func_00128ED8(f32* arg0) {
    *arg0 = func_00177D68();
}

void func_00128F00(f32* arg0) {
    *arg0 = D_002B8344[0];
}

void func_00128F10(s32* arg0) {
    *arg0 = func_00147A10(*arg0);
}

void func_00128F40(void) {
}

void func_00128F48(void) {
}

void func_00128F50(void) {
}

INCLUDE_ASM("asm/nonmatchings/xaudacity", func_00128F58);
// void func_00128F58(f32* arg0) {
//     *arg0 = func_00120AC8((*arg0 / 180.0f) * PI);
// }

void func_00128FA8(f32* arg0) {
    D_002B8348 = *arg0;
}

#ifdef VERSION_FM
extern u32 D_002BBDE4;

void fm_func_00128F70(XAudArg* arg0) {
    arg0[0].s = D_002BBDE4 >= 2 && D_002BBDE4 != 7;
}
#endif

#ifdef VERSION_FM
extern u32 D_002C1EA8;
void fm_func_00128F98(XAudArg* arg0) {
    arg0[0].s = (D_002C1EA8 >> 13) & 1;
}
#endif

#ifdef VERSION_FM
extern s32 D_00301088;
void fm_func_00128FB0(XAudArg* arg0) {
    arg0[0].s = D_00301088 & 7;
}
#endif

f32 func_00120A38(s32);

void func_00128FB8(XAudArg* arg0) {
    arg0[0].f = func_00120A38(arg0[0].s);
}

void func_00128FE8(f32** arg0) {
    sceVu0AddVector(arg0[0], arg0[0], arg0[1]);
}

void func_00129010(f32** arg0) {
    sceVu0SubVector(arg0[0], arg0[0], arg0[1]);
}

void func_00129038(f32** arg0) {
    func_001223B0(arg0[0], arg0[0]);
}

INCLUDE_ASM("asm/nonmatchings/xaudacity", func_00129058);

INCLUDE_ASM("asm/nonmatchings/xaudacity", func_001290C8);

INCLUDE_ASM("asm/nonmatchings/xaudacity", func_00129138);

INCLUDE_ASM("asm/nonmatchings/xaudacity", func_00129188);

void sceVu0ScaleVectorXYZ(f32*, f32*, f32);

void func_001291D8(XAudArg* arg0) {
    sceVu0ScaleVectorXYZ(arg0[0].p, arg0[0].p, arg0[1].f);
}

f32 func_001215A8(s32, s32);

void func_00129200(XAudArg* arg0) {
    arg0[0].f = func_001215A8(arg0[0].s, arg0[1].s);
}

void func_0014E668(s32, f32, f32, s32, s32);

void func_00129230(XAudArg* arg0) {
    func_0014E668(arg0[0].s, arg0[1].f, arg0[2].f, 0, arg0[3].s);
}

INCLUDE_ASM("asm/nonmatchings/xaudacity", func_00129260);

#ifdef VERSION_FM
void fm_func_00129330(void) {
}
#endif

#ifdef VERSION_FM
void func_00129320(void);
INCLUDE_ASM("asm/nonmatchings/xaudacity", func_00129320);
#else
void func_00129320(void) {
}
#endif

s32 func_00123880(s32);

void func_00129328(XAudArg* arg0) {
    arg0[0].s = func_00123880(arg0[0].s);
}

void func_00137688(XAudObj*, f32);

void func_00129358(XAudArg* arg0) {
    f32* v = arg0[1].p;
    XAudObj* obj = arg0[0].obj;
    f32 a = atan2f(v[0], v[2]);
    obj->unk_150 = a;
    func_00137688(obj, a);
}

void func_00130398(s32, s32, f32);

void func_00129398(XAudArg* arg0) {
    func_00130398(arg0[0].s, arg0[1].s, arg0[2].f);
}

f32* func_00130340(s32, s32, f32);

void func_001293C0(XAudArg* arg0) {
    func_00130340(arg0[0].s, arg0[1].s, arg0[2].f)[1] = arg0[3].f;
}

f32* func_00130578(s32, s32, f32);

void func_001293F8(XAudArg* arg0) {
    func_00130578(arg0[0].s, arg0[1].s, arg0[2].f)[1] = arg0[3].f;
}

void func_001315C0(s32, s32, f32, s32);

void func_00129430(XAudArg* arg0) {
    func_001315C0(arg0[0].s, arg0[1].s, arg0[2].f, arg0[3].s);
}

f32 func_00142CF0(s32, s32, f32, f32);

void func_00129458(XAudArg* arg0) {
    arg0[0].f = func_00142CF0(arg0[0].s, arg0[1].s, arg0[2].f, arg0[3].f);
}

s32 func_001234A0(s32);

void func_00129490(XAudArg* arg0) {
    arg0[0].s = func_001234A0(arg0[0].s);
}

void func_0012EC88(void*, s32);

void func_001294C0(XAudArg* arg0) {
    func_0012EC88(arg0[0].p, arg0[1].s);
}

INCLUDE_ASM("asm/nonmatchings/xaudacity", func_001294E0);

void sceVu0CopyVector(f32*, f32*);

void func_00129500(XAudArg* arg0) {
    f32 v[4] __attribute__((aligned(16)));
    XAudObj* obj = arg0[0].obj;
    sceVu0CopyVector(v, arg0[1].p);
    obj->unk_150 = atan2f(v[0], v[2]);
}

s32 func_001245F0(s32);

void func_00129540(XAudArg* arg0) {
    arg0[0].s = func_001245F0(arg0[0].s);
}

f32 func_00142E30(s32, s32, s32);

void func_00129570(XAudArg* arg0) {
    arg0[0].f = func_00142E30(arg0[0].s, arg0[1].s, arg0[2].s);
}

f32 func_00131A68(s32, s32);

void func_001295A8(XAudArg* arg0) {
    arg0[0].f = func_00131A68(arg0[0].s, arg0[1].s);
}

s32 func_001349D0(s32, s32);

void func_001295D8(XAudArg* arg0) {
    arg0[0].s = func_001349D0(arg0[0].s, arg0[1].s);
}

void func_0014A380(s32, s32);

void func_00129608(XAudArg* arg0) {
    func_0014A380(arg0[0].s, arg0[1].s);
    arg0[0].s = 0;
}

void func_00138A20(s32, f32, s32);

void func_00129638(XAudArg* arg0) {
    func_00138A20(arg0[0].s, arg0[1].f, arg0[2].s);
}

s32 func_001233F8(s32);

void func_00129660(XAudArg* arg0) {
    if (func_001233F8(arg0[0].s) != 0) {
        arg0[0].s = arg0[0].obj->unk_164;
    } else {
        arg0[0].s = 0xFFF;
    }
}

void func_001296A8(void) {
}

void func_00131C28(void*, f32);

void func_001296B0(XAudArg* arg0) {
    func_00131C28(arg0[0].p, arg0[1].f);
}

s32 func_00123558(s32, s32);

void func_001296D0(XAudArg* arg0) {
    arg0[0].s = func_00123558(arg0[0].s, arg0[1].s);
}

void func_00129700(XAudArg* arg0) {
    arg0[0].f = arg0[0].obj->unk_14C->unk_18->unk_24;
}

s32 func_00148A40(s32, s32);

void func_00129718(XAudArg* arg0) {
    arg0[0].s = func_00148A40(arg0[0].s, arg0[1].s);
}

s32 func_0012EF30(s32, s32, s32, f32);

void func_00129748(XAudArg* arg0) {
    arg0[0].s = func_0012EF30(arg0[0].s, arg0[1].s, arg0[2].s, arg0[3].f);
}

void func_0014D428(s32, s32, f32, f32);

void func_00129780(XAudArg* arg0) {
    func_0014D428(arg0[0].s, arg0[1].s, arg0[2].f, arg0[3].f);
}

void func_001297A8(XAudArg* arg0) {
    arg0[0].obj->unk_3D0 = arg0[1].s - 3;
}

s32 func_0014EFE0(s32, s32);

void func_001297C0(XAudArg* arg0) {
    arg0[0].s = func_0014EFE0(arg0[0].s, arg0[1].s);
}

s32 func_0014EE88(s32);

void func_001297F0(XAudArg* arg0) {
    arg0[0].s = func_0014EE88(arg0[0].s);
}

void func_00123E48(void*, s32);

void func_00129820(XAudArg* arg0) {
    func_00123E48(arg0[0].ptrs->unk_04, arg0[1].s);
}

void func_00129840(void) {
}

void func_0014F658(void*, s32);

void func_00129848(XAudArg* arg0) {
    func_0014F658(arg0[0].p, arg0[1].s);
}

void func_00129868(XAudArg* arg0) {
    arg0[0].f = arg0[0].obj->unk_3D4;
}

s32 func_00142B30(s32, s32);

void func_00129878(XAudArg* arg0) {
    arg0[0].s = func_00142B30(arg0[0].s, arg0[1].s);
}

s32 func_00142C80(s32, s32);

void func_001298A8(XAudArg* arg0) {
    arg0[0].s = func_00142C80(arg0[0].s, arg0[1].s);
}

void func_001298D8(XAudArg* arg0) {
    arg0[0].obj->unk_370.b.unk_37 = arg0[1].u;
}

void func_00135978(s32, s32, s32);

void func_00129910(XAudArg* arg0) {
    func_00135978(arg0[0].s, arg0[1].s, arg0[2].s);
}

void func_001359C0(s32, s32, s32);

void func_00129938(XAudArg* arg0) {
    func_001359C0(arg0[0].s, arg0[1].s, arg0[2].s);
}

INCLUDE_ASM("asm/nonmatchings/xaudacity", func_00129960);

s32 func_00148B70(s32, s32, s32, f32);

void func_001299B8(XAudArg* arg0) {
    arg0[0].s = func_00148B70(arg0[0].s, arg0[1].s, arg0[2].s, arg0[3].f);
}

void func_00148D18(s32, s32, f32);

void func_001299F0(XAudArg* arg0) {
    func_00148D18(arg0[0].s, arg0[1].s, arg0[2].f);
}

void func_00148D50(s32, s32, s32, f32, f32);

void func_00129A18(XAudArg* arg0) {
    func_00148D50(arg0[0].s, arg0[1].s, arg0[2].s, arg0[3].f, arg0[4].f);
}

s32 func_00148B98(s32, s32, s32);

void func_00129A48(XAudArg* arg0) {
    arg0[0].s = func_00148B98(arg0[0].s, arg0[1].s, arg0[2].s | 0x1000);
}

void func_00148DB0(s32, s32, s32, f32);

void func_00129A80(XAudArg* arg0) {
    func_00148DB0(arg0[0].s, arg0[1].s, arg0[2].s | 0x1000, arg0[3].f);
}

void func_00129AB0(XAudArg* arg0) {
    arg0[0].obj->unk_1CC |= arg0[1].s;
}

void func_00129AC8(XAudArg* arg0) {
    arg0[0].obj->unk_1CC &= ~arg0[1].s;
}

void func_00131498(XAudObj*, void*);

void func_00129AE8(XAudArg* arg0) {
    s32* tbl = arg0[0].obj->unk_1DC;
    XAudObj* obj = arg0[1].obj;
    func_00131498(obj, (u8*)tbl + tbl[obj->unk_130->unk_4C + 1]);
}

void func_00129B28(XAudArg* arg0) {
    arg0[0].s = arg0[0].obj->unk_130->unk_4C;
}

INCLUDE_ASM("asm/nonmatchings/xaudacity", func_00129B40);

void func_00129B88(XAudArg* arg0) {
    XAudObj* obj = arg0[0].obj;
    obj->unk_3A4 |= arg0[1].s;
    obj->unk_3A8 |= arg0[2].s;
    obj->unk_3AC |= arg0[3].s;
}

void func_00129BC0(XAudArg* arg0) {
    XAudObj* obj = arg0[0].obj;
    obj->unk_3A4 &= ~arg0[1].s;
    obj->unk_3A8 &= ~arg0[2].s;
    obj->unk_3AC &= ~arg0[3].s;
}

void func_00129C08(XAudArg* arg0) {
    sceVu0SubVector(arg0[1].p, arg0[0].obj->unk_010, arg0[0].obj->unk_490);
}

void func_0012EC60(s32, s32, s32);

void func_00129C30(XAudArg* arg0) {
    func_0012EC60(arg0[0].s, arg0[1].s, arg0[2].s);
}

s32 func_001233F8(s32);

void func_00129C58(XAudArg* arg0) {
    arg0[0].s = func_001233F8(arg0[0].s);
}

void func_0014F948(void*, s32);

void func_00129C88(XAudArg* arg0) {
    func_0014F948(arg0[0].p, arg0[1].s);
}

void func_00129CA8(XAudArg* arg0) {
    arg0[0].obj->unk_130->unk_18 = arg0[1].f;
}

INCLUDE_ASM("asm/nonmatchings/xaudacity", func_00129CC0);

void func_001358B8(void*, s32);

void func_00129CF8(XAudArg* arg0) {
    func_001358B8(arg0[0].p, arg0[1].s);
}

void func_001358F8(void*, s32);

void func_00129D18(XAudArg* arg0) {
    func_001358F8(arg0[0].p, arg0[1].s);
}

void func_00129D38(XAudArg* arg0) {
    arg0[0].obj->unk_370.raw |= 0x8000000000000;
}

void func_00129D58(XAudArg* arg0) {
    arg0[0].s = arg0[0].obj->unk_130->unk_5A;
}

void func_00131A30(s32, s32, s32);

void func_00129D70(XAudArg* arg0) {
    func_00131A30(arg0[0].s, arg0[1].s, arg0[2].s);
}

void func_00129D98(XAudArg* arg0) {
    func_0014F658(arg0[0].p, 4);
    sceVu0ScaleVectorXYZ(arg0[0].obj->unk_3C0, arg0[1].p, ((f32*)arg0[1].p)[3]);
}

void func_00135A10(void*, s32);

void func_00129DD8(XAudArg* arg0) {
    func_00135A10(arg0[0].p, arg0[1].s);
}

void func_00135A38(void*, s32);

void func_00129DF8(XAudArg* arg0) {
    func_00135A38(arg0[0].p, arg0[1].s);
}

INCLUDE_ASM("asm/nonmatchings/xaudacity", func_00129E18);

s32 func_001237E8(s32);

void func_00129E78(XAudArg* arg0) {
    arg0[0].s = func_001237E8(arg0[0].s);
}

INCLUDE_ASM("asm/nonmatchings/xaudacity", func_00129EA8);

void func_00137440(void*, s32);

void func_00129F20(XAudArg* arg0) {
    func_00137440(arg0[0].p, arg0[1].s);
}

void func_00129F40(XAudArg* arg0) {
    XAud398* p = arg0[0].obj->unk_398;
    arg0[0].s = (p != NULL) ? p->unk_04 : -1;
}

void func_001366D8(s32, s32, s32);

void func_00129F60(XAudArg* arg0) {
    func_001366D8(arg0[0].s, arg0[1].s, arg0[2].s);
}

s32 func_00137618(s32);

void func_00129F88(XAudArg* arg0) {
    arg0[0].s = func_00137618(arg0[0].s);
}

void func_00137448(void*);

void func_00129FB8(XAudArg* arg0) {
    func_00137448(arg0[0].p);
}

s32 func_001477E0(s32);

void func_00129FD0(XAudArg* arg0) {
    arg0[0].s = func_001477E0(arg0[1].s);
}

void func_0012A000(XAudArg* arg0) {
    arg0[0].s = (s32)(arg0[0].obj->unk_370.raw >> 35) & 1;
}

void func_00157818(void*, s32);

void func_0012A018(XAudArg* arg0) {
    func_00157818(arg0[0].p, arg0[1].s);
}

void func_0012A038(XAudArg* arg0) {
    func_0014F658(arg0[0].p, 7);
    sceVu0ScaleVectorXYZ(arg0[0].obj->unk_3C0, arg0[1].p, ((f32*)arg0[1].p)[3]);
}

void func_0012A078(XAudArg* arg0) {
    XAudObj* obj = arg0[0].obj;
    arg0[0].s = (obj != NULL) ? (s32)(obj->unk_370.raw >> 37) & 3 : 0;
}

s32 func_00131B08(s32);

void func_0012A098(XAudArg* arg0) {
    arg0[0].s = func_00131B08(arg0[0].s);
}

void func_0012A0C8(XAudArg* arg0) {
    arg0[0].s = arg0[0].obj->unk_130->unk_4E;
}

void func_0012A0E0(XAudArg* arg0) {
    arg0[0].obj->unk_06C->unk_BD = arg0[1].s;
}

s32 func_00157528(s32);

void func_0012A0F8(XAudArg* arg0) {
    arg0[0].s = func_00157528(arg0[0].s);
}

void func_00157648(void*);

void func_0012A128(XAudArg* arg0) {
    func_00157648(arg0[0].p);
}

void func_00157978(s32, s32, f32);

void func_0012A140(XAudArg* arg0) {
    func_00157978(arg0[0].s, arg0[1].s, arg0[2].f);
}

INCLUDE_ASM("asm/nonmatchings/xaudacity", func_0012A168);

void func_0012A1B8(XAudArg* arg0) {
    arg0[0].s = arg0[0].obj->unk_39E;
}

f32 func_00132F00(s32);

void func_0012A1C8(XAudArg* arg0) {
    arg0[0].f = func_00132F00(arg0[0].s);
}

void func_0012A1F8(XAudArg* arg0) {
    arg0[0].s = arg0[0].obj->unk_130->unk_58;
}

INCLUDE_ASM("asm/nonmatchings/xaudacity", func_0012A210);

void func_0012A270(XAudArg* arg0) {
    arg0[0].f = arg0[0].obj->unk_284;
}

INCLUDE_ASM("asm/nonmatchings/xaudacity", func_0012A280);

void func_0012A308(XAudArg* arg0) {
    arg0[0].obj->unk_370.raw |= 0x10000000000000;
}

s32 func_00148968(s32, s32, s32);

void func_0012A328(XAudArg* arg0) {
    arg0[0].s = func_00148968(arg0[0].s, arg0[1].s, arg0[2].s);
}

INCLUDE_ASM("asm/nonmatchings/xaudacity", func_0012A360);

#ifdef VERSION_FM
void func_F20000(s32, s32);

void fm_func_0012A400(XAudArg* arg0) {
    if ((D_002C1EA8 >> 13) & 1) {
        func_F20000(6, arg0[0].s);
    }
}
#endif

INCLUDE_ASM("asm/nonmatchings/xaudacity", func_0012A3D0);

#ifdef VERSION_FM
void func_00135848(s32);
void func_00135870(s32);

void fm_func_0012A498(XAudArg* arg0) {
    if (arg0[1].s != 0) {
        func_00135848(arg0[0].s);
    } else {
        func_00135870(arg0[0].s);
    }
}
#endif

#ifdef VERSION_FM
s32 func_00148A60(s32, s32);

void fm_func_0012A4C8(XAudArg* arg0) {
    arg0[0].s = func_00148A60(arg0[0].s, arg0[1].s);
}
#endif

s32 func_00147C98(s32, s32, s32);

void func_0012A418(XAudArg* arg0) {
    arg0[0].s = func_00147C98(arg0[0].s, arg0[1].s, arg0[2].s);
}

void sceVu0CopyVector(f32*, f32*);

void func_0012A450(XAudArg* arg0) {
    sceVu0CopyVector(arg0[0].ptrs->unk_00, arg0[1].p);
}

void func_00176340(void*);

void func_0012A470(XAudArg* arg0) {
    func_00176340(arg0[0].p);
}

s32 func_00148768(s32, s32, s32, s32, f32);

void func_0012A488(XAudArg* arg0) {
    arg0[0].s = func_00148768(arg0[0].s, arg0[1].s, arg0[2].s, arg0[3].s, arg0[4].f);
}

void func_00147F88(void*, f32);

void func_0012A4C8(XAudArg* arg0) {
    func_00147F88(arg0[0].p, arg0[1].f);
}

extern f32 D_002DEC60[4][4];
void sceVu0InversMatrix(f32 (*)[4], f32 (*)[4]);
void func_00120D38(s32, f32 (*)[4], s32);

void func_0012A4E8(XAudArg* arg0) {
    f32 m[4][4] __attribute__((aligned(16)));
    sceVu0InversMatrix(m, D_002DEC60);
    func_00120D38(arg0[0].s, m, arg0[1].s);
}

void func_0012A528(XAudArg* arg0) {
    sceVu0CopyVector(arg0[0].ptrs->unk_08, arg0[1].p);
}

INCLUDE_ASM("asm/nonmatchings/xaudacity", func_0012A548);

extern f32 D_002DEC60[4][4];

void func_0012A5F0(XAudArg* arg0) {
    arg0[0].f = atan2f(D_002DEC60[0][2], D_002DEC60[2][2]);
}

void func_00147D50(void*, s32);

void func_0012A628(XAudArg* arg0) {
    func_00147D50(arg0[0].p, arg0[1].s);
}

s32 func_00147ED8(s32, s32, s32, s32);

void func_0012A648(XAudArg* arg0) {
    arg0[0].s = func_00147ED8(arg0[0].s, arg0[1].s, arg0[2].s, arg0[3].s);
}

void func_00176310(void*);

void func_0012A680(XAudArg* arg0) {
    if (arg0[0].p != NULL) {
        func_00176310(arg0[0].p);
    }
    arg0[0].s = 0;
}

void func_0012BD00(void*, s32);

void func_0012A6B8(XAudArg* arg0) {
    func_0012BD00(arg0[0].p, arg0[1].s);
}

void func_001486B0(s32, s32, s32);

void func_0012A6D8(XAudArg* arg0) {
    func_001486B0(arg0[0].s, arg0[1].s, arg0[2].s);
}

void func_00148068(void*, f32);

void func_0012A700(XAudArg* arg0) {
    func_00148068(arg0[0].p, arg0[1].f);
}

void func_00176310(void*);

void func_0012A720(XAudArg* arg0) {
    func_00176310(arg0[0].p);
}

s32 func_0014A408(XAudArg*);

void func_0012A738(XAudArg* arg0) {
    arg0[0].s = func_0014A408(arg0);
}

s32* func_0014A4A8(s32, s32, s32);
extern s32 D_00514F10;

void func_0012A760(XAudArg* arg0) {
    s32* p = func_0014A4A8(arg0[0].s, arg0[1].s, arg0[2].s);
    arg0[0].p = p;
    p[0xA0 / 4] = D_00514F10;
}

s32 func_001354B8(s32, s32);

void func_0012A7A0(XAudArg* arg0) {
    arg0[0].s = func_001354B8(arg0[0].s, arg0[1].s);
}

void func_0014A898(void*, s32);

void func_0012A7D0(XAudArg* arg0) {
    func_0014A898(arg0[0].p, arg0[1].s);
}

INCLUDE_ASM("asm/nonmatchings/xaudacity", func_0012A7F0);

void func_00135640(void*, s32);

void func_0012A818(XAudArg* arg0) {
    func_00135640(arg0[0].p, arg0[1].s);
}

INCLUDE_ASM("asm/nonmatchings/xaudacity", func_0012A838);

void func_0014AB78(void*);

void func_0012A888(XAudArg* arg0) {
    func_0014AB78(arg0[0].p);
}

INCLUDE_ASM("asm/nonmatchings/xaudacity", func_0012A8A0);

void func_0012A8E8(XAudArg* arg0) {
    arg0[0].p = arg0[0].obj->unk_02C->unk_06C;
}

INCLUDE_ASM("asm/nonmatchings/xaudacity", func_0012A900);

INCLUDE_ASM("asm/nonmatchings/xaudacity", func_0012A968);

INCLUDE_ASM("asm/nonmatchings/xaudacity", func_0012A9B8);

void func_00141F10(void*, s32);

void func_0012AA08(XAudArg* arg0) {
    func_00141F10(arg0[0].p, arg0[1].s);
}

s32 func_0013A440(s32, s32, f32, s32);

void func_0012AA28(XAudArg* arg0) {
    arg0[0].s = func_0013A440(arg0[0].s, arg0[1].s, arg0[2].f, arg0[3].s);
}

void func_00123430(s32, s32, s32);

void func_0012AA60(XAudArg* arg0) {
    func_00123430(arg0[0].s, arg0[1].s, 0);
}

void func_00139408(s32, s32);

void func_0012AA80(XAudArg* arg0) {
    func_00139408(arg0[0].s, arg0[1].s);
    arg0[0].s = 0;
}

s32 func_001389C0(s32);

void func_0012AAB0(XAudArg* arg0) {
    arg0[0].s = func_001389C0(arg0[0].s);
}

s32 func_001389E8(s32);

void func_0012AAE0(XAudArg* arg0) {
    arg0[0].s = func_001389E8(arg0[0].s);
}

INCLUDE_ASM("asm/nonmatchings/xaudacity", func_0012AB10);

s32 func_001235B8(s32, s32);

void func_0012AB60(XAudArg* arg0) {
    arg0[0].s = func_001235B8(arg0[0].s, arg0[1].s);
}

s32 func_00137230(s32, s32, s32);

void func_0012AB90(XAudArg* arg0) {
    arg0[0].s = func_00137230(arg0[0].s, arg0[1].s, arg0[2].s);
}

s32 func_001334B8(s32, s32, s32, s32, s32);

void func_0012ABC8(XAudArg* arg0) {
    arg0[0].s = func_001334B8(arg0[0].s, arg0[1].s, arg0[2].s, arg0[3].s, arg0[4].s);
}

s32 func_0013A670(s32, s32, f32, f32);

void func_0012AC08(XAudArg* arg0) {
    arg0[0].s = func_0013A670(arg0[0].s, arg0[1].s, arg0[2].f, arg0[3].f);
}

void func_00138870(void*);

void func_0012AC40(XAudArg* arg0) {
    func_00138870(arg0[0].p);
}

void func_00138808(void*, f32);

void func_0012AC58(XAudArg* arg0) {
    func_00138808(arg0[0].p, arg0[1].f);
}

void func_0012AC78(XAudArg* arg0) {
    XAudObj* obj = arg0[0].obj;
    obj->unk_088 &= ~arg0[1].s;
    if (arg0[1].s & 2) {
        obj->unk_3E4 = 0;
    }
}

s32 func_00122AF8(s32, s32, s32);

void func_0012ACA8(XAudArg* arg0) {
    arg0[0].s = func_00122AF8(arg0[0].s, arg0[1].s | 8, arg0[2].s);
}

void func_00122B70(void*);

void func_0012ACE0(XAudArg* arg0) {
    func_00122B70(arg0[0].p);
}

void func_001228C8(void*, void*, f32, void*);

void func_0012ACF8(XAudArg* arg0) {
    func_001228C8(arg0[0].p, arg0[1].p, arg0[2].f, NULL);
}

extern s32 D_002C5C60;

void func_0012AD20(XAudArg* arg0) {
    func_001228C8(arg0[0].p, &D_002C5C60, arg0[1].f, func_00122B70);
}

void func_00142058(void*);

void func_0012AD50(XAudArg* arg0) {
    func_00142058(arg0[0].p);
}

void func_001421D0(void*, s32);

void func_0012AD68(XAudArg* arg0) {
    func_001421D0(arg0[0].p, arg0[1].s);
}

s32 func_00142240(s32);

void func_0012AD88(XAudArg* arg0) {
    arg0[0].s = func_00142240(arg0[0].s);
}

void func_001473A8(s32, s32, s32);

void func_0012ADB8(XAudArg* arg0) {
    func_001473A8(arg0[0].s, arg0[1].s, arg0[2].s);
}

void func_00147338(void*, s32);

void func_0012ADE0(XAudArg* arg0) {
    func_00147338(arg0[0].p, arg0[1].s);
}

void func_0012AE00(void) {
    func_0011D598(65);
    func_001ED878(14);
    func_0023F758();
}

INCLUDE_ASM("asm/nonmatchings/xaudacity", func_0012AE28);

s32 func_00142480(s32, s32, s32, s32);

void func_0012AE78(XAudArg* arg0) {
    arg0[0].s = func_00142480(arg0[0].s, arg0[1].s, 0, arg0[2].s) + 1;
}

INCLUDE_ASM("asm/nonmatchings/xaudacity", func_0012AEB8);

s32 func_00142480(s32, s32, s32, s32);

void func_0012AFF0(XAudArg* arg0) {
    arg0[0].s = func_00142480(arg0[0].s, arg0[1].s, arg0[2].s, arg0[3].s) + 1;
}

s32 func_0015BD78(s32, s32, s32);

void func_0012B030(XAudArg* arg0) {
    arg0[0].s = func_0015BD78(arg0[0].s, arg0[1].s, 0);
}

void func_0012CC38(void*, s32);

void func_0012B068(XAudArg* arg0) {
    func_0012CC38(arg0[0].p, arg0[1].s);
}

void func_0012CB78(void*, s32);

void func_0012B088(XAudArg* arg0) {
    func_0012CB78(arg0[0].p, arg0[1].s);
}

void func_0012B0A8(s32* arg0) {
    *arg0 = func_0012CBC0(*arg0);
}

#ifdef VERSION_FM
extern s32 D_002E31A8[];

void fm_func_0012B1A8(XAudArg* arg0) {
    if (arg0[0].s != 0) {
        D_002E31A8[0] |= 4;
    } else {
        D_002E31A8[0] &= ~4;
    }
}
#endif

void func_0012B0D8(s32* arg0) {
    *arg0 = &D_002DF430;
}

void func_0012B0E8(s32* arg0) {
    *arg0 = &D_002DF43C;
}

extern s32 D_002C5C4C;

void func_0012B0F8(XAudArg* arg0) {
    func_00146610(arg0[0].s, arg0[1].s, D_002C5C4C != 0);
}

void func_0012B120(s32* arg0) {
    *arg0 = func_00146740(*arg0);
}

void func_0012B150(s32* arg0) {
    func_00146610(arg0[0], arg0[1], 1);
}

void func_0012B170(s32* arg0) {
    *arg0 = func_001C6530(arg0[0], arg0[1]);
}

void func_0012B1A0(s32* arg0) {
    *arg0 = D_002979E8;
}
