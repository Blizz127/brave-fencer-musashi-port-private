/* Main-exec range [8004917C,800491AC) from the SLUS executable.
 * SHA256(span)=b9ce521ecd6cadeda48a0828b73f9b37d260c4f83e4d3b099334608f9e8fe598.
 * Word export for the native seam; the body below is kept
 * byte-identical (wrap only, no rewrite). */
#include "psx_types.h"

/* GTE/cop2 mnemonic overlay: ordinary C cannot emit coprocessor ops.
 * Verified by tools/match_function.py. */
__asm__(
    ".set noreorder\n"
    ".globl func_8004917C\n"
    ".type func_8004917C, @function\n"
    "func_8004917C:\n"
    "lw $t0, 0x0($a0)\n"
    "lw $t1, 0x4($a0)\n"
    "lw $t2, 0x8($a0)\n"
    "lw $t3, 0xC($a0)\n"
    "lw $t4, 0x10($a0)\n"
    "ctc2 $t0, $8\n"
    "ctc2 $t1, $9\n"
    "ctc2 $t2, $10\n"
    "ctc2 $t3, $11\n"
    "ctc2 $t4, $12\n"
    "jr $ra\n"
    "nop\n"
    ".size func_8004917C, .-func_8004917C\n"
    ".set reorder\n"
);
