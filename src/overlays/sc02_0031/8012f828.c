/* SC02 resident retail span [8012F828,8012F87C). Offset 0x76D0 at base 80128158.
 * SHA256(span)=d25b6e9a02ea772dfad8faf61b1477a0c53a6de1a677d1e7abccbe8bb1347085.
 * Words are the guest's loaded image (artifacts/sc02-resident-20260910).
 * Member-0012 C shape retargeted to this member: D_8017E6F0->D_80184FE0.
 * Oracle MATCH re-earned against the resident image; Not MAIN10.
 */
#include "psx_types.h"

/* HAND MODEL of func_8012F828 (main_0012.s), decoded manually from
 * raw asm (NOT verified against retail; C89-gated only,
 * promotion requires an oracle MATCH): unconditionally sets byte
 * unkC1 = 4 (sb in the beqz delay slot); when word unkB4 & 8
 * calls 80131170(obj, &D_80184FE0, 0xB) (a0 still holds obj at
 * the jal: pass-through first arg, m2c showed two); ends with
 * 31CA8(obj, 9). */

struct obj_8012F828 {
    u8 pad[0xB4];
    s32 unkB4;
    u8 pad2[0xC1 - 0xB8];
    u8 unkC1;
};

extern u8 D_80184FE0;
extern void func_80131170(void *arg0, void *arg1, s32 arg2);
extern void func_80131CA8(void *arg0, s32 arg1);

void func_8012F828(struct obj_8012F828 *arg0) {
    arg0->unkC1 = 4;
    if (arg0->unkB4 & 8) {
        func_80131170(arg0, &D_80184FE0, 0xB);
    }
    func_80131CA8(arg0, 9);
}
