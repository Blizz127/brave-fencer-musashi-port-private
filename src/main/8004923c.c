/* Exact retail word export for [8004923C,80049248); EXE and assembly verified. */
#include "psx_types.h"

/* GTE/cop2 mnemonic overlay: ordinary C cannot emit coprocessor ops.
 * Verified by tools/match_function.py. */
__asm__(
    ".set noreorder\n"
    ".globl func_8004923C\n"
    ".type func_8004923C, @function\n"
    "func_8004923C:\n"
    "ctc2 $a0, $26\n"
    "jr $ra\n"
    "nop\n"
    ".size func_8004923C, .-func_8004923C\n"
    ".set reorder\n"
);
