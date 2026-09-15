/* Main-exec range [80020A28,80020DA4) from the SLUS executable.
 * SHA256(span)=a3b7f4bf1a0c92de81cea08e1cb11b321360d518291906be1c759ce1b98e3cfa.
 * Word export only: the native seam executes the retail instruction
 * stream itself; this is not a C match claim. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void func_80020A70(s32);                               /* extern */

void func_80020A28(s32 arg1, s32 arg2, s32 arg3) {
    func_80020A70(arg2);
}
