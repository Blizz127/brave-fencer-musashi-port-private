/* SC02.CD FILE_031 / ov_SC02_031 retail span [801704B0,801704EC).
 * Offset 0x48358 at overlay base 80128158. SHA256(span)=e603a7afefacfb7bec94397c03d25dd86babb9d45eaf71e3e1681769c0e275ec.
 * Differs from the registry-verified MAIN member 0012 carve in exactly one
 * data reference: D_80181868 here is D_801820F0 (+0x888 member
 * data-block shift). Oracle MATCH re-earned on this file; Not MAIN10.
 */
/* Decompiled by m2c from main.s, then verified byte-exact
 * against retail by tools/match_function.py. Types and signatures are
 * whatever reproduces the bytes; they are not evidence of the
 * original declaration. */

#include "psx_types.h"
typedef void (*CB)();
extern CB D_801820F0[];
typedef struct { u8 pad[534]; u8 idx; } T;
void func_801704B0(T *p) {
    D_801820F0[p->idx](p);
}
