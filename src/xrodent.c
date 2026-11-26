/**
 * One function, still assembly: a config menu page (it reads and writes options with Config_Get / Config_Set,
 * the option words of the GameData buffer D_003ED718, and draws menu items with func_002078F0), probably the main
 * config screen's update (see xpotato for the other config pages).
 */
#include "common.h"

INCLUDE_ASM("asm/nonmatchings/xrodent", func_002197E8);
