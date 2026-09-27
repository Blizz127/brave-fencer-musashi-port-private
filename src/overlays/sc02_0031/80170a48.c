/* SC02.CD FILE_031 / ov_SC02_031 retail span [80170A48,80170A90).
 * Offset 0x488F0 at overlay base 80128158. SHA256(span)=a58845b2004e5c37e6c1d23126fccc8cc08be9329bc9f1449d951615e73d7e3a.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80170a48.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
#include "psx_types.h"
extern void *D_8011F738;
extern s32 D_800D5DA8;
extern s32 D_80126B58;
void func_80170AD8();
void func_80171904();
void func_80170B48();
void func_80170A48(void) {
    D_8011F738 = &D_800D5DA8;
    func_80171904(func_80170AD8);
    func_80170B48(&D_80126B58);
}
