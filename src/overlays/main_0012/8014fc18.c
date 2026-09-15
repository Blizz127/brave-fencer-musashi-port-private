/* Overlay range [8014FC18,8014FCFC) from MAIN.CD member 0012.
 * SHA256(span)=579ef747b61bb1ebb0cc3a76466bf8615e605a469d8a20fa0f87b24d1cc5b0a8.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

s32 func_80133784(s32, u16 *, u16 *);                 /* static */

s32 func_8014FC18(void *arg0) {
    u16 sp1C;
    u16 sp1A;
    u16 sp18;
    u16 sp14;
    u16 sp12;
    u16 sp10;
    s32 temp_v0;

    sp10 = arg0->unk6;
    sp12 = arg0->unkA;
    sp14 = arg0->unkE;
    sp18 = arg0->unk6;
    sp1A = arg0->unkA + 0x10;
    sp1C = arg0->unkE;
    temp_v0 = func_80133784(1, &sp10, &sp18);
    if (temp_v0 != 0) {
        arg0->unk6 = sp18;
        arg0->unkA = sp1A;
        arg0->unkE = sp1C;
        if (sp1E != 0) {
            arg0->unk16C = (s16) sp1E;
        }
        arg0->unk16E = (s16) ((u16) sp1E >> 0xD);
        return temp_v0;
    }
    if (sp1E != 0) {
        arg0->unk16C = (s16) sp1E;
    }
    return 0;
}
