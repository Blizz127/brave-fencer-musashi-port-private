/* SC02.CD FILE_031 / ov_SC02_031 retail span [8016FF30,8016FF6C).
 * Offset 0x47DD8 at overlay base 80128158. SHA256(span)=78b7032077b941aff0b97f7e6d8115212c3c0526477b3c63681c343a5c48f487.
 * Differs from the registry-verified MAIN member 0012 carve in exactly one
 * data reference: D_80181830 here is D_801820B8 (+0x888 member
 * data-block shift). Oracle MATCH re-earned on this file; Not MAIN10.
 */
/* Decompiled by m2c from main.s, then verified byte-exact
 * against retail by tools/match_function.py. Types and signatures are
 * whatever reproduces the bytes; they are not evidence of the
 * original declaration. */

#include "psx_types.h"
typedef void (*CB)();
extern CB D_801820B8[];
typedef struct { u8 pad[534]; u8 idx; } T;
void func_8016FF30(T *p) {
    D_801820B8[p->idx](p);
}
