/* Exact retail word export for [8003C0A0,8003C23C); EXE and assembly verified. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

extern s32 D_8006B0E0;
extern s32 D_8006B144;
extern s32 D_8006B568;
extern s32 D_8006B574;
extern s32 D_8006B584;
extern s32 D_8006B5B4;
void func_8003AB84(s32, s32 (*)(), u32);                   /* static */
s32 func_8003B3D0(s32);                             /* static */
void func_8005CE98(s32);                               /* static */

s32 func_8003C0A0(u32 arg0) {
    s32 sp10;
    s32 *temp_s1;
    s32 temp_a0;
    s32 temp_s4;
    s32 var_s2;
    s32 var_s3;
    s32 var_s5;
    s32 var_v0;
    u32 var_s0;
    u32 var_s1;

    sp10 = 0;
    var_s5 = 0;
    if ((arg0 >= 0xAU) || (temp_s1 = (arg0 * 4) + D_8006B5B4, (func_8003B3D0(*temp_s1) != 0))) {
        return -1;
    }
    if (arg0 == 0) {
        var_s1 = 0x10 << D_8006B574;
        var_s2 = 0xFFF0 << D_8006B574;
    } else {
        temp_a0 = *temp_s1;
        var_s1 = (0x10000 - temp_a0) << D_8006B574;
        var_s2 = temp_a0 << D_8006B574;
    }
    temp_s4 = D_8006B568;
    if (temp_s4 == 1) {
        D_8006B568 = 0;
        var_s5 = 1;
    }
    var_s3 = 1;
    if (D_8006B584 != 0) {
        sp10 = D_8006B584;
        D_8006B584 = 0;
    }
    var_v0 = var_s1 < 0x401U;
    do {
        var_s0 = var_s1;
        if (var_v0 == 0) {
            var_s0 = 0x400;
        } else {
            var_s3 = 0;
        }
        func_8003AB84(2, (s32 (*)()) var_s2);
        func_8003AB84(1);
        func_8003AB84(3, D_8006B144, var_s0);
        var_s1 -= 0x400;
        var_s2 += 0x400;
        func_8005CE98(D_8006B0E0);
        var_v0 = var_s1 < 0x401U;
    } while (var_s3 != 0);
    if (var_s5 != 0) {
        D_8006B568 = temp_s4;
    }
    if (sp10 != 0) {
        D_8006B584 = sp10;
    }
    return 0;
}
