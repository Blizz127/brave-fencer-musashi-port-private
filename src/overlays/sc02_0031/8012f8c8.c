/* SC02.CD FILE_031 / ov_SC02_031 retail span [8012F8C8,8012F91C).
 * Offset 0x7770 at overlay base 80128158. SHA256(span)=fa5059e98900c616ff2a0f8189e23e26622f064202398292f8b3f2469839372a.
 * Differs from the registry-verified MAIN member 0012 carve in exactly one
 * data reference: D_8017E6FC here is D_8017EF84 (+0x888 member
 * data-block shift). Oracle MATCH re-earned on this file; Not MAIN10.
 */
#include "psx_types.h"

/* HAND MODEL of func_8012F8C8 (main_0012.s), decoded manually from
 * raw asm (NOT verified against retail; C89-gated only,
 * promotion requires an oracle MATCH): F828-sibling:
 * unconditionally sets byte unkC1 = 7 (sb in the beqz delay
 * slot); when word unkB4 & 0x80 calls 80131170(obj,
 * &D_8017EF84, 0xB) (pass-through a0); ends with 31CA8(obj,
 * 0x16). */

struct obj_8012F8C8 {
    u8 pad[0xB4];
    s32 unkB4;
    u8 pad2[0xC1 - 0xB8];
    u8 unkC1;
};

extern u8 D_8017EF84;
extern void func_80131170(void *arg0, void *arg1, s32 arg2);
extern void func_80131CA8(void *arg0, s32 arg1);

void func_8012F8C8(struct obj_8012F8C8 *arg0) {
    arg0->unkC1 = 7;
    if (arg0->unkB4 & 0x80) {
        func_80131170(arg0, &D_8017EF84, 0xB);
    }
    func_80131CA8(arg0, 0x16);
}
