/* Overlay range [8012DBD0,8012DDA4) from MAIN.CD member 0012.
 * SHA256(span)=96d01c28993e5b43c45070c263738d2013c485fea89c25bb629a2a6f6c1d4b41.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

s32 func_80013350(void *, void *);                  /* extern */
void *func_8012DDA4();                              /* static */
void *func_8012DE2C();                              /* static */

s32 func_8012DBD0(void *arg0, s16 arg1, s16 arg2, u16 arg3) {
    s16 temp_v0;
    s16 temp_v0_2;
    s16 temp_v0_3;
    s16 temp_v0_4;
    s16 temp_v0_5;
    s16 var_s1;
    s16 var_s1_2;
    s16 var_v1;
    s16 var_v1_2;
    s16 var_v1_3;
    s16 var_v1_4;
    s16 var_v1_5;
    s32 temp_a0;
    s32 temp_v1;
    s32 var_lo;
    u16 temp_v1_2;
    void *var_s0;

    var_s0 = func_8012DE2C();
    if (var_s0 != 0) {
        temp_v1 = M2C_FIELD(arg0, s32 *, 0x58);
        if (temp_v1 == 0) {
            var_s1 = 0x80;
            goto block_25;
        }
        temp_a0 = temp_v1 & 0x0FFFFFFF;
        temp_v0 = M2C_FIELD(temp_a0, s16 *, 4);
        var_v1 = M2C_FIELD(temp_a0, s16 *, 6);
        var_s1_2 = temp_v0;
        if (temp_v0 < 0) {
            var_s1_2 = -var_s1_2;
        }
        if (var_v1 < 0) {
            var_v1 = -var_v1;
        }
        if (var_s1_2 < var_v1) {
            var_s1_2 = var_v1;
        }
        temp_v0_2 = M2C_FIELD(temp_a0, s16 *, 8);
        var_v1_2 = temp_v0_2;
        if (temp_v0_2 < 0) {
            var_v1_2 = -var_v1_2;
        }
        if (var_s1_2 < var_v1_2) {
            var_s1_2 = var_v1_2;
        }
        temp_v0_3 = M2C_FIELD(temp_a0, s16 *, 0xA);
        var_v1_3 = temp_v0_3;
        if (temp_v0_3 < 0) {
            var_v1_3 = -var_v1_3;
        }
        if (var_s1_2 < var_v1_3) {
            var_s1_2 = var_v1_3;
        }
        temp_v0_4 = M2C_FIELD(temp_a0, s16 *, 0xC);
        var_v1_4 = temp_v0_4;
        if (temp_v0_4 < 0) {
            var_v1_4 = -var_v1_4;
        }
        if (var_s1_2 < var_v1_4) {
            var_s1_2 = var_v1_4;
        }
        temp_v0_5 = M2C_FIELD(temp_a0, s16 *, 0xE);
        var_v1_5 = temp_v0_5;
        if (temp_v0_5 < 0) {
            var_v1_5 = -var_v1_5;
        }
        var_lo = var_s1_2 * var_s1_2;
        if (var_s1_2 < var_v1_5) {
            var_s1 = var_v1_5;
block_25:
            var_lo = var_s1 * var_s1;
        }
        do {
            temp_v1_2 = M2C_FIELD(var_s0, u16 *, 0x5C);
            if ((temp_v1_2 & 0x8000) && !(temp_v1_2 & 0x4000) && (M2C_FIELD(var_s0, u16 *, 0x5E) != arg3) && !(M2C_FIELD(var_s0, u16 *, 0xAE) & 1) && (func_80013350(arg0 + 4, var_s0 + 4) < var_lo)) {
                M2C_FIELD(var_s0, s16 *, 0x60) = arg1;
                M2C_FIELD(var_s0, s16 *, 0x62) = arg2;
                M2C_FIELD(var_s0, u16 *, 0x5E) = arg3;
                M2C_FIELD(var_s0, u16 *, 0x5C) = (u16) (M2C_FIELD(var_s0, u16 *, 0x5C) | 1);
            }
            var_s0 = func_8012DDA4();
        } while (var_s0 != 0);
    }
    return 0;
}
