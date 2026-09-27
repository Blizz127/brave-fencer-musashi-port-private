/* Native retail instruction export [8003D548,8003D630).
 * Verified against asm/main.s and the extracted EXE. No C match claim. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

extern s32 D_8006B8B4;
extern s32 D_8006B8C4;
void func_8003FE3C(s32, s32, u16 *, s32 (*)());            /* static */
extern s32 D_800A6510;
extern s32 D_800AE818;
extern s32 D_800C6D30;
extern s32 *D_800C7458;

void func_8003D548(void) {
    s32 (*var_v1)();
    s32 (*var_v1_2)();
    void *var_v1_3;
    s32 *var_v0;
    s32 var_a0;
    s32 var_a0_2;
    s32 var_a0_3;
    s32 var_a1;
    s32 var_a1_2;
    u16 *var_a2;
    u16 *var_a2_2;
    u16 temp_v0;
    u16 temp_v0_2;

    var_a2 = (u16 *)0x1F801C00;
    var_a0 = 0;
    do {
        var_a1 = 0;
        var_v1 = D_8006B8B4;
loop_2:
        temp_v0 = *var_v1;
        var_v1 += 2;
        var_a1 += 1;
        *var_a2 = temp_v0;
        var_a2 += 2;
        if (var_a1 < 8) {
            goto loop_2;
        }
        var_a0 += 1;
    } while (var_a0 < 0x18);
    var_a2_2 = (u16 *)0x1F801D80;
    var_a0_2 = 0;
    var_v1_2 = D_8006B8C4;
    do {
        temp_v0_2 = *var_v1_2;
        var_v1_2 += 2;
        var_a0_2 += 1;
        *var_a2_2 = temp_v0_2;
        var_a2_2 += 2;
    } while (var_a0_2 < 0x10);
    func_8003FE3C(0x18, var_a1, var_a2_2, D_8006B8B4);
    var_a1_2 = 0;
    var_v1_3 = &D_800C7458;
    do {
        var_a0_3 = 0xF;
        var_v0 = var_v1_3 + 0x3C;
loop_8:
        *var_v0 = 0;
        var_a0_3 -= 1;
        var_v0 -= 4;
        if (var_a0_3 >= 0) {
            goto loop_8;
        }
        var_a1_2 += 1;
        var_v1_3 += 0x40;
    } while (var_a1_2 < 0x20);
    D_800C6D30 = 0x3C;
    D_800AE818 = 0;
    D_800A6510 = 0;
}
