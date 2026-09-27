/* Exact retail word export for [80045660,80045940); EXE-verified. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

extern s32 D_8006CC90;
extern s32 D_8006CF94;
extern s32 D_800738F8;
extern s32 D_80073924;
extern s32 D_8007392C;
extern s32 D_8007395C;
extern s32 D_80073980;
extern s32 D_800739A0;
extern s32 D_800739B4;
s32 func_80045C94(s32, s32, void *);                     /* static */
void func_8005C324(void *, void *, u8, s32);           /* static */
s32 func_8005C584(void *, s32 (*)(), s32);              /* static */
void func_8005C604(s32 (*)(), s32, s32, s32, void *);    /* static */
extern s32 *D_80076A00;
extern s32 *D_80076A04;
extern s32 *D_80076A08;
extern s32 *D_80078000;
extern s32 *D_80078800;

s32 func_80045660(void) {
    s32 sp1B;
    void *var_s1;
    s32 temp_s0;
    s32 temp_s3;
    s32 temp_v0;
    s32 var_a3;
    s32 var_v0;
    u8 temp_v1;
    void *temp_s2;
    void *temp_v0_2;

    temp_v0 = func_80045C94(1, 0x10, &D_80078000);
    if (temp_v0 != 1) {
        var_v0 = 0;
        if (D_8006CC90 > 0) {
            func_8005C604(D_800738F8);
            return 0;
        }
        /* Duplicate return node #22. Try simplifying control flow for better match */
        return var_v0;
    }
    if (func_8005C584(&D_80078000 + 1, D_80073924, 5) != 0) {
        var_v0 = 0;
        if (D_8006CC90 > 0) {
            func_8005C604(D_8007392C);
            return 0;
        }
        /* Duplicate return node #22. Try simplifying control flow for better match */
        return var_v0;
    }
    sp1B = (unaligned s32) M2C_ERROR(/* Unable to handle lwr; missing a corresponding lwl */);
    if (func_80045C94(1, (s32) sp18, &D_80078000) != temp_v0) {
        var_v0 = 0;
        if (D_8006CC90 > 0) {
            func_8005C604(D_8007395C, (s32) sp18);
            return 0;
        }
        /* Duplicate return node #22. Try simplifying control flow for better match */
        return var_v0;
    }
    var_s1 = &D_80078000;
    if (D_8006CC90 >= 2) {
        func_8005C604(D_80073980);
    }
    var_a3 = 0;
    if ((u32) &D_80078000 < (u32) (&D_80078000 + 0x800)) {
loop_13:
        if (var_s1->unk0 != 0) {
            temp_s0 = var_a3 * 0x2C;
            temp_v0_2 = temp_s0 + &D_80076A08;
            temp_v0_2->unk3 = (unaligned s32) (first 3 bytes) var_s1->unk0;
            temp_v0_2->unk-2 = (first 3 bytes) var_s1->unk0;
            temp_s2 = temp_s0 + (&D_80076A08 + 4);
            temp_s3 = var_a3 + 1;
            *(&D_80076A00 + temp_s0) = temp_s3;
            *(&D_80076A04 + temp_s0) = (s32) var_s1->unk6;
            func_8005C324(temp_s2, var_s1 + 8, var_s1->unk0, var_a3);
            *(temp_s2 + var_s1->unk0) = 0;
            temp_v1 = var_s1->unk0;
            var_s1 += temp_v1 + ((temp_v1 & 1) + 8);
            if (D_8006CC90 >= 2) {
                func_8005C604(D_800739A0, *(&D_80076A08 + temp_s0), *(&D_80076A00 + temp_s0), *(&D_80076A04 + temp_s0), temp_s2);
            }
            var_a3 = temp_s3;
            if (var_a3 < 0x80) {
                if ((u32) var_s1 >= (u32) &D_80078800) {
                    goto block_18;
                }
                goto loop_13;
            }
        } else {
            goto block_18;
        }
    } else {
block_18:
        if (var_a3 < 0x80) {
            *(&D_80076A04 + (var_a3 * 0x2C)) = 0;
        }
    }
    D_8006CF94 = 0;
    var_v0 = 1;
    if (D_8006CC90 >= 2) {
        func_8005C604(D_800739B4, var_a3);
        var_v0 = 1;
    }
    return var_v0;
}
