/* SC02 resident retail span [80168AA8,80168AE4). Offset 0x40950 at base 80128158.
 * SHA256(span)=6fcc99214f924973d73dfbb6ef7e09923194e9c267148c228dd4629c98cb9d87.
 * Words are the guest's loaded image (artifacts/sc02-resident-20260910).
 * Member-0012 C shape retargeted to this member: D_80181384->D_80187C74.
 * Oracle MATCH re-earned against the resident image; Not MAIN10.
 */
/* Decompiled by m2c from main.s, then verified byte-exact
 * against retail by tools/match_function.py. Types and signatures are
 * whatever reproduces the bytes; they are not evidence of the
 * original declaration. */

#include "psx_types.h"
typedef void (*CB)();
extern CB D_80187C74[];
typedef struct { u8 pad[2]; u16 idx; } T;
void func_80168AA8(T *p) {
    D_80187C74[p->idx](p);
}
