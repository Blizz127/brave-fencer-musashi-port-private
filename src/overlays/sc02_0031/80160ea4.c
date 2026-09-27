/* SC02 resident retail span [80160EA4,80160EE0). Offset 0x38D4C at base 80128158.
 * SHA256(span)=9eda212de7481ed18ac3ca1159f3ed41b7840ddb8597a6dc6509fc465631d490.
 * Words are the guest's loaded image (artifacts/sc02-resident-20260910).
 * Member-0012 C shape retargeted to this member: D_80180E28->D_80187718.
 * Oracle MATCH re-earned against the resident image; Not MAIN10.
 */
/* Decompiled by m2c from main.s, then verified byte-exact
 * against retail by tools/match_function.py. Types and signatures are
 * whatever reproduces the bytes; they are not evidence of the
 * original declaration. */

#include "psx_types.h"
typedef void (*CB)();
extern CB D_80187718[];
typedef struct { u8 pad[2]; u16 idx; } T;
void func_80160EA4(T *p) {
    D_80187718[p->idx](p);
}
