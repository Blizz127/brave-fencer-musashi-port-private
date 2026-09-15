/* Overlay range [801496D4,80149704) from MAIN.CD member 0012.
 * SHA256(span)=f348aa0b3a05a3e24c0ee52e4112903613d116fc07b772d70336b84cb27f5d5a.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

s32 func_801496D4(void *arg0) {
    s32 var_v0;

    var_v0 = 0;
    if (M2C_FIELD(arg0, s32 *, 0x178) == 0) {
        var_v0 = M2C_FIELD(arg0, u16 *, 0xAC) & 0x40;
        if (var_v0 != 0) {
            var_v0 = 1;
        }
    }
    return var_v0;
}
