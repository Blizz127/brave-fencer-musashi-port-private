/* SC02 resident retail span [80152D24,80152D60). Offset 0x2ABCC at base 80128158.
 * SHA256(span)=23b9ec40fc1c7c815da7e55da75a06c2380c3507dd05217b874d78d6cc1e7653.
 * Words are the guest's loaded image (artifacts/sc02-resident-20260910).
 * Member-0012 C shape retargeted to this member: D_8018013C->D_80186A2C.
 * Oracle MATCH re-earned against the resident image; Not MAIN10.
 */
/* Decompiled by m2c from main.s, then verified byte-exact
 * against retail by tools/match_function.py. Types and signatures are
 * whatever reproduces the bytes; they are not evidence of the
 * original declaration. */

#include "psx_types.h"
typedef void (*CB)();
extern CB D_80186A2C[];
typedef struct { u8 pad[2]; u16 idx; } T;
void func_80152D24(T *p) {
    D_80186A2C[p->idx](p);
}
