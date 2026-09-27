/* Main-exec range [8003E310,8003E418) from the SLUS executable.
 * SHA256(span)=d00a8b49dfab820d5765b121c1f3cecf553587c5c2d7ee6305d39c3c565dcbb7.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void func_8003E65C(s16, s16);                    /* static */
extern s32 *D_800C73D8;

void func_8003E310(s16 arg0, s16 arg1) {
    s16 temp_v0;
    s16 temp_v1_2;
    s16 temp_v1_3;
    s32 temp_a0;
    s32 temp_v0_2;
    s32 temp_v1;
    s32 var_s0;
    s32 var_v0;
    void *temp_s1;

    temp_s1 = *(&D_800C73D8 + ((s32) (arg0 << 0x10) >> 0xE)) + (arg1 * 0xB0);
    temp_v0 = M2C_FIELD(temp_s1, s16 *, 0x54);
    temp_v1 = M2C_FIELD(temp_s1, s32 *, 0x90);
    temp_a0 = temp_v1 - temp_v0;
    if (temp_a0 > 0) {
        temp_v1_2 = M2C_FIELD(temp_s1, s16 *, 0x52);
        if (temp_v1_2 > 0) {
            M2C_FIELD(temp_s1, s16 *, 0x52) = (s16) (temp_v1_2 - 1);
            return;
        }
        if (temp_v1_2 == 0) {
            M2C_FIELD(temp_s1, s16 *, 0x52) = temp_v0;
            var_v0 = M2C_FIELD(temp_s1, s32 *, 0x90) - 1;
            goto block_10;
        }
        M2C_FIELD(temp_s1, s32 *, 0x90) = temp_a0;
        return;
    }
    var_s0 = temp_v1;
    if (temp_v0 >= temp_v1) {
        do {
loop_8:
            func_8003E65C(arg0, arg1);
            temp_v0_2 = M2C_FIELD(temp_s1, s32 *, 0x90);
            if (temp_v0_2 == 0) {
                goto loop_8;
            }
            temp_v1_3 = M2C_FIELD(temp_s1, s16 *, 0x54);
            var_s0 += temp_v0_2;
            var_v0 = var_s0 - temp_v1_3;
        } while (var_s0 < temp_v1_3);
block_10:
        M2C_FIELD(temp_s1, s32 *, 0x90) = var_v0;
    }
}
