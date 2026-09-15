/* Overlay range [8012EA90,8012EC04) from MAIN.CD member 0012.
 * SHA256(span)=073f5964918652575c2f62ceb6eadeb5aa67626881763dcfe5255f298e0c6d05.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void func_80049CAC(u16 *, void *, s32);          /* extern */

void func_8012EA90(void *arg0, s32 arg1, void *arg2) {
    u16 sp14;
    u16 sp12;
    u16 sp10;
    s32 temp_a2_2;
    s32 temp_a2_3;
    s32 temp_s1;
    void *temp_a2;
    void *temp_s0;
    void *temp_s1_2;

    temp_a2 = M2C_FIELD(arg0, void **, 0x20);
    temp_s1 = M2C_FIELD(temp_a2, s32 *, 0x20);
    if (temp_s1 == 0) {
        M2C_FIELD(arg2, s32 *, 0) = (s32) M2C_FIELD(temp_a2, s32 *, 0x34);
        M2C_FIELD(arg2, s32 *, 4) = (s32) M2C_FIELD(temp_a2, s32 *, 0x38);
        M2C_FIELD(arg2, s32 *, 8) = (s32) M2C_FIELD(temp_a2, s32 *, 0x3C);
        M2C_FIELD(arg2, s32 *, 0xC) = (s32) M2C_FIELD(temp_a2, s32 *, 0x40);
        M2C_FIELD(arg2, s32 *, 0x10) = (s32) M2C_FIELD(temp_a2, s32 *, 0x44);
        M2C_FIELD(arg2, s32 *, 0x14) = (s32) M2C_FIELD(temp_a2, s32 *, 0x48);
        M2C_FIELD(arg2, s32 *, 0x18) = (s32) M2C_FIELD(temp_a2, s32 *, 0x4C);
        M2C_FIELD(arg2, s32 *, 0x1C) = (s32) M2C_FIELD(temp_a2, s32 *, 0x50);
        return;
    }
    if (temp_s1 & 0x01000000) {
        temp_s0 = (temp_s1 & 0xFEFFFFFF) + (arg1 * 8);
        sp10 = M2C_FIELD(temp_s0, u16 *, 6);
        temp_a2_2 = M2C_FIELD(temp_s0, s32 *, 0);
        temp_a2_3 = (temp_a2_2 & 0xF0) * 0x10;
        sp12 = M2C_FIELD(temp_s0, u8 *, 1) | ((temp_a2_2 & 0xF) << 8);
        sp14 = ((temp_a2_2 >> 0x10) & 0xFF) | temp_a2_3;
        func_80049CAC(&sp10, arg2, temp_a2_3);
        M2C_FIELD(arg2, s32 *, 0x14) = (s32) M2C_FIELD(temp_s0, s8 *, 3);
        M2C_FIELD(arg2, s32 *, 0x18) = (s32) M2C_FIELD(temp_s0, s8 *, 4);
        M2C_FIELD(arg2, s32 *, 0x1C) = (s32) M2C_FIELD(temp_s0, s8 *, 5);
        return;
    }
    temp_s1_2 = temp_s1 + (arg1 * 0xC);
    sp10 = M2C_FIELD(temp_s1_2, u16 *, 6);
    sp12 = M2C_FIELD(temp_s1_2, u16 *, 8);
    sp14 = M2C_FIELD(temp_s1_2, u16 *, 0xA);
    func_80049CAC(&sp10, arg2, (s32) temp_a2);
    M2C_FIELD(arg2, s32 *, 0x14) = (s32) M2C_FIELD(temp_s1_2, s16 *, 0);
    M2C_FIELD(arg2, s32 *, 0x18) = (s32) M2C_FIELD(temp_s1_2, s16 *, 2);
    M2C_FIELD(arg2, s32 *, 0x1C) = (s32) M2C_FIELD(temp_s1_2, s16 *, 4);
}
