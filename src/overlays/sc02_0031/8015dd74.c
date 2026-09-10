/* SC02.CD FILE_031 / ov_SC02_031 retail span [8015DD74,8015DDF0).
 * Offset 0x35C1C at overlay base 80128158. SHA256(span)=cf24d13ea4d4c1ffc03a04fcad2e652af58e3a49445da08fafa1f1fc236baf97.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/8015dd74.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
#include "psx_types.h"
void func_8014C1A0();
void func_80015978();
s32 func_80029AAC();
void func_8014C4AC();
typedef struct Inner { u8 pad[0x12]; s16 u12; } Inner;
typedef struct {
    u8 pad[0x20]; Inner *inner;
    u8 pad24[0x154]; void *u178;
} T;
void func_8015DD74(T *p) {
    s16 tmp[4];
    void *q = p->u178;
    s32 v;
    if (q == 0) {
        return;
    }
    func_8014C1A0(p, q);
    func_80015978((u8 *)q + 4, tmp);
    tmp[3] = 0;
    v = func_80029AAC();
    func_8014C4AC(q, 9, v, tmp, p->inner->u12);
    p->u178 = 0;
}
