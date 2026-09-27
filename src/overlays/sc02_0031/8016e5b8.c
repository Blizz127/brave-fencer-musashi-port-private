/* SC02 resident retail span [8016E5B8,8016E5F4). Offset 0x46460 at base 80128158.
 * SHA256(span)=f72d4567f5c009add4d412075037205e764ef31061cd0bb779e1f3cbb3e51154.
 * Words are the guest's loaded image (artifacts/sc02-resident-20260910).
 * Member-0012 C shape retargeted to this member: D_8018170C->D_80187FFC.
 * Oracle MATCH re-earned against the resident image; Not MAIN10.
 */
/* Decompiled by m2c from main.s, then verified byte-exact
 * against retail by tools/match_function.py. Types and signatures are
 * whatever reproduces the bytes; they are not evidence of the
 * original declaration. */

#include "psx_types.h"
typedef void (*CB)();
extern CB D_80187FFC[];
typedef struct { u8 pad[2]; u16 idx; } T;
void func_8016E5B8(T *p) {
    D_80187FFC[p->idx](p);
}
