/* SC02.CD FILE_031 / ov_SC02_031 retail span [80155440,80155458).
 * Offset 0x2D2E8 at overlay base 80128158. SHA256(span)=8d6b7a899b76ea2a0aa22e2ab4c80cfab40ef7c95722ec5a7170b301fc8849b2.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80155440.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
#include "psx_types.h"
typedef struct { u8 pad[0x44]; s32 flags; } T;
void func_80155440(T *p) {
    p->flags &= ~0x10000000;
}
