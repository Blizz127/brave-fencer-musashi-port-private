/* SC02 resident retail span [80158880,801588CC). Offset 0x30728 at base 80128158.
 * SHA256(span)=46901c75bac2ec070af8017941af17c895672db256c4ffcbaf6ba5eec6e84fd5.
 * Words are the guest's loaded image (artifacts/sc02-resident-20260910).
 * Member-0012 C shape retargeted to this member: D_8018071C->D_8018700C.
 * Oracle MATCH re-earned against the resident image; Not MAIN10.
 */
#include "psx_types.h"
typedef void (*CB)();
extern CB D_8018700C[];
void func_80149020();
typedef struct { u8 pad[0x4F]; u8 idx; } T;
void func_80158880(T *p) {
    func_80149020(p);
    D_8018700C[p->idx](p);
}
