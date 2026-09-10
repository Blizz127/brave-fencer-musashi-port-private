/* SC02 resident retail span [80170EFC,80170F38). Offset 0x48DA4 at base 80128158.
 * SHA256(span)=8a175117d4eaf495dad0db2c7b2f32b3df5be5af69443654682cab9f7ee41211.
 * Words are the guest's loaded image (artifacts/sc02-resident-20260910).
 * Member-0012 C shape retargeted to this member: D_801818C0->D_801881B0.
 * Oracle MATCH re-earned against the resident image; Not MAIN10.
 */
/* Decompiled by m2c from main.s, then verified byte-exact
 * against retail by tools/match_function.py. Types and signatures are
 * whatever reproduces the bytes; they are not evidence of the
 * original declaration. */

#include "psx_types.h"
typedef void (*CB)();
extern CB D_801881B0[];
typedef struct { u8 pad[534]; u8 idx; } T;
void func_80170EFC(T *p) {
    D_801881B0[p->idx](p);
}
