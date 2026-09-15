/* Overlay range [8017AD0C,8017ADE8) from MAIN.CD member 0012.
 * SHA256(span)=45e2bcb084979fd87e6fe1b87bdb4221fffa70af65ab0a47a652930408f89567.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void func_80059A80(s16 *, s32, s32);                       /* extern */

void func_8017AD0C(s32 arg0) {
    s16 sp16;
    s16 sp14;
    s16 sp12;
    s16 sp10;
    s16 var_v0_2;
    s32 temp_s0;
    s32 var_v0;
    s32 var_v1;

    temp_s0 = arg0 - 1;
    sp10 = ((temp_s0 & 3) * 0x10) + 0x280;
    var_v0 = temp_s0;
    if (temp_s0 < 0) {
        var_v0 = temp_s0 + 3;
    }
    sp12 = (var_v0 >> 2) + 0x1F8;
    sp14 = 0x10;
    sp16 = 1;
    func_80059A80(&sp10, 0x160, 0x1C9);
    if (temp_s0 == 0x18) {
        sp10 = 0x2C0;
        var_v0_2 = 0x1D0;
    } else {
        sp10 = ((temp_s0 & 7) * 8) + 0x280;
        var_v1 = temp_s0 >> 3;
        if (temp_s0 < 0) {
            var_v1 = (s32) (temp_s0 + 7) >> 3;
        }
        var_v0_2 = (var_v1 * 0x28) + 0x180;
    }
    sp12 = var_v0_2;
    sp14 = 0x20;
    sp16 = 0x28;
    func_80059A80(&sp10, 0x1C8, 0x190);
}
