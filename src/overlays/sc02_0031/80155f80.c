/* SC02.CD FILE_031 / ov_SC02_031 retail span [80155F80,80155FB0).
 * Offset 0x2DE28 at overlay base 80128158. SHA256(span)=192c3ee4a67404d330ad5190396da4ca848861c899446a5fabb90edd3b36b407.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80155f80.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
#include "psx_types.h"
void func_80154A74();
typedef struct { u8 pad[0x44]; s32 flags; } T;
void func_80155F80(T *p) {
    p->flags &= ~2;
    func_80154A74(p, 0x11);
}
