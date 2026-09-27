/* SC02.CD FILE_031 / ov_SC02_031 retail span [80170FEC,80171028).
 * Offset 0x48E94 at overlay base 80128158. SHA256(span)=15a25f2f6dd819c390e2fef40f58baa754dfd9dad34e35d7258c6ec6b3cb4bed.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80170fec.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Decompiled by m2c from main.s, then verified byte-exact
 * against retail by tools/match_function.py. Types and signatures are
 * whatever reproduces the bytes; they are not evidence of the
 * original declaration. */

#include "psx_types.h"
void func_801719A4();
void func_80171990();
void func_80171028();
void func_80170FEC(void *p) {
    func_801719A4(p, 1);
    func_80171990(p);
    func_80171028(p);
}
