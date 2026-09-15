/* Main-exec range [800301C8,80030470) from the SLUS executable.
 * SHA256(span)=fffe827d70041321fca72c71d62fd47df447a58753ea72507926bcc68b6070c7.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

extern s32 D_80064D49;
extern s32 D_80064D4A;
extern s32 D_8006AA14;
extern s32 func_800301A4;
void func_80031A98(s32, u8, s32);                      /* static */
s32 func_80037CD8(s32 (*)());                         /* static */
void func_800415A8(s16);                               /* static */
s16 func_80041A50(s32, s32, s32);                     /* static */
extern u8 D_8006AEF4;
extern s32 *D_800A463C;
extern s32 *D_800A4640;
extern s32 *D_800A4642;
extern s32 *D_800A4644;
extern s32 *D_800A4648;
extern s32 *D_800A464C;
extern s32 *D_800A4650;
extern s32 D_800A46BC;
extern s32 D_800A46C0;
extern s32 D_800A46C4;
extern s16 D_800A46CC;
extern s16 D_800A46CE;
extern s16 D_800A46D0;
extern s16 D_800A46D2;
extern s32 *D_800C5328;
extern s32 *D_800C532A;

s32 func_800301C8(s16 arg0, s32 arg1, s32 arg2) {
    s16 temp_v0_3;
    s16 temp_v1;
    s16 var_v0_2;
    s32 temp_a0;
    s32 temp_a3;
    s32 temp_s1;
    s32 temp_v0;
    s32 var_v0;
    u8 temp_v0_2;
    u8 temp_v0_4;

    if (D_800A46CC == 0) {
        temp_a3 = arg0 * 0xC;
        D_800A46C4 = 0;
        temp_v0_2 = *(D_80064D49 + temp_a3);
        D_800A46C0 = arg2;
        D_800A46BC = arg1;
        D_800A46CE = (s16) temp_v0_2;
        temp_a0 = temp_v0_2 * 0x18;
        temp_v1 = *(&D_800A4644 + temp_a0);
        *(&D_800A464C + temp_a0) = arg1;
        var_v0 = temp_v0_2 * 2;
        if (temp_v1 != 0) {
            if (temp_v1 != *(D_80064D4A + temp_a3)) {
                *(&D_800C532A + (*(&D_800A4648 + temp_a0) * 4)) = -1;
                *(&D_800A4644 + temp_a0) = 0;
                *(&D_800A4648 + temp_a0) = 0;
            }
            var_v0 = temp_v0_2 * 2;
        }
        temp_s1 = (var_v0 + temp_v0_2) * 8;
        if (*(&D_800A4650 + temp_s1) == 0) {
            *(&D_800C5328 + (*(&D_800A4640 + temp_s1) * 4)) = -1;
            func_80031A98(arg1, temp_v0_2, temp_a3);
            func_800415A8(*(&D_800A4642 + temp_s1));
        }
        D_800A46D0 = arg0;
        *(&D_800A4640 + temp_s1) = arg0;
        *(&D_800A4650 + temp_s1) = 1;
        temp_v0_3 = func_80041A50(arg1, -1, *(&D_800A463C + temp_s1));
        D_800A46D2 = temp_v0_3;
        (temp_s1 + (&D_800A46D0 - 0x98))->unkA = temp_v0_3;
        if (temp_v0_3 == -1) {
            *(&D_800A4650 + temp_s1) = 1;
            return 1;
        }
        var_v0_2 = 1;
        if (func_80037CD8(func_800301A4) != 0) {
            temp_v0_4 = D_8006AEF4 | 2;
            D_8006AEF4 = temp_v0_4;
            if (temp_v0_4 & 1) {
                var_v0_2 = 2;
            } else {
                var_v0_2 = 3;
            }
        }
        D_800A46CC = var_v0_2;
        return 0;
    }
    temp_v0 = *(D_8006AA14 + (D_800A46CC * 4))();
    if (temp_v0 != 0) {
        if (D_800A46D2 >= 0) {
            func_800415A8(D_800A46D2);
            D_800A46D2 = -1;
            *(&D_800A4642 + (D_800A46CE * 0x18)) = -1;
        }
    }
    return temp_v0;
}
