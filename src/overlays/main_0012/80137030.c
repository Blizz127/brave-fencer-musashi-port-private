/* Overlay range [80137030,80137178) from MAIN.CD member 0012.
 * SHA256(span)=a9794940e97da2c42f717f73b0357258cdccde43fab4a07115037848a2258377.
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

void func_80137030(s16 arg0, s16 arg1) {
    s8 sp1E;
    s8 sp1D;
    s8 sp1C;
    s16 sp1A;
    s16 sp18;
    s16 sp16;
    s16 sp14;
    s32 sp10;
    s16 temp_s6;

    temp_s6 = arg1 - 3;
    sp10 = 0;
    sp1C = 0;
    sp1D = 0xFF;
    sp1E = 0;
    sp14 = arg0 - 3;
    sp16 = temp_s6;
    sp18 = arg0;
    sp1A = arg1;
    func_80051DC8(&sp10, (D_800B9A02 * 0x14) + &D_800A6518, 0);
    sp16 = temp_s6;
    sp10 = 0;
    sp1C = 0;
    sp1D = 0xFF;
    sp1E = 0;
    sp14 = arg0 + 3;
    sp18 = arg0;
    sp1A = arg1;
    func_80051DC8(&sp10, (D_800B9A02 * 0x14) + &D_800A6518, 0);
    sp10 = 0;
    sp1C = 0;
    sp1D = 0xFF;
    sp1E = 0;
    sp14 = arg0;
    sp16 = arg1 + 3;
    sp18 = arg0;
    sp1A = arg1;
    func_80051DC8(&sp10, (D_800B9A02 * 0x14) + &D_800A6518, 0);
}
