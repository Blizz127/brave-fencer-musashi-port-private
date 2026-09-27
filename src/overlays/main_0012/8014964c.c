/* Overlay range [8014964C,801496D4) from MAIN.CD member 0012.
 * SHA256(span)=b65d062f6b02cf0e37095c862979b73fe375e750ae10b25db29fb84167937a47.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void func_8012EFB8(void *, u16 *);                        /* static */
void func_8012F14C(s32, u16 *, void *);                   /* static */

void func_8014964C(void *arg0, void *arg1) {
    s32 sp20;
    u16 sp18;
    u16 sp14;
    u16 sp12;
    u16 sp10;

    sp10 = arg1->unk2;
    sp12 = arg1->unk6;
    sp14 = arg1->unkA;
    func_8012F14C(arg0->unk20 + 0x34, &sp10, &sp20);
    func_8012EFB8(&sp20, &sp18);
    arg1->unk2 = sp18;
    arg1->unk6 = sp1A;
    arg1->unkA = sp1C;
}
