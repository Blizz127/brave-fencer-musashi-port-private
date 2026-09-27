/* SC02 resident retail span [8015BFF4,8015C030). Offset 0x33E9C at base 80128158.
 * SHA256(span)=9005cbd2d4d4a11dbc536cef7e052487d7577263042e9ad378aca11caf88d1a5.
 * Words are the guest's loaded image (artifacts/sc02-resident-20260910).
 * Member-0012 C shape retargeted to this member: D_80180B9C->D_8018748C.
 * Oracle MATCH re-earned against the resident image; Not MAIN10.
 */
/* Decompiled by m2c from main.s, then verified byte-exact
 * against retail by tools/match_function.py. Types and signatures are
 * whatever reproduces the bytes; they are not evidence of the
 * original declaration. */

#include "psx_types.h"
typedef void (*CB)();
extern CB D_8018748C[];
typedef struct { u8 pad[2]; u16 idx; } T;
void func_8015BFF4(T *p) {
    D_8018748C[p->idx](p);
}
