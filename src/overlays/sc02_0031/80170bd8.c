/* SC02 resident retail span [80170BD8,80170C14). Offset 0x48A80 at base 80128158.
 * SHA256(span)=f665e129a5d58fb1a8cda70f470db0391378f5e2b701f6c0f6e26f3251db9139.
 * Words are the guest's loaded image (artifacts/sc02-resident-20260910).
 * Member-0012 C shape retargeted to this member: D_801818A0->D_80188190.
 * Oracle MATCH re-earned against the resident image; Not MAIN10.
 */
/* Decompiled by m2c from main.s, then verified byte-exact
 * against retail by tools/match_function.py. Types and signatures are
 * whatever reproduces the bytes; they are not evidence of the
 * original declaration. */

#include "psx_types.h"
typedef void (*CB)();
extern CB D_80188190[];
typedef struct { u8 pad[534]; u8 idx; } T;
void func_80170BD8(T *p) {
    D_80188190[p->idx](p);
}
