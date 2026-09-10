/* SC02.CD FILE_031 / ov_SC02_031 retail span [8015DE94,8015DECC).
 * Offset 0x35D3C at overlay base 80128158. SHA256(span)=25f054bb79544d537a2a4825295aef9e054964d1e776fa34e83304f9ab18e305.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/8015de94.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
#include "psx_types.h"

void func_8015DECC(s32);                               /* static */
s32 func_80161104();                                /* static */

void func_8015DE94(s32 arg0) {
    if (func_80161104() != 0) {
        func_8015DECC(arg0);
    }
}
