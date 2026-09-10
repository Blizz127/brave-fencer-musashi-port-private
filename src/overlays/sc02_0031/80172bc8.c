/* SC02.CD FILE_031 / ov_SC02_031 retail span [80172BC8,80172C48).
 * Offset 0x4AA70 at overlay base 80128158. SHA256(span)=3a0fa987f6472d69001828bbcc2399dceb5e5f4360f7c93e0440cbe6cf18a717.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80172bc8.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
#include "psx_types.h"
s32 func_80012B04();
void func_80171A1C();
void func_80174650();
extern s16 D_80126B32;
typedef struct Inner { u8 pad[0x12]; s16 a; } Inner;
typedef struct { u8 pad[0x20]; Inner *inner; } T;
void func_80172BC8(T *p) {
    s32 d = func_80012B04(p->inner->a, D_80126B32, 4);
    if ((s16)d == 0) {
        func_80171A1C(p);
        func_80174650(p);
    }
    p->inner->a = (p->inner->a + d) & 0xFFF;
}
