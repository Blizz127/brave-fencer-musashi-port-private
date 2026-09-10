/* SC02.CD FILE_031 / ov_SC02_031 retail span [8016F834,8016F870).
 * Offset 0x476DC at overlay base 80128158. SHA256(span)=db1c08db5cf54d8dce6cb7c1ae7df8c0263aef91a44128923d62d759bd1dd00f.
 * Differs from the registry-verified MAIN member 0012 carve in exactly one
 * data reference: D_801817E4 here is D_8018206C (+0x888 member
 * data-block shift). Oracle MATCH re-earned on this file; Not MAIN10.
 */
/* Decompiled by m2c from main.s, then verified byte-exact
 * against retail by tools/match_function.py. Types and signatures are
 * whatever reproduces the bytes; they are not evidence of the
 * original declaration. */

#include "psx_types.h"
typedef void (*CB)();
extern CB D_8018206C[];
typedef struct { u8 pad[534]; u8 idx; } T;
void func_8016F834(T *p) {
    D_8018206C[p->idx](p);
}
