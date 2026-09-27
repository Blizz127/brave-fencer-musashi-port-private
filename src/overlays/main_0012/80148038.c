/* Overlay range [80148038,80148094) from MAIN.CD member 0012.
 * SHA256(span)=1aea098cf9d704ff73f1dc52a1ba23ef1f4bbd392104cd002d8279af4b93dbe1.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void func_80148038(void *arg0, s32 arg1) {
    s32 temp_v1;
    s32 var_a1;

    var_a1 = arg1;
    temp_v1 = M2C_FIELD(arg0, s32 *, 0x34);
    if (temp_v1 < 0) {
        if ((var_a1 < 0) && (temp_v1 <= -0x1F0000)) {
            var_a1 = 0;
        }
    } else if ((var_a1 > 0) && (temp_v1 > 0x1EFFFF)) {
        var_a1 = 0;
    }
    M2C_FIELD(arg0, s32 *, 0x34) = (s32) (M2C_FIELD(arg0, s32 *, 0x34) + var_a1);
}
