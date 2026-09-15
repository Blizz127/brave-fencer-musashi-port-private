/* Main-exec range [800119F0,80011A3C) from the SLUS executable.
 * SHA256(span)=59660aa77f9820985edd32db12863f8a3376c2e0778ef4c071427ecb04762594.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

extern s32 *D_800AF630;

void func_800119F0(u16 arg0) {
    u16 sp0;

    sp0 = arg0;
    M2C_FIELD(&D_800AF630, u16 *, 0xA3BA) = sp0;
    M2C_FIELD(&D_800AF630, s16 *, 0xA3BC) = 0;
}
