/* Overlay range [80177940,80177AD4) from MAIN.CD member 0012.
 * SHA256(span)=85c239ad8ee3c7b442a1021b3619d2f4daa8777fa167f7b9108a0360516ef170.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

s32 func_80029504();                                /* extern */

void func_80177940(void *arg0, s32 arg1, s32 arg2, s32 arg3) {
    s16 temp_v0_2;
    s16 var_a3;
    s32 *var_a0;
    s32 temp_s1;
    s32 temp_v0;
    s32 var_s0;
    s32 var_s2;
    s32 var_t0;
    u32 temp_v0_3;
    void *var_a1;

    var_s0 = arg2;
    var_s2 = arg1;
    temp_v0 = -((u32) (func_80029504() - 0xA) < 0x4B0U) & 0xB4;
    temp_s1 = arg3 << 0x10;
    arg0->unk0 = (s32) (((arg0 - 0x14) & 0xFFFFFF) | 0x03000000);
    arg0->unk8 = (s32) (temp_s1 | ((var_s0 + 0xF) & 0xFFFF));
    arg0->unk4 = 0x74808080;
    arg0->unkC = (s32) ((((temp_v0 << 6) | 0x4016) << 0x10) | 0x3850);
    var_a0 = arg0 + 0x14;
    var_t0 = 0x01000000;
    var_a3 = 0;
    var_a1 = var_a0 + 0xC;
    do {
        temp_v0_3 = (u32) (var_s2 << 0x10) >> 0x1C;
        if ((temp_v0_3 != 0) || (var_a3 == 3) || (var_a3 == 1)) {
            var_t0 = 0;
        }
        *var_a0 = ((s32) (var_a0 - 0x14) & 0xFFFFFF) | 0x03000000;
        var_a1->unk-4 = (s32) (temp_s1 | (var_s0 & 0xFFFF) | var_t0);
        var_a1->unk-8 = 0x74808080;
        var_a1->unk0 = (s32) ((((temp_v0 << 6) | 0x4016) << 0x10) | (((temp_v0_3 * 8) + 8) | 0x4000));
        var_a1 += 0x14;
        var_a0 += 0x14;
        var_s0 += 8;
        temp_v0_2 = var_a3 + 1;
        var_a3 = temp_v0_2;
        var_s2 *= 0x10;
    } while (temp_v0_2 < 4);
    var_a0->unk-20 = (u16) (var_a0->unk-20 + 6);
    var_a0->unk-C = (u16) (var_a0->unk-C + 6);
}
