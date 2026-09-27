/* SC02 resident retail span [80163A58,80163A94). Offset 0x3B900 at base 80128158.
 * SHA256(span)=86516446970e46fa0e4773e0bec6bd0e663fa87bc052a453f31395a60b23b872.
 * Words are the guest's loaded image (artifacts/sc02-resident-20260910).
 * Member-0012 C shape retargeted to this member: D_80180F30->D_80187820.
 * Oracle MATCH re-earned against the resident image; Not MAIN10.
 */
/* Decompiled by m2c from main.s, then verified byte-exact
 * against retail by tools/match_function.py. Types and signatures are
 * whatever reproduces the bytes; they are not evidence of the
 * original declaration. */

#include "psx_types.h"
typedef void (*CB)();
extern CB D_80187820[];
typedef struct { u8 pad[2]; u16 idx; } T;
void func_80163A58(T *p) {
    D_80187820[p->idx](p);
}
