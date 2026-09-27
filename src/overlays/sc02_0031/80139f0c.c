/* SC02.CD FILE_031 / ov_SC02_031 retail span [80139F0C,80139FBC).
 * Offset 0x11DB4 at overlay base 80128158. SHA256(span)=4f520a140f7589c7957b8dd3cfca611a9fc39e60d7e8026b051ac68b1b25bd5e.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80139f0c.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
#include "psx_types.h"
s32 func_80138DB8();
void func_8002D4C8();
void func_80139B18();
extern void *D_80127524;
typedef struct { u8 pad[4]; s16 u4; u8 pad6[2]; s32 u8; } T;
void func_80139F0C(T *p) {
    s32 a2;
    if (D_80127524 != p && (p->u8 & 0x2000) == 0) {
        p->u4 = 4;
        return;
    }
    a2 = (p->u8 & 0x4000) ? 0x70 : 0x60;
    if ((func_80138DB8(p, 0, a2) << 16) == 0) {
        func_80139B18(p);
        return;
    }
    p->u4 = 2;
    if ((p->u8 & 0x20000) == 0) {
        p->u8 &= ~0x20;
    }
    func_8002D4C8(0x88D, 0);
    func_80139B18(p);
}
