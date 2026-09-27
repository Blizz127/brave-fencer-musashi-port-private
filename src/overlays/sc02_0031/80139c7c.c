/* SC02.CD FILE_031 / ov_SC02_031 retail span [80139C7C,80139D04).
 * Offset 0x11B24 at overlay base 80128158. SHA256(span)=8145f2a838d51bbe59cd24054d5d75002025b703b7dd6330143da23e77ce7778.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80139c7c.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
#include "psx_types.h"
typedef struct {
    u8 pad[0x20]; u8 u20;
    u8 pad21; u8 u22;
    u8 pad23; u16 u24, u26;
    u8 pad28[8]; s16 u30, u32, u34, u36;
} T;
void func_80139C7C(T *p) {
    s32 a1;
    if (p->u20) {
        if (p->u22 & 8) {
            a1 = (p->u34 + 0x28) >> 1;
        } else {
            a1 = ((p->u34 + 0x28) >> 1) - 0x28;
        }
    } else {
        a1 = (s16)p->u34 >> 1;
    }
    p->u30 = p->u24 - a1;
    p->u32 = p->u26 - (p->u36 >> 1);
}
