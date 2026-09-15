/* Main-exec range [80043528,8004355C) from the SLUS executable.
 * SHA256(span)=a3e99ba544ede2d2c25b31770bf36d76ef8f0d95aa7003fda50e53f0177d70c5.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

extern s32 D_8006CD2C;
extern s32 D_80073614;

s32 func_80043528(s32 arg0) {
    u32 temp_a0;

    temp_a0 = arg0 & 0xFF;
    if (temp_a0 < 7U) {
        return *(D_8006CD2C + (temp_a0 * 4));
    }
    return D_80073614;
}
