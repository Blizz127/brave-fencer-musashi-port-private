/* SC02 resident retail span [801704B0,801704EC). Offset 0x48358 at base 80128158.
 * SHA256(span)=c8ef39cf7ce31d0ea37f00b4f47a98c912468b9aebea7826e2308f5c10ffa36f.
 * Words are the guest's loaded image (artifacts/sc02-resident-20260910).
 * Member-0012 C shape retargeted to this member: D_80181868->D_80188158.
 * Oracle MATCH re-earned against the resident image; Not MAIN10.
 */
/* Decompiled by m2c from main.s, then verified byte-exact
 * against retail by tools/match_function.py. Types and signatures are
 * whatever reproduces the bytes; they are not evidence of the
 * original declaration. */

#include "psx_types.h"
typedef void (*CB)();
extern CB D_80188158[];
typedef struct { u8 pad[534]; u8 idx; } T;
void func_801704B0(T *p) {
    D_80188158[p->idx](p);
}
