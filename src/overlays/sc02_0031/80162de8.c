/* SC02.CD FILE_031 / ov_SC02_031 retail span [80162DE8,80162E48).
 * Offset 0x3AC90 at overlay base 80128158. SHA256(span)=e39f47913320e095f0b505937f54a59d233ae03a01560b0f2ac58f80df47a235.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80162de8.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
#include "psx_types.h"
void func_80013F3C();
void func_800123F0();
void func_800126C4();
void func_80012558();
typedef struct Inner {
    u8 pad_0[16];
    s16 b;
    s16 c;
    s16 a;
} Inner;
typedef struct {
    u8 pad_0[32];
    Inner * inner;
} T;
void func_80162DE8(T *p) {
    Inner *q = p->inner;
    func_80013F3C((u8 *)q + 52);
    func_800123F0((u8 *)q + 52, q->a);
    func_800126C4((u8 *)q + 52, q->b);
    func_80012558((u8 *)q + 52, q->c);
}
