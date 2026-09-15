/* Overlay range [8017869C,80178744) from MAIN.CD member 0012.
 * SHA256(span)=5650da561189fc5de5225bef5034db39acf7666eb8a246a853f118ac78d1362d.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void func_80178744(s32);                         /* static */

void func_8017869C(void *arg0) {
    s16 temp_v0;
    s16 temp_v0_2;
    s32 var_a1;

    temp_v0 = M2C_FIELD(arg0, s16 *, 0xAA);
    if (temp_v0 != 0) {
        temp_v0_2 = temp_v0 - 1;
        M2C_FIELD(arg0, s16 *, 0xAA) = temp_v0_2;
        if (temp_v0_2 == 0) {
            var_a1 = 0x1000;
            if (M2C_FIELD(arg0, u16 *, 0x5E) == 0x1E) {
                M2C_FIELD(arg0, u16 *, 0x5E) = 0U;
            }
        } else if (temp_v0_2 >= 0xF1) {
            var_a1 = 0x1000 - ((0x100 - temp_v0_2) * 0x90);
        } else if (temp_v0_2 < 0x10) {
            var_a1 = 0x1000 - (temp_v0_2 * 0x90);
        } else {
            var_a1 = 0x700;
        }
        func_80178744(var_a1);
    }
}
