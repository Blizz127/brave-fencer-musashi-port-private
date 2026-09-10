/* SC02 resident retail span [80174384,801743C0). Offset 0x4C22C at base 80128158.
 * SHA256(span)=9ce15fd62fd6ea093dd6034d10df01dd9fe0420abd7a4a0b128ea66d45892315.
 * Words are the guest's loaded image (artifacts/sc02-resident-20260910).
 * Member-0012 C shape retargeted to this member: D_801819CC->D_801882BC.
 * Oracle MATCH re-earned against the resident image; Not MAIN10.
 */
/* Decompiled by m2c from main.s, then verified byte-exact
 * against retail by tools/match_function.py. Types and signatures are
 * whatever reproduces the bytes; they are not evidence of the
 * original declaration. */

#include "psx_types.h"
typedef void (*CB)();
extern CB D_801882BC[];
typedef struct { u8 pad[532]; u8 idx; } T;
void func_80174384(T *p) {
    D_801882BC[p->idx](p);
}
