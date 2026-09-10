/* SC02 resident retail span [80164BA0,80164BDC). Offset 0x3CA48 at base 80128158.
 * SHA256(span)=e0e8364213b00f74b74f394ff72d93a9b31f81d1aee39466d1d8fd1938ba3007.
 * Words are the guest's loaded image (artifacts/sc02-resident-20260910).
 * Member-0012 C shape retargeted to this member: D_80180F90->D_80187880.
 * Oracle MATCH re-earned against the resident image; Not MAIN10.
 */
/* Decompiled by m2c from main.s, then verified byte-exact
 * against retail by tools/match_function.py. Types and signatures are
 * whatever reproduces the bytes; they are not evidence of the
 * original declaration. */

#include "psx_types.h"
typedef void (*CB)();
extern CB D_80187880[];
typedef struct { u8 pad[2]; u16 idx; } T;
void func_80164BA0(T *p) {
    D_80187880[p->idx](p);
}
