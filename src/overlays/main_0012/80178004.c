/* Overlay range [80178004,80178298) from MAIN.CD member 0012.
 * SHA256(span)=05abbc84e40dd593100f2b2b37c71c8ee71243624095298673e6ad697ec146fd.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

s32 func_801783D0(s32, s32, s32, s32);                    /* static */
extern s16 D_8011F81E;

s32 *func_80178004(void *arg0, s32 arg1, s32 arg2) {
    s16 temp_v0;
    s16 var_a3;
    s32 *var_a0;
    s32 temp_s0;
    s32 var_s1;
    s32 var_t0;
    s32 var_t1;
    u32 temp_v0_2;
    void *temp_s2;
    void *temp_s2_2;
    void *temp_s2_3;
    void *temp_s2_4;
    void *temp_s2_5;
    void *var_a1;

    temp_s0 = arg2 << 0x10;
    arg0->unk0 = (s32) (((arg0 - 0x14) & 0xFFFFFF) | 0x03000000);
    arg0->unk4 = 0x74808080;
    arg0->unk8 = (s32) (temp_s0 | (arg1 & 0xFFFF));
    arg0->unkC = 0x6D165828;
    temp_s2 = arg0 + 0x14;
    arg0->unk14 = (s32) (((s32) (temp_s2 - 0x14) & 0xFFFFFF) | 0x03000000);
    temp_s2->unk4 = 0x74808080;
    temp_s2->unk8 = (s32) (temp_s0 | ((arg1 + 7) & 0xFFFF));
    temp_s2->unkC = 0x6D160048;
    temp_s2_2 = temp_s2 + 0x14;
    temp_s2->unk14 = (s32) (((s32) (temp_s2_2 - 0x14) & 0xFFFFFF) | 0x03000000);
    temp_s2_2->unk4 = 0x74808080;
    temp_s2_2->unk8 = (s32) (temp_s0 | ((arg1 + 0xD) & 0xFFFF));
    temp_s2_2->unkC = 0x6D160818;
    temp_s2_3 = temp_s2_2 + 0x14;
    temp_s2_2->unk14 = (s32) (((s32) (temp_s2_3 - 0x14) & 0xFFFFFF) | 0x03000000);
    temp_s2_3->unk4 = 0x74808080;
    temp_s2_3->unk8 = (s32) (temp_s0 | ((arg1 + 0x13) & 0xFFFF));
    temp_s2_3->unkC = 0x6D160028;
    temp_s2_4 = temp_s2_3 + 0x14;
    temp_s2_3->unk14 = (s32) (((s32) (temp_s2_4 - 0x14) & 0xFFFFFF) | 0x03000000);
    temp_s2_4->unk4 = 0x74808080;
    temp_s2_4->unk8 = (s32) (temp_s0 | ((arg1 + 0x19) & 0xFFFF));
    temp_s2_4->unkC = 0x6D160020;
    temp_s2_5 = temp_s2_4 + 0x14;
    temp_s2_4->unk14 = (s32) (((s32) (temp_s2_5 - 0x14) & 0xFFFFFF) | 0x03000000);
    temp_s2_5->unk4 = 0x74808080;
    temp_s2_5->unk8 = (s32) (temp_s0 | ((arg1 + 0x3A) & 0xFFFF));
    temp_s2_5->unkC = 0x6D164058;
    var_a0 = temp_s2_5 + 0x14;
    var_t0 = func_801783D0(0x64 - ((s32) (D_8011F81E * 0xA198) >> 0x10), 4, 0x6D164058, 0x6D165828);
    var_s1 = arg1 + 0x22;
    var_t1 = 0x01000000;
    var_a3 = 0;
    var_a1 = var_a0 + 0xC;
    do {
        temp_v0_2 = (u32) (var_t0 << 0x10) >> 0x1C;
        if ((temp_v0_2 != 0) || (var_a3 == 2) || (var_a3 == 0xFF)) {
            var_t1 = 0;
        }
        *var_a0 = ((s32) (var_a0 - 0x14) & 0xFFFFFF) | 0x03000000;
        var_a1->unk-4 = (s32) (temp_s0 | (var_s1 & 0xFFFF) | var_t1);
        var_a1->unk-8 = 0x74808080;
        var_a1->unk0 = (s32) (0x6D160000 | (((temp_v0_2 * 8) + 8) | 0x4000));
        var_a1 += 0x14;
        var_a0 += 0x14;
        var_s1 += 8;
        temp_v0 = var_a3 + 1;
        var_a3 = temp_v0;
        var_t0 *= 0x10;
    } while (temp_v0 < 3);
    return var_a0;
}
