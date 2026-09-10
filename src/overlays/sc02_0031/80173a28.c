/* SC02.CD FILE_031 / ov_SC02_031 retail span [80173A28,80173A60).
 * Offset 0x4B8D0 at overlay base 80128158. SHA256(span)=3574479f5a8ec3c9147b3331cb8065cc70c6191fcfe7229118b851974b28f928.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80173a28.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
#include "psx_types.h"
void func_80173A60();
extern s32 D_8012750C;
void func_80173A28(s32 a0, s32 a1, s32 a2, s32 a3, s32 a4, s32 a5) {
    func_80173A60(a0, a1, a2, a3, a4);
    D_8012750C = a5;
}
