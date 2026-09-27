/* SC02.CD FILE_031 / ov_SC02_031 retail span [80174438,80174474).
 * Offset 0x4C2E0 at overlay base 80128158. SHA256(span)=dc3ad0042a734c792934057e7152222b2c079b88fedc1b373cba92232e8d1282.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80174438.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
#include "psx_types.h"
void func_80174474();
void func_80174684();
extern s32 D_80127508;
void func_80174438(s32 a0) {
    func_80174684(func_80174474);
    D_80127508 = a0;
}
