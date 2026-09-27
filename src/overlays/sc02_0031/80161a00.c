/* SC02.CD FILE_031 / ov_SC02_031 retail span [80161A00,80161A30).
 * Offset 0x398A8 at overlay base 80128158. SHA256(span)=811ba4102566e37e1d28c442c59834a697df148e2bf3d4e17612dda0f106472d.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80161a00.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
#include "psx_types.h"
extern u8 D_80078EC0;
typedef struct { u8 pad[0x1C8]; s16 u1C8; } T;
s32 func_80161A00(T *p) {
    if (p->u1C8) {
        return (D_80078EC0 & 0x7F) == 4;
    }
    return 0;
}
