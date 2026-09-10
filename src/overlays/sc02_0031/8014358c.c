/* SC02 resident retail span [8014358C,80143640). Offset 0x1B434 at base 80128158.
 * SHA256(span)=61739139e51f421f26539120293d54288f56e37d81fca90537264cba3763fb7c.
 * Words are the guest's loaded image (artifacts/sc02-resident-20260910).
 * Member-0012 C shape retargeted to this member: D_8017FB8C->D_8018647C; D_8017FC88->D_80186578.
 * Oracle MATCH re-earned against the resident image; Not MAIN10.
 */
#include "psx_types.h"
void func_80128EA8();
extern u8 D_8018647C[];
extern void *D_80186578[];
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
    p->inner->u20 = D_8018647C;
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
    func_80128EA8(p->inner, (u8 *)p + 0x24, D_80186578[p->u34 & 3]);
    p->u2 = p->u2 + 1;
}
