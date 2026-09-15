/* Overlay range [80149AD4,80149B14) from MAIN.CD member 0012.
 * SHA256(span)=51a616ec0da4f828b3506a2053bd464f2270231ca986b00d2ed255f8c78849e4.
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

void func_80149AD4(void *arg0) {
    if (M2C_FIELD(arg0, s32 *, 0x178) != 0) {
        func_8015DAC4();
        return;
    }
    M2C_FIELD(arg0, s8 *, 0x1AA) = 1;
    func_8015554C();
}
