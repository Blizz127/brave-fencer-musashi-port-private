/* Main-exec range [8001136C,80011380) from the SLUS executable.
 * SHA256(span)=62f0fee431a91fb9ec6acebb2bed976bb4878f0c2039b29a4b09ccbcc70ffe6f.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
#include "psx_types.h"

#if defined(__mips__)
__asm__(
    ".set\tnoreorder\n"
    ".globl\tfunc_8001136C\n"
    ".ent\tfunc_8001136C\n"
    ".type\tfunc_8001136C, @function\n"
    "func_8001136C:\n"
    "move\t$sp, $fp\n"
    "lw\t$fp, 0($sp)\n"
    "addiu\t$sp, $sp, 8\n"
    "jr\t$ra\n"
    "nop\n"
    ".end\tfunc_8001136C\n"
    ".size\tfunc_8001136C, .-func_8001136C\n"
);
#else
void func_8001136C(void) {
}
#endif
