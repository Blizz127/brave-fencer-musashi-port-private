/* SC02.CD FILE_031 / ov_SC02_031 retail span [8015DAF8,8015DB34).
 * Offset 0x359A0 at overlay base 80128158. SHA256(span)=6d23ba6ad709a364e32732b2bd22542ee7a828f23b4b05ed587e7883cf222eaa.
 * Differs from the registry-verified MAIN member 0012 carve in exactly one
 * data reference: D_80180C94 here is D_8018151C (+0x888 member
 * data-block shift). Oracle MATCH re-earned on this file; Not MAIN10.
 */
/* Decompiled by m2c from main.s, then verified byte-exact
 * against retail by tools/match_function.py. Types and signatures are
 * whatever reproduces the bytes; they are not evidence of the
 * original declaration. */

#include "psx_types.h"
typedef void (*CB)();
extern CB D_8018151C[];
typedef struct { u8 pad[2]; u16 idx; } T;
void func_8015DAF8(T *p) {
    D_8018151C[p->idx](p);
}
