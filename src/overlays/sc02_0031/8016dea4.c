/* SC02 resident retail span [8016DEA4,8016DEE0). Offset 0x45D4C at base 80128158.
 * SHA256(span)=fd9333ca0fd59c131b82657ee0ccc8eba611ff51a637eb1342041ac6e1126d59.
 * Words are the guest's loaded image (artifacts/sc02-resident-20260910).
 * Member-0012 C shape retargeted to this member: D_801816B0->D_80187FA0.
 * Oracle MATCH re-earned against the resident image; Not MAIN10.
 */
/* Decompiled by m2c from main.s, then verified byte-exact
 * against retail by tools/match_function.py. Types and signatures are
 * whatever reproduces the bytes; they are not evidence of the
 * original declaration. */

#include "psx_types.h"
typedef void (*CB)();
extern CB D_80187FA0[];
typedef struct { u8 pad[2]; u16 idx; } T;
void func_8016DEA4(T *p) {
    D_80187FA0[p->idx](p);
}
