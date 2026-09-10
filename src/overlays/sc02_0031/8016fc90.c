/* SC02.CD FILE_031 / ov_SC02_031 retail span [8016FC90,8016FCCC).
 * Offset 0x47B38 at overlay base 80128158. SHA256(span)=817a20a47b78ad81cb9bba73fe069d9b70e1355e32b6f254115d28c15235a3f8.
 * Differs from the registry-verified MAIN member 0012 carve in exactly one
 * data reference: D_80181814 here is D_8018209C (+0x888 member
 * data-block shift). Oracle MATCH re-earned on this file; Not MAIN10.
 */
/* Decompiled by m2c from main.s, then verified byte-exact
 * against retail by tools/match_function.py. Types and signatures are
 * whatever reproduces the bytes; they are not evidence of the
 * original declaration. */

#include "psx_types.h"
typedef void (*CB)();
extern CB D_8018209C[];
typedef struct { u8 pad[534]; u8 idx; } T;
void func_8016FC90(T *p) {
    D_8018209C[p->idx](p);
}
