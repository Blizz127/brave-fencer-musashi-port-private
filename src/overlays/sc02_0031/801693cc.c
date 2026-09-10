/* SC02 resident retail span [801693CC,80169408). Offset 0x41274 at base 80128158.
 * SHA256(span)=19ec9f400bdc2ae74c0a1c7a81e96151bc2566ea79d8495c347e023ab579ea76.
 * Words are the guest's loaded image (artifacts/sc02-resident-20260910).
 * Member-0012 C shape retargeted to this member: D_8018139C->D_80187C8C.
 * Oracle MATCH re-earned against the resident image; Not MAIN10.
 */
/* Decompiled by m2c from main.s, then verified byte-exact
 * against retail by tools/match_function.py. Types and signatures are
 * whatever reproduces the bytes; they are not evidence of the
 * original declaration. */

#include "psx_types.h"
typedef void (*CB)();
extern CB D_80187C8C[];
typedef struct { u8 pad[2]; u16 idx; } T;
void func_801693CC(T *p) {
    D_80187C8C[p->idx](p);
}
