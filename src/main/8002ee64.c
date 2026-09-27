/* Exact retail word export for [8002EE64,8002EE90); EXE and assembly verified. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void func_8002EC10();                                  /* static */
void func_80036EB4(s32);                               /* static */

void func_8002EE64(void) {
    func_80036EB4(0x88);
    func_8002EC10();
}
