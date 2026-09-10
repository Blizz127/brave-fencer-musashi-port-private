/* SC02 resident retail span [80169F00,80169F3C). Offset 0x41DA8 at base 80128158.
 * SHA256(span)=1ec26a9b99b1a9c1888c97e8630d10738edacf90e66c99b1e36492ecfc4c7449.
 * Words are the guest's loaded image (artifacts/sc02-resident-20260910).
 * Member-0012 C shape retargeted to this member: D_80181460->D_80187D50.
 * Oracle MATCH re-earned against the resident image; Not MAIN10.
 */
/* Decompiled by m2c from main.s, then verified byte-exact
 * against retail by tools/match_function.py. Types and signatures are
 * whatever reproduces the bytes; they are not evidence of the
 * original declaration. */

#include "psx_types.h"
typedef void (*CB)();
extern CB D_80187D50[];
typedef struct { u8 pad[2]; u16 idx; } T;
void func_80169F00(T *p) {
    D_80187D50[p->idx](p);
}
