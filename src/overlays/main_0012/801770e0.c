/* Overlay range [801770E0,80177340) from MAIN.CD member 0012.
 * SHA256(span)=35097fec875b4f2bce8bc48a96f009f0a89e39389e25ec9ee6014705f8f81300.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

s32 func_80177784(s32, s32, s32);                     /* static */
s32 func_801777BC(s32, s16, s16, s16, s32, s32, s32); /* static */
s16 func_801783D0(u16, s32);                          /* static */
extern u16 D_8011F82E;
extern u16 D_8011F830;

s32 func_801770E0(s32 arg1, s16 arg2) {
    s32 temp_a2;
    s32 temp_s0;
    s32 temp_s0_2;
    s32 temp_s0_3;
    s32 temp_v1;
    void *temp_v0;

    temp_s0 = arg2 << 0x10;
    temp_s0_2 = func_80177784(func_80177784(func_80177784(func_80177784(temp_s0 | (arg1 & 0xFFFF), 0x6E165010), temp_s0 | ((arg1 + 8) & 0xFFFF), 0x6E165808), temp_s0 | ((arg1 + 0x10) & 0xFFFF), 0x6E164060), temp_s0 | ((arg1 + 0x30) & 0xFFFF), 0x6E163858);
    temp_s0_3 = func_801777BC(temp_s0_2, func_801783D0(D_8011F830, 4), (s16) (arg1 + 0x18), arg2, 3, 0xB8, 0xFF);
    temp_v0 = func_801777BC(temp_s0_3, func_801783D0(D_8011F82E, 4), (s16) (arg1 + 0x38), arg2, 3, 0xB8, 0xFF);
    temp_v0->unk4 = 0x6055FF00;
    temp_v0->unk0 = (s32) (((temp_v0 - 0x14) & 0xFFFFFF) | 0x03000000);
    temp_a2 = ((arg2 - 4) << 0x10) | ((arg1 + 1) & 0xFFFF);
    temp_v0->unk8 = temp_a2;
    temp_v0->unkC = (s32) (((s32) (D_8011F830 * 0x50E6) >> 0x10) | 0x20000);
    temp_v0->unk14 = (s32) (((s32) temp_v0 & 0xFFFFFF) | 0x03000000);
    temp_v0->unk28 = (s32) (((s32) (temp_v0 + 0x14) & 0xFFFFFF) | 0x03000000);
    temp_v0->unk18 = 0x60FF3214;
    temp_v0->unk1C = temp_a2;
    temp_v0->unk2C = 0x60000000;
    temp_v0->unk30 = (s32) (((arg2 - 5) << 0x10) | (arg1 & 0xFFFF));
    temp_v1 = (s32) (D_8011F82E * 0x50E6) >> 0x10;
    temp_v0->unk20 = (s32) (temp_v1 | 0x20000);
    temp_v0->unk34 = (s32) ((temp_v1 + 2) | 0x40000);
    return temp_v0 + 0x3C;
}
