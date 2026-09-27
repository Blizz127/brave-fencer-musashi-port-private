/* SC02.CD FILE_031 / ov_SC02_031 retail span [8015309C,801530E4).
 * Offset 0x2AF44 at overlay base 80128158. SHA256(span)=e4aa8354ed5a6656e19fe5fa40a7740d050f18497d5c49fb800bfaed5e709b45.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/8015309c.c (recovery=c, -O2); the span is
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
void func_801530E4(s32);                               /* static */

void func_8015309C(s32 arg0) {
    func_8014E934();
    func_8014CC28(arg0);
    func_8014F3E8(arg0);
    func_801530E4(arg0);
    func_80146CA0(arg0);
}
