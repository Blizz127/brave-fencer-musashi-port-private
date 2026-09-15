/* Exact retail word export for [800149E0,80014B10); EXE and assembly verified. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

s32 func_80014C28(s32);                             /* static */
s32 func_80014CF8(s32, s32);                          /* static */
s32 func_80014D30(s32, s32);                          /* static */
extern s32 *D_80078DD2;

u16 func_800149E0(s32 arg0) {
    s32 temp_a0;
    s32 temp_a0_2;
    s32 temp_a1;
    s32 temp_s0;
    s32 temp_s0_2;
    s32 temp_s1;
    s32 temp_s1_2;
    s32 temp_s2;
    s32 temp_v1;
    s32 var_v1;
    u16 var_v0;
    u32 temp_v0;
    u32 temp_v0_2;

    temp_a0 = arg0 & 0xFF;
    var_v0 = *(&D_80078DD2 + (temp_a0 * 0x4C));
    if ((var_v0 == 0) && ((temp_v1 = func_80014C28(temp_a0) & 0xFF, (temp_v1 == 0x53)) || ((var_v0 = 0, ((temp_v1 < 0x54) == 0)) && (var_v0 = 0, (temp_v1 == 0x73))))) {
        temp_s0 = arg0 & 0xFF;
        temp_s1 = func_80014D30(temp_s0, 5) & 0xFF;
        temp_s2 = func_80014D30(temp_s0, 4) & 0xFF;
        temp_s0_2 = func_80014CF8(temp_s0, 5) & 0xFF;
        temp_a1 = func_80014CF8(temp_s0, 4) & 0xFF;
        temp_s1_2 = temp_s1 & 0xFFFF;
        var_v1 = 0;
        if (temp_s1_2 == 0x80) {
            temp_v0 = temp_s0_2 & 0xFFFF;
            if (temp_v0 != temp_s1_2) {
                var_v1 = 0x1000;
                if (temp_v0 >= 0x80U) {
                    var_v1 = 0x4000;
                }
            }
        }
        temp_a0_2 = temp_s2 & 0xFFFF;
        var_v0 = var_v1 & 0xFFFF;
        if (temp_a0_2 == 0x80) {
            temp_v0_2 = temp_a1 & 0xFFFF;
            if (temp_v0_2 != temp_a0_2) {
                if (temp_v0_2 < 0x80U) {
                    var_v1 |= 0x8000;
                } else {
                    var_v1 |= 0x2000;
                }
            }
            var_v0 = var_v1 & 0xFFFF;
        }
    }
    return var_v0;
}
