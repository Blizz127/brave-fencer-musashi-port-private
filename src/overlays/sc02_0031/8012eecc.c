/* SC02.CD FILE_031 / ov_SC02_031 retail span [8012EECC,8012EF34).
 * Offset 0x6D74 at overlay base 80128158. SHA256(span)=98655699b6efc9039998860ebd8d1fb8d9228f98061ebeea1dd12b431ae962a2.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/8012eecc.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
#include "psx_types.h"

/* Decompiled by m2c from main_0012.s, then verified byte-exact
 * against retail by tools/match_function.py. Types and signatures are
 * whatever reproduces the bytes; they are not evidence of the
 * original declaration. */

s32 func_8002A4FC();                                /* extern */

s32 func_8012EECC(s32 arg0) {
    return arg0 - ((arg0 * func_8002A4FC() * 0x64) / 7680);
}
