/* Exact retail [800234E4,80023570).
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

void func_800234E4(void *arg0, s32 arg1, s32 arg2) {
    s32 temp_lo;
    s32 temp_s3;
    s32 var_s0;
    s32 var_s2;
    void *var_s1;

    var_s2 = 0;
    temp_s3 = arg1 & 0xFFFF;
    var_s1 = arg0;
    var_s0 = arg2 & 0xFFFF;
    do {
        M2C_FIELD(var_s1, s16 *, 0x10) = (s16) ((s32) (func_8004787C(var_s0) * temp_s3) >> 0xC);
        temp_lo = func_80047948(var_s0) * temp_s3;
        var_s0 += 0x155;
        var_s2 += 1;
        M2C_FIELD(var_s1, s16 *, 0x12) = (s16) (temp_lo >> 0xC);
        var_s1 += 4;
    } while (var_s2 < 0xC);
}
