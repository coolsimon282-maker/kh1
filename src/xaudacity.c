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

typedef struct XAudObj {
    /* 0x000 */ char unk_000[0x2C];
    /* 0x02C */ struct XAudObj* unk_02C;
    /* 0x030 */ char unk_030[0x3C];
    /* 0x06C */ XAud6C* unk_06C;
    /* 0x070 */ char unk_070[0xC0];
    /* 0x130 */ XAud130* unk_130;
    /* 0x134 */ char unk_134[0x18];
    /* 0x14C */ XAud14C* unk_14C;
    /* 0x150 */ char unk_150[0x7C];
    /* 0x1CC */ s32 unk_1CC;
    /* 0x1D0 */ char unk_1D0[0xB4];
    /* 0x284 */ f32 unk_284;
    /* 0x288 */ char unk_288[0xE8];
    /* 0x370 */ u64 unk_370;
    /* 0x378 */ char unk_378[0x20];
    /* 0x398 */ XAud398* unk_398;
    /* 0x39C */ char unk_39C[0x2];
    /* 0x39E */ u8 unk_39E;
    /* 0x39F */ char unk_39F[0x31];
    /* 0x3D0 */ s32 unk_3D0;
    /* 0x3D4 */ f32 unk_3D4;
} XAudObj;

typedef union XAudArg {
    s32 s;
    u32 u;
    f32 f;
    void* p;
    XAudObj* obj;
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
INCLUDE_ASM("asm/nonmatchings/xaudacity", fm_func_00128F70);
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

INCLUDE_ASM("asm/nonmatchings/xaudacity", func_001291D8);

INCLUDE_ASM("asm/nonmatchings/xaudacity", func_00129200);

INCLUDE_ASM("asm/nonmatchings/xaudacity", func_00129230);

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

INCLUDE_ASM("asm/nonmatchings/xaudacity", func_00129358);

INCLUDE_ASM("asm/nonmatchings/xaudacity", func_00129398);

INCLUDE_ASM("asm/nonmatchings/xaudacity", func_001293C0);

INCLUDE_ASM("asm/nonmatchings/xaudacity", func_001293F8);

INCLUDE_ASM("asm/nonmatchings/xaudacity", func_00129430);

INCLUDE_ASM("asm/nonmatchings/xaudacity", func_00129458);

s32 func_001234A0(s32);

void func_00129490(XAudArg* arg0) {
    arg0[0].s = func_001234A0(arg0[0].s);
}

void func_0012EC88(void*, s32);

void func_001294C0(XAudArg* arg0) {
    func_0012EC88(arg0[0].p, arg0[1].s);
}

INCLUDE_ASM("asm/nonmatchings/xaudacity", func_001294E0);

INCLUDE_ASM("asm/nonmatchings/xaudacity", func_00129500);

s32 func_001245F0(s32);

void func_00129540(XAudArg* arg0) {
    arg0[0].s = func_001245F0(arg0[0].s);
}

INCLUDE_ASM("asm/nonmatchings/xaudacity", func_00129570);

INCLUDE_ASM("asm/nonmatchings/xaudacity", func_001295A8);

s32 func_001349D0(s32, s32);

void func_001295D8(XAudArg* arg0) {
    arg0[0].s = func_001349D0(arg0[0].s, arg0[1].s);
}

INCLUDE_ASM("asm/nonmatchings/xaudacity", func_00129608);

INCLUDE_ASM("asm/nonmatchings/xaudacity", func_00129638);

INCLUDE_ASM("asm/nonmatchings/xaudacity", func_00129660);

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

INCLUDE_ASM("asm/nonmatchings/xaudacity", func_00129748);

INCLUDE_ASM("asm/nonmatchings/xaudacity", func_00129780);

void func_001297A8(XAudArg* arg0) {
    arg0[0].obj->unk_3D0 = arg0[1].s - 3;
}

INCLUDE_ASM("asm/nonmatchings/xaudacity", func_001297C0);

s32 func_0014EE88(s32);

void func_001297F0(XAudArg* arg0) {
    arg0[0].s = func_0014EE88(arg0[0].s);
}

INCLUDE_ASM("asm/nonmatchings/xaudacity", func_00129820);

void func_00129840(void) {
}

void func_0014F658(void*, s32);

void func_00129848(XAudArg* arg0) {
    func_0014F658(arg0[0].p, arg0[1].s);
}

void func_00129868(XAudArg* arg0) {
    arg0[0].f = arg0[0].obj->unk_3D4;
}

INCLUDE_ASM("asm/nonmatchings/xaudacity", func_00129878);

INCLUDE_ASM("asm/nonmatchings/xaudacity", func_001298A8);

INCLUDE_ASM("asm/nonmatchings/xaudacity", func_001298D8);

INCLUDE_ASM("asm/nonmatchings/xaudacity", func_00129910);

INCLUDE_ASM("asm/nonmatchings/xaudacity", func_00129938);

INCLUDE_ASM("asm/nonmatchings/xaudacity", func_00129960);

INCLUDE_ASM("asm/nonmatchings/xaudacity", func_001299B8);

INCLUDE_ASM("asm/nonmatchings/xaudacity", func_001299F0);

INCLUDE_ASM("asm/nonmatchings/xaudacity", func_00129A18);

INCLUDE_ASM("asm/nonmatchings/xaudacity", func_00129A48);

INCLUDE_ASM("asm/nonmatchings/xaudacity", func_00129A80);

void func_00129AB0(XAudArg* arg0) {
    arg0[0].obj->unk_1CC |= arg0[1].s;
}

void func_00129AC8(XAudArg* arg0) {
    arg0[0].obj->unk_1CC &= ~arg0[1].s;
}

INCLUDE_ASM("asm/nonmatchings/xaudacity", func_00129AE8);

void func_00129B28(XAudArg* arg0) {
    arg0[0].s = arg0[0].obj->unk_130->unk_4C;
}

INCLUDE_ASM("asm/nonmatchings/xaudacity", func_00129B40);

INCLUDE_ASM("asm/nonmatchings/xaudacity", func_00129B88);

INCLUDE_ASM("asm/nonmatchings/xaudacity", func_00129BC0);

INCLUDE_ASM("asm/nonmatchings/xaudacity", func_00129C08);

INCLUDE_ASM("asm/nonmatchings/xaudacity", func_00129C30);

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
    arg0[0].obj->unk_370 |= 0x8000000000000;
}

