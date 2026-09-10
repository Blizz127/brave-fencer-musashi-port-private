/* SC02 resident retail span [80160B34,80160B70). Offset 0x389DC at base 80128158.
 * SHA256(span)=4d44d1b0651f886d0ec4be29668c5c7ac7ee91ae8f8ec7a569d24fca7f2d187a.
 * Words are the guest's loaded image (artifacts/sc02-resident-20260910).
 * Member-0012 C shape retargeted to this member: D_80180E18->D_80187708.
 * Oracle MATCH re-earned against the resident image; Not MAIN10.
 */
/* Decompiled by m2c from main.s, then verified byte-exact
 * against retail by tools/match_function.py. Types and signatures are
 * whatever reproduces the bytes; they are not evidence of the
 * original declaration. */

#include "psx_types.h"
typedef void (*CB)();
extern CB D_80187708[];
typedef struct { u8 pad[2]; u16 idx; } T;
void func_80160B34(T *p) {
    D_80187708[p->idx](p);
}
