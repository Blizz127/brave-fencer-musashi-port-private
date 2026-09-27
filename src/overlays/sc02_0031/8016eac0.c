/* SC02 resident retail span [8016EAC0,8016EB3C). Offset 0x46968 at base 80128158.
 * SHA256(span)=1f0dfb5a766d986330483885141f6703425e0edb21d3b4f6a4f729152bda106c.
 * Words are the guest's loaded image (artifacts/sc02-resident-20260910).
 * Member-0012 C shape retargeted to this member: D_80181740->D_80188030.
 * Oracle MATCH re-earned against the resident image; Not MAIN10.
 */
#include "psx_types.h"
void func_8016EC0C();
extern u16 D_80188030[];
typedef struct {
    u8 pad0, u1, u2, pad3;
    u16 u4;
} T;
void func_8016EAC0(T *p) {
    p->u4 = p->u4 + D_80188030[p->u2];
    func_8016EC0C(p, 0x80);
    p->u2 = p->u2 + 1;
    if (p->u2 >= 6) {
        p->u2 = 0x20;
        p->u1 = p->u1 + 1;
    }
}
