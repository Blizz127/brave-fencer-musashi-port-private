/* SC02 resident retail span [8016FDB4,8016FDF0). Offset 0x47C5C at base 80128158.
 * SHA256(span)=14d1ff45652d3787866c891db03f2d2198dc49d53fdf98dd988a2efe55d8b31a.
 * Words are the guest's loaded image (artifacts/sc02-resident-20260910).
 * Member-0012 C shape retargeted to this member: D_80181820->D_80188110.
 * Oracle MATCH re-earned against the resident image; Not MAIN10.
 */
/* Decompiled by m2c from main.s, then verified byte-exact
 * against retail by tools/match_function.py. Types and signatures are
 * whatever reproduces the bytes; they are not evidence of the
 * original declaration. */

#include "psx_types.h"
typedef void (*CB)();
extern CB D_80188110[];
typedef struct { u8 pad[534]; u8 idx; } T;
void func_8016FDB4(T *p) {
    D_80188110[p->idx](p);
}
