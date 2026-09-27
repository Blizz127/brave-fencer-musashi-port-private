/* SC02 resident retail span [80165B28,80165B6C). Offset 0x3D9D0 at base 80128158.
 * SHA256(span)=2338b115028b24b69fa3a75f1970a7943a2e056c3fe7c1386dbe87dd0f28ef7c.
 * Words are the guest's loaded image (artifacts/sc02-resident-20260910).
 * Member-0012 C shape retargeted to this member: D_80181254->D_80187B44.
 * Oracle MATCH re-earned against the resident image; Not MAIN10.
 */
#include "psx_types.h"
typedef void (*CB)();
extern CB D_80187B44[];
typedef struct { u8 pad[0x44]; u32 flags; u8 pad2[0x197-0x48]; u8 idx; } T;
void func_80165B28(T *p) {
    p->flags |= 8;
    D_80187B44[p->idx]();
}
