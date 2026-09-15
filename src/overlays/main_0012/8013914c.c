/* Overlay range [8013914C,801391F0) from MAIN.CD member 0012.
 * SHA256(span)=8868c2714bb1d5a336d07d383494d1db1f8f7d9402233a8f4bcc4d04f17b2fac.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

s32 func_80139220();                                /* static */

s32 func_8013914C(void *arg0, void *arg1) {
    s32 var_v0;

    if (((s32) M2C_FIELD(arg0, u16 *, 0x14) < M2C_FIELD(arg0, s16 *, 0x2C)) || (var_v0 = 1, (func_80139220() == 0))) {
        M2C_FIELD(arg1, s16 *, 0) = (s16) (M2C_FIELD(arg0, u16 *, 0x38) + ((u32) (M2C_FIELD(arg0, u16 *, 0x14) * 3) >> 1));
        M2C_FIELD(arg1, s16 *, 2) = (s16) (M2C_FIELD(arg0, u16 *, 0x3A) + (M2C_FIELD(arg0, u16 *, 0x12) * 0xC));
        var_v0 = 0;
        M2C_FIELD(arg0, u16 *, 0x14) = (u16) (M2C_FIELD(arg0, u16 *, 0x14) + 1);
    }
    return var_v0;
}
