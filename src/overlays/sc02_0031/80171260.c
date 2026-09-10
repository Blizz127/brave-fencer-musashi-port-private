/* SC02.CD FILE_031 / ov_SC02_031 retail span [80171260,8017129C).
 * Offset 0x49108 at overlay base 80128158. SHA256(span)=bf666408e6c75ec448ca1035e59f050586f27556891ee3cfe30293fc0439b457.
 * Differs from the registry-verified MAIN member 0012 carve in exactly one
 * data reference: D_801818E8 here is D_80182170 (+0x888 member
 * data-block shift). Oracle MATCH re-earned on this file; Not MAIN10.
 */
/* Decompiled by m2c from main.s, then verified byte-exact
 * against retail by tools/match_function.py. Types and signatures are
 * whatever reproduces the bytes; they are not evidence of the
 * original declaration. */

#include "psx_types.h"
typedef void (*CB)();
extern CB D_80182170[];
typedef struct { u8 pad[534]; u8 idx; } T;
void func_80171260(T *p) {
    D_80182170[p->idx](p);
}
