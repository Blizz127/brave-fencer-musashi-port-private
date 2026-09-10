/* SC02.CD FILE_031 / ov_SC02_031 retail span [801742E0,80174318).
 * Offset 0x4C188 at overlay base 80128158. SHA256(span)=c590851bf15d37f1a120c42903013880a068b2d3d341f4715ab2f0f685f9e91a.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/801742e0.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
#include "psx_types.h"

void func_80147060();                                  /* static */
void func_80171A1C(s32);                               /* static */
void func_80174318(s32);                               /* static */

void func_801742E0(s32 arg0) {
    func_80147060();
    func_80171A1C(arg0);
    func_80174318(arg0);
}
