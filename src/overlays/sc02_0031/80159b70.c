/* SC02 resident retail span [80159B70,80159BAC). Offset 0x31A18 at base 80128158.
 * SHA256(span)=e7599dccb457339ce749ebaecf03fe3473dbfc018e3ee3823e59d0be0f0fbb40.
 * Words are the guest's loaded image (artifacts/sc02-resident-20260910).
 * Member-0012 C shape retargeted to this member: D_80180B64->D_80187454.
 * Oracle MATCH re-earned against the resident image; Not MAIN10.
 */
/* Decompiled by m2c from main.s, then verified byte-exact
 * against retail by tools/match_function.py. Types and signatures are
 * whatever reproduces the bytes; they are not evidence of the
 * original declaration. */

#include "psx_types.h"
typedef void (*CB)();
extern CB D_80187454[];
typedef struct { u8 pad[2]; u16 idx; } T;
void func_80159B70(T *p) {
    D_80187454[p->idx](p);
}
