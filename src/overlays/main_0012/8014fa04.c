/* Overlay range [8014FA04,8014FA70) from MAIN.CD member 0012.
 * SHA256(span)=3f378be053345d7c1392377a38a58e020565cbb7d820de05247f0b153b160d93.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

extern s32 D_8018424C;
s32 func_8014FA70();                               /* static */

s32 func_8014FA04(void *arg0) {
    s32 var_v0;

    var_v0 = 0;
    if (!(arg0->unk44 & 0x40000)) {
        **(void ***)0x1F8003FC = sp;
        D_8018424C = func_8014FA70(0x1F8003FC);
        var_v0 = D_8018424C;
    }
    return var_v0;
}
