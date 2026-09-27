/* SC02 resident retail span [80131F28,80131F64). Offset 0x9DD0 at base 80128158.
 * SHA256(span)=b393dffb5227903f4dc17ae2e768d6e4ddd92afb9f5096c4fab2315331a776ad.
 * Words are the guest's loaded image (artifacts/sc02-resident-20260910).
 * Member-0012 C shape retargeted to this member: D_8017E8F0->D_801851E0.
 * Oracle MATCH re-earned against the resident image; Not MAIN10.
 */
#include "psx_types.h"

/* HAND MODEL of func_80131F28 (main_0012.s), decoded manually from raw
 * asm (fully visible; NOT verified against retail; C89-gated
 * only, promotion requires an oracle MATCH): indirect tail
 * dispatcher, 0x18 frame, s32 result. Calls the code pointer at
 * D_801851E0[(u16)arg0[1]] (lhu + sll-2 + lw) via jalr with a0 still
 * live (no a-reg writes precede it) and returns its . Table
 * contents unstaged; the s32(void*)-typed view matches the
 * func_80042580 callback precedent. */

struct h_80131F28 {
    u16 unk0;
    u16 unk2;
};

typedef s32 (*tgt_80131F28)(struct h_80131F28 *);

extern tgt_80131F28 D_801851E0[];

s32 func_80131F28(struct h_80131F28 *arg0) {
    return D_801851E0[arg0->unk2](arg0);
}
