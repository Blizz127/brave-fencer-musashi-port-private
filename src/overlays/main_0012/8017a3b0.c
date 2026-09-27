/* Overlay range [8017A3B0,8017A3D8) from MAIN.CD member 0012.
 * SHA256(span)=878e8b2edd286fa3aae75824e44ed9a2b5c02333c6adde8b377bf90f64ba6574.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

extern s32 D_80185348;

s32 func_8017A3B0(void) {
    s32 var_v0;

    var_v0 = 1;
    if ((D_80185348 != 0) && (D_80185348 == 1)) {
        var_v0 = 0;
    }
    return var_v0;
}
