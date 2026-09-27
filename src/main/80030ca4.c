/* Exact retail word export for [80030CA4,80030D80); EXE and assembly verified. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void func_80030D80(void *, s32, s32, s32); /* static */
extern s32 *D_800A4988;

s32 func_80030CA4(s32 arg0) {
    u8 sp1A;
    u16 sp18;
    void *sp14;
    s32 sp10;
    void *var_s0;
    s32 var_a2;
    s32 var_v0;
    u16 temp_v1;
    void *var_a1;

    var_s0 = &D_800A4988;
    var_a2 = 0;
    var_a1 = &D_800A4988 + 8;
    sp1A = 0;
loop_1:
    var_v0 = var_a2 + 1;
    if (M2C_FIELD(var_a1, u8 *, 0x46) != 0) {
        if (sp1A == 0) {
            sp1A = 1;
            sp10 = var_a2;
            sp14 = var_s0;
            sp18 = M2C_FIELD(var_a1, u16 *, 0);
        } else {
            temp_v1 = M2C_FIELD(var_a1, u16 *, 0);
            if (temp_v1 < sp18) {
                sp18 = temp_v1;
                sp10 = var_a2;
                sp14 = var_s0;
            }
        }
        var_a2 += 1;
        var_a1 += 0x54;
        var_s0 += 0x54;
        if (var_a2 >= 8) {
            var_v0 = 0;
            if ((u32) (arg0 & 0xFFFF) >= sp18) {
                func_80030D80(sp14, 1, var_a2, 1);
                M2C_FIELD(var_s0, s8 *, 0x4E) = 0;
                var_v0 = sp10 + 1;
                sp10 = var_v0;
            }
        } else {
            goto loop_1;
        }
    }
    return var_v0;
}
