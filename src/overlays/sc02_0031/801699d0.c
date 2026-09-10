/* SC02.CD FILE_031 / ov_SC02_031 retail span [801699D0,80169A4C).
 * Offset 0x41878 at overlay base 80128158. SHA256(span)=2aeb80a4d36bd304f2e8705fa948350326320e93bdad663aac737089eb4c063d.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/801699d0.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
#include "psx_types.h"

/* HAND MODEL from m2c draft of func_801699D0 (main_0012.s): NOT verified
 * against retail. C89-gated only; promotion requires an oracle MATCH.
 * m2c shapes: arg0->unk1C/unk30/unk14 on a void*, plus arg0 + 0x38.
 * The disassembly touches the members as words (lw/sw +0x1C/+0x30/
 * +0x14) and computes the address with a byte addiu, so the model
 * declares three s32 members and casts for the +0x38 address.
 * CORRECTION to the draft: the func_80169A4C call passes TWO
 * arguments — $a0 still holds arg0 at the jal (nothing clobbers it
 * after entry) while $a1 gets arg0+0x38. The draft passed only the
 * second. Callee declarations follow the repo pipeline convention.
 * Otherwise the body is m2c's verbatim. */

struct data_801699D0 {
    u8 pad[0x14];
    s32 unk14;
    u8 pad2[0x4];
    s32 unk1C;
    u8 pad3[0x10];
    s32 unk30;
};

void func_80146C3C(void *);
void func_80169A4C();
void func_800D22E4();

void func_801699D0(struct data_801699D0 *arg0) {
    s32 temp_v1;

    temp_v1 = arg0->unk1C;
    if (temp_v1 < 0xF) {
        arg0->unk30 = (s32) (0xC0 - (temp_v1 * 8));
        func_80169A4C(arg0, (void *) ((u8 *) arg0 + 0x38));
        func_800D22E4(arg0);
        arg0->unk14 = (s32) (arg0->unk14 + 0x10000);
        arg0->unk1C = (s32) (arg0->unk1C + 1);
        return;
    }
    func_80146C3C(arg0);
}
