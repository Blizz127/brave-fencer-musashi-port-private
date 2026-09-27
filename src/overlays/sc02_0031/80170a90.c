/* SC02.CD FILE_031 / ov_SC02_031 retail span [80170A90,80170AD8).
 * Offset 0x48938 at overlay base 80128158. SHA256(span)=8de90190502936ef320d3684a6fc8b26f757963a54a1db4b70acb1430382f196.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80170a90.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
#include "psx_types.h"
extern void *D_8011F738;
extern s32 D_800D5DC0;
extern s32 D_80126B58;
void func_80170AD8();
void func_80171904();
void func_80170B48();
void func_80170A90(void) {
    D_8011F738 = &D_800D5DC0;
    func_80171904(func_80170AD8);
    func_80170B48(&D_80126B58);
}
