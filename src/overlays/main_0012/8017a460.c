/* Overlay range [8017A460,8017A4AC) from MAIN.CD member 0012.
 * SHA256(span)=23556cfe52175f45dd6e6d8a276cddfa500db58932648b591608bbe3c2bd66b9.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

extern s32 D_80185384;

s32 func_8017A460(s32 arg4) {
    u16 temp_v0;

    temp_v0 = D_80185384 + 1;
    D_80185384 = temp_v0;
    if ((s16) temp_v0 >= 0x1E) {
        D_80185384 = 0x64U;
    }
    return 0;
}
