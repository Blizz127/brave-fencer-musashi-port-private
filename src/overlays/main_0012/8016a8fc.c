/* Overlay range [8016A8FC,8016AA50) from MAIN.CD member 0012.
 * SHA256(span)=60a39859ef0f1acd5c3c86285f7ed796744049877b21f8a37a59a00906b2e2f8.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void func_80016A5C(s16 *, void *);            /* extern */
extern s32 *D_800AE620;

void func_8016A8FC(void *arg0) {
    s32 sp28;
    s8 sp26;
    s8 sp25;
    s8 sp24;
    s8 sp22;
    s8 sp21;
    s8 sp20;
    u16 sp1C;
    u16 sp1A;
    u16 sp18;
    s16 sp14;
    s16 sp12;
    s16 sp10;
    s32 temp_v0;
    s32 temp_v0_2;
    s32 temp_v0_3;
    s32 temp_v0_4;
    s32 temp_v1;
    s32 temp_v1_2;
    void *temp_a1;

    temp_a1 = M2C_FIELD(arg0, void **, 0x34);
    sp10 = (s16) M2C_FIELD(arg0, s32 *, 0x4C);
    sp12 = (s16) M2C_FIELD(arg0, s32 *, 0x50);
    sp14 = (s16) M2C_FIELD(arg0, s32 *, 0x54);
    sp18 = M2C_FIELD(temp_a1, u16 *, 6);
    sp1A = M2C_FIELD(temp_a1, u16 *, 0xA);
    sp1C = M2C_FIELD(temp_a1, u16 *, 0xE);
    sp10 = (s16) ((s32) (M2C_FIELD(arg0, s16 *, 6) + M2C_FIELD(arg0, s32 *, 0x4C)) >> 1);
    sp12 = (s16) ((s32) (M2C_FIELD(arg0, s16 *, 0xA) + M2C_FIELD(arg0, s32 *, 0x50)) >> 1);
    sp14 = (s16) ((s32) (M2C_FIELD(arg0, s16 *, 0xE) + M2C_FIELD(arg0, s32 *, 0x54)) >> 1);
    temp_v0 = M2C_FIELD(arg0, s32 *, 0x4C);
    M2C_FIELD(arg0, s16 *, 6) = (s16) temp_v0;
    temp_v0_2 = (s32) ((s16) temp_v0 + (s16) M2C_FIELD(temp_a1, u16 *, 6)) >> 1;
    sp18 = (u16) temp_v0_2;
    temp_v1 = M2C_FIELD(arg0, s32 *, 0x50);
    M2C_FIELD(arg0, s32 *, 0x4C) = temp_v0_2;
    M2C_FIELD(arg0, s16 *, 0xA) = (s16) temp_v1;
    temp_v1_2 = (s32) ((s16) temp_v1 + (s16) M2C_FIELD(temp_a1, u16 *, 0xA)) >> 1;
    sp1A = (u16) temp_v1_2;
    temp_v0_3 = M2C_FIELD(arg0, s32 *, 0x54);
    M2C_FIELD(arg0, s32 *, 0x50) = temp_v1_2;
    M2C_FIELD(arg0, s16 *, 0xE) = (s16) temp_v0_3;
    temp_v0_4 = (s32) ((s16) temp_v0_3 + (s16) M2C_FIELD(temp_a1, u16 *, 0xE)) >> 1;
    sp1C = (u16) temp_v0_4;
    M2C_FIELD(arg0, s32 *, 0x54) = temp_v0_4;
    sp21 = 0x10;
    sp25 = 0x80;
    sp26 = 0x20;
    sp24 = 0x20;
    sp22 = 0;
    sp20 = 0;
    sp28 = 0x50000000;
    func_80016A5C(&sp10, &D_800AE620);
}
