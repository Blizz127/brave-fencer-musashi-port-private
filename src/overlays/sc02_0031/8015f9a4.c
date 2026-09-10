/* SC02.CD FILE_031 / ov_SC02_031 retail span [8015F9A4,8015FA24).
 * Offset 0x3784C at overlay base 80128158. SHA256(span)=ee31b1018f9100caea736661df5b5568e94b3c200a2de873111f3745f0cc5cf3.
 * Differs from the registry-verified MAIN member 0012 carve in exactly one
 * data reference: D_80180A1C here is D_801812A4 (+0x888 member
 * data-block shift). Oracle MATCH re-earned on this file; Not MAIN10.
 */
#include "psx_types.h"

/* HAND MODEL from m2c draft of func_8015F9A4 (main_0012.s): NOT verified
 * against retail. C89-gated only; promotion requires an oracle MATCH.
 * m2c shapes: arg0->unkB8 and arg0->unk0 on a void*, plus a callback
 * table call `*(D_801812A4 + (unk0 * 4))()`. The disassembly loads both
 * members as halfwords (lhu +0xB8 and +0x0) and calls the table via
 * sll-2/addu/lw/jalr, so the model declares two u16 members and an
 * extern table of unchecked-prototype function pointers indexed by
 * unk0. No other layout is guessed. Body is m2c's verbatim. */

struct data_8015F9A4 {
    u16 unk0;
    u8 pad[0xB6];
    u16 unkB8;
};

typedef void (*callback_8015F9A4)();
extern callback_8015F9A4 D_801812A4[];

void func_80147078(void *, s32);
void func_80159B70(void *);
void func_80161208(void *);

void func_8015F9A4(struct data_8015F9A4 *arg0) {
    if (arg0->unkB8 & 0x8000) {
        D_801812A4[arg0->unk0]();
        func_80147078(arg0, 0);
        func_80159B70(arg0);
        return;
    }
    func_80161208(arg0);
}
