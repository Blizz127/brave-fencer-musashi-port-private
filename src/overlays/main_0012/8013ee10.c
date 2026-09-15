/* Overlay range [8013EE10,8013EF88) from MAIN.CD member 0012.
 * SHA256(span)=1f10207e37f3d038071277dbcd68fe7862d0b589641d02a42467eb242cef858b.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

extern s32 D_8017F6FA;
extern s32 D_8017F6FC;
void func_801376E8(s32, s32 (*)());                      /* static */
void func_8013FAF8(s32, s32);                              /* static */
s32 func_80141CA4(s32 (*)(), s32, s16);               /* static */
extern u16 D_800B9A02;
extern u16 D_80115112;
extern u16 D_80115118;
extern s32 *D_80115168;
extern s32 *D_80115188;
extern s32 *D_801151C8;
extern s32 D_801151D0;
extern u16 D_8017F6F8;

void func_8013EE10(void) {
    s16 temp_a0;
    s16 temp_v1;
    s16 var_a2;
    s16 var_a2_2;
    s32 temp_a1;
    s32 temp_v0;
    s32 temp_v0_2;
    s32 var_v0;

    D_801151D0 = *(&D_801151C8 + (D_800B9A02 * 4));
    func_8013FAF8(0, 5);
    var_a2 = 0;
    do {
        temp_a1 = (s32) (var_a2 << 0x10) >> 0xE;
        temp_a0 = var_a2 + 1;
        var_a2 = temp_a0;
        temp_v0 = (s32) (*(&D_80115168 + temp_a1) * 3) >> 2;
        *(&D_80115188 + temp_a1) = temp_v0;
        *(&D_80115168 + temp_a1) = *(&D_80115168 + temp_a1) - temp_v0;
    } while (temp_a0 < 5);
    if (D_8017F6FA < 3) {
        D_8017F6FA = (s16) (D_8017F6FA + 1);
    }
    D_8017F6F8 += 2;
    D_80115118 += 1;
    if ((u16) D_80115118 >= 5U) {
        func_801376E8(func_80141CA4(D_8017F6FA, temp_a1, var_a2), D_8017F6FC);
        var_a2_2 = 0;
        var_v0 = 0 << 0x10;
        do {
            temp_v1 = var_a2_2 + 1;
            var_a2_2 = temp_v1;
            temp_v0_2 = var_v0 >> 0xE;
            (temp_v0_2 + (&D_80115118 - 8))->unk78 = 0;
            *(&D_80115168 + temp_v0_2) = 0;
            var_v0 = var_a2_2 << 0x10;
        } while (temp_v1 < 5);
        D_80115112 += 1;
    }
}
