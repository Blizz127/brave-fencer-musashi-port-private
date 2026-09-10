/* SC02.CD FILE_031 / ov_SC02_031 retail span [80165A20,80165A50).
 * Offset 0x3D8C8 at overlay base 80128158. SHA256(span)=ec7f0b45717997b37d781dd16018c4b50688a626f8d38a6e6123878d05b9f6c4.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80165a20.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
#include "psx_types.h"

void func_80165A50(s32);                               /* static */
void func_80165A78();                                  /* static */

void func_80165A20(s32 arg0) {
    func_80165A78();
    func_80165A50(arg0);
}
