/* SC02.CD FILE_031 / ov_SC02_031 retail span [8016FD7C,8016FDB4).
 * Offset 0x47C24 at overlay base 80128158. SHA256(span)=3983b0a72f63efb62372e5547c1a669659e019547f5ab019bd36c425f5a1a1a3.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/8016fd7c.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
#include "psx_types.h"

void func_80171928(s32);                               /* static */
s32 func_80172658();                                /* static */

void func_8016FD7C(s32 arg0) {
    if (func_80172658() != 0) {
        func_80171928(arg0);
    }
}
