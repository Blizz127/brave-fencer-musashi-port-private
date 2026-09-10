/* SC02.CD FILE_031 / ov_SC02_031 retail span [80131F28,80131F64).
 * Offset 0x9DD0 at overlay base 80128158. SHA256(span)=fe04ef5cf5b3a5587d702a35a43cbf8781a29b912aea611fef13575fc1354934.
 * Differs from the registry-verified MAIN member 0012 carve in exactly one
 * data reference: D_8017E8F0 here is D_8017F178 (+0x888 member
 * data-block shift). Oracle MATCH re-earned on this file; Not MAIN10.
 */
#include "psx_types.h"

/* HAND MODEL of func_80131F28 (main_0012.s), decoded manually from raw
 * asm (fully visible; NOT verified against retail; C89-gated
 * only, promotion requires an oracle MATCH): indirect tail
 * dispatcher, 0x18 frame, s32 result. Calls the code pointer at
 * D_8017F178[(u16)arg0[1]] (lhu + sll-2 + lw) via jalr with a0 still
 * live (no a-reg writes precede it) and returns its . Table
 * contents unstaged; the s32(void*)-typed view matches the
 * func_80042580 callback precedent. */

struct h_80131F28 {
    u16 unk0;
    u16 unk2;
};

typedef s32 (*tgt_80131F28)(struct h_80131F28 *);

extern tgt_80131F28 D_8017F178[];

s32 func_80131F28(struct h_80131F28 *arg0) {
    return D_8017F178[arg0->unk2](arg0);
}
