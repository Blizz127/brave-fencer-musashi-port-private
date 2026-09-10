/* SC02 resident retail span [8015FAAC,8015FAE8). Offset 0x37954 at base 80128158.
 * SHA256(span)=059014aa0ada01cf7d59c319eaaf5d040119910d7ccaa5b64800b422f5c1adad.
 * Words are the guest's loaded image (artifacts/sc02-resident-20260910).
 * Member-0012 C shape retargeted to this member: D_80180D64->D_80187654.
 * Oracle MATCH re-earned against the resident image; Not MAIN10.
 */
/* Decompiled by m2c from main.s, then verified byte-exact
 * against retail by tools/match_function.py. Types and signatures are
 * whatever reproduces the bytes; they are not evidence of the
 * original declaration. */

#include "psx_types.h"
typedef void (*CB)();
extern CB D_80187654[];
typedef struct { u8 pad[2]; u16 idx; } T;
void func_8015FAAC(T *p) {
    D_80187654[p->idx](p);
}
