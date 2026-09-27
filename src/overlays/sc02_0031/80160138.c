/* SC02 resident retail span [80160138,80160174). Offset 0x37FE0 at base 80128158.
 * SHA256(span)=20515e702c963f38365380fe714d59787d3e91a804bd595ca5eba99857dbdf32.
 * Words are the guest's loaded image (artifacts/sc02-resident-20260910).
 * Member-0012 C shape retargeted to this member: D_80180DF4->D_801876E4.
 * Oracle MATCH re-earned against the resident image; Not MAIN10.
 */
/* Decompiled by m2c from main.s, then verified byte-exact
 * against retail by tools/match_function.py. Types and signatures are
 * whatever reproduces the bytes; they are not evidence of the
 * original declaration. */

#include "psx_types.h"
typedef void (*CB)();
extern CB D_801876E4[];
typedef struct { u8 pad[2]; u16 idx; } T;
void func_80160138(T *p) {
    D_801876E4[p->idx](p);
}
