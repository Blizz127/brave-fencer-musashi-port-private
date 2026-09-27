/* SC02 resident retail span [8015F324,8015F360). Offset 0x371CC at base 80128158.
 * SHA256(span)=aaffab542983e5c1a962c2a15410a73c7f2cc0d504d7a7a4162d80ffb266bc0c.
 * Words are the guest's loaded image (artifacts/sc02-resident-20260910).
 * Member-0012 C shape retargeted to this member: D_80180D20->D_80187610.
 * Oracle MATCH re-earned against the resident image; Not MAIN10.
 */
/* Decompiled by m2c from main.s, then verified byte-exact
 * against retail by tools/match_function.py. Types and signatures are
 * whatever reproduces the bytes; they are not evidence of the
 * original declaration. */

#include "psx_types.h"
typedef void (*CB)();
extern CB D_80187610[];
typedef struct { u8 pad[2]; u16 idx; } T;
void func_8015F324(T *p) {
    D_80187610[p->idx](p);
}
