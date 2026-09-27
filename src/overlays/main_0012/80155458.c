/* Overlay range [80155458,801554B8) from MAIN.CD member 0012.
 * SHA256(span)=9e1c51789b156a0cfab4e692cacc499f23d15153ec067c8564d39609062c5f7a.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

extern s32 D_801801EC;

u8 func_80155458(void *arg0) {
    u8 temp_v0;

    temp_v0 = arg0->unk4E;
    if ((temp_v0 != 0) && (*(D_801801EC + ((temp_v0 - 1) * 4))() == 0)) {
        arg0->unk4E = 0U;
    }
    return arg0->unk4E;
}
