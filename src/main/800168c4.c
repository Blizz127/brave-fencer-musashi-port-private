/* Main-exec range [800168C4,80016940) from the SLUS executable.
 * SHA256(span)=18c21b1c7ee0a0876e79f705b5b11a8fbbac423623fa7388faed5cada54c90dc.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

extern s32 D_80062BA0[];
extern s32 *D_800AF630;
extern u16 D_800AF7CE;
extern s32 D_800B9A18;

s32 func_800168C4(s32 arg0) {
    s32 temp_a0;
    s32 var_v0;
    u8 var_v1;

    temp_a0 = arg0 & 3;
    if (temp_a0 == 0) {
        var_v1 = *(D_80062BA0 + D_800B9A18);
    } else {
        var_v1 = *(D_80062BA0 + temp_a0);
    }
    D_800AF7CE += var_v1;
    var_v0 = 0;
    if ((u16) M2C_FIELD(&D_800AF630, u16 *, 0x19E) >= 0xFFU) {
        var_v0 = M2C_FIELD(&D_800AF630, u16 *, 0x188) != 0;
    }
    return var_v0;
}
