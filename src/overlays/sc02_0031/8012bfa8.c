/* SC02.CD FILE_031 / ov_SC02_031 retail span [8012BFA8,8012C044).
 * Offset 0x3E50 at overlay base 80128158. SHA256(span)=91ebad4cb511bfb5db3829ffadeeb82946d7661985379bb60eebf8a692558be3.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/8012bfa8.c (recovery=assembly, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
#include "psx_types.h"

/* GTE/cop2 mnemonic overlay: ordinary C cannot emit coprocessor ops.
 * Verified by tools/match_function.py. */
__asm__(
    ".set noreorder\n"
    ".globl func_8012BFA8\n"
    ".type func_8012BFA8, @function\n"
    "func_8012BFA8:\n"
    "lui $v0, %hi(D_80126CAC)\n"
    "lh $v0, %lo(D_80126CAC)($v0)\n"
    "lh $v1, 0x6($a0)\n"
    "addiu $sp, $sp, -0x20\n"
    "subu $v0, $v0, $v1\n"
    "sw $v0, 0x0($sp)\n"
    "lui $v0, %hi(D_80126CAE)\n"
    "lh $v0, %lo(D_80126CAE)($v0)\n"
    "lh $v1, 0xA($a0)\n"
    "nop\n"
    "subu $v0, $v0, $v1\n"
    "sw $v0, 0x4($sp)\n"
    "lui $v0, %hi(D_80126CB0)\n"
    "lh $v0, %lo(D_80126CB0)($v0)\n"
    "lh $v1, 0xE($a0)\n"
    "nop\n"
    "subu $v0, $v0, $v1\n"
    "sw $v0, 0x8($sp)\n"
    "lwc2 $9, 0x0($sp)\n"
    "lwc2 $10, 0x4($sp)\n"
    "lwc2 $11, 0x8($sp)\n"
    "nop\n"
    "nop\n"
    "addiu $v0, $sp, 0x10\n"
    "swc2 $25, 0x0($v0)\n"
    "swc2 $26, 0x4($v0)\n"
    "swc2 $27, 0x8($v0)\n"
    "lui $a1, (0xFFFFF >> 16)\n"
    "ori $a1, $a1, (0xFFFFF & 0xFFFF)\n"
    "lw $v0, 0x10($sp)\n"
    "lw $v1, 0x14($sp)\n"
    "lw $a0, 0x18($sp)\n"
    "addu $v0, $v0, $v1\n"
    "addu $v0, $v0, $a0\n"
    "slt $v0, $a1, $v0\n"
    "addiu $sp, $sp, 0x20\n"
    "jr $ra\n"
    "nop\n"
    ".size func_8012BFA8, .-func_8012BFA8\n"
    ".set reorder\n"
);
