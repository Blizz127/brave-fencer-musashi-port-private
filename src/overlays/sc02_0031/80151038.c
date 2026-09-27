/* SC02.CD FILE_031 / ov_SC02_031 retail span [80151038,80151070).
 * Offset 0x28EE0 at overlay base 80128158. SHA256(span)=44d9076aa71e564ef0a3474aeff8c4cc360eef382840b254659496e2ed3945c2.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80151038.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
#include "psx_types.h"
void func_80151184();
extern s16 D_800B9A08;
void func_80151038(void *p) {
    s32 a2 = 0x18;
    if (D_800B9A08 == 0x30A0) {
        a2 = 0x30;
    }
    func_80151184(p, 0xC00C, a2);
}
