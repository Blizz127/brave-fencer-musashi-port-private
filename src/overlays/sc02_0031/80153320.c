/* SC02 resident retail span [80153320,8015335C). Offset 0x2B1C8 at base 80128158.
 * SHA256(span)=7d2b0b9899bda8eedaa6b9e07b441bf09b5f60653530d914bd0d638a38398bdd.
 * Words are the guest's loaded image (artifacts/sc02-resident-20260910).
 * Member-0012 C shape retargeted to this member: D_80180164->D_80186A54.
 * Oracle MATCH re-earned against the resident image; Not MAIN10.
 */
/* Decompiled by m2c from main.s, then verified byte-exact
 * against retail by tools/match_function.py. Types and signatures are
 * whatever reproduces the bytes; they are not evidence of the
 * original declaration. */

#include "psx_types.h"
typedef void (*CB)();
extern CB D_80186A54[];
typedef struct { u8 pad[2]; u16 idx; } T;
void func_80153320(T *p) {
    D_80186A54[p->idx](p);
}
