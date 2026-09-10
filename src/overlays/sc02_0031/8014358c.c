/* SC02.CD FILE_031 / ov_SC02_031 retail span [8014358C,80143640).
 * Offset 0x1B434 at overlay base 80128158. SHA256(span)=d168e0ef979a76a675d5af435cac36241b1dc4365c510ab93ce116a5e7a8fc64.
 * Same shape as the registry-verified MAIN member 0012 carve with only the
 * listed data references retargeted for this member: D_8017FB8C->D_80180414; D_8017FC88->D_80180510.
 * Oracle MATCH re-earned on this file; Not MAIN10.
 */
#include "psx_types.h"
void func_80128EA8();
extern u8 D_80180414[];
extern void *D_80180510[];
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
void func_8014358C(T *p) {
    Inner *in;
    u16 v;
    p->inner->u20 = D_80180414;
    in = p->inner;
    if (in->u4 == 0) {
        in->u4 = 0x50000000;
    }
    p->inner->u27 = 0x90;
    v = p->u34 & 0x7FFF;
    if (v) {
        in = p->inner;
        in->u1A = v;
        in->u18 = v;
    }
    func_80128EA8(p->inner, (u8 *)p + 0x24, D_80180510[p->u34 & 3]);
    p->u2 = p->u2 + 1;
}
