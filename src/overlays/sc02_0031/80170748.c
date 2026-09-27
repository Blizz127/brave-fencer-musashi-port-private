/* SC02 resident retail span [80170748,80170784). Offset 0x485F0 at base 80128158.
 * SHA256(span)=51b70fb0fc0903dfec7dc269a35a2647790880e1f47088725a0502777dd93abb.
 * Words are the guest's loaded image (artifacts/sc02-resident-20260910).
 * Member-0012 C shape retargeted to this member: D_80181888->D_80188178.
 * Oracle MATCH re-earned against the resident image; Not MAIN10.
 */
/* Decompiled by m2c from main.s, then verified byte-exact
 * against retail by tools/match_function.py. Types and signatures are
 * whatever reproduces the bytes; they are not evidence of the
 * original declaration. */

#include "psx_types.h"
typedef void (*CB)();
extern CB D_80188178[];
typedef struct { u8 pad[534]; u8 idx; } T;
void func_80170748(T *p) {
    D_80188178[p->idx](p);
}
