/* Overlay range [8014DCE0,8014DD8C) from MAIN.CD member 0012.
 * SHA256(span)=34b6dcdbb56fe8afba8f938650f267a5132ca653ff51d7e03d6c1c24b267b297.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

s32 func_80135888(s32, s32 *, s32, s32);        /* static */

s32 func_8014DCE0(void *arg0, s32 arg1, s32 arg2) {
    s32 sp1C;
    s32 sp18;
    s32 sp14;
    s32 sp10;
    s32 temp_v0;
    s32 var_s0;
    s32 var_s1;

    var_s1 = 0;
    var_s0 = arg2;
    temp_v0 = M2C_FIELD(arg0, s32 *, 0x58) & 0x0FFFFFFF;
    sp10 = M2C_FIELD(temp_v0, s32 *, 0);
    sp14 = M2C_FIELD(temp_v0, s32 *, 4);
    sp18 = M2C_FIELD(temp_v0, s32 *, 8);
    sp1C = M2C_FIELD(temp_v0, s32 *, 0xC);
loop_1:
    var_s1 += 1;
    if (func_80135888(M2C_FIELD(arg0, s32 *, 0x20), &sp10, arg1, var_s0) != 0) {
        return 1;
    }
    var_s0 += 8;
    if (var_s1 >= 3) {
        return 0;
    }
    goto loop_1;
}
