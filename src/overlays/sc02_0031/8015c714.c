/* SC02 resident retail span [8015C714,8015C750). Offset 0x345BC at base 80128158.
 * SHA256(span)=1e93c33afe18173ca7414e63e4d7da17315c3f118225247c6b4ff3da55e5fd04.
 * Words are the guest's loaded image (artifacts/sc02-resident-20260910).
 * Member-0012 C shape retargeted to this member: D_80180BA8->D_80187498.
 * Oracle MATCH re-earned against the resident image; Not MAIN10.
 */
/* Decompiled by m2c from main.s, then verified byte-exact
 * against retail by tools/match_function.py. Types and signatures are
 * whatever reproduces the bytes; they are not evidence of the
 * original declaration. */

#include "psx_types.h"
typedef void (*CB)();
extern CB D_80187498[];
typedef struct { u8 pad[2]; u16 idx; } T;
void func_8015C714(T *p) {
    D_80187498[p->idx](p);
}
