/* Exact retail word export for [8005CF38,8005CF44); EXE and assembly verified. */
#include "psx_types.h"

/* Byte-exact BIOS vector thunk [8005CF38,8005CF44).
 * The retail body loads the B0 vector and BIOS write selector 35h, then
 * returns through the vector.  Keep the delay slot explicit: the assembler's
 * default reordering would insert a nop and break the match. */
__asm__(
    ".set noreorder\n"
    ".globl func_8005CF38\n"
    ".type func_8005CF38, @function\n"
    "func_8005CF38:\n"
    "addiu $t2, $zero, 0xB0\n"
    "jr    $t2\n"
    "addiu $t1, $zero, 0x35\n"
    ".size func_8005CF38, .-func_8005CF38\n"
    ".set reorder\n"
);
