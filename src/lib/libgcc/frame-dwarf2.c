// Library code (Final Mix). One function at a time: replace an INCLUDE_ASM line with matching C.
// Data this file owns is still in the data segments: declare it extern here, do not define it.
#include "common.h"

INCLUDE_ASM("asm/nonmatchings/lib/libgcc/frame-dwarf2", decode_uleb128);

INCLUDE_ASM("asm/nonmatchings/lib/libgcc/frame-dwarf2", decode_sleb128);

INCLUDE_ASM("asm/nonmatchings/lib/libgcc/frame-dwarf2", fde_merge);

INCLUDE_ASM("asm/nonmatchings/lib/libgcc/frame-dwarf2", end_fde_sort);

INCLUDE_ASM("asm/nonmatchings/lib/libgcc/frame-dwarf2", __register_frame_info);

INCLUDE_ASM("asm/nonmatchings/lib/libgcc/frame-dwarf2", __register_frame);

INCLUDE_ASM("asm/nonmatchings/lib/libgcc/frame-dwarf2", __register_frame_info_table);

INCLUDE_ASM("asm/nonmatchings/lib/libgcc/frame-dwarf2", __register_frame_table);

INCLUDE_ASM("asm/nonmatchings/lib/libgcc/frame-dwarf2", __deregister_frame_info);

INCLUDE_ASM("asm/nonmatchings/lib/libgcc/frame-dwarf2", __deregister__frame);

INCLUDE_ASM("asm/nonmatchings/lib/libgcc/frame-dwarf2", count_fdes);

INCLUDE_ASM("asm/nonmatchings/lib/libgcc/frame-dwarf2", add_fdes);

INCLUDE_ASM("asm/nonmatchings/lib/libgcc/frame-dwarf2", search_fdes);

INCLUDE_ASM("asm/nonmatchings/lib/libgcc/frame-dwarf2", frame_init);

INCLUDE_ASM("asm/nonmatchings/lib/libgcc/frame-dwarf2", find_fde);

INCLUDE_ASM("asm/nonmatchings/lib/libgcc/frame-dwarf2", extract_cie_info);

INCLUDE_ASM("asm/nonmatchings/lib/libgcc/frame-dwarf2", decode_stack_op);

INCLUDE_ASM("asm/nonmatchings/lib/libgcc/frame-dwarf2", execute_cfa_insn);

INCLUDE_ASM("asm/nonmatchings/lib/libgcc/frame-dwarf2", __frame_state_for);
