/* Exact retail word export for [80030A14,80030CA4); EXE and assembly verified. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

extern s32 D_80064D44;
extern s32 D_8006A970;
s32 func_8003F144(s16, u8, u8, void *);                /* static */
s32 func_8003F380(s16, s16);                        /* static */
s32 func_80042374();                               /* static */
extern s32 D_800760F0;
extern s32 D_800760F4;
extern s32 *D_800A4644;
extern s32 *D_800A4646;
extern s32 *D_800A4648;
extern s32 *D_800A4650;
extern s16 D_800A46CC;
extern s16 D_800A46CE;
extern s16 D_800A46D0;
extern s16 D_800A46D2;
extern s32 *D_800C5328;
extern s32 *D_800C532A;

s32 func_80030A14(void) {
    s32 sp10;
    s32 *var_s3;
    s32 temp_v0;
    s32 var_s1;
    s32 var_s4;
    s32 var_v0;
    void *temp_a2;
    void *var_s0;
    void *var_s2;

    var_v0 = 0;
    if ((func_80042374(0) << 0x10) != 0) {
        temp_a2 = (D_800A46D0 * 0xC) + D_80064D44;
        var_s2 = temp_a2->unk0 + (D_800760F0 * 2);
        var_s3 = *(D_8006A970 + (D_800A46CE * 4)) + (D_800760F0 * 0xC);
        var_s4 = 0xA;
        if (D_800760F4 < 0xB) {
            if (temp_a2->unk6 != 0) {
                *(&D_800A4646 + (D_800A46CE * 0x18)) = (s16) temp_a2->unk7;
                *(&D_800A4644 + (D_800A46CE * 0x18)) = (s16) temp_a2->unk6;
                *(&D_800A4648 + (D_800A46CE * 0x18)) = (s16) temp_a2->unk8;
                *(&D_800C532A + (temp_a2->unk8 * 4)) = (u16) D_800A46CE;
            }
            var_s4 = D_800760F4;
            D_800760F4 = 0;
            *(&D_800C5328 + (D_800A46D0 * 4)) = (u16) D_800A46CE;
        } else {
            D_800760F4 -= 0xA;
        }
        var_s1 = 0;
        if (var_s4 > 0) {
            var_s0 = var_s3 + 8;
            do {
                if ((func_8003F144(D_800A46D2, var_s2->unk0, var_s2->unk1, &sp10) << 0x10) == 0) {
                    temp_v0 = func_8003F380(D_800A46D2, sp26);
                    if (temp_v0 >= 0) {
                        var_s0->unk2 = 1;
                        var_s0->unk-4 = (s16) (sp14 << 8);
                        *var_s3 = temp_v0;
                        var_s0->unk-2 = sp20;
                        var_s0->unk0 = sp22;
                    }
                }
                var_s1 += 1;
                var_s2 += 2;
                var_s0 += 0xC;
                var_s3 += 0xC;
            } while (var_s1 < var_s4);
        }
        if (D_800760F4 != 0) {
            D_800760F0 += 0xA;
            return 0;
        }
        var_v0 = 1;
        *(&D_800A4650 + (D_800A46CE * 0x18)) = 0;
        D_800A46CC = 0;
        /* Duplicate return node #15. Try simplifying control flow for better match */
        return var_v0;
    }
    return var_v0;
}
