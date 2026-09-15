/* Exact retail word export for [8002EAB0,8002EB10); EXE and assembly verified. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void func_80038308(s16);                               /* static */
extern s16 D_800A4E86;
extern u16 D_800A4E8E;

void func_8002EAB0(void) {
    if (D_800A4E8E & 0x10) {
        func_80038308(D_800A4E86);
        D_800A4E8E = (D_800A4E8E | 9) & 0xFFEF;
    }
}
