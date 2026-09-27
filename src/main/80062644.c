/* Main-exec range [80062644,80062684) from the SLUS executable.
 * SHA256(span)=6579cca9ab8165068fcc93cc35e3181226c57d97db63e645c24e1e0f20a0dcdb.
 * Word export for the native seam (m2c produced no draft). */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

extern s32 D_80072A2C;

s32 func_80062644(void) {
    s32 var_v0;

    var_v0 = 0;
    if (M2C_FIELD(D_80072A2C, s32 *, 4) & 1) {
        var_v0 = 1;
        if (!(M2C_FIELD(D_80072A2C, s32 *, 0) & 1)) {
            var_v0 = 0;
        }
    }
    return var_v0;
}
