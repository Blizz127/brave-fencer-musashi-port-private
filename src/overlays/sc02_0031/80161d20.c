/* SC02 resident retail span [80161D20,80161D58). Offset 0x39BC8 at base 80128158.
 * SHA256(span)=78e6a7bbf86ab545987e529a99515bc86c562fbd6491ee398b978319d025c3bd.
 * Words are the guest's loaded image (artifacts/sc02-resident-20260910).
 * Member-0012 C shape retargeted to this member: D_80180E78->D_80187768.
 * Oracle MATCH re-earned against the resident image; Not MAIN10.
 */
#include "psx_types.h"
void func_80147324();
extern u16 D_80187768[];
void func_80161D20(s32 a0, u32 a1) {
    if (a1 < 8) {
        func_80147324(D_80187768[a1]);
    }
}
