/* SC02.CD FILE_031 / ov_SC02_031 retail span [8016EAC0,8016EB3C).
 * Offset 0x46968 at overlay base 80128158. SHA256(span)=e7747aa3a4630201247228bc2c9088820323d7d593d7523105e5de2bcb6144dd.
 * Differs from the registry-verified MAIN member 0012 carve in exactly one
 * data reference: D_80181740 here is D_80181FC8 (+0x888 member
 * data-block shift). Oracle MATCH re-earned on this file; Not MAIN10.
 */
#include "psx_types.h"
void func_8016EC0C();
extern u16 D_80181FC8[];
typedef struct {
    u8 pad0, u1, u2, pad3;
    u16 u4;
} T;
void func_8016EAC0(T *p) {
    p->u4 = p->u4 + D_80181FC8[p->u2];
    func_8016EC0C(p, 0x80);
    p->u2 = p->u2 + 1;
    if (p->u2 >= 6) {
        p->u2 = 0x20;
        p->u1 = p->u1 + 1;
    }
}
