/* SC02.CD FILE_031 / ov_SC02_031 retail span [80130898,801308DC).
 * Offset 0x8740 at overlay base 80128158. SHA256(span)=690a5f73bac418a50711959765b7a08a0d5a2d650ea575dec5c5ef800d60b508.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80130898.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
#include "psx_types.h"

/* HAND MODEL of func_80130898 (main_0012.s), decoded manually from
 * raw asm (fully visible; NOT verified against retail; C89-gated
 * only, promotion requires an oracle MATCH): if arg0->unkB4 & 0x4000,
 * arg0->unkAA = 0x100 (v1 = 0x100 set in the branch delay slot)
 * and arg0->unk5C &= ~1. Then func_80131CA8(arg0, 0x28) (result
 * ignored). Returns void. */

struct obj_80130898 {
    u8 pad[0x5C];
    u16 unk5C;
    u8 pad2[0xAA - 0x5E];
    u16 unkAA;
    u8 pad3[0xB4 - 0xAC];
    s32 unkB4;
};

extern s32 func_80131CA8(void *arg0, s32 arg1);

void func_80130898(struct obj_80130898 *arg0) {
    if (arg0->unkB4 & 0x4000) {
        arg0->unkAA = 0x100;
        arg0->unk5C &= ~1;
    }
    func_80131CA8(arg0, 0x28);
}
