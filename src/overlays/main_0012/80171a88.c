/* Overlay range [80171A88,80171AB0) from MAIN.CD member 0012.
 * SHA256(span)=f9f2255593ce67e8bb6032262515fd13b110b862e30b976d0a0569d57e59f9d1.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

s32 func_80171A88(void *arg0) {
    s32 temp_v0;
    s32 temp_v0_2;

    temp_v0_2 = M2C_FIELD(arg0, s32 *, 0x200);
    temp_v0 = temp_v0_2 - 1;
    if (temp_v0_2 == 0) {
        return 1;
    }
    M2C_FIELD(arg0, s32 *, 0x200) = temp_v0;
    return temp_v0 == 0;
}
