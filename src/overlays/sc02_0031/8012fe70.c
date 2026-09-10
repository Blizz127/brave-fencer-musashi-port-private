/* SC02.CD FILE_031 / ov_SC02_031 retail span [8012FE70,8012FF00).
 * Offset 0x7D18 at overlay base 80128158. SHA256(span)=9845e2af3b1462b453f3845cb2f28a86c3b29fd8afe86f18f3dceb9559e15fcc.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/8012fe70.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
#include "psx_types.h"

/* HAND MODEL of func_8012FE70 (main_0012.s), decoded manually from
 * raw asm (0x90 bytes; NOT verified against retail; C89-gated
 * only, promotion requires an oracle MATCH): FCC4-family with
 * unkC1 = 9: word unkC4 & 2 sets unkC1 = 1 and ends with
 * CA8(obj, 3); word unkC4 & 1 calls 31E00(obj, 1) and returns;
 * word unkB4 & 0x200 calls 80131170(obj, 0, 0) (both extra args
 * zeroed in the surrounding delay slots, a0 pass-through), then
 * ends with CA8(obj, 0x1E). */

struct obj_8012FE70 {
    u8 pad[0xB4];
    s32 unkB4;
    u8 pad2[0xC1 - 0xB8];
    u8 unkC1;
    u8 pad3[0xC4 - 0xC2];
    s32 unkC4;
};

extern void func_80131E00(void *arg0, s32 arg1);
extern void func_80131170(void *arg0, void *arg1, s32 arg2);
extern void func_80131CA8(void *arg0, s32 arg1);

void func_8012FE70(struct obj_8012FE70 *arg0) {
    arg0->unkC1 = 9;
    if (arg0->unkC4 & 2) {
        arg0->unkC1 = 1;
        func_80131CA8(arg0, 3);
        return;
    }
    if (arg0->unkC4 & 1) {
        func_80131E00(arg0, 1);
        return;
    }
    if (arg0->unkB4 & 0x200) {
        func_80131170(arg0, 0, 0);
    }
    func_80131CA8(arg0, 0x1E);
}
