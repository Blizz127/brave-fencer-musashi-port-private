/* SC02 resident retail span [801702FC,80170338). Offset 0x481A4 at base 80128158.
 * SHA256(span)=524eb5744f8631d16a773ebf54e4740badb9acf7b0676cd95c5fc7e41740b0c0.
 * Words are the guest's loaded image (artifacts/sc02-resident-20260910).
 * Member-0012 C shape retargeted to this member: D_80181858->D_80188148.
 * Oracle MATCH re-earned against the resident image; Not MAIN10.
 */
/* Decompiled by m2c from main.s, then verified byte-exact
 * against retail by tools/match_function.py. Types and signatures are
 * whatever reproduces the bytes; they are not evidence of the
 * original declaration. */

#include "psx_types.h"
typedef void (*CB)();
extern CB D_80188148[];
typedef struct { u8 pad[534]; u8 idx; } T;
void func_801702FC(T *p) {
    D_80188148[p->idx](p);
}
