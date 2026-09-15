/* Overlay range [8013A9F8,8013AA24) from MAIN.CD member 0012.
 * SHA256(span)=f0579ddda68d5a018cb893d350abcdc60236852c2d441a4887000fa0e7bc77ba.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void func_8013A9F8(void *arg0, s32 arg1) {
    if ((u32) ((arg1 - 2) & 0xFFFF) < 5U) {
        M2C_FIELD(arg0, s16 *, 0xE) = (s16) (((arg1 & 0xFFFF) - 2) << 0xA);
    }
}
