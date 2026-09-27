/* SC02 resident retail span [80170E34,80170E70). Offset 0x48CDC at base 80128158.
 * SHA256(span)=b2ebe9bfe1e672b313f6bb511cf7bb023670b5d3b4b9e947aab2974688efe57c.
 * Words are the guest's loaded image (artifacts/sc02-resident-20260910).
 * Member-0012 C shape retargeted to this member: D_801818B8->D_801881A8.
 * Oracle MATCH re-earned against the resident image; Not MAIN10.
 */
/* Decompiled by m2c from main.s, then verified byte-exact
 * against retail by tools/match_function.py. Types and signatures are
 * whatever reproduces the bytes; they are not evidence of the
 * original declaration. */

#include "psx_types.h"
typedef void (*CB)();
extern CB D_801881A8[];
typedef struct { u8 pad[534]; u8 idx; } T;
void func_80170E34(T *p) {
    D_801881A8[p->idx](p);
}
