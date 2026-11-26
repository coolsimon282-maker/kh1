#ifndef GAMESTATE_H
#define GAMESTATE_H

#include "common.h"

/* A position with an angle: x, y, z and (for party members) the facing angle in w. */
typedef struct GameStatePos {
    f32 x, y, z, w;
} GameStatePos;

/* The game state in work buffer 3 (gameState, xtrumpet.c): where the player is and the party's positions there,
   probably the part of a save that says where to continue. Size at least 0x160. */
typedef struct GameState {
    /* 0x000 */ u8 unk_00[0x10];
    /* 0x010 */ GameStatePos memberPos[3]; // the three party members (D_002E26A0) at the last save of the location
    /* 0x040 */ s32 worldNo;               // curWorldNo
    /* 0x044 */ s32 roomNo;                // curRoomNo
    /* 0x048 */ s32 entranceNo;            // curEntranceNo
    /* 0x04C */ s32 unk_4C[8];             // eight words copied from func_0017F1C8()
    /* 0x06C */ u8 unk_6C[234];            // byte groups per world (group sizes D_002BCB68), set by func_00111408
    /* 0x156 */ u8 pad_156[2];             // probably unused
    /* 0x158 */ s32 charFlags;             // bit n: character n has been in the party (GameState_RefreshAvailableFlags)
    /* 0x15C */ void* unk_15C;             // counted up by func_001115C0
} GameState;

extern GameState* gameState;

#endif // GAMESTATE_H
