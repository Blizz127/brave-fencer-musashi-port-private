/* Main-exec range [80061024,80061114) from the SLUS executable.
 * SHA256(span)=116617f5dbcb5bd1655da7b2f1a1f50ad16107361406a7940fe9a5ff7cabf438.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

extern s32 *D_80078C80;
extern s32 D_80078C84;
extern s32 D_80078C88;
extern s32 D_80078CC4;
extern s32 D_80078CC8;

s32 func_80061024(s32 arg0, s32 *arg1, s32 *arg2) {
    s32 var_v0;

    if ((M2C_FIELD(&D_80078C80, s32 *, 0) != 0) || (var_v0 = -1, (D_80078C88 != 0))) {
        if (arg0 == 0) {
            if (D_80078C88 == 0) {
                do {

                } while (M2C_FIELD(&D_80078C80, s32 *, 8) == 0);
            }
            goto block_11;
        }
        if (D_80078C88 == 0) {
            if (arg2 != 0) {
                *arg2 = D_80078C84;
            }
            var_v0 = 0;
            if (arg1 != 0) {
                *arg1 = M2C_FIELD(&D_80078C80, s32 *, 0);
                return 0;
            }
            /* Duplicate return node #16. Try simplifying control flow for better match */
            return var_v0;
        }
block_11:
        if (arg2 != 0) {
            *arg2 = D_80078CC8;
        }
        if (arg1 != 0) {
            *arg1 = D_80078CC4;
        }
        D_80078C88 = 0;
        var_v0 = 1;
        /* Duplicate return node #16. Try simplifying control flow for better match */
        return var_v0;
    }
    return var_v0;
}
