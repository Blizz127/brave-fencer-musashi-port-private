/* Main-exec range [80010938,8001094C) from the SLUS executable.
 * SHA256(span)=b83875baf4d20f898459ac773bb45f161e3cdc99b712c9eaeabfa99322330aad.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
#include "psx_types.h"

#if defined(__mips__)
__asm__(
    ".set\tnoreorder\n"
    ".globl\tfunc_80010938\n"
    ".ent\tfunc_80010938\n"
    ".type\tfunc_80010938, @function\n"
    "func_80010938:\n"
    "move\t$a0, $zero\n"
    "jal\tfunc_80042610\n"
    "nop\n"
    "j\tfunc_80010204\n"
    "nop\n"
    ".end\tfunc_80010938\n"
    ".size\tfunc_80010938, .-func_80010938\n"
);
#else
void func_80042610(s32);
void func_80010204(void);

void func_80010938(void) {
    func_80042610(0);
    func_80010204();
}
#endif
