/* SC02 resident retail span [80171120,8017115C). Offset 0x48FC8 at base 80128158.
 * SHA256(span)=8881269f9ac98a6ba2f7a9dc6bc64af11965da4cca167e75c5984279d4dfc14e.
 * Words are the guest's loaded image (artifacts/sc02-resident-20260910).
 * Member-0012 C shape retargeted to this member: D_801818D8->D_801881C8.
 * Oracle MATCH re-earned against the resident image; Not MAIN10.
 */
/* Decompiled by m2c from main.s, then verified byte-exact
 * against retail by tools/match_function.py. Types and signatures are
 * whatever reproduces the bytes; they are not evidence of the
 * original declaration. */

#include "psx_types.h"
typedef void (*CB)();
extern CB D_801881C8[];
typedef struct { u8 pad[534]; u8 idx; } T;
void func_80171120(T *p) {
    D_801881C8[p->idx](p);
}
