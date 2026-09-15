/* Exact retail word export for [800322A8,800324A4); EXE and assembly verified. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

extern s32 D_80068304;
void func_80032A74(void *, s32, void *, s32);          /* static */
s32 func_8003310C(u16);                             /* static */
s32 func_800331D4(s32, u8, u8);                     /* static */
void func_8003324C(s32);                               /* static */
extern void *D_800A4EE8;
extern s16 D_800A4EF0;
extern u8 D_800A4F17;

s32 func_800322A8(u16 arg0, void *arg1, s32 arg2) {
    u16 sp10;
    s32 temp_v0;
    s32 temp_v0_2;
    s32 var_s0;
    s32 var_s3;
    s32 var_v0;
    u16 temp_s6;
    u8 temp_a1;
    u8 temp_a2;
    u8 temp_s7;
    u8 temp_v1;
    void *var_s1;
    void *var_s2;

    sp10 = (u16) (arg0 >> 0x10);
    temp_v1 = arg1->unk2;
    temp_a2 = arg1->unk1;
    temp_a1 = arg1->unk3;
    if (temp_a2 == 0) {
        var_s2 = *(D_80068304 + (temp_v1 * 4)) + (temp_a1 * 0x14);
        goto block_6;
    }
    var_v0 = 0;
    if (D_800A4EF0 == temp_a2) {
        if (D_800A4EE8 == 0) {
            return 0;
        }
        var_s2 = *((temp_v1 * 4) + D_800A4EE8->unk14) + (temp_a1 * 0x14);
block_6:
        var_s3 = 0;
        temp_s7 = D_800A4F17;
        D_800A4F17 = 1;
        temp_s6 = var_s2->unk0;
        temp_v0 = func_800331D4(arg0 & 0xFFFF, temp_a1, temp_a2);
        if (temp_v0 == 0) {
            if (!(arg2 & 0x4000) || (arg2 & 0x3000)) {
                temp_v0_2 = func_8003310C(temp_s6);
                if (temp_v0_2 != 0) {
                    var_s3 = temp_v0_2;
                    var_s0 = var_s3 - 1;
                    var_s1 = (var_s0 * 0x54) + (&D_800A4F17 - 0x82F);
                    goto block_13;
                }
            }
        } else {
            var_s0 = temp_v0 - 1;
            var_s1 = (var_s0 * 0x54) + (&D_800A4F17 - 0x82F);
            if (var_s1->unk8 == 0) {
                var_s3 = var_s0 + 1;
                func_8003324C(var_s0 & 0xFFFF);
block_13:
                var_s1->unk4 = arg0;
                var_s1->unk6 = sp10;
                var_s1->unk2 = temp_s6;
                var_s1->unk0 = (s16) ((arg1->unk0 & 0xC0) | 1);
                var_s1->unkA = 5;
                var_s1->unk8 = (u16) var_s2->unkC;
                func_80032A74(var_s1, var_s0, var_s2, arg2 & 0xFFFF);
            }
        }
        D_800A4F17 = temp_s7;
        var_v0 = var_s3;
        /* Duplicate return node #15. Try simplifying control flow for better match */
        return var_v0;
    }
    return var_v0;
}
