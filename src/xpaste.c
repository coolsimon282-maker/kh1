#include "common.h"
#include "common_funcs.h"

#include "xarcade.h"
#include "xblade.h"
#include "xturtle.h"

extern s32 D_002B29D0; // also in xpancake
extern s32 D_002B8354; // also in xarcade, xblade, xtailor
extern s32 D_002BD854; // also in xbeginning and unsplit code
extern s32 D_002BD858; // also in xblade
extern s32 D_002BD85C; // also in xblade
extern s32 D_003ED704; // also in xarcade, xturtle, and unsplit code
extern s32 D_003F117C; // also in unsplit code
extern s32 D_003F1514; // also in unsplit code
extern s32 D_003F1518; // also in unsplit code

void func_0011C540();

extern void func_00180CE0();
extern void func_0022BA18(u16);

#ifdef VERSION_FM
extern s32 D_003F34A4;
extern s32 D_003F720C;

void func_0011C5E8();
void fm_func_001C07A8(void);

s32 func_0011C440(void) {
    if (D_003F34A4 == 0) {
        if (D_003F720C == 1) {
            func_0011C5E8();
            GameMode_Request(15);
            fm_func_001C07A8();
        } else {
            func_0011C540();
        }
        return 4;
    }
    return 0;
}
#else
s32 func_0011C440(void) {
    if (D_003ED704 == 0) {
        if (D_003F117C == 1) {
            GameMode_Request(2);
            func_00111638();
            D_002B29D0 = 1;
        } else {
            func_0011C540();
        }
        return 4;
    }
    return 0;
}
#endif

#ifdef VERSION_FM
extern s32 D_003F7774;
extern s32 D_003F7778;

void func_0022BCB8(s32);

s32 func_0011C4B0(void) {
    if (D_003F7774 == 0) {
        switch (D_003F7778) {
            case FALSE:
                GameMode_Request(10);
                return 4;
            case TRUE:
                func_0022BCB8(0xffff);
                TaskSystem_AddTask(30000, func_0011C440);
                return 4;
        }
    }
    return 0;
}
#else
s32 func_0011C4B0(void) {
    if (D_003F1514 == 0) {
        switch (D_003F1518) {
            case FALSE:
                GameMode_Request(10);
                func_0022F848();
                func_00158C00(15);
                func_00111638();
                return 4;
            case TRUE:
                func_00229D60(0xffff);
                TaskSystem_AddTask(30000, func_0011C440);
                return 4;
        }
    }
    return 0;
}
#endif

void func_0011C540(void) {
    D_002BD854 = 1;
    D_002B8354 = 0;
    func_00114420();
    func_00180CE0();
    func_0022BA18(-1);
    func_0011E340();
    TaskSystem_AddTask(30000, func_0011C4B0);
    func_0011D4B8(120);
}

void func_0011C598(s32 arg0) {
    D_002BD858 = arg0;
}

void func_0011C5A8(void) {
    D_002BD858 = 0;
}

void PartyMenu_RequestOpen(void) {
    D_002BD85C = 1;
}

void PartyMenu_ClearOpenRequest(void) {
    D_002BD85C = 0;
}
