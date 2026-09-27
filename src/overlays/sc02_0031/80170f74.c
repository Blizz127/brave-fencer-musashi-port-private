/* SC02.CD FILE_031 / ov_SC02_031 retail span [80170F74,80170FB0).
 * Offset 0x48E1C at overlay base 80128158. SHA256(span)=b3c0257e311db777e5605023d651a1bbed02e68cdd406609a1a5d6546761f245.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80170f74.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
#include "psx_types.h"

void func_80029124(s32, s32);                            /* extern */
void func_80171928(s32);                               /* static */
extern s32 D_8011F738;

void func_80170F74(s32 arg0) {
    func_80029124(D_8011F738, 1);
    func_80171928(arg0);
}
