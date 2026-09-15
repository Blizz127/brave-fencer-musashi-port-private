/* Main-exec range [8004A27C,8004A414) from the SLUS executable.
 * SHA256(span)=7501873b1f3e984e3550025f130767cabbb4d72ddba00d7acc503e5733035bf7.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

extern s32 D_8006DF1C[];

void *func_8004A27C(s32 arg0, void *arg1) {
    s16 temp_t2;
    s16 temp_t3;
    s16 temp_t4;
    s16 temp_t5;
    s16 temp_t6;
    s16 temp_t7_2;
    s16 var_t1;
    s32 temp_t7;
    s32 temp_t9;
    s32 temp_t9_2;
    s32 var_t0;

    if (arg0 < 0) {
        temp_t7 = -arg0;
        if (temp_t7 < 0) {

        }
        temp_t9 = *(D_8006DF1C + ((temp_t7 & 0xFFF) * 4));
        var_t1 = -(s16) temp_t9;
        var_t0 = temp_t9 >> 0x10;
    } else {
        temp_t9_2 = *(D_8006DF1C + ((arg0 & 0xFFF) * 4));
        var_t1 = (s16) temp_t9_2;
        var_t0 = temp_t9_2 >> 0x10;
    }
    temp_t2 = M2C_FIELD(arg1, s16 *, 0);
    temp_t5 = M2C_FIELD(arg1, s16 *, 6);
    temp_t3 = M2C_FIELD(arg1, s16 *, 2);
    temp_t6 = M2C_FIELD(arg1, s16 *, 8);
    temp_t4 = M2C_FIELD(arg1, s16 *, 4);
    temp_t7_2 = M2C_FIELD(arg1, s16 *, 0xA);
    M2C_FIELD(arg1, s16 *, 0) = (s16) ((s32) ((var_t0 * temp_t2) - (var_t1 * temp_t5)) >> 0xC);
    M2C_FIELD(arg1, s16 *, 2) = (s16) ((s32) ((var_t0 * temp_t3) - (var_t1 * temp_t6)) >> 0xC);
    M2C_FIELD(arg1, s16 *, 4) = (s16) ((s32) ((var_t0 * temp_t4) - (var_t1 * temp_t7_2)) >> 0xC);
    M2C_FIELD(arg1, s16 *, 6) = (s16) ((s32) ((var_t1 * temp_t2) + (var_t0 * temp_t5)) >> 0xC);
    M2C_FIELD(arg1, s16 *, 8) = (s16) ((s32) ((var_t1 * temp_t3) + (var_t0 * temp_t6)) >> 0xC);
    M2C_FIELD(arg1, s16 *, 0xA) = (s16) ((s32) ((var_t1 * temp_t4) + (var_t0 * temp_t7_2)) >> 0xC);
    return arg1;
}
