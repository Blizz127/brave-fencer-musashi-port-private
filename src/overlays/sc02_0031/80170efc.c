/* SC02.CD FILE_031 / ov_SC02_031 retail span [80170EFC,80170F38).
 * Offset 0x48DA4 at overlay base 80128158. SHA256(span)=89b4fa0ddcf816f959b5e5b51188bb03d50d34e808195f4bf1dffc1814097281.
 * Differs from the registry-verified MAIN member 0012 carve in exactly one
 * data reference: D_801818C0 here is D_80182148 (+0x888 member
 * data-block shift). Oracle MATCH re-earned on this file; Not MAIN10.
 */
/* Decompiled by m2c from main.s, then verified byte-exact
 * against retail by tools/match_function.py. Types and signatures are
 * whatever reproduces the bytes; they are not evidence of the
 * original declaration. */

#include "psx_types.h"
typedef void (*CB)();
extern CB D_80182148[];
typedef struct { u8 pad[534]; u8 idx; } T;
void func_80170EFC(T *p) {
    D_80182148[p->idx](p);
}
