/* Exact retail word export for [8003BE98,8003C0A0); EXE-verified. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

extern s32 D_8006B110;
extern s32 D_8006B544;
extern s32 D_8006B54C;
extern s32 *D_800A6288;

s32 func_8003BE98(s32 arg0, u32 arg1, s32 arg2, s32 arg3) {
    void *var_a0;
    s32 temp_v1;
    s32 temp_v1_4;
    s32 var_t2;
    s32 var_v0;
    u16 *temp_a0;
    u16 *temp_a0_2;
    u16 *temp_a0_3;
    u16 *temp_a0_4;
    u16 *temp_v1_2;
    u16 *temp_v1_3;
    u16 *temp_v1_5;
    u16 *temp_v1_6;

    if (D_8006B544 & 1) {
        var_a0 = &D_800A6288;
        var_v0 = arg3 * 2;
    } else {
        var_a0 = D_8006B54C;
        var_v0 = arg3 * 2;
    }
    var_t2 = *((arg2 * 2) + var_a0) | ((*(var_v0 + var_a0) & 0xFF) << 0x10);
    if (arg0 != 0) {
        if (arg0 == 1) {
            temp_v1 = arg2 * 2;
            if (D_8006B544 & 1) {
                temp_v1_2 = temp_v1 + &D_800A6288;
                temp_a0 = (arg3 * 2) + &D_800A6288;
                *temp_v1_2 |= arg1;
                *temp_a0 |= (arg1 >> 0x10) & 0xFF;
                D_8006B110 = (s32) (D_8006B110 | (arg0 << ((s32) (arg2 - 0xC6) >> 1)));
            } else {
                temp_v1_3 = temp_v1 + D_8006B54C;
                temp_a0_2 = (arg3 * 2) + D_8006B54C;
                *temp_v1_3 |= arg1;
                *temp_a0_2 |= (arg1 >> 0x10) & 0xFF;
            }
            var_t2 |= arg1 & 0xFFFFFF;
        }
    } else {
        temp_v1_4 = arg2 * 2;
        if (D_8006B544 & 1) {
            temp_v1_5 = temp_v1_4 + &D_800A6288;
            temp_a0_3 = (arg3 * 2) + &D_800A6288;
            *temp_v1_5 &= ~arg1;
            *temp_a0_3 &= ~((arg1 >> 0x10) & 0xFF);
            D_8006B110 = (s32) (D_8006B110 | (1 << ((s32) (arg2 - 0xC6) >> 1)));
        } else {
            temp_v1_6 = temp_v1_4 + D_8006B54C;
            temp_a0_4 = (arg3 * 2) + D_8006B54C;
            *temp_v1_6 &= ~arg1;
            *temp_a0_4 &= ~((arg1 >> 0x10) & 0xFF);
        }
        var_t2 &= ~(arg1 & 0xFFFFFF);
    }
    return var_t2 & 0xFFFFFF;
}
