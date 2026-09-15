/* Overlay range [8012DEB8,8012DF34) from MAIN.CD member 0012.
 * SHA256(span)=262e5302194c2a49152810cbce934c4ecbced2ea3c692747aaa3dda34307950f.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

s32 func_8012DF34(void *, void *, void *);                   /* static */
void func_8012F214(void *, s32, void *);                       /* static */
extern u16 D_80126B9A;

s32 func_8012DEB8(void *arg0, s32 arg2) {
    s32 sp18;
    s32 sp10;
    s32 var_v0;

    func_8012F214(&sp10);
    func_8012F214(arg0, arg2, &sp18);
    var_v0 = 0;
    if (func_8012DF34(arg0, &sp10, &sp18) != 0) {
        var_v0 = 1;
        D_80126B9A = arg0->unk20->unk12;
    }
    return var_v0;
}
