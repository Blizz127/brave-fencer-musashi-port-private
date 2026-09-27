/* Main-exec range [80045190,80045280) from the SLUS executable.
 * SHA256(span)=77e526dc5a872043abece5e9e352f9dad763783516e64d981969950d3bf0eb77.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

extern s32 *D_8006CF4C;
extern s32 *D_8006CF58;
extern s32 *D_8006CF5C;
extern s32 *D_8006CF80;
extern s32 *D_8006CF84;
extern s32 *D_8006CF88;
extern s32 *D_8006CF8C;
extern s32 *D_8006CF90;

s32 func_80045190(s32 arg0, s32 arg1) {
    s32 sp0;

    *D_8006CF4C = 0;
    *D_8006CF58 = 0x80;
    *D_8006CF80 = 0x21020843;
    *D_8006CF5C = 0x1325;
    *D_8006CF84 |= 0x8000;
    *D_8006CF88 = arg0;
    *D_8006CF8C = arg1 | 0x10000;
    if (!(*D_8006CF4C & 0x40)) {
        do {

        } while (!(*D_8006CF4C & 0x40));
    }
    *D_8006CF90 = 0x11400100;
    sp0 = *D_8006CF90;
    return 0;
}
