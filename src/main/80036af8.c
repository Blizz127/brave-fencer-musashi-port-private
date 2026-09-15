/* Exact retail word export for [80036AF8,80036D24); EXE and assembly verified. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

extern s32 D_8006A69C;
extern s32 D_8006A6A0;
extern s32 D_8006A6A4;
extern s32 D_8006AEE8;
s32 func_80034CF0(void *);                             /* static */
void func_80034DFC(s16);                               /* static */
extern s32 func_80035270;
extern s32 func_800359B0;
extern s32 func_80036D24;
extern s32 func_80036FB0;
s32 func_80043B1C(s32);                             /* static */
extern s16 D_80078F10;
extern s8 D_800A46BA;
extern s8 D_800A4F1A;

void func_80036AF8(s32 arg0, s16 arg1) {
    s32 (*sp38)();
    s32 (*sp34)();
    s32 sp30;
    s32 (*sp2C)();
    s32 sp20;
    s32 sp1C;
    s32 (*sp18)();
    s32 sp10;
    s16 *var_s0;
    s32 temp_a0;
    s32 temp_a0_2;
    s32 temp_a2;
    s32 temp_v0;
    s32 temp_v0_2;
    s32 temp_v1;
    s32 temp_v1_3;
    s32 var_a3;
    s32 var_s1;
    s32 var_v0;
    u8 temp_v1_2;

    if (arg1 & 0x4000) {
        temp_a2 = arg1 & 0xF;
        var_a3 = temp_a2;
        temp_v0 = arg1 << 0x10;
        temp_v1 = temp_v0 >> 0x14;
        temp_a0 = (temp_v0 >> 0x19) & 0x1F;
        if (temp_v1 & 1) {
            var_a3 = temp_a2 + 4;
            if (*(D_8006A6A0 + (temp_a0 * 0x48)) == 0) {
                var_a3 = temp_a2 + 8;
            }
        }
        temp_a0_2 = (s32) ((temp_v1 & 0x1F) << 0x10) >> 0x11;
        temp_v1_2 = (*(D_8006A69C + (temp_a0 * 0x48)) + (temp_a0_2 << 6) + (var_a3 * 4))->unk1;
        if (temp_v1_2 & 0xF0) {
            temp_v1_3 = temp_v1_2 & 0xF;
            if (D_8006AEE8 != 0) {
                if (temp_v1_3 != 0) {
                    if (temp_v1_3 == 1) {
                        var_s1 = 0;
                        if (D_8006AEE8 > 0) {
                            var_s0 = &D_80078F10;
                            do {
                                var_s1 += 1;
                                func_80034DFC(*var_s0);
                                *var_s0 = 0;
                                var_s0 += 4;
                            } while (var_s1 < D_8006AEE8);
                        }
                        D_8006AEE8 = 0;
                    }
                    goto block_12;
                }
            } else {
block_12:
                sp18 = func_80035270;
                D_800A46BA = 0;
                if ((s16) temp_a0_2 != 0) {
                    var_v0 = func_80043B1C(arg0) + *(((s16) temp_a0_2 * 4) + ((temp_a0 * 0x48) + D_8006A6A4));
                } else {
                    var_v0 = func_80043B1C(arg0);
                }
                sp1C = var_v0;
                sp20 = (s32) arg1;
                sp2C = func_80036D24;
                sp34 = func_800359B0;
                sp30 = 0;
                sp38 = func_80036FB0;
                temp_v0_2 = func_80034CF0(&sp10);
                if (temp_v0_2 != 0) {
                    *(&D_80078F10 + (D_8006AEE8 * 4)) = temp_v0_2;
                    D_8006AEE8 = (s32) (D_8006AEE8 + 1);
                }
                D_800A4F1A = 1;
            }
        }
    }
}
