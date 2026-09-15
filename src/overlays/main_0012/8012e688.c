/* Overlay range [8012E688,8012E778) from MAIN.CD member 0012.
 * SHA256(span)=0d04ff05ed490a2f5c165c10a7ab123f76ed1b355b6dde8fe4bb2605eb7833af.
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
void func_8004955C(s16 *, u16 *, void *, s32 *);          /* extern */
extern s32 *D_800AF648;

void func_8012E688(void *arg0, s32 arg1, s32 arg2) {
    s32 sp20;
    s32 sp1C;
    u16 sp18;
    s16 sp14;
    s16 sp12;
    s16 sp10;
    void *temp_v0;

    temp_v0 = arg0->unk20;
    if ((temp_v0 == 0) || ((sp10 = (s16) temp_v0->unk48, sp12 = (s16) arg0->unk20->unk4C, sp14 = (s16) arg0->unk20->unk50, func_8004914C(&D_800AF648), func_800491AC(&D_800AF648), func_8004955C(&sp10, &sp18, &sp1C, &sp20), (sp20 >= 0)) && ((u32) ((sp18 + 0xC7) & 0xFFFF) < 0x18FU) && ((u32) ((sp1A + 0xA9) & 0xFFFF) < 0x153U))) {
        func_8002D4C8(arg1 & 0xFFFF, arg2 & 0xFFFF);
    }
}
