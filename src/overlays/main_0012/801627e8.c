/* Overlay range [801627E8,80162834) from MAIN.CD member 0012.
 * SHA256(span)=be0b217f2a1dcf2b1f0f3974387efba02ae46fefe18583bd0af528795f49133f.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

extern s32 D_80180F24;
extern u8 D_8011F750;

void func_801627E8(void) {
    if (D_8011F750 != 0) {
        *(D_80180F24 + ((D_8011F750 - 1) * 4))(&D_8011F750);
    }
}
