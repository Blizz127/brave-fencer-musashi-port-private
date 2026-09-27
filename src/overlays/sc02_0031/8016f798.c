/* SC02 resident retail span [8016F798,8016F7D4). Offset 0x47640 at base 80128158.
 * SHA256(span)=99664a53d4d3483b4e072ba39bc0c497f91ce9dbd9eedb7af12579aeb5e62ddb.
 * Words are the guest's loaded image (artifacts/sc02-resident-20260910).
 * Member-0012 C shape retargeted to this member: D_801817DC->D_801880CC.
 * Oracle MATCH re-earned against the resident image; Not MAIN10.
 */
/* Decompiled by m2c from main.s, then verified byte-exact
 * against retail by tools/match_function.py. Types and signatures are
 * whatever reproduces the bytes; they are not evidence of the
 * original declaration. */

#include "psx_types.h"
typedef void (*CB)();
extern CB D_801880CC[];
typedef struct { u8 pad[534]; u8 idx; } T;
void func_8016F798(T *p) {
    D_801880CC[p->idx](p);
}
