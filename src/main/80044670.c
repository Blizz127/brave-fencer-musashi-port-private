/* Exact retail word export for [80044670,80044A8C); EXE and assembly verified. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void D_8006CC84();                                     /* static */
void D_8006CC88();                                     /* static */
extern s32 D_8006CC90;
extern s32 D_8006CCA0;
extern s32 D_8006CCA5;
extern s32 D_8006CCAC;
extern s32 D_8006CD2C;
extern s32 D_8006CDCC;
extern s32 D_8006CECC;
extern s32 *D_8006CF4C;
extern s32 *D_8006CF50;
extern s32 *D_8006CF54;
extern s32 D_8006CF65;
extern s32 D_80073758;
extern s32 D_80073768;
extern s32 D_800737F4;
extern s32 D_800737FC;
extern s32 D_8007380C;
s32 func_8004239C();                               /* static */
s32 func_800426D4();                                /* static */
s32 func_80043B9C();                                /* static */
void func_80044124(s32, s32);                              /* static */
void func_80044B14();                                  /* static */
void func_8005C604(s32 (*)(), s32 (*)(), s32, s32, s32);   /* static */
void func_8005CD48(s32 (*)());                           /* static */
extern u8 D_8006CCA4;
extern s32 D_8006CF64;
extern u8 D_800763D8;
extern s32 *D_800763E0;
extern s32 D_800763F0;
extern s32 D_800763F4;
extern s32 (*D_800763F8)();

s32 func_80044670(u8 arg0, u8 *arg1, u8 *arg2, s32 arg3) {
    s32 *temp_v1_2;
    s32 temp_a0;
    s32 temp_v0_2;
    s32 temp_v1;
    s32 temp_v1_3;
    s32 var_a0;
    s32 var_a0_2;
    s32 var_v0;
    s32 var_v0_2;
    s32 var_v0_3;
    s32 var_v1;
    s32 var_v1_3;
    u8 *var_a0_3;
    u8 *var_a1;
    u8 *var_a2;
    u8 *var_v1_2;
    u8 temp_s1;
    u8 temp_v0;
    u8 temp_v0_3;

    if (D_8006CC90 >= 2) {
        func_8005C604(D_800737F4, *(D_8006CCAC + ((arg0 & 0xFF) * 4)));
    }
    temp_v1 = (arg0 & 0xFF) * 4;
    if ((*(D_8006CECC + temp_v1) != 0) && (arg1 == 0)) {
        var_v0 = -2;
        if (D_8006CC90 > 0) {
            func_8005C604(D_800737FC, *(D_8006CCAC + temp_v1));
            return -2;
        }
        /* Duplicate return node #41. Try simplifying control flow for better match */
        return var_v0;
    }
    func_80044124(0, 0);
    var_v1 = arg0 & 0xFF;
    if (var_v1 == 2) {
        var_a0 = 0;
        var_v1_2 = arg1;
        do {
            *(D_8006CCA0 + var_a0) = *var_v1_2;
            var_a0 += 1;
            var_v1_2 += 1;
        } while (var_a0 < 4);
        var_v1 = arg0 & 0xFF;
    }
    if (var_v1 == 0xE) {
        D_8006CCA4 = *arg1;
    }
    temp_a0 = var_v1 * 4;
    D_8006CF64.unk0 = 0U;
    if (*(D_8006CDCC + temp_a0) != 0) {
        D_8006CF65 = 0;
    }
    *D_8006CF4C = 0;
    temp_v1_2 = temp_a0 + (D_8006CDCC + 0x100);
    var_a0_2 = 0;
    if (*temp_v1_2 > 0) {
        var_a1 = arg1;
        do {
            temp_v0 = *var_a1;
            var_a1 += 1;
            *D_8006CF54 = temp_v0;
            var_a0_2 += 1;
        } while (var_a0_2 < *temp_v1_2);
    }
    D_8006CCA5 = arg0;
    *D_8006CF50 = arg0;
    var_v0 = 0;
    if (arg3 == 0) {
        D_800763F0 = func_8004239C(-1) + 0x3C0;
        D_800763F4 = 0;
        D_800763F8 = D_8007380C;
        var_a2 = arg2;
        if (D_8006CF64.unk0 == 0) {
loop_20:
            if ((D_800763F0 < func_8004239C(-1)) || (temp_v1_3 = D_800763F4, D_800763F4 = temp_v1_3 + 1, ((temp_v1_3 > 0x3C0000) != 0))) {
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
loop_27:
                    temp_v0_2 = func_80043B9C();
                    if (temp_v0_2 != 0) {
                        var_v0_3 = temp_v0_2 & 2;
                        if (temp_v0_2 & 4) {
                            if (D_8006CC88 != 0) {
                                D_8006CC88(D_8006CF64.unk1, &D_800763E0);
                            }
                            var_v0_3 = temp_v0_2 & 2;
                        }
                        if ((var_v0_3 != 0) && (D_8006CC84 != 0)) {
                            D_8006CC84(D_8006CF64.unk0, &D_800763D8);
                        }
                        goto loop_27;
                    }
                    *D_8006CF4C = temp_s1;
                }
                var_a2 = arg2;
                if (D_8006CF64.unk0 != 0) {
                    goto block_37;
                }
                goto loop_20;
            }
        } else {
block_37:
            var_a0_3 = &D_800763D8;
            if (var_a2 != 0) {
                var_v1_3 = 7;
                do {
                    temp_v0_3 = *var_a0_3;
                    var_a0_3 += 1;
                    var_v1_3 -= 1;
                    *var_a2 = temp_v0_3;
                    var_a2 += 1;
                } while (var_v1_3 != -1);
            }
            var_v0 = -(D_8006CF64.unk0 == 5);
        }
    }
    return var_v0;
}
