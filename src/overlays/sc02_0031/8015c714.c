/* SC02.CD FILE_031 / ov_SC02_031 retail span [8015C714,8015C750).
 * Offset 0x345BC at overlay base 80128158. SHA256(span)=e7252a56a1be40a43468e6fe345fd7df352df729d9b8691f185445a32dc23339.
 * Differs from the registry-verified MAIN member 0012 carve in exactly one
 * data reference: D_80180BA8 here is D_80181430 (+0x888 member
 * data-block shift). Oracle MATCH re-earned on this file; Not MAIN10.
 */
/* Decompiled by m2c from main.s, then verified byte-exact
 * against retail by tools/match_function.py. Types and signatures are
 * whatever reproduces the bytes; they are not evidence of the
 * original declaration. */

#include "psx_types.h"
typedef void (*CB)();
extern CB D_80181430[];
typedef struct { u8 pad[2]; u16 idx; } T;
void func_8015C714(T *p) {
    D_80181430[p->idx](p);
}
