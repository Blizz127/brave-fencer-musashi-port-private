/* SC02 resident retail span [80166018,80166054). Offset 0x3DEC0 at base 80128158.
 * SHA256(span)=5d9abb904a1792dd78c2c0a810ecf6d35378e5f894f1c1e3e2bb0fc8bdd989db.
 * Words are the guest's loaded image (artifacts/sc02-resident-20260910).
 * Member-0012 C shape retargeted to this member: D_80181260->D_80187B50.
 * Oracle MATCH re-earned against the resident image; Not MAIN10.
 */
/* Decompiled by m2c from main.s, then verified byte-exact
 * against retail by tools/match_function.py. Types and signatures are
 * whatever reproduces the bytes; they are not evidence of the
 * original declaration. */

#include "psx_types.h"
typedef void (*CB)();
extern CB D_80187B50[];
typedef struct { u8 pad[2]; u16 idx; } T;
void func_80166018(T *p) {
    D_80187B50[p->idx](p);
}
