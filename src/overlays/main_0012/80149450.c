/* Overlay range [80149450,801494CC) from MAIN.CD member 0012.
 * SHA256(span)=1c18dd186e20628c2bdcd8cc5023a3b49bf38ce2c5122518d59c872047814648.
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

void func_80149450(void *arg0, void *arg1) {
    u16 sp1C;
    u16 sp1A;
    u16 sp18;
    u16 sp10;

    sp18 = arg1->unk2;
    sp1A = arg1->unk6;
    sp1C = arg1->unkA;
    func_8012F038(arg0->unk20 + 0x34, &sp18, &sp10);
    arg1->unk2 = sp10;
    arg1->unk6 = sp12;
    arg1->unkA = sp14;
}
