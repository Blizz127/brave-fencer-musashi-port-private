/* Overlay range [80136F3C,80137030) from MAIN.CD member 0012.
 * SHA256(span)=e3a1941cf86c3eec6db1c67973ac28ac124e38c69c73c285dd324b14635cffb1.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void func_80051DC8(s32 *, void *, s32);                  /* extern */
extern s32 *D_800A6518;
extern u16 D_800B9A02;

void func_80136F3C(s32 arg0, s32 arg1) {
    s8 sp1E;
    s8 sp1D;
    s8 sp1C;
    s16 sp1A;
    s16 sp18;
    s16 sp16;
    s16 sp14;
    s32 sp10;
    s16 temp_s0;
    s16 temp_s1;
    s16 temp_s2;
    s16 temp_s5;

    temp_s5 = arg1 - 3;
    temp_s0 = arg0 + 3;
    temp_s2 = arg1 + 3;
    temp_s1 = arg0 - 3;
    sp10 = 0;
    sp1C = 0xFF;
    sp1D = 0;
    sp1E = 0;
    sp14 = temp_s1;
    sp16 = temp_s5;
    sp18 = temp_s0;
    sp1A = temp_s2;
    func_80051DC8(&sp10, (D_800B9A02 * 0x14) + &D_800A6518, 0);
    sp10 = 0;
    sp1C = 0xFF;
    sp1D = 0;
    sp1E = 0;
    sp14 = temp_s0;
    sp16 = temp_s5;
    sp18 = temp_s1;
    sp1A = temp_s2;
    func_80051DC8(&sp10, (D_800B9A02 * 0x14) + &D_800A6518, 0);
}
