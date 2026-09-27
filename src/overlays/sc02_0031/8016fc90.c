/* SC02 resident retail span [8016FC90,8016FCCC). Offset 0x47B38 at base 80128158.
 * SHA256(span)=fd59a6e221c6127ce358d0d71edd82d257d3dcdb1e4dd144fa663c84ada5401c.
 * Words are the guest's loaded image (artifacts/sc02-resident-20260910).
 * Member-0012 C shape retargeted to this member: D_80181814->D_80188104.
 * Oracle MATCH re-earned against the resident image; Not MAIN10.
 */
/* Decompiled by m2c from main.s, then verified byte-exact
 * against retail by tools/match_function.py. Types and signatures are
 * whatever reproduces the bytes; they are not evidence of the
 * original declaration. */

#include "psx_types.h"
typedef void (*CB)();
extern CB D_80188104[];
typedef struct { u8 pad[534]; u8 idx; } T;
void func_8016FC90(T *p) {
    D_80188104[p->idx](p);
}
