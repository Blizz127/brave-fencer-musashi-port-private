/* SC02.CD FILE_031 / ov_SC02_031 retail span [80175414,80175454).
 * Offset 0x4D2BC at overlay base 80128158. SHA256(span)=f964a827c86a6b4cd52eacb9e6213c8c9afe39a5039afc17e37a2d23c5614029.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80175414.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
#include "psx_types.h"
typedef struct { u8 a, b; u8 pad[3]; u8 e, f; } G;
extern G D_8011F7A8;
void func_80175414(void) {
    if (D_8011F7A8.a == 1) {
        D_8011F7A8.a = 0;
        D_8011F7A8.e = 0xA;
        D_8011F7A8.b = 0;
        D_8011F7A8.f = 0x37;
    }
}
