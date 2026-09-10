/* SC02.CD FILE_031 / ov_SC02_031 retail span [80178438,8017849C).
 * Offset 0x502E0 at overlay base 80128158. SHA256(span)=ca95c6e9199c54cd0f524f597e9cef726f3272b40483b524f965b39616397202.
 * Same shape as the registry-verified MAIN member 0012 carve with only the
 * listed data references retargeted for this member: D_80183B94->D_801A40AC.
 * Oracle MATCH re-earned on this file; Not MAIN10.
 */
#include "psx_types.h"
extern s32 D_801A40AC;
void func_8001534C();
void func_800153CC();
void func_80178438(u16 *p) {
    func_8001534C(2, &D_801A40AC, 0x80, 0x88, 0, 0);
    func_800153CC(3, p[0], 0xA8, 0x88, 0x40, 0);
}
