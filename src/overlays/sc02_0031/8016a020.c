/* SC02 resident retail span [8016A020,8016A05C). Offset 0x41EC8 at base 80128158.
 * SHA256(span)=1c76286f846088cf432191f1a8ce5be87bacdfcd5d5e815fd2cdb4676ed94fd0.
 * Words are the guest's loaded image (artifacts/sc02-resident-20260910).
 * Member-0012 C shape retargeted to this member: D_80181498->D_80187D88.
 * Oracle MATCH re-earned against the resident image; Not MAIN10.
 */
/* Decompiled by m2c from main.s, then verified byte-exact
 * against retail by tools/match_function.py. Types and signatures are
 * whatever reproduces the bytes; they are not evidence of the
 * original declaration. */

#include "psx_types.h"
typedef void (*CB)();
extern CB D_80187D88[];
typedef struct { u8 pad[2]; u16 idx; } T;
void func_8016A020(T *p) {
    D_80187D88[p->idx](p);
}
