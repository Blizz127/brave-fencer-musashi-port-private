/* SC02.CD FILE_031 / ov_SC02_031 retail span [801511E0,80151204).
 * Offset 0x29088 at overlay base 80128158. SHA256(span)=354ec1762652d0930551d6264c5a7f0f3db9b15fa87dda2b03c3065cbb3087b5.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/801511e0.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
#include "psx_types.h"
void func_80151204();
typedef struct { u8 pad[0xF2]; s16 f; } T;
void func_801511E0(T *p) {
    func_80151204(p, p->f);
}
