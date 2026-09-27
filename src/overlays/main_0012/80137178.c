/* Overlay range [80137178,801372B0) from MAIN.CD member 0012.
 * SHA256(span)=c2eabd1eb74125e4ece4320368a96526ec2346ca01efe14a4d58461c914459f6.
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

void func_80137178(s32 arg0, s32 arg1) {
    s8 sp1E;
    s8 sp1D;
    s8 sp1C;
    s16 sp1A;
    s16 sp18;
    s16 sp16;
    s16 sp14;
    s32 sp10;
    s16 temp_s0;
    s16 temp_s3;
    s16 temp_s5;
    s16 temp_s5_2;

    temp_s3 = arg0 - 3;
    temp_s5 = arg1 - 3;
    temp_s0 = arg0 + 3;
    sp16 = temp_s5;
    sp1A = temp_s5;
    temp_s5_2 = arg1 + 3;
    sp10 = 0;
    sp1C = 0;
    sp1D = 0;
    sp1E = 0xFF;
    sp14 = temp_s3;
    sp18 = temp_s0;
    func_80051DC8(&sp10, (D_800B9A02 * 0x14) + &D_800A6518, 0);
    sp10 = 0;
    sp1C = 0;
    sp1D = 0;
    sp1E = 0xFF;
    sp14 = temp_s3;
    sp16 = temp_s5_2;
    sp18 = temp_s0;
    sp1A = temp_s5;
    func_80051DC8(&sp10, (D_800B9A02 * 0x14) + &D_800A6518, 0);
    sp10 = 0;
    sp1C = 0;
    sp1D = 0;
    sp1E = 0xFF;
    sp14 = temp_s3;
    sp16 = temp_s5_2;
    sp18 = temp_s0;
    sp1A = temp_s5_2;
    func_80051DC8(&sp10, (D_800B9A02 * 0x14) + &D_800A6518, 0);
}
