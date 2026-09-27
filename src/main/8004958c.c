/* Main-exec range [8004958C,800495E0) from the SLUS executable.
 * SHA256(span)=6dd2d4421dbd97f4d19df2c97fcc9c62ae767fbc5ffe3650e46470f37489e9e3.
 * Word export for the native seam; the body below is kept
 * byte-identical (wrap only, no rewrite). */
#include "psx_types.h"

/* GTE/cop2 mnemonic overlay: ordinary C cannot emit coprocessor ops.
 * Verified by tools/match_function.py. */
__asm__(
    ".set noreorder\n"
    ".globl func_8004958C\n"
    ".type func_8004958C, @function\n"
    "func_8004958C:\n"
    "lwc2 $0, 0x0($a0)\n"
    "lwc2 $1, 0x4($a0)\n"
    "lwc2 $2, 0x0($a1)\n"
    "lwc2 $3, 0x4($a1)\n"
    "lwc2 $4, 0x0($a2)\n"
    "lwc2 $5, 0x4($a2)\n"
    "nop\n"
    "lw $t0, 0x10($sp)\n"
    "lw $t1, 0x14($sp)\n"
    "lw $t2, 0x18($sp)\n"
    "lw $t3, 0x1C($sp)\n"
    "swc2 $12, 0x0($a3)\n"
    "swc2 $13, 0x0($t0)\n"
    "swc2 $14, 0x0($t1)\n"
    "swc2 $8, 0x0($t2)\n"
    "cfc2 $v1, $31\n"
    "mfc2 $v0, $19\n"
    "sw $v1, 0x0($t3)\n"
    "jr $ra\n"
    "sra $v0, $v0, 2\n"
    ".size func_8004958C, .-func_8004958C\n"
    ".set reorder\n"
);
