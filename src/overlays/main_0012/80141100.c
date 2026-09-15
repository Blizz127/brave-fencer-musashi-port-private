/* Overlay range [80141100,801412A8) from MAIN.CD member 0012.
 * SHA256(span)=4df757002fe0c8a00dd03e4a4fc8df3ac098cec7fd528742b09e685ef9ae5a4f.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

s16 func_8002A1B4();                                /* extern */
s16 func_8002A27C();                                /* extern */
s16 func_8002A28C();                                /* extern */
s16 func_8002A400();                                /* extern */
s16 func_8002A4C8();                                /* extern */
s16 func_8002A4D8();                                /* extern */
s16 func_8002A670();                                /* extern */
s16 func_8002A738();                                /* extern */
s16 func_8002A748();                                /* extern */
s16 func_8002A8E0();                                /* extern */
s16 func_8002A9A8();                                /* extern */
s16 func_8002A9B8();                                /* extern */
extern s32 D_8017F1DE;
extern s32 D_8017F1E2;
extern s32 D_8017F1E6;
extern s32 D_8017F1EA;
s32 func_801412A8(s32, s16, s16, s16, s32, s32);    /* static */
extern s16 D_80115128;
extern u16 D_80115172;

s32 func_80141100(s32 arg0) {
    s16 temp_s0;
    s16 temp_s0_2;
    s16 temp_s0_3;
    s16 temp_s0_4;
    s16 temp_s1;
    s16 temp_s1_2;
    s16 temp_s1_3;
    s16 temp_s1_4;
    s16 temp_s2;
    s32 temp_s3;
    s32 temp_s3_2;
    s32 temp_s3_3;
    s32 var_s3;
    u16 temp_s4;
    u16 temp_s4_2;
    u16 temp_s4_3;
    u16 temp_s4_4;

    var_s3 = arg0;
    if (D_80115128 == 0) {
        temp_s4 = D_8017F1DE;
        temp_s2 = D_80115172 + 0x31;
        temp_s1 = func_8002A1B4();
        temp_s0 = func_8002A28C();
        temp_s4_2 = D_8017F1E2;
        temp_s3 = func_801412A8(var_s3, temp_s1, temp_s0, func_8002A27C(), (s32) temp_s2, (s32) (s16) temp_s4);
        temp_s1_2 = func_8002A400();
        temp_s0_2 = func_8002A4D8();
        temp_s4_3 = D_8017F1E6;
        temp_s3_2 = func_801412A8(temp_s3, temp_s1_2, temp_s0_2, func_8002A4C8(), (s32) temp_s2, (s32) (s16) temp_s4_2);
        temp_s1_3 = func_8002A8E0();
        temp_s0_3 = func_8002A9B8();
        temp_s4_4 = D_8017F1EA;
        temp_s3_3 = func_801412A8(temp_s3_2, temp_s1_3, temp_s0_3, func_8002A9A8(), (s32) temp_s2, (s32) (s16) temp_s4_3);
        temp_s1_4 = func_8002A670();
        temp_s0_4 = func_8002A748();
        var_s3 = func_801412A8(temp_s3_3, temp_s1_4, temp_s0_4, func_8002A738(), (s32) temp_s2, (s32) (s16) temp_s4_4);
    }
    return var_s3;
}
