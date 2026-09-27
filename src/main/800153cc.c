/* Main-exec range [800153CC,80015424) from the SLUS executable.
 * SHA256(span)=b796f3d8ea24ba71b6ee92da079f9ddbecf9bd5ada924e29c0f392af373dee9b.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
#include "psx_types.h"

#if defined(__mips__)
__asm__(
    ".set\tnoreorder\n"
    ".globl\tfunc_800153CC\n"
    ".ent\tfunc_800153CC\n"
    ".type\tfunc_800153CC, @function\n"
    "func_800153CC:\n"
    ".end\tfunc_800153CC\n"
    ".size\tfunc_800153CC, .-func_800153CC\n"
);
#else
void func_80015424(void *, s16, s16, s32, s32);
extern s32 *D_800AF630;

void func_800153CC(s32 arg0, s16 arg2, s16 arg3, u8 arg4, u8 arg5) {
    func_80015424(((s32) (arg0 << 0x10) >> 0xC) + 0x9DA8 + &D_800AF630, arg2, arg3, (s32) arg4, (s32) arg5);
}
#endif
