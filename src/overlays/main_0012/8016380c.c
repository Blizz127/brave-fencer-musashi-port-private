/* Overlay range [8016380C,801638A0) from MAIN.CD member 0012.
 * SHA256(span)=0a7d4a7a216997bf7d91dec02ad651041ab42c38888ad03baf3bcbc8e7674348.
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
s32 func_80133784(s32, void *, s32);     /* static */

s32 func_8016380C(void *arg0, s32 arg1) {
    s32 sp17;
    s32 sp13;
    s32 sp10;
    s32 temp_v0;
    void *temp_s2;

    sp13 = M2C_UNALIGNED32(M2C_ERROR(/* Unable to handle lwr; missing a corresponding lwl */));
    sp17 = M2C_UNALIGNED32(M2C_ERROR(/* Unable to handle lwr; missing a corresponding lwl */));
    temp_s2 = arg0 + 4;
    func_80015978(temp_s2, arg1);
    temp_v0 = func_80133784(1, &sp10, arg1);
    if (temp_v0 == 0) {
        return 0;
    }
    func_80015954(arg1, temp_s2);
    return temp_v0;
}
