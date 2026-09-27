/* SC02 resident retail span [8015DAF8,8015DB34). Offset 0x359A0 at base 80128158.
 * SHA256(span)=b800de52aa06f02c9e5e05d21807f78905d004d2f6d25eb2563ab8871e28dd4f.
 * Words are the guest's loaded image (artifacts/sc02-resident-20260910).
 * Member-0012 C shape retargeted to this member: D_80180C94->D_80187584.
 * Oracle MATCH re-earned against the resident image; Not MAIN10.
 */
/* Decompiled by m2c from main.s, then verified byte-exact
 * against retail by tools/match_function.py. Types and signatures are
 * whatever reproduces the bytes; they are not evidence of the
 * original declaration. */

#include "psx_types.h"
typedef void (*CB)();
extern CB D_80187584[];
typedef struct { u8 pad[2]; u16 idx; } T;
void func_8015DAF8(T *p) {
    D_80187584[p->idx](p);
}
