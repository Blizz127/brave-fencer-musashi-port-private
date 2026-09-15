/* Overlay range [8015640C,801564B0) from MAIN.CD member 0012.
 * SHA256(span)=0ccf92b7d46f0909909836120e61de2c556d4a8f6159382be99c1d15c3cc9ee4.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

s32 func_80029178();                               /* extern */
s32 func_801564B0();                                /* static */

s32 func_8015640C(s32 arg1) {
    s32 var_v0;
    s32 var_v1;

    var_v0 = arg1 & 0xFFFF;
    if (func_801564B0() & 0xFFFF) {
        if (func_80029178(0x1C) & 0xFF) {
            var_v1 = (arg1 & 0xFFFF) * 0xAF;
        } else {
            var_v1 = (arg1 & 0xFFFF) * 0x96;
        }
        var_v0 = ((var_v1 / 100) & 0xFFFF) | 0x8000;
    }
    return var_v0;
}
