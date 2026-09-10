/* SC02 resident retail span [801663FC,80166438). Offset 0x3E2A4 at base 80128158.
 * SHA256(span)=3a2a9364152b5ad9ac4190c922bbef5a00d6e8e9ba5212da3d2e68cb97b59535.
 * Words are the guest's loaded image (artifacts/sc02-resident-20260910).
 * Member-0012 C shape retargeted to this member: D_80181268->D_80187B58.
 * Oracle MATCH re-earned against the resident image; Not MAIN10.
 */
/* Decompiled by m2c from main.s, then verified byte-exact
 * against retail by tools/match_function.py. Types and signatures are
 * whatever reproduces the bytes; they are not evidence of the
 * original declaration. */

#include "psx_types.h"
typedef void (*CB)();
extern CB D_80187B58[];
typedef struct { u8 pad[2]; u16 idx; } T;
void func_801663FC(T *p) {
    D_80187B58[p->idx](p);
}
