/* Main-exec range [80011664,80011680) from the SLUS executable.
 * SHA256(span)=5f52a18a295a4ef28791b24fdab6465133c3424044afb7538919db4b6542c0aa.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
#include "psx_types.h"

#if defined(__mips__)
__asm__(
    ".set\tnoreorder\n"
    ".globl\tfunc_80011664\n"
    ".ent\tfunc_80011664\n"
    ".type\tfunc_80011664, @function\n"
    "func_80011664:\n"
    "move\t$sp, $fp\n"
    "lw\t$ra, 32($sp)\n"
    "lw\t$fp, 28($sp)\n"
    "lw\t$s0, 24($sp)\n"
    "addiu\t$sp, $sp, 40\n"
    "jr\t$ra\n"
    "nop\n"
    ".end\tfunc_80011664\n"
    ".size\tfunc_80011664, .-func_80011664\n"
);
#else
void func_80011664(void) {
}
#endif
