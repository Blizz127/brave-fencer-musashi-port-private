/* SC02 resident retail span [80167A9C,80167AD8). Offset 0x3F944 at base 80128158.
 * SHA256(span)=70eb577d214e8e438fa8331571cd00a526851c01c365024f7d9af3930f337fa4.
 * Words are the guest's loaded image (artifacts/sc02-resident-20260910).
 * Member-0012 C shape retargeted to this member: D_8018135C->D_80187C4C.
 * Oracle MATCH re-earned against the resident image; Not MAIN10.
 */
/* Decompiled by m2c from main.s, then verified byte-exact
 * against retail by tools/match_function.py. Types and signatures are
 * whatever reproduces the bytes; they are not evidence of the
 * original declaration. */

#include "psx_types.h"
typedef void (*CB)();
extern CB D_80187C4C[];
typedef struct { u8 pad[2]; u16 idx; } T;
void func_80167A9C(T *p) {
    D_80187C4C[p->idx](p);
}
