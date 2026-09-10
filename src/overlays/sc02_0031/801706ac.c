/* SC02.CD FILE_031 / ov_SC02_031 retail span [801706AC,801706E8).
 * Offset 0x48554 at overlay base 80128158. SHA256(span)=e1160a501a6fe10a92e8ce531df5a95cf6f13515dd609f889efcf0bfb07f77fc.
 * Differs from the registry-verified MAIN member 0012 carve in exactly one
 * data reference: D_80181880 here is D_80182108 (+0x888 member
 * data-block shift). Oracle MATCH re-earned on this file; Not MAIN10.
 */
/* Decompiled by m2c from main.s, then verified byte-exact
 * against retail by tools/match_function.py. Types and signatures are
 * whatever reproduces the bytes; they are not evidence of the
 * original declaration. */

#include "psx_types.h"
typedef void (*CB)();
extern CB D_80182108[];
typedef struct { u8 pad[534]; u8 idx; } T;
void func_801706AC(T *p) {
    D_80182108[p->idx](p);
}
