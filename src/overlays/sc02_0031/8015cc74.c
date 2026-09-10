/* SC02.CD FILE_031 / ov_SC02_031 retail span [8015CC74,8015CCB0).
 * Offset 0x34B1C at overlay base 80128158. SHA256(span)=18efec6a9e598ba75757712f207b4c9984e9ee1927bca1ec1760ea4ca7de3ed3.
 * Differs from the registry-verified MAIN member 0012 carve in exactly one
 * data reference: D_80180BB8 here is D_80181440 (+0x888 member
 * data-block shift). Oracle MATCH re-earned on this file; Not MAIN10.
 */
/* Decompiled by m2c from main.s, then verified byte-exact
 * against retail by tools/match_function.py. Types and signatures are
 * whatever reproduces the bytes; they are not evidence of the
 * original declaration. */

#include "psx_types.h"
typedef void (*CB)();
extern CB D_80181440[];
typedef struct { u8 pad[2]; u16 idx; } T;
void func_8015CC74(T *p) {
    D_80181440[p->idx](p);
}
