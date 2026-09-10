/* SC02.CD FILE_031 / ov_SC02_031 retail span [80172E20,80172E8C).
 * Offset 0x4ACC8 at overlay base 80128158. SHA256(span)=cff09b337e305685cdd4962700d5140659af68a902920672885ab52ca8505658.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80172e20.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
#include "psx_types.h"
s32 func_80171AB0();
void func_80171A1C();
void func_80174650();
typedef struct { u8 pad[6]; u16 a; u8 pad8[2]; u16 b; u8 padC[2]; u16 c; } G;
extern G *D_80127508;
void func_80172E20(void *p) {
    s16 tmp[3];
    G *g = D_80127508;
    tmp[0] = g->a;
    tmp[1] = g->b;
    tmp[2] = g->c;
    if ((s16)func_80171AB0(p, tmp) == 0) {
        func_80171A1C(p);
        func_80174650(p);
    }
}
