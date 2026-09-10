/* SC02.CD FILE_031 / ov_SC02_031 retail span [8015A264,8015A2A0).
 * Offset 0x3210C at overlay base 80128158. SHA256(span)=2aa1e63a991151ca16dbd977cda979afc8d522fc5eb95e5abbdad130f318ef58.
 * Differs from the registry-verified MAIN member 0012 carve in exactly one
 * data reference: D_80180B6C here is D_801813F4 (+0x888 member
 * data-block shift). Oracle MATCH re-earned on this file; Not MAIN10.
 */
/* Decompiled by m2c from main.s, then verified byte-exact
 * against retail by tools/match_function.py. Types and signatures are
 * whatever reproduces the bytes; they are not evidence of the
 * original declaration. */

#include "psx_types.h"
typedef void (*CB)();
extern CB D_801813F4[];
typedef struct { u8 pad[2]; u16 idx; } T;
void func_8015A264(T *p) {
    D_801813F4[p->idx](p);
}
