/* Overlay range [801651B8,80165240) from MAIN.CD member 0012.
 * SHA256(span)=387c6b9c6fd8f333e75d2585e224e32ecc0058c5a755e17bd1542811389f2492.
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
void func_80165240(s32, s32 (*)(), void *);              /* static */

void func_801651B8(s32 arg0) {
    s32 (*var_s0)();
    s32 var_s1;

    func_80165240(arg0 + 0x2C, arg0 + 0x50);
    var_s1 = 0;
    var_s0 = D_80184398;
    do {
        if (var_s0->unkC != 0) {
            func_80165240(arg0, var_s0, var_s0 + 8);
            var_s0->unkC = (s32) (var_s0->unkC - 1);
        }
        var_s1 += 1;
        var_s0 += 0x10;
    } while (var_s1 < 8);
}
