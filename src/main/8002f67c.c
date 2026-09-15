/* Main-exec range [8002F67C,8002F714) from the SLUS executable.
 * SHA256(span)=d1bfb59f95dd2f0c91c1401575c77d0f3fc6b54d51b80b079bc320a4e9e3a426.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void func_800415A8(s16);                               /* static */
extern s16 D_800A4688;
extern u8 D_800A4698;
extern s16 D_800A46A2;
extern u8 D_800A46B0;
extern s32 *D_800C5328;

void func_8002F67C(void) {
    if (D_800A4698 == 0) {
        *(&D_800C5328 + (D_800A4688 * 4)) = -1;
        D_800A4698 = 1;
    }
    if (D_800A46A2 >= 0) {
        func_800415A8(D_800A46A2);
        D_800A46A2 = -1;
    }
    if (D_800A46B0 == 0) {
        D_800A46B0 = 1;
    }
}
