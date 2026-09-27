/* SC02 resident retail span [80152698,801526D4). Offset 0x2A540 at base 80128158.
 * SHA256(span)=d9c707ae7071ada0c4d9e62955ae87e9eacd30015816ebe5650fc44f0aab7186.
 * Words are the guest's loaded image (artifacts/sc02-resident-20260910).
 * Member-0012 C shape retargeted to this member: D_801800F4->D_801869E4.
 * Oracle MATCH re-earned against the resident image; Not MAIN10.
 */
/* Decompiled by m2c from main.s, then verified byte-exact
 * against retail by tools/match_function.py. Types and signatures are
 * whatever reproduces the bytes; they are not evidence of the
 * original declaration. */

#include "psx_types.h"
typedef void (*CB)();
extern CB D_801869E4[];
typedef struct { u8 pad[2]; u16 idx; } T;
void func_80152698(T *p) {
    D_801869E4[p->idx](p);
}
