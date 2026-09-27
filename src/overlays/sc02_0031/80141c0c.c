/* SC02 resident retail span [80141C0C,80141C50). Offset 0x19AB4 at base 80128158.
 * SHA256(span)=7ba0dec8adbc0348a5630ee7fafc24fcc9fa30bd7b793982339a24a9fd64db05.
 * Words are the guest's loaded image (artifacts/sc02-resident-20260910).
 * Member-0012 C shape retargeted to this member: D_8017F6D4->D_80185FC4.
 * Oracle MATCH re-earned against the resident image; Not MAIN10.
 */
#include "psx_types.h"

extern void func_8002D4C8(s32 arg0, s32 arg1);
extern u16 D_80115110;
extern u16 D_80185FC4[];

/* HAND MODEL of func_80141C0C (main_0012.s), decoded manually from
 * raw asm (fully visible; NOT verified against retail; C89-gated
 * only, promotion requires an oracle MATCH): void (s32), 0x18
 * frame. Runs 8002D4C8(lhu(F6D4[sext(a0)*2 + lhu(115110)]), 0)
 * (the (a0<<16)>>15 pair is sext(a0)*2; the final <<1 makes it a
 * byte offset = u16 element index). 2D4C8 decl matches the
 * provisional (s32, s32) shape used verbatim across staging. */
void func_80141C0C(s32 arg0)
{
    func_8002D4C8(D_80185FC4[((arg0 << 16) >> 16) * 2 + D_80115110], 0);
}
