/* Exact retail word export for [80034314,80034650); EXE and assembly verified. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

extern s32 D_80068A54;
extern s32 D_8006AED8;
s32 func_8003310C(u16);                             /* static */
void func_80034650(void *, s32);                         /* static */
s32 func_800348A8(void *);                          /* static */
extern s32 *D_800A46E8;
extern void *D_800A4EE8;
extern s16 D_800A4EF0;

s32 func_80034314(u16 arg0, void *arg1, u32 arg2) {
    s32 (*var_v0_2)();
    s16 *var_a1_2;
    s16 var_v0_3;
    s32 temp_v0;
    s32 temp_v0_2;
    s32 var_a2;
    s32 var_s5;
    s32 var_v0;
    s32 var_v0_4;
    s32 var_v1;
    s8 *var_v1_2;
    u32 temp_v1_2;
    u8 temp_s4;
    u8 temp_v0_3;
    u8 temp_v1;
    void *temp_s1;
    void *temp_s3;
    void *var_a0;
    void *var_a1;
    void *var_s0;

    var_a1 = arg1;
    temp_s3 = var_a1;
    temp_s4 = temp_s3->unk1;
    if (temp_s4 == 0) {
        var_v0_2 = D_80068A54;
        var_v1 = temp_s3->unk3 * 0xC;
        goto block_5;
    }
    var_a1 = D_800A4EE8;
    var_v0 = 0;
    if (var_a1 != 0) {
        var_v0 = 0;
        if (D_800A4EF0 == temp_s4) {
            var_v0_2 = var_a1->unk18;
            var_v1 = temp_s3->unk3 * 0xC;
block_5:
            temp_s1 = var_v0_2 + var_v1;
            temp_v0 = func_800348A8(var_a1);
            var_s5 = temp_v0;
            if (temp_v0 != 0) {
                var_s0 = ((var_s5 - 1) * 0x54) + &D_800A46E8;
                if (arg2 & 0x1000) {
                    var_s0->unk22 = 1;
                    var_s0->unk1E = 0x100;
                    var_s0->unk20 = (s16) ((s32) ((arg2 & 0x7F) * 0x3FFF) >> 7);
                    if (arg2 & 0x2000) {
                        var_s0->unk38 = (u8) *(D_8006AED8 + ((arg2 >> 8) & 0xF));
                    } else {
                        var_s0->unk38 = 0U;
                        var_s0->unk39 = 0;
                    }
                    goto block_32;
                }
                var_v0 = 0;
                if (var_s0->unk8 == 0) {
                    func_80034650(var_s0, 0);
                    goto block_15;
                }
                /* Duplicate return node #33. Try simplifying control flow for better match */
                return var_v0;
            }
            temp_v0_2 = func_8003310C(temp_s1->unk4);
            var_s5 = temp_v0_2;
            if (temp_v0_2 == 0) {
                return 0;
            }
            var_s0 = ((var_s5 - 1) * 0x54) + &D_800A46E8;
block_15:
            var_s0->unk34 = (s16) temp_s4;
            var_s0->unk37 = (u8) temp_s1->unk8;
            var_s0->unkC = (s32) temp_s1->unk0;
            var_s0->unk4 = arg0;
            var_s0->unk6 = (s16) (arg0 >> 0x10);
            var_s0->unk14 = 1;
            var_s0->unk2 = (u16) temp_s1->unk4;
            var_s0->unk10 = (s32) var_s0->unkC;
            var_s0->unk16 = 0;
            var_s0->unk18 = 0x7FFF;
            var_s0->unk17 = (u8) temp_s3->unk2;
            var_s0->unk50 = 0;
            var_s0->unk52 = 0;
            var_s0->unk8 = (u16) temp_s1->unk6;
            if (temp_s1->unk8 & 0x10) {
                var_s0->unk48 = 1;
            } else {
                var_s0->unk48 = 0;
            }
            temp_v1 = temp_s1->unk8;
            var_v0_3 = 0x400;
            if (!(temp_v1 & 4)) {
                var_v0_3 = 0x200;
                if (!(temp_v1 & 8)) {
                    var_v0_3 = 0x5F;
                }
            }
            var_s0->unk1A = var_v0_3;
            var_s0->unk36 = 0;
            var_a1_2 = var_s0 + 0x1C;
            var_a2 = 0;
            temp_v1_2 = (u32) ((arg2 & 0x7F) * 0x3FFF) >> 7;
            var_a0 = var_s0 + 0x20;
            do {
                var_a0->unk-2 = 0x100;
                var_a0->unk2 = 0;
                if (var_a2 != 0) {
                    *var_a1_2 = 0x3FFF;
                    var_a0->unk0 = 0x3FFF;
                } else if (arg2 & 0x1000) {
                    *var_a1_2 = (s16) temp_v1_2;
                    var_a0->unk0 = (s16) temp_v1_2;
                    if (arg2 & 0x2000) {
                        temp_v0_3 = *(D_8006AED8 + ((arg2 >> 8) & 0xF));
                        var_s0->unk38 = temp_v0_3;
                        var_s0->unk39 = temp_v0_3;
                    }
                } else {
                    *var_a1_2 = 0x3FFF;
                    var_a0->unk0 = 0x3FFF;
                    var_s0->unk38 = 0U;
                    var_s0->unk39 = 0U;
                }
                var_a2 += 1;
                var_a0 += 8;
                var_a1_2 += 8;
            } while (var_a2 < 3);
            var_v1_2 = var_s0 + 0x3A;
            var_v0_4 = 7;
            do {
                *var_v1_2 = 0;
                var_v0_4 -= 1;
                var_v1_2 += 1;
            } while (var_v0_4 >= 0);
            var_s0->unk0 = 5;
block_32:
            var_v0 = var_s5;
            /* Duplicate return node #33. Try simplifying control flow for better match */
            return var_v0;
        }
    }
    return var_v0;
}
