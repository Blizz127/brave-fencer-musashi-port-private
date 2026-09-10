/* SC02 resident retail span [80157788,801577C8). Offset 0x2F630 at base 80128158.
 * SHA256(span)=0d5f31685d9854a949955beca0a503893cf73d66db07ee0331365eaa977dff4c.
 * Words are the guest's loaded image (artifacts/sc02-resident-20260910).
 * Member-0012 C shape retargeted to this member: D_80184280->D_801B6438.
 * Oracle MATCH re-earned against the resident image; Not MAIN10.
 */
#include "psx_types.h"
extern s32 D_801B6438;
void func_80147078();
void func_801578C0();
void func_80157788(void *p) {
    D_801B6438 = 300;
    func_80147078(p, 7);
    func_801578C0(p);
}
