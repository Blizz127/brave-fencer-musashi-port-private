/* Main-exec range [8003DC90,8003DF8C) from the SLUS executable.
 * SHA256(span)=6caa05a946ec7e7b44ec76e678ef3c125e1099cc7a2a0a9dcc3f62d6aee5b7fd.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void func_80040DE8(s16, s32, s32, s32);                  /* static */
void func_80041354(s16, u16 *, u16 *, s32);            /* static */
extern s32 *D_800C73D8;

void func_8003DC90(s32 arg0, s16 arg1) {
    u16 sp12;
    u16 sp10;
    s16 temp_a0;
    s16 temp_a2;
    s16 temp_v0_3;
    s16 temp_v0_6;
    s16 temp_v1;
    s16 var_a0_2;
    s32 *temp_s2;
    s32 temp_s1;
    s32 temp_v0;
    s32 temp_v0_4;
    s32 var_a0;
    s32 var_a0_3;
    s32 var_a1;
    s32 var_a2;
    u16 temp_v0_2;
    u16 temp_v0_5;
    void *temp_s0;
    void *temp_v1_2;
    void *var_v0;

    temp_s2 = ((s32) (arg0 << 0x10) >> 0xE) + &D_800C73D8;
    temp_s1 = arg1 * 0xB0;
    temp_s0 = *temp_s2 + temp_s1;
    temp_v0 = temp_s0->unkA0 - 1;
    temp_s0->unkA0 = temp_v0;
    if (temp_v0 < 0) {
        var_v0 = temp_s1 + *temp_s2;
        goto block_20;
    }
    temp_a2 = temp_s0->unk4C;
    if (temp_a2 > 0) {
        var_a0 = arg1 << 8;
        if ((temp_v0 % temp_a2) == 0) {
            temp_v0_2 = temp_s0->unk4A - 1;
            temp_s0->unk4A = temp_v0_2;
            if (!(temp_v0_2 & 0x8000)) {
                temp_v0_3 = arg0 | (arg1 << 8);
                func_80041354(temp_v0_3, &sp10, &sp12, arg0);
                temp_v0_4 = sp10 & 0xFFFF;
                var_a0_2 = temp_v0_3;
                if ((temp_v0_4 + (s16) temp_s0->unk4A) >= (temp_v0_4 + 1)) {
                    var_a1 = (sp10 + 1) & 0xFFFF;
                    var_a2 = sp12 + 1;
                    goto block_14;
                }
            } else {
                goto block_15;
            }
            goto block_16;
        }
    } else {
        var_a0 = arg1 << 8;
        if (temp_a2 < 0) {
            temp_v0_5 = temp_s0->unk4A + temp_a2;
            temp_s0->unk4A = temp_v0_5;
            if (!(temp_v0_5 & 0x8000)) {
                temp_v0_6 = arg0 | (arg1 << 8);
                func_80041354(temp_v0_6, &sp10, &sp12, arg0);
                temp_v1 = temp_s0->unk4C;
                if (((sp10 - temp_v1) >= 0x7F) && ((sp12 - temp_v1) >= 0x7F)) {
                    func_80040DE8(temp_v0_6, 0x7F, 0x7F, 1);
                }
                temp_a0 = temp_s0->unk4C;
                if (((temp_s0->unk9C - temp_s0->unkA0) * -temp_a0) < temp_s0->unk48) {
                    var_a0_2 = arg0 | (arg1 << 8);
                    var_a1 = (sp10 - temp_a0) & 0xFFFF;
                    var_a2 = sp12 - temp_a0;
block_14:
                    func_80040DE8(var_a0_2, var_a1, var_a2 & 0xFFFF, 1);
                }
            } else {
block_15:
                func_80040DE8((s16) (arg0 | (arg1 << 8)), 0x7F, 0x7F, 1);
                temp_v1_2 = temp_s1 + *temp_s2;
                temp_v1_2->unk98 = (s32) (temp_v1_2->unk98 & ~0x10);
            }
block_16:
            var_a0_3 = arg0 << 0x10;
            if (temp_s0->unkA0 != 0) {
                var_a0 = arg1 << 8;
                if ((s16) temp_s0->unk4A == 0) {
                    var_a0_3 = arg0 << 0x10;
                    goto block_19;
                }
            } else {
block_19:
                var_v0 = (arg1 * 0xB0) + *(&D_800C73D8 + (var_a0_3 >> 0xE));
block_20:
                var_v0->unk98 = (s32) (var_v0->unk98 & ~0x10);
                var_a0 = arg1 << 8;
            }
        }
    }
    func_80041354((s16) (arg0 | var_a0), temp_s0 + 0x5C, temp_s0 + 0x5E);
}
