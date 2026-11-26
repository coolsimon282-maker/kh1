// Final Mix's version of xstuck (JP: src/xstuck.c, 0x1DEE78-0x1DF198, two 0x190-byte functions; here the same two
// at 0x1DDC78-0x1DDF98, right after xhumungus). Split out of the placeholder seg_0DDC78; FM only (JP/EU use src/xstuck.c).
#include "common.h"

// .data (0x003DABD8-0x003DAC40): "<world>/<world>" path prefixes, one per world
char D_003DABD8[17][6] = {
    "al/al", "aw/aw", "dc/dc", "dh/dh", "di/di", "ew/ew", "he/he", "lm/lm", "nm/nm",
    "pc/pc", "pi/pi", "po/po", "pp/pp", "tw/tw", "tz/tz", "zz/zz", "gb/gb",
};

INCLUDE_ASM("asm/nonmatchings/unsplit/xstuck", func_001DDC78);

INCLUDE_ASM("asm/nonmatchings/unsplit/xstuck", func_001DDE08);
