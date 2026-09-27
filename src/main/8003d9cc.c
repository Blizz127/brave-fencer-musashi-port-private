/* Main-exec range [8003D9CC,8003DA1C) from the SLUS executable.
 * SHA256(span)=6e80098d10569f4ef6e4048dfcc17639c124f9a303c3233806cf3dd041fbb7bf.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void D_8006B8EC();                                     /* static */
extern s32 D_8006B8F8;

void func_8003D9CC(void) {
    if (D_8006B8F8 == 0) {
        D_8006B8F8 = 1;
        return;
    }
    D_8006B8F8 = 0;
    D_8006B8EC();
}
