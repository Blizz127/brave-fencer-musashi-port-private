/* Main-exec range [800304C8,80030538) from the SLUS executable.
 * SHA256(span)=c4bfc73944f5a101c1aa33269e7964c3d6a783f19885e1e0731e3be0f8111ace.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

s32 func_8003C4F0();                               /* static */
extern u8 D_8006AEF4;
extern u16 D_800A46CC;

s32 func_800304C8(void) {
    if (D_8006AEF4 & 1) {
        if (func_8003C4F0(0) != 0) {
            D_8006AEF4 &= 0xFE;
        }
    } else {
        D_800A46CC += 1;
    }
    return 0;
}
