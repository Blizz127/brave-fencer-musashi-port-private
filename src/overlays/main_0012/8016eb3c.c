/* Overlay range [8016EB3C,8016EBA8) from MAIN.CD member 0012.
 * SHA256(span)=305a0f4482d5bcf13308fc9b81d55a98526ef4e42abcae5715b6972ac282560d.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

extern s32 D_80181730;
void func_8016EC0C(u8);                                /* static */

void func_8016EB3C(void *arg0) {
    u8 temp_v1;

    func_8016EC0C(*(D_80181730 + (arg0->unk2 & 3)));
    temp_v1 = arg0->unk2;
    arg0->unk2 = (u8) (temp_v1 + 0xFF);
    if (temp_v1 == 0) {
        arg0->unk2 = 5U;
        arg0->unk1 = (u8) (arg0->unk1 + 1);
    }
}
