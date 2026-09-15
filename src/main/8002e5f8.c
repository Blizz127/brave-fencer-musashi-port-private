/* Exact retail word export for [8002E5F8,8002E638); EXE and assembly verified. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void func_80043974(s8 *);                              /* static */
extern s8 D_800A4F19;

void func_8002E5F8(void) {
    s8 sp13;
    s8 sp12;
    s8 sp11;
    s8 sp10;

    sp10 = 0x80;
    sp11 = 0;
    sp12 = 0x80;
    sp13 = 0;
    func_80043974(&sp10);
    D_800A4F19 = 1;
}
