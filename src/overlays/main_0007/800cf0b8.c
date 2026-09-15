/* Overlay range [800CF0B8,800CF0F4) from MAIN.CD member 0007.
 * SHA256(span)=4ad4c0542204db911789176d73f5192759005807adb9f7d1be6964e94ae41db0.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main_0007.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

extern s32 D_800D1344;
extern s32 D_800D1374;

void func_800CF0B8(void) {
    *(D_800D1344 + (D_800D1374 * 4))();
}
