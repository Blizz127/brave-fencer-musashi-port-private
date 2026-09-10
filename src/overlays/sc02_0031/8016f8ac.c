/* SC02.CD FILE_031 / ov_SC02_031 retail span [8016F8AC,8016F8E4).
 * Offset 0x47754 at overlay base 80128158. SHA256(span)=77126bb2f33eb31edfa94eccc5edf80b48af6b64638a4dd30f61a618de834e92.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/8016f8ac.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
#include "psx_types.h"
extern s32 D_8011F738;
void func_80172358();
void func_80171928();
void func_8016F8AC(void *p) {
    func_80172358(p, &D_8011F738);
    func_80171928(p);
}
