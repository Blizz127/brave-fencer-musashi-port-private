/* Exact retail word export for [80053AD8,80053AF8); EXE/asm verified. */
#include "psx_types.h"

/* GTE/cop2 mnemonic overlay: ordinary C cannot emit coprocessor ops.
 * Verified by tools/match_function.py. */
__asm__(
    ".set noreorder\n"
    ".globl func_80053AD8\n"
    ".type func_80053AD8, @function\n"
    "func_80053AD8:\n"
    "sll $a0, $a0, 4\n"
    "sll $a1, $a1, 4\n"
    "sll $a2, $a2, 4\n"
    "ctc2 $a0, $21\n"
    "ctc2 $a1, $22\n"
    "ctc2 $a2, $23\n"
    "jr $ra\n"
    "nop\n"
    ".size func_80053AD8, .-func_80053AD8\n"
    ".set reorder\n"
);
