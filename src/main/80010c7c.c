/* Exact retail word export for [80010C7C,80010CEC); EXE and assembly verified. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

extern s32 D_80072C70;
void func_80010AE0();                                 /* static */
void func_80011778();                                  /* static */
s32 func_80019A24(void *, s32, s32, s32);                  /* static */
extern s32 *D_800AE838;

void func_80010C7C(void) {
    s32 sp10;
    s32 temp_v0;

    temp_v0 = func_80019A24(&D_800AE838, D_80072C70, 0, 0);
    sp10 = temp_v0;
    if (temp_v0 != 0) {
        func_80010AE0(0x3E0);
        func_80011778();
    }
}
