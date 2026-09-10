/* SC02 resident retail span [8015F00C,8015F048). Offset 0x36EB4 at base 80128158.
 * SHA256(span)=35c3ad46030c6e4a4d2d25fbe7fcd299ddb2cfedc52c6a4095576e75e5932ffe.
 * Words are the guest's loaded image (artifacts/sc02-resident-20260910).
 * Member-0012 C shape retargeted to this member: D_80180D18->D_80187608.
 * Oracle MATCH re-earned against the resident image; Not MAIN10.
 */
/* Decompiled by m2c from main.s, then verified byte-exact
 * against retail by tools/match_function.py. Types and signatures are
 * whatever reproduces the bytes; they are not evidence of the
 * original declaration. */

#include "psx_types.h"
typedef void (*CB)();
extern CB D_80187608[];
typedef struct { u8 pad[2]; u16 idx; } T;
void func_8015F00C(T *p) {
    D_80187608[p->idx](p);
}
