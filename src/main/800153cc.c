/* Main-exec range [800153CC,80015424) from the SLUS executable.
 * SHA256(span)=b796f3d8ea24ba71b6ee92da079f9ddbecf9bd5ada924e29c0f392af373dee9b.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void func_80015424(void *, s16, s16, s32, s32);        /* static */
extern s32 *D_800AF630;

void func_800153CC(s32 arg0, s16 arg2, s16 arg3, u8 arg4, u8 arg5) {
    func_80015424(((s32) (arg0 << 0x10) >> 0xC) + 0x9DA8 + &D_800AF630, arg2, arg3, (s32) arg4, (s32) arg5);
}
