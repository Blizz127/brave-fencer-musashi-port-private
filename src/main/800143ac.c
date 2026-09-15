/* Exact retail word export for [800143AC,80014444); EXE and assembly verified. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void func_800145EC();                                 /* static */
void func_8004239C();                                 /* static */
extern s32 *D_800A6518;
extern s32 *D_800A651C;
extern s32 *D_800A6520;
extern s32 *D_800A6524;
extern s32 *D_800A6610;
extern s8 D_800AF7C2;
extern s8 D_800AF7C3;
extern s8 D_800AF7C4;

void func_800143AC(void) {
    void *var_a0;
    s32 var_a1;
    s32 var_v1;

    func_800145EC(1);
    func_8004239C(0);
    var_a1 = 0;
    var_a0 = &D_800A6610;
    var_v1 = 0;
    D_800AF7C4 = 0;
    D_800AF7C3 = 0;
    D_800AF7C2 = 0;
    do {
        *(&D_800A651C + var_v1) = var_a0;
        var_a0 += 0x4000;
        *(&D_800A6518 + var_v1) = 0xC;
        *(&D_800A6520 + var_v1) = 0;
        *(&D_800A6524 + var_v1) = 0;
        var_a1 += 1;
        var_v1 += 0x14;
    } while (var_a1 < 2);
}
