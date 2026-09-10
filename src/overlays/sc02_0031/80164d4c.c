/* SC02.CD FILE_031 / ov_SC02_031 retail span [80164D4C,80164DB0).
 * Offset 0x3CBF4 at overlay base 80128158. SHA256(span)=9116e0981747fa1cc2400057e58d16dd2e29124883b697de43b9ff32c80f37e6.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80164d4c.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
#include "psx_types.h"
s32 func_80164E40();
void func_80146CA0();
typedef struct Inner { u8 pad[0x18]; u16 a, b; } Inner;
typedef struct { u8 pad[0x20]; Inner *inner; } T;
void func_80164D4C(T *p) {
    Inner *in = p->inner;
    if (func_80164E40(p)) {
        func_80146CA0(p);
    } else {
        u16 v = in->b + 0x100;
        in->b = v;
        in->a = v;
    }
}
