/* SC02 resident retail span [80171064,801710A0). Offset 0x48F0C at base 80128158.
 * SHA256(span)=9ad7a1a6008a55ffbe0e636a630c5502d51c946a98d47564947a8b74f0082ec4.
 * Words are the guest's loaded image (artifacts/sc02-resident-20260910).
 * Member-0012 C shape retargeted to this member: D_801818D0->D_801881C0.
 * Oracle MATCH re-earned against the resident image; Not MAIN10.
 */
/* Decompiled by m2c from main.s, then verified byte-exact
 * against retail by tools/match_function.py. Types and signatures are
 * whatever reproduces the bytes; they are not evidence of the
 * original declaration. */

#include "psx_types.h"
typedef void (*CB)();
extern CB D_801881C0[];
typedef struct { u8 pad[534]; u8 idx; } T;
void func_80171064(T *p) {
    D_801881C0[p->idx](p);
}
