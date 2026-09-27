/* Exact retail word export for [8002FF0C,800301A4); EXE and assembly verified. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

extern s32 D_80064D49;
extern s32 D_80064D4A;
extern s32 D_80064D4E;
s32 func_80030730(s16);                             /* static */
s32 func_80030A14(s16);                             /* static */
void func_80031A98(s32, s32);                          /* static */
void func_800415A8(s16);                               /* static */
s16 func_800419B0(s16);                             /* static */
s16 func_80041A80(s32, s32, s32);                     /* static */
extern s32 *D_800A463C;
extern s32 *D_800A4640;
extern s32 *D_800A4642;
extern s32 *D_800A4644;
extern s32 *D_800A4648;
extern s32 *D_800A464C;
extern s32 *D_800A4650;
extern s32 D_800A46BC;
extern s16 D_800A46CC;
extern s16 D_800A46CE;
extern s16 D_800A46D0;
extern s16 D_800A46D2;
extern s16 D_800A4EF6;
extern s32 *D_800C5328;
extern s32 *D_800C532A;

s32 func_8002FF0C(s16 arg0, s32 arg1) {
    s16 temp_v0_2;
    s16 temp_v1;
    s32 temp_a0;
    s32 temp_a1;
    s32 temp_s0;
    s32 var_v0;
    s32 var_v0_2;
    s32 var_v1;
    u8 temp_s1;
    u8 temp_v0;

    if (D_800A46CC == 0) {
        temp_a1 = arg0 * 0xC;
        temp_s1 = *(D_80064D49 + temp_a1);
        temp_a0 = temp_s1 * 0x18;
        temp_v1 = *(&D_800A4644 + temp_a0);
        var_v0_2 = temp_s1 * 2;
        if (temp_v1 != 0) {
            if (temp_v1 != *(D_80064D4A + temp_a1)) {
                *(&D_800C532A + (*(&D_800A4648 + temp_a0) * 4)) = -1;
                *(&D_800A4644 + temp_a0) = 0;
                *(&D_800A4648 + temp_a0) = 0;
            }
            var_v0_2 = temp_s1 * 2;
        }
        temp_s0 = (var_v0_2 + temp_s1) * 8;
        if (*(&D_800A4650 + temp_s0) == 0) {
            *(&D_800C5328 + (*(&D_800A4640 + temp_s0) * 4)) = -1;
            func_80031A98(temp_a0, temp_a1);
        }
        D_800A46CE = (s16) temp_s1;
        *(&D_800A4640 + temp_s0) = arg0;
        D_800A46D0 = arg0;
        D_800A46BC = arg1;
        *(&D_800A464C + temp_s0) = arg1;
        temp_v0 = *(D_80064D4E + (arg0 * 0xC));
        if (temp_v0 != 0) {
            D_800A4EF6 = (s16) temp_v0;
        }
        temp_v0_2 = func_80041A80(arg1, -1, *(&D_800A463C + temp_s0));
        D_800A46D2 = temp_v0_2;
        (temp_s0 + (&D_800A46CE - 0x96))->unkA = temp_v0_2;
        if ((temp_v0_2 == -1) || (func_800419B0(D_800A46D2) == -1)) {
            *(&D_800A4650 + temp_s0) = 1;
            return 1;
        }
        D_800A46CC = 1;
        goto block_13;
    }
block_13:
    var_v1 = 0;
    switch (D_800A46CC) {                           /* irregular */
    case 1:
        var_v1 = func_80030730(D_800A46CC);
        break;
    case 2:
        var_v1 = func_80030A14(D_800A46CC);
        break;
    }
    var_v0 = 0;
    if (var_v1 != 0) {
        func_800415A8(D_800A46D2);
        var_v0 = 1;
        D_800A46D2 = -1;
        *(&D_800A4642 + (D_800A46CE * 0x18)) = -1;
    }
    return var_v0;
}
