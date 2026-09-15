/* Native retail instruction export [80052D00,80052D90).
 * Verified against asm/main.s and the extracted EXE. No C match claim. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void func_80059D68(s16 *, s16, s16);                   /* static */
extern s32 *D_800794E0;
extern s32 *D_800794E4;
extern s16 D_800A6438;
extern s16 D_800A643A;
extern u16 D_800A643C;
extern u16 D_800A643E;
extern s16 D_800AE820;
extern s16 D_800AE822;
extern u16 D_800AE824;
extern u16 D_800AE826;
extern s16 D_800C7C74;

void func_80052D00(void) {
    s16 temp_a1;
    s16 temp_a2;
    s32 temp_v0;

    temp_v0 = D_800C7C74 * 2;
    temp_a1 = *(&D_800794E0 + temp_v0);
    temp_a2 = *(&D_800794E4 + temp_v0);
    D_800A643C = D_800AE824;
    D_800A643E = D_800AE826;
    D_800A6438 = D_800AE820 + temp_a1;
    D_800A643A = D_800AE822 + temp_a2;
    func_80059D68(&D_800A6438, temp_a1, temp_a2);
}
