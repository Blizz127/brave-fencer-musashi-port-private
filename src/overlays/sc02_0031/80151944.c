/* SC02 resident retail span [80151944,80151980). Offset 0x297EC at base 80128158.
 * SHA256(span)=89c75a38b122571a4fa226f4e24a8bcd6054231ab5d4938ee4e99db1dbf1f4fe.
 * Words are the guest's loaded image (artifacts/sc02-resident-20260910).
 * Member-0012 C shape retargeted to this member: D_80180090->D_80186980.
 * Oracle MATCH re-earned against the resident image; Not MAIN10.
 */
/* Decompiled by m2c from main.s, then verified byte-exact
 * against retail by tools/match_function.py. Types and signatures are
 * whatever reproduces the bytes; they are not evidence of the
 * original declaration. */

#include "psx_types.h"
typedef void (*CB)();
extern CB D_80186980[];
typedef struct { u8 pad[2]; u16 idx; } T;
void func_80151944(T *p) {
    D_80186980[p->idx](p);
}
