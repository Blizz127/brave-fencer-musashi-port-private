/* Main-exec range [80011998,800119F0) from the SLUS executable.
 * SHA256(span)=989a6c490195f84193c72e06c28670d63fa37ac91dfe9ecfc929ffb4e4853ce0.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

extern s32 *D_800AF630;

void func_80011998(void) {
    M2C_FIELD(&D_800AF630, u16 *, 0xA3BA) = (u16) (M2C_FIELD(&D_800AF630, u16 *, 0xA3BA) + 1);
    M2C_FIELD(&D_800AF630, s16 *, 0xA3BC) = 0;
}
