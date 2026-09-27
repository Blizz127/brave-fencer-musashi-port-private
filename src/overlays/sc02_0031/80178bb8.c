/* SC02.CD FILE_031 / ov_SC02_031 retail span [80178BB8,80178BF8).
 * Offset 0x50A60 at overlay base 80128158. SHA256(span)=c9525716a2e2addf46ee3db3fafb60bf27ca1336f336348b1f79113bc926df0c.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80178bb8.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
#include "psx_types.h"

void func_80178BF8();                                  /* static */
void func_80178CBC(s32, s32);                            /* static */

void func_80178BB8(s32 arg0, s32 arg1) {
    func_80178BF8();
    func_80178CBC(arg0, arg1);
}
