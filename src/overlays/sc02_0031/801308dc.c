/* SC02.CD FILE_031 / ov_SC02_031 retail span [801308DC,80130974).
 * Offset 0x8784 at overlay base 80128158. SHA256(span)=b0062d71236415fe3b2bf19f3e7bcc0e684863fde9fb4a75f14b7287c5766db5.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/801308dc.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
#include "psx_types.h"
void func_8002D4C8();
void func_80131CA8();
typedef struct Inner {
    u8 pad[0x18]; s16 u18, u1A, u1C;
    u8 pad1E[0xE]; u16 u2C;
} Inner;
typedef struct {
    u8 pad[0x1C]; s32 u1C;
    Inner *inner;
    u8 pad24[0x38]; s16 u5C;
    u8 pad5E[0x3A]; s16 u98;
    u8 pad9A[0x10]; s16 uAA;
    u8 padAC[8]; s32 uB4;
    u8 padB8[9]; u8 uC1;
} T;
void func_801308DC(T *p) {
    p->uC1 = 0xE;
    if (p->uB4 & 0x8000) {
        p->u1C = 0x10;
        p->uAA = 0;
        p->u5C = 0;
        p->u98 = 0;
        p->inner->u18 = 0x400;
        p->inner->u1C = 0x400;
        p->inner->u1A = 0x200;
        p->inner->u2C |= 0x10;
        func_8002D4C8(0x68A, 0);
    }
    func_80131CA8(p, 0x2A);
}
