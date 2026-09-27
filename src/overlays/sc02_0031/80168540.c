/* SC02.CD FILE_031 / ov_SC02_031 retail span [80168540,801685EC).
 * Offset 0x403E8 at overlay base 80128158. SHA256(span)=d691210d851768126b409194e3978a3fa1e7ec63e06701646291940f2be9356d.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80168540.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
#include "psx_types.h"
void func_80166994();
s32 func_80166690();
void func_80146C3C();
typedef struct Q { u8 pad[0x44]; s32 flags; } Q;
typedef struct {
    u8 pad[2]; u16 u2;
    u8 pad4[0x18]; s32 u1C;
    u8 pad20[0x10]; s16 u30;
    u8 pad32[2]; Q *u34;
} T;
void func_80168540(T *p) {
    if ((p->u34->flags & 2) == 0 || (p->u1C = p->u1C - 1) == 0) {
        p->u2 = p->u2 + 1;
        func_80166994(p, 2, 2, 0);
    } else {
        func_80166994(p, 1, 2, p->u30);
    }
    if ((s16)func_80166690(2, 1) == 0) {
        func_80146C3C(p);
    }
}
