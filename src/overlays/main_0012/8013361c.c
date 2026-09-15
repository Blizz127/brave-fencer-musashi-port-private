/* Overlay range [8013361C,801336E8) from MAIN.CD member 0012.
 * SHA256(span)=5544766a570733e9d1fdebff2b079f7ad7eb84dadc86c1770d82ff4c9ca75157.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

s32 func_8013361C(void *arg0, void *arg1, void *arg2, void *arg3) {
    s16 temp_a2;
    s16 temp_a3;
    s16 temp_t0;
    s16 temp_t0_2;
    s16 temp_t1;
    s16 temp_t1_2;
    s32 var_v0;

    temp_t1 = M2C_FIELD(arg2, s16 *, 0);
    temp_t0 = M2C_FIELD(arg3, s16 *, 0);
    var_v0 = 0;
    if ((M2C_FIELD(arg1, s16 *, 6) + temp_t0) >= (M2C_FIELD(arg0, s16 *, 4) + temp_t1)) {
        var_v0 = 0;
        if ((M2C_FIELD(arg0, s16 *, 6) + temp_t1) >= (M2C_FIELD(arg1, s16 *, 4) + temp_t0)) {
            temp_t1_2 = M2C_FIELD(arg2, s16 *, 4);
            temp_t0_2 = M2C_FIELD(arg3, s16 *, 4);
            var_v0 = 0;
            if ((M2C_FIELD(arg1, s16 *, 0xE) + temp_t0_2) >= (M2C_FIELD(arg0, s16 *, 0xC) + temp_t1_2)) {
                var_v0 = 0;
                if ((M2C_FIELD(arg0, s16 *, 0xE) + temp_t1_2) >= (M2C_FIELD(arg1, s16 *, 0xC) + temp_t0_2)) {
                    temp_a2 = M2C_FIELD(arg2, s16 *, 2);
                    temp_a3 = M2C_FIELD(arg3, s16 *, 2);
                    var_v0 = 0;
                    if ((M2C_FIELD(arg1, s16 *, 0xA) + temp_a3) >= (M2C_FIELD(arg0, s16 *, 8) + temp_a2)) {
                        var_v0 = 0;
                        if ((M2C_FIELD(arg0, s16 *, 0xA) + temp_a2) >= (M2C_FIELD(arg1, s16 *, 8) + temp_a3)) {
                            var_v0 = 1;
                        }
                    }
                }
            }
        }
    }
    return var_v0;
}
