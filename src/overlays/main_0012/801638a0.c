/* Overlay range [801638A0,80163950) from MAIN.CD member 0012.
 * SHA256(span)=00a79b42f520329092091eadaea5582ae07fa17fb00e21beff15f63625f18d1b.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void func_80015954(s32, void *);             /* extern */
void func_80015978(void *, s32);             /* extern */
s32 func_80135004(s32, void *, s32);     /* static */
extern s16 D_801152AA;

s32 func_801638A0(void *arg0, s32 arg1) {
    s32 sp17;
    s32 sp13;
    s32 sp10;
    s32 var_v0;
    void *temp_s1;

    sp13 = M2C_UNALIGNED32(M2C_ERROR(/* Unable to handle lwr; missing a corresponding lwl */));
    sp17 = M2C_UNALIGNED32(M2C_ERROR(/* Unable to handle lwr; missing a corresponding lwl */));
    temp_s1 = arg0 + 4;
    func_80015978(temp_s1, arg1);
    if (func_80135004(1, &sp10, arg1) != 0) {
        func_80015954(arg1, temp_s1);
        if (D_801152AA >= -0x578) {
            return 0x8000;
        }
        var_v0 = 0x2000;
        if (D_801152AA >= -0xBCB) {
            return 0x4000;
        }
        /* Duplicate return node #6. Try simplifying control flow for better match */
        return var_v0;
    }
    var_v0 = 0;
    return var_v0;
}