void func_00129D58(XAudArg* arg0) {
    arg0[0].s = arg0[0].obj->unk_130->unk_5A;
}

INCLUDE_ASM("asm/nonmatchings/xaudacity", func_00129D70);

INCLUDE_ASM("asm/nonmatchings/xaudacity", func_00129D98);

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

INCLUDE_ASM("asm/nonmatchings/xaudacity", func_00129F60);

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

INCLUDE_ASM("asm/nonmatchings/xaudacity", func_0012A000);

void func_00157818(void*, s32);

void func_0012A018(XAudArg* arg0) {
    func_00157818(arg0[0].p, arg0[1].s);
}

INCLUDE_ASM("asm/nonmatchings/xaudacity", func_0012A038);

INCLUDE_ASM("asm/nonmatchings/xaudacity", func_0012A078);

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

INCLUDE_ASM("asm/nonmatchings/xaudacity", func_0012A140);

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
    arg0[0].obj->unk_370 |= 0x10000000000000;
}

INCLUDE_ASM("asm/nonmatchings/xaudacity", func_0012A328);

INCLUDE_ASM("asm/nonmatchings/xaudacity", func_0012A360);

#ifdef VERSION_FM
INCLUDE_ASM("asm/nonmatchings/xaudacity", fm_func_0012A400);
#endif

INCLUDE_ASM("asm/nonmatchings/xaudacity", func_0012A3D0);

#ifdef VERSION_FM
INCLUDE_ASM("asm/nonmatchings/xaudacity", fm_func_0012A498);
#endif

#ifdef VERSION_FM
INCLUDE_ASM("asm/nonmatchings/xaudacity", fm_func_0012A4C8);
#endif

INCLUDE_ASM("asm/nonmatchings/xaudacity", func_0012A418);

INCLUDE_ASM("asm/nonmatchings/xaudacity", func_0012A450);

void func_00176340(void*);

void func_0012A470(XAudArg* arg0) {
    func_00176340(arg0[0].p);
}

INCLUDE_ASM("asm/nonmatchings/xaudacity", func_0012A488);

void func_00147F88(void*, f32);

