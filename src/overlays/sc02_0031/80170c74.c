/* SC02 resident retail span [80170C74,80170CB0). Offset 0x48B1C at base 80128158.
 * SHA256(span)=4b1074ed73ae3b245cd70953ccb4e972b9dcccd315fa78dce86726bb8ded8680.
 * Words are the guest's loaded image (artifacts/sc02-resident-20260910).
 * Member-0012 C shape retargeted to this member: D_801818A8->D_80188198.
 * Oracle MATCH re-earned against the resident image; Not MAIN10.
 */
/* Decompiled by m2c from main.s, then verified byte-exact
 * against retail by tools/match_function.py. Types and signatures are
 * whatever reproduces the bytes; they are not evidence of the
 * original declaration. */

#include "psx_types.h"
typedef void (*CB)();
extern CB D_80188198[];
typedef struct { u8 pad[533]; u8 idx; } T;
void func_80170C74(T *p) {
    D_80188198[p->idx](p);
}
