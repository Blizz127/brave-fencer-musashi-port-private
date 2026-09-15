/* Overlay range [801612B8,8016130C) from MAIN.CD member 0012.
 * SHA256(span)=7ba46055884c2bcca8d1a5e12724bddaca8530085ccf59dda897a015fd5ae973.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

s32 func_8014CC28(s32);                             /* static */
void func_8014E934(s32);                               /* static */
s32 func_8014F3E8(s32);                             /* static */

s32 func_801612B8(s32 arg0, s32 arg1) {
    s32 temp_a1;
    s32 temp_s0;

    temp_a1 = arg1 & 1;
    if (temp_a1 == 0) {
        func_8014E934(temp_a1);
    }
    temp_s0 = func_8014CC28(arg0);
    return temp_s0 | func_8014F3E8(arg0);
}
