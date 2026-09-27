/* Native retail instruction export [80010000,800100A0).
 * Verified against asm/main.s and the extracted EXE. No C match claim. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

extern s32 D_800629A0;
extern s32 D_8006299C;
extern s32 D_80062998;
extern s32 D_800629BC;
extern s32 D_800629C0;
extern s32 D_80074750;
void func_80010000(s32 arg1, s32 arg2, s32 arg3);   /* static */
void func_80010178(s32, s32);                          /* static */
extern s32 *D_800C7F08;

void func_80010000(s32 arg1, s32 arg2, s32 arg3) {
    s32 (*temp_t0)();
    s32 (*var_v0)();
    s32 temp_a0_2;
    s32 temp_a1;
    s32 temp_ra;
    s32 var_s1;
    u32 temp_a0;
    void (*var_s0)(s32, s32, s32);

    var_v0 = D_80074750;
    do {
        *var_v0 = 0;
        var_v0 += 4;
    } while ((u32) var_v0 < (u32) &D_800C7F08);
    temp_a0 = (u32) ((s32) &D_800C7F08 * 8) >> 3;
    temp_a1 = ((D_800629BC - 8) - D_800629C0) - temp_a0;
    D_800629A0 = temp_a1;
    temp_a0_2 = temp_a0 | 0x80000000;
    D_8006299C = temp_a0_2;
    D_80074750 = (s32) saved_reg_ra;
    temp_ra = D_80074750;
    func_80010178(temp_a0_2, temp_a1);
    M2C_BREAK(0);
    arg3 = temp_ra;
    if (D_80062998 == 0) {
        D_80062998 = 1;
        var_s0 = func_80010000;
        var_s1 = 0;
        if (0 != 0) {
            do {
                temp_t0 = *var_s0;
                var_s0 += 4;
                var_s1 -= 1;
                temp_t0();
            } while (var_s1 != 0);
        }
    }
}
