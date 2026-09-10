/* SC02 resident retail span [8016FFDC,80170018). Offset 0x47E84 at base 80128158.
 * SHA256(span)=1df6d9e9a35445e73e7003365665da7b434504020b369230437b51b53c958e15.
 * Words are the guest's loaded image (artifacts/sc02-resident-20260910).
 * Member-0012 C shape retargeted to this member: D_80181840->D_80188130.
 * Oracle MATCH re-earned against the resident image; Not MAIN10.
 */
/* Decompiled by m2c from main.s, then verified byte-exact
 * against retail by tools/match_function.py. Types and signatures are
 * whatever reproduces the bytes; they are not evidence of the
 * original declaration. */

#include "psx_types.h"
typedef void (*CB)();
extern CB D_80188130[];
typedef struct { u8 pad[534]; u8 idx; } T;
void func_8016FFDC(T *p) {
    D_80188130[p->idx](p);
}
