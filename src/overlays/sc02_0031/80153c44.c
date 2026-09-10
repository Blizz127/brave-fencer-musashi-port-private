/* SC02.CD FILE_031 / ov_SC02_031 retail span [80153C44,80153C74).
 * Offset 0x2BAEC at overlay base 80128158. SHA256(span)=4fa226182427abf4b4e57d25c51d8a9569a7233ce769122501c3ffe1852a94c9.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80153c44.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
#include "psx_types.h"
void func_80153C74();
extern s16 D_8011DB18;
void func_80153C44(void *a0, void *a1, s32 a2) {
    func_80153C74(a0, a1, a2);
    D_8011DB18 = a2;
}
