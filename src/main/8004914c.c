#include "psx_types.h"

/* GTE/cop2 mnemonic overlay: ordinary C cannot emit coprocessor ops.
 * Verified by tools/match_function.py. */
__asm__(
    ".set noreorder\n"
    ".globl func_8004914C\n"
    ".type func_8004914C, @function\n"
    "func_8004914C:\n"
    "lw $t0, 0x0($a0)\n"
    "lw $t1, 0x4($a0)\n"
    "lw $t2, 0x8($a0)\n"
    "lw $t3, 0xC($a0)\n"
    "lw $t4, 0x10($a0)\n"
    "ctc2 $t0, $0\n"
    "ctc2 $t1, $1\n"
    "ctc2 $t2, $2\n"
    "ctc2 $t3, $3\n"
    "ctc2 $t4, $4\n"
    "jr $ra\n"
    "nop\n"
    ".size func_8004914C, .-func_8004914C\n"
    ".set reorder\n"
);
