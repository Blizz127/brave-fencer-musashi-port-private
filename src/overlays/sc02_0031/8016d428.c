/* SC02 resident retail span [8016D428,8016D464). Offset 0x452D0 at base 80128158.
 * SHA256(span)=24604c3c7091ee58299965221a6b46adf7fa61ba0011d5908132675aa4a53aae.
 * Words are the guest's loaded image (artifacts/sc02-resident-20260910).
 * Member-0012 C shape retargeted to this member: D_80181614->D_80187F04.
 * Oracle MATCH re-earned against the resident image; Not MAIN10.
 */
/* Decompiled by m2c from main.s, then verified byte-exact
 * against retail by tools/match_function.py. Types and signatures are
 * whatever reproduces the bytes; they are not evidence of the
 * original declaration. */

#include "psx_types.h"
typedef void (*CB)();
extern CB D_80187F04[];
typedef struct { u8 pad[2]; u16 idx; } T;
void func_8016D428(T *p) {
    D_80187F04[p->idx](p);
}
