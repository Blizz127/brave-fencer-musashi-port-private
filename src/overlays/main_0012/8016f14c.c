/* Overlay range [8016F14C,8016F1AC) from MAIN.CD member 0012.
 * SHA256(span)=8a876cbf4d0099edacc4abdecaf9b07db5880e08c345237e2b3bf09d9628ddb2.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void func_80148634();                            /* static */

void func_8016F14C(void *arg0) {
    s32 temp_v1;

    temp_v1 = M2C_FIELD(arg0, s32 *, 0x1F8);
    if (temp_v1 != 0) {
        if (temp_v1 & 0x01000000) {
            func_80148634();
        }
        ((s32 (*)()) (temp_v1 & 0x80FFFFFF))(arg0);
    }
}
