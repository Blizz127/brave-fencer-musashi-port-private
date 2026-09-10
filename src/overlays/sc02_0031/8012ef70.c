/* SC02.CD FILE_031 / ov_SC02_031 retail span [8012EF70,8012EFB8).
 * Offset 0x6E18 at overlay base 80128158. SHA256(span)=bd9c9f952cefc04ff3caff08b59fc229d95998c0e9eb833fe6455008053a68c0.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/8012ef70.c (recovery=assembly, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
#include "psx_types.h"

/* GTE/cop2 mnemonic overlay: ordinary C cannot emit coprocessor ops.
 * Verified by tools/match_function.py. */
__asm__(
    ".set noreorder\n"
    ".globl func_8012EF70\n"
    ".type func_8012EF70, @function\n"
    "func_8012EF70:\n"
    "addiu $sp, $sp, -0x20\n"
    "sw $s0, 0x18($sp)\n"
    "sw $ra, 0x1C($sp)\n"
    "addu $s0, $a1, $zero\n"
    "addiu $v1, $sp, 0x10\n"
    "mfc2 $t4, $19\n"
    "nop\n"
    "sra $t4, $t4, 2\n"
    "sw $t4, 0x0($v1)\n"
    "lw $v1, 0x10($sp)\n"
    "nop\n"
    "sh $v1, 0x4($s0)\n"
    "lw $ra, 0x1C($sp)\n"
    "lw $s0, 0x18($sp)\n"
    "addiu $sp, $sp, 0x20\n"
    "jr $ra\n"
    "nop\n"
    ".size func_8012EF70, .-func_8012EF70\n"
    ".set reorder\n"
);
