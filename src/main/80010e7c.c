/* Main-exec range [80010E7C,80010ED4) from the SLUS executable.
 * SHA256(span)=fee8a8470b095bda8275f7dda272f5c41f34c8acf292f5c7538a726b4aabcc11.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void func_8002D4C8(s32, s32);            /* static */
extern s32 *D_800AF630;

void func_80010E7C(void) {
    func_8002D4C8(2, 0);
    M2C_FIELD(&D_800AF630, s16 *, 0xA3D4) = 1;
}
