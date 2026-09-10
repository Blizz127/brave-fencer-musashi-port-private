/* SC02.CD FILE_031 / ov_SC02_031 retail span [80155580,801555BC).
 * Offset 0x2D428 at overlay base 80128158. SHA256(span)=ae96d5446d145c6f503d7771cc8d8c3e8044cea9425527209ddf0dfe2df6cc61.
 * Differs from the registry-verified MAIN member 0012 carve in exactly one
 * data reference: D_801801F0 here is D_80180A78 (+0x888 member
 * data-block shift). Oracle MATCH re-earned on this file; Not MAIN10.
 */
/* Decompiled by m2c from main.s, then verified byte-exact
 * against retail by tools/match_function.py. Types and signatures are
 * whatever reproduces the bytes; they are not evidence of the
 * original declaration. */

#include "psx_types.h"
typedef void (*CB)();
extern CB D_80180A78[];
typedef struct { u8 pad[2]; u16 idx; } T;
void func_80155580(T *p) {
    D_80180A78[p->idx](p);
}
