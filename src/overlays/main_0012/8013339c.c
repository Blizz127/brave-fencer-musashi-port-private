/* Overlay range [8013339C,8013361C) from MAIN.CD member 0012.
 * SHA256(span)=090d249dd9cd88db78801084c619e904a3af3f99f7333c9c53475400cef74cea.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void func_8013339C(void *arg0, void *arg1) {
    s16 temp_v0;
    s16 temp_v0_2;
    s16 temp_v0_3;
    s16 var_a0;
    s16 var_a2;
    s16 var_t5;

    temp_v0 = M2C_FIELD(arg1, s16 *, 0);
    var_a0 = 1;
    if (temp_v0 != 0) {
        var_a0 = temp_v0;
    }
    temp_v0_2 = M2C_FIELD(arg1, s16 *, 2);
    var_a2 = 1;
    if (temp_v0_2 != 0) {
        var_a2 = temp_v0_2;
    }
    temp_v0_3 = M2C_FIELD(arg1, s16 *, 4);
    var_t5 = 1;
    if (temp_v0_3 != 0) {
        var_t5 = temp_v0_3;
    }
    M2C_FIELD(arg0, s16 *, 0) = (s16) ((s32) (M2C_FIELD(arg0, s16 *, 0) << 0xC) / var_a0);
    M2C_FIELD(arg0, s16 *, 6) = (s16) ((s32) (M2C_FIELD(arg0, s16 *, 6) << 0xC) / var_a0);
    M2C_FIELD(arg0, s16 *, 0xC) = (s16) ((s32) (M2C_FIELD(arg0, s16 *, 0xC) << 0xC) / var_a0);
    M2C_FIELD(arg0, s16 *, 2) = (s16) ((s32) (M2C_FIELD(arg0, s16 *, 2) << 0xC) / var_a2);
    M2C_FIELD(arg0, s16 *, 8) = (s16) ((s32) (M2C_FIELD(arg0, s16 *, 8) << 0xC) / var_a2);
    M2C_FIELD(arg0, s16 *, 0xE) = (s16) ((s32) (M2C_FIELD(arg0, s16 *, 0xE) << 0xC) / var_a2);
    M2C_FIELD(arg0, s16 *, 4) = (s16) ((s32) (M2C_FIELD(arg0, s16 *, 4) << 0xC) / var_t5);
    M2C_FIELD(arg0, s16 *, 0xA) = (s16) ((s32) (M2C_FIELD(arg0, s16 *, 0xA) << 0xC) / var_t5);
    M2C_FIELD(arg0, s16 *, 0x10) = (s16) ((s32) (M2C_FIELD(arg0, s16 *, 0x10) << 0xC) / var_t5);
}
