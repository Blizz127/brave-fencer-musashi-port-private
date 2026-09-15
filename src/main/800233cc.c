/* Exact retail [800233CC,800234E4).
 * Words from pinned SLUS_007.26.
 */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

s32 func_8004787C(s32);                             /* static */
s32 func_80047948(s32);                             /* static */

void func_800233CC(void *arg0, s32 arg1) {
    s32 temp_lo;
    s32 temp_s3;
    s32 var_s0;
    s32 var_s0_2;
    s32 var_s0_3;
    s32 var_s1;
    void *temp_v0;
    void *temp_v1;
    void *var_a0;
    void *var_a0_2;
    void *var_s2;

    var_s0 = 0;
    temp_s3 = arg1 & 0xFFFF;
    var_s2 = arg0;
    var_s1 = 0;
    do {
        M2C_FIELD(var_s2, s16 *, 0x10) = (s16) ((s32) (func_8004787C(var_s1) * temp_s3) >> 0xC);
        temp_lo = func_80047948(var_s1) * temp_s3;
        var_s1 += 0x155;
        var_s0 += 1;
        M2C_FIELD(var_s2, s16 *, 0x12) = (s16) (temp_lo >> 0xC);
        var_s2 += 4;
    } while (var_s0 < 4);
    var_s0_2 = 4;
    var_a0 = arg0 + 0x10;
    do {
        temp_v0 = arg0 + ((6 - var_s0_2) * 4);
        M2C_FIELD(var_a0, u16 *, 0x10) = (u16) M2C_FIELD(temp_v0, u16 *, 0x10);
        var_s0_2 += 1;
        M2C_FIELD(var_a0, s16 *, 0x12) = (s16) -(s16) M2C_FIELD(temp_v0, u16 *, 0x12);
        var_a0 += 4;
    } while (var_s0_2 < 7);
    var_s0_3 = 7;
    var_a0_2 = arg0 + 0x1C;
    do {
        temp_v1 = arg0 + ((0xC - var_s0_3) * 4);
        M2C_FIELD(var_a0_2, s16 *, 0x10) = (s16) -(s16) M2C_FIELD(temp_v1, u16 *, 0x10);
        var_s0_3 += 1;
        M2C_FIELD(var_a0_2, u16 *, 0x12) = (u16) M2C_FIELD(temp_v1, u16 *, 0x12);
        var_a0_2 += 4;
    } while (var_s0_3 < 0xC);
}
