/* Exact retail word export for [8003B1EC,8003B250); EXE-verified. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

extern s32 D_8006B544;

void func_8003B1EC(void *arg0) {
    s32 temp_v0;

    temp_v0 = M2C_FIELD(arg0, s32 *, 0);
    if ((temp_v0 == 0) || (temp_v0 & 1)) {
        if (M2C_FIELD(arg0, s32 *, 4) != 0) {
            D_8006B544 = (s32) (D_8006B544 | 1);
            return;
        }
        D_8006B544 = (s32) (D_8006B544 & ~1);
    }
}
