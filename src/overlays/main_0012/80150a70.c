/* Overlay range [80150A70,80150B28) from MAIN.CD member 0012.
 * SHA256(span)=cd1b661b1d6d9a6a376bb9473c882e55c1ab651cf55221b397bad7630234b676.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void func_80015978(void *, void *);                    /* extern */
extern s32 D_8018424C;
s32 func_8014FA70(void *, s32);                       /* static */

void func_80150A70(void *arg0) {
    void *var_a0;

    if ((arg0->unk6 != arg0->unk88) || (arg0->unkA != arg0->unk8A) || (arg0->unkE != arg0->unk8C)) {
        var_a0 = arg0 + 4;
        if (!(arg0->unk44 & 0x40000)) {
            **(void ***)0x1F8003FC = sp;
            D_8018424C = func_8014FA70(arg0, 0x1F8003FC);
            var_a0 = arg0 + 4;
        }
        func_80015978(var_a0, arg0 + 0x88);
    }
}
