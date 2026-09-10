/* SC02.CD FILE_031 / ov_SC02_031 retail span [801709B8,80170A00).
 * Offset 0x48860 at overlay base 80128158. SHA256(span)=8bff7fbada11dbcf95c79c908ea4bd2da77adc09c8ff1b22858c08f7be6922e1.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/801709b8.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
#include "psx_types.h"
extern void *D_8011F738;
extern s32 D_800D599C;
extern s32 D_80126B58;
void func_80170AD8();
void func_80171904();
void func_80170B48();
void func_801709B8(void) {
    D_8011F738 = &D_800D599C;
    func_80171904(func_80170AD8);
    func_80170B48(&D_80126B58);
}
