/* Main-exec range [8002374C,80023BF0) from the SLUS executable.
 * SHA256(span)=b431c7ac5aa9f1cd70da90f0900404a6e76e270c12eea7ce46034312c673994d.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

s32 func_80058B40(s32, s32, s32, s32);                    /* static */
void func_8005A600(s32 *, s32, s32, s32, s32);             /* static */
extern s32 *D_800A5E60;
extern s32 *D_800A6610;
extern u16 D_800B9A02;

void func_8002374C(void *arg0) {
    u16 sp20;
    void *sp18;
    s32 var_a2;
    s32 *temp_a0_14;
    s32 *var_s0;
    s32 temp_a0;
    s32 temp_a0_10;
    s32 temp_a0_11;
    s32 temp_a0_12;
    s32 temp_a0_13;
    s32 temp_a0_2;
    s32 temp_a0_3;
    s32 temp_a0_4;
    s32 temp_a0_5;
    s32 temp_a0_6;
    s32 temp_a0_7;
    s32 temp_a0_8;
    s32 temp_a0_9;
    s32 temp_s5;
    s32 temp_s6;
    s32 var_a0;
    s32 var_s3_2;
    s32 var_v0;
    s32 var_v0_2;
    u32 *var_s7;
    u32 temp_v1;
    u32 var_s1;
    u32 var_s3;
    void *var_s2;

    if (arg0->unk4 >= 0) {
        var_s7 = arg0->unk20;
        temp_s6 = arg0->unk8 - arg0->unk2E;
        temp_s5 = arg0->unkA - arg0->unk30;
        var_s3 = *var_s7;
        sp18 = (D_800B9A02 << 0xE) + &D_800A6610;
        var_s1 = var_s3;
        sp20 = arg0->unk2C;
        if (var_s3 != 0) {
            var_s2 = var_s7 + 0xC;
            do {
                var_s3_2 = var_s3 << 0x18;
                if (var_s1 & 0x40000000) {
                    var_s3_2 |= 0x02000000;
                }
                var_s0 = D_800A5E60;
                if (var_s1 & 0x800000) {
                    var_v0 = func_80058B40(2, (var_s1 >> 0x1C) & 3, 0x280, 0);
                    var_a2 = 1;
                } else {
                    var_v0 = func_80058B40(2, (var_s1 >> 0x1C) & 3, 0x280, 0);
                    var_a2 = 0;
                }
                func_8005A600(var_s0, 0, var_a2, var_v0 & 0xFFFF);
                temp_v1 = var_s1 & 0xFF;
                if (temp_v1 != 0x38) {
                    if (temp_v1 < 0x39U) {
                        if (temp_v1 != 0x30) {

                        } else {
                            D_800A5E60 += 0x2C;
                            func_8005A600(D_800A5E60 - 0xC, 0, 0, func_80058B40(2, (var_s1 >> 0x1C) & 3, 0x280, 0) & 0xFFFF, 0);
                            *var_s0 = 0x0A000000;
                            var_s0 += 8;
                            var_s0->unk4 = (s32) (var_s3_2 | (var_s2->unk4 & 0xFFFFFF));
                            var_s0->unkC = (s32) var_s2->unk8;
                            var_s0->unk14 = (s32) var_s2->unkC;
                            temp_a0 = var_s2->unk-8;
                            temp_a0_2 = (temp_a0 & 0xFFFF0000) | ((temp_s6 + temp_a0) & 0xFFFF);
                            var_s0->unk8 = (s32) ((temp_a0_2 & 0xFFFF) | ((temp_s5 + (temp_a0_2 >> 0x10)) << 0x10));
                            temp_a0_3 = var_s2->unk-4;
                            temp_a0_4 = (temp_a0_3 & 0xFFFF0000) | ((temp_s6 + temp_a0_3) & 0xFFFF);
                            var_s0->unk10 = (s32) ((temp_a0_4 & 0xFFFF) | ((temp_s5 + (temp_a0_4 >> 0x10)) << 0x10));
                            temp_a0_5 = var_s2->unk0;
                            temp_a0_6 = (temp_a0_5 & 0xFFFF0000) | ((temp_s6 + temp_a0_5) & 0xFFFF);
                            var_a0 = temp_a0_6 & 0xFFFF;
                            var_v0_2 = (temp_s5 + (temp_a0_6 >> 0x10)) << 0x10;
                            goto block_16;
                        }
                    } else if (temp_v1 == 0x60) {
                        D_800A5E60 += 0x20;
                        func_8005A600(D_800A5E60 - 0xC, 0, 0, func_80058B40(2, (var_s1 >> 0x1C) & 3, 0x280, 0) & 0xFFFF, 0);
                        *var_s0 = 0x07000000;
                        var_s0 += 8;
                        var_s0->unk4 = (s32) (var_s3_2 | (var_s2->unk0 & 0xFFFFFF));
                        temp_a0_7 = var_s2->unk-8;
                        temp_a0_8 = (temp_a0_7 & 0xFFFF0000) | ((temp_s6 + temp_a0_7) & 0xFFFF);
                        var_s0->unk8 = (s32) ((temp_a0_8 & 0xFFFF) | ((temp_s5 + (temp_a0_8 >> 0x10)) << 0x10));
                        var_s0->unkC = (s32) var_s2->unk-4;
                    }
                } else {
                    D_800A5E60 += 0x34;
                    func_8005A600(D_800A5E60 - 0xC, 0, 0, func_80058B40(2, (var_s1 >> 0x1C) & 3, 0x280, 0) & 0xFFFF, 0);
                    *var_s0 = 0x0C000000;
                    var_s0 += 8;
                    var_s0->unk4 = (s32) (var_s3_2 | (var_s2->unk0 & 0xFFFFFF));
                    var_s0->unkC = (s32) var_s2->unk4;
                    var_s0->unk14 = (s32) var_s2->unk8;
                    var_s0->unk1C = (s32) var_s2->unkC;
                    temp_a0_9 = var_s2->unk-8;
                    temp_a0_10 = (temp_a0_9 & 0xFFFF0000) | ((temp_s6 + temp_a0_9) & 0xFFFF);
                    temp_a0_11 = (temp_a0_10 & 0xFFFF) | ((temp_s5 + (temp_a0_10 >> 0x10)) << 0x10);
                    var_s0->unk8 = temp_a0_11;
                    temp_a0_12 = (temp_a0_11 & 0xFFFF0000) | (((u16) var_s2->unk-4 + temp_a0_11) & 0xFFFF);
                    var_s0->unk10 = temp_a0_12;
                    temp_a0_13 = (temp_a0_12 & 0xFFFF) | ((var_s2->unk-2 + (temp_a0_12 >> 0x10)) << 0x10);
                    var_s0->unk20 = temp_a0_13;
                    var_a0 = temp_a0_13 & 0xFFFF0000;
                    var_v0_2 = (temp_a0_13 - (u16) var_s2->unk-4) & 0xFFFF;
block_16:
                    var_s0->unk18 = (s32) (var_a0 | var_v0_2);
                }
                var_s7 += 0x1C;
                temp_a0_14 = (sp20 * 4) + sp18;
                var_s0->unk-8 = (s32) ((var_s0->unk-8 & 0xFF000000) | (*temp_a0_14 & 0xFFFFFF));
                *temp_a0_14 = (*temp_a0_14 & 0xFF000000) | ((s32) (var_s0 - 8) & 0xFFFFFF);
                var_s3 = *var_s7;
                var_s2 += 0x1C;
                var_s1 = var_s3;
            } while (var_s3 != 0);
        }
    }
}
