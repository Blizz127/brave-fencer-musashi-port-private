/* SC02.CD FILE_031 / ov_SC02_031 retail span [8016FC24,8016FC64).
 * Offset 0x47ACC at overlay base 80128158. SHA256(span)=85be96715c583f978fb6f12d798aa6da473f8a9af7d853dfa18c87699c8424a1.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/8016fc24.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
#include "psx_types.h"
s32 func_80171B4C();
void func_80171990();
extern u8 D_8011F738;
void func_8016FC24(void *p) {
    if (func_80171B4C(p, D_8011F738)) {
        func_80171990(p);
    }
}
