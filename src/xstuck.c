/**
 * Event effect loading, two functions (JP/EU; Final Mix: src/unsplit/xstuck.c): build file names of the form
 * eveffect/<name>_%03d.dpp (and the matching data file) and queue them with cdvd_QueueFileLoad, with a load callback.
 */
#include "common.h"

INCLUDE_ASM("asm/nonmatchings/xstuck", func_001DEE78);

INCLUDE_ASM("asm/nonmatchings/xstuck", func_001DF008);

INCLUDE_RODATA("asm/nonmatchings/xstuck", D_0048A458);

INCLUDE_RODATA("asm/nonmatchings/xstuck", D_0048A468);

INCLUDE_RODATA("asm/nonmatchings/xstuck", D_0048A470);

INCLUDE_RODATA("asm/nonmatchings/xstuck", D_0048A478);
