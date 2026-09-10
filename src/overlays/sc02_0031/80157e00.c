/* SC02.CD FILE_031 / ov_SC02_031 retail span [80157E00,80157E38).
 * Offset 0x2FCA8 at overlay base 80128158. SHA256(span)=65176389459e8e5d4f4c6c88d17779c101e200dc69fd46d60b87d99222d3e763.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80157e00.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
#include "psx_types.h"

void func_80157E38(s32);                               /* static */
s32 func_80161104();                                /* static */

void func_80157E00(s32 arg0) {
    if (func_80161104() != 0) {
        func_80157E38(arg0);
    }
}
