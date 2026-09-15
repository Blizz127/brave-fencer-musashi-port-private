/* Overlay range [80150170,801502EC) from MAIN.CD member 0012.
 * SHA256(span)=fb90263505f5f73487d74e494a88c89bec1b939f405d95891c9a2ad98fb09506.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

s32 func_801502EC(u16 *, void *);                      /* static */
s32 func_80150460(void *, u16 *);                   /* static */

s32 func_80150170(void *arg0) {
    s32 sp20;
    u16 sp1C;
    s16 sp1A;
    u16 sp18;
    u16 sp14;
    s16 sp12;
    u16 sp10;
    s16 temp_v0_2;
    s32 temp_s1;
    s32 temp_v0_4;
    s32 var_v0;
    u16 temp_v0;
    u16 temp_v0_3;

    temp_v0 = arg0->unk6;
    sp18 = temp_v0;
    sp10 = temp_v0;
    temp_v0_2 = arg0->unkA - 0x10;
    sp1A = temp_v0_2;
    sp12 = temp_v0_2;
    temp_v0_3 = arg0->unkE;
    sp1C = temp_v0_3;
    sp14 = temp_v0_3;
    temp_s1 = func_801502EC(&sp10, &sp20);
    temp_v0_4 = func_80150460(arg0, &sp18);
    var_v0 = temp_s1 | temp_v0_4;
    if (temp_v0_4 == 0) {
        sp1A = 0x7FFF;
        var_v0 = temp_s1 | temp_v0_4;
    }
    if (var_v0 != 0) {
        if (sp12 < sp1A) {
            arg0->unk78 = sp10;
            arg0->unk7A = (u16) sp12;
            arg0->unk7C = sp14;
            arg0->unk83 = (unaligned s32) M2C_ERROR(/* Unable to handle lwr; missing a corresponding lwl */);
            arg0->unk87 = (unaligned s32) M2C_ERROR(/* Unable to handle lwr; missing a corresponding lwl */);
        } else {
            arg0->unk78 = sp18;
            arg0->unk7A = (u16) sp1A;
            arg0->unk7C = sp1C;
            arg0->unk83 = (unaligned s32) M2C_ERROR(/* Unable to handle lwr; missing a corresponding lwl */);
            arg0->unk87 = (unaligned s32) M2C_ERROR(/* Unable to handle lwr; missing a corresponding lwl */);
        }
        arg0->unk7E = (u16) (arg0->unk7E & 0xFFFE);
        return 1;
    }
    arg0->unk7A = 0x7FFFU;
    arg0->unk78 = sp10;
    arg0->unk7E = (u16) (arg0->unk7E | 1);
    arg0->unk7C = sp14;
    return 0;
}
