/* SC02 resident retail span [80168744,80168780). Offset 0x405EC at base 80128158.
 * SHA256(span)=9045700e4854c0ae453e7c290bdcd9eec4f89eff4ad454d519ec3352168943c4.
 * Words are the guest's loaded image (artifacts/sc02-resident-20260910).
 * Member-0012 C shape retargeted to this member: D_80181374->D_80187C64.
 * Oracle MATCH re-earned against the resident image; Not MAIN10.
 */
/* Decompiled by m2c from main.s, then verified byte-exact
 * against retail by tools/match_function.py. Types and signatures are
 * whatever reproduces the bytes; they are not evidence of the
 * original declaration. */

#include "psx_types.h"
typedef void (*CB)();
extern CB D_80187C64[];
typedef struct { u8 pad[2]; u16 idx; } T;
void func_80168744(T *p) {
    D_80187C64[p->idx](p);
}
