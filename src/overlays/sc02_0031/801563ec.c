/* SC02 resident retail span [801563EC,8015640C). Offset 0x2E294 at base 80128158.
 * SHA256(span)=f7ffa480f6af6728d00a75b07040784866462f426b17556d44d88ba9ea4454ad.
 * Words are the guest's loaded image (artifacts/sc02-resident-20260910).
 * Member-0012 C shape retargeted to this member: D_801803E4->D_80186CD4.
 * Oracle MATCH re-earned against the resident image; Not MAIN10.
 */
#include "psx_types.h"
extern u8 D_80186CD4[];
void *func_801563EC(u16 a0) {
    return D_80186CD4 + a0 * 12;
}
