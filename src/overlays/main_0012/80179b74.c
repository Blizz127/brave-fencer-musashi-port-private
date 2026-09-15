/* Overlay range [80179B74,80179D30) from MAIN.CD member 0012.
 * SHA256(span)=f85d99d1e822c370c03d0f8707bcc0a65ac078258968b1a5ffb40efcd74daae0.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

extern s32 D_80184F40;
extern s32 D_80185344;

void func_80179B74(u16 *arg0) {
    u16 temp_a0;

    temp_a0 = *arg0;
    *(D_80184F40 + (D_80185344 * 2)) = temp_a0;
    D_80185344 = (s16) ((D_80185344 + 1) & 0x1FF);
    if ((u32) (s16) temp_a0 < 0x23U) {
        switch ((s16) temp_a0) {
        case 0:
            break;
        }
    }
}
