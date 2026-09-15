/* Overlay range [8013F1BC,8013F244) from MAIN.CD member 0012.
 * SHA256(span)=e83706c5b7ed6054f55030692fbcfb72277de70db4baf2ca36a4736451b04d7c.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void func_800D2624();                                  /* extern */
extern u16 D_800B9A02;
extern u16 D_80115112;
extern u16 D_80115114;
extern u16 D_80115118;

void func_8013F1BC(void) {
    if ((D_80115118 == 0) || (D_80115118 -= 0x10, (D_80115118 == 0))) {
        if (D_80115114 == (D_800B9A02 ^ 1)) {
            func_800D2624();
            return;
        }
        D_80115112 += 1;
    }
}
