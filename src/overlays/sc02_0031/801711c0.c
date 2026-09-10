/* SC02 resident retail span [801711C0,801711FC). Offset 0x49068 at base 80128158.
 * SHA256(span)=208107331ee2b55f90379e4f3402fd8c69d45268f86ac321414d9969f127cacf.
 * Words are the guest's loaded image (artifacts/sc02-resident-20260910).
 * Member-0012 C shape retargeted to this member: D_801818E0->D_801881D0.
 * Oracle MATCH re-earned against the resident image; Not MAIN10.
 */
/* Decompiled by m2c from main.s, then verified byte-exact
 * against retail by tools/match_function.py. Types and signatures are
 * whatever reproduces the bytes; they are not evidence of the
 * original declaration. */

#include "psx_types.h"
typedef void (*CB)();
extern CB D_801881D0[];
typedef struct { u8 pad[534]; u8 idx; } T;
void func_801711C0(T *p) {
    D_801881D0[p->idx](p);
}
