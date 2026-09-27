/* SC02 resident retail span [8017553C,80175590). Offset 0x4D3E4 at base 80128158.
 * SHA256(span)=f526f56f6281405f218d0fc0b11d372b8a497f4ca2e732dc58f8a7c0214f4171.
 * Words are the guest's loaded image (artifacts/sc02-resident-20260910).
 * Member-0012 C shape retargeted to this member: D_80181B78->D_80188468.
 * Oracle MATCH re-earned against the resident image; Not MAIN10.
 */
#include "psx_types.h"
typedef void (*CB)();
extern CB D_80188468[];
void func_801758FC();
void func_80175820();
void func_801759D8();
void func_8017553C(u8 *p) {
    D_80188468[p[1]]();
    func_801758FC();
    func_80175820();
    func_801759D8();
}
