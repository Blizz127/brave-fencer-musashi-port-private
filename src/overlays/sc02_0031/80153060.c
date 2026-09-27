/* SC02 resident retail span [80153060,8015309C). Offset 0x2AF08 at base 80128158.
 * SHA256(span)=254995224d07b39036d68c0414b08f5ae55b0a86b63bbeccb48d984ddf65ba78.
 * Words are the guest's loaded image (artifacts/sc02-resident-20260910).
 * Member-0012 C shape retargeted to this member: D_80180150->D_80186A40.
 * Oracle MATCH re-earned against the resident image; Not MAIN10.
 */
/* Decompiled by m2c from main.s, then verified byte-exact
 * against retail by tools/match_function.py. Types and signatures are
 * whatever reproduces the bytes; they are not evidence of the
 * original declaration. */

#include "psx_types.h"
typedef void (*CB)();
extern CB D_80186A40[];
typedef struct { u8 pad[2]; u16 idx; } T;
void func_80153060(T *p) {
    D_80186A40[p->idx](p);
}
