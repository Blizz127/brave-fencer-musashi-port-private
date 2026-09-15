/* Overlay range [801588CC,80158AB4) from MAIN.CD member 0012.
 * SHA256(span)=fa82cbd335aace6d4a6cbd8b77eb972dc7dbd0da30c44805c9cf1d78ebe7f545.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

extern s32 D_80180720;
extern s32 D_80184288;

void func_801588CC(void *arg0) {
    *(D_80180720 + (arg0->unk2 * 4))();
    if ((u32) D_80184288 < 9U) {
        switch (D_80184288) {
        case 0:
            break;
        }
    }
}
