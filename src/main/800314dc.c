/* Exact retail word export for [800314DC,800316F8); EXE and assembly verified. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

extern s32 D_8006A970;
extern s32 D_8006AB32;
extern s32 D_80073140;
extern s32 *D_8006AB30;
extern s32 *D_800A4C28;

void func_800314DC(void *arg0) {
    s16 temp_a0;
    s16 var_v0_2;
    s32 temp_a0_3;
    s32 temp_a1_2;
    s32 temp_v0_2;
    s32 temp_v0_3;
    s32 temp_v0_4;
    s32 temp_v1;
    s32 var_v0;
    s32 var_v0_4;
    u16 temp_a0_2;
    u16 temp_v0;
    u32 temp_a1;
    u32 var_v0_3;
    void *temp_a3;

    if (arg0->unk37 & 1) {
        temp_v0 = arg0->unk30;
        if (temp_v0 != 0) {
            arg0->unk30 = (u16) (temp_v0 - 1);
            return;
        }
        temp_v1 = arg0->unk2C;
        if (temp_v1 < 0) {
            temp_v0_2 = arg0->unk24 + temp_v1;
            arg0->unk24 = temp_v0_2;
            var_v0 = arg0->unk28 < temp_v0_2;
        } else {
            temp_v0_3 = arg0->unk24 + temp_v1;
            arg0->unk24 = temp_v0_3;
            var_v0 = temp_v0_3 < arg0->unk28;
        }
        if (var_v0 == 0) {
            arg0->unk24 = arg0->unk28;
            arg0->unk37 = (u8) (arg0->unk37 & 0xFE);
        }
        if (!(arg0->unk37 & 1) && (arg0->unk38 != 0)) {
            temp_a0 = arg0->unk3C;
            if (arg0->unk24 != temp_a0) {
                arg0->unk28 = (s32) temp_a0;
                if (arg0->unk3C < arg0->unk24) {
                    var_v0_2 = -arg0->unk3A;
                } else {
                    var_v0_2 = arg0->unk3A;
                }
                arg0->unk2C = (s32) var_v0_2;
            }
            arg0->unk38 = 0U;
            arg0->unk37 = (u8) (arg0->unk37 | 1);
        }
        temp_a3 = (arg0->unk51 * 0x48) + &D_800A4C28;
        temp_a3->unk0 = (s32) *(D_80073140 + (arg0->unkA * 4));
        temp_a0_2 = ((arg0->unkC * 0xC) + *(D_8006A970 + (arg0->unk10 * 4)))->unk4;
        temp_v0_4 = temp_a0_2 & 0xFFFF;
        temp_a3->unk18 = temp_a0_2;
        temp_a1 = arg0->unk24 - (((temp_v0_4 & 0xFF00) + ((s32) (temp_v0_4 << 0x18) >> 0x17)) - 0x3C00);
        if (temp_a1 >= 0x5300U) {
            var_v0_3 = 0x3FFF;
        } else {
            temp_a0_3 = (temp_a1 >> 8) * 2;
            temp_a1_2 = temp_a1 & 0xFF;
            var_v0_3 = (u32) ((*(&D_8006AB30 + temp_a0_3) * (0x100 - temp_a1_2)) + (*(D_8006AB32 + temp_a0_3) * temp_a1_2)) >> 8;
        }
        temp_a3->unk14 = (s16) var_v0_3;
        temp_a3->unk40 = (s32) arg0->unkA;
        if (temp_a3->unk44 != 0) {
            var_v0_4 = temp_a3->unk4 | 0x10;
        } else {
            temp_a3->unk44 = 1U;
            var_v0_4 = 0x10;
        }
        temp_a3->unk4 = var_v0_4;
    }
}
