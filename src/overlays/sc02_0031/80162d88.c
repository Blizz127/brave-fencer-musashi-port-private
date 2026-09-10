/* SC02.CD FILE_031 / ov_SC02_031 retail span [80162D88,80162DE8).
 * Offset 0x3AC30 at overlay base 80128158. SHA256(span)=f490fff42739dbf1d4948fd8ebe368761b7b9d28b8c72b47c1145584679aa3ba.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80162d88.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
#include "psx_types.h"
void func_80013F3C();
void func_80012558();
void func_800126C4();
void func_800123F0();
typedef struct Inner {
    u8 pad_0[16];
    s16 b;
    s16 a;
    s16 c;
} Inner;
typedef struct {
    u8 pad_0[32];
    Inner * inner;
} T;
void func_80162D88(T *p) {
    Inner *q = p->inner;
    func_80013F3C((u8 *)q + 52);
    func_80012558((u8 *)q + 52, q->a);
    func_800126C4((u8 *)q + 52, q->b);
    func_800123F0((u8 *)q + 52, q->c);
}
