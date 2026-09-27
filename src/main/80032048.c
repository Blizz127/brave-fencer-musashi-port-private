/* Exact retail word export for [80032048,800322A8); EXE and assembly verified. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

extern s32 D_80068304;
void func_80032A74(void *, s32, void *, s32);          /* static */
s32 func_8003310C(u32);                             /* static */
s32 func_800331D4(u16, u8, u8);                     /* static */
void func_8003324C(s32);                               /* static */
void func_800335B8(s32, s32);                          /* static */
extern s32 *D_800A46E8;
extern void *D_800A4EE8;
extern s16 D_800A4EF0;
extern u8 D_800A4F17;

s32 func_80032048(u16 arg0, void *arg1, s32 arg2) {
    u8 sp10;
    s32 temp_v0;
    s32 temp_v0_2;
    s32 temp_v0_3;
    s32 var_s0;
    s32 var_s2;
    s32 var_s6;
    s32 var_v0;
    u16 var_s4;
    u16 var_s5;
    u32 var_fp;
    u8 temp_a1;
    u8 temp_a2;
    u8 temp_v1;
    void *var_s1;
    void *var_s3;

    var_s2 = arg2;
    temp_v1 = arg1->unk2;
    temp_a2 = arg1->unk1;
    temp_a1 = arg1->unk3;
    var_fp = arg0 >> 0x10;
    if (temp_a2 == 0) {
        var_s3 = *(D_80068304 + (temp_v1 * 4)) + (temp_a1 * 0x14);
        goto block_6;
    }
    var_v0 = 0;
    if (D_800A4EF0 == temp_a2) {
        if (D_800A4EE8 == 0) {
            return 0;
        }
        var_s3 = *((temp_v1 * 4) + D_800A4EE8->unk14) + (temp_a1 * 0x14);
block_6:
        sp10 = D_800A4F17;
        D_800A4F17 = 1;
        var_s4 = var_s3->unk0;
        var_s6 = 0;
        if ((var_s2 & 0xFFFF) == 0xFFFF) {
            var_s2 = 0;
            var_s5 = var_fp & 0xFFFF;
            var_fp = 0;
        } else {
            var_s5 = arg0;
        }
        temp_v0 = func_800331D4(var_s5, temp_a1, temp_a2);
        temp_v0_2 = var_s2 & 0x4000;
        if (temp_v0 == 0) {
            if (temp_v0_2 != 0) {
                if (var_s2 & 0x3000) {
                    goto block_16;
                }
            } else {
                if ((var_s2 & 0x1000) && ((u32) (var_s2 & 0x7F) < 0x30U)) {
                    var_s4 = (u16) (var_s4 >> 1);
                }
block_16:
                temp_v0_3 = func_8003310C((u32) var_s4);
                if (temp_v0_3 != 0) {
                    var_s6 = temp_v0_3;
                    var_s0 = var_s6 - 1;
                    var_s1 = (var_s0 * 0x54) + &D_800A46E8;
                    goto block_22;
                }
            }
        } else if (temp_v0_2 != 0) {
            func_800335B8(temp_v0 - 1, var_s2 & 0xFFFF);
        } else {
            var_s0 = temp_v0 - 1;
            var_s1 = (var_s0 * 0x54) + &D_800A46E8;
            if (var_s1->unk8 == 0) {
                var_s6 = var_s0 + 1;
                func_8003324C(var_s0 & 0xFFFF);
block_22:
                var_s1->unk4 = var_s5;
                var_s1->unk6 = (s16) var_fp;
                var_s1->unk2 = var_s4;
                var_s1->unk0 = (s16) ((arg1->unk0 & 0xC0) | 1);
                var_s1->unkA = 5;
                var_s1->unk8 = (u16) var_s3->unkC;
                func_80032A74(var_s1, var_s0, var_s3, var_s2 & 0xFFFF);
            }
        }
        var_v0 = var_s6;
        D_800A4F17 = sp10;
        /* Duplicate return node #24. Try simplifying control flow for better match */
        return var_v0;
    }
    return var_v0;
}
