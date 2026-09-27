/* Exact retail word export for [8003AB84,8003AE14); EXE and assembly verified. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

extern s32 D_8006B54C;
extern s32 *D_8006B550;
extern s32 *D_8006B554;
extern s32 *D_8006B558;
extern s32 D_8006B564;
extern s32 D_8006B574;
extern s32 D_8006B59C;
extern s32 D_8006B5A0;
extern s32 D_8006B5A4;
void func_8003B08C(s32, void *, s32);        /* static */
void func_8003B0B8(s32, void *, s32);        /* static */

s32 func_8003AB84(s32 arg0, u32 arg1, s32 arg2, s32 arg3) {
    s32 temp_a0;
    s32 var_a0;
    s32 var_a2;
    s32 var_v0;
    u32 *var_s0;
    u32 temp_a0_2;
    u32 temp_v0;
    u32 var_v1;
    u32 var_v1_2;
    u32 var_v1_3;

    if (arg0 != 1) {
        if (arg0 < 2) {
            if (arg0 != 0) {
                return 0;
            }
            D_8006B59C = 1;
            if ((M2C_FIELD(D_8006B54C, u16 *, 0x1A6) & 0xFFFF) != D_8006B564) {
                var_v1 = 1;
loop_15:
                var_v0 = -2;
                if (var_v1 < 0xF01U) {
                    var_v1 += 1;
                    if (M2C_FIELD(D_8006B54C, u16 *, 0x1A6) == D_8006B564) {
                        goto block_17;
                    }
                    goto loop_15;
                }
                /* Duplicate return node #29. Try simplifying control flow for better match */
                return var_v0;
            }
block_17:
            M2C_FIELD(D_8006B54C, u16 *, 0x1AA) = (u16) (M2C_FIELD(D_8006B54C, u16 *, 0x1AA) | 0x30);
            return 0;
        }
        switch (arg0) {                             /* irregular */
        case 2:
            temp_v0 = arg1 >> D_8006B574;
            D_8006B564 = (u16) temp_v0;
            M2C_FIELD(D_8006B54C, u16 *, 0x1A6) = (u16) temp_v0;
            return 0;
        case 3:
            var_a0 = 0x20;
            if (D_8006B59C == 1) {
                var_a0 = 0x30;
            }
            temp_a0 = var_a0 & 0xFFFF;
            var_v1_2 = 1;
            if ((M2C_FIELD(D_8006B54C, u16 *, 0x1AA) & 0x30) != temp_a0) {
loop_21:
                var_v0 = -2;
                if (var_v1_2 < 0xF01U) {
                    var_v1_2 += 1;
                    if ((M2C_FIELD(D_8006B54C, u16 *, 0x1AA) & 0x30) == temp_a0) {
                        goto block_23;
                    }
                    goto loop_21;
                }
            } else {
block_23:
                if (D_8006B59C == 1) {
                    var_s0 = &arg1 + 4;
                    func_8003B0B8(temp_a0, D_8006B54C, 1);
                } else {
                    var_s0 = &arg1 + 4;
                    func_8003B08C(temp_a0, D_8006B54C, 1);
                }
                D_8006B5A0 = (s32) M2C_FIELD(var_s0, s32 *, -4);
                temp_a0_2 = M2C_FIELD(var_s0, u32 *, 0);
                D_8006B5A4 = (s32) ((temp_a0_2 >> 6) + ((temp_a0_2 & 0x3F) != 0));
                *D_8006B550 = D_8006B5A0;
                *D_8006B554 = (D_8006B5A4 << 0x10) | 0x10;
                var_a2 = 0x01000201;
                if (D_8006B59C == 1) {
                    var_a2 = 0x01000200;
                }
                *D_8006B558 = var_a2;
                var_v0 = 0;
            }
            /* Duplicate return node #29. Try simplifying control flow for better match */
            return var_v0;
        default:
            return 0;
        }
    } else {
        D_8006B59C = 0;
        if ((M2C_FIELD(D_8006B54C, u16 *, 0x1A6) & 0xFFFF) != D_8006B564) {
            var_v1_3 = 1;
loop_10:
            var_v0 = -2;
            if (var_v1_3 < 0xF01U) {
                var_v1_3 += 1;
                if (M2C_FIELD(D_8006B54C, u16 *, 0x1A6) == D_8006B564) {
                    goto block_12;
                }
                goto loop_10;
            }
            return var_v0;
        }
block_12:
        M2C_FIELD(D_8006B54C, u16 *, 0x1AA) = (u16) ((M2C_FIELD(D_8006B54C, u16 *, 0x1AA) & 0xFFCF) | 0x20);
        return 0;
    }
}
