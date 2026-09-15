/* Native retail instruction export [8005D6CC,8005D734).
 * Verified against asm/main.s and the extracted EXE. No C match claim. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void D_80072984();                               /* static */
extern s32 D_800729BC;

s32 func_8005D6CC(void) {
    s32 var_v0;

    var_v0 = 0;
    if (M2C_FIELD(D_800729BC, s32 *, 4) & 1) {
        var_v0 = 0;
        if (M2C_FIELD(D_800729BC, s32 *, 0) & 1) {
            if (D_80072984 != 0) {
                D_80072984();
            }
            var_v0 = 1;
        }
    }
    return var_v0;
}
