/* SC02.CD FILE_031 / ov_SC02_031 retail span [80160ACC,80160B00).
 * Offset 0x38974 at overlay base 80128158. SHA256(span)=9e806c3bd48acced0fba3efb0eba94cb72c4200afafb25d4d5230064eec18034.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80160acc.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Decompiled by m2c from main.s, then verified byte-exact
 * against retail by tools/match_function.py. Types and signatures are
 * whatever reproduces the bytes; they are not evidence of the
 * original declaration. */

#include "psx_types.h"
void func_80147078();
void func_80160BB4();
void func_80160ACC(void *p) {
    func_80147078(p, 29);
    func_80160BB4(p);
}
