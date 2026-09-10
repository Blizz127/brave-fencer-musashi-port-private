/* SC02 resident retail span [80128C98,80128CFC). Offset 0xB40 at base 80128158.
 * SHA256(span)=ff4ece4b660a107931bcf4af13a15cd8d656a363d24f91e8389ce3ff00afbf36.
 * Words are the guest's loaded image (artifacts/sc02-resident-20260910).
 * Member-0012 C shape retargeted to this member: D_8017E630->D_80184F20; D_80182D1C->D_801B5128.
 * Oracle MATCH re-earned against the resident image; Not MAIN10.
 */
#include "psx_types.h"

/* HAND MODEL of func_80128C98 (main_0012.s), decoded manually from
 * raw asm (fully visible; NOT verified against retail; C89-gated
 * only, promotion requires an oracle MATCH): v = lh
 * D_80184F20[arg0] (s16 table, sll-1 index); when negative
 * returns 1, else returns func_8001ABBC(0, 0, &D_800AE830 +
 * (v << 3), D_801B5128, 0) (shift/add in bltz delay + addu;
 * zero stack slot in jal delay). */

extern s16 D_80184F20[];
extern u8 D_800AE830;
extern s32 func_8001ABBC(s32 arg0, s32 arg1, void *arg2, s32 arg3, void *arg4);
extern s32 D_801B5128;

s32 func_80128C98(s32 arg0) {
    s16 v;

    v = D_80184F20[arg0];
    if (v < 0) {
        return 1;
    }
    return func_8001ABBC(0, 0, &D_800AE830 + (v << 3), D_801B5128, 0);
}
