/* SC02 resident retail span [801634D8,80163534). Offset 0x3B380 at base 80128158.
 * SHA256(span)=9d414ae077f3353922b20a077e660b46b84b9a047a7fd3e319357ac74a877cf4.
 * Words are the guest's loaded image (artifacts/sc02-resident-20260910).
 * Member-0012 C shape retargeted to this member: D_8018393C->D_801B5D48.
 * Oracle MATCH re-earned against the resident image; Not MAIN10.
 */
#include "psx_types.h"
typedef struct { u8 b[8]; } S;
extern S D_801B5D48;
void func_80163534();
void func_801634D8(s32 a0, s32 a1, s32 a2, s32 a3, u16 a4) {
    S tmp;
    tmp = D_801B5D48;
    func_80163534(a0, a1 & 0xFFFF, a2 & 0xFFFF, a3, a4, &tmp);
}
