/* SC02.CD FILE_031 / ov_SC02_031 retail span [80128C98,80128CFC).
 * Offset 0xB40 at overlay base 80128158. SHA256(span)=6f2b35d67f906de49c6aca1cfa2a6f292a6057d0853a38398308ddc7b88e6571.
 * Same shape as the registry-verified MAIN member 0012 carve with only the
 * listed data references retargeted for this member: D_8017E630->D_8017EEB8; D_80182D1C->D_801A3234.
 * Oracle MATCH re-earned on this file; Not MAIN10.
 */
#include "psx_types.h"

/* HAND MODEL of func_80128C98 (main_0012.s), decoded manually from
 * raw asm (fully visible; NOT verified against retail; C89-gated
 * only, promotion requires an oracle MATCH): v = lh
 * D_8017EEB8[arg0] (s16 table, sll-1 index); when negative
 * returns 1, else returns func_8001ABBC(0, 0, &D_800AE830 +
 * (v << 3), D_801A3234, 0) (shift/add in bltz delay + addu;
 * zero stack slot in jal delay). */

extern s16 D_8017EEB8[];
extern u8 D_800AE830;
extern s32 func_8001ABBC(s32 arg0, s32 arg1, void *arg2, s32 arg3, void *arg4);
extern s32 D_801A3234;

s32 func_80128C98(s32 arg0) {
    s16 v;

    v = D_8017EEB8[arg0];
    if (v < 0) {
        return 1;
    }
    return func_8001ABBC(0, 0, &D_800AE830 + (v << 3), D_801A3234, 0);
}
