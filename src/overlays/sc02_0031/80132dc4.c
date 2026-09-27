/* SC02.CD FILE_031 / ov_SC02_031 retail span [80132DC4,80132E6C).
 * Offset 0xAC6C at overlay base 80128158. SHA256(span)=578670785d8c1b643f51c3da411965805774dd43f2a29b5d8ecc603f3e10a851.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80132dc4.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
#include "psx_types.h"

/* HAND MODEL of func_80132DC4 (main_0012.s), decoded manually from
 * raw asm (fully visible; NOT verified against retail; C89-gated
 * only, promotion requires an oracle MATCH): 3-arg void. Builds an
 * s16[3] on the stack: in[i] = a1[i] - s0 field (offsets +6/+0xA/
 * +0xE; the third sh is the jal delay slot, executed before the
 * callee runs). Calls func_80047E98(in, out) where out is a second
 * stack s16[3] (a1 = sp+0x18, never pre-stored: pure callee output),
 * then s0+0x10/0x14/0x18 = out[i] * arg2 via mult/mflo, modelled as
 * plain C * (low 32 bits, func_8012D664 precedent). New callee typed
 * from raw asm (2 words: in-vector, out-vector). */

struct in_80132DC4 {
    u16 unk0;
    u16 unk2;
    u16 unk4;
};

struct obj_80132DC4 {
    u8 pad[0x6];
    u16 unk6;
    u8 pad2[0x2];
    u16 unkA;
    u8 pad3[0x2];
    u16 unkE;
    s32 unk10;
    s32 unk14;
    s32 unk18;
};

extern void func_80047E98(s16 *arg0, s16 *arg1);

void func_80132DC4(struct obj_80132DC4 *arg0, struct in_80132DC4 *arg1, s32 arg2) {
    s16 in[3];
    s16 out[3];

    in[0] = arg1->unk0 - arg0->unk6;
    in[1] = arg1->unk2 - arg0->unkA;
    in[2] = arg1->unk4 - arg0->unkE;
    func_80047E98(in, out);
    arg0->unk10 = out[0] * arg2;
    arg0->unk14 = out[1] * arg2;
    arg0->unk18 = out[2] * arg2;
}
