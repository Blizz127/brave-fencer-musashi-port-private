/* SC02.CD FILE_031 / ov_SC02_031 retail span [80142778,801427DC).
 * Offset 0x1A620 at overlay base 80128158. SHA256(span)=d3ebc319079cf3c27071417545c6581d69b2ba6145d5c6a0b72125628b2478de.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80142778.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
#include "psx_types.h"
void func_8012C218();
typedef struct Inner { u8 pad[0x18]; s16 u18, u1A; } Inner;
typedef struct {
    u8 pad[0xA]; s16 uA;
    u8 padC[0x14]; Inner *inner;
} T;
void func_80142778(T *p) {
    Inner *in = p->inner;
    in->u18 -= 0x800;
    in->u1A -= 0x800;
    p->uA += 0x10;
    if (in->u18 <= 0) {
        func_8012C218(p);
    }
}
