/**
 * The game over sequence (probably: a two-choice menu, then game mode 10 or a continue) and the pause and party menu
 * request flags.
 */
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

void GameOver_Start();

extern void func_00180CE0();
extern void func_0022BA18(u16);

#ifdef VERSION_FM
extern s32 D_003F34A4;
extern s32 D_003F720C;

void func_0011C5E8();
void fm_func_001C07A8(void);

// Task: when D_003F34A4 clears, either requests game mode 15 (D_003F720C == 1, FM) or starts the sequence again.
s32 GameOver_ContinueTask(void) {
    if (D_003F34A4 == 0) {
        if (D_003F720C == 1) {
            func_0011C5E8();
            GameMode_Request(15);
            fm_func_001C07A8();
        } else {
            GameOver_Start();
        }
        return 4;
    }
    return 0;
}
#else
#ifdef VERSION_EU
s32 GameOver_ContinueTask(void);
INCLUDE_ASM("asm/nonmatchings/xpaste", GameOver_ContinueTask);
#else
s32 GameOver_ContinueTask(void) {
    if (D_003ED704 == 0) {
        if (D_003F117C == 1) {
            GameMode_Request(2);
            func_00111638();
            D_002B29D0 = 1;
        } else {
            GameOver_Start();
        }
        return 4;
    }
    return 0;
}
#endif
#endif

#ifdef VERSION_FM
extern s32 D_003F7774;
extern s32 D_003F7778;

void func_0022BCB8(s32);

// Task: when the menu (D_003F7774) closes, choice 0 requests game mode 10, choice 1 starts func_0022BCB8 and adds GameOver_ContinueTask.
s32 GameOver_ChoiceTask(void) {
    if (D_003F7774 == 0) {
        switch (D_003F7778) {
            case FALSE:
                GameMode_Request(10);
                return 4;
            case TRUE:
                func_0022BCB8(0xffff);
                TaskSystem_AddTask(30000, GameOver_ContinueTask);
                return 4;
        }
    }
    return 0;
}
#else
#ifdef VERSION_EU
s32 GameOver_ChoiceTask(void);
INCLUDE_ASM("asm/nonmatchings/xpaste", GameOver_ChoiceTask);
#else
s32 GameOver_ChoiceTask(void) {
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
                TaskSystem_AddTask(30000, GameOver_ContinueTask);
                return 4;
        }
    }
    return 0;
}
#endif
#endif

// Starts the game over sequence, probably: sets D_002BD854, stops the game (func_00114420, func_00180CE0), fades the music and adds GameOver_ChoiceTask.
void GameOver_Start(void) {
    D_002BD854 = 1;
    D_002B8354 = 0;
    func_00114420();
    func_00180CE0();
    func_0022BA18(-1);
    func_0011E340();
    TaskSystem_AddTask(30000, GameOver_ChoiceTask);
    func_0011D4B8(120);
}

// D_002BD858 = arg0 (makes PauseMenu_SelectMode choose mode 4).
void func_0011C598(s32 arg0) {
    D_002BD858 = arg0;
}

// Clears D_002BD858.
void func_0011C5A8(void) {
    D_002BD858 = 0;
}

// Requests the party menu (D_002BD85C = 1, pause mode 5).
void PartyMenu_RequestOpen(void) {
    D_002BD85C = 1;
}

// Clears the party menu request.
void PartyMenu_ClearOpenRequest(void) {
    D_002BD85C = 0;
}
