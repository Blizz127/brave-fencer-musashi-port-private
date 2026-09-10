/* SC02.CD FILE_031 / ov_SC02_031 retail span [8014168C,801416D4).
 * Offset 0x19534 at overlay base 80128158. SHA256(span)=b37b00aa11d293f650da8bc32d73f915182ba2e6f707ac2a826a43c3dfa29ab9.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/8014168c.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
#include "psx_types.h"

extern u8 D_80115148[];
extern u8 D_80115149[];
extern u8 D_80115158[];

/* HAND MODEL of func_8014168C (main_0012.s), decoded manually from
 * raw asm (fully visible; NOT verified against retail; C89-gated
 * only, promotion requires an oracle MATCH): s32 (s32), leaf.
 * Returns sext(lbu(115148[i]) + lbu(115149[i])*lbu(115158[i]))
 * with i = sext(a0)*2 (the (a0<<16)>>15 shift pair). */
s32 func_8014168C(s32 arg0)
{
    s32 i = ((arg0 << 16) >> 16) * 2;

    return ((s32)(D_80115148[i] + D_80115149[i] * D_80115158[i]) << 16) >> 16;
}
