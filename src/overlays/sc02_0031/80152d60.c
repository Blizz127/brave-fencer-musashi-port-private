/* SC02.CD FILE_031 / ov_SC02_031 retail span [80152D60,80152DA8).
 * Offset 0x2AC08 at overlay base 80128158. SHA256(span)=37edf317af46d54d020757d1d1228000da68f223059cc9914b8228bbd0e6938f.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80152d60.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
#include "psx_types.h"

/* Decompiled by m2c from main_0012.s, then verified byte-exact
 * against retail by tools/match_function.py. Types and signatures are
 * whatever reproduces the bytes; they are not evidence of the
 * original declaration. */

void func_80146CA0(s32);                               /* static */
void func_8014CC28(s32);                               /* static */
void func_8014E934();                                  /* static */
void func_8014F3E8(s32);                               /* static */
void func_80152DA8(s32);                               /* static */

void func_80152D60(s32 arg0) {
    func_8014E934();
    func_8014CC28(arg0);
    func_8014F3E8(arg0);
    func_80152DA8(arg0);
    func_80146CA0(arg0);
}
