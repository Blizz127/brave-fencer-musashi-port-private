/* SC02.CD FILE_031 / ov_SC02_031 retail span [80168744,80168780).
 * Offset 0x405EC at overlay base 80128158. SHA256(span)=811e374a13c99ee871645fc94859cc7111e857b0d999ffcc2675efeeac28e71c.
 * Differs from the registry-verified MAIN member 0012 carve in exactly one
 * data reference: D_80181374 here is D_80181BFC (+0x888 member
 * data-block shift). Oracle MATCH re-earned on this file; Not MAIN10.
 */
/* Decompiled by m2c from main.s, then verified byte-exact
 * against retail by tools/match_function.py. Types and signatures are
 * whatever reproduces the bytes; they are not evidence of the
 * original declaration. */

#include "psx_types.h"
typedef void (*CB)();
extern CB D_80181BFC[];
typedef struct { u8 pad[2]; u16 idx; } T;
void func_80168744(T *p) {
    D_80181BFC[p->idx](p);
}
