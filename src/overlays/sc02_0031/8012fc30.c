/* SC02.CD FILE_031 / ov_SC02_031 retail span [8012FC30,8012FCA4).
 * Offset 0x7AD8 at overlay base 80128158. SHA256(span)=ba5b2d1016e78992d288c8fd45bf62ed46b081f9dd8b899415e469ab31a4a496.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/8012fc30.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
#include "psx_types.h"

/* HAND MODEL of func_8012FC30 (main_0012.s), decoded manually from
 * raw asm (NOT verified against retail; C89-gated only,
 * promotion requires an oracle MATCH): unconditionally sets byte
 * unkC1 = 0xA (sb in the beqz delay slot). When word unkB4 &
 * 0x400: calls 31B14(obj) (a0 set in the jal delay slot),
 * zeroes byte unkC2, calls B23C(obj) (unk98 = 0 in its jal delay
 * slot), calls 31A34(obj, 8), then 8002D4C8(0xA74, 0). Ends with
 * CA8(obj, 0x1A). */

struct obj_8012FC30 {
    u8 pad[0x98];
    u16 unk98;
    u8 pad2[0xB4 - 0x9A];
    s32 unkB4;
    u8 pad3[0xC1 - 0xB8];
    u8 unkC1;
    u8 unkC2;
};

extern void func_80131B14(void *arg0);
extern void func_8012B23C(void *arg0);
extern s32 func_80131A34(void *arg0, s32 arg1);
extern void func_8002D4C8(s32 arg0, s32 arg1);
extern void func_80131CA8(void *arg0, s32 arg1);

void func_8012FC30(struct obj_8012FC30 *arg0) {
    arg0->unkC1 = 0xA;
    if (arg0->unkB4 & 0x400) {
        func_80131B14(arg0);
        arg0->unkC2 = 0;
        arg0->unk98 = 0;
        func_8012B23C(arg0);
        func_80131A34(arg0, 8);
        func_8002D4C8(0xA74, 0);
    }
    func_80131CA8(arg0, 0x1A);
}
