/* Exact retail word export for [80045374,80045640); EXE-verified. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

extern s32 D_8006CC90;
extern s32 D_8006CC9C;
extern s32 D_8006CF98;
extern s32 D_8007386C;
extern s32 D_80073888;
extern s32 D_800738A0;
extern s32 D_800738BC;
extern s32 D_800738DC;
extern s32 D_800738E8;
s32 func_80045640(void *, u8 *);                       /* static */
s32 func_80045660();                                /* static */
s32 func_80045940(s32, u8 *);                       /* static */
s32 func_800459E8(s32);                             /* static */
void func_8005C604(s32 (*)(), u8 *, s32);                /* static */
extern s32 *D_80076408;

void *func_80045374(void *arg0, u8 *arg1) {
    u8 sp10;
    s32 (*var_a0_2)();
    void *var_s3;
    s32 var_a0;
    s32 var_s1_2;
    s32 var_s2;
    s32 var_s2_2;
    s32 var_v0;
    u8 *var_a1_2;
    u8 *var_s0_2;
    u8 *var_s1;
    u8 var_a1;
    void *var_s0;

    if (D_8006CF98 != D_8006CC9C) {
        if (func_80045660() != 0) {
            D_8006CF98 = (s32) D_8006CC9C;
            goto block_3;
        }
        /* Duplicate return node #36. Try simplifying control flow for better match */
        return 0;
    }
block_3:
    var_a0 = 1;
    if (*arg1 != 0x5C) {
        return 0;
    }
    sp10 = 0;
    var_s0_2 = arg1;
    var_s2 = 0;
loop_7:
    var_a1 = *var_s0_2;
    var_s1 = &sp10;
    if ((var_a1 & 0xFF) != 0x5C) {
loop_8:
        if (var_a1 != 0) {
            var_s0_2 += 1;
            *var_s1 = var_a1;
            var_a1 = *var_s0_2;
            var_s1 += 1;
            if (var_a1 == 0x5C) {
                goto block_10;
            }
            goto loop_8;
        }
        goto block_13;
    }
block_10:
    var_v0 = var_s2 < 8;
    if (*var_s0_2 != 0) {
        var_s0_2 += 1;
        *var_s1 = 0;
        var_a0 = func_80045940(var_a0, &sp10);
        if (var_a0 != -1) {
            var_s2 += 1;
            if (var_s2 >= 8) {
                goto block_13;
            }
            goto loop_7;
        }
        sp10 = 0;
block_13:
        var_v0 = var_s2 < 8;
    }
    if (var_v0 == 0) {
        if (D_8006CC90 > 0) {
            func_8005C604(D_8007386C, arg1, var_s2);
            return 0;
        }
        goto block_35;
    }
    if (sp10 == 0) {
        var_a1_2 = arg1;
        if (D_8006CC90 > 0) {
            var_a0_2 = D_80073888;
            goto block_34;
        }
        goto block_35;
    }
    *var_s1 = 0;
    if (func_800459E8(var_a0) == 0) {
        if (D_8006CC90 > 0) {
            func_8005C604(D_800738A0);
            return 0;
        }
        /* Duplicate return node #36. Try simplifying control flow for better match */
        return 0;
    }
    var_s2_2 = 0;
    if (D_8006CC90 >= 2) {
        func_8005C604(D_800738BC, &sp10);
        var_s2_2 = 0;
    }
    var_s0 = &D_80076408 - 8;
    var_s3 = &D_80076408;
    var_s1_2 = 0;
loop_26:
    if (*(&D_80076408 + var_s1_2) != 0) {
        if (func_80045640(var_s3, &sp10) != 0) {
            if (D_8006CC90 >= 2) {
                func_8005C604(D_800738DC, &sp10);
            }
            arg0->unk0 = (s32) var_s0->unk0;
            arg0->unk4 = (s32) var_s0->unk4;
            arg0->unk8 = (s32) var_s0->unk8;
            arg0->unkC = (s32) var_s0->unkC;
            arg0->unk10 = (s32) var_s0->unk10;
            arg0->unk14 = (s32) var_s0->unk14;
            return var_s0;
        }
        var_s0 += 0x18;
        var_s3 += 0x18;
        var_s2_2 += 1;
        var_s1_2 += 0x18;
        if (var_s2_2 >= 0x40) {
            goto block_32;
        }
        goto loop_26;
    }
block_32:
    var_a1_2 = &sp10;
    if (D_8006CC90 > 0) {
        var_a0_2 = D_800738E8;
block_34:
        func_8005C604(var_a0_2, var_a1_2);
    }
block_35:
    return 0;
}
