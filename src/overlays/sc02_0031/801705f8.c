/* SC02 resident retail span [801705F8,80170634). Offset 0x484A0 at base 80128158.
 * SHA256(span)=0b3def9becfb1ac93d78b361693b77454276102bf6bc4bc6f8b7559b5d478d0d.
 * Words are the guest's loaded image (artifacts/sc02-resident-20260910).
 * Member-0012 C shape retargeted to this member: D_80181878->D_80188168.
 * Oracle MATCH re-earned against the resident image; Not MAIN10.
 */
/* Decompiled by m2c from main.s, then verified byte-exact
 * against retail by tools/match_function.py. Types and signatures are
 * whatever reproduces the bytes; they are not evidence of the
 * original declaration. */

#include "psx_types.h"
typedef void (*CB)();
extern CB D_80188168[];
typedef struct { u8 pad[534]; u8 idx; } T;
void func_801705F8(T *p) {
    D_80188168[p->idx](p);
}
