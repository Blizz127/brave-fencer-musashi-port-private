/* SC02 resident retail span [8015E698,8015E714). Offset 0x36540 at base 80128158.
 * SHA256(span)=06304da1ad29476aea511783a54cb2a8f15d3717740fbd7926e701f5e456b809.
 * Words are the guest's loaded image (artifacts/sc02-resident-20260910).
 * Member-0012 C shape retargeted to this member: D_80180A1C->D_8018730C.
 * Oracle MATCH re-earned against the resident image; Not MAIN10.
 */
#include "psx_types.h"

/* HAND MODEL from m2c draft of func_8015E698 (main_0012.s): NOT verified
 * against retail. C89-gated only; promotion requires an oracle MATCH.
 * Same object family as func_8015F9A4: both members load as halfwords
 * (lhu +0x0 and +0xB8), and the callback table is indexed by the +0x0
 * member. Here the table call passes arg0 (m2c dataflow; $a0 is
 * unclobbered at the jalr), so the table type takes void*. No other
 * layout is guessed. Body is m2c's verbatim. */

struct data_8015E698 {
    u16 unk0;
    u8 pad[0xB6];
    u16 unkB8;
};

typedef void (*callback_8015E698)(void *);
extern callback_8015E698 D_8018730C[];

void func_80147078(void *, s32);
void func_80159BE4(void *);
s32 func_80161208();

void func_8015E698(struct data_8015E698 *arg0) {
    if ((func_80161208() == 0) && (arg0->unkB8 & 0x8000)) {
        D_8018730C[arg0->unk0](arg0);
        func_80147078(arg0, 0);
        func_80159BE4(arg0);
    }
}
