/* Main-exec range [80011E10,80011E24) from the SLUS executable.
 * SHA256(span)=62f0fee431a91fb9ec6acebb2bed976bb4878f0c2039b29a4b09ccbcc70ffe6f.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
#include "psx_types.h"

__asm__(
    ".set\tnoreorder\n"
    ".globl\tfunc_80011E10\n"
    ".ent\tfunc_80011E10\n"
    ".type\tfunc_80011E10, @function\n"
    "func_80011E10:\n"
    "move\t$sp, $fp\n"
    "lw\t$fp, 0($sp)\n"
    "addiu\t$sp, $sp, 8\n"
    "jr\t$ra\n"
    "nop\n"
    ".end\tfunc_80011E10\n"
    ".size\tfunc_80011E10, .-func_80011E10\n"
);
