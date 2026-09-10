/* SC02 resident retail span [80166654,80166690). Offset 0x3E4FC at base 80128158.
 * SHA256(span)=12380af1913a31410920fd2f8b1f3669aed08869f2a8ab2b0f9c12e5473c2c6f.
 * Words are the guest's loaded image (artifacts/sc02-resident-20260910).
 * Member-0012 C shape retargeted to this member: D_80181340->D_80187C30.
 * Oracle MATCH re-earned against the resident image; Not MAIN10.
 */
/* Decompiled by m2c from main.s, then verified byte-exact
 * against retail by tools/match_function.py. Types and signatures are
 * whatever reproduces the bytes; they are not evidence of the
 * original declaration. */

#include "psx_types.h"
typedef void (*CB)();
extern CB D_80187C30[];
typedef struct { u8 pad[2]; u16 idx; } T;
void func_80166654(T *p) {
    D_80187C30[p->idx](p);
}
