#include "psx_types.h"

extern s32 func_80043450(s32);
extern void func_8004359C(void *);
extern void func_800435B4(void *);
extern void func_8004654C(void *);
extern void func_80046564(s32);
extern s32 func_8005C604(const char *);
extern void func_80043398(void);
extern void func_800433C0(void);
extern void func_800433E8(void);
extern char D_800735FC[];

/* Retail's branch layout is not reproduced by equivalent structured C, so
 * retain the source-backed instruction form for this small startup dispatcher. */
__asm__(
    ".set noreorder\n"
    ".globl func_80043300\n"
    ".type func_80043300, @function\n"
    "func_80043300:\n"
    "addiu $sp, $sp, -0x18\n"
    "sw    $s0, 0x10($sp)\n"
    "addiu $s0, $zero, 4\n"
    "sw    $ra, 0x14($sp)\n"
    ".L43300_retry:\n"
    "addiu $a0, $zero, 1\n"
    "addiu $v1, $zero, 1\n"
    "addiu $s0, $s0, -1\n"
    "lui   $a0, 0x8004\n"
    "addiu $a0, $a0, 0x3398\n"
    "nop\n"
    "lui   $a0, 0x8004\n"
    "addiu $a0, $a0, 0x33c0\n"
    "nop\n"
    "lui   $a0, 0x8004\n"
    "addiu $a0, $a0, 0x33e8\n"
    "nop\n"
    "move  $a0, $zero\n"
    "addiu $v0, $zero, 1\n"
    ".L43300_failed:\n"
    "addiu $v0, $zero, -1\n"
    "nop\n"
    "lui   $a0, 0x8007\n"
    "addiu $a0, $a0, 0x35fc\n"
    "nop\n"
    "move  $v0, $zero\n"
    ".L43300_return_one:\n"
    "lw    $ra, 0x14($sp)\n"
    "lw    $s0, 0x10($sp)\n"
    "addiu $sp, $sp, 0x18\n"
    "jr    $ra\n"
    "nop\n"
    ".size func_80043300, .-func_80043300\n"
    ".set reorder\n"
);

