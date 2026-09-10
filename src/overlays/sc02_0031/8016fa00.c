/* SC02.CD FILE_031 / ov_SC02_031 retail span [8016FA00,8016FA44).
 * Offset 0x478A8 at overlay base 80128158. SHA256(span)=01f757a07326757868a65a5de2231d0e3f49f8a0d4b21bcf16c686d891b71164.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/8016fa00.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Decompiled by m2c from main.s, then verified byte-exact
 * against retail by tools/match_function.py. Types and signatures are
 * whatever reproduces the bytes; they are not evidence of the
 * original declaration. */

#include "psx_types.h"
void func_801719A4();
void func_80171B44();
void func_80171990();
void func_8016FA44();
void func_8016FA00(void *p) {
    func_801719A4(p, 1);
    func_80171B44(p);
    func_80171990(p);
    func_8016FA44(p);
}
