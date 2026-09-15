/* Overlay range [8014C168,8014C1A0) from MAIN.CD member 0012.
 * SHA256(span)=a615915d45cbd5c945ebf1504dd8e9a8a15164794ccde48f6316ee4834150bf7.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

extern u16 D_801202A0;

u16 *func_8014C168(s32 arg1) {
    u16 *var_v0;
    u16 *var_v1;
    u32 var_a0;

    var_a0 = 0;
    var_v1 = &D_801202A0;
loop_1:
    var_v0 = var_v1;
    if (*var_v1 != arg1) {
        var_a0 += 1;
        var_v1 += 0x10C;
        if (var_a0 >= 0x60U) {
            var_v0 = 0;
        } else {
            goto loop_1;
        }
    }
    return var_v0;
}
