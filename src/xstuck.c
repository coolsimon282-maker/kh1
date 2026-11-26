/**
 * Event effect loading, two functions: build file names of the form eveffect/<name>_%03d.dpp (and the matching data
 * file) and queue them with cdvd_QueueFileLoad, with a load callback. JP/EU: 0x1DEE78-0x1DF198. Final Mix
 * (#ifdef VERSION_FM): the same two 0x190-byte functions at 0x1DDC78-0x1DDF98, right after xhumungus.
 */
#include "common.h"

#ifdef VERSION_FM
// .data (0x003DABD8-0x003DAC40): "<world>/<world>" path prefixes, one per world
char D_003DABD8[17][6] = {
    "al/al", "aw/aw", "dc/dc", "dh/dh", "di/di", "ew/ew", "he/he", "lm/lm", "nm/nm",
    "pc/pc", "pi/pi", "po/po", "pp/pp", "tw/tw", "tz/tz", "zz/zz", "gb/gb",
};

INCLUDE_ASM("asm/nonmatchings/xstuck", func_001DDC78);
#else
INCLUDE_ASM("asm/nonmatchings/xstuck", func_001DEE78);
#endif

#ifdef VERSION_FM
INCLUDE_ASM("asm/nonmatchings/xstuck", func_001DDE08);
#else
INCLUDE_ASM("asm/nonmatchings/xstuck", func_001DF008);
#endif

#ifndef VERSION_FM
INCLUDE_RODATA("asm/nonmatchings/xstuck", D_0048A458);

INCLUDE_RODATA("asm/nonmatchings/xstuck", D_0048A468);

INCLUDE_RODATA("asm/nonmatchings/xstuck", D_0048A470);

INCLUDE_RODATA("asm/nonmatchings/xstuck", D_0048A478);
#endif
