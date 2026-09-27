/* SC02.CD FILE_031 / ov_SC02_031 retail span [80165A78,80165AC8).
 * Offset 0x3D920 at overlay base 80128158. SHA256(span)=73192f2cc33948521cfeb9d238dcd9add8e039be2b4f7e3a19bdada6b76703d3.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80165a78.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
#include "psx_types.h"
void func_80165AC8();
typedef struct Inner { u8 pad[0x2C]; u16 f; } Inner;
typedef struct {
    u8 pad[0x20]; Inner *inner;
    u8 pad24[0x20]; s32 flags;
    u8 pad48[0x197-0x48]; u8 unk197;
} T;
void func_80165A78(T *p) {
    func_80165AC8(p);
    p->unk197 = 0;
    p->flags &= ~8;
    p->inner->f &= ~0x20;
}
