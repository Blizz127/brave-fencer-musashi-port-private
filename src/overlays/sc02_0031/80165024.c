/* SC02.CD FILE_031 / ov_SC02_031 retail span [80165024,80165064).
 * Offset 0x3CECC at overlay base 80128158. SHA256(span)=8b0d4e0600f155603674295f32f90d47c655f1147c1d311edaae6038456da94f.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80165024.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
#include "psx_types.h"

void func_80146CA0(s32);                               /* static */
s32 func_80146E98();                                /* static */
void func_801651B8(s32);                               /* static */

void func_80165024(s32 arg0) {
    if (func_80146E98() != 0) {
        func_80146CA0(arg0);
    }
    func_801651B8(arg0);
}
