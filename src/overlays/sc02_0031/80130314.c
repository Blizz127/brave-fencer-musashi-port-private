/* SC02.CD FILE_031 / ov_SC02_031 retail span [80130314,80130360).
 * Offset 0x81BC at overlay base 80128158. SHA256(span)=ed7a7d57704a070b254621493ec5b2a25bee7c0d9f820fccf853e88702fd050c.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80130314.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
#include "psx_types.h"

/* HAND MODEL of func_80130314 (main_0012.s), decoded manually from
 * raw asm (fully visible; NOT verified against retail; C89-gated
 * only, promotion requires an oracle MATCH): if s0->unkB4 & 0x800,
 * func_80131340(s0) (a0 still holds s0; nop delay slot). Then
 * func_80131CA8(s0, 0x2D) (result ignored). Returns void. */

struct obj_80130314 {
    u8 pad[0xB4];
    s32 unkB4;
};

extern void func_80131340(void *arg0);
extern s32 func_80131CA8(void *arg0, s32 arg1);

void func_80130314(struct obj_80130314 *arg0) {
    if (arg0->unkB4 & 0x800) {
        func_80131340(arg0);
    }
    func_80131CA8(arg0, 0x2D);
}
