/* Exact retail word export [8002F5C8,8002F620); verified against pinned EXE and asm. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void func_8002F620();                                  /* static */
extern u16 *D_800A4EE8;
extern s16 D_800A4EF0;

void func_8002F5C8(u16 *arg0) {
    if (D_800A4EF0 != 0) {
        func_8002F620();
    }
    D_800A4EE8 = arg0;
    D_800A4EF0 = (s16) *arg0;
}
