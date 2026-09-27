/* SC02 resident retail span [80178438,8017849C). Offset 0x502E0 at base 80128158.
 * SHA256(span)=84ecd3ea71493ae940ebcc68c4f1a03c1b0dbbdc921d737d952ea4404f2d03fb.
 * Words are the guest's loaded image (artifacts/sc02-resident-20260910).
 * Member-0012 C shape retargeted to this member: D_80183B94->D_801B5FA0.
 * Oracle MATCH re-earned against the resident image; Not MAIN10.
 */
#include "psx_types.h"
extern s32 D_801B5FA0;
void func_8001534C();
void func_800153CC();
void func_80178438(u16 *p) {
    func_8001534C(2, &D_801B5FA0, 0x80, 0x88, 0, 0);
    func_800153CC(3, p[0], 0xA8, 0x88, 0x40, 0);
}
