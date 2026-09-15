/* Overlay range [8012E470,8012E4C8) from MAIN.CD member 0012.
 * SHA256(span)=376e20a61843a59643a97940655e41504ad94b5a314904a5d821ea1368ee7b99.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

s32 func_8012E470(void *arg0) {
    s16 temp_v0_2;
    s16 temp_v1;
    s32 temp_v0;
    s32 temp_v0_3;
    void *temp_a1;

    temp_a1 = M2C_FIELD(arg0, void **, 0x20);
    temp_v1 = M2C_FIELD(temp_a1, s16 *, 0x18);
    temp_v0_2 = temp_v1 + ((s32) (0x1000 - temp_v1) / 4);
    M2C_FIELD(temp_a1, s16 *, 0x1C) = temp_v0_2;
    M2C_FIELD(temp_a1, s16 *, 0x18) = temp_v0_2;
    temp_v0_3 = M2C_FIELD(arg0, s32 *, 0x1C);
    temp_v0 = temp_v0_3 - 1;
    if (temp_v0_3 == 0) {
        return 1;
    }
    M2C_FIELD(arg0, s32 *, 0x1C) = temp_v0;
    return temp_v0 == 0;
}
