#include "common.h"

typedef s32 (*XHumungusFunc)(UNK_PTR);

/* XGiantMountain: the event / script system's state block D_003854E0 (0x3384+ bytes). The struct below is kept exactly as
   it is: xhumungus.c includes this header, and adding field names here changes its code for JP/EU (func_001DB7A8 is
   sensitive to how many identifiers the file declares, rule F1; tried 26 Nov). What the views in xhumungus.c
   (XGiantMountainQ/F/B/C/D/X/Y/0F10/06F0) and xbuffalo.c (XBuffaloGM) show of the layout:
     0x0010 u16 tables [8][256], 0x1010 s32 counts [8] (one per table; this struct has s32* unk_1010 there)
     0x3034 / 0x3038 s32, cleared together when the script state is reset (xbuffalo.c)
     0x3070 u64 flag bits (single bits used: 33, 34, 38, 40, 43, 45..49, 58); 0x3078 u64 flag bits (bit 0, 0x1000)
     0x3080..0x3090 s32 words; 0x3098 / 0x309C s32; 0x30A0 f32 [3]; 0x30AC f32*
     0x3128 s32 frames left / 0x312C s32 step of a fade of the screen colour's alpha (D_002BC080[3] += step), probably
     0x3130 s32 frames left / 0x3134 s32 steps [3] of a fade of the screen colour's RGB (D_002BC080[0..2]), probably
     0x3140..0x3174 s32 words (0x3144 a pointer), 0x3380 s32
   (The offset comments of unk_3140..unk_3154 below were wrong by a field; the offsets in the list above are right.) */
typedef struct XGiantMountain {
    /* 0x0000 */ u8 unk_00;
    /* 0x0001 */ char unk_01[0x100F];
    /* 0x1010 */ s32* unk_1010;
    /* 0x1014 */ char unk_1004[0x205C];
    /* 0x3070 */ u64 unk_3070;
    /* 0x3078 */ u64 unk_3078;
    /* 0x3080 */ char unk_3080[12];
    /* 0x308C */ s32 unk_308C;
    /* 0x3090 */ s32 unk_3090;
    /* 0x3094 */ char unk_3094[172];
    /* 0x3140 */ s32 unk_3140;
    /* 0x3140 */ s32* unk_3144;
    /* 0x3148 */ s32 unk_3148;
    /* 0x315C */ s32 unk_314C;
    /* 0x315C */ s32 unk_3150;
    /* 0x3148 */ char unk_3154[8];
    /* 0x315C */ s32 unk_315C;
    /* 0x3160 */ s32 unk_3160;
    /* 0x3164 */ s32 unk_3164;
    /* 0x3168 */ s32 unk_3168;
    /* 0x316C */ s32 unk_316C;
    /* 0x3170 */ s32 unk_3170;
    /* 0x3174 */ s32 unk_3174;
    /* 0x3178 */ char unk_3178[0x208];
    /* 0x3380 */ s32 unk_3380;
} XGiantMountain;
