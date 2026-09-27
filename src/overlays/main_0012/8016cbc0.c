/* Overlay range [8016CBC0,8016CF04) from MAIN.CD member 0012.
 * SHA256(span)=6e5d6ee73a0be74301fe0e7f46fd4f60cd18e528ac00fe9176414426529d1523.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void func_80017758(u16 *, s32 *, u32, u16);            /* extern */
extern s32 D_801848D0;
extern s32 D_800AE620;

s16 func_8016CBC0(void) {
    s32 sp9C;
    s32 sp98;
    s32 sp94;
    s32 sp90;
    s32 sp8C;
    s32 sp88;
    s32 sp84;
    s32 sp80;
    s32 sp78;
    s8 sp76;
    s8 sp75;
    s8 sp74;
    s8 sp72;
    u8 sp71;
    s8 sp70;
    s8 sp6E;
    s8 sp6D;
    s8 sp6C;
    s8 sp6A;
    u8 sp69;
    s8 sp68;
    u16 sp64;
    u16 sp62;
    u16 sp60;
    s16 sp5C;
    s16 sp5A;
    s16 sp58;
    u16 sp54;
    u16 sp52;
    u16 sp50;
    s16 sp4C;
    s16 sp4A;
    u16 sp48;
    s32 sp40;
    s8 sp3E;
    u8 sp3D;
    s8 sp3C;
    s8 sp3A;
    s8 sp39;
    s8 sp38;
    s8 sp36;
    u8 sp35;
    s8 sp34;
    s8 sp32;
    s8 sp31;
    s8 sp30;
    s16 sp2C;
    s16 sp2A;
    s16 sp28;
    u16 sp24;
    u16 sp22;
    u16 sp20;
    s16 sp1C;
    s16 sp1A;
    s16 sp18;
    u16 sp14;
    u16 sp12;
    u16 sp10;
    s16 temp_v0;
    s16 temp_v1;
    s16 var_s2;
    s16 var_s5;
    s16 var_s6;
    s16 var_v0;
    s32 var_v1;
    s32 var_v1_2;
    u16 temp_a0_2;
    u16 temp_a0_3;
    u16 temp_a0_5;
    u16 temp_a0_6;
    u16 temp_a1_2;
    u16 temp_a3;
    u16 temp_v1_10;
    u16 temp_v1_12;
    u16 temp_v1_2;
    u16 temp_v1_4;
    u16 temp_v1_6;
    u16 temp_v1_8;
    u32 temp_a2;
    u32 temp_v0_2;
    u32 temp_v1_11;
    u32 temp_v1_13;
    u32 temp_v1_3;
    u32 temp_v1_5;
    u32 temp_v1_7;
    u32 temp_v1_9;
    u8 temp_a0_4;
    u8 var_s0;
    u8 var_s1;
    void *temp_a0;
    void *temp_a1;
    void *temp_a1_3;
    void *temp_s3;

    sp80 = D_800AE620.unk0;
    sp84 = D_800AE620.unk4;
    sp88 = D_800AE620.unk8;
    sp8C = D_800AE620.unkC;
    sp90 = D_800AE620.unk10;
    sp94 = D_800AE620.unk14;
    sp98 = D_800AE620.unk18;
    sp9C = D_800AE620.unk1C;
    var_s6 = 0;
    var_s5 = 0;
    sp78 = 0x50000000;
    sp40 = 0x50000000;
    sp76 = 0;
    sp75 = 0;
    sp74 = 0;
    sp6E = 0;
    sp6D = 0;
    sp6C = 0;
    sp3A = 0;
    sp39 = 0;
    sp38 = 0;
    sp32 = 0;
    sp31 = 0;
    sp30 = 0;
    var_v1 = 0 << 0x10;
    do {
        temp_a0 = ((var_v1 >> 0x10) * 0xC4) + D_801848D0;
        var_v0 = var_s5 + 1;
        if (temp_a0->unk0 != 0) {
            var_s6 += 1;
            temp_s3 = temp_a0 + 4;
            var_s1 = temp_a0->unk1;
            var_s0 = temp_a0->unk3;
            temp_v1 = temp_a0->unk2 - 1;
            var_s2 = temp_v1;
            if (temp_v1 != -1) {
                var_v1_2 = var_s1 << 0x10;
                do {
                    temp_a1 = temp_s3 + ((var_v1_2 >> 0x10) * 0xC);
                    temp_v1_2 = temp_a1->unk0;
                    sp10 = temp_v1_2;
                    temp_a0_2 = temp_a1->unk6;
                    temp_v1_3 = (u32) ((s16) temp_v1_2 + (s16) temp_a0_2) >> 1;
                    sp50 = temp_a0_2;
                    sp48 = (u16) temp_v1_3;
                    sp18 = (s16) temp_v1_3;
                    temp_v1_4 = temp_a1->unk2;
                    sp12 = temp_v1_4;
                    temp_a0_3 = temp_a1->unk8;
                    temp_v1_5 = (u32) ((s16) temp_v1_4 + (s16) temp_a0_3) >> 1;
                    temp_v0_2 = (u32) (var_s0 & 0xFF) >> 3;
                    sp52 = temp_a0_3;
                    temp_a0_4 = var_s1 - 1;
                    var_s1 = temp_a0_4;
                    sp4A = (s16) temp_v1_5;
                    sp1A = (s16) temp_v1_5;
                    temp_v1_6 = temp_a1->unk4;
                    sp14 = temp_v1_6;
                    temp_a1_2 = temp_a1->unkA;
                    sp69 = var_s0;
                    sp35 = var_s0;
                    sp6A = (s8) temp_v0_2;
                    sp36 = (s8) temp_v0_2;
                    sp68 = (s8) temp_v0_2;
                    sp34 = (s8) temp_v0_2;
                    temp_v1_7 = (u32) ((s16) temp_v1_6 + (s16) temp_a1_2) >> 1;
                    sp54 = temp_a1_2;
                    sp4C = (s16) temp_v1_7;
                    sp1C = (s16) temp_v1_7;
                    if (temp_a0_4 & 0x8000) {
                        var_s1 = 0xF;
                    }
                    temp_a1_3 = temp_s3 + ((s16) var_s1 * 0xC);
                    var_s0 -= 0xF;
                    temp_v1_8 = temp_a1_3->unk0;
                    sp20 = temp_v1_8;
                    temp_a0_5 = temp_a1_3->unk6;
                    temp_v1_9 = (u32) ((s16) temp_v1_8 + (s16) temp_a0_5) >> 1;
                    sp60 = temp_a0_5;
                    sp58 = (s16) temp_v1_9;
                    sp28 = (s16) temp_v1_9;
                    temp_v1_10 = temp_a1_3->unk2;
                    temp_a2 = (u32) (var_s0 & 0xFF) >> 3;
                    sp22 = temp_v1_10;
                    temp_a0_6 = temp_a1_3->unk8;
                    temp_v1_11 = (u32) ((s16) temp_v1_10 + (s16) temp_a0_6) >> 1;
                    sp62 = temp_a0_6;
                    sp5A = (s16) temp_v1_11;
                    sp2A = (s16) temp_v1_11;
                    temp_v1_12 = temp_a1_3->unk4;
                    sp24 = temp_v1_12;
                    temp_a3 = temp_a1_3->unkA;
                    sp71 = var_s0;
                    sp3D = var_s0;
                    sp72 = (s8) temp_a2;
                    sp3E = (s8) temp_a2;
                    sp70 = (s8) temp_a2;
                    sp3C = (s8) temp_a2;
                    temp_v1_13 = (u32) ((s16) temp_v1_12 + (s16) temp_a3) >> 1;
                    sp64 = temp_a3;
                    sp5C = (s16) temp_v1_13;
                    sp2C = (s16) temp_v1_13;
                    func_80017758(&sp10, &sp80, temp_a2, temp_a3);
                    func_80017758(&sp48, &sp80);
                    temp_v0 = var_s2 - 1;
                    var_s2 = temp_v0;
                    var_v1_2 = var_s1 << 0x10;
                } while (temp_v0 != -1);
            }
            var_v0 = var_s5 + 1;
        }
        var_s5 = var_v0;
        var_v1 = var_s5 << 0x10;
    } while (var_v0 < 8);
    return var_s6;
}
