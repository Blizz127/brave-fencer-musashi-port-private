/* SC02 resident retail span [8016901C,80169058). Offset 0x40EC4 at base 80128158.
 * SHA256(span)=2963466a82555567a9bce1b5530176944ef1dd9314b66596c5a10337ad2002fb.
 * Words are the guest's loaded image (artifacts/sc02-resident-20260910).
 * Member-0012 C shape retargeted to this member: D_80181394->D_80187C84.
 * Oracle MATCH re-earned against the resident image; Not MAIN10.
 */
/* Decompiled by m2c from main.s, then verified byte-exact
 * against retail by tools/match_function.py. Types and signatures are
 * whatever reproduces the bytes; they are not evidence of the
 * original declaration. */

#include "psx_types.h"
typedef void (*CB)();
extern CB D_80187C84[];
typedef struct { u8 pad[2]; u16 idx; } T;
void func_8016901C(T *p) {
    D_80187C84[p->idx](p);
}
