/* SC02.CD FILE_031 / ov_SC02_031 retail span [8015F7D4,8015F810).
 * Offset 0x3767C at overlay base 80128158. SHA256(span)=b8f5b5e3b32959ef7b4abf283d56e3fac68e9b6f125c90131ece2d46d15c2f29.
 * Differs from the registry-verified MAIN member 0012 carve in exactly one
 * data reference: D_80180D58 here is D_801815E0 (+0x888 member
 * data-block shift). Oracle MATCH re-earned on this file; Not MAIN10.
 */
/* Decompiled by m2c from main.s, then verified byte-exact
 * against retail by tools/match_function.py. Types and signatures are
 * whatever reproduces the bytes; they are not evidence of the
 * original declaration. */

#include "psx_types.h"
typedef void (*CB)();
extern CB D_801815E0[];
typedef struct { u8 pad[2]; u16 idx; } T;
void func_8015F7D4(T *p) {
    D_801815E0[p->idx](p);
}
