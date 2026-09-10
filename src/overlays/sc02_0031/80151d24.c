/* SC02 resident retail span [80151D24,80151D60). Offset 0x29BCC at base 80128158.
 * SHA256(span)=d1a558c75cc3a8e87000c10c1cb3831d5dff14e6a7c1f24b822e8fce872cc3ce.
 * Words are the guest's loaded image (artifacts/sc02-resident-20260910).
 * Member-0012 C shape retargeted to this member: D_801800A0->D_80186990.
 * Oracle MATCH re-earned against the resident image; Not MAIN10.
 */
/* Decompiled by m2c from main.s, then verified byte-exact
 * against retail by tools/match_function.py. Types and signatures are
 * whatever reproduces the bytes; they are not evidence of the
 * original declaration. */

#include "psx_types.h"
typedef void (*CB)();
extern CB D_80186990[];
typedef struct { u8 pad[2]; u16 idx; } T;
void func_80151D24(T *p) {
    D_80186990[p->idx](p);
}
