/* Main-exec range [80042154,800422B4) from the SLUS executable.
 * SHA256(span)=405b7bc8510d6b7f8a7ac71da1575110516473a4d742f12485af9a0877c3acf1.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

extern s32 D_8006BA84;
extern s32 D_8006BA88;
void func_8003C498(s32);                               /* static */
void func_800401A0();                                 /* static */
void func_800422B4(s32, s16);                            /* static */
void func_800422E8(s32, u32);                          /* static */
extern s32 *D_800B9B40;
extern s32 *D_800C7C98;
extern s32 *D_800C7CE0;

s16 func_80042154(s32 arg0, u32 arg1, s16 arg2) {
    s16 temp_s2;
    s16 var_v0;
    s32 temp_s0;
    u32 temp_v0;
    u32 var_s0;

    if (((u32) (arg2 & 0xFFFF) < 0x11U) && (*(&D_800B9B40 + arg2) == 2)) {
        temp_s0 = arg2 * 4;
        if (D_8006BA84 == 0) {
            D_8006BA88 = arg2;
            D_8006BA84 = (u32) *(&D_800C7C98 + temp_s0);
            func_800422B4(0, arg2);
            func_8003C498(*(&D_800C7CE0 + temp_s0));
        }
        temp_s2 = D_8006BA88;
        var_s0 = arg1;
        if (temp_s2 != arg2) {
            goto block_5;
        }
        if ((u32) D_8006BA84 < var_s0) {
            var_s0 = D_8006BA84;
        }
        func_800401A0(1);
        func_800422E8(arg0, var_s0);
        temp_v0 = D_8006BA84 - var_s0;
        D_8006BA84 = temp_v0;
        var_v0 = -2;
        if (temp_v0 == 0) {
            var_v0 = temp_s2;
            D_8006BA88 = -1;
            D_8006BA84 = 0U;
            *(&D_800B9B40 + var_v0) = 1;
        }
        return var_v0;
    }
block_5:
    func_800401A0(0);
    return -1;
}
