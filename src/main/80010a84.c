/* Exact retail word export for [80010A84,80010A98); EXE and assembly verified. */
#include "psx_types.h"

__asm__(
    ".set\tnoreorder\n"
    ".globl\tfunc_80010A84\n"
    ".ent\tfunc_80010A84\n"
    ".type\tfunc_80010A84, @function\n"
    "func_80010A84:\n"
    "move\t$sp, $fp\n"
    "lw\t$fp, 8($sp)\n"
    "addiu\t$sp, $sp, 16\n"
    "jr\t$ra\n"
    "nop\n"
    ".end\tfunc_80010A84\n"
    ".size\tfunc_80010A84, .-func_80010A84\n"
);
