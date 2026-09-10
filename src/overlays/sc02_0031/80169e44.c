/* SC02.CD FILE_031 / ov_SC02_031 retail span [80169E44,80169F00).
 * Offset 0x41CEC at overlay base 80128158. SHA256(span)=64e9cf7bd2ea5cc59f3bc13dd21fd43d0d2023da28b6cdfa2c995c9361f8aebb.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80169e44.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
#include "psx_types.h"
s32 func_80128ED8();
void func_80146C3C();
void *func_80146A6C();
typedef struct {
    u8 pad[6]; s16 u6; u8 pad8[2]; s16 uA; u8 padC[2]; s16 uE;
    u8 pad10[2]; u16 u12; u8 pad14[2]; u16 u16; u8 pad18[2]; u16 u1A;
    s32 u1C;
    void *inner;
} T;
typedef struct { u8 pad[0x12]; u16 u12; u8 pad14[2]; u16 u16; u8 pad18[2]; u16 u1A; } R;
void func_80169E44(T *p) {
    R *r;
    if (func_80128ED8(p->inner, (u8 *)p + 0x24)) {
        func_80146C3C(p);
        return;
    }
    if (p->u1C++ >= 3) {
        return;
    }
    r = func_80146A6C(9, p, p->u6, p->uA, p->uE, p->u1C & 1, 0);
    if (r) {
        r->u12 = p->u12;
        r->u16 = p->u16;
        r->u1A = p->u1A;
    }
}
