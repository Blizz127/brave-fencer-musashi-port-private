/* SC02 resident retail span [8015E8E8,8015E924). Offset 0x36790 at base 80128158.
 * SHA256(span)=ac9ff4f179947c1a9bd8ef60b1a70842fe8099cb0cf5e4d79eb6dd4b1772e970.
 * Words are the guest's loaded image (artifacts/sc02-resident-20260910).
 * Member-0012 C shape retargeted to this member: D_80180D08->D_801875F8.
 * Oracle MATCH re-earned against the resident image; Not MAIN10.
 */
/* Decompiled by m2c from main.s, then verified byte-exact
 * against retail by tools/match_function.py. Types and signatures are
 * whatever reproduces the bytes; they are not evidence of the
 * original declaration. */

#include "psx_types.h"
typedef void (*CB)();
extern CB D_801875F8[];
typedef struct { u8 pad[2]; u16 idx; } T;
void func_8015E8E8(T *p) {
    D_801875F8[p->idx](p);
}
