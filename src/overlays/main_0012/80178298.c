/* Overlay range [80178298,801783D0) from MAIN.CD member 0012.
 * SHA256(span)=877e1f8f1fc80ad2f24d89d606edc8d64e55129f8ba2fcd01675a091464bd149.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

s32 *func_80178298(s32 *arg0, u8 *arg1, s16 arg2, s16 arg3) {
    s16 temp_v1;
    s16 var_a2;
    s16 var_v0;
    s32 *var_t1;
    u8 *var_a1;
    u8 temp_v1_2;
    void *var_t0;

    var_a1 = arg1;
    var_a2 = arg2;
    var_t1 = arg0;
    if ((u8) *var_a1 < 0x80U) {
        var_t0 = arg0 + 0x12;
        do {
            temp_v1 = var_a1->unk0;
            if (temp_v1 != 0x3870) {
                if (temp_v1 < 0x3871) {
                    if (temp_v1 != 0x1850) {
                        var_v0 = var_a2 + 4;
                        if (temp_v1 != 0x1858) {
                            var_t0->unk-A = var_a2;
                            goto block_15;
                        }
                        goto block_11;
                    }
                    var_v0 = var_a2 + 4;
block_11:
                    var_t0->unk-A = var_v0;
                    var_t0->unk-8 = (s16) (arg3 - 7);
                    goto block_18;
                }
                if (temp_v1 != 0x3871) {
                    if (temp_v1 != 0x3872) {
                        var_t0->unk-A = var_a2;
block_15:
                        var_t0->unk-8 = arg3;
                        if (var_a1->unk0 >= 0x861) {
                            var_a2 += 8;
                        } else {
                            var_a2 += 7;
                        }
block_18:
                        *var_t1 = ((var_t1 - 0x14) & 0xFFFFFF) | 0x04000000;
                        var_t0->unk-E = 0x64808080;
                        var_t1 += 0x14;
                        var_t0->unk-6 = (u8) var_a1->unk0;
                        temp_v1_2 = var_a1->unk1;
                        var_a1 = var_a1 + 1 + 1;
                        var_t0->unk-4 = 0x4056;
                        var_t0->unk-2 = 8;
                        var_t0->unk0 = 8;
                        var_t0->unk-5 = temp_v1_2;
                        var_t0 += 0x14;
                    } else {
                        var_a2 += 2;
                        var_a1 += 2;
                    }
                } else {
                    var_a2 += 4;
                    var_a1 += 2;
                }
            } else {
                var_a2 += 8;
                var_a1 += 2;
            }
        } while ((u8) *var_a1 < 0x80U);
    }
    return var_t1;
}
