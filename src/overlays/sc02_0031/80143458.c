/* SC02 resident retail span [80143458,8014350C). Offset 0x1B300 at base 80128158.
 * SHA256(span)=6491791b1ed6985889c158614c22ac4b7cc31a955079e5c51b1b8597c6db82eb.
 * Words are the guest's loaded image (artifacts/sc02-resident-20260910).
 * Member-0012 C shape retargeted to this member: D_8017FB7C->D_8018646C.
 * Oracle MATCH re-earned against the resident image; Not MAIN10.
 */
#include "psx_types.h"
void func_80128EA8();
extern u8 D_800D387C[];
extern void *D_8018646C[];
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
    func_80128EA8(p->inner, (u8 *)p + 0x24, D_8018646C[p->u34 & 3]);
    p->u2 = p->u2 + 1;
}
