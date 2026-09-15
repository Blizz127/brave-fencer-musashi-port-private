/* Main-exec range [80053BD8,80053CF8) from the SLUS executable.
 * SHA256(span)=9dad37683509c56a456988f04b7ffa0fe888d79ba44b96855b4c56c5369f1d07.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

s32 func_80053BD8(void *arg0, s16 arg1, s16 arg2, s32 arg3) {
    s32 temp_v1;
    s32 var_t0;
    s32 var_v0;

    var_t0 = 0;
    if (arg1 != 0x1000) {
        var_t0 = 1;
        M2C_FIELD(arg0, s16 *, 0) = (s16) ((s32) (M2C_FIELD(arg0, s16 *, 0) * arg1) >> 0xC);
        M2C_FIELD(arg0, s16 *, 6) = (s16) ((s32) (M2C_FIELD(arg0, s16 *, 6) * arg1) >> 0xC);
        M2C_FIELD(arg0, s16 *, 0xC) = (s16) ((s32) (M2C_FIELD(arg0, s16 *, 0xC) * arg1) >> 0xC);
    }
    var_v0 = arg3 << 0x10;
    if (arg2 != 0x1000) {
        var_t0 = 1;
        M2C_FIELD(arg0, s16 *, 2) = (s16) ((s32) (M2C_FIELD(arg0, s16 *, 2) * arg2) >> 0xC);
        M2C_FIELD(arg0, s16 *, 8) = (s16) ((s32) (M2C_FIELD(arg0, s16 *, 8) * arg2) >> 0xC);
        M2C_FIELD(arg0, s16 *, 0xE) = (s16) ((s32) (M2C_FIELD(arg0, s16 *, 0xE) * arg2) >> 0xC);
        var_v0 = arg3 << 0x10;
    }
    temp_v1 = var_v0 >> 0x10;
    if (temp_v1 != 0x1000) {
        var_t0 = 1;
        M2C_FIELD(arg0, s16 *, 4) = (s16) ((s32) (M2C_FIELD(arg0, s16 *, 4) * temp_v1) >> 0xC);
        M2C_FIELD(arg0, s16 *, 0xA) = (s16) ((s32) (M2C_FIELD(arg0, s16 *, 0xA) * temp_v1) >> 0xC);
        M2C_FIELD(arg0, s16 *, 0x10) = (s16) ((s32) (M2C_FIELD(arg0, s16 *, 0x10) * temp_v1) >> 0xC);
    }
    return var_t0;
}
