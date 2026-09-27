/* SC02 resident retail span [80166618,80166654). Offset 0x3E4C0 at base 80128158.
 * SHA256(span)=95f373c5411fc75796b0e9ec5450091aee8f0f57368966f91f7162dabede1b31.
 * Words are the guest's loaded image (artifacts/sc02-resident-20260910).
 * Member-0012 C shape retargeted to this member: D_80181330->D_80187C20.
 * Oracle MATCH re-earned against the resident image; Not MAIN10.
 */
/* Decompiled by m2c from main.s, then verified byte-exact
 * against retail by tools/match_function.py. Types and signatures are
 * whatever reproduces the bytes; they are not evidence of the
 * original declaration. */

#include "psx_types.h"
typedef void (*CB)();
extern CB D_80187C20[];
typedef struct { u8 pad[2]; u16 idx; } T;
void func_80166618(T *p) {
    D_80187C20[p->idx](p);
}
