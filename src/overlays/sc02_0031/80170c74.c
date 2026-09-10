/* SC02.CD FILE_031 / ov_SC02_031 retail span [80170C74,80170CB0).
 * Offset 0x48B1C at overlay base 80128158. SHA256(span)=0402a0c6e3ee477ab174e17f86576b7766df38d02c5ffaf0dd07be837bda3da5.
 * Differs from the registry-verified MAIN member 0012 carve in exactly one
 * data reference: D_801818A8 here is D_80182130 (+0x888 member
 * data-block shift). Oracle MATCH re-earned on this file; Not MAIN10.
 */
/* Decompiled by m2c from main.s, then verified byte-exact
 * against retail by tools/match_function.py. Types and signatures are
 * whatever reproduces the bytes; they are not evidence of the
 * original declaration. */

#include "psx_types.h"
typedef void (*CB)();
extern CB D_80182130[];
typedef struct { u8 pad[533]; u8 idx; } T;
void func_80170C74(T *p) {
    D_80182130[p->idx](p);
}
