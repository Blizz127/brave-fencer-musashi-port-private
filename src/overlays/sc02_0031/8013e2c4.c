/* SC02.CD FILE_031 / ov_SC02_031 retail span [8013E2C4,8013E370).
 * Offset 0x1616C at overlay base 80128158. SHA256(span)=4f7e213e9439383457152597428668beab2b199bf194f5d25077be33a234cd6c.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/8013e2c4.c (recovery=assembly, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
#include "psx_types.h"

/* GTE/cop2 mnemonic overlay: ordinary C cannot emit coprocessor ops.
 * Verified by tools/match_function.py. */
__asm__(
    ".set noreorder\n"
    ".globl func_8013E2C4\n"
    ".type func_8013E2C4, @function\n"
    "func_8013E2C4:\n"
    "lui $v0,%hi(D_80126CAC)\n"
    "lh $v0,%lo(D_80126CAC)($v0)\n"
    "lh $v1,0x0($a0)\n"
    "addiu $sp,$sp,-0x20\n"
    "subu $v0,$v0,$v1\n"
    "sw $v0,0x0($sp)\n"
    "lui $v0,%hi(D_80126CAE)\n"
    "lh $v0,%lo(D_80126CAE)($v0)\n"
    "lh $v1,0x2($a0)\n"
    "nop\n"
    "subu $v0,$v0,$v1\n"
    "sw $v0,0x4($sp)\n"
    "lui $v0,%hi(D_80126CB0)\n"
    "lh $v0,%lo(D_80126CB0)($v0)\n"
    "lh $v1,0x4($a0)\n"
    "nop\n"
    "subu $v0,$v0,$v1\n"
    "sw $v0,0x8($sp)\n"
    "lwc2 $9,0x0($sp)\n"
    "lwc2 $10,0x4($sp)\n"
    "lwc2 $11,0x8($sp)\n"
    "nop\n"
    "nop\n"
    "addiu $v0,$sp,0x10\n"
    "swc2 $25,0x0($v0)\n"
    "swc2 $26,0x4($v0)\n"
    "swc2 $27,0x8($v0)\n"
    "lui $a2,0xFFF6\n"
    "ori $a2,$a2,0xFFFF\n"
    "lui $v0,0x1\n"
    "ori $v0,$v0,0x8FFE\n"
    "lw $v1,0x10($sp)\n"
    "lw $a0,0x14($sp)\n"
    "lw $a1,0x18($sp)\n"
    "addu $v1,$v1,$a0\n"
    "addu $v1,$v1,$a1\n"
    "addu $v1,$v1,$a2\n"
    "sltu $v0,$v0,$v1\n"
    "xori $v0,$v0,0x1\n"
    "addiu $sp,$sp,0x20\n"
    "jr $ra\n"
    "nop\n"
    ".size func_8013E2C4, .-func_8013E2C4\n"
    ".set reorder\n"
);
