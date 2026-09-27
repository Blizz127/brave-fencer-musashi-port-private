/* Main-exec range [8001094C,8001096C) from the SLUS executable.
 * SHA256(span)=4f333c8fc41b9063a42c85d18b5b1eca22b56a3d956ecbda8ee5ce4e09dce466.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
#include "psx_types.h"

#if defined(__mips__)
__asm__(
    ".set\tnoreorder\n"
    ".globl\tfunc_8001094C\n"
    ".ent\tfunc_8001094C\n"
    ".type\tfunc_8001094C, @function\n"
    "func_8001094C:\n"
    "move\t$sp, $fp\n"
    "lw\t$ra, 52($sp)\n"
    "lw\t$fp, 48($sp)\n"
    "lw\t$s1, 44($sp)\n"
    "lw\t$s0, 40($sp)\n"
    "addiu\t$sp, $sp, 56\n"
    "jr\t$ra\n"
    "nop\n"
    ".end\tfunc_8001094C\n"
    ".size\tfunc_8001094C, .-func_8001094C\n"
);
#else
void func_8001094C(void) {
}
#endif
