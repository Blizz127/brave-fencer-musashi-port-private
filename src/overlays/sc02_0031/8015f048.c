/* SC02.CD FILE_031 / ov_SC02_031 retail span [8015F048,8015F080).
 * Offset 0x36EF0 at overlay base 80128158. SHA256(span)=3bd1f17f5d10efafb6a26bc945bd85c51410fe17ad4a9af8928f3dc79558cf02.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/8015f048.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
#include "psx_types.h"

void func_8015F080(s32);                               /* static */
s32 func_80161104();                                /* static */

void func_8015F048(s32 arg0) {
    if (func_80161104() != 0) {
        func_8015F080(arg0);
    }
}
