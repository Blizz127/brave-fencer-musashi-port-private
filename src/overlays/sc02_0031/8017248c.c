/* SC02.CD FILE_031 / ov_SC02_031 retail span [8017248C,801724EC).
 * Offset 0x4A334 at overlay base 80128158. SHA256(span)=cb72ecf8427459d7fc59739af2beb9b1b34a99e60d65175cdf3bbed79be33082.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/8017248c.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
#include "psx_types.h"
s32 func_801724EC();
typedef struct { u16 a, b, c; } V;
typedef struct {
    u8 pad[6]; u16 u6;
    u8 pad8[2]; u16 uA;
    u8 padC[2]; u16 uE;
} T;
s32 func_8017248C(T *p, V *v) {
    if (func_801724EC(p, v) == 0) {
        return 0;
    }
    p->u6 = v->a;
    p->uA = v->b;
    p->uE = v->c;
    return 1;
}
