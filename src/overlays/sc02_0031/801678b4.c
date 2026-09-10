/* SC02.CD FILE_031 / ov_SC02_031 retail span [801678B4,801678F0).
 * Offset 0x3F75C at overlay base 80128158. SHA256(span)=c02a62740822db7cfa93397ac2341a99d7dc0aac0dea0f17444b8612115479e3.
 * Differs from the registry-verified MAIN member 0012 carve in exactly one
 * data reference: D_80181350 here is D_80181BD8 (+0x888 member
 * data-block shift). Oracle MATCH re-earned on this file; Not MAIN10.
 */
/* Decompiled by m2c from main.s, then verified byte-exact
 * against retail by tools/match_function.py. Types and signatures are
 * whatever reproduces the bytes; they are not evidence of the
 * original declaration. */

#include "psx_types.h"
typedef void (*CB)();
extern CB D_80181BD8[];
typedef struct { u8 pad[2]; u16 idx; } T;
void func_801678B4(T *p) {
    D_80181BD8[p->idx](p);
}
