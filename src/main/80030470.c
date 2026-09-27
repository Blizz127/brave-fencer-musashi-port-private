/* Main-exec range [80030470,800304C8) from the SLUS executable.
 * SHA256(span)=cf74af99fc0dc1c651c267e014d5ea880013087db30eecc0cba1b049913bcaf0.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

extern s32 func_800301A4;
s32 func_80037CD8(s32 (*)());                         /* static */
extern u8 D_8006AEF4;
extern u16 D_800A46CC;

s32 func_80030470(void) {
    if (func_80037CD8(func_800301A4) != 0) {
        D_800A46CC += 1;
        D_8006AEF4 |= 2;
    }
    return 0;
}
