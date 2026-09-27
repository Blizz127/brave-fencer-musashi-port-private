/* SC02.CD FILE_031 / ov_SC02_031 retail span [8017250C,80172560).
 * Offset 0x4A3B4 at overlay base 80128158. SHA256(span)=4d4b13bfed885aa01ecf9f09fdbad531e98f2f25ae914ca169296f287b5de9aa.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/8017250c.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
#include "psx_types.h"
s32 func_80172560();
typedef struct { u16 a, b, c; } V;
typedef struct {
    u8 pad[6]; u16 u6;
    u8 pad8[6]; u16 uE;
} T;
s32 func_8017250C(T *p, V *v) {
    if (func_80172560(p, v) == 0) {
        return 0;
    }
    p->u6 = v->a;
    p->uE = v->c;
    return 1;
}
