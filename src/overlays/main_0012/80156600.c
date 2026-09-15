/* Overlay range [80156600,80156648) from MAIN.CD member 0012.
 * SHA256(span)=ab9145429a2387cd66af6d2d74ddc7b5befce9f1cdf07e2f7e138d4fc9644639.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

extern s32 *D_801151E0;
extern s32 *D_80126AF0;

void *func_80156600(void) {
    void *var_a1;
    void *var_v0;
    s32 *var_v1;
    u32 var_a0;

    var_a0 = 0;
    var_a1 = &D_80126AF0;
    var_v1 = &D_801151E0;
loop_1:
    var_v0 = var_a1;
    if (!(*var_v1 & 1)) {
        var_a1 += 8;
        var_a0 += 1;
        var_v1 += 4;
        if (var_a0 >= 3U) {
            var_v0 = 0;
        } else {
            goto loop_1;
        }
    }
    return var_v0;
}
