/* Overlay range [80165718,80165770) from MAIN.CD member 0012.
 * SHA256(span)=09763157ecfa85525712bfc7092447e9a3b82ce0e18560ef96a8e5e9efa94be3.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void func_80165A20();                                  /* static */
extern u8 D_80078EC1;

void func_80165718(void) {
    if (D_80078EC1 != 0xC) {
        if ((s32) D_80078EC1 < 0xD) {
            if (D_80078EC1 != 3) {
                return;
            }
            goto block_5;
        }
        if (D_80078EC1 == 0x18) {
            goto block_5;
        }
    } else {
block_5:
        func_80165A20();
    }
}
