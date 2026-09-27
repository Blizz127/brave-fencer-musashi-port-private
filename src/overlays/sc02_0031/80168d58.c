/* SC02 resident retail span [80168D58,80168D94). Offset 0x40C00 at base 80128158.
 * SHA256(span)=6d909525d9095bf8b837993ce447400dbb4f18f31444c5b71a0c6f51d924a560.
 * Words are the guest's loaded image (artifacts/sc02-resident-20260910).
 * Member-0012 C shape retargeted to this member: D_8018138C->D_80187C7C.
 * Oracle MATCH re-earned against the resident image; Not MAIN10.
 */
/* Decompiled by m2c from main.s, then verified byte-exact
 * against retail by tools/match_function.py. Types and signatures are
 * whatever reproduces the bytes; they are not evidence of the
 * original declaration. */

#include "psx_types.h"
typedef void (*CB)();
extern CB D_80187C7C[];
typedef struct { u8 pad[2]; u16 idx; } T;
void func_80168D58(T *p) {
    D_80187C7C[p->idx](p);
}
