/* Exact retail word export for [800416A8,800419B0); EXE and assembly verified. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

extern s32 D_8006B5AC;
extern s32 D_8006B5B0;

void func_800416A8(void) {
    s32 *var_v1;
    s32 temp_a1_2;
    s32 temp_a3;
    s32 temp_v1;
    s32 temp_v1_2;
    s32 temp_v1_3;
    s32 temp_v1_4;
    s32 temp_v1_5;
    s32 var_a2;
    s32 var_a2_2;
    s32 var_t1;
    s32 var_t1_2;
    s32 var_t1_3;
    s32 var_t1_4;
    s32 var_t1_5;
    void *temp_a1;
    void *temp_v0;
    void *var_a0;
    void *var_a0_2;
    void *var_a0_3;
    void *var_a3;
    void *var_t2;
    void *var_v1_2;

    var_t1 = 0;
    if (D_8006B5AC >= 0) {
        var_a3 = D_8006B5B0;
        do {
            var_a2 = var_t1 + 1;
            if (M2C_FIELD(var_a3, s32 *, 0) & 0x80000000) {
                var_v1 = (var_a2 * 8) + D_8006B5B0;
loop_4:
                var_v1 += 8;
                if (*var_v1 == 0x2FFFFFFF) {
                    var_a2 += 1;
                    goto loop_4;
                }
                temp_a1 = (var_a2 * 8) + D_8006B5B0;
                temp_v1 = M2C_FIELD(temp_a1, s32 *, 0);
                if ((temp_v1 & 0x80000000) && ((temp_v1 & 0x0FFFFFFF) == ((M2C_FIELD(var_a3, s32 *, 0) & 0x0FFFFFFF) + M2C_FIELD(var_a3, s32 *, 4)))) {
                    M2C_FIELD(temp_a1, s32 *, 0) = 0x2FFFFFFF;
                    M2C_FIELD(var_a3, s32 *, 4) = (s32) (M2C_FIELD(var_a3, s32 *, 4) + M2C_FIELD(temp_a1, s32 *, 4));
                } else {
                    goto block_9;
                }
            } else {
block_9:
                var_a3 += 8;
                var_t1 += 1;
            }
        } while (D_8006B5AC >= var_t1);
    }
    var_t1_2 = 0;
    if (D_8006B5AC >= 0) {
        var_v1_2 = D_8006B5B0;
        do {
            if (M2C_FIELD(var_v1_2, s32 *, 4) == 0) {
                M2C_FIELD(var_v1_2, s32 *, 0) = 0x2FFFFFFF;
            }
            var_t1_2 += 1;
            var_v1_2 += 8;
        } while (D_8006B5AC >= var_t1_2);
    }
    var_t1_3 = 0;
    if (D_8006B5AC >= 0) {
        var_t2 = D_8006B5B0;
loop_19:
        if (!(M2C_FIELD(var_t2, s32 *, 0) & 0x40000000)) {
            var_a2_2 = var_t1_3 + 1;
            if (D_8006B5AC >= var_a2_2) {
                var_a0 = (var_a2_2 * 8) + D_8006B5B0;
loop_22:
                temp_a1_2 = M2C_FIELD(var_a0, s32 *, 0);
                if (!(temp_a1_2 & 0x40000000)) {
                    temp_a3 = M2C_FIELD(var_t2, s32 *, 0);
                    if ((u32) (temp_a1_2 & 0x0FFFFFFF) < (u32) (temp_a3 & 0x0FFFFFFF)) {
                        M2C_FIELD(var_t2, s32 *, 0) = temp_a1_2;
                        temp_v1_2 = M2C_FIELD(var_t2, s32 *, 4);
                        M2C_FIELD(var_t2, s32 *, 4) = (s32) M2C_FIELD(var_a0, s32 *, 4);
                        M2C_FIELD(var_a0, s32 *, 0) = temp_a3;
                        M2C_FIELD(var_a0, s32 *, 4) = temp_v1_2;
                    }
                    var_a2_2 += 1;
                    var_a0 += 8;
                    if (D_8006B5AC >= var_a2_2) {
                        goto loop_22;
                    }
                }
            }
            var_t1_3 += 1;
            var_t2 += 8;
            if (D_8006B5AC >= var_t1_3) {
                goto loop_19;
            }
        }
    }
    var_t1_4 = 0;
    if (D_8006B5AC >= 0) {
        var_a0_2 = D_8006B5B0;
loop_29:
        temp_v1_3 = M2C_FIELD(var_a0_2, s32 *, 0);
        if (!(temp_v1_3 & 0x40000000)) {
            if (temp_v1_3 == 0x2FFFFFFF) {
                temp_v0 = (D_8006B5AC * 8) + D_8006B5B0;
                M2C_FIELD(var_a0_2, s32 *, 0) = (s32) M2C_FIELD(temp_v0, s32 *, 0);
                D_8006B5AC = var_t1_4;
                M2C_FIELD(var_a0_2, s32 *, 4) = (s32) M2C_FIELD(temp_v0, s32 *, 4);
            } else {
                var_t1_4 += 1;
                var_a0_2 += 8;
                if (D_8006B5AC >= var_t1_4) {
                    goto loop_29;
                }
            }
        }
    }
    var_t1_5 = D_8006B5AC - 1;
    if (var_t1_5 >= 0) {
        var_a0_3 = (var_t1_5 * 8) + D_8006B5B0;
loop_35:
        temp_v1_4 = M2C_FIELD(var_a0_3, s32 *, 0);
        if (temp_v1_4 & 0x80000000) {
            temp_v1_5 = D_8006B5AC;
            M2C_FIELD(var_a0_3, s32 *, 0) = (s32) ((temp_v1_4 & 0x0FFFFFFF) | 0x40000000);
            D_8006B5AC = var_t1_5;
            var_t1_5 -= 1;
            M2C_FIELD(var_a0_3, s32 *, 4) = (s32) (M2C_FIELD(var_a0_3, s32 *, 4) + M2C_FIELD(((temp_v1_5 * 8) + D_8006B5B0), s32 *, 4));
            var_a0_3 -= 8;
            if (var_t1_5 >= 0) {
                goto loop_35;
            }
        }
    }
}
