/* SC02 resident retail span [8012F8C8,8012F91C). Offset 0x7770 at base 80128158.
 * SHA256(span)=23b035b8c5b9814bfa3e34acd228edfd76e3ca5443a4ce3d957e85dcac21977e.
 * Words are the guest's loaded image (artifacts/sc02-resident-20260910).
 * Member-0012 C shape retargeted to this member: D_8017E6FC->D_80184FEC.
 * Oracle MATCH re-earned against the resident image; Not MAIN10.
 */
#include "psx_types.h"

/* HAND MODEL of func_8012F8C8 (main_0012.s), decoded manually from
 * raw asm (NOT verified against retail; C89-gated only,
 * promotion requires an oracle MATCH): F828-sibling:
 * unconditionally sets byte unkC1 = 7 (sb in the beqz delay
 * slot); when word unkB4 & 0x80 calls 80131170(obj,
 * &D_80184FEC, 0xB) (pass-through a0); ends with 31CA8(obj,
 * 0x16). */

struct obj_8012F8C8 {
    u8 pad[0xB4];
    s32 unkB4;
    u8 pad2[0xC1 - 0xB8];
    u8 unkC1;
};

extern u8 D_80184FEC;
extern void func_80131170(void *arg0, void *arg1, s32 arg2);
extern void func_80131CA8(void *arg0, s32 arg1);

void func_8012F8C8(struct obj_8012F8C8 *arg0) {
    arg0->unkC1 = 7;
    if (arg0->unkB4 & 0x80) {
        func_80131170(arg0, &D_80184FEC, 0xB);
    }
    func_80131CA8(arg0, 0x16);
}
