/* Overlay range [80149B14,80149B54) from MAIN.CD member 0012.
 * SHA256(span)=f697007e8398a70312243e508bc353ecdc26b858cbe75e1c204f15d27ae2075a.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void func_8015554C();                            /* static */
void func_8015DAC4();                            /* static */

void func_80149B14(void *arg0) {
    if (M2C_FIELD(arg0, s32 *, 0x178) != 0) {
        func_8015DAC4();
        return;
    }
    func_8015554C();
}
