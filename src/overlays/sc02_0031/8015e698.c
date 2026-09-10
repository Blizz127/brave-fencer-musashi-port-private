/* SC02.CD FILE_031 / ov_SC02_031 retail span [8015E698,8015E714).
 * Offset 0x36540 at overlay base 80128158. SHA256(span)=accc029ab57338f72cdd15549084ae289e8ef5072c400141a2913abc232f9024.
 * Differs from the registry-verified MAIN member 0012 carve in exactly one
 * data reference: D_80180A1C here is D_801812A4 (+0x888 member
 * data-block shift). Oracle MATCH re-earned on this file; Not MAIN10.
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
extern callback_8015E698 D_801812A4[];

void func_80147078(void *, s32);
void func_80159BE4(void *);
s32 func_80161208();

void func_8015E698(struct data_8015E698 *arg0) {
    if ((func_80161208() == 0) && (arg0->unkB8 & 0x8000)) {
        D_801812A4[arg0->unk0](arg0);
        func_80147078(arg0, 0);
        func_80159BE4(arg0);
    }
}
