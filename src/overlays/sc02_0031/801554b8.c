/* SC02.CD FILE_031 / ov_SC02_031 retail span [801554B8,80155518).
 * Offset 0x2D360 at overlay base 80128158. SHA256(span)=5bb7f3b3fac7bc1e4a5a133c367194ca0a2b35d0b1890fd0543b069ee9892a35.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/801554b8.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
#include "psx_types.h"
s32 func_800D02D0();
void func_801659DC();
typedef struct { u8 pad[0x196]; u8 u196; u8 pad197[9]; u8 u1A0; } T;
s32 func_801554B8(T *p) {
    u8 v;
    v = p->u1A0;
    if (v == p->u196) {
        return 0;
    }
    if (func_800D02D0(v) == 0) {
        return 1;
    }
    p->u196 = p->u1A0;
    func_801659DC(p);
    return 0;
}
