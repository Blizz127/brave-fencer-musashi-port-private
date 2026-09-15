/* Exact retail word export for [8002823C,80028304); EXE and assembly verified. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void func_80028620(s32, void *);                          /* static */
extern s32 *D_800A5E88;
extern s32 *D_800A5E8C;
extern s32 *D_800A5E90;
extern s32 *D_800A5E94;
extern s32 *D_800A5E95;
extern s32 *D_800A5E96;

void func_8002823C(void) {
    void *var_s2;
    s32 var_s0;
    s32 var_s1;

    var_s1 = 0;
    var_s2 = &D_800A5E88;
    var_s0 = 0;
    do {
        *(&D_800A5E88 + var_s0) = 0x800;
        *(&D_800A5E8C + var_s0) = 0x800;
        *(&D_800A5E90 + var_s0) = 0;
        *(&D_800A5E94 + var_s0) = 0x20;
        *(&D_800A5E95 + var_s0) = 0x20;
        *(&D_800A5E96 + var_s0) = 0x20;
        func_80028620(var_s1, var_s2);
        var_s2 += 0x10;
        var_s1 += 1;
        var_s0 += 0x10;
    } while (var_s1 < 3);
}
