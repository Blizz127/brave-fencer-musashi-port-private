/* Overlay range [801626B8,80162714) from MAIN.CD member 0012.
 * SHA256(span)=09dafa4dffe1f0ebba35cd3ec4dcaf5052ccd290b3c0dea02ae4e38881c5b0e4.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

s32 func_800291DC();                               /* extern */
s16 func_800D0E30(s16 *);                           /* extern */

s16 func_801626B8(void) {
    s16 sp10;

    sp10 = func_800291DC(0x12) & 0x7FFF;
    sp10 = func_800D0E30(&sp10);
    return (s16) ((unksp11 * 0x64) + (u8) sp10);
}
