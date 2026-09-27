/* SC02 resident retail span [8017390C,80173948). Offset 0x4B7B4 at base 80128158.
 * SHA256(span)=224753e96281f2db3f9b03e501ec45fe39a8781ecb753c7119e4da764eefa34f.
 * Words are the guest's loaded image (artifacts/sc02-resident-20260910).
 * Member-0012 C shape retargeted to this member: D_80181990->D_80188280.
 * Oracle MATCH re-earned against the resident image; Not MAIN10.
 */
/* Decompiled by m2c from main.s, then verified byte-exact
 * against retail by tools/match_function.py. Types and signatures are
 * whatever reproduces the bytes; they are not evidence of the
 * original declaration. */

#include "psx_types.h"
typedef void (*CB)();
extern CB D_80188280[];
typedef struct { u8 pad[532]; u8 idx; } T;
void func_8017390C(T *p) {
    D_80188280[p->idx](p);
}
