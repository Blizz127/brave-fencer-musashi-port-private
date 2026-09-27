/* SC02 resident retail span [8016DF20,8016DF5C). Offset 0x45DC8 at base 80128158.
 * SHA256(span)=8e4b71b1bb373d3f5d1662aac93ab8c91e50653725946fd67bfe7023a490b2f1.
 * Words are the guest's loaded image (artifacts/sc02-resident-20260910).
 * Member-0012 C shape retargeted to this member: D_801816B8->D_80187FA8.
 * Oracle MATCH re-earned against the resident image; Not MAIN10.
 */
/* Decompiled by m2c from main.s, then verified byte-exact
 * against retail by tools/match_function.py. Types and signatures are
 * whatever reproduces the bytes; they are not evidence of the
 * original declaration. */

#include "psx_types.h"
typedef void (*CB)();
extern CB D_80187FA8[];
typedef struct { u8 pad[2]; u16 idx; } T;
void func_8016DF20(T *p) {
    D_80187FA8[p->idx](p);
}
