/* SC02 resident retail span [80170548,80170584). Offset 0x483F0 at base 80128158.
 * SHA256(span)=c64be7d8d573834e2988512f3a1e75b5e46ddcc257c19a3d863521000ffc63d7.
 * Words are the guest's loaded image (artifacts/sc02-resident-20260910).
 * Member-0012 C shape retargeted to this member: D_80181870->D_80188160.
 * Oracle MATCH re-earned against the resident image; Not MAIN10.
 */
/* Decompiled by m2c from main.s, then verified byte-exact
 * against retail by tools/match_function.py. Types and signatures are
 * whatever reproduces the bytes; they are not evidence of the
 * original declaration. */

#include "psx_types.h"
typedef void (*CB)();
extern CB D_80188160[];
typedef struct { u8 pad[534]; u8 idx; } T;
void func_80170548(T *p) {
    D_80188160[p->idx](p);
}
