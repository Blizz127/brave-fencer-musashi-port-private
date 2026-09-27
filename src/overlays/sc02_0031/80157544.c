/* SC02 resident retail span [80157544,80157580). Offset 0x2F3EC at base 80128158.
 * SHA256(span)=4d27a62002f4e8c9d69ebfa77f966eb772bdb0f1fd67910076b7fc3fa860f4fc.
 * Words are the guest's loaded image (artifacts/sc02-resident-20260910).
 * Member-0012 C shape retargeted to this member: D_80180664->D_80186F54.
 * Oracle MATCH re-earned against the resident image; Not MAIN10.
 */
/* Decompiled by m2c from main.s, then verified byte-exact
 * against retail by tools/match_function.py. Types and signatures are
 * whatever reproduces the bytes; they are not evidence of the
 * original declaration. */

#include "psx_types.h"
typedef void (*CB)();
extern CB D_80186F54[];
typedef struct { u8 pad[2]; u16 idx; } T;
void func_80157544(T *p) {
    D_80186F54[p->idx](p);
}
