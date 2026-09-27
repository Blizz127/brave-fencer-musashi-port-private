/* SC02.CD FILE_031 / ov_SC02_031 retail span [8012F1A4,8012F214).
 * Offset 0x704C at overlay base 80128158. SHA256(span)=3b5a821c033fa09d8badfd75b9cf44675df9aab151383d3f45f98af15dd92487.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/8012f1a4.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
#include "psx_types.h"

/* HAND MODEL of func_8012F1A4 (main_0012.s), decoded manually from
 * raw asm (0x70 bytes; NOT verified against retail; C89-gated
 * only, promotion requires an oracle MATCH): calls 800484EC with
 * no arguments, then accumulates (arg0 words +0x14/+0x18/+0x1C
 * << 16) into arg2 words +0/+4/+8 (lw/sll/addu/sw). The middle
 * argument is never read (callers pass a scratch buffer); kept
 * as an explicit unused parameter. */

struct in_8012F1A4 {
    u8 pad[0x14];
    s32 unk14;
    s32 unk18;
    s32 unk1C;
};

struct acc_8012F1A4 {
    s32 unk0;
    s32 unk4;
    s32 unk8;
};

extern void func_800484EC(void);

void func_8012F1A4(struct in_8012F1A4 *arg0, void *unused, struct acc_8012F1A4 *arg2) {
    (void) unused;
    func_800484EC();
    arg2->unk0 += arg0->unk14 << 16;
    arg2->unk4 += arg0->unk18 << 16;
    arg2->unk8 += arg0->unk1C << 16;
}
