/* SC02 resident retail span [80169830,8016986C). Offset 0x416D8 at base 80128158.
 * SHA256(span)=7aa1cd3a9acca3b8f4ed8406e4a2b912ab9440ed0c740b17e734a8147ec99437.
 * Words are the guest's loaded image (artifacts/sc02-resident-20260910).
 * Member-0012 C shape retargeted to this member: D_801813A4->D_80187C94.
 * Oracle MATCH re-earned against the resident image; Not MAIN10.
 */
/* Decompiled by m2c from main.s, then verified byte-exact
 * against retail by tools/match_function.py. Types and signatures are
 * whatever reproduces the bytes; they are not evidence of the
 * original declaration. */

#include "psx_types.h"
typedef void (*CB)();
extern CB D_80187C94[];
typedef struct { u8 pad[2]; u16 idx; } T;
void func_80169830(T *p) {
    D_80187C94[p->idx](p);
}
