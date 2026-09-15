/* Exact retail word export for [80041E8C,80042154); EXE and assembly verified.
 * SHA256(span)=d8c5e7434724aac87991dc50599cd73b10c922e575d7d2e7b8be238291b8ee45. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

extern s32 D_8006B0F0;
extern s32 D_8006B0F4;
extern s32 D_8006B574;
extern s32 D_8006B57C;
extern s32 D_8006B5A8;
extern s32 D_8006B5AC;
extern s32 D_8006B5B0;
void func_800416A8(s32, s32, void *, s32 *);             /* static */

s32 func_80041E8C(s32 arg0) {
    s32 temp_a0;
    s32 temp_a0_2;
    s32 temp_a1;
    s32 temp_s0;
    s32 temp_s0_2;
    s32 temp_v1;
    s32 temp_v1_2;
    s32 var_a0;
    s32 var_s0;
    s32 var_s2;
    s32 var_s3;
    s32 var_v0;
    u32 temp_s1;
    u32 temp_t0;
    void *temp_a2;
    void *temp_v0;
    void *temp_v1_3;
    void *temp_v1_4;
    void *var_a0_2;

    var_s0 = 0;
    var_s2 = -1;
    if (D_8006B0F0 == 0) {
        var_s3 = 0;
    } else {
        var_s3 = (0x10000 - D_8006B0F4) << D_8006B574;
    }
    var_a0 = arg0;
    if (arg0 & ~D_8006B57C) {
        var_a0 = arg0 + D_8006B57C;
    }
    temp_s1 = (var_a0 >> D_8006B574) << D_8006B574;
    if (*D_8006B5B0 & 0x40000000) {
        var_s2 = 0;
    } else {
        func_800416A8(var_a0);
        if (D_8006B5A8 > 0) {
            var_a0_2 = (0 * 8) + D_8006B5B0;
loop_9:
            temp_v1 = var_a0_2->unk0;
            if ((temp_v1 & 0x40000000) || ((temp_v1 & 0x80000000) && ((u32) var_a0_2->unk4 >= temp_s1))) {
                var_s2 = var_s0;
            } else {
                var_s0 += 1;
                var_a0_2 += 8;
                if (var_s0 < D_8006B5A8) {
                    goto loop_9;
                }
            }
        }
    }
    var_v0 = -1;
    temp_s0 = var_s2 * 8;
    if (var_s2 != -1) {
        temp_a2 = temp_s0 + D_8006B5B0;
        temp_v1_2 = temp_a2->unk0;
        if (temp_v1_2 & 0x40000000) {
            var_v0 = -1;
            if (var_s2 < D_8006B5A8) {
                var_v0 = -1;
                if ((u32) (temp_a2->unk4 - var_s3) >= temp_s1) {
                    temp_a0 = var_s2 + 1;
                    temp_v1_3 = (temp_a0 * 8) + D_8006B5B0;
                    temp_v1_3->unk0 = (s32) (((temp_a2->unk0 & 0x0FFFFFFF) + temp_s1) | 0x40000000);
                    temp_v1_3->unk4 = (s32) (temp_a2->unk4 - temp_s1);
                    D_8006B5AC = temp_a0;
                    temp_a2->unk4 = temp_s1;
                    temp_a2->unk0 = (s32) (temp_a2->unk0 & 0x0FFFFFFF);
                    func_800416A8(temp_a0, 0x0FFFFFFF, temp_a2, D_8006B5B0);
                    return *(temp_s0 + D_8006B5B0);
                }
            }
            /* Duplicate return node #23. Try simplifying control flow for better match */
            return var_v0;
        }
        temp_t0 = temp_a2->unk4;
        if ((temp_s1 < temp_t0) && (D_8006B5AC < D_8006B5A8)) {
            temp_v0 = (D_8006B5AC * 8) + D_8006B5B0;
            temp_a1 = temp_v0->unk0;
            temp_a0_2 = temp_v0->unk4;
            temp_v0->unk0 = (s32) ((temp_v1_2 + temp_s1) | 0x80000000);
            temp_v0->unk4 = (s32) (temp_t0 - temp_s1);
            D_8006B5AC = (s32) (D_8006B5AC + 1);
            temp_v0->unk8 = temp_a1;
            temp_v0->unkC = temp_a0_2;
        }
        temp_s0_2 = var_s2 * 8;
        temp_v1_4 = temp_s0_2 + D_8006B5B0;
        temp_v1_4->unk4 = temp_s1;
        temp_v1_4->unk0 = (s32) (temp_v1_4->unk0 & 0x0FFFFFFF);
        func_800416A8(0x0FFFFFFF);
        var_v0 = *(temp_s0_2 + D_8006B5B0);
        /* Duplicate return node #23. Try simplifying control flow for better match */
        return var_v0;
    }
    return var_v0;
}
