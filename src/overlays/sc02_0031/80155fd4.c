/* SC02.CD FILE_031 / ov_SC02_031 retail span [80155FD4,80155FF8).
 * Offset 0x2DE7C at overlay base 80128158. SHA256(span)=9bdb9a4425c92e9c4a1ecd5ac1c15bda35b852a5af93994a415595f7acd257b2.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80155fd4.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
#include "psx_types.h"
void func_80155FF8();
void func_80155FD4(void *p, s32 a1) {
    func_80155FF8(p, a1 | 0x20000);
}
