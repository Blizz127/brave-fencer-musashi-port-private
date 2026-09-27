/* SC02.CD FILE_031 / ov_SC02_031 retail span [8016FA44,8016FA84).
 * Offset 0x478EC at overlay base 80128158. SHA256(span)=58167613ffd39c0353d9be2893f59ba03191fa63fccfdb8b6645354122ed1839.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/8016fa44.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
#include "psx_types.h"
s32 func_80171C64();
void func_80171928();
extern u8 D_8011F738;
void func_8016FA44(void *p) {
    if (func_80171C64(p, D_8011F738)) {
        func_80171928(p);
    }
}
