/* Exact retail word export for [80032774,80032A74); EXE and assembly verified. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

extern s32 D_80068304;
void func_80032A74(void *, s32, void *, s32);          /* static */
s32 func_8003310C(u16, u8 *, u16 *, s32);           /* static */
void func_8003324C(s32, u8 *, u16 *, s32);             /* static */
void func_800335B8(s32, s32, u16 *, s32);              /* static */
extern s32 *D_800A46E8;
extern void *D_800A4EE8;
extern s16 D_800A4EF0;
extern u8 D_800A4F17;

s32 func_80032774(u16 arg0, void *arg1, s32 arg2) {
    u8 sp18;
    u16 sp10;
    s32 temp_v0;
    s32 temp_v1_2;
    s32 var_a0;
    s32 var_a3;
    s32 var_s0;
    s32 var_s0_2;
    s32 var_s2;
    s32 var_s4;
    s32 var_s5;
    s32 var_t0;
    s32 var_v0;
    s8 temp_v0_2;
    u16 temp_fp;
    u8 *var_a1;
    u8 *var_a2;
    u8 temp_a0;
    u8 temp_a1;
    u8 temp_v1;
    void *var_s1;
    void *var_s3;

    var_s2 = arg2;
    sp10 = (u16) (arg0 >> 0x10);
    temp_v1 = arg1->unk2;
    temp_a1 = arg1->unk1;
    temp_a0 = arg1->unk3;
    var_s5 = 0;
    if (temp_a1 == 0) {
        var_s3 = *(D_80068304 + (temp_v1 * 4)) + (temp_a0 * 0x14);
        goto block_6;
    }
    var_v0 = 0;
    if (D_800A4EF0 == temp_a1) {
        if (D_800A4EE8 == 0) {
            return 0;
        }
        var_s3 = *((temp_v1 * 4) + D_800A4EE8->unk14) + (temp_a0 * 0x14);
block_6:
        var_s4 = 0;
        var_s0 = 0;
        var_t0 = 0;
        var_a2 = &D_800A4F17 - 0x82F;
        var_a3 = 0x80;
        var_a0 = 0;
        var_a1 = &D_800A4F17 - 0x824;
        sp18 = D_800A4F17;
        D_800A4F17 = 1;
        temp_fp = var_s3->unk0;
loop_7:
        if (((*var_a2 & 0x3F) == 1) && (var_a1->unk-7 == (arg0 & 0xFFFF))) {
            if ((sp10 == 0) || (var_a1->unk-5 == sp10)) {
                if (var_s2 & 0x4000) {
                    func_800335B8(var_a0, var_s2 & 0xFFFF, (u16 *) var_a2, var_a3);
                }
            } else {
                temp_v1_2 = var_a1->unk0 & 0x7F;
                if (temp_v1_2 < var_a3) {
                    var_s0 = var_a0 + 1;
                    var_a3 = temp_v1_2;
                }
                if (temp_v1_2 >= var_s5) {
                    var_s5 = temp_v1_2;
                }
                var_t0 += 1;
                goto block_18;
            }
        } else {
block_18:
            var_a0 += 1;
            var_a1 += 0x54;
            var_a2 += 0x54;
            if (var_a0 >= 8) {
                if (var_t0 < 2) {
                    var_s0 = 0;
                    goto block_22;
                }
                if ((var_s2 & 0x7F) >= var_a3) {
block_22:
                    if (var_s0 == 0) {
                        if (!(var_s2 & 0x4000) || (var_s2 & 0x3000)) {
                            temp_v0 = func_8003310C(temp_fp, var_a1, (u16 *) var_a2, var_a3);
                            if (temp_v0 != 0) {
                                var_s4 = temp_v0;
                                var_s0_2 = var_s4 - 1;
                                var_s1 = (var_s0_2 * 0x54) + &D_800A46E8;
                                goto block_29;
                            }
                        }
                    } else {
                        var_s4 = var_s0;
                        var_s0_2 = var_s4 - 1;
                        var_s1 = (var_s0_2 * 0x54) + &D_800A46E8;
                        if (var_s1->unk8 == 0) {
                            func_8003324C(var_s0_2 & 0xFFFF, var_a1, (u16 *) var_a2, var_a3);
block_29:
                            temp_v0_2 = var_s2 & 0x7F;
                            if (var_s2 & 0x1000) {
                                var_s1->unkB = temp_v0_2;
                                if (temp_v0_2 < var_s5) {
                                    var_s2 |= 0x8000;
                                }
                            }
                            var_s1->unk4 = arg0;
                            var_s1->unk6 = sp10;
                            var_s1->unk2 = temp_fp;
                            var_s1->unk0 = (s16) ((arg1->unk0 & 0xC0) | 1);
                            var_s1->unkA = 5;
                            var_s1->unk8 = (u16) var_s3->unkC;
                            func_80032A74(var_s1, var_s0_2, var_s3, var_s2 & 0xFFFF);
                        }
                    }
                }
            } else {
                goto loop_7;
            }
        }
        var_v0 = var_s4;
        D_800A4F17 = sp18;
        /* Duplicate return node #35. Try simplifying control flow for better match */
        return var_v0;
    }
    return var_v0;
}
