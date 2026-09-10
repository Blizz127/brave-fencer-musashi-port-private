/* SC02 resident retail span [80156A1C,80156A88). Offset 0x2E8C4 at base 80128158.
 * SHA256(span)=8e2bbfb6380779042c242c6bfb2f9f9f2657b15fc802443e733149682e887ab3.
 * Words are the guest's loaded image (artifacts/sc02-resident-20260910).
 * Member-0012 C shape retargeted to this member: D_80180654->D_80186F44.
 * Oracle MATCH re-earned against the resident image; Not MAIN10.
 */
#include "psx_types.h"
void func_80147324();
extern u8 D_8011520C[];
extern u16 D_80186F44[];
typedef struct { u8 pad[0xDA]; u8 uDA; } T;
void func_80156A1C(T *p, s32 a1) {
    if (p->uDA) {
        return;
    }
    func_80147324(D_80186F44[D_8011520C[a1]]);
    p->uDA++;
}
