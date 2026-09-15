/* Overlay range [80150B28,80150B9C) from MAIN.CD member 0012.
 * SHA256(span)=4cac5a2b426da23c617530203eb52104ff2165e0845ea1968fc18bbe52f43569.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

extern s32 D_8017FFFC;
extern s32 D_800AE6B0;

void func_80150B28(void *arg0) {
    u16 temp_v1;

    if (!(D_800AE6B0 & 0x80FFFFFF)) {
        temp_v1 = arg0->unk16C;
        if ((temp_v1 != 0) && (temp_v1 < 0x26U)) {
            *(D_8017FFFC + ((temp_v1 - 1) * 4))();
        }
    }
    arg0->unk16C = 0U;
}
