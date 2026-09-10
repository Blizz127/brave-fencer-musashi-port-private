/* SC02 resident retail span [80170AD8,80170B14). Offset 0x48980 at base 80128158.
 * SHA256(span)=1643b67e0f032d1a478729492be0b290f6e6b1fccecc8c2bcbc5caa6c4e0e004.
 * Words are the guest's loaded image (artifacts/sc02-resident-20260910).
 * Member-0012 C shape retargeted to this member: D_80181898->D_80188188.
 * Oracle MATCH re-earned against the resident image; Not MAIN10.
 */
/* Decompiled by m2c from main.s, then verified byte-exact
 * against retail by tools/match_function.py. Types and signatures are
 * whatever reproduces the bytes; they are not evidence of the
 * original declaration. */

#include "psx_types.h"
typedef void (*CB)();
extern CB D_80188188[];
typedef struct { u8 pad[534]; u8 idx; } T;
void func_80170AD8(T *p) {
    D_80188188[p->idx](p);
}
