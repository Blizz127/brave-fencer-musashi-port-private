/* Main-exec range [8005C540,8005C584) from the SLUS executable.
 * SHA256(span)=83f1261096a02f2dc5770b577c92ace41c327074183dfadcb9fbd23ab14c3a89.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

u8 *func_8005C540(u8 *arg0, u8 *arg1) {
    u8 *var_a0;
    u8 *var_a1;
    u8 *var_v0;
    u8 temp_v0;
    u8 temp_v0_2;

    var_v0 = 0;
    if ((arg0 != 0) && (arg1 != 0)) {
        temp_v0 = *arg1;
        var_a1 = arg1 + 1;
        var_a0 = arg0 + 1;
        *arg0 = temp_v0;
        if (temp_v0 != 0) {
            do {
                temp_v0_2 = *var_a1;
                var_a1 += 1;
                *var_a0 = temp_v0_2;
                var_a0 += 1;
            } while (temp_v0_2 != 0);
        }
        var_v0 = arg0;
    }
    return var_v0;
}
