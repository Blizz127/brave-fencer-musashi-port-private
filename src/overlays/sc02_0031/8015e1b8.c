/* SC02.CD FILE_031 / ov_SC02_031 retail span [8015E1B8,8015E1F4).
 * Offset 0x36060 at overlay base 80128158. SHA256(span)=75a53f4a7d64b84378bb12458129b6d3f57ee14da861a8745220208e3f21d648.
 * Differs from the registry-verified MAIN member 0012 carve in exactly one
 * data reference: D_80180CD4 here is D_8018155C (+0x888 member
 * data-block shift). Oracle MATCH re-earned on this file; Not MAIN10.
 */
/* Decompiled by m2c from main.s, then verified byte-exact
 * against retail by tools/match_function.py. Types and signatures are
 * whatever reproduces the bytes; they are not evidence of the
 * original declaration. */

#include "psx_types.h"
typedef void (*CB)();
extern CB D_8018155C[];
typedef struct { u8 pad[2]; u16 idx; } T;
void func_8015E1B8(T *p) {
    D_8018155C[p->idx](p);
}
