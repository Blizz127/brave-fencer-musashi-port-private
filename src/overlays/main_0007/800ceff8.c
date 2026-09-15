/* Overlay range [800CEFF8,800CF02C) from MAIN.CD member 0007.
 * SHA256(span)=5050b71448420e8081ca7b915e579cfa2615e27166fd5ee2142eae687917ea7f.
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
extern s16 D_800B99E6;

void func_800CEFF8(void) {
    if (func_800167F0(4) & 0xFFFF) {
        D_800B99E6 = 1;
    }
}
