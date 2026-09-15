/* Overlay range [801494CC,80149544) from MAIN.CD member 0012.
 * SHA256(span)=ebe943cd289f70892de886918c5a0be347976fc7104f9817b81a42630f66867b.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void func_8012F038(s32, u16 *, u16 *);                 /* static */

void func_801494CC(void *arg0, void *arg1, void *arg2) {
    u16 sp1C;
    u16 sp1A;
    u16 sp18;
    u16 sp10;

    sp18 = arg1->unk2;
    sp1A = arg1->unk6;
    sp1C = arg1->unkA;
    func_8012F038(arg0->unk20 + 0x34, &sp18, &sp10);
    arg2->unk2 = sp10;
    arg2->unk6 = sp12;
    arg2->unkA = sp14;
}
