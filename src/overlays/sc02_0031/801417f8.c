/* SC02.CD FILE_031 / ov_SC02_031 retail span [801417F8,80141874).
 * Offset 0x196A0 at overlay base 80128158. SHA256(span)=16b19deba3e9754b853aac051c0018306638f9f311f6cced62497bab1fecb419.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/801417f8.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
#include "psx_types.h"

/* Decompiled by m2c from main_0012.s, then verified byte-exact
 * against retail by tools/match_function.py. Types and signatures are
 * whatever reproduces the bytes; they are not evidence of the
 * original declaration. */

void func_800D2624();                                  /* extern */
extern u16 D_800B9A02;
extern u8 D_800B9A15;
extern u8 D_800B9A16;
extern u16 D_80115112;
extern u16 D_80115114;

void func_801417F8(void) {
    if ((D_800B9A15 == 0) || (D_800B9A16 != 0)) {
        if (D_80115114 == (D_800B9A02 ^ 1)) {
            func_800D2624();
            return;
        }
        D_80115112 += 1;
    }
}
