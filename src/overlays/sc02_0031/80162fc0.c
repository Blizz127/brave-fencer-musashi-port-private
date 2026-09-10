/* SC02.CD FILE_031 / ov_SC02_031 retail span [80162FC0,80162FF4).
 * Offset 0x3AE68 at overlay base 80128158. SHA256(span)=8ba7a8502e27791f8b1444b8d8f5f268230990dbe4372e0a27587eb9b2b6ea56.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80162fc0.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
#include "psx_types.h"
typedef struct { u8 pad[4]; s32 a, b, c, d, e, f; } T;
void func_80162FC0(T *p) {
    p->a += p->d;
    p->b += p->e;
    p->c += p->f;
}
