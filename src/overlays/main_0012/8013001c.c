/* Overlay range [8013001C,80130088) from MAIN.CD member 0012.
 * SHA256(span)=b61ee6990ed95195de8478fa14af5f92fe95aa953aa8d1f206edf177a110443c.
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

void func_8013001C(s32 arg0) {
    s32 var_a1;
    if (func_8012BCCC() <= 0x8FFF) {
        if (func_80131AC8(arg0, 0x30) == 0) {
            var_a1 = 0x31;
            goto block_5;
        }
    } else if (func_80131AC8(arg0, 0x31) == 0) {
        var_a1 = 0x30;
block_5:
        func_80131AC8(arg0, var_a1);
    }
}
