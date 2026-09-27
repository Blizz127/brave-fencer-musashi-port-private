/* Overlay range [80177B5C,80177DA8) from MAIN.CD member 0012.
 * SHA256(span)=919bbd1da96631d5c76e8153345aac34d01214c7786078a79360e95e93317a12.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

extern s32 D_80181B64;

void *func_80177B5C(void *arg0, s32 arg1, s16 arg2, s32 arg3, s32 arg4) {
    s16 temp_v0;
    s16 var_t4;
    s32 *var_a2;
    s32 temp_a0;
    s32 temp_a1;
    s32 temp_a1_2;
    s32 temp_v1;
    s32 temp_v1_2;
    s32 var_t5;
    s32 var_t6;
    s32 var_t7;
    u32 temp_v0_2;
    u8 temp_t9;
    void *temp_t3;
    void *temp_t3_2;
    void *var_a1;

    var_t6 = arg1;
    var_t5 = arg3 + 0xE;
    var_t7 = 0x01000000;
    var_t4 = 0;
    temp_t9 = *(D_80181B64 + arg2);
    arg0->unk0 = (s32) (((arg0 - 0x14) & 0xFFFFFF) | 0x03000000);
    arg0->unk4 = 0x74808080;
    temp_a1 = ((s16) arg4 + 1) << 0x10;
    temp_v1 = ((temp_t9 << 6) | 0x4016) << 0x10;
    arg0->unk8 = (s32) (temp_a1 | ((arg3 - 3) & 0xFFFF));
    arg0->unkC = (s32) (temp_v1 | 0x1800);
    temp_t3_2 = arg0 + 0x14;
    arg0->unk14 = (s32) (((s32) (temp_t3_2 - 0x14) & 0xFFFFFF) | 0x03000000);
    temp_t3_2->unk4 = 0x74808080;
    temp_t3_2->unk8 = (s32) (temp_a1 | ((arg3 + 5) & 0xFFFF));
    temp_t3_2->unkC = (s32) (temp_v1 | 0x1808);
    var_a2 = temp_t3_2 + 0x14;
    var_a1 = var_a2 + 0xC;
    do {
        temp_v0_2 = (u32) (var_t6 << 0x10) >> 0x1C;
        if ((temp_v0_2 != 0) || (var_t4 == 2) || (var_t4 == 0xFF)) {
            var_t7 = 0;
        }
        *var_a2 = ((s32) (var_a2 - 0x14) & 0xFFFFFF) | 0x03000000;
        var_a1->unk-4 = (s32) (((s16) arg4 << 0x10) | (var_t5 & 0xFFFF) | var_t7);
        var_a1->unk-8 = 0x74808080;
        var_a1->unk0 = (s32) (temp_v1 | (((temp_v0_2 * 8) + 8) | 0x4000));
        var_a1 += 0x14;
        var_a2 += 0x14;
        var_t5 += 8;
        temp_v0 = var_t4 + 1;
        var_t4 = temp_v0;
        var_t6 *= 0x10;
    } while (temp_v0 < 3);
    temp_a1_2 = arg4 << 0x10;
    var_a2->unk0 = ((s32) (var_a2 - 0x14) & 0xFFFFFF) | 0x03000000;
    temp_v1_2 = ((temp_t9 << 6) | 0x4016) << 0x10;
    temp_a0 = (s32) (arg2 << 0x10) >> 0xC;
    var_a2->unk8 = (s32) (temp_a1_2 | ((arg3 + 0x2A) & 0xFFFF));
    var_a2->unk4 = 0x74808080;
    var_a2->unkC = (s32) (temp_v1_2 | (temp_a0 | 0x1000));
    temp_t3 = var_a2 + 0x14;
    var_a2->unk14 = (s32) (((s32) (temp_t3 - 0x14) & 0xFFFFFF) | 0x03000000);
    temp_t3->unk4 = 0x74808080;
    temp_t3->unk8 = (s32) (temp_a1_2 | ((arg3 + 0x32) & 0xFFFF));
    temp_t3->unkC = (s32) (temp_v1_2 | (temp_a0 | 0x1008));
    return temp_t3 + 0x14;
}
