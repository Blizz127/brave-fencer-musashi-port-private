/* SC02 resident retail span [801714E4,80171520). Offset 0x4938C at base 80128158.
 * SHA256(span)=282a8af411aa4dda842a3a8e00547338f11cf628ea5e1a8271604135d1bde014.
 * Words are the guest's loaded image (artifacts/sc02-resident-20260910).
 * Member-0012 C shape retargeted to this member: D_801818F0->D_801881E0.
 * Oracle MATCH re-earned against the resident image; Not MAIN10.
 */
/* Decompiled by m2c from main.s, then verified byte-exact
 * against retail by tools/match_function.py. Types and signatures are
 * whatever reproduces the bytes; they are not evidence of the
 * original declaration. */

#include "psx_types.h"
typedef void (*CB)();
extern CB D_801881E0[];
typedef struct { u8 pad[534]; u8 idx; } T;
void func_801714E4(T *p) {
    D_801881E0[p->idx](p);
}
