/* Exact retail word export for [80037D98,80037EA0); EXE-verified. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

extern s32 D_80073140;
void func_8003D424(void *, s32 (*)());                      /* static */
extern void *D_800762B0;
extern s32 *D_80079A68;
extern s32 *D_800A4EFE;
extern s32 *D_800B9EC8;
extern s32 *D_800B9ED2;
extern s32 *D_800B9ED3;
extern s32 *D_800C6DE0;
extern s32 *D_800C6DE4;
extern s32 *D_800C6DEC;
extern s32 *D_800C6DEE;
extern s32 *D_800C6E2A;
extern s32 *D_800C6E2B;
extern s32 *D_800C6E2C;
extern s32 *D_800C6E2D;
extern s32 *D_800C6E2E;

void func_80037D98(void) {
    s32 (*var_a1)();
    s16 var_a0_2;
    s32 temp_v0;
    s32 var_a0;
    s32 var_v1;
    s32 var_v1_2;

    var_a0 = 0;
    var_a1 = D_80073140;
    var_v1 = 0;
    D_800762B0 = &D_800A4EFE;
    do {
        temp_v0 = *var_a1;
        var_a1 += 4;
        var_a0 += 1;
        *(&D_800C6E2A + var_v1) = 0;
        *(&D_800C6E2B + var_v1) = 0;
        *(&D_800C6E2C + var_v1) = 0;
        *(&D_800C6E2D + var_v1) = 0;
        *(&D_800C6DEC + var_v1) = 0;
        *(&D_800C6DEE + var_v1) = 0;
        *(&D_800C6DE4 + var_v1) = 0;
        *(&D_800C6E2E + var_v1) = 0;
        *(&D_800C6DE0 + var_v1) = temp_v0;
        var_v1 += 0x60;
    } while (var_a0 < 0x10);
    var_a0_2 = 0;
    var_v1_2 = 0;
    do {
        *(&D_800B9ED3 + var_v1_2) = 0;
        *(&D_800B9ED2 + var_v1_2) = 0;
        *(&D_800B9EC8 + var_v1_2) = var_a0_2;
        var_a0_2 += 1;
        var_v1_2 += 0x1FC;
    } while (var_a0_2 < 2);
    func_8003D424(&D_80079A68, var_a1);
}
