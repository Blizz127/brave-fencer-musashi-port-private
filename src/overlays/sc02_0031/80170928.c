/* SC02.CD FILE_031 / ov_SC02_031 retail span [80170928,80170970).
 * Offset 0x487D0 at overlay base 80128158. SHA256(span)=0834dc9913fe01504f0f7aadb53ac080702dc3f89a4fea1f28e53bca2cb39a62.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80170928.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
#include "psx_types.h"
extern void *D_8011F738;
extern s32 D_800D5A34;
extern s32 D_80126B58;
void func_80170AD8();
void func_80171904();
void func_80170B48();
void func_80170928(void) {
    D_8011F738 = &D_800D5A34;
    func_80171904(func_80170AD8);
    func_80170B48(&D_80126B58);
}
