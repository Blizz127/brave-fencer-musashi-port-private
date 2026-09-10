/* SC02.CD FILE_031 / ov_SC02_031 retail span [8016F494,8016F4C4).
 * Offset 0x4733C at overlay base 80128158. SHA256(span)=117a1f082a7a48dc39ef418f78c73e9bedec16e49984f48ae6019f35571a54e4.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/8016f494.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
#include "psx_types.h"

void func_8016F4C4(s32);                               /* static */
void func_80175414();                                  /* static */

void func_8016F494(s32 arg0) {
    func_80175414();
    func_8016F4C4(arg0);
}
