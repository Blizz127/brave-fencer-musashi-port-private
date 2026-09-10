/* SC02.CD FILE_031 / ov_SC02_031 retail span [801703E0,8017041C).
 * Offset 0x48288 at overlay base 80128158. SHA256(span)=0fa06aa01ace9da3d639a8c42e05c3dc487be6061986dd464110743e54c99b00.
 * Differs from the registry-verified MAIN member 0012 carve in exactly one
 * data reference: D_80181860 here is D_801820E8 (+0x888 member
 * data-block shift). Oracle MATCH re-earned on this file; Not MAIN10.
 */
/* Decompiled by m2c from main.s, then verified byte-exact
 * against retail by tools/match_function.py. Types and signatures are
 * whatever reproduces the bytes; they are not evidence of the
 * original declaration. */

#include "psx_types.h"
typedef void (*CB)();
extern CB D_801820E8[];
typedef struct { u8 pad[534]; u8 idx; } T;
void func_801703E0(T *p) {
    D_801820E8[p->idx](p);
}
