/* Overlay range [80131A34,80131AC8) from MAIN.CD member 0012.
 * SHA256(span)=689e3be6fe24e71bcbca696bf0d7ae81fcb56f12b76931445e1b99b2e1ecb058.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void func_8012A828(void *, s32);                 /* static */
s32 func_80131CF4(s32);                             /* static */

s32 func_80131A34(void *arg0, s32 arg1) {
    s32 temp_v0;
    s32 var_v0;

    temp_v0 = func_80131CF4(M2C_FIELD(arg0, s32 *, 0xBC));
    if (temp_v0 != 0) {
        if ((arg1 == 0xB) || (arg1 == 8) || (arg1 == 0x20)) {
            var_v0 = M2C_FIELD(arg0, s32 *, 0xC4) | 4;
        } else {
            var_v0 = M2C_FIELD(arg0, s32 *, 0xC4) & ~4;
        }
        M2C_FIELD(arg0, s32 *, 0xC4) = var_v0;
        func_8012A828(arg0, temp_v0);
        return 1;
    }
    return 0;
}
