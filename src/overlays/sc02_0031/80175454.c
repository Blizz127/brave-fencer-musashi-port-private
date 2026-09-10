/* SC02.CD FILE_031 / ov_SC02_031 retail span [80175454,80175494).
 * Offset 0x4D2FC at overlay base 80128158. SHA256(span)=e70a5b1d2eb9412a3231f0245b409acf1d912db4a19976fe3938f1678bf58b69.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80175454.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
#include "psx_types.h"
typedef struct { u8 a, b; u8 pad[3]; u8 e, f; } G;
extern G D_8011F7A8;
void func_80175454(void) {
    if (D_8011F7A8.a == 0) {
        D_8011F7A8.a = 1;
        D_8011F7A8.b = 0;
        D_8011F7A8.e = 0xA;
        D_8011F7A8.f = 0;
    }
}
