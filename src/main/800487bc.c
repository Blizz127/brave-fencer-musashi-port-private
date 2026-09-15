/* Main-exec range [800487BC,80048804) from the SLUS executable.
 * SHA256(span)=3826a102b888245f21b1b159cd1d4d08be11f4c6d460ce122047a9d2cc7e48db.
 * Word export for the native seam; the body below is kept
 * byte-identical (wrap only, no rewrite). */
#include "psx_types.h"

/* GTE/cop2 mnemonic overlay: ordinary C cannot emit coprocessor ops.
 * Verified by tools/match_function.py. */
__asm__(
    ".set noreorder\n"
    ".globl func_800487BC\n"
    ".type func_800487BC, @function\n"
    "func_800487BC:\n"
    "cfc2 $t0, $0\n"
    "cfc2 $t1, $1\n"
    "cfc2 $t2, $2\n"
    "cfc2 $t3, $3\n"
    "cfc2 $t4, $4\n"
    "sw $t0, 0x0($a0)\n"
    "sw $t1, 0x4($a0)\n"
    "sw $t2, 0x8($a0)\n"
    "sw $t3, 0xC($a0)\n"
    "sw $t4, 0x10($a0)\n"
    "cfc2 $t0, $5\n"
    "cfc2 $t1, $6\n"
    "cfc2 $t2, $7\n"
    "sw $t0, 0x14($a0)\n"
    "sw $t1, 0x18($a0)\n"
    "sw $t2, 0x1C($a0)\n"
    "jr $ra\n"
    "nop\n"
    ".size func_800487BC, .-func_800487BC\n"
    ".set reorder\n"
);
