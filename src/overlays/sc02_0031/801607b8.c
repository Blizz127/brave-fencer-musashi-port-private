/* SC02.CD FILE_031 / ov_SC02_031 retail span [801607B8,801607E4).
 * Offset 0x38660 at overlay base 80128158. SHA256(span)=c86551bfb128cf20840cfb8d687c7431cb3e7fd852f4da2e0f276f4b63e52cd3.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/801607b8.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
#include "psx_types.h"
void func_80149048();
typedef struct { u8 pad[0x44]; s32 flags; } T;
void func_801607B8(T *p) {
    p->flags &= ~1;
    func_80149048(p);
}
