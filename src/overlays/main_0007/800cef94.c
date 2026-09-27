/* Overlay range [800CEF94,800CEFF8) from MAIN.CD member 0007.
 * SHA256(span)=b066f19dfab228a0522dba17b459673f258c79750a6decdb0e3628ff9858bf6c.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main_0007.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void func_800118AC();                                  /* extern */
s32 func_80014CAC(s32, s32);                            /* extern */
void func_800167B8();                                 /* extern */
extern u16 D_800B99E8;

void func_800CEF94(void) {
    u16 temp_v0;

    temp_v0 = D_800B99E8 + 1;
    D_800B99E8 = temp_v0;
    if (((s16) temp_v0 >= 0x81) || ((func_80014CAC(0, 0x800) << 0x10) != 0)) {
        func_800167B8(4);
        func_800118AC();
    }
}
