/* Exact retail word export for [8003750C,8003775C); EXE and assembly verified. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

extern s32 D_80064D4A;
void func_80031A98();                                  /* static */
s32 func_8003C4F0();                               /* static */
void func_800415A8(s16, s16, u8);                      /* static */
extern u8 D_8006AEF4;
extern s32 *D_80076248;
extern s32 *D_80076251;
extern s32 *D_80076252;
extern s8 D_80076298;
extern s32 D_8007629C;
extern s32 *D_800A4640;
extern s32 *D_800A4642;
extern s32 *D_800A4644;
extern s32 *D_800A4648;
extern s32 *D_800A4650;
extern s32 *D_800C5328;
extern s32 *D_800C532A;

s32 func_8003750C(void) {
    s16 temp_a0_3;
    s16 temp_a1;
    s32 temp_a0;
    s32 temp_a0_2;
    s32 temp_v1;
    s32 var_s0;
    s32 var_s1;
    s32 var_s2;
    s32 var_v0;
    s32 var_v0_2;
    u8 temp_a2;

    if (D_8007629C != 1) {
        if (D_8007629C < 2) {
            if (D_8007629C != 0) {
                return 0;
            }
            var_v0 = 0;
            if (!(D_8006AEF4 & 2)) {
                D_8006AEF4 |= 2;
                D_8007629C = 1;
                goto block_8;
            }
            /* Duplicate return node #24. Try simplifying control flow for better match */
            return var_v0;
        }
        var_s2 = 0;
        if (D_8007629C != 2) {
            return 0;
        }
        goto block_11;
    }
block_8:
    if (!(D_8006AEF4 & 1) || (var_v0 = 0, (func_8003C4F0(0) != 0))) {
        D_8007629C += 1;
        var_s2 = 0;
block_11:
        var_s1 = 0;
        var_s0 = 0;
        do {
            if (*(&D_80076251 + var_s0) != 0) {
                temp_a0 = *(&D_80076248 + var_s0);
                temp_a2 = *(&D_80076252 + var_s0);
                if (!(temp_a0 & 0x6000)) {
                    temp_v1 = temp_a2 * 0x18;
                    temp_a1 = *(&D_800A4644 + temp_v1);
                    if (temp_a1 != 0) {
                        var_v0_2 = temp_a2 * 2;
                        if (temp_a1 != *(D_80064D4A + (temp_a0 * 0xC))) {
                            *(&D_800C532A + (*(&D_800A4648 + temp_v1) * 4)) = -1;
                            *(&D_800A4644 + temp_v1) = 0;
                            *(&D_800A4648 + temp_v1) = 0;
                            goto block_17;
                        }
                    } else {
block_17:
                        var_v0_2 = temp_a2 * 2;
                    }
                    temp_a0_2 = (var_v0_2 + temp_a2) * 8;
                    if (*(&D_800A4650 + temp_a0_2) == 0) {
                        *(&D_800A4650 + temp_a0_2) = 1;
                        *(&D_800C5328 + (*(&D_800A4640 + temp_a0_2) * 4)) = -1;
                        temp_a0_3 = *(&D_800A4642 + var_s1);
                        if (temp_a0_3 >= 0) {
                            func_800415A8(temp_a0_3, temp_a1, temp_a2);
                            *(&D_800A4642 + var_s1) = -1;
                        }
                        func_80031A98();
                    }
                }
            }
            var_s1 += 0x18;
            var_s2 += 1;
            var_s0 += 0x10;
        } while (var_s2 < 5);
        D_8007629C = 0;
        D_80076298 = 0;
        var_v0 = 1;
    }
    return var_v0;
}
