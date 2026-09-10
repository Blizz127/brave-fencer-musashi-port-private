/* SC02 resident retail span [8016A700,8016A73C). Offset 0x425A8 at base 80128158.
 * SHA256(span)=3c6fb88030c28778a025abbf8891ea2de67c148632530d3687ea11760acaa3bc.
 * Words are the guest's loaded image (artifacts/sc02-resident-20260910).
 * Member-0012 C shape retargeted to this member: D_801814A4->D_80187D94.
 * Oracle MATCH re-earned against the resident image; Not MAIN10.
 */
/* Decompiled by m2c from main.s, then verified byte-exact
 * against retail by tools/match_function.py. Types and signatures are
 * whatever reproduces the bytes; they are not evidence of the
 * original declaration. */

#include "psx_types.h"
typedef void (*CB)();
extern CB D_80187D94[];
typedef struct { u8 pad[2]; u16 idx; } T;
void func_8016A700(T *p) {
    D_80187D94[p->idx](p);
}
