/* Exact retail word export for [800491FC,8004921C); EXE and assembly verified. */
#include "psx_types.h"

/* GTE/cop2 mnemonic overlay: ordinary C cannot emit coprocessor ops.
 * Verified by tools/match_function.py. */
__asm__(
    ".set noreorder\n"
    ".globl func_800491FC\n"
    ".type func_800491FC, @function\n"
    "func_800491FC:\n"
    "sll $a0, $a0, 4\n"
    "sll $a1, $a1, 4\n"
    "sll $a2, $a2, 4\n"
    "ctc2 $a0, $13\n"
    "ctc2 $a1, $14\n"
    "ctc2 $a2, $15\n"
    "jr $ra\n"
    "nop\n"
    ".size func_800491FC, .-func_800491FC\n"
    ".set reorder\n"
);
