/* SC02 resident retail span [801736FC,80173738). Offset 0x4B5A4 at base 80128158.
 * SHA256(span)=8aa27d66937784cc7d1f55b061c1223656ad5796f7b2ff3e272e34ca1563f018.
 * Words are the guest's loaded image (artifacts/sc02-resident-20260910).
 * Member-0012 C shape retargeted to this member: D_80181978->D_80188268.
 * Oracle MATCH re-earned against the resident image; Not MAIN10.
 */
/* Decompiled by m2c from main.s, then verified byte-exact
 * against retail by tools/match_function.py. Types and signatures are
 * whatever reproduces the bytes; they are not evidence of the
 * original declaration. */

#include "psx_types.h"
typedef void (*CB)();
extern CB D_80188268[];
typedef struct { u8 pad[532]; u8 idx; } T;
void func_801736FC(T *p) {
    D_80188268[p->idx](p);
}
