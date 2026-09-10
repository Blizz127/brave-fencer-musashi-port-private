/* SC02 resident retail span [80170150,8017018C). Offset 0x47FF8 at base 80128158.
 * SHA256(span)=31c5e6c73a72c3db86d607c560200dc532d48b3f67df553486197a5b1706e07b.
 * Words are the guest's loaded image (artifacts/sc02-resident-20260910).
 * Member-0012 C shape retargeted to this member: D_80181848->D_80188138.
 * Oracle MATCH re-earned against the resident image; Not MAIN10.
 */
/* Decompiled by m2c from main.s, then verified byte-exact
 * against retail by tools/match_function.py. Types and signatures are
 * whatever reproduces the bytes; they are not evidence of the
 * original declaration. */

#include "psx_types.h"
typedef void (*CB)();
extern CB D_80188138[];
typedef struct { u8 pad[534]; u8 idx; } T;
void func_80170150(T *p) {
    D_80188138[p->idx](p);
}
