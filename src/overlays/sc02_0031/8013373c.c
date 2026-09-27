/* SC02 resident retail span [8013373C,80133784). Offset 0xB5E4 at base 80128158.
 * SHA256(span)=a597560631580f6fb21806d4ec562cb67163d685d6734362b2990546f6555f34.
 * Words are the guest's loaded image (artifacts/sc02-resident-20260910).
 * Member-0012 C shape retargeted to this member: D_80184120->D_801B62D8; D_80184124->D_801B62DC.
 * Oracle MATCH re-earned against the resident image; Not MAIN10.
 */
#include "psx_types.h"
void func_80136BC4();
extern void *D_801B62DC[];
extern void *D_801B62D8;
void func_8013373C(s32 a0) {
    void *p = D_801B62DC[(s16)a0];
    if (p) {
        D_801B62D8 = p;
        func_80136BC4(p);
    }
}
