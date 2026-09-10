/* SC02.CD FILE_031 / ov_SC02_031 retail span [80157580,801575E4).
 * Offset 0x2F428 at overlay base 80128158. SHA256(span)=12f107eaea8af7ce70aff1dfc83d9f7c88bceaf6bbac4cb61fb60bea081dbb15.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80157580.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
#include "psx_types.h"

/* Decompiled by m2c from main_0012.s, then verified byte-exact
 * against retail by tools/match_function.py. Types and signatures are
 * whatever reproduces the bytes; they are not evidence of the
 * original declaration. */

s32 func_8014CC28();                                /* static */
s32 func_8014F3E8(s32);                             /* static */
void func_801575E4(s32);                               /* static */
void func_8015BDD0(s32);                               /* static */

void func_80157580(s32 arg0) {
    s32 temp_s1;

    temp_s1 = func_8014CC28();
    if ((func_8014F3E8(arg0) == 0) && (temp_s1 == 0)) {
        func_8015BDD0(arg0);
        return;
    }
    func_801575E4(arg0);
}
