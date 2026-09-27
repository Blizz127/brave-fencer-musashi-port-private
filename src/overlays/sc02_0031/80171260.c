/* SC02 resident retail span [80171260,8017129C). Offset 0x49108 at base 80128158.
 * SHA256(span)=2f0c752514b3ed30a530c6deedbf13e90713c0a3626b4d00f3f7aa8d678bb26d.
 * Words are the guest's loaded image (artifacts/sc02-resident-20260910).
 * Member-0012 C shape retargeted to this member: D_801818E8->D_801881D8.
 * Oracle MATCH re-earned against the resident image; Not MAIN10.
 */
/* Decompiled by m2c from main.s, then verified byte-exact
 * against retail by tools/match_function.py. Types and signatures are
 * whatever reproduces the bytes; they are not evidence of the
 * original declaration. */

#include "psx_types.h"
typedef void (*CB)();
extern CB D_801881D8[];
typedef struct { u8 pad[534]; u8 idx; } T;
void func_80171260(T *p) {
    D_801881D8[p->idx](p);
}
