/* Overlay range [80130AC4,80130AF0) from MAIN.CD member 0012.
 * SHA256(span)=4b9f6f0a654e99d336acfecd56cb2ac06856f885fde283fbbc8e2d3cda517f0d.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void func_80130AC4(void *arg0) {
    u16 temp_v0;

    temp_v0 = M2C_FIELD(arg0, u16 *, 0xAC) - 1;
    M2C_FIELD(arg0, u16 *, 0xAC) = temp_v0;
    if ((temp_v0 << 0x10) == 0) {
        M2C_FIELD(arg0, s8 *, 0xC1) = 0;
        M2C_FIELD(arg0, s16 *, 0x5E) = 0;
    }
}
