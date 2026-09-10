/* SC02.CD FILE_031 / ov_SC02_031 retail span [80172DE8,80172E20).
 * Offset 0x4AC90 at overlay base 80128158. SHA256(span)=8f0d91929b63bc9ebce5f5866d0308e18fd1bff566c85d28f64340ad73814e92.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80172de8.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
#include "psx_types.h"

void func_80147060();                                  /* static */
void func_80171A1C(s32);                               /* static */
void func_80172E20(s32);                               /* static */

void func_80172DE8(s32 arg0) {
    func_80147060();
    func_80171A1C(arg0);
    func_80172E20(arg0);
}
