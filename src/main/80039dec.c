/* Main-exec range [80039DEC,80039F14) from the SLUS executable.
 * SHA256(span)=114e0708397033c9819f6a2f54d4cfacd2026efe57f5dfc917b50f1c3e5fdf7d.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void func_80039DEC(void *arg0, s16 arg1, s16 arg2) {
    s32 temp_a1;
    s32 var_v0;
    s8 var_a0;
    u8 temp_v1_2;
    u8 var_v1;
    void *temp_v1;
    void *var_v0_2;

    if (arg2 != 0x1E) {
        if (arg2 < 0x1F) {
            if (arg2 != 0x14) {
                var_v0 = arg1 << 0x10;
                goto block_14;
            }
            var_v0_2 = arg0 + (arg1 * 0x1A);
            var_v1 = M2C_FIELD(var_v0_2, u8 *, 0x21);
            var_a0 = 0x18;
            goto block_13;
        }
        if (arg2 != 0x28) {
            var_v0 = arg1 << 0x10;
block_14:
            temp_v1 = arg0 + ((var_v0 >> 0x10) * 0x1A);
            M2C_FIELD(temp_v1, s8 *, 0x1F) = (s8) arg2;
            M2C_FIELD(temp_v1, u8 *, 0x21) = (u8) (M2C_FIELD(temp_v1, u8 *, 0x21) | 1);
        } else {
            var_v0_2 = arg0 + (arg1 * 0x1A);
            var_v1 = M2C_FIELD(var_v0_2, u8 *, 0x21);
            var_a0 = 0x1A;
block_13:
            M2C_FIELD(var_v0_2, s8 *, 0x1F) = (s8) arg2;
            M2C_FIELD(var_v0_2, s8 *, 0x22) = var_a0;
            M2C_FIELD(var_v0_2, s8 *, 0x21) = (s8) (var_v1 | 3);
        }
    } else {
        if (M2C_FIELD(arg0, u8 *, 0x1F6) == 0) {
            M2C_FIELD(arg0, s8 *, 0x1F9) = 1;
            return;
        }
        temp_v1_2 = M2C_FIELD(arg0, u8 *, 0x1F5);
        temp_a1 = temp_v1_2 & 0xFF;
        if ((temp_a1 == 0x7F) || (M2C_FIELD(arg0, u8 *, 0x1F5) = (u8) (temp_v1_2 + 0xFF), (temp_a1 != 0))) {
            M2C_FIELD(arg0, s8 *, 0x1F7) = (s8) (arg1 | 0xB0);
            M2C_FIELD(arg0, s32 *, 0) = (s32) M2C_FIELD(arg0, s32 *, 0xC);
        }
    }
}
