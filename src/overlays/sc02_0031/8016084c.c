/* SC02 resident retail span [8016084C,80160888). Offset 0x386F4 at base 80128158.
 * SHA256(span)=55b9e2152d9f8246e5a01ff963e9169d6b06a300a9ae8dcc0e2487654c33631d.
 * Words are the guest's loaded image (artifacts/sc02-resident-20260910).
 * Member-0012 C shape retargeted to this member: D_80180E0C->D_801876FC.
 * Oracle MATCH re-earned against the resident image; Not MAIN10.
 */
/* Decompiled by m2c from main.s, then verified byte-exact
 * against retail by tools/match_function.py. Types and signatures are
 * whatever reproduces the bytes; they are not evidence of the
 * original declaration. */

#include "psx_types.h"
typedef void (*CB)();
extern CB D_801876FC[];
typedef struct { u8 pad[2]; u16 idx; } T;
void func_8016084C(T *p) {
    D_801876FC[p->idx](p);
}
