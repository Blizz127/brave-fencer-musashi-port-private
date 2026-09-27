/* SC02.CD FILE_031 / ov_SC02_031 retail span [80164CD4,80164D4C).
 * Offset 0x3CB7C at overlay base 80128158. SHA256(span)=19ec0c7fbc687d37e3d7c026b3421899261f5deedb45338fbc5291bfcb34ac73.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80164cd4.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
#include "psx_types.h"
void func_80164E40();
void func_80146CA0();
typedef struct Inner { u8 pad[0x18]; s16 a, b; } Inner;
typedef struct {
    u8 pad[0x20]; Inner *inner;
    u8 pad24[0x3C]; s16 u60, u62;
} T;
void func_80164CD4(T *p) {
    Inner *in = p->inner;
    func_80164E40(p);
    p->u60 += p->u62;
    in->b += p->u60;
    in->a = in->b;
    if (p->u60 < 0) {
        func_80146CA0(p);
    }
}
