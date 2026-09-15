/* Exact retail word export for [800443A4,80044670); EXE-verified. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void D_8006CC84();                                     /* static */
void D_8006CC88();                                     /* static */
extern s32 D_8006CCA5;
extern s32 D_8006CCAC;
extern s32 D_8006CD2C;
extern s32 *D_8006CF4C;
extern s32 D_80073758;
extern s32 D_80073768;
extern s32 D_800737E8;
s32 func_8004239C();                               /* static */
s32 func_800426D4();                                /* static */
s32 func_80043B9C();                                /* static */
void func_80044B14();                                  /* static */
void func_8005C604(s32 (*)(), s32 (*)(), s32, s32, s32);   /* static */
void func_8005CD48(s32 (*)());                           /* static */
extern s32 D_8006CF64;
extern s32 *D_800763D8;
extern u8 D_800763E0;
extern u8 D_800763E8;
extern s32 D_800763F0;
extern s32 D_800763F4;
extern s32 (*D_800763F8)();

s32 func_800443A4(s32 arg0, u8 *arg1) {
    s32 temp_v0;
    s32 temp_v1;
    s32 var_a2;
    s32 var_v0;
    s32 var_v0_2;
    s32 var_v0_3;
    s32 var_v1;
    s32 var_v1_2;
    u8 *var_a0;
    u8 *var_a0_2;
    u8 *var_a1;
    u8 *var_a1_2;
    u8 temp_s1;
    u8 temp_v0_2;
    u8 temp_v0_3;
    void *temp_s3;

    temp_s3 = &D_8006CF64 + 2;
    D_800763F0 = func_8004239C(-1) + 0x3C0;
    D_800763F4 = 0;
    D_800763F8 = D_800737E8;
loop_1:
    if ((D_800763F0 < func_8004239C(-1)) || (temp_v1 = D_800763F4, D_800763F4 = temp_v1 + 1, ((temp_v1 > 0x3C0000) != 0))) {
        func_8005CD48(D_80073758);
        func_8005C604(D_80073768, D_800763F8, *(D_8006CCAC + (D_8006CCA5 * 4)), *((D_8006CF64.unk0 * 4) + D_8006CD2C), *((D_8006CF64.unk1 * 4) + D_8006CD2C));
        func_80044B14();
        var_v0_2 = -1;
    } else {
        var_v0_2 = 0;
    }
    var_v0 = -1;
    if (var_v0_2 == 0) {
        if (func_800426D4() != 0) {
            temp_s1 = *D_8006CF4C & 3;
loop_8:
            temp_v0 = func_80043B9C();
            if (temp_v0 != 0) {
                var_v0_3 = temp_v0 & 2;
                if (temp_v0 & 4) {
                    if (D_8006CC88 != 0) {
                        D_8006CC88(D_8006CF64.unk1, &D_800763E0);
                    }
                    var_v0_3 = temp_v0 & 2;
                }
                if ((var_v0_3 != 0) && (D_8006CC84 != 0)) {
                    D_8006CC84(D_8006CF64.unk0, &D_800763D8);
                }
                goto loop_8;
            }
            *D_8006CF4C = temp_s1;
        }
        var_a2 = D_8006CF64.unk2 & 0xFF;
        if (var_a2 != 0) {
            D_8006CF64.unk2 = 0U;
            var_a0 = &D_800763E8;
            var_a1 = arg1;
            if (arg1 != 0) {
                var_v1 = 7;
                do {
                    temp_v0_2 = *var_a0;
                    var_a0 += 1;
                    var_v1 -= 1;
                    *var_a1 = temp_v0_2;
                    var_a1 += 1;
                } while (var_v1 != -1);
                return var_a2;
            }
            goto block_26;
        }
        var_a2 = temp_s3->unk-1 & 0xFF;
        if (var_a2 != 0) {
            temp_s3->unk-1 = 0U;
            var_a1_2 = arg1;
            var_a0_2 = &D_800763E0;
            var_v1_2 = 7;
            if (var_a1_2 != 0) {
                do {
                    temp_v0_3 = *var_a0_2;
                    var_a0_2 += 1;
                    var_v1_2 -= 1;
                    *var_a1_2 = temp_v0_3;
                    var_a1_2 += 1;
                } while (var_v1_2 != -1);
            }
block_26:
            return var_a2;
        }
        var_v0 = 0;
        if (arg0 != 0) {
            /* Duplicate return node #28. Try simplifying control flow for better match */
            return var_v0;
        }
        goto loop_1;
    }
    return var_v0;
}
