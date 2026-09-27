/* Overlay range [80165140,801651B8) from MAIN.CD member 0012.
 * SHA256(span)=ea6f85930a93c01b4a4a4dcc2011309efce84bfb89c0bb18359322bf75062d80.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

extern s32 D_80184398;

void func_80165140(void *arg0) {
    s32 (*var_a2)();
    s32 var_v1;

    var_v1 = 0;
    var_a2 = D_80184398;
loop_1:
    var_v1 += 1;
    if (var_a2->unkC == 0) {
        var_a2->unkC = 8;
        var_a2->unk3 = (unaligned s32) M2C_ERROR(/* Unable to handle lwr; missing a corresponding lwl */);
        var_a2->unk7 = (unaligned s32) M2C_ERROR(/* Unable to handle lwr; missing a corresponding lwl */);
        var_a2->unkB = (unaligned s32) M2C_ERROR(/* Unable to handle lwr; missing a corresponding lwl */);
        return;
    }
    var_a2 += 0x10;
    if (var_v1 >= 8) {
        return;
    }
    goto loop_1;
}
