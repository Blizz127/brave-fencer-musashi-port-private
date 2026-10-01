/* Main-exec range [8003A098,8003A0D0) from the SLUS executable.
 * SHA256(span)=0b8ef50584290b9d27fb04342a75c3848adf2668fe679ee86eb0d7558276c435.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
#include "psx_types.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void func_8003A098(u8 **arg0, s16 arg1) {
    u8 *temp_v1;

    temp_v1 = *arg0;
    *arg0 = temp_v1 + 1;
    arg0 = (u8 **) ((u8 *) arg0 + (arg1 * 0x1A));
    (*(u8 *) ((s8 *) (arg0) + (0x1A))) = (u8) *temp_v1;
}
