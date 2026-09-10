/* SC02 resident retail span [80162330,8016236C). Offset 0x3A1D8 at base 80128158.
 * SHA256(span)=a5361498eee65b64101b39da149520b0e34581d5dc24690782c67bfe457c4911.
 * Words are the guest's loaded image (artifacts/sc02-resident-20260910).
 * Member-0012 C shape retargeted to this member: D_80180EE0->D_801877D0.
 * Oracle MATCH re-earned against the resident image; Not MAIN10.
 */
/* Decompiled by m2c from main.s, then verified byte-exact
 * against retail by tools/match_function.py. Types and signatures are
 * whatever reproduces the bytes; they are not evidence of the
 * original declaration. */

#include "psx_types.h"
typedef void (*CB)();
extern CB D_801877D0[];
typedef struct { u8 pad[21]; u8 idx; } T;
void func_80162330(T *p) {
    D_801877D0[p->idx](p);
}
