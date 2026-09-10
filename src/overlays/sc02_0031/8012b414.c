/* SC02.CD FILE_031 / ov_SC02_031 retail span [8012B414,8012B4B8).
 * Offset 0x32BC at overlay base 80128158. SHA256(span)=3c67b445edbf3f9b2d9eecd48af2834effab029067e3257d782b81f4c17234ea.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/8012b414.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
#include "psx_types.h"
void func_8004978C();
typedef struct {
    u8 pad[8]; s16 u8, uA, uC;
    u8 padE[0x1E]; u16 u2C;
    u8 pad2E[0x1A]; s32 u48, u4C, u50;
} Inner;
typedef struct {
    u8 pad[6]; u16 u6;
    u8 pad8[2]; u16 uA;
    u8 padC[2]; u16 uE;
    u8 pad10[0x10]; Inner *inner;
    u8 pad24[0x2C]; u16 u50, u52, u54;
} T;
void func_8012B414(T *p) {
    Inner *in = p->inner;
    Inner *q;
    s16 v;
    if (in) {
        func_8004978C((u8 *)in + 0x10, (u8 *)in + 0x34);
        q = p->inner;
        v = p->u6 + p->u50;
        q->u8 = v;
        q->u48 = v;
        v = p->uA + p->u52;
        q->uA = v;
        q->u4C = v;
        v = p->uE + p->u54;
        q->uC = v;
        q->u2C = q->u2C | 1;
        q->u50 = v;
    }
}
