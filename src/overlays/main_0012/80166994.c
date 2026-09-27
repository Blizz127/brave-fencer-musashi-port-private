/* Overlay range [80166994,80166F58) from MAIN.CD member 0012.
 * SHA256(span)=d8d36242db38ba6fa8a76e20c30de2fba251a9337a6c11d18fd18ad8a2301743.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void func_80047E98(u16 *, u16 *, s32, u16);            /* extern */
void func_8004945C(s16 *, s16 *, void *);                 /* extern */
extern s32 D_80184418;
void func_801484B0(s16 *, s16 *, s16);                 /* static */
void func_80148534(s16 *, s16 *, s16);                 /* static */
void func_80149350(s32, s16 *, s16 *);                 /* static */
void func_80165FA4(s32, s16 *, s16 *);                 /* static */

s32 func_80166994(void *arg0, s16 arg1, s16 arg2, s16 arg3) {
    s32 sp30;
    u16 sp2C;
    u16 sp2A;
    u16 sp28;
    u16 sp24;
    u16 sp22;
    u16 sp20;
    s16 sp18;
    s16 sp10;
    s32 temp_a2;
    s32 temp_a3;
    s32 temp_s2;
    s32 temp_t0;
    s32 temp_t1;
    s32 temp_v0_3;
    s32 temp_v1_3;
    s32 var_v0;
    u16 temp_a2_2;
    u16 temp_a3_2;
    u16 temp_v1_4;
    u32 temp_a0;
    u32 temp_v1;
    u8 temp_a1;
    u8 temp_v0;
    u8 temp_v0_2;
    u8 temp_v0_4;
    u8 temp_v1_2;
    u8 temp_v1_5;
    void *temp_s1;

    temp_s1 = (arg2 * 0xC4) + D_80184418;
    temp_s2 = arg0->unk34;
    if (arg1 != 1) {
        if (arg1 < 2) {
            if (arg1 != 0) {
                var_v0 = arg2 << 0x10;
            } else {
                temp_s1->unk0 = 1;
                temp_s1->unk2 = 0U;
                temp_s1->unk1 = 0U;
                temp_s1->unk3 = 0xF4U;
                goto block_17;
            }
            goto block_18;
        }
        var_v0 = arg2 << 0x10;
        if (arg1 != 2) {
            goto block_18;
        }
        temp_v0 = temp_s1->unk3 - 0x10;
        temp_a0 = temp_v0 & 0xFF;
        temp_s1->unk3 = temp_v0;
        if (temp_a0 < 0x10U) {
            temp_s1->unk0 = 0;
            return 1;
        }
        temp_a1 = temp_s1->unk2;
        temp_v1 = temp_a1 & 0xFF;
        if (temp_v1 >= 2U) {
            if ((u32) (temp_a0 >> 4) < temp_v1) {
                temp_s1->unk2 = (u8) (temp_a1 - 1);
            }
            return 0;
        }
        /* Duplicate return node #27. Try simplifying control flow for better match */
        return 0;
    }
    sp20 = (temp_s1 + (temp_s1->unk1 * 0xC))->unk4;
    sp22 = (temp_s1 + (temp_s1->unk1 * 0xC))->unk6;
    sp24 = (temp_s1 + (temp_s1->unk1 * 0xC))->unk8;
    sp28 = (temp_s1 + (temp_s1->unk1 * 0xC))->unkA;
    sp2A = (temp_s1 + (temp_s1->unk1 * 0xC))->unkC;
    sp2C = (temp_s1 + (temp_s1->unk1 * 0xC))->unkE;
    temp_v0_2 = temp_s1->unk1 + 1;
    temp_s1->unk1 = temp_v0_2;
    if ((u32) (temp_v0_2 & 0xFF) >= 0x10U) {
        temp_s1->unk1 = 0U;
    }
    temp_v1_2 = temp_s1->unk2;
    if (temp_v1_2 < 0xFU) {
        temp_s1->unk2 = (u8) (temp_v1_2 + 1);
    }
block_17:
    var_v0 = arg2 << 0x10;
block_18:
    if ((var_v0 >> 0x10) < 2) {
        func_801484B0(&sp10, &sp18, arg2);
    } else {
        func_80148534(&sp10, &sp18, arg2);
    }
    func_80165FA4(temp_s2, &sp10, &sp18);
    func_80149350(temp_s2, &sp10, &sp10);
    func_8004945C(&sp18, &sp18, &sp30);
    if ((arg1 << 0x10) != 0) {
        temp_t0 = (s32) (sp10 + (s16) sp20) >> 1;
        sp20 = (u16) temp_t0;
        temp_a3 = (s32) (sp12 + (s16) sp22) >> 1;
        sp22 = (u16) temp_a3;
        temp_v1_3 = (s32) (sp14 + (s16) sp24) >> 1;
        sp24 = (u16) temp_v1_3;
        temp_t1 = (s32) (sp18 + (s16) sp28) >> 1;
        sp28 = (u16) temp_t1;
        sp20 = temp_t0 - temp_t1;
        temp_a2 = (s32) (sp1A + (s16) sp2A) >> 1;
        temp_a3_2 = temp_a3 - temp_a2;
        sp2A = (u16) temp_a2;
        sp22 = temp_a3_2;
        temp_v0_3 = (s32) (sp1C + (s16) sp2C) >> 1;
        sp2C = (u16) temp_v0_3;
        sp24 = temp_v1_3 - temp_v0_3;
        func_80047E98(&sp20, &sp20, temp_a2, temp_a3_2);
        temp_a2_2 = sp28 + ((s16) sp20 / arg3);
        sp20 = temp_a2_2;
        sp22 = sp2A + ((s16) sp22 / arg3);
        temp_v1_4 = sp2C + ((s16) sp24 / arg3);
        sp24 = temp_v1_4;
        (temp_s1 + (temp_s1->unk1 * 0xC))->unk4 = temp_a2_2;
        (temp_s1 + (temp_s1->unk1 * 0xC))->unk6 = sp22;
        (temp_s1 + (temp_s1->unk1 * 0xC))->unk8 = temp_v1_4;
        (temp_s1 + (temp_s1->unk1 * 0xC))->unkA = sp28;
        (temp_s1 + (temp_s1->unk1 * 0xC))->unkC = sp2A;
        (temp_s1 + (temp_s1->unk1 * 0xC))->unkE = sp2C;
        temp_v0_4 = temp_s1->unk1 + 1;
        temp_s1->unk1 = temp_v0_4;
        if ((u32) (temp_v0_4 & 0xFF) >= 0x10U) {
            temp_s1->unk1 = 0U;
        }
        temp_v1_5 = temp_s1->unk2;
        if (temp_v1_5 < 0xFU) {
            temp_s1->unk2 = (u8) (temp_v1_5 + 1);
        }
    }
    (temp_s1 + (temp_s1->unk1 * 0xC))->unk4 = (u16) sp10;
    (temp_s1 + (temp_s1->unk1 * 0xC))->unk6 = (u16) sp12;
    (temp_s1 + (temp_s1->unk1 * 0xC))->unk8 = (u16) sp14;
    (temp_s1 + (temp_s1->unk1 * 0xC))->unkA = (u16) sp18;
    (temp_s1 + (temp_s1->unk1 * 0xC))->unkC = (u16) sp1A;
    (temp_s1 + (temp_s1->unk1 * 0xC))->unkE = (u16) sp1C;
    return 0;
}
