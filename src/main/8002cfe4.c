/* Exact retail word export for [8002CFE4,8002D034); EXE and assembly verified. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void func_8002D320();                                  /* static */
void func_80030F80(s16 *);                             /* static */
void func_80031BE0();                                  /* static */
extern s16 D_800A4EFC;

void func_8002CFE4(void) {
    if (D_800A4EFC != 0) {
        D_800A4EFC -= 1;
    }
    func_80030F80(&D_800A4EFC);
    func_8002D320();
    func_80031BE0();
}
