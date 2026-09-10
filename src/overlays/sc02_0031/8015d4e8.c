/* SC02 resident retail span [8015D4E8,8015D524). Offset 0x35390 at base 80128158.
 * SHA256(span)=1ab8cdcf5d6bcdcf29599d9aba32481eedc186b8ed57308f149750419e7ccdbf.
 * Words are the guest's loaded image (artifacts/sc02-resident-20260910).
 * Member-0012 C shape retargeted to this member: D_80180C54->D_80187544.
 * Oracle MATCH re-earned against the resident image; Not MAIN10.
 */
/* Decompiled by m2c from main.s, then verified byte-exact
 * against retail by tools/match_function.py. Types and signatures are
 * whatever reproduces the bytes; they are not evidence of the
 * original declaration. */

#include "psx_types.h"
typedef void (*CB)();
extern CB D_80187544[];
typedef struct { u8 pad[2]; u16 idx; } T;
void func_8015D4E8(T *p) {
    D_80187544[p->idx](p);
}
