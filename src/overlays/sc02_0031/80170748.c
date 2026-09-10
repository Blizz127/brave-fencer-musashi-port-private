/* SC02.CD FILE_031 / ov_SC02_031 retail span [80170748,80170784).
 * Offset 0x485F0 at overlay base 80128158. SHA256(span)=6979aa88618bd81305f5d29d2bdd75b85897d767c22c44b8df5c479ccc636962.
 * Differs from the registry-verified MAIN member 0012 carve in exactly one
 * data reference: D_80181888 here is D_80182110 (+0x888 member
 * data-block shift). Oracle MATCH re-earned on this file; Not MAIN10.
 */
/* Decompiled by m2c from main.s, then verified byte-exact
 * against retail by tools/match_function.py. Types and signatures are
 * whatever reproduces the bytes; they are not evidence of the
 * original declaration. */

#include "psx_types.h"
typedef void (*CB)();
extern CB D_80182110[];
typedef struct { u8 pad[534]; u8 idx; } T;
void func_80170748(T *p) {
    D_80182110[p->idx](p);
}
