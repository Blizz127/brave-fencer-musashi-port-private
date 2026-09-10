/* SC02.CD FILE_031 / ov_SC02_031 retail span [80170A00,80170A48).
 * Offset 0x488A8 at overlay base 80128158. SHA256(span)=db08b5dee6a403d9547b8d27bbd9bafed2f781622a13df9b052846ad071550af.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80170a00.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
#include "psx_types.h"
extern void *D_8011F738;
extern s32 D_800D5934;
extern s32 D_80126B58;
void func_80170AD8();
void func_80171904();
void func_80170B48();
void func_80170A00(void) {
    D_8011F738 = &D_800D5934;
    func_80171904(func_80170AD8);
    func_80170B48(&D_80126B58);
}
