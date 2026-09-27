/* SC02.CD FILE_031 / ov_SC02_031 retail span [8017044C,801704B0).
 * Offset 0x482F4 at overlay base 80128158. SHA256(span)=4302a56210c5335dbe70fab4bf4be581f2d83c4be3585bdbad5250280390d224.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/8017044c.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
#include "psx_types.h"
s32 func_80171AB0();
void func_80171928();
typedef struct { u8 pad[0x3C]; s32 a, b, c; } G;
extern G *D_801151D4;
void func_8017044C(void *p) {
    s16 tmp[3];
    G *g = D_801151D4;
    tmp[0] = g->a;
    tmp[1] = g->b;
    tmp[2] = g->c;
    if ((s16)func_80171AB0(p, tmp) == 0) {
        func_80171928(p);
    }
}
