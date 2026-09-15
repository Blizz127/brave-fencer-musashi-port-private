/* Overlay range [8012E5CC,8012E688) from MAIN.CD member 0012.
 * SHA256(span)=d3d85af1d135e1f4116f6fe9dcb0c4208b91d3b16ffc217ceabf655bc5e3414c.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void func_8002D4C8(s32, s32);                          /* extern */
void func_8004914C(void *);                               /* extern */
void func_800491AC(void *);                               /* extern */
void func_8004955C(s32, u16 *, void *, s32 *);            /* extern */
extern s32 *D_800AF648;

void func_8012E5CC(s32 arg0, s32 arg1, s32 arg2) {
    s32 sp18;
    s32 sp14;
    u16 sp10;

    func_8004914C(&D_800AF648);
    func_800491AC(&D_800AF648);
    func_8004955C(arg0, &sp10, &sp14, &sp18);
    if ((sp18 >= 0) && ((u32) ((sp10 + 0xC7) & 0xFFFF) < 0x18FU) && ((u32) ((sp12 + 0xA9) & 0xFFFF) < 0x153U)) {
        func_8002D4C8(arg1 & 0xFFFF, arg2 & 0xFFFF);
    }
}
