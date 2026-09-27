/* SC02.CD FILE_031 / ov_SC02_031 retail span [8016FB10,8016FB50).
 * Offset 0x479B8 at overlay base 80128158. SHA256(span)=38b94c950d357223e635c333631e1ff69874404115d0da1f08495016c404d6bb.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/8016fb10.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
#include "psx_types.h"
s32 func_80171CC4();
void func_80171990();
extern u8 D_8011F738;
void func_8016FB10(void *p) {
    if (func_80171CC4(p, &D_8011F738)) {
        func_80171990(p);
    }
}
