/* Overlay range [80130088,801300F4) from MAIN.CD member 0012.
 * SHA256(span)=a8c2d8590c6ff08df34ddae94130e50a5368c734aaa46f06406f7ed012930430.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

s32 func_8012BCCC();                                /* static */
s32 func_80131AC8(s32, s32);                          /* static */

void func_80130088(s32 arg0) {
    s32 var_a1;
    if (func_8012BCCC() <= 0x8FFF) {
        if (func_80131AC8(arg0, 0x32) == 0) {
            var_a1 = 0x33;
            goto block_5;
        }
    } else if (func_80131AC8(arg0, 0x33) == 0) {
        var_a1 = 0x32;
block_5:
        func_80131AC8(arg0, var_a1);
    }
}
