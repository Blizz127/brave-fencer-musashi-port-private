/* Main-exec range [800120C4,800120DC) from the SLUS executable.
 * SHA256(span)=acbf2dbbf868f7d60f3237379d0fa12965040cc49d5228eb1c5f333dd38aa4f2.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
#include "psx_types.h"

#if defined(__mips__)
__asm__(
    ".set\tnoreorder\n"
    ".globl\tfunc_800120C4\n"
    ".ent\tfunc_800120C4\n"
    ".type\tfunc_800120C4, @function\n"
    "func_800120C4:\n"
    "move\t$sp, $fp\n"
    "lw\t$ra, 28($sp)\n"
    "lw\t$fp, 24($sp)\n"
    "addiu\t$sp, $sp, 32\n"
    "jr\t$ra\n"
    "nop\n"
    ".end\tfunc_800120C4\n"
    ".size\tfunc_800120C4, .-func_800120C4\n"
);
#else
void func_800120C4(void) {
}
#endif
