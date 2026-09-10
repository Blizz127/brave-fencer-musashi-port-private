/* SC02 resident retail span [801425CC,80142608). Offset 0x1A474 at base 80128158.
 * SHA256(span)=5e93bac7069eedd08b78192bfbaa2594134d58a3df5ef36511bab1f3eca2b087.
 * Words are the guest's loaded image (artifacts/sc02-resident-20260910).
 * Member-0012 C shape retargeted to this member: D_8017F7B4->D_801860A4.
 * Oracle MATCH re-earned against the resident image; Not MAIN10.
 */
#include "psx_types.h"

extern void (*D_801860A4[])(void *arg0);

/* HAND MODEL of func_801425CC (main_0012.s), decoded manually from
 * raw asm (fully visible; NOT verified against retail; C89-gated
 * only, promotion requires an oracle MATCH): void (u8 *), 0x18
 * frame. Indirect tail-call of F7B4[lhu(a0+2)] with a0 (which
 * still holds the incoming pointer across the nop delay slot).
 * Table element type provisional. */
void func_801425CC(u8 *arg0)
{
    D_801860A4[*(u16 *)(arg0 + 2)](arg0);
}
