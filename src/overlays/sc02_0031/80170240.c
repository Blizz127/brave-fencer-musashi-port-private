/* SC02.CD FILE_031 / ov_SC02_031 retail span [80170240,8017027C).
 * Offset 0x480E8 at overlay base 80128158. SHA256(span)=0e51c9a60c84369596d01506d8404f09dfcc15c88250c6716e6c413d6e0fc144.
 * Differs from the registry-verified MAIN member 0012 carve in exactly one
 * data reference: D_80181850 here is D_801820D8 (+0x888 member
 * data-block shift). Oracle MATCH re-earned on this file; Not MAIN10.
 */
/* Decompiled by m2c from main.s, then verified byte-exact
 * against retail by tools/match_function.py. Types and signatures are
 * whatever reproduces the bytes; they are not evidence of the
 * original declaration. */

#include "psx_types.h"
typedef void (*CB)();
extern CB D_801820D8[];
typedef struct { u8 pad[534]; u8 idx; } T;
void func_80170240(T *p) {
    D_801820D8[p->idx](p);
}
