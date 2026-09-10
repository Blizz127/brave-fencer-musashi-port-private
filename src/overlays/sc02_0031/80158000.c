/* SC02.CD FILE_031 / ov_SC02_031 retail span [80158000,80158038).
 * Offset 0x2FEA8 at overlay base 80128158. SHA256(span)=12075c69894b4a002d5262801018f48d7b2f4f10aa9752a37d8f8c9bb1ce59ea.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80158000.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
#include "psx_types.h"

void func_80158038(s32);                               /* static */
s32 func_80161104();                                /* static */

void func_80158000(s32 arg0) {
    if (func_80161104() != 0) {
        func_80158038(arg0);
    }
}
