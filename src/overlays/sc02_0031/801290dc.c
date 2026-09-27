/* SC02.CD FILE_031 / ov_SC02_031 retail span [801290DC,8012913C).
 * Offset 0xF84 at overlay base 80128158. SHA256(span)=c517302d64ed786d697bb94f4a208d1e813f114c772c9126fd3ea2b9eb0e687e.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/801290dc.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
#include "psx_types.h"
void *func_8012913C();
typedef struct { u16 a, b, c; } V;
typedef struct {
    u8 pad[6]; u16 u6;
    u8 pad8[2]; u16 uA;
    u8 padC[2]; u16 uE;
} T;
T *func_801290DC(u16 a0, V *v) {
    T *q = func_8012913C(a0);
    if (q) {
        q->u6 = v->a;
        q->uA = v->b;
        q->uE = v->c;
    }
    return q;
}
