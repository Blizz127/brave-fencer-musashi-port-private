/* Native retail instruction export [80052BEC,80052D00).
 * Verified against asm/main.s and the extracted EXE. No C match claim. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void func_8004921C(s16, s16);                          /* static */
void func_80059D68(s16 *, u16);                        /* static */
extern s16 D_800794E0;
extern s16 D_800794E4;
extern u16 D_800A5E50;
extern u16 D_800A5E52;
extern s16 D_800A6440;
extern s16 D_800A6442;
extern s16 D_800A6548;
extern s16 D_800A654A;
extern s16 D_800C7C74;
extern s16 D_800C7C88;

void func_80052BEC(void) {
    s16 *var_v0;
    s16 *var_v1;
    s16 temp_s0;
    s16 temp_s1;
    u16 temp_a1;

    if (D_800C7C88 != 0) {
        temp_a1 = (u16) (&D_800794E0)[D_800C7C74];
        D_800A654A = 0;
        D_800A6548 = 0;
        D_800A6440 = D_800A5E50 + temp_a1;
        D_800A6442 = D_800A5E52 + (u16) (&D_800794E4)[D_800C7C74];
        func_80059D68(&D_800A6440 - 8, temp_a1);
        return;
    }
    var_v0 = &D_800794E0;
    if (D_800C7C74 == 0) {
        var_v0 = &D_800794E0 + 2;
    }
    var_v1 = &D_800794E4;
    temp_s1 = (s16) D_800A5E50 + *var_v0;
    if (D_800C7C74 == 0) {
        var_v1 = &D_800794E4 + 2;
    }
    temp_s0 = (s16) D_800A5E52 + *var_v1;
    func_8004921C(temp_s1, temp_s0);
    D_800A6548 = temp_s1;
    D_800A654A = temp_s0;
}
