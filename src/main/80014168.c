/* Main-exec range [80014168,800141AC) from the SLUS executable.
 * SHA256(span)=e057702a93e921a02421e5ec73b0279ffe91b95496c440c5d8ca7d111918d253.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void func_80048FBC(void *, void *);           /* static */

void func_80014168(void *arg1) {
    s32 sp17;
    s32 sp13;
    s32 sp10;
    sp13 = M2C_UNALIGNED32(M2C_ERROR(/* Unable to handle lwr; missing a corresponding lwl */));
    sp17 = M2C_UNALIGNED32(M2C_ERROR(/* Unable to handle lwr; missing a corresponding lwl */));
    func_80048FBC(&sp10, arg1);
}
