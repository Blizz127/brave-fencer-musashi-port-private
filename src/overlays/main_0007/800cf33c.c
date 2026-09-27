/* Overlay range [800CF33C,800CF390) from MAIN.CD member 0007.
 * SHA256(span)=a22f482be6a47ee3d769ed82a1ddfd7a712140eaf6ae76063b74a344caa7873e.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main_0007.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

s32 func_800167F0();                               /* extern */
extern s32 D_800D136C;
extern s32 D_800D1374;
void func_800CF6D0(s32, s32);                            /* static */

void func_800CF33C(void) {
    func_800CF6D0(D_800D136C, 0);
    if (func_800167F0(4) & 0xFFFF) {
        D_800D1374 = (s32) (D_800D1374 + 1);
    }
}
