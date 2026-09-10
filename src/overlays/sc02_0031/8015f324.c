/* SC02.CD FILE_031 / ov_SC02_031 retail span [8015F324,8015F360).
 * Offset 0x371CC at overlay base 80128158. SHA256(span)=c464bf1090fecd80a9c589334ab2a3b20e1da3107cfbcb4d0014c7c77e616e32.
 * Differs from the registry-verified MAIN member 0012 carve in exactly one
 * data reference: D_80180D20 here is D_801815A8 (+0x888 member
 * data-block shift). Oracle MATCH re-earned on this file; Not MAIN10.
 */
/* Decompiled by m2c from main.s, then verified byte-exact
 * against retail by tools/match_function.py. Types and signatures are
 * whatever reproduces the bytes; they are not evidence of the
 * original declaration. */

#include "psx_types.h"
typedef void (*CB)();
extern CB D_801815A8[];
typedef struct { u8 pad[2]; u16 idx; } T;
void func_8015F324(T *p) {
    D_801815A8[p->idx](p);
}
