/* SC02.CD FILE_031 / ov_SC02_031 retail span [8012A758,8012A79C).
 * Offset 0x2600 at overlay base 80128158. SHA256(span)=71dbee9872f3c01e195a53041714c9d9bff86b59037b0f98f1bf6c6d8431195d.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/8012a758.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
#include "psx_types.h"

/* HAND MODEL from m2c draft of func_8012A758 (main_0012.s): NOT
 * verified against retail. C89-gated only; promotion requires an
 * oracle MATCH. Call chain grounded from raw asm: A7D4(sp+0x10, sp+0x18) then A79C with the same pair. */

struct pair_8012A7D4 {
    s16 unk0;
    s16 unk2;
    s16 unk4;
};

void func_8012A7D4(struct pair_8012A7D4 *arg0, struct pair_8012A7D4 *arg1);
s16 func_8012A79C(struct pair_8012A7D4 *arg0, struct pair_8012A7D4 *arg1);

s16 func_8012A758(void) {
    struct pair_8012A7D4 sp10;
    struct pair_8012A7D4 sp18;

    func_8012A7D4(&sp10, &sp18);
    return func_8012A79C(&sp10, &sp18);
}
