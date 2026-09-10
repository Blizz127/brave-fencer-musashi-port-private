/* SC02 resident retail span [8015824C,80158288). Offset 0x300F4 at base 80128158.
 * SHA256(span)=d1c5c8b525455030c96a401b2ba7942ae8fd8856c76ae3aed1a0c4b60abfdc6d.
 * Words are the guest's loaded image (artifacts/sc02-resident-20260910).
 * Member-0012 C shape retargeted to this member: D_801806E0->D_80186FD0.
 * Oracle MATCH re-earned against the resident image; Not MAIN10.
 */
/* Decompiled by m2c from main.s, then verified byte-exact
 * against retail by tools/match_function.py. Types and signatures are
 * whatever reproduces the bytes; they are not evidence of the
 * original declaration. */

#include "psx_types.h"
typedef void (*CB)();
extern CB D_80186FD0[];
typedef struct { u8 pad[2]; u16 idx; } T;
void func_8015824C(T *p) {
    D_80186FD0[p->idx](p);
}
