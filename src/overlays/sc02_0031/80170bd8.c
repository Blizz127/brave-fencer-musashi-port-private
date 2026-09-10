/* SC02.CD FILE_031 / ov_SC02_031 retail span [80170BD8,80170C14).
 * Offset 0x48A80 at overlay base 80128158. SHA256(span)=47c2eca5ceecd2ecda2a98bd90fee045475d2d3165afc6fff79d958d0664fed5.
 * Differs from the registry-verified MAIN member 0012 carve in exactly one
 * data reference: D_801818A0 here is D_80182128 (+0x888 member
 * data-block shift). Oracle MATCH re-earned on this file; Not MAIN10.
 */
/* Decompiled by m2c from main.s, then verified byte-exact
 * against retail by tools/match_function.py. Types and signatures are
 * whatever reproduces the bytes; they are not evidence of the
 * original declaration. */

#include "psx_types.h"
typedef void (*CB)();
extern CB D_80182128[];
typedef struct { u8 pad[534]; u8 idx; } T;
void func_80170BD8(T *p) {
    D_80182128[p->idx](p);
}
