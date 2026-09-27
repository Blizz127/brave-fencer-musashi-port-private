/* SC02.CD FILE_031 / ov_SC02_031 retail span [8015DB34,8015DB6C).
 * Offset 0x359DC at overlay base 80128158. SHA256(span)=3d85452a39f2705c3bdf04a2bc8467a437c4909852ec10dbd7914bc6ce0441b8.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/8015db34.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
#include "psx_types.h"

void func_8015DB6C(s32);                               /* static */
s32 func_80161104();                                /* static */

void func_8015DB34(s32 arg0) {
    if (func_80161104() != 0) {
        func_8015DB6C(arg0);
    }
}
