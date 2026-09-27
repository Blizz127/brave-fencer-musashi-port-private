/* Overlay range [80131CA8,80131CF4) from MAIN.CD member 0012.
 * SHA256(span)=78933c7d331de709f1fce0aabe0af38cbb8ace27b0ae6d8710b12532e7ea806b.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

s32 (*func_80131CF4(s32))(void *);              /* static */

s32 func_80131CA8(void *arg0) {
    s32 (*temp_v0)();

    temp_v0 = func_80131CF4(M2C_FIELD(arg0, s32 *, 0xBC));
    if (temp_v0 == 0) {
        return 0;
    }
    temp_v0(arg0);
    return 1;
}
