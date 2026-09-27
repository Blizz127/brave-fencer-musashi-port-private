/* SC02.CD FILE_031 / ov_SC02_031 retail span [80142740,80142778).
 * Offset 0x1A5E8 at overlay base 80128158. SHA256(span)=b2881956db37839631c48612d4834d823f6955e9ac9c55461c5c4b64698456b5.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80142740.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
#include "psx_types.h"

/* Decompiled by m2c from main_0012.s, then verified byte-exact
 * against retail by tools/match_function.py. Types and signatures are
 * whatever reproduces the bytes; they are not evidence of the
 * original declaration. */

void func_8012AD50(s32);                               /* static */
s32 func_8012BEE8();                                /* static */

void func_80142740(s32 arg0) {
    if (func_8012BEE8() != 0) {
        func_8012AD50(arg0);
    }
}
