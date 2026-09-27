/* SC02.CD FILE_031 / ov_SC02_031 retail span [8015ADB0,8015AE2C).
 * Offset 0x32C58 at overlay base 80128158. SHA256(span)=0a110a97958b630a17ea053311b01209cd3fe015a15f794a1e71d5ce20feac6e.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/8015adb0.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
#include "psx_types.h"

/* HAND MODEL from m2c draft of func_8015ADB0 (main_0012.s): NOT verified
 * against retail. C89-gated only; promotion requires an oracle MATCH.
 * m2c shape: arg0->unkA8 compared and stored. The disassembly moves
 * it as a byte (lbu/sb +0xA8), so the model declares one u8 at +0xA8
 * — the draft's own (u8) cast already pointed at a byte. The global
 * is a word RMW (lw/sw %lo(D_8011F730)). No other layout is guessed.
 * Body is m2c's verbatim. */

struct data_8015ADB0 {
    u8 pad[0xA8];
    u8 unkA8;
};

void func_801477E8(void *, s32);
void func_8014C010(void *, s32);
void func_80161124(void *);
extern s32 D_8011F730;
void func_80146CA0();

void func_8015ADB0(struct data_8015ADB0 *arg0) {
    if ((u8) arg0->unkA8 >= 0x19U) {
        arg0->unkA8 = 0x18U;
    }
    func_80161124(arg0);
    func_801477E8(arg0, 0xFFEE0000);
    func_8014C010(arg0, 2);
    D_8011F730 |= 1;
    func_80146CA0(arg0);
}
