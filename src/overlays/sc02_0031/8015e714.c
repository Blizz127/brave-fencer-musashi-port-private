/* SC02.CD FILE_031 / ov_SC02_031 retail span [8015E714,8015E84C).
 * Offset 0x365BC at overlay base 80128158. SHA256(span)=484eac39b336dd90a0579f58d061416c3b382978b13e20070fb40efc67a49e2d.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/8015e714.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
#include "psx_types.h"
s32 func_80133784();
void func_80015978();
void func_8014C4AC();
void func_801553C0();
void func_80155440();
void func_80154A74();
typedef struct {
    u8 pad[6]; s16 u6; u8 pad8[2]; s16 uA; u8 padC[2]; s16 uE;
} Q;
typedef struct Inner { u8 pad[0x12]; s16 u12; } Inner;
typedef struct {
    u8 pad[6]; s16 u6; u8 pad8[2]; s16 uA; u8 padC[2]; s16 uE;
    u8 pad10[0x10]; Inner *inner;
    u8 pad24[0x20]; s32 flags;
    u8 pad48[0x144]; Q *u18C;
    u8 pad190[0xA4]; s32 u234;
} T;
void func_8015E714(T *p) {
    s16 a[4];
    s16 b[4];
    Q *q;
    if (p->u234 == 0) {
        q = p->u18C;
        if (q) {
            a[0] = p->u6;
            a[1] = p->uA - 0x14;
            a[2] = p->uE;
            b[0] = q->u6;
            b[1] = q->uA;
            b[2] = q->uE;
            if (func_80133784(0, a, b)) {
                q->u6 = b[0];
                q->uA = b[1];
                q->uE = b[2];
            }
            func_80015978((u8 *)q + 4, a);
            a[3] = 0;
            func_8014C4AC(q, 0x1C, 0, a, p->inner->u12);
            p->u18C = 0;
        }
    }
    func_801553C0(p);
    func_80155440(p);
    p->flags &= -3;
    func_80154A74(p, 0x11);
    p->flags &= -3;
}
