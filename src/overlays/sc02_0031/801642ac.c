/* SC02.CD FILE_031 / ov_SC02_031 retail span [801642AC,8016432C).
 * Offset 0x3C154 at overlay base 80128158. SHA256(span)=a8a73b7d559aedc0b0ee7254c8db7660970b8a9886b1c189514cafcdffe90743.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/801642ac.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
#include "psx_types.h"

/* HAND MODEL from m2c draft of func_801642AC (main_0012.s): NOT verified
 * against retail. C89-gated only; promotion requires an oracle MATCH.
 * m2c shapes: arg0->unk4C and arg0 + 4 on a void*. The disassembly
 * loads the member as a word (lw 0x4C($s1)) and passes arg0+4 as a
 * byte address (addiu $a1, $s1, 0x4), so the model declares one s32
 * at +0x4C and spells the +4 address with a (u8 *) cast — the same
 * addiu either way. Callee declarations follow the repo pipeline
 * convention (unchecked prototypes; s32 return where slti consumes
 * the result). Body is m2c's verbatim. */

struct data_801642AC {
    u8 pad[0x4C];
    s32 unk4C;
};

void func_80146CA0(void *);
void func_80146E90(void *, s32);
s32 func_80146E98(void *);
void func_80147324();
void func_80163764(void *);
void func_80164418();
s32 func_80013328();

void func_801642AC(struct data_801642AC *arg0) {
    s32 temp_s0;

    temp_s0 = arg0->unk4C;
    func_80164418();
    if ((func_80013328(temp_s0 + 4, (void *) ((u8 *) arg0 + 4)) < 0x28) || (func_80146E98(arg0) != 0)) {
        func_80146E90(arg0, 8);
        func_80147324(0x44A);
        func_80146CA0(arg0);
    }
    func_80163764(arg0);
}
