/* SC02.CD FILE_031 / ov_SC02_031 retail span [80165B28,80165B6C).
 * Offset 0x3D9D0 at overlay base 80128158. SHA256(span)=5f2ad3e2649242287c1a097ea763bc0898e932e54e132e3c0f1e82ed8c224bf4.
 * Differs from the registry-verified MAIN member 0012 carve in exactly one
 * data reference: D_80181254 here is D_80181ADC (+0x888 member
 * data-block shift). Oracle MATCH re-earned on this file; Not MAIN10.
 */
#include "psx_types.h"
typedef void (*CB)();
extern CB D_80181ADC[];
typedef struct { u8 pad[0x44]; u32 flags; u8 pad2[0x197-0x48]; u8 idx; } T;
void func_80165B28(T *p) {
    p->flags |= 8;
    D_80181ADC[p->idx]();
}
