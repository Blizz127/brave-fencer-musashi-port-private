/* SC02 resident retail span [8013BD34,8013BD74). Offset 0x13BDC at base 80128158.
 * SHA256(span)=0e85d0fe54e984adc8c2909a84e060ee05015d3aa40bd1cc5874a6b8ab8d9c5b.
 * Words are the guest's loaded image (artifacts/sc02-resident-20260910).
 * Member-0012 C shape retargeted to this member: D_80185C10->D_801B7AA0.
 * Oracle MATCH re-earned against the resident image; Not MAIN10.
 */
#include "psx_types.h"

extern void func_8013BD74(u8 *arg0, u8 *arg1);
extern u8 D_801B7AA0[];

/* HAND MODEL of func_8013BD34 (main_0012.s), decoded manually from
 * raw asm (fully visible; NOT verified against retail; C89-gated
 * only, promotion requires an oracle MATCH): void (u8 *), 0x18
 * fp-frame. Thin wrapper: func_8013BD74(&D_801B7AA0, arg0). Void:
 * v0 after the jal is ignored. */
void func_8013BD34(u8 *arg0)
{
    func_8013BD74(D_801B7AA0, arg0);
}
