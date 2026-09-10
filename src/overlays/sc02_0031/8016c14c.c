/* SC02 resident retail span [8016C14C,8016C188). Offset 0x43FF4 at base 80128158.
 * SHA256(span)=e90483c13b7338cdb881303162ffe87298f23e84af51da785b63e835d277041f.
 * Words are the guest's loaded image (artifacts/sc02-resident-20260910).
 * Member-0012 C shape retargeted to this member: D_801815E8->D_80187ED8.
 * Oracle MATCH re-earned against the resident image; Not MAIN10.
 */
/* Decompiled by m2c from main.s, then verified byte-exact
 * against retail by tools/match_function.py. Types and signatures are
 * whatever reproduces the bytes; they are not evidence of the
 * original declaration. */

#include "psx_types.h"
typedef void (*CB)();
extern CB D_80187ED8[];
typedef struct { u8 pad[2]; u16 idx; } T;
void func_8016C14C(T *p) {
    D_80187ED8[p->idx](p);
}
