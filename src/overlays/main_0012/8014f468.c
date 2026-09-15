/* Overlay range [8014F468,8014F4C0) from MAIN.CD member 0012.
 * SHA256(span)=42bbc18959d1281a42df172a3d4ef74f66f79652e7518a9f44280dc577720fe3.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

extern s32 D_8018424C;
s32 func_8014F4C0();                                /* static */

s32 func_8014F468(void) {
    **(void ***)0x1F8003FC = sp;
    D_8018424C = func_8014F4C0();
    return D_8018424C;
}
