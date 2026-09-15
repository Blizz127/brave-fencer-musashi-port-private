/* Main-exec range [80028488,8002850C) from the SLUS executable.
 * SHA256(span)=8751db49e198c44176eabc2fc6f331475d627fdbc86e66e6e86f500ddaf09f37.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void func_80028620(u32, void *);                       /* static */
extern s32 *D_800A5E88;
extern s32 *D_800A5E8C;
extern s32 *D_800A5E90;
extern s32 *D_800A5E94;
extern s32 *D_800A5E95;
extern s32 *D_800A5E96;

void func_80028488(s32 arg0) {
    s32 temp_a1;
    u32 temp_a0;

    temp_a0 = arg0 & 0xFFFF;
    if (temp_a0 < 3U) {
        temp_a1 = temp_a0 * 0x10;
        *(&D_800A5E90 + temp_a1) = 0x64;
        *(&D_800A5E88 + temp_a1) = 0;
        *(&D_800A5E8C + temp_a1) = 0;
        *(&D_800A5E94 + temp_a1) = 0;
        *(&D_800A5E95 + temp_a1) = 0;
        *(&D_800A5E96 + temp_a1) = 0;
        func_80028620(temp_a0, temp_a1 + &D_800A5E88);
    }
}
