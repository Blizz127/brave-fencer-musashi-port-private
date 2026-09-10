/* SC02.CD FILE_031 / ov_SC02_031 retail span [8016F6E0,8016F71C).
 * Offset 0x47588 at overlay base 80128158. SHA256(span)=b6077eadf62e31041ab38ac66064201e3b2a05267ab23f9ae75f76a2e021aa76.
 * Differs from the registry-verified MAIN member 0012 carve in exactly one
 * data reference: D_801817D4 here is D_8018205C (+0x888 member
 * data-block shift). Oracle MATCH re-earned on this file; Not MAIN10.
 */
/* Decompiled by m2c from main.s, then verified byte-exact
 * against retail by tools/match_function.py. Types and signatures are
 * whatever reproduces the bytes; they are not evidence of the
 * original declaration. */

#include "psx_types.h"
typedef void (*CB)();
extern CB D_8018205C[];
typedef struct { u8 pad[534]; u8 idx; } T;
void func_8016F6E0(T *p) {
    D_8018205C[p->idx](p);
}
