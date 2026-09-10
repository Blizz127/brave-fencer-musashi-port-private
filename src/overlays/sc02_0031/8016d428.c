/* SC02.CD FILE_031 / ov_SC02_031 retail span [8016D428,8016D464).
 * Offset 0x452D0 at overlay base 80128158. SHA256(span)=d2c7db400e5b047809f5a23910581de3d85b8976a30bdfaf1d2a84db1fa7d44d.
 * Differs from the registry-verified MAIN member 0012 carve in exactly one
 * data reference: D_80181614 here is D_80181E9C (+0x888 member
 * data-block shift). Oracle MATCH re-earned on this file; Not MAIN10.
 */
/* Decompiled by m2c from main.s, then verified byte-exact
 * against retail by tools/match_function.py. Types and signatures are
 * whatever reproduces the bytes; they are not evidence of the
 * original declaration. */

#include "psx_types.h"
typedef void (*CB)();
extern CB D_80181E9C[];
typedef struct { u8 pad[2]; u16 idx; } T;
void func_8016D428(T *p) {
    D_80181E9C[p->idx](p);
}
