/* Overlay range [800CF220,800CF268) from MAIN.CD member 0007.
 * SHA256(span)=7169d0c7518323f28010fcb53fcbd7e3eb289dd84dfb927056e73fa6cfdf2d57.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main_0007.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void func_800167B8();                                 /* extern */
void func_8001AA98(s32 (*)());                           /* extern */
extern s32 D_800CEE14;
extern s32 D_800D1374;

void func_800CF220(void) {
    func_8001AA98(D_800CEE14);
    func_800167B8(0);
    D_800D1374 = (s32) (D_800D1374 + 1);
}
