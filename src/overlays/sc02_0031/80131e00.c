/* SC02 resident retail span [80131E00,80131E38). Offset 0x9CA8 at base 80128158.
 * SHA256(span)=7313a6190db8095c42ab7859430613c2c3d9839933fa0cb0e144e644e40bab50.
 * Words are the guest's loaded image (artifacts/sc02-resident-20260910).
 * Member-0012 C shape retargeted to this member: D_8017E850->D_80185140.
 * Oracle MATCH re-earned against the resident image; Not MAIN10.
 */
/* Decompiled by m2c from main.s, then verified byte-exact
 * against retail by tools/match_function.py. Types and signatures are
 * whatever reproduces the bytes; they are not evidence of the
 * original declaration. */

#include "psx_types.h"
typedef void (*CB)();
extern CB D_80185140[];
typedef struct { u8 pad[176]; s32 unk; } T;
void func_80131E00(T *p, s32 idx) {
    p->unk = idx;
    D_80185140[idx](p);
}
