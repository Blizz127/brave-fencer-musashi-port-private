/* Overlay range [80178970,801789AC) from MAIN.CD member 0012.
 * SHA256(span)=2629493751c3db7fa8e0ed0d60b213758d2839bb9cea09184ea57dfdfaf4584a.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

s32 func_801789AC();                                /* static */
extern s16 D_80185C08;

s32 func_80178970(void) {
    s32 var_v0;

    var_v0 = 0;
    if (func_801789AC() != 0) {
        var_v0 = D_80185C08 == 0;
    }
    return var_v0;
}
