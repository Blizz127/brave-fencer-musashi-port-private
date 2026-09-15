/* Overlay range [8012C284,8012C2D0) from MAIN.CD member 0012.
 * SHA256(span)=52a25608f3f8af9aa0d53700f62225c99f6bfba1119ed66e45543cb276f8a828.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

extern s32 *D_80126720;

u16 *func_8012C284(s32 arg0) {
    u16 *var_a0;

    var_a0 = arg0 + 0x10C;
    if (arg0 == 0) {
        var_a0 = &D_80126720 - 0x6480;
    }
    if (var_a0 != &D_80126720) {
loop_4:
        if (*var_a0 != 0) {
            var_a0 += 0x10C;
            if (var_a0 == &D_80126720) {
                /* Duplicate return node #6. Try simplifying control flow for better match */
                return 0;
            }
            goto loop_4;
        }
        return var_a0;
    }
    return 0;
}