void func_0012A4C8(XAudArg* arg0) {
    func_00147F88(arg0[0].p, arg0[1].f);
}

INCLUDE_ASM("asm/nonmatchings/xaudacity", func_0012A4E8);

INCLUDE_ASM("asm/nonmatchings/xaudacity", func_0012A528);

INCLUDE_ASM("asm/nonmatchings/xaudacity", func_0012A548);

INCLUDE_ASM("asm/nonmatchings/xaudacity", func_0012A5F0);

void func_00147D50(void*, s32);

void func_0012A628(XAudArg* arg0) {
    func_00147D50(arg0[0].p, arg0[1].s);
}

INCLUDE_ASM("asm/nonmatchings/xaudacity", func_0012A648);

INCLUDE_ASM("asm/nonmatchings/xaudacity", func_0012A680);

void func_0012BD00(void*, s32);

void func_0012A6B8(XAudArg* arg0) {
    func_0012BD00(arg0[0].p, arg0[1].s);
}

INCLUDE_ASM("asm/nonmatchings/xaudacity", func_0012A6D8);

void func_00148068(void*, f32);

void func_0012A700(XAudArg* arg0) {
    func_00148068(arg0[0].p, arg0[1].f);
}

void func_00176310(void*);

void func_0012A720(XAudArg* arg0) {
    func_00176310(arg0[0].p);
}

INCLUDE_ASM("asm/nonmatchings/xaudacity", func_0012A738);

INCLUDE_ASM("asm/nonmatchings/xaudacity", func_0012A760);

INCLUDE_ASM("asm/nonmatchings/xaudacity", func_0012A7A0);

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

INCLUDE_ASM("asm/nonmatchings/xaudacity", func_0012AA28);

INCLUDE_ASM("asm/nonmatchings/xaudacity", func_0012AA60);

INCLUDE_ASM("asm/nonmatchings/xaudacity", func_0012AA80);

s32 func_001389C0(s32);

void func_0012AAB0(XAudArg* arg0) {
    arg0[0].s = func_001389C0(arg0[0].s);
}

s32 func_001389E8(s32);

void func_0012AAE0(XAudArg* arg0) {
    arg0[0].s = func_001389E8(arg0[0].s);
}

INCLUDE_ASM("asm/nonmatchings/xaudacity", func_0012AB10);

INCLUDE_ASM("asm/nonmatchings/xaudacity", func_0012AB60);

INCLUDE_ASM("asm/nonmatchings/xaudacity", func_0012AB90);

INCLUDE_ASM("asm/nonmatchings/xaudacity", func_0012ABC8);

INCLUDE_ASM("asm/nonmatchings/xaudacity", func_0012AC08);

void func_00138870(void*);

void func_0012AC40(XAudArg* arg0) {
    func_00138870(arg0[0].p);
}

void func_00138808(void*, f32);

void func_0012AC58(XAudArg* arg0) {
    func_00138808(arg0[0].p, arg0[1].f);
}

INCLUDE_ASM("asm/nonmatchings/xaudacity", func_0012AC78);

INCLUDE_ASM("asm/nonmatchings/xaudacity", func_0012ACA8);

void func_00122B70(void*);

void func_0012ACE0(XAudArg* arg0) {
    func_00122B70(arg0[0].p);
}

INCLUDE_ASM("asm/nonmatchings/xaudacity", func_0012ACF8);

INCLUDE_ASM("asm/nonmatchings/xaudacity", func_0012AD20);

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

INCLUDE_ASM("asm/nonmatchings/xaudacity", func_0012ADB8);

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

INCLUDE_ASM("asm/nonmatchings/xaudacity", func_0012AE78);

INCLUDE_ASM("asm/nonmatchings/xaudacity", func_0012AEB8);

INCLUDE_ASM("asm/nonmatchings/xaudacity", func_0012AFF0);

INCLUDE_ASM("asm/nonmatchings/xaudacity", func_0012B030);

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
INCLUDE_ASM("asm/nonmatchings/xaudacity", fm_func_0012B1A8);
#endif

void func_0012B0D8(s32* arg0) {
    *arg0 = &D_002DF430;
}

void func_0012B0E8(s32* arg0) {
    *arg0 = &D_002DF43C;
}

INCLUDE_ASM("asm/nonmatchings/xaudacity", func_0012B0F8);

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
