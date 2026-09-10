#include "psx_types.h"

/* Exact saved-context stream used by the bounded native callback diagnostic. */

/* Retail saved-context capture: 48-byte PS1 register record.
 * This source overlay is not a host setjmp/longjmp implementation. */
__asm__(
    ".set noreorder\n"
    ".globl func_8005CD98\n"
    ".type func_8005CD98, @function\n"
    "func_8005CD98:\n"
    "sw $ra,0($a0)\n"
    "sw $gp,44($a0)\n"
    "sw $sp,4($a0)\n"
    "sw $fp,8($a0)\n"
    "sw $s0,12($a0)\n"
    "sw $s1,16($a0)\n"
    "sw $s2,20($a0)\n"
    "sw $s3,24($a0)\n"
    "sw $s4,28($a0)\n"
    "sw $s5,32($a0)\n"
    "sw $s6,36($a0)\n"
    "sw $s7,40($a0)\n"
    "addu $v0,$zero,$zero\n"
    "jr $ra\n"
    "nop\n"
    ".size func_8005CD98, .-func_8005CD98\n"
    ".set reorder\n"
);
