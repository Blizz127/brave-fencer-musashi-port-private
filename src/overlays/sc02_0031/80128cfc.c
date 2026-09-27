/* SC02 resident retail span [80128CFC,80128D60). Offset 0xBA4 at base 80128158.
 * SHA256(span)=8a5b054c63fefe682e5477020e9242fedf682c22f4c1a71f261810fa155b1773.
 * Words are the guest's loaded image (artifacts/sc02-resident-20260910).
 * Member-0012 C shape retargeted to this member: D_8017E640->D_80184F30; D_80182D1C->D_801B5128.
 * Oracle MATCH re-earned against the resident image; Not MAIN10.
 */
#include "psx_types.h"

/* HAND MODEL of func_80128CFC (main_0012.s), decoded manually from
 * raw asm (fully visible; NOT verified against retail; C89-gated
 * only, promotion requires an oracle MATCH): func_80128C98
 * sibling keyed on s16 table D_80184F30: negative returns 1,
 * else returns func_8001ABBC(0, 0, &D_800AE830 + (v << 3),
 * D_801B5128, 0). */

extern s16 D_80184F30[];
extern u8 D_800AE830;
extern s32 func_8001ABBC(s32 arg0, s32 arg1, void *arg2, s32 arg3, void *arg4);
extern s32 D_801B5128;

s32 func_80128CFC(s32 arg0) {
    s16 v;

    v = D_80184F30[arg0];
    if (v < 0) {
        return 1;
    }
    return func_8001ABBC(0, 0, &D_800AE830 + (v << 3), D_801B5128, 0);
}
