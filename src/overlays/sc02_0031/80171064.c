/* SC02.CD FILE_031 / ov_SC02_031 retail span [80171064,801710A0).
 * Offset 0x48F0C at overlay base 80128158. SHA256(span)=ba2f761140afa7ccc5aa4d5f88344bca3683a3d74ebc536d046b9531934d58d6.
 * Differs from the registry-verified MAIN member 0012 carve in exactly one
 * data reference: D_801818D0 here is D_80182158 (+0x888 member
 * data-block shift). Oracle MATCH re-earned on this file; Not MAIN10.
 */
/* Decompiled by m2c from main.s, then verified byte-exact
 * against retail by tools/match_function.py. Types and signatures are
 * whatever reproduces the bytes; they are not evidence of the
 * original declaration. */

#include "psx_types.h"
typedef void (*CB)();
extern CB D_80182158[];
typedef struct { u8 pad[534]; u8 idx; } T;
void func_80171064(T *p) {
    D_80182158[p->idx](p);
}
