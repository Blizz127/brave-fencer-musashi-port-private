/* SC02.CD FILE_031 / ov_SC02_031 retail span [801705F8,80170634).
 * Offset 0x484A0 at overlay base 80128158. SHA256(span)=4f37bab0104b7e4c672dd1d0da97e07f7eb01d7e8d62d148290fdd68f33b854b.
 * Differs from the registry-verified MAIN member 0012 carve in exactly one
 * data reference: D_80181878 here is D_80182100 (+0x888 member
 * data-block shift). Oracle MATCH re-earned on this file; Not MAIN10.
 */
/* Decompiled by m2c from main.s, then verified byte-exact
 * against retail by tools/match_function.py. Types and signatures are
 * whatever reproduces the bytes; they are not evidence of the
 * original declaration. */

#include "psx_types.h"
typedef void (*CB)();
extern CB D_80182100[];
typedef struct { u8 pad[534]; u8 idx; } T;
void func_801705F8(T *p) {
    D_80182100[p->idx](p);
}
