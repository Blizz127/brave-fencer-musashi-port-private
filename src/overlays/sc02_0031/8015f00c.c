/* SC02.CD FILE_031 / ov_SC02_031 retail span [8015F00C,8015F048).
 * Offset 0x36EB4 at overlay base 80128158. SHA256(span)=5cc70ed15ca65274705eb9a64d4c4d70b6b340adb603ff0269a87f6e0f17845f.
 * Differs from the registry-verified MAIN member 0012 carve in exactly one
 * data reference: D_80180D18 here is D_801815A0 (+0x888 member
 * data-block shift). Oracle MATCH re-earned on this file; Not MAIN10.
 */
/* Decompiled by m2c from main.s, then verified byte-exact
 * against retail by tools/match_function.py. Types and signatures are
 * whatever reproduces the bytes; they are not evidence of the
 * original declaration. */

#include "psx_types.h"
typedef void (*CB)();
extern CB D_801815A0[];
typedef struct { u8 pad[2]; u16 idx; } T;
void func_8015F00C(T *p) {
    D_801815A0[p->idx](p);
}
