/* SC02 resident retail span [80174F28,80174F64). Offset 0x4CDD0 at base 80128158.
 * SHA256(span)=4cfae82bbccd1a328332638f08121aeed34474c1ec37c93e24b98f8914ee5f81.
 * Words are the guest's loaded image (artifacts/sc02-resident-20260910).
 * Member-0012 C shape retargeted to this member: D_80181A00->D_801882F0.
 * Oracle MATCH re-earned against the resident image; Not MAIN10.
 */
/* Decompiled by m2c from main.s, then verified byte-exact
 * against retail by tools/match_function.py. Types and signatures are
 * whatever reproduces the bytes; they are not evidence of the
 * original declaration. */

#include "psx_types.h"
typedef void (*CB)();
extern CB D_801882F0[];
typedef struct { u8 pad[4]; u8 idx; } T;
void func_80174F28(T *p) {
    D_801882F0[p->idx](p);
}
