/* SC02.CD FILE_031 / ov_SC02_031 retail span [801739D8,80173A20).
 * Offset 0x4B880 at overlay base 80128158. SHA256(span)=acb813bcabf9272a99316fca2e601fc795aa3779103dfe705fe1d1091959e27c.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/801739d8.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
#include "psx_types.h"
void func_80171A1C();
void func_80174650();
typedef struct { u8 pad[0x44]; s32 flags; } T;
void func_801739D8(T *p) {
    if (!(p->flags & 2)) {
        func_80171A1C(p);
        func_80174650(p);
    }
}
