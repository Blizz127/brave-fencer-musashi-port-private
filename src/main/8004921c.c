/* Exact retail word export for [8004921C,80049234); EXE/asm verified. */
#include "psx_types.h"

/* GTE/cop2 mnemonic overlay: ordinary C cannot emit coprocessor ops.
 * Verified by tools/match_function.py. */
__asm__(
    ".set noreorder\n"
    ".globl func_8004921C\n"
    ".type func_8004921C, @function\n"
    "func_8004921C:\n"
    "sll $a0, $a0, 16\n"
    "sll $a1, $a1, 16\n"
    "ctc2 $a0, $24\n"
    "ctc2 $a1, $25\n"
    "jr $ra\n"
    "nop\n"
    ".size func_8004921C, .-func_8004921C\n"
    ".set reorder\n"
);
