/* SC02.CD FILE_031 / ov_SC02_031 retail span [80143458,8014350C).
 * Offset 0x1B300 at overlay base 80128158. SHA256(span)=ac40d3e0a8b9876cb711210dfb8b7d54f62e54274c86866dd798fe6b2db25b19.
 * Differs from the registry-verified MAIN member 0012 carve in exactly one
 * data reference: D_8017FB7C here is D_80180404 (+0x888 member
 * data-block shift). Oracle MATCH re-earned on this file; Not MAIN10.
 */
#include "psx_types.h"
void func_80128EA8();
extern u8 D_800D387C[];
extern void *D_80180404[];
typedef struct {
    u8 pad[4]; s32 u4;
    u8 pad8[0x10]; s16 u18, u1A;
    u8 pad1C[4]; void *u20;
    u8 pad24[3]; u8 u27;
} Inner;
typedef struct {
    u8 pad[2]; u16 u2;
    u8 pad4[0x1C]; Inner *inner;
    u8 pad24[0x10]; u16 u34;
} T;
void func_80143458(T *p) {
    Inner *in;
    u16 v;
    p->inner->u20 = D_800D387C;
    in = p->inner;
    if (in->u4 == 0) {
        in->u4 = 0x50000000;
    }
    p->inner->u27 = 0x9C;
    v = p->u34 & 0x7FFF;
    if (v) {
        in = p->inner;
        in->u1A = v;
        in->u18 = v;
    }
    func_80128EA8(p->inner, (u8 *)p + 0x24, D_80180404[p->u34 & 3]);
    p->u2 = p->u2 + 1;
}
