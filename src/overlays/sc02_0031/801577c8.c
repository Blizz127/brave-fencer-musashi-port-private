/* SC02 resident retail span [801577C8,80157808). Offset 0x2F670 at base 80128158.
 * SHA256(span)=6e98b54ac27d50118019f68ba45442a4c1319f9363902e2bbceb0d91ef95ddb2.
 * Words are the guest's loaded image (artifacts/sc02-resident-20260910).
 * Member-0012 C shape retargeted to this member: D_80184280->D_801B6438.
 * Oracle MATCH re-earned against the resident image; Not MAIN10.
 */
#include "psx_types.h"
extern s32 D_801B6438;
void func_80147078();
void func_80157808();
void func_801577C8(void *p) {
    D_801B6438 = 300;
    func_80147078(p, 7);
    func_80157808(p);
}
