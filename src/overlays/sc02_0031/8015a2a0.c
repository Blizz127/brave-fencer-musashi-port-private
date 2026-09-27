/* SC02.CD FILE_031 / ov_SC02_031 retail span [8015A2A0,8015A2D8).
 * Offset 0x32148 at overlay base 80128158. SHA256(span)=8c46e70cfe5fa2c57d72b9b1588210a45e42806f71c5237025bbaa4438897041.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/8015a2a0.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
#include "psx_types.h"

void func_8015A2D8(s32);                               /* static */
s32 func_80161104();                                /* static */

void func_8015A2A0(s32 arg0) {
    if (func_80161104() != 0) {
        func_8015A2D8(arg0);
    }
}
