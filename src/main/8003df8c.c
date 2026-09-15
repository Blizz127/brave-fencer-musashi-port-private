/* Main-exec range [8003DF8C,8003E248) from the SLUS executable.
 * SHA256(span)=fd52910c8df993e8d4073a1112e44d31fbcb7accc0cdeb7e68065a53ce9b18aa.
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

void func_8003DF8C(s32 arg0, s16 arg1) {
    u16 sp12;
    u16 sp10;
    s16 temp_a0_2;
    s16 temp_a2;
    s16 temp_a2_2;
    s16 temp_v0_3;
    s16 temp_v0_5;
    s16 temp_v1;
    s16 var_a0;
    s32 *temp_t0;
    s32 temp_a0;
    s32 temp_a3;
    s32 temp_v0;
    s32 var_a0_2;
    s32 var_a0_3;
    s32 var_a1;
    s32 var_a2;
    u16 temp_v0_2;
    u16 temp_v0_4;
    void *temp_s0;
    void *temp_v0_6;
    void *var_v0;

    temp_t0 = ((s32) (arg0 << 0x10) >> 0xE) + &D_800C73D8;
    temp_a3 = arg1 * 0xB0;
    temp_s0 = *temp_t0 + temp_a3;
    temp_v0 = temp_s0->unkA0 - 1;
    temp_s0->unkA0 = temp_v0;
    if (temp_v0 < 0) {
        var_v0 = temp_a3 + *temp_t0;
        goto block_20;
    }
    temp_a2 = temp_s0->unk4C;
    if (temp_a2 > 0) {
        if ((temp_v0 % temp_a2) == 0) {
            temp_v0_2 = temp_s0->unk4A - 1;
            temp_s0->unk4A = temp_v0_2;
            if ((temp_v0_2 << 0x10) > 0) {
                temp_v0_3 = arg0 | (arg1 << 8);
                func_80041354(temp_v0_3, &sp10, &sp12, temp_a3);
                temp_v1 = (s16) temp_s0->unk4A;
                temp_a0 = sp10 & 0xFFFF;
                if (((temp_a0 - temp_v1) > 0) && ((sp12 - temp_v1) > 0) && (var_a0 = temp_v0_3, (temp_a0 != 1))) {
                    var_a1 = (sp10 - 1) & 0xFFFF;
                    var_a2 = (sp12 - 1) & 0xFFFF;
                } else {
                    goto block_13;
                }
                goto block_14;
            }
            goto block_15;
            goto block_16;
        }
        goto block_21;
    }
    temp_v0_4 = temp_s0->unk4A + temp_a2;
    temp_s0->unk4A = temp_v0_4;
    if ((temp_v0_4 << 0x10) > 0) {
        temp_v0_5 = arg0 | (arg1 << 8);
        func_80041354(temp_v0_5, &sp10, &sp12, temp_a3);
        temp_a0_2 = temp_s0->unk4C;
        temp_a2_2 = -temp_a0_2;
        if ((temp_s0->unk48 >= ((temp_s0->unk9C - temp_s0->unkA0) * temp_a2_2)) && (temp_a2_2 < (s32) sp10)) {
            func_80040DE8(temp_v0_5, (sp10 + temp_a0_2) & 0xFFFF, (sp12 + temp_a0_2) & 0xFFFF, 1);
        } else {
block_13:
            var_a0 = arg0 | (arg1 << 8);
            var_a1 = 1;
            var_a2 = 1;
block_14:
            func_80040DE8(var_a0, var_a1, var_a2, 1);
        }
    } else {
block_15:
        temp_v0_6 = temp_a3 + *temp_t0;
        temp_v0_6->unk98 = (s32) (temp_v0_6->unk98 & ~0x20);
    }
block_16:
    var_a0_2 = arg0 << 0x10;
    if (temp_s0->unkA0 != 0) {
        var_a0_3 = arg1 << 8;
        if ((s16) temp_s0->unk4A == 0) {
            var_a0_2 = arg0 << 0x10;
            goto block_19;
        }
    } else {
block_19:
        var_v0 = (arg1 * 0xB0) + *(&D_800C73D8 + (var_a0_2 >> 0xE));
block_20:
        var_v0->unk98 = (s32) (var_v0->unk98 & ~0x20);
block_21:
        var_a0_3 = arg1 << 8;
    }
    func_80041354((s16) (arg0 | var_a0_3), temp_s0 + 0x5C, temp_s0 + 0x5E);
}
