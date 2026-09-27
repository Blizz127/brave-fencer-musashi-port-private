/* SC02 resident retail span [8016B9F8,8016BA48). Offset 0x438A0 at base 80128158.
 * SHA256(span)=9956e3a9812ad61867be8f27c9572f3c9b19c1b0deddc40860aece117de715ea.
 * Words are the guest's loaded image (artifacts/sc02-resident-20260910).
 * Member-0012 C shape retargeted to this member: D_801846B8->D_801B6870.
 * Oracle MATCH re-earned against the resident image; Not MAIN10.
 */
#include "psx_types.h"
extern s32 D_801B6870;
s32 func_8012EFB8();
void func_80015954();
s32 func_8016B9F8(u8 *p) {
    s16 tmp[4];
    s32 v = func_8012EFB8(&D_801B6870, tmp);
    func_80015954(tmp, p + 4);
    return (v & ~0x1000) != 0;
}
