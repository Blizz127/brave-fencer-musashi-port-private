/* SC02.CD FILE_031 / ov_SC02_031 retail span [8015C08C,8015C0C4).
 * Offset 0x33F34 at overlay base 80128158. SHA256(span)=bd8a9dcfc6b17345c27db5168d38ecd346c5daa3b5f62ac206fb8806bb4fa555.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/8015c08c.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
#include "psx_types.h"

void func_8015C0C4(s32);                               /* static */
s32 func_80161104();                                /* static */

void func_8015C08C(s32 arg0) {
    if (func_80161104() != 0) {
        func_8015C0C4(arg0);
    }
}
