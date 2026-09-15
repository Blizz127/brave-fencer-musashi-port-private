/* Exact retail word export for [80010A08,80010A84); EXE and assembly verified. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void func_80010A84(s32);                               /* static */
extern s32 D_800A5E60;

void func_80010A08(s32 arg0) {
    s32 sp4;
    s32 sp0;
    s32 temp_a0;
    s32 temp_v0;

    sp4 = (s32) (arg0 + 3) / 4;
    temp_v0 = D_800A5E60;
    sp0 = temp_v0;
    temp_a0 = D_800A5E60;
    D_800A5E60 = temp_a0 + (sp4 * 4);
    func_80010A84(temp_a0);
}
