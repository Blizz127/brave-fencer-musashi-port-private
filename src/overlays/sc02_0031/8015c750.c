/* SC02.CD FILE_031 / ov_SC02_031 retail span [8015C750,8015C788).
 * Offset 0x345F8 at overlay base 80128158. SHA256(span)=76ad9b0235139c6845381e719d49d1e3c24be2cee29efba1eaff576fb1784a4c.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/8015c750.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
#include "psx_types.h"

void func_8015C788(s32);                               /* static */
s32 func_80161104();                                /* static */

void func_8015C750(s32 arg0) {
    if (func_80161104() != 0) {
        func_8015C788(arg0);
    }
}
