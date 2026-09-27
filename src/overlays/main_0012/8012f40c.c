/* Overlay range [8012F40C,8012F49C) from MAIN.CD member 0012.
 * SHA256(span)=97b3c4ff071d2c74b0b56b067efac4a96692735a2c711ea7ad9a37810a1eb6e7.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void func_8004914C(void *);                               /* extern */
void func_800491AC(void *);                               /* extern */
void func_8004955C(s32, s32 *, void *, s32 *);              /* extern */
extern s32 *D_800AF648;

s32 *func_8012F40C(s32 *arg0, s32 arg1) {
    s32 sp18;
    s32 sp14;
    s32 sp10;

    sp10 = 0;
    func_8004914C(&D_800AF648);
    func_800491AC(&D_800AF648);
    func_8004955C(arg1, &sp10, &sp14, &sp18);
    if (sp18 < 0) {
        sp10 = 0;
        *arg0 = 0;
    } else {
        *arg0 = sp10;
    }
    return arg0;
}
