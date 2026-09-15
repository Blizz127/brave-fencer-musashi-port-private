/* Main-exec range [800603BC,80060404) from the SLUS executable.
 * SHA256(span)=43267bf995bb26c435abcc39e2d68f7f66229b8961e243e64196e442ae7fa2f8.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void func_80061F68(s32);                               /* static */
extern s32 D_80078C90;

void func_800603BC(void) {
    if (D_80078C90 >= 0) {
        func_80061F68(D_80078C90);
        D_80078C90 = -1;
    }
}
