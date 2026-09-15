/* Exact retail word export for [8001971C,80019930); EXE-verified. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

extern s32 D_80062C38;
extern s32 D_80062C68;
extern s32 D_80063058;
extern s32 D_80063074;
extern s32 D_800747D0;
extern s32 D_800747D4;
extern s32 D_800747D8;
void func_80019990();                                  /* static */
s32 func_80019A24(s32 (*)(), s32, s32, s32);                /* static */
void func_8004239C();                                 /* static */
void func_80043A18(s32, void *, s32);                  /* static */
s32 func_80043B1C(void *);                          /* static */
s32 func_80045374(s32 (*)(), void *);                 /* static */
extern s32 *D_800AE830;
extern s32 *D_800AE834;
extern s32 *D_80180000;
extern s32 *D_80180004;

void func_8001971C(void) {
    s32 sp2C;
    s32 sp28;
    s32 sp20;
    s32 (*var_a0)();
    s32 *var_s1_2;
    s32 *var_s6;
    s32 temp_a0;
    s32 temp_v0;
    s32 temp_v0_2;
    s32 temp_v0_3;
    s32 var_a2;
    s32 var_fp;
    s32 var_s0;
    s32 var_s1;
    s32 var_s2;
    s32 var_s3;
    s32 var_s5;
    s32 var_s5_3;
    s32 var_s7;
    s32 var_v1;
    u32 var_s5_2;
    void *var_s4;

    func_80019990();
    var_s5 = 0;
loop_1:
    temp_v0 = func_80045374(D_80063058, D_80063058 - 0x14);
    var_s5 += 1;
    if (temp_v0 == -1) {
        if (var_s5 < 0x10) {
            goto loop_1;
        }
    }
    var_s5_2 = 0;
    var_s1 = 0;
    D_800747D0 = (s32) (temp_v0 != 0);
    D_800747D4 = 1;
    D_80063074 = 0;
    D_800747D8 = 0;
    do {
        var_a0 = var_s1 + D_80062C38;
loop_5:
        var_a0 = var_s1 + D_80062C38;
        if ((u32) (func_80045374(var_a0, D_80062C38 - 0x14 + var_s1) + 1) < 2U) {
            goto loop_5;
        }
        var_s5_2 += 1;
        var_s1 += 0x30;
    } while (var_s5_2 < 0x15U);
loop_7:
    var_fp = 0;
    if (func_80019A24(D_80062C38, 0x80180000, 0xE40, 0) == 0) {
        func_8004239C(0);
        goto loop_7;
    }
    var_s7 = 0;
    var_s5_3 = 0;
    sp20 = 0;
    var_s6 = &D_80180000;
    do {
        var_v1 = *var_s6;
        var_s7 += 1;
        var_s3 = 0;
        var_a2 = func_80043B1C(sp20 + D_80062C68);
        if (var_v1 > 0) {
            temp_v0_2 = var_fp * 8;
            var_s4 = temp_v0_2 + &D_800AE830;
            var_s2 = temp_v0_2;
            temp_v0_3 = var_s7 * 8;
            var_s1_2 = temp_v0_3 + &D_80180000;
            var_s0 = temp_v0_3;
            do {
                temp_a0 = *var_s1_2;
                if (temp_a0 != 0) {
                    sp28 = var_v1;
                    sp2C = var_a2;
                    func_80043A18(temp_a0 + var_a2, var_s4, var_a2);
                    *(&D_800AE834 + var_s2) = *(var_s0 + &D_80180004);
                }
                var_s0 += 8;
                var_s6 += 8;
                var_s7 += 1;
                var_s4 += 8;
                var_s2 += 8;
                var_s3 += 1;
                var_fp += 1;
            } while (var_s3 < var_v1);
        }
        var_s5_3 += 1;
        sp20 += 0x30;
    } while (var_s5_3 < 8);
}
