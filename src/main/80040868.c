/* Native retail instruction export [80040868,80040938).
 * Verified against asm/main.s and the extracted EXE. No C match claim. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

extern u16 D_80078D8C;
extern u16 D_80078D8E;
extern s32 *D_80079588;
extern s32 *D_8007958C;
extern s32 *D_800795A3;
extern u16 D_800B9B3A;
extern u16 D_800C7F04;
extern u16 D_800C7F06;

void func_80040868(void) {
    s32 temp_v0;
    s32 var_a1;
    s32 var_a2;
    u16 temp_a0;
    u16 temp_v1;
    u32 var_v1;

    var_v1 = D_800B9B3A & 0xFFFF;
    if (var_v1 < 0x10U) {
        var_a2 = 1 << var_v1;
        var_a1 = 0;
    } else {
        var_a2 = 0;
        var_a1 = 1 << (var_v1 - 0x10);
        var_v1 = D_800B9B3A & 0xFFFF;
    }
    temp_v0 = var_v1 * 0x34;
    *(&D_800795A3 + temp_v0) = 0;
    *(&D_8007958C + temp_v0) = 0;
    *(&D_80079588 + temp_v0) = 0;
    temp_v1 = D_800C7F04 | var_a2;
    D_800C7F04 = temp_v1;
    D_80078D8C &= ~temp_v1;
    temp_a0 = D_800C7F06 | var_a1;
    D_800C7F06 = temp_a0;
    D_80078D8E &= ~temp_a0;
}
