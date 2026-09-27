/* Exact retail word export for [8005D538,8005D6A0); EXE and assembly verified. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void D_80072970();                                     /* static */
void func_8005E188(s32, s32, s32);                         /* static */

void func_8005D538(s32 arg1, s32 arg2) {
    func_8005E188(D_80072970(), arg1, arg2);
}
