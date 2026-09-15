/* Main-exec range [80010110,80010178) from the SLUS executable.
 * SHA256(span)=422b7e8743ae79493a90d8582626284dcfb0df9651369976f7ad57a8a8c9672e.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

extern s32 D_80062998;
extern s32 func_80010000;

void func_80010110(void) {
    s32 (*temp_t0)();
    s32 (*var_s0)();
    s32 var_s1;

    if (D_80062998 != 0) {
        var_s0 = func_80010000;
        var_s1 = 0;
        if (0 != 0) {
            do {
                temp_t0 = *var_s0;
                var_s0 += 4;
                var_s1 -= 1;
                temp_t0();
            } while (var_s1 != 0);
        }
    }
}
