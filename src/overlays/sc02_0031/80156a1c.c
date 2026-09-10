/* SC02.CD FILE_031 / ov_SC02_031 retail span [80156A1C,80156A88).
 * Offset 0x2E8C4 at overlay base 80128158. SHA256(span)=f300bff2f94c08f9f476fa74bdcee0e14085463578aa967029840047340a71a0.
 * Differs from the registry-verified MAIN member 0012 carve in exactly one
 * data reference: D_80180654 here is D_80180EDC (+0x888 member
 * data-block shift). Oracle MATCH re-earned on this file; Not MAIN10.
 */
#include "psx_types.h"
void func_80147324();
extern u8 D_8011520C[];
extern u16 D_80180EDC[];
typedef struct { u8 pad[0xDA]; u8 uDA; } T;
void func_80156A1C(T *p, s32 a1) {
    if (p->uDA) {
        return;
    }
    func_80147324(D_80180EDC[D_8011520C[a1]]);
    p->uDA++;
}
