/* Main-exec range [8002A1B4,8002A200) from the SLUS executable.
 * SHA256(span)=85447d38de075cb556948414a0a0b8175c0f800933e33c289858910506f02151.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

s32 func_8002A26C();                                /* static */
s32 func_8002A27C();                                /* static */
s32 func_8002A28C();                                /* static */
s32 func_8002AA00(s32);                             /* static */

s32 func_8002A1B4(void) {
    s32 temp_s0;
    s32 var_v0;

    var_v0 = 0;
    if (func_8002AA00(func_8002A26C() + 1) != 0) {
        temp_s0 = func_8002A27C();
        var_v0 = temp_s0 == func_8002A28C();
    }
    return var_v0;
}
